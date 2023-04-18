#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Token.h"

const std::string KEYWORDS[] = {"hi","hello"};

bool is_whitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f';
}

bool is_digit(char c) {

}

bool is_letter_or_underscore(char c) {

}

bool is_legal_identifier_char(char c) {
    return is_letter_or_underscore(c) || is_digit(c) || c == '$';
}

// if skipped comment also retrieves next token, if didn't returns None token or Error token
Token skip_comments(std::istream& in, int cur_c, int next_c) {
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

Token handle_string_literals(std::istream& in, int cur_c, int next_c) {

}

Token handle_bytes_literal(std::istream& in, int cur_c, int next_c) {

}

Token handle_integer_and_real_literals(std::istream& in, int cur_c, int next_c) {

}

Token handle_identifiers_and_keywords(std::istream& in, int cur_c, int next_c) {
    // check for first character was done already, and variants of first character is subset of variants of other characters, so used generalized variant
    std::stringstream read_string;
    while (true) {
        int c_i = in.get();
        if (is_legal_identifier_char(c_i)) {
            char c = static_cast<char>(c_i);
            read_string << c;
        }
        else {
            in.putback(c);
            break;
        }
    }
}

Token handle_operators_and_punctuation(const std::string& s, std::size_t& pos) {
    if (s[pos] == '(') return Token(Token::TokenType::LeftRoundBracket);
    // all other one symbol Tokens that don't conflict with any longer Tokens
    if (s[pos] == '<') {
        if (pos < s.size() - 1 && s[pos + 1] == '=') return Token(Token::TokenType::RelationalOperator, "<=");
    }
}

Token retrive_next_token(std::istream& in) {
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
    // handle Identifiers and Keywords
    if (is_letter_or_underscore(cur_c)) {
        return handle_identifiers_and_keywords(in, cur_c, next_c);
    }
    return Token(Token::TokenType::LeftRoundBracket);
}

 bool tokenize_stream(std::istream& in, std::vector<Token>& tokens) {
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

bool tokenize_file(std::string file_name, std::vector<Token>& tokens) {
    std::ifstream in(file_name);
    return tokenize_stream(in, tokens);
}

int main()
{
    char** keywords = [["hi"], ["hello"]];
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file