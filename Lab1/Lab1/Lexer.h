#pragma once
#include <fstream>
#include <vector>
#include "Token.h"
#include "KeywordAutomata.h"

class Lexer
{
private:
    static const std::vector<std::string> KEYWORDS;
    KeywordAutomata keyword_automata;
public:
    Lexer();
    bool tokenize_stream(std::istream& in, std::vector<Token>& tokens);

    bool tokenize_file(std::string file_name, std::vector<Token>& tokens);
private:
    bool is_whitespace(char c);

    bool is_digit(char c);

    bool is_letter_or_underscore(char c);

    bool is_legal_identifier_char(char c);

    // if skipped comment also retrieves next token, if didn't returns None token or Error token
    Token skip_comments(std::istream& in, int cur_c, int next_c);

    Token handle_string_literals(std::istream& in, int cur_c, int next_c);

    Token handle_bytes_literal(std::istream& in, int cur_c, int next_c);

    Token handle_integer_and_real_literals(std::istream& in, int cur_c, int next_c);

    Token handle_identifiers_keywords_and_bool_literals(std::istream& in, int cur_c, int next_c);

    Token handle_operators_and_punctuation(std::istream& in, int cur_c, int next_c);

    Token retrive_next_token(std::istream& in);
};

