#include "Token.h"
#include <iostream>

Token::Token(TokenType token_type, std::string token_value)
    : token_type(token_type), token_value(token_value)
{
}

Token::TokenType Token::get_token_type() const
{
    return token_type;
}

std::string Token::get_token_value() const
{
    return token_value;
}

std::ostream& operator<<(std::ostream& out, const Token::TokenType& token_type) {
	const char* s = "";
	switch (token_type) {
	case Token::TokenType::Identifier: s = "Identifier"; break;
	case Token::TokenType::Keyword: s = "Keyword"; break;
	case Token::TokenType::BoolLiteral: s = "BoolLiteral"; break;
	case Token::TokenType::Error: s = "Error"; break;
	case Token::TokenType::EndOfFile: s = "EndOfFile"; break;
	case Token::TokenType::None: s = "None"; break;
	}

	return out << s;
}

std::ostream& operator<<(std::ostream& out, Token const& token) {
	return out << '(' << token.get_token_type() << ", " << token.get_token_value() << ')';
}