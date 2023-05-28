#include "ASTNodeType.hh"

std::ostream& operator<<(std::ostream& out, const ASTNodeType& astNodeType) {
    const char* s = "";
    switch (astNodeType) {
        case ASTNodeType::Identifier: s = "Identifier"; break;
        case ASTNodeType::Keyword: s = "Keyword"; break;
        case ASTNodeType::BoolLiteral: s = "BoolLiteral"; break;
        case ASTNodeType::IntegerLiteral: s = "IntegerLiteral"; break;
        case ASTNodeType::RealLiteral: s = "RealLiteral"; break;
        case ASTNodeType::ImaginaryLiteral: s = "ImaginaryLiteral"; break;
        case ASTNodeType::InterpretedStringLiteral: s = "InterpretedStringLiteral"; break;
        case ASTNodeType::UninterpretedStringLiteral: s = "UninterpretedStringLiteral"; break;
        case ASTNodeType::InterpretedBytesLiteral: s = "InterpretedBytesLiteral"; break;
        case ASTNodeType::UninterpretedBytesLiteral: s = "UninterpretedBytesLiteral"; break;
        case ASTNodeType::Assignment: s = "Assignment"; break;
        case ASTNodeType::CompoundAssignment: s = "CompoundAssignment"; break;
        case ASTNodeType::Swap: s = "Swap"; break;
        case ASTNodeType::RangeSpecifier: s = "RangeSpecifier"; break;
        case ASTNodeType::RangeDomainStrideSpecifier: s = "RangeDomainStrideSpecifier"; break;
        case ASTNodeType::RangeCount: s = "RangeCount"; break;
        case ASTNodeType::VariableArgumentLists: s = "VariableArgumentLists"; break;
        case ASTNodeType::Plus: s = "Plus"; break;
        case ASTNodeType::Minus: s = "Minus"; break;
        case ASTNodeType::Multiplication: s = "Multiplication"; break;
        case ASTNodeType::Division: s = "Division"; break;
        case ASTNodeType::Modulus: s = "Modulus"; break;
        case ASTNodeType::Exponentiation: s = "Exponentiation"; break;
        case ASTNodeType::BitwiseComplement: s = "BitwiseComplement"; break;
        case ASTNodeType::BitwiseAnd: s = "BitwiseAnd"; break;
        case ASTNodeType::BitwiseOr: s = "BitwiseOr"; break;
        case ASTNodeType::BitwiseXor: s = "BitwiseXor"; break;
        case ASTNodeType::BitwiseShift: s = "BitwiseShift"; break;
        case ASTNodeType::ExclamationMark: s = "ExclamationMark"; break;
        case ASTNodeType::LogicalAnd: s = "LogicalAnd"; break;
        case ASTNodeType::LogicalOr: s = "LogicalOr"; break;
        case ASTNodeType::OrderedComp: s = "OrderedComp"; break;
        case ASTNodeType::EqualityComp: s = "EqualityComp"; break;
        case ASTNodeType::By: s = "By"; break;
        case ASTNodeType::TypeSpecifier: s = "TypeSpecifier"; break;
        case ASTNodeType::StatementSeparator: s = "StatementSeparator"; break;
        case ASTNodeType::ExpressionSeparator: s = "ExpressionSeparator"; break;
        case ASTNodeType::MemberAccess: s = "MemberAccess"; break;
        case ASTNodeType::TypeQuery: s = "TypeQuery"; break;
        case ASTNodeType::LeftRoundBracket: s = "LeftRoundBracket"; break;
        case ASTNodeType::RightRoundBracket: s = "RightRoundBracket"; break;
        case ASTNodeType::LeftSquareBracket: s = "LeftSquareBracket"; break;
        case ASTNodeType::RightSquareBracket: s = "RightSquareBracket"; break;
        case ASTNodeType::LeftCurlyBracket: s = "LeftCurlyBracket"; break;
        case ASTNodeType::RightCurlyBracket: s = "RightCurlyBracket"; break;
        case ASTNodeType::UnaryExpression: s = "UnaryExpression"; break;
        case ASTNodeType::BinaryExpression: s = "BinaryExpression"; break;
        case ASTNodeType::ExpressionStatement: s = "ExpressionStatement"; break;
        case ASTNodeType::Statements: s = "Statements"; break;
    }

    return out << s;
}