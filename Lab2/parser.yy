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
%token <ASTNode*> ASSIGNMENT "="
%token <ASTNode*> COMPOUND_ASSIGNMENT
%token <ASTNode*> STATEMENT_SEPARATOR ";"
%token <ASTNode*> LEFT_ROUND_BRACKET "("
%token <ASTNode*> RIGHT_ROUND_BRACKET ")"
%token <ASTNode*> LEFT_CURLY_BRACKET "{"
%token <ASTNode*> RIGHT_CURLY_BRACKET "}"
%token <ASTNode*> IF "if"
%token <ASTNode*> THEN "then"
%token <ASTNode*> ELSE "else"
%token <ASTNode*> VAR "var"
%token <ASTNode*> CONST "const"
%token <ASTNode*> WHILE "while"
%token <ASTNode*> DO "do"
%token <ASTNode*> IDENTIFIER
%token <ASTNode*> INTEGER_LITERAL

%nterm <ASTNode*> literal_expression
%nterm <ASTNode*> variable_expression
%nterm <ASTNode*> expression
%nterm <ASTNode*> parenthesized_expression
%nterm <ASTNode*> unary_expression
%nterm <ASTNode*> binary_expression
%nterm <ASTNode*> lvalue_expression

%nterm <ASTNode*> block_statement
%nterm <ASTNode*> expression_statement
%nterm <ASTNode*> assignment_statement
%nterm <ASTNode*> conditional_statement
%nterm <ASTNode*> else_part_opt
%nterm <ASTNode*> ctrl_decl
%nterm <ASTNode*> while_do_statement
%nterm <ASTNode*> do_while_statement
%nterm <ASTNode*> statement
%nterm <ASTNode*> statements_opt

%printer { yyo << *$$; } <*>;

%%
%precedence "then";
%precedence "else";
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
unit: statements_opt  { drv.result = $1;};

statements_opt:
  %empty                 {$$ = nullptr;}
| statements_opt statement {$$ = new ASTNode(ASTNodeType::Statements, {$1, $2});};

statement: block_statement | expression_statement | assignment_statement | conditional_statement | while_do_statement
| do_while_statement;
block_statement: "{" statements_opt "}" { $$ = new ASTNode(ASTNodeType::BlockStatement, {$2}); delete $1; delete $3;};
expression_statement: variable_expression ";" { $$ = new ASTNode(ASTNodeType::ExpressionStatement, {$1}); delete $2;};
assignment_statement:
  lvalue_expression "=" expression ";" { $$ = new ASTNode(ASTNodeType::AssignmentStatement, {$1, $2, $3});}
| lvalue_expression COMPOUND_ASSIGNMENT expression ";" { $$ = new ASTNode(ASTNodeType::AssignmentStatement, {$1, $2, $3});};

conditional_statement:
  "if" expression "then" statement else_part_opt { $$ = new ASTNode(ASTNodeType::ConditionalStatement, {$2, $4, $5}); delete $1; delete $3;}
| "if" expression block_statement else_part_opt { $$ = new ASTNode(ASTNodeType::ConditionalStatement, {$2, $3, $4}); delete $1;}
| "if" ctrl_decl "then" statement else_part_opt { $$ = new ASTNode(ASTNodeType::ConditionalStatement, {$2, $4, $5}); delete $1; delete $3;}
| "if" ctrl_decl block_statement else_part_opt { $$ = new ASTNode(ASTNodeType::ConditionalStatement, {$2, $3, $4}); delete $1;};
else_part_opt:
  %empty {$$ = nullptr;}
| "else" statement {$$ = $2; delete $1;};
ctrl_decl:
  "var" IDENTIFIER "=" expression { $$ = new ASTNode(ASTNodeType::CtrlDecl, {$1, $2, $4}); delete $3;}
| "const" IDENTIFIER "=" expression { $$ = new ASTNode(ASTNodeType::CtrlDecl, {$1, $2, $4}); delete $3;};

while_do_statement:
  "while" expression "do" statement { $$ = new ASTNode(ASTNodeType::WhileDoStatement, {$2, $4}); delete $1; delete $3;}
| "while" expression block_statement { $$ = new ASTNode(ASTNodeType::WhileDoStatement, {$2, $3}); delete $1;}
| "while" ctrl_decl "do" statement { $$ = new ASTNode(ASTNodeType::WhileDoStatement, {$2, $4}); delete $1; delete $3;}
| "while" ctrl_decl block_statement { $$ = new ASTNode(ASTNodeType::WhileDoStatement, {$2, $3}); delete $1;}

do_while_statement: "do" statement "while" expression ";" { $$ = new ASTNode(ASTNodeType::DoWhileStatement, {$2, $4}); delete $1; delete $3; delete $5;}

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
