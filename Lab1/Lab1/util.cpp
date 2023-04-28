#include <iostream>

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