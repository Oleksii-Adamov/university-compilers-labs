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

bool is_interpreted_string_char(int c) {
    return (c != '\n' && c != EOF)
}