#include "Lexer.h"
#include <sstream>
#include <iostream>
#include "util.h"

const std::string Lexer::MAX_DECIMAL_INTEGER = "18446744073709551615";
const std::string Lexer::MAX_OCTAL_INTEGER = "1777777777777777777777";
const std::size_t Lexer::MAX_HEXADECIMAL_INTEGER_LENGTH = 16;
const std::size_t Lexer::MAX_BINARY_INTEGER_LENGTH = 64;

const std::vector <std::string> Lexer::KEYWORDS = { "_", "align", "as", "atomic",  "begin",  "bool",  "borrowed",  "break",  "by",  "bytes",  "catch",
"class",  "cobegin",  "coforall",  "complex", "config",  "const",  "continue",  "defer",  "delete",  "dmapped",  "do",  "domain",  "else",  "enum",
"except",  "export",  "extern",  "false",  "for",  "forall",  "foreach",  "forwarding",  "if",  "imag", "implements",  "in",  "index",  "inline",
"inout",  "int",  "interface",  "iter",  "label",  "let",  "lifetime",  "local",  "locale",  "manage",  "module",  "new",  "nil",  "noinit",  "on",
"only", "operator", "otherwise", "out", "override", "owned", "param", "private", "prototype", "proc", "public", "real", "record", "reduce", "ref",
"require", "return", "scan", "select", "serial", "shared", "single", "sparse", "string", "subdomain", "sync", "then", "this", "throw", "throws",
"true", "try", "type", "uint", "union", "unmanaged", "use", "var", "when", "where",  "while",  "with",  "yield",  "zip",  "lambda",  "pragma",
"primitive"};

Lexer::Lexer() {
    for (std::size_t i = 0; i < KEYWORDS.size(); i++) {
        keyword_automata.add_keyword(KEYWORDS[i]);
    }
}

bool Lexer::tokenize_file(std::string file_name, std::vector<Token>& tokens, std::vector<std::string>& errors)
{
    std::ifstream in(file_name);
    return tokenize_stream(in, tokens, errors);
}

bool Lexer::tokenize_stream(std::istream& in, std::vector<Token>& tokens, std::vector<std::string>& errors)
{
    bool error = false;
    while (true) {
        Token new_token = retrive_next_token(in);
        if (new_token.get_token_type() == Token::TokenType::Error) {
            errors.push_back(new_token.get_token_value());
            error = true;
        }
        if (new_token.get_token_type() == Token::TokenType::EndOfFile) {
            return !error;
        }
        tokens.push_back(new_token);
    }
}
// if token ended correctly (and is the longest possible) then no further checks are done, so 2x is (IntegerLiteralDecimal, "2"), (Identifier, "x") 
Token Lexer::retrive_next_token(std::istream& in)
{
    // Sequential checks for different types of tokens, most determined by first two chars
    // order of checks is crucial (e.g. bytes literals before identifiers, real numbers before dot operators),
    // but enables immediate return of token without further checks (the longest correct token guaranteed)
    // So this implementation acts like united automata
    // In fact based on first two characters input is transfered to corresponding algorithm (implicit automata)

    // reading from stream, generally when unaccepted character of analyzed token encountered (start of next token) I put it back and return formed token

    int cur_c = in.get();
    if (cur_c == EOF) return Token(Token::TokenType::EndOfFile);

    // skip whitespace chars, transition by whitespace to same starting state
    if (is_whitespace(cur_c)) {
        if (cur_c == '\n') cur_line++;
        return retrive_next_token(in);
    }

    // handle unambiguous single char tokens
    Token return_token = handle_unambiguous_single_char_tokens(cur_c);
    if (return_token.get_token_type() != Token::TokenType::None) return return_token;

    int next_c = in.peek();

    // skip comments, if skipped comment also retrieves next token, if didn't returns None token or Error token. Automata notes in function
    Token token_from_skip_comments = skip_comments(in, cur_c, next_c);
    if (token_from_skip_comments.get_token_type() != Token::TokenType::None) return token_from_skip_comments;

    // handle string literals
    if (cur_c == '"' || cur_c == '\'') return handle_string_literals(in, cur_c, next_c);

    // handle bytes literals (lexical structure like string literals with b before it)
    if (cur_c == 'b' && (next_c == '"' || next_c == '\'')) {
        cur_c = in.get();
        next_c = in.peek();
        Token string_literal_token = handle_string_literals(in, cur_c, next_c);
        if (string_literal_token.get_token_type() == Token::TokenType::InterpretedStringLiteral) {
            return Token(Token::TokenType::InterpretedBytesLiteral, string_literal_token.get_token_value());
        }
        else if (string_literal_token.get_token_type() == Token::TokenType::UninterpretedStringLiteral) {
            return Token(Token::TokenType::UninterpretedBytesLiteral, string_literal_token.get_token_value());
        }
        else { // error
            return string_literal_token;
        }
    }

    // handle number (integer, real, imaginary) literals
    if (is_digit(cur_c) || (cur_c == '.' && is_digit(next_c))) {
        return handle_number_literals(in, cur_c, next_c);
    }

    // handle Identifiers, Keywords, bool literals
    if (is_letter_or_underscore(cur_c)) {
        return handle_identifiers_keywords_and_bool_literals(in, cur_c, next_c);
    }

    // handle ambiguous tokens (e.g. relational operators)
    return_token = handle_ambiguous_tokens(in, cur_c, next_c);
    if (return_token.get_token_type() != Token::TokenType::None) return return_token;

    // no token can start with this character
    return Token(Token::TokenType::Error, error_string_wrapper("no token can start with character: " + std::string(1, (char)cur_c)));
}

Token Lexer::handle_unambiguous_single_char_tokens(int cur_c) {
    // transition by this chars to accepted state
    // this chars it text always represent their tokens, they cannot be a part of other tokens (no  ambiguity)
    if (cur_c == '(') return Token(Token::TokenType::LeftRoundBracket);
    if (cur_c == ')') return Token(Token::TokenType::RightRoundBracket);
    if (cur_c == '{') return Token(Token::TokenType::LeftCurlyBracket);
    if (cur_c == '}') return Token(Token::TokenType::RightCurlyBracket);
    if (cur_c == '[') return Token(Token::TokenType::LeftSquareBracket);
    if (cur_c == ']') return Token(Token::TokenType::RightSquareBracket);
    if (cur_c == '#') return Token(Token::TokenType::RangeCountOperator);
    if (cur_c == ':') return Token(Token::TokenType::TypeSpecifier);
    if (cur_c == ';') return Token(Token::TokenType::StatementSeparator);
    if (cur_c == ',') return Token(Token::TokenType::ExpressionSeparator);
    if (cur_c == '?') return Token(Token::TokenType::TypeQuery);
    if (cur_c == '~') return Token(Token::TokenType::BitwiseOperator, "~");
    return Token(Token::TokenType::None);
}

Token Lexer::skip_comments(std::istream& in, int cur_c, int next_c)
{
    if (cur_c == '/' && next_c == '/') {
        // transition to next state only by EOF or \n
        cur_c = in.get();
        while (cur_c != EOF && cur_c != '\n')
        {
            cur_c = in.get();
        }
        if (cur_c == EOF) {
            return Token(Token::TokenType::EndOfFile);
        }
        else {
            cur_line++;
            // state with transition by \n is starting state
            return retrive_next_token(in);
        }
    }
    else if (cur_c == '/' && next_c == '*') {
        // transition by seq */ to starting state, transition by EOF to error state, all other characters lead to this same state
        cur_c = in.get();
        cur_c = in.get();
        next_c = in.peek();
        while (cur_c != EOF && !(cur_c == '*' && next_c == '/'))
        {
            if (cur_c == '\n') cur_line++;
            cur_c = in.get();
            next_c = in.peek();
        }
        if (cur_c == EOF) {
            return Token(Token::TokenType::Error, error_string_wrapper("unterminated comment"));
        }
        cur_c = in.get();
        return retrive_next_token(in);
    }
    else {
        // all transitions except above lead to starting state with no additional characters read
        return Token(Token::TokenType::None);
    }
}

Token Lexer::handle_string_literals(std::istream& in, int cur_c, int next_c)
{
    int terminating_char = cur_c;
    bool is_interpreted = true;
    if (next_c == terminating_char) {
        cur_c = in.get();
        next_c = in.peek();
        if (next_c == terminating_char) {
            cur_c = in.get();
            is_interpreted = false;
        }
        else {
            // empty string
            return Token(Token::TokenType::InterpretedStringLiteral, "");
        }
    }
    int terminating_char_seq_count = 0;
    cur_c = in.get();
    if (is_interpreted) return handle_interpreted_string_literal(in, cur_c, terminating_char);
    else return  handle_uninterpreted_string_literal(in, cur_c, terminating_char);
}

Token Lexer::handle_interpreted_string_literal(std::istream& in, int cur_c, int terminating_char) {
    std::stringstream token_value_stream;
    bool error = false;
    std::string error_discritption;
    while (cur_c) {
        if (cur_c == EOF) {
            error = true;
            error_discritption = "end of file in string literal";
            break;
        }
        else if (cur_c == '\n') {
            error = true;
            error_discritption = "new line in string literal";
            break;
        }
        else if (cur_c == '\\') { // interpreting escape character
            int next_c = in.peek();
            if (is_acceptable_simple_escape_char(next_c)) {
                token_value_stream << escape_char(next_c);
                cur_c = in.get();
            }
            else {
                cur_c = in.get();
                if (cur_c == 'x') { // can be hexadecimal escape char
                    next_c = in.peek();
                    if (is_hexadecimal_digit(next_c)) {
                        cur_c = in.get();
                        token_value_stream << interpret_hexadecimal_escape_char(in, cur_c);
                        cur_c = in.get();
                        continue;
                    }
                }
                error = true;
                error_discritption = "unacceptable escape character: \\" + std::string(1, cur_c);
                break;
            }
        }
        else if (cur_c == terminating_char) {
            break;
        }
        else {
            token_value_stream << (char)cur_c;
        }
        cur_c = in.get();
    }
    if (error) {
        // skip all charasters to EOF or termitating char (panic mode), because otherwise if string literal was closed and we stop here that would
        // produce new errors and misleading tokens
        while (cur_c != EOF && cur_c != terminating_char)
        {
            cur_c = in.get();
        }
        return Token(Token::TokenType::Error, error_string_wrapper(error_discritption));
    }
    return Token(Token::TokenType::InterpretedStringLiteral, token_value_stream.str());
}

char Lexer::interpret_hexadecimal_escape_char(std::istream& in, int cur_c) { // \x? or \x??, where ? and ?? are hexadecimal numbers representing char code
    int next_c = in.peek();
    if (is_hexadecimal_digit(next_c)) {
        next_c = in.get();
        return (char)(16 * hexadecimal_digit_to_int(cur_c) + hexadecimal_digit_to_int(next_c));
    }
    else return (char)hexadecimal_digit_to_int(cur_c);
}

Token Lexer::handle_uninterpreted_string_literal(std::istream& in, int cur_c, int terminating_char) {
    // any characters allowed (new line included) till three terminating chars encountered in a row
    // can be represented by automata with any character except terminating leading to staring state, and three consecutive transitions
    // by terminating chars, only third accepted, in first two all chars except terminating lead to starting state
    std::stringstream read_string_stream;
    int terminating_char_successively_count = 0;
    while (cur_c) {
        if (cur_c == EOF) {
            return Token(Token::TokenType::Error, error_string_wrapper("end of file in string literal"));
        }
        if (cur_c == '\n') cur_line++;
        if (cur_c == terminating_char) {
            terminating_char_successively_count++;
            if (terminating_char_successively_count == 3) break;
        }
        else {
            terminating_char_successively_count = 0;
        }
        read_string_stream << (char)cur_c;
        cur_c = in.get();
    }
    std::string read_string = read_string_stream.str();
    // excluding last 2 chars (terminating chars - third is not in read_string)
    return Token(Token::TokenType::UninterpretedStringLiteral, read_string.substr(0, read_string.size() - 2));
}

Token Lexer::handle_number_literals(std::istream& in, int cur_c, int next_c)
{
    std::vector<int> chars_to_putback;
    Token return_token = Token(Token::TokenType::None);
    NumberFormat number_format = NumberFormat::decimal;
    if (cur_c == '0') {
        if (next_c == 'x' || next_c == 'X') number_format = NumberFormat::hexadecimal;
        if (next_c == 'o' || next_c == 'O') number_format = NumberFormat::octal;
        if (next_c == 'b' || next_c == 'B') number_format = NumberFormat::binary;
    }
    if (number_format == NumberFormat::decimal) {
        // guaranteed number
        return_token = handle_number_literals_with_format_by_stage(in, cur_c, number_format, NumberHandlingStage::WholeNumber, chars_to_putback);
    }
    else {
        cur_c = in.get();
        cur_c = in.get();
        Token token = handle_number_literals_with_format_by_stage(in, cur_c, number_format, NumberHandlingStage::WholeNumber, chars_to_putback);
        // after 0x can be not number, if so then it is just 0 (and identifier x next)
        if (token.get_token_type() == Token::TokenType::None) {
            chars_to_putback.insert(chars_to_putback.begin(), next_c);
            return_token = Token(Token::TokenType::IntegerLiteralDecimal, "0");
        }
        else return_token = token;
    }
    // putting back chars can be: last read character, dot, exponent char (e, p)
    for (int i = chars_to_putback.size() - 1; i >= 0; i--) in.putback(chars_to_putback[i]);
    return return_token;
}

// united 3 functions/automatas for whole number, fractional part, and exponent part because of similar code
Token Lexer::handle_number_literals_with_format_by_stage(std::istream& in, int& cur_c, NumberFormat number_format,
    NumberHandlingStage number_handling_stage, std::vector<int>& chars_to_putback) {

    // real numbers cannot be binary or octal
    if (number_handling_stage == NumberHandlingStage::FractionalPart && (number_format == NumberFormat::binary || number_format == NumberFormat::octal))
        return Token(Token::TokenType::None, "");

    if (!(number_handling_stage == NumberHandlingStage::WholeNumber)) cur_c = in.get();

    bool (*is_acceptable_digit)(char) = get_check_digit_func(number_format);

    std::stringstream number_string_stream;
    std::string next_part = "";
    // number can have underscores(eg. 100_100) but it is not allowed at the start, after dot, and at the start of exponent value
    bool underscore_acceptable = false;

    // after exponent char optional sign can be encountered, yet such number cannot end with sign
    if (number_handling_stage == NumberHandlingStage::ExponentPart && is_sign(cur_c)) {
        int next_c = in.peek();
        if (is_digit(next_c)) {
            number_string_stream << (char)cur_c;
            cur_c = in.get();
        }
        else {
            return Token(Token::TokenType::None, "");
        }
    }

    while (true) {
        bool is_acceptable_cur_c = false;

        if (number_handling_stage == NumberHandlingStage::WholeNumber && cur_c == '.') { // that can be real number, finding fractional part
            // call fractional part handler
            if (is_acceptable_digit(in.peek())) next_part = "." +
                handle_number_literals_with_format_by_stage(in, cur_c, number_format, NumberHandlingStage::FractionalPart,
                    chars_to_putback).get_token_value();
            // check if following chars result in invalid fractional part
            if (next_part.size() == 1) next_part = "";
            break;
        }

        if (is_e_exponent(cur_c) || is_p_exponent(cur_c)) {
            // found exponent part, but it can be incorrect (or legal char of fractional part)
            if (!((is_e_exponent(cur_c) && number_format == NumberFormat::hexadecimal) ||
                (is_p_exponent(cur_c) && number_format == NumberFormat::decimal))) { // if exponent corresponds to number format
                next_part.append(1, (char)cur_c);
                // call exponent part handler
                next_part.append(handle_number_literals_with_format_by_stage(in, cur_c, NumberFormat::decimal, NumberHandlingStage::ExponentPart,
                    chars_to_putback).get_token_value());
                // check if following chars result in invalid exponent
                if (next_part.size() == 1) {
                    chars_to_putback.push_back(next_part[0]);
                    next_part = "";
                }
                break;
            }
        }
        if (cur_c == '_') {
            is_acceptable_cur_c = underscore_acceptable;
        }
        if (is_acceptable_digit(cur_c)) {
            is_acceptable_cur_c = true;
            number_string_stream << (char)cur_c;
        }
        if (is_acceptable_cur_c) {
            cur_c = in.get();
            underscore_acceptable = true;
        }
        else {
            break;
        }
    }

    std::string number_string = number_string_stream.str();

    // if not whole number stage only string matters, so just return it 
    if (!(number_handling_stage == NumberHandlingStage::WholeNumber)) return Token(Token::TokenType::None, number_string + next_part);

    // cur_c is updated by recursive calls, because passed by reference, and so points to first unaccepted character in whole analysis

    if (number_string == "" && next_part == "") {
        chars_to_putback.push_back(cur_c);
        return Token(Token::TokenType::None);
    }

    // imaginary numbers end with i (e.g. 12i)
    bool is_imaginary = false;
    if (cur_c == 'i') is_imaginary = true;
    else chars_to_putback.push_back(cur_c);

    if (next_part == "") {
        return build_integer_token(number_string, number_format, is_imaginary);
    }
    else {
        return build_real_token(number_string + next_part, number_format, is_imaginary);
    }
}


Token Lexer::build_integer_token(const std::string& number_string, NumberFormat number_format, bool is_imaginary) {
    // here we handle integer overflow - maximum uint(64) as errors, but imaginary integers in this case are converted to real imaginary numbers
    std::string text_integer_representation_for_error = "";
    if (number_string == "") {
        return Token(Token::TokenType::None);
    }
    if (number_format == NumberFormat::binary) {
        if (number_string.size() > MAX_BINARY_INTEGER_LENGTH) {
            text_integer_representation_for_error = "0b" + number_string;
        }
        else {
            if (is_imaginary) return Token(Token::TokenType::ImaginaryIntegerLiteralBinary, number_string);
            else return Token(Token::TokenType::IntegerLiteralBinary, number_string);    
        }
    }
    if (number_format == NumberFormat::octal) {
        if (number_string.size() > MAX_OCTAL_INTEGER.size() || (number_string.size() == MAX_OCTAL_INTEGER.size() && number_string > MAX_OCTAL_INTEGER)) {
            text_integer_representation_for_error = "0o" + number_string;
        }
        else {
            if (is_imaginary) return Token(Token::TokenType::ImaginaryIntegerLiteralOctal, number_string);
            else return Token(Token::TokenType::IntegerLiteralOctal, number_string);
        }
    }
    if (number_format == NumberFormat::hexadecimal) {
        if (number_string.size() > MAX_HEXADECIMAL_INTEGER_LENGTH) {
            if (is_imaginary)return build_real_token(number_string, number_format, is_imaginary);
            else text_integer_representation_for_error = "0x" + number_string;
        }
        else {
            if (is_imaginary) return Token(Token::TokenType::ImaginaryIntegerLiteralHexadecimal, number_string);
            else  return Token(Token::TokenType::IntegerLiteralHexadecimal, number_string);
        }
    }
    if (number_format == NumberFormat::decimal) {
        if (number_string.size() > MAX_DECIMAL_INTEGER.size() || (number_string.size() == MAX_DECIMAL_INTEGER.size() && number_string > MAX_DECIMAL_INTEGER)) {
            if (is_imaginary) return build_real_token(number_string, number_format, is_imaginary);
            else text_integer_representation_for_error = number_string;
        }
        else {
            if (is_imaginary) return Token(Token::TokenType::ImaginaryIntegerLiteralDecimal, number_string);
            else return Token(Token::TokenType::IntegerLiteralDecimal, number_string);
        }
    }
    return Token(Token::TokenType::Error, error_string_wrapper("integer literal overflow: '" + text_integer_representation_for_error +
        "' is too big for a 64-bit unsigned integer"));
}

Token Lexer::build_real_token(const std::string& number_string, NumberFormat number_format, bool is_imaginary) {
    // real overflow should (imo) be handled by other parts of compiler pipeline (conversion (to bit representation) needed)
    if (number_format == NumberFormat::binary || number_format == NumberFormat::octal) {
        return Token(Token::TokenType::None);
    }
    if (number_format == NumberFormat::hexadecimal) {
        if (is_imaginary) return Token(Token::TokenType::ImaginaryRealLiteralHexadecimal, number_string);
        else return Token(Token::TokenType::RealLiteralHexadecimal, number_string);
    }
    if (number_format == NumberFormat::decimal) {
        if (is_imaginary) return Token(Token::TokenType::ImaginaryRealLiteralDecimal, number_string);
        return Token(Token::TokenType::RealLiteralDecimal, number_string);
    }
    return Token(Token::TokenType::None);
}

Token Lexer::handle_identifiers_keywords_and_bool_literals(std::istream& in, int cur_c, int next_c)
{
    // check for first character was done already, and variants of first character is subset of variants of other characters, so used is_legal_identifier_char
    std::stringstream read_string_stream;
    keyword_automata.reset_state();
    while (true) {
        if (is_legal_identifier_char(cur_c)) {
            char c = (char) cur_c;
            read_string_stream << c;
            // using automata in explicit form, because all other solutions I could think of was inefficient (e.g check for all keywords on each iteration)
            keyword_automata.feed(c);
        }
        else {
            in.putback(cur_c);
            break;
        }
        cur_c = in.get();
    }
    std::string read_string = read_string_stream.str();
    if (keyword_automata.is_in_accepted_state()) {
        // check for bool literal
        if (read_string == "true" || read_string == "false") {
            return Token(Token::TokenType::BoolLiteral, read_string);
        }
        // check of compound assignment reduce=
        else if (read_string == "reduce" && cur_c == '=') {
            // take back =
            cur_c = in.get();
            return Token(Token::TokenType::CompoundAssignment, "reduce=");
        }
        else {
            return Token(Token::TokenType::Keyword, read_string);
        }
    }
    else {
        return Token(Token::TokenType::Identifier, read_string);
    }
}

Token Lexer::handle_ambiguous_tokens(std::istream& in, int cur_c, int next_c) {
    // a lot of ifs because of different types tokens instead of few (like operator and punctuation)
    // That is done so because it will be easier for parser to work with meaningful tokens (imo)
    char c;
    if (cur_c == '.') {
        if (next_c == '.') {
            c = in.get();
            next_c = in.peek();
            if (next_c == '.') {
                c = in.get();
                return Token(Token::TokenType::VariableArgumentLists);
            }
            else if (next_c == '<') {
                c = in.get();
                return Token(Token::TokenType::RangeSpecifier, "..<");
            }
            else return Token(Token::TokenType::RangeSpecifier, "..");
        }
        else return Token(Token::TokenType::MemberAccess);
    }
    if (cur_c == '*' && next_c == '*') {
        c = in.get();
        if (in.peek() == '=') {
            c = in.get();
            return Token(Token::TokenType::CompoundAssignment, "**=");
        }
        else {
            return Token(Token::TokenType::ArithmeticOperator, "**");
        }
    }
    if (cur_c == '+' || cur_c == '-' || cur_c == '/' || cur_c == '%' || cur_c == '*') {
        if (next_c == '=') {
            c = in.get();
            return Token(Token::TokenType::CompoundAssignment, std::string(1, cur_c) + "=");
        }
        else {
            return Token(Token::TokenType::ArithmeticOperator, std::string(1, cur_c));
        }
    }
    if (cur_c == '&' || cur_c == '|' || cur_c == '^') {
        if (next_c == '=') {
            c = in.get();
            return Token(Token::TokenType::CompoundAssignment, std::string(1, cur_c) + "=");
        }
        else if (cur_c != '^' && next_c == cur_c) {
            c = in.get();
            if (in.peek() == '=') {
                c = in.get();
                return Token(Token::TokenType::CompoundAssignment, std::string(2, cur_c) + "=");
            }
            return Token(Token::TokenType::LogicalOperator, std::string(2, cur_c));
        }
        else return Token(Token::TokenType::BitwiseOperator, std::string(1, cur_c));
    }
    if (cur_c == '!') {
        if (next_c == '=') {
            c = in.get();
            return Token(Token::TokenType::RelationalOperator, "!=");
        }
        else return Token(Token::TokenType::LogicalOperator, "!");
    }
    if (cur_c == '<' || cur_c == '>') {
        if (next_c == '=') {
            c = in.get();
            if (cur_c == '<' && in.peek() == '>') { // swap - <=>
                c = in.get();
                return Token(Token::TokenType::Swap);
            }
            else return Token(Token::TokenType::RelationalOperator, std::string(1, cur_c) + "=");
        }
        else if (next_c == cur_c) {
            c = in.get();
            if (in.peek() == '=') {
                c = in.get();
                return Token(Token::TokenType::CompoundAssignment, std::string(2, cur_c) + "=");
            }
            return Token(Token::TokenType::BitwiseOperator, std::string(2, cur_c));
        }
        else return Token(Token::TokenType::RelationalOperator, std::string(1, cur_c));
    }
    if (cur_c == '=') {
        if (next_c == '=') {
            c = in.get();
            return Token(Token::TokenType::RelationalOperator, "==");
        }
        else return Token(Token::TokenType::Assignment);
    }
    return Token(Token::TokenType::None);
}

std::string Lexer::error_string_wrapper(std::string error_discritption) {
    return "Lexical error in line " + std::to_string(cur_line) + ": " + error_discritption;
}