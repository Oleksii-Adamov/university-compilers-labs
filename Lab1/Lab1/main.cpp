#include <iostream>
#include <fstream>
#include <vector>
#include "Token.h"

bool is_ascii(char c) {
    return static_cast<unsigned char>(c) <= 127;
}
std::string retrive_string_limited_by_char() {
    std::string s;
    return s;
}

/*bool skip_to_char_seq(const std::string& s, int& pos, const std::string& stop_seq) {

}*/

/*void skip_whitespaces(const std::string& s, std::size_t& pos) {
    while (pos < s.size() && (s[pos] == ' ' || s[pos] == '\t' || s[pos] == '\n' || s[pos] == '\r' || s[pos] == '\f')) pos++;
}*/

bool is_whitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f';
}

/*bool skip_comments(const std::string& s, std::size_t& pos) {
    if (pos < s.size() - 1) {
        if (s[pos] == '/' && s[pos + 1] == '/') {
            pos = pos + 2;
            while (pos < s.size() && !(s[pos] == '\n'))
            {
                pos++;
            }
            if (pos < s.size()) {
                pos++;
            }
            return true;
        }
        if (s[pos] == '/' && s[pos + 1] == '*') {
            pos = pos + 2;
            while (pos < s.size() && !(pos < s.size() - 1 && s[pos] == '*' && s[pos+1] == '/'))
            {
                pos++;
            }
            if (pos < s.size()) {
                pos+=2;
                return true;
            }
            else {
                return false;
            }
        }
    }
    return true;
}*/

Token skip_comments(std::istream& in, int& cur_c, int& next_c) {
    if (cur_c == '/' && next_c == '/') {
        cur_c = in.get();
        while (cur_c != EOF && cur_c != '\n')
        {
            cur_c = in.get();
        }
        if (cur_c == EOF) {
            return Token(Token::TokenType::EndOfFile);
        }
        
        pos = pos + 2;
        while (pos < s.size() && !(s[pos] == '\n'))
        {
            pos++;
        }
        if (pos < s.size()) {
            pos++;
        }
        return true;
    }
    if (s[pos] == '/' && s[pos + 1] == '*') {
        pos = pos + 2;
        while (pos < s.size() && !(pos < s.size() - 1 && s[pos] == '*' && s[pos + 1] == '/'))
        {
            pos++;
        }
        if (pos < s.size()) {
            pos += 2;
            return true;
        }
        else {
            return false;
        }
    }
    return true;
}

Token handle_operators_and_punctuation(const std::string& s, std::size_t& pos) {
    if (s[pos] == '(') return Token(Token::TokenType::LeftRoundBracket);
    // all other one symbol Tokens that don't conflict with any longer Tokens
    if (s[pos] == '<') {
        if (pos < s.size() - 1 && s[pos + 1] == '=') return Token(Token::TokenType::RelationalOperator, "<=");
    }
}

Token retrive_next_token(const std::string& s, std::size_t& pos) {
    if (pos )
    if (is_whitespace(s[pos])) {
        pos++;
        return retrive_next_token(s, pos);
    }
    bool is_comments_ok = skip_comments(s, pos);
    if (!is_comments_ok) return Token(Token::TokenType::Error, "unterminated comment");
    return Token(Token::TokenType::LeftRoundBracket);
}

Token retrive_next_token(std::istream& in) {
    int cur_c = in.get();
    if (cur_c == EOF) return Token(Token::TokenType::EndOfFile);
    int next_c = in.peek();
    if (is_whitespace(cur_c)) {
        return retrive_next_token(in);
    }
    bool is_comments_ok = skip_comments(s, pos);
    if (!is_comments_ok) return Token(Token::TokenType::Error, "unterminated comment");
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