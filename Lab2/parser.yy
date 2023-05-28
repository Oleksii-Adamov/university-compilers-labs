%skeleton "lalr1.cc" // -*- C++ -*-
%require "3.8.1"
%header

%define api.token.raw

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
  # include <string>
  # include "ASTNode.hh"
  # include <iostream>
  class driver;
}

// The parsing context.
%param { driver& drv }

%locations

%define parse.trace
%define parse.error detailed
%define parse.lac full

%code {
# include "driver.hh"
}

%define api.token.prefix {TOK_}

%token <ASTNode*> PLUS "+"
%token <ASTNode*> MINUS "-"
%token <ASTNode*> MULTIPLICATION "*"
%token <ASTNode*> DIVISION "/"
%token <ASTNode*> MODULUS "%"
%token <ASTNode*> EXPONENTIATION "**"
%token <ASTNode*> BITWISE_COMPLEMENT "~"
%token <ASTNode*> BITWISE_AND "&"
%token <ASTNode*> BITWISE_OR "|"
%token <ASTNode*> BITWISE_XOR "^"
%token <ASTNode*> BITWISE_SHIFT
%token <ASTNode*> EXCLAMATION_MARK "!"
%token <ASTNode*> LOGICAL_AND "&&"
%token <ASTNode*> LOGICAL_OR "||"
%token <ASTNode*> ORDERED_COMP
%token <ASTNode*> EQUALITY_COMP
%token <ASTNode*> BY "by"
%token <ASTNode*> RANGE_COUNT "#"
%token <ASTNode*> ASSIGNMENT_OP
%token <ASTNode*> STATEMENT_SEPARATOR ";"
%token <ASTNode*> LEFT_ROUND_BRACKET "("
%token <ASTNode*> RIGHT_ROUND_BRACKET ")"
%token <ASTNode*> LEFT_CURLY_BRACKET "{"
%token <ASTNode*> RIGHT_CURLY_BRACKET "}"
%token <ASTNode*> IDENTIFIER
%token <ASTNode*> INTEGER_LITERAL
%nterm <ASTNode*> literal_expression
%nterm <ASTNode*> variable_expression
%nterm <ASTNode*> expression
%nterm <ASTNode*> parenthesized_expression
%nterm <ASTNode*> unary_expression
%nterm <ASTNode*> binary_expression
%nterm <ASTNode*> lvalue_expression
%nterm <ASTNode*> expression_statement
%nterm <ASTNode*> assignment_statement
%nterm <ASTNode*> statement
%nterm <ASTNode*> statements

%printer { yyo << *$$; } <*>;

%%
%left "by" "#";
%left "||";
%left "&&";
%left EQUALITY_COMP;
%left ORDERED_COMP;
%left "+" "-";
%left "|";
%left "^";
%left "&";
%left BITWISE_SHIFT;
%right NEG POSITIVE_IDENTITY;
%left "*" "/" "%";
%right "!" "~";
%right "**";
%left HIGHEST_PREC;

%start unit;
unit: statements  { drv.result = $1;};

statements:
  %empty                 {$$ = nullptr;}
| statements statement {$$ = new ASTNode(ASTNodeType::Statements, {$1, $2});};

statement: expression_statement | assignment_statement;

expression_statement: variable_expression ";" { $$ = new ASTNode(ASTNodeType::ExpressionStatement, {$1}); delete $2;};
assignment_statement: lvalue_expression ASSIGNMENT_OP expression ";" { $$ = new ASTNode(ASTNodeType::AssignmentStatement, {$1, $2, $3});}

expression:
  literal_expression
| variable_expression
| parenthesized_expression
| lvalue_expression
| unary_expression
| binary_expression;

literal_expression: INTEGER_LITERAL;
variable_expression: IDENTIFIER;
parenthesized_expression: "(" expression ")" %prec HIGHEST_PREC { $$ = $2; delete $1; delete $3;};
lvalue_expression:
  variable_expression
| parenthesized_expression;

unary_expression:
  "+" expression %prec POSITIVE_IDENTITY { $$ = new ASTNode(ASTNodeType::UnaryExpression, {$1, $2});}
| "-" expression %prec NEG { $$ = new ASTNode(ASTNodeType::UnaryExpression, {$1, $2});}
| "~" expression { $$ = new ASTNode(ASTNodeType::UnaryExpression, {$1, $2});}
| "!" expression { $$ = new ASTNode(ASTNodeType::UnaryExpression, {$1, $2});}
binary_expression:
  expression "+" expression { $$ = new ASTNode(ASTNodeType::BinaryExpression, {$1, $2, $3});}
| expression "-" expression { $$ = new ASTNode(ASTNodeType::BinaryExpression, {$1, $2, $3});}
| expression "*" expression { $$ = new ASTNode(ASTNodeType::BinaryExpression, {$1, $2, $3});}
| expression "/" expression { $$ = new ASTNode(ASTNodeType::BinaryExpression, {$1, $2, $3});}
| expression "%" expression { $$ = new ASTNode(ASTNodeType::BinaryExpression, {$1, $2, $3});}
| expression "**" expression { $$ = new ASTNode(ASTNodeType::BinaryExpression, {$1, $2, $3});}
| expression "&" expression { $$ = new ASTNode(ASTNodeType::BinaryExpression, {$1, $2, $3});}
| expression "|" expression { $$ = new ASTNode(ASTNodeType::BinaryExpression, {$1, $2, $3});}
| expression "^" expression { $$ = new ASTNode(ASTNodeType::BinaryExpression, {$1, $2, $3});}
| expression BITWISE_SHIFT expression { $$ = new ASTNode(ASTNodeType::BinaryExpression, {$1, $2, $3});}
| expression "&&" expression { $$ = new ASTNode(ASTNodeType::BinaryExpression, {$1, $2, $3});}
| expression "||" expression { $$ = new ASTNode(ASTNodeType::BinaryExpression, {$1, $2, $3});}
| expression EQUALITY_COMP expression { $$ = new ASTNode(ASTNodeType::BinaryExpression, {$1, $2, $3});}
| expression ORDERED_COMP expression { $$ = new ASTNode(ASTNodeType::BinaryExpression, {$1, $2, $3});}
| expression "by" expression { $$ = new ASTNode(ASTNodeType::BinaryExpression, {$1, $2, $3});}
| expression "#" expression { $$ = new ASTNode(ASTNodeType::BinaryExpression, {$1, $2, $3});};
%%

void yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
