#include "Lexer.h"
#include <sstream>
#include <iostream>

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

bool Lexer::tokenize_stream(std::istream& in, std::vector<Token>& tokens)
{
    while (true) {
        Token new_token = retrive_next_token(in);
        if (new_token.get_token_type() == Token::TokenType::Error) {
            std::cout << "Error: " << new_token.get_token_value();
            return false;
        }
        if (new_token.get_token_type() == Token::TokenType::EndOfFile) {
            return true;
        }
        tokens.push_back(new_token);
    }
}

bool Lexer::tokenize_file(std::string file_name, std::vector<Token>& tokens)
{
    std::ifstream in(file_name);
    return tokenize_stream(in, tokens);
}

Token Lexer::handle_unambiguous_single_char_tokens(int cur_c) {
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
    return Token(Token::TokenType::None);
}

Token Lexer::handle_ambiguous_operators(std::istream& in, int cur_c, int next_c) {
    if (cur_c == '.') return Token(Token::TokenType::MemberAccess);
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
        // state with transition by \n is starting state
        return retrive_next_token(in);
    }
    else if (cur_c == '/' && next_c == '*') {
        // transition by seq */ to starting state, transition by EOF to error state, all other characters lead to this same state
        cur_c = in.get();
        cur_c = in.get();
        next_c = in.peek();
        while (cur_c != EOF && !(cur_c == '*' && next_c == '/'))
        {
            cur_c = in.get();
            next_c = in.peek();
        }
        if (cur_c == EOF) {
            return Token(Token::TokenType::Error, "unterminated comment");
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
    return Token(Token::TokenType::Error);
}

Token Lexer::handle_bytes_literal(std::istream& in, int cur_c, int next_c)
{
    return Token(Token::TokenType::Error);
}

Token Lexer::build_integer_token(const std::string& number_string, NumberFormat number_format, bool is_imaginary) {
    if (number_string == "") {
        return Token(Token::TokenType::None);
    }
    if (number_format == NumberFormat::binary) {
        if (is_imaginary) return Token(Token::TokenType::ImaginaryIntegerLiteralBinary, number_string);
        else return Token(Token::TokenType::IntegerLiteralBinary, number_string);
    }
    if (number_format == NumberFormat::octal) {
        if (is_imaginary) return Token(Token::TokenType::ImaginaryIntegerLiteralOctal, number_string);
        else return Token(Token::TokenType::IntegerLiteralOctal, number_string);
    }
    if (number_format == NumberFormat::hexadecimal) {
        if (is_imaginary) return Token(Token::TokenType::ImaginaryIntegerLiteralHexadecimal, number_string);
        else return Token(Token::TokenType::IntegerLiteralHexadecimal, number_string);
    }
    if (number_format == NumberFormat::decimal) {
        if (is_imaginary) return Token(Token::TokenType::ImaginaryIntegerLiteralDecimal, number_string);
        else return Token(Token::TokenType::IntegerLiteralDecimal, number_string);
    }
}

Token Lexer::build_real_token(const std::string& number_string, NumberFormat number_format, bool is_imaginary) {
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
}

std::string Lexer::handle_exponent_part(std::istream& in, int& cur_c) {
    std::stringstream number_string_stream;
    bool underscore_acceptable = false;
    cur_c = in.get();
    if (is_sign(cur_c)) {
        int next_c = in.peek();
        if (is_digit(next_c)) {
            number_string_stream << cur_c;
            cur_c = in.get();
        }
        else {
            return "";
        }
    }
    while (true) {
        if (cur_c == '_' && !underscore_acceptable) {
            break;
        }
        else if (is_digit(cur_c)) {
            number_string_stream << (char) cur_c;
        }
        else {
            break;
        }
    }
    // letting caller to return not acceptable cur_c (because it maybe be acceptable in other context e.g 'i' - imaginary)
    return number_string_stream.str();
}

std::string Lexer::handle_fractional_part(std::istream& in, int& cur_c, NumberFormat number_format) {
    if (number_format == NumberFormat::binary || number_format == NumberFormat::octal) return "";
    bool (*is_acceptable_digit)(char) = get_check_digit_func(number_format);
    std::stringstream number_string_stream;
    std::string exponent_part = "";
    bool underscore_acceptable = false;
    cur_c = in.get();
    while (true)
    {
        if (is_e_exponent(cur_c) || is_p_exponent(cur_c)) {
            if (!((is_e_exponent(cur_c) && number_format == NumberFormat::hexadecimal) ||
                (is_p_exponent(cur_c) && number_format == NumberFormat::decimal))) { // if exponent corresponds to number format
                exponent_part = std::string(1, cur_c) + handle_exponent_part(in, cur_c);
                if (exponent_part.size() == 1) {
                    in.putback(exponent_part[0]);
                    exponent_part = "";
                }
            }
            break;
        }
        else if (cur_c == '_' && !underscore_acceptable) {
            break;
        }
        else if (is_acceptable_digit(cur_c)) {
            number_string_stream << (char) cur_c;
        }
        else {
            break;
        }
        cur_c = in.get();
        underscore_acceptable = true;
    }
    // letting caller to return not acceptable cur_c (because it maybe be acceptable in other context e.g 'i' - imaginary)
    return number_string_stream.str() + exponent_part;
}

// united 3 functions/automatas for whole number, fractional part, and exponent part because of similar code
Token Lexer::handle_number_literals_with_format_by_stage(std::istream& in, int& cur_c, NumberFormat number_format,
    NumberHandlingStage number_handling_stage) {
    
    if (number_handling_stage == NumberHandlingStage::FractionalPart && (number_format == NumberFormat::binary || number_format == NumberFormat::octal))
        return Token(Token::TokenType::None, "");

    if (!(number_handling_stage == NumberHandlingStage::WholeNumber)) cur_c = in.get();

    bool (*is_acceptable_digit)(char) = get_check_digit_func(number_format);

    std::stringstream number_string_stream;
    std::string next_part = "";
    bool underscore_acceptable = false;
    
    if (number_handling_stage == NumberHandlingStage::ExponentPart && is_sign(cur_c)) {
        int next_c = in.peek();
        if (is_digit(next_c)) {
            number_string_stream << (char) cur_c;
            cur_c = in.get();
        }
        else {
            return Token(Token::TokenType::None, "");
        }
    }
    
    while (true) {
        bool is_acceptable_cur_c = false;
        if (number_handling_stage == NumberHandlingStage::WholeNumber && cur_c == '.') {
            if (is_acceptable_digit(in.peek())) next_part = 
                handle_number_literals_with_format_by_stage(in, cur_c, number_format, NumberHandlingStage::FractionalPart).get_token_value();
            //if (fractional_part == "") in.putback('.');
            break;
        }
        if (number_handling_stage == NumberHandlingStage::FractionalPart && (is_e_exponent(cur_c) || is_p_exponent(cur_c))) {
            if (!((is_e_exponent(cur_c) && number_format == NumberFormat::hexadecimal) ||
                (is_p_exponent(cur_c) && number_format == NumberFormat::decimal))) { // if exponent corresponds to number format
                next_part.append(1, (char)cur_c);
                next_part.append(handle_number_literals_with_format_by_stage(in, cur_c, NumberFormat::decimal, NumberHandlingStage::ExponentPart).get_token_value());
                //next_part = std::string(1, (char) cur_c) + 
                //    handle_number_literals_with_format_by_stage(in, cur_c, NumberFormat::decimal, NumberHandlingStage::ExponentPart).get_token_value();
                if (next_part.size() == 1) {
                    in.putback(next_part[0]);
                    next_part = "";
                }
            }
            break;
        }
        if (cur_c == '_') {
            is_acceptable_cur_c = underscore_acceptable;
        }
        if (is_acceptable_digit(cur_c)) {
            is_acceptable_cur_c = true;
            number_string_stream << (char) cur_c;
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

    if (!(number_handling_stage == NumberHandlingStage::WholeNumber)) return Token(Token::TokenType::None, number_string + next_part);
    
    if (number_string == "" && next_part == "") {
        in.putback(cur_c);
        return Token(Token::TokenType::None);
    }

    bool is_imaginary = false;
    if (cur_c == 'i') is_imaginary = true;
    else in.putback(cur_c);

    if (next_part == "") {
        return build_integer_token(number_string, number_format, is_imaginary);
    }
    else {
        return build_real_token(number_string + "." + next_part, number_format, is_imaginary);
    }
}

Token Lexer::handle_number_literals(std::istream& in, int cur_c, int next_c)
{
    std::vector<char> chars_to_putback();
    NumberFormat number_format = NumberFormat::decimal;
    if (cur_c == '0') {
        if (next_c == 'x' || next_c == 'X') number_format = NumberFormat::hexadecimal;
        if (next_c == 'o' || next_c == 'O') number_format = NumberFormat::octal;
        if (next_c == 'b' || next_c == 'B') number_format = NumberFormat::binary;
    }
    if (number_format == NumberFormat::decimal) {
        // guaranteed number
        return handle_number_literals_with_format_by_stage(in, cur_c, number_format, NumberHandlingStage::WholeNumber);
    }
    else {
        cur_c = in.get();
        cur_c = in.get();
        Token token = handle_number_literals_with_format_by_stage(in, cur_c, number_format, NumberHandlingStage::WholeNumber, chars_to_putback);
        // after 0x can be not number, if so then it is just 0 (and id x next)
        if (token.get_token_type() == Token::TokenType::None) {
            in.putback(next_c);
            return Token(Token::TokenType::IntegerLiteralDecimal, "0");
        }
        else return token;
    }
}

Token Lexer::handle_identifiers_keywords_and_bool_literals(std::istream& in, int cur_c, int next_c)
{
    // check for first character was done already, and variants of first character is subset of variants of other characters, so used is_legal_identifier_char
    std::stringstream read_string_stream;
    keyword_automata.reset_state();
    while (true) {
        if (is_legal_identifier_char(cur_c)) {
            char c = static_cast<char>(cur_c);
            read_string_stream << c;
            // using automata in explicit form, because all other solutions I could think of was inefficient
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
        if (read_string == "true" || read_string == "false") {
            return Token(Token::TokenType::BoolLiteral, read_string);
        }
        else {
            return Token(Token::TokenType::Keyword, read_string);
        }
    }
    else {
        return Token(Token::TokenType::Identifier, read_string);
    }
}

Token Lexer::handle_operators_and_punctuation(std::istream& in, int cur_c, int next_c)
{
    /*if (s[pos] == '(') return Token(Token::TokenType::LeftRoundBracket);
    // all other one symbol Tokens that don't conflict with any longer Tokens
    if (s[pos] == '<') {
        if (pos < s.size() - 1 && s[pos + 1] == '=') return Token(Token::TokenType::RelationalOperator, "<=");
    }*/
    return Token(Token::TokenType::Error);
}

Token Lexer::retrive_next_token(std::istream& in)
{
    int cur_c = in.get();
    if (cur_c == EOF) return Token(Token::TokenType::EndOfFile);

    // skip whitespace chars, transition by whitespace to same starting state
    if (is_whitespace(cur_c)) {
        return retrive_next_token(in);
    }

    Token return_token = handle_unambiguous_single_char_tokens(cur_c);
    if (return_token.get_token_type() != Token::TokenType::None) return return_token;

    int next_c = in.peek();

    // skip comments, if skipped comment also retrieves next token, if didn't returns None token or Error token. Automata notes in function
    Token token_from_skip_comments = skip_comments(in, cur_c, next_c);
    if (token_from_skip_comments.get_token_type() != Token::TokenType::None) return token_from_skip_comments;

    // handle string literals
    if (cur_c == '"' || cur_c == '\''/* || (cur_c == 'b' && (next_c == '"' || next_c == '\''))*/) return handle_string_literals(in, cur_c, next_c);
    // handle bytes literals
    if (cur_c == 'b' && (next_c == '"' || next_c == '\'')) return handle_bytes_literal(in, cur_c, next_c);
    // handle integer and real literals
    if (is_digit(cur_c) || (cur_c == '.' && is_digit(next_c))) {
        return handle_number_literals(in, cur_c, next_c);
    }
    // handle Identifiers, Keywords, bool literals
    if (is_letter_or_underscore(cur_c)) {
        return handle_identifiers_keywords_and_bool_literals(in, cur_c, next_c);
    }
    // handle ambiguous operators
    return_token = handle_ambiguous_operators(in, cur_c, next_c);
    if (return_token.get_token_type() != Token::TokenType::None) return return_token;

    return Token(Token::TokenType::Error);
}