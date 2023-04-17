#include "Token.h"

Token::Token(TokenType token_type, std::string token_value)
    : token_type(token_type), token_value(token_value)
{
}

Token::TokenType Token::get_token_type()
{
    return token_type;
}

std::string Token::get_token_value()
{
    return token_value;
}
