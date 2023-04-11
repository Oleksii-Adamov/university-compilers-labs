#pragma once
#include<string>
class Token
{
public:
	enum class TokenType {
		OneLineComment,
		MultiLineCommentOpening,
		MultiLineCommentEnclosing,
		WhiteSpace,

		Identifier,
		Keyword,

		BoolLiteral,
		IntegerLiteral,
		RealLiteral,
		ImaginaryLiteral,
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
		LogicalBitwiseOperator,
		RelationalOperator,
		ArithmeticOperator,
		TypeSpecifier,
		StatementSeparator,
		ExpressionSeparator,
		MemberAccess,
		TypeQuery,
		StringDelimiter,

		LeftRoundBracket,
		RightRoundBracket,
		LeftSquareBracket,
		RightSquareBracket,
		LeftCurlyBracket,
		RightCurlyBracket
	};
private: 
	TokenType token_type;
	std::string token_value;
public:
	Token(TokenType token_type, std::string token_value = "");
	TokenType get_token_type();
	std::string get_token_value();
};

