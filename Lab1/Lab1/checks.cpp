#include "checks.h"
#include <iostream>
bool is_lowercase_letter(char c) {
	return c >= 'a' && c <= 'z';
}

bool is_whitespace(char c)
{
    return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f';
}

bool is_digit(char c)
{
    return c >= '0' && c <= '9';
}

bool is_hexadecimal_digit(char c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}

bool is_octal_digit(char c) {
    return (c >= '0' && c <= '7');
}

bool is_binary_digit(char c) {
    return c == '0' || c == '1';
}

bool (*get_check_digit_func(NumberFormat integer_format))(char) {
    bool (*is_acceptable_digit)(char) = nullptr;
    if (integer_format == NumberFormat::binary) {
        is_acceptable_digit = is_binary_digit;
    }
    if (integer_format == NumberFormat::octal) {
        is_acceptable_digit = is_octal_digit;
    }
    if (integer_format == NumberFormat::hexadecimal) {
        is_acceptable_digit = is_hexadecimal_digit;
    }
    if (integer_format == NumberFormat::decimal) {
        is_acceptable_digit = is_digit;
    }
    return is_acceptable_digit;
}

bool is_sign(char c) {
    return c == '+' || c == '-';
}

bool is_e_exponent(char c) {
    return c == 'e' || c == 'E';
}

bool is_p_exponent(char c) {
    return c == 'p' || c == 'P';
}

bool is_letter_or_underscore(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

bool is_legal_identifier_char(char c)
{
    return is_letter_or_underscore(c) || is_digit(c) || c == '$';
}

bool is_acceptable_simple_escape_char(int c) {
    return c == '\'' || c == '"' || c == '?' || c == '\\' || c == 'a' || c == 'b' || c == 'f' || c == 'n' || c == 'r' || c == 't' || c == 'v';
}

char escape_char(char c) {
    switch (c)
    {
    case '\'': return '\'';
    case '"': return '"';
    case '?': return '?';
    case '\\': return '\\';
    case 'a': return '\a';
    case 'b': return '\b';
    case 'f': return '\f';
    case 'n': return '\n';
    case 'r': return '\r';
    case 't': return '\t';
    case 'v': return '\v';
    default: throw std::invalid_argument("unchecked invalid escape char");
    }
}

int hexadecimal_digit_to_int(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    else if (c >= 'a' && c <= 'f') return (c - 'a') + 10;
    else if (c >= 'A' && c <= 'F') return (c - 'A') + 10;
    else throw std::invalid_argument("not hexadecimal digit in hexadecimal_digit_to_int");
}