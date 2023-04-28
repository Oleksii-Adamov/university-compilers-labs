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
	case Token::TokenType::IntegerLiteralDecimal: s = "IntegerLiteralDecimal"; break;
	case Token::TokenType::IntegerLiteralHexadecimal: s = "IntegerLiteralHexadecimal"; break;
	case Token::TokenType::IntegerLiteralOctal: s = "IntegerLiteralOctal"; break;
	case Token::TokenType::IntegerLiteralBinary: s = "IntegerLiteralBinary"; break;
	case Token::TokenType::RealLiteralDecimal: s = "RealLiteralDecimal"; break;
	case Token::TokenType::RealLiteralHexadecimal: s = "RealLiteralHexadecimal"; break;
	case Token::TokenType::ImaginaryIntegerLiteralDecimal: s = "ImaginaryIntegerLiteralDecimal"; break;
	case Token::TokenType::ImaginaryIntegerLiteralHexadecimal: s = "ImaginaryIntegerLiteralHexadecimal"; break;
	case Token::TokenType::ImaginaryIntegerLiteralOctal: s = "ImaginaryIntegerLiteralOctal"; break;
	case Token::TokenType::ImaginaryIntegerLiteralBinary: s = "ImaginaryIntegerLiteralBinary"; break;
	case Token::TokenType::ImaginaryRealLiteralDecimal: s = "ImaginaryRealLiteralDecimal"; break;
	case Token::TokenType::ImaginaryRealLiteralHexadecimal: s = "ImaginaryRealLiteralHexadecimal"; break;
	case Token::TokenType::InterpretedStringLiteral: s = "InterpretedStringLiteral"; break;
	case Token::TokenType::UninterpretedStringLiteral: s = "UninterpretedStringLiteral"; break;
	case Token::TokenType::InterpretedBytesLiteral: s = "InterpretedBytesLiteral"; break;
	case Token::TokenType::UninterpretedBytesLiteral: s = "UninterpretedBytesLiteral"; break;
	case Token::TokenType::Assignment: s = "Assignment"; break;
	case Token::TokenType::CompoundAssignment: s = "CompoundAssignment"; break;
	case Token::TokenType::Swap: s = "Swap"; break;
	case Token::TokenType::RangeSpecifier: s = "RangeSpecifier"; break;
	case Token::TokenType::RangeDomainStrideSpecifier: s = "RangeDomainStrideSpecifier"; break;
	case Token::TokenType::RangeCountOperator: s = "RangeCountOperator"; break;
	case Token::TokenType::VariableArgumentLists: s = "VariableArgumentLists"; break;
	case Token::TokenType::LogicalBitwiseOperator: s = "LogicalBitwiseOperator"; break;
	case Token::TokenType::RelationalOperator: s = "RelationalOperator"; break;
	case Token::TokenType::ArithmeticOperator: s = "ArithmeticOperator"; break;
	case Token::TokenType::TypeSpecifier: s = "TypeSpecifier"; break;
	case Token::TokenType::StatementSeparator: s = "StatementSeparator"; break;
	case Token::TokenType::ExpressionSeparator: s = "ExpressionSeparator"; break;
	case Token::TokenType::MemberAccess: s = "MemberAccess"; break;
	case Token::TokenType::TypeQuery: s = "TypeQuery"; break;
	case Token::TokenType::LeftRoundBracket: s = "LeftRoundBracket"; break;
	case Token::TokenType::RightRoundBracket: s = "RightRoundBracket"; break;
	case Token::TokenType::LeftSquareBracket: s = "LeftSquareBracket"; break;
	case Token::TokenType::RightSquareBracket: s = "RightSquareBracket"; break;
	case Token::TokenType::LeftCurlyBracket: s = "LeftCurlyBracket"; break;
	case Token::TokenType::RightCurlyBracket: s = "RightCurlyBracket"; break;
	case Token::TokenType::Error: s = "Error"; break;
	case Token::TokenType::EndOfFile: s = "EndOfFile"; break;
	case Token::TokenType::None: s = "None"; break;
	}

	return out << s;
}

std::ostream& operator<<(std::ostream& out, Token const& token) {
	return out << '(' << token.get_token_type() << ", " << token.get_token_value() << ')';
}