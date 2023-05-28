#ifndef LAB2_ASTNODETYPE_HH
#define LAB2_ASTNODETYPE_HH

#include <iostream>

enum class ASTNodeType {
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
    RangeCount,
    VariableArgumentLists,
    Plus,
    Minus,
    Multiplication,
    Division,
    Modulus,
    Exponentiation,
    BitwiseComplement,
    BitwiseAnd,
    BitwiseOr,
    BitwiseXor,
    BitwiseShift,
    ExclamationMark,
    LogicalAnd,
    LogicalOr,
    OrderedComp,
    EqualityComp,
    By,
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

    BinaryExpression,
    ExpressionStatement,
    Statements,

};

std::ostream& operator<<(std::ostream& out, const ASTNodeType& node);


#endif //LAB2_ASTNODETYPE_HH
