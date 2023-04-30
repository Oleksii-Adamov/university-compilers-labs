#include <iostream>
#include <fstream>
#include "Lexer.h"

void output_to_stream(std::ostream& out, bool success, const std::vector<Token>& tokens, const std::vector<std::string>& errors) {
    if (!success) {
        out << "Errors:\n";
        for (std::size_t i = 0; i < errors.size(); i++) {
            out << errors[i] << "\n";
        }
    }
    out << "Tokens:" << "\n";
    for (std::size_t i = 0; i < tokens.size(); i++) {
        out << tokens[i] << "\n";
    }
}

int main()
{
    //std::string input_file_name = "full_test_input.txt";
    //std::string output_file_name = "full_test_output.txt";
    std::string input_file_name = "demo_input.txt";
    std::string output_file_name = "demo_output.txt";

    std::ofstream out(output_file_name);
    Lexer lexer;
    std::vector<Token> tokens;
    std::vector<std::string> errors;
    try {
        bool success = lexer.tokenize_file(input_file_name, tokens, errors);
        output_to_stream(out, success, tokens, errors);
        output_to_stream(std::cout, success, tokens, errors);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    out.close();
}
