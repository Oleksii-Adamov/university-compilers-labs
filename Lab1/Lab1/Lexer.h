#pragma once
#include <fstream>
#include <vector>
#include "Token.h"
#include "KeywordAutomata.h"

class Lexer
{
private:
    static const std::string MAX_DECIMAL_INTEGER;
    static const std::string MAX_OCTAL_INTEGER;
    static const std::size_t MAX_HEXADECIMAL_INTEGER_LENGTH;
    static const std::size_t MAX_BINARY_INTEGER_LENGTH;

    static const std::vector<std::string> KEYWORDS;
    KeywordAutomata keyword_automata;
    // counting lines to notify in which line error occurred
    unsigned int cur_line = 1;
public:
    Lexer();
    bool tokenize_stream(std::istream& in, std::vector<Token>& tokens, std::vector<std::string>& errors);

    bool tokenize_file(std::string file_name, std::vector<Token>& tokens, std::vector<std::string>& errors);
private:

    Token handle_unambiguous_single_char_tokens(int cur_c);

    Token handle_ambiguous_tokens(std::istream& in, int cur_c, int next_c);

    // if skipped comment also retrieves next token, if didn't returns None token or Error token
    Token skip_comments(std::istream& in, int cur_c, int next_c);

    Token handle_string_literals(std::istream& in, int cur_c, int next_c);

    Token handle_interpreted_string_literal(std::istream& in, int cur_c, int terminating_char);
    Token handle_uninterpreted_string_literal(std::istream& in, int cur_c, int terminating_char);
    char interpret_hexadecimal_escape_char(std::istream& in, int cur_c);

    enum class NumberHandlingStage
    {
        WholeNumber,
        FractionalPart,
        ExponentPart
    };

    Token build_integer_token(const std::string& number_string, NumberFormat integer_format, bool is_imaginary);

    Token build_real_token(const std::string& number_string, NumberFormat integer_format, bool is_imaginary);

    Token build_imaginary_token(const std::string& read_string, NumberFormat integer_format, bool is_real);

    Token handle_number_literals(std::istream& in, int cur_c, int next_c);

    Token handle_number_literals_with_format_by_stage(std::istream& in, int& cur_c, NumberFormat integer_format,
        NumberHandlingStage number_handling_stage, std::vector<int>& chars_to_putback);

    Token handle_identifiers_keywords_and_bool_literals(std::istream& in, int cur_c, int next_c);

    Token retrive_next_token(std::istream& in);

    std::string error_string_wrapper(std::string error_discritption);
};

