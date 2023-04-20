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

bool Lexer::is_whitespace(char c)
{
    return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f';
}

bool Lexer::is_digit(char c)
{
    return c >= '0' && c <= '9';
}

bool Lexer::is_letter_or_underscore(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

bool Lexer::is_legal_identifier_char(char c)
{
    return is_letter_or_underscore(c) || is_digit(c) || c == '$';
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

Token Lexer::handle_integer_and_real_literals(std::istream& in, int cur_c, int next_c)
{
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
    if (is_digit(cur_c)) {
        return handle_integer_and_real_literals(in, cur_c, next_c);
    }
    // handle Identifiers, Keywords, bool literals
    if (is_letter_or_underscore(cur_c)) {
        return handle_identifiers_keywords_and_bool_literals(in, cur_c, next_c);
    }
    return Token(Token::TokenType::LeftRoundBracket);
}