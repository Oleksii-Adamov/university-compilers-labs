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

    // if skipped comment also retrieves next token, if didn't returns None token or Error token
    Token skip_comments(std::istream& in, int cur_c, int next_c);

    Token handle_string_literals(std::istream& in, int cur_c, int next_c);

    Token handle_bytes_literal(std::istream& in, int cur_c, int next_c);

    Token build_integer_token(const std::string& read_string, IntegerFormat integer_format);

    Token build_real_token(const std::string& read_string, IntegerFormat integer_format);

    Token build_imaginary_token(const std::string& read_string, IntegerFormat integer_format, bool is_real);

    Token handle_number_literals(std::istream& in, int cur_c, int next_c);

    Token handle_number_literals_with_func(std::istream& in, int cur_c, IntegerFormat integer_format);

    Token handle_identifiers_keywords_and_bool_literals(std::istream& in, int cur_c, int next_c);

    Token handle_operators_and_punctuation(std::istream& in, int cur_c, int next_c);

    Token retrive_next_token(std::istream& in);
};

