#pragma once
#include<string>
class Token
{
public:
	enum class TokenType {
		/*OneLineComment,
		MultiLineCommentOpening,
		MultiLineCommentEnclosing,
		WhiteSpace,*/

		Identifier,
		Keyword,

		BoolLiteral,

		IntegerLiteralDecimal,
		IntegerLiteralHexadecimal,
		IntegerLiteralOctal,
		IntegerLiteralBinary,

		RealLiteralDecimal,
		RealLiteralHexadecimal,

		ImaginaryIntegerLiteralDecimal,
		ImaginaryIntegerLiteralHexadecimal,
		ImaginaryIntegerLiteralOctal,
		ImaginaryIntegerLiteralBinary,
		ImaginaryRealLiteralDecimal,
		ImaginaryRealLiteralHexadecimal,

		InterpretedStringLiteral,
		UninterpretedStringLiteral,
		InterpretedBytesLiteral,
		UninterpretedBytesLiteral,

		Assignment,
		CompoundAssignment,
		Swap,
		RangeSpecifier,
		RangeDomainStrideSpecifier,
		RangeCountOperator,
		VariableArgumentLists,
		LogicalOperator,
		BitwiseOperator,
		RelationalOperator,
		ArithmeticOperator,
		TypeSpecifier,
		StatementSeparator,
		ExpressionSeparator,
		MemberAccess,
		TypeQuery,

		LeftRoundBracket,
		RightRoundBracket,
		LeftSquareBracket,
		RightSquareBracket,
		LeftCurlyBracket,
		RightCurlyBracket,

		Error,
		EndOfFile,
		None
	};
private: 
	TokenType token_type;
	std::string token_value;
public:
	Token(TokenType token_type, std::string token_value = "");
	TokenType get_token_type() const;
	std::string get_token_value() const;
};

std::ostream& operator<<(std::ostream& out, const Token::TokenType& token_type);
std::ostream& operator<<(std::ostream& out, Token const& token);

