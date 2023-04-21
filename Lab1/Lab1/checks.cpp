#include "checks.h"

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

bool is_letter_or_underscore(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

bool is_legal_identifier_char(char c)
{
    return is_letter_or_underscore(c) || is_digit(c) || c == '$';
}