#pragma once

bool is_lowercase_letter(char c);

bool is_whitespace(char c);

bool is_digit(char c);

bool is_hexadecimal_digit(char c);

bool is_octal_digit(char c);

bool is_binary_digit(char c);

enum class IntegerFormat {
	decimal,
	hexadecimal,
	octal,
	binary
};

bool (*get_check_digit_func(IntegerFormat integer_format))(char);

bool is_sign(char c);

bool is_e_exponent(char c);

bool is_p_exponent(char c);

bool is_letter_or_underscore(char c);

bool is_legal_identifier_char(char c);