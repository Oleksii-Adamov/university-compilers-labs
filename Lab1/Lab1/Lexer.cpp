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

Token Lexer::build_integer_token(const std::string& number_string, IntegerFormat integer_format, bool is_imaginary) {
    if (number_string == "") {
        return Token(Token::TokenType::None);
    }
    if (integer_format == IntegerFormat::binary) {
        if (is_imaginary) return Token(Token::TokenType::ImaginaryIntegerLiteralBinary, number_string);
        else return Token(Token::TokenType::IntegerLiteralBinary, number_string);
    }
    if (integer_format == IntegerFormat::octal) {
        if (is_imaginary) return Token(Token::TokenType::ImaginaryIntegerLiteralOctal, number_string);
        else return Token(Token::TokenType::IntegerLiteralOctal, number_string);
    }
    if (integer_format == IntegerFormat::hexadecimal) {
        if (is_imaginary) return Token(Token::TokenType::ImaginaryIntegerLiteralHexadecimal, number_string);
        else return Token(Token::TokenType::IntegerLiteralHexadecimal, number_string);
    }
    if (integer_format == IntegerFormat::decimal) {
        if (is_imaginary) return Token(Token::TokenType::ImaginaryIntegerLiteralDecimal, number_string);
        else return Token(Token::TokenType::IntegerLiteralDecimal, number_string);
    }
}

Token build_real_token(const std::string& number_string, IntegerFormat integer_format, bool is_imaginary) {
    if (integer_format == IntegerFormat::binary || integer_format == IntegerFormat::octal) {
        return Token(Token::TokenType::None);
    }
    if (integer_format == IntegerFormat::hexadecimal) {
        if (is_imaginary) return Token(Token::TokenType::ImaginaryRealLiteralHexadecimal, number_string);
        else return Token(Token::TokenType::RealLiteralHexadecimal, number_string);
    }
    if (integer_format == IntegerFormat::decimal) {
        if (is_imaginary) return Token(Token::TokenType::ImaginaryRealLiteralDecimal, number_string);
        return Token(Token::TokenType::RealLiteralDecimal, number_string);
    }
}
/*
Token build_imaginary_token(const std::string& read_string, IntegerFormat integer_format, bool is_real) {
    if (read_string == "") {
        return Token(Token::TokenType::None);
    }
    if (is_real) {
        if (integer_format == IntegerFormat::binary || integer_format == IntegerFormat::octal) {
            return Token(Token::TokenType::None);
        }
        if (integer_format == IntegerFormat::hexadecimal) {
            return Token(Token::TokenType::ImaginaryRealLiteralHexadecimal, read_string.substr(0, read_string.size() - 1));
        }
        if (integer_format == IntegerFormat::decimal) {
            return Token(Token::TokenType::ImaginaryRealLiteralDecimal, read_string.substr(0, read_string.size() - 1));
        }
    }
    else {
        if (integer_format == IntegerFormat::binary) {
            return Token(Token::TokenType::ImaginaryIntegerLiteralBinary, read_string);
        }
        if (integer_format == IntegerFormat::octal) {
            return Token(Token::TokenType::ImaginaryIntegerLiteralOctal, read_string);
        }
        if (integer_format == IntegerFormat::hexadecimal) {
            return Token(Token::TokenType::ImaginaryIntegerLiteralHexadecimal, read_string);
        }
        if (integer_format == IntegerFormat::decimal) {
            return Token(Token::TokenType::ImaginaryIntegerLiteralDecimal, read_string);
        }
    }
}
*/

std::string handle_exponent_part(std::istream& in, int& cur_c) {
    std::stringstream number_string_stream;
    bool underscore_acceptable = false;
    cur_c = in.get();
    if (is_sign(cur_c)) {
        number_string_stream << cur_c;
        cur_c = in.get();
        // will need to retract if ahead is not digits, well can check right now (and also maybe with dot using acceptible_digit() if no exponent possible without digits)
    }
}

std::string handle_fractional_part(std::istream& in, int& cur_c, IntegerFormat integer_format) {
    if (integer_format == IntegerFormat::binary || integer_format == IntegerFormat::octal) return "";
    bool (*is_acceptable_digit)(char) = get_check_digit_func(integer_format);
    std::stringstream number_string_stream;
    std::string exponent_part = "";
    bool underscore_acceptable = false;
    cur_c = in.get();
    while (true)
    {
        if (is_e_exponent(cur_c)) {
            if (integer_format == IntegerFormat::hexadecimal) break;
            exponent_part = handle_exponent_part(in, cur_c);
        }
        else if (is_p_exponent(cur_c)) {
            if (integer_format == IntegerFormat::decimal) break;
            exponent_part = handle_exponent_part(in, cur_c);
        }
        else if (cur_c == '_' && !underscore_acceptable) {
            break;
        }
        else if (is_acceptable_digit(cur_c)) {
            number_string_stream << cur_c;
        }
        else {
            break;
        }
        cur_c = in.get();
        underscore_acceptable = true;
    }
    return number_string_stream.str() + exponent_part;
}

Token Lexer::handle_number_literals_with_format(std::istream& in, int cur_c, IntegerFormat integer_format) {
    bool (*is_acceptable_digit)(char) = get_check_digit_func(integer_format);
    
    std::stringstream number_string_stream;
    std::string fractional_part = "";
    bool underscore_acceptable = false;
    while (true) {
        if (cur_c == '.') {
            fractional_part = handle_fractional_part(in, cur_c, integer_format);
            if (fractional_part == "") in.putback('.');
            break;
        }
        else if (cur_c == '_' && !underscore_acceptable) {
            break;
        }
        else if (is_acceptable_digit(cur_c)) {
            number_string_stream << cur_c;
        }
        else {
            break;
        }
        cur_c = in.get();
        underscore_acceptable = true;
    }
    if (cur_c == 'i') is_imaginary = true;
    else in.putback(cur_c);
    if (fractional_part == "") {
        return build_integer_token(number_string, integer_format, is_imaginary);
    }
    else {
        return build_real_token(number_string + "." + fractional_part, integer_format, is_imaginary);
    }

    std::stringstream read_string_stream;
    bool encountered_dot = false;
    
    char prev_c = 0;
    bool encountered_exponent = false;
    // handle exponents and imaginary
    // maybe go while true and break if not acceptable
    while (is_acceptable_digit(cur_c) || cur_c == '.' || cur_c == '_' || cur_c == 'e' || cur_c == 'E' || cur_c == 'p' || cur_c == 'P' || cur_c == '+' || cur_c == '-')
    {
        if (is_sign(cur_c) && !(is_e_exponent(prev_c) || is_p_exponent(prev_c))) break;
        if (is_e_exponent(cur_c) && integer_format != IntegerFormat::decimal) break;
        if (is_p_exponent(cur_c) && integer_format != IntegerFormat::hexadecimal) break;
        if ((is_e_exponent(cur_c) || is_p_exponent(cur_c)) && !encountered_dot) break;
        if (is_e_exponent(cur_c) || is_p_exponent(cur_c)) {

        }
        if (cur_c == '_' && !underscore_acceptable) {
            break;
        }
        if (cur_c == '.') {
            if (encountered_dot)
            {
                break;
            }
            else {
                encountered_dot = true;
                underscore_acceptable = false;
            }
        }
        else {
            underscore_acceptable = true;
        }
        if (cur_c != '_') number_string_stream << cur_c;
        read_string_stream << cur_c;
        cur_c = in.get();
    }
    bool should_put_back_cur_c = true;
    bool is_imaginary = false;
    if (cur_c == 'i') {
        is_imaginary = true;
        should_put_back_cur_c = false;
    }
    std::string read_string = read_string_stream.str();
    std::string number_string = number_string_stream.str();
    Token return_token = Token(Token::TokenType::Error, "error in parsing number (shouldn't occur)");
    
    if (encountered_dot) {
        if (number_string[number_string.size() - 1] == '.') {
            // real literal cannot end with dot
            in.putback('.');
            // case with dot and no digits ahead cannot occur here (check before)
            return_token = build_integer_token(number_string.substr(0, number_string.size() - 1), integer_format, is_imaginary);
        }
        return_token = build_real_token(number_string, integer_format, is_imaginary);
    }
    else {
        return_token = build_integer_token(number_string, integer_format, is_imaginary);
    }
    if (return_token.get_token_type() == Token::TokenType::None) {
        // retract, put back all read chars
        for (std::size_t i = 0; i < read_string.size(); i++) {
            // change read_string to include all chars and add number_string
            in.putback(read_string[i]);
        }
        should_put_back_cur_c = true;
    }
    if (should_put_back_cur_c) in.putback(cur_c);
    return return_token;
}

Token Lexer::handle_number_literals(std::istream& in, int cur_c, int next_c)
{
    if (cur_c == '0' && (next_c == 'x' || next_c == 'X')) {
        // hexadecimal
        cur_c = in.get();
        cur_c = in.get();
        next_c = in.peek();
        Token token = handle_number_literals_with_func(in, cur_c, next_c, is_hexadecimal_digit);
        if (token.get_token_type() == Token::TokenType::None) {
            in.putback(cur_c);
            return Token(Token::TokenType::IntegerLiteral, "0");
        }
    }
    if (cur_c == '0' && (next_c == 'o' || next_c == 'O')) {
        // octal
    }
    return Token(Token::TokenType::Error);
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
    int next_c = in.peek();

    // skip whitespace chars, transition by whitespace to same starting state
    if (is_whitespace(cur_c)) {
        return retrive_next_token(in);
    }

    // skip comments, if skipped comment also retrieves next token, if didn't returns None token or Error token. Automata notes in function
    Token token_from_skip_comments = skip_comments(in, cur_c, next_c);
    if (token_from_skip_comments.get_token_type() != Token::TokenType::None) return token_from_skip_comments;

    // handle string literals
    if (cur_c == '"' || cur_c == '\''/* || (cur_c == 'b' && (next_c == '"' || next_c == '\''))*/) return handle_string_literals(in, cur_c, next_c);
    // handle bytes literals
    if (cur_c == 'b' && (next_c == '"' || next_c == '\'')) return handle_bytes_literal(in, cur_c, next_c);
    // handle integer and real literals
    if (is_digit(cur_c) || (cur_c == '.' && is_digit(next_c))) {
        return handle_integer_and_real_literals(in, cur_c, next_c);
    }
    // handle Identifiers, Keywords, bool literals
    if (is_letter_or_underscore(cur_c)) {
        return handle_identifiers_keywords_and_bool_literals(in, cur_c, next_c);
    }
    return Token(Token::TokenType::LeftRoundBracket);
}