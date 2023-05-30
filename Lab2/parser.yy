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
%token <ASTNode*> EXPRESSION_SEPARATOR ","
%token <ASTNode*> LEFT_ROUND_BRACKET "("
%token <ASTNode*> RIGHT_ROUND_BRACKET ")"
%token <ASTNode*> LEFT_CURLY_BRACKET "{"
%token <ASTNode*> RIGHT_CURLY_BRACKET "}"
%token <ASTNode*> LEFT_SQUARE_BRACKET "["
%token <ASTNode*> RIGHT_SQUARE_BRACKET "]"
%token <ASTNode*> RANGE_SPECIFIER ".."
%token <ASTNode*> HALF_OPEN_RANGE_SPECIFIER "..<"
%token <ASTNode*> MEMBER_ACCESS "."
%token <ASTNode*> VARIABLE_ARGUMENT_LISTS "..."
%token <ASTNode*> COLUMN ":"
%token <ASTNode*> PUBLIC "public"
%token <ASTNode*> PRIVATE "private"
%token <ASTNode*> CONFIG "config"
%token <ASTNode*> EXTERN "extern"
%token <ASTNode*> EXPORT "export"
%token <ASTNode*> PARAM "param"
%token <ASTNode*> REF "ref"
%token <ASTNode*> VOID "void"
%token <ASTNode*> NOTHING "nothing"
%token <ASTNode*> BOOL "bool"
%token <ASTNode*> INT "int"
%token <ASTNode*> UINT "uint"
%token <ASTNode*> REAL "real"
%token <ASTNode*> IMAG "imag"
%token <ASTNode*> COMPLEX "complex"
%token <ASTNode*> STRING "string"
%token <ASTNode*> BYTES "bytes"
%token <ASTNode*> ENUM "enum"
%token <ASTNode*> RECORD "record"
%token <ASTNode*> CLASS "class"
%token <ASTNode*> OWNED "owned"
%token <ASTNode*> SHARED "shared"
%token <ASTNode*> UNMANAGED "unmanaged"
%token <ASTNode*> BORROWED "borrowed"
%token <ASTNode*> IF "if"
%token <ASTNode*> THEN "then"
%token <ASTNode*> ELSE "else"
%token <ASTNode*> VAR "var"
%token <ASTNode*> CONST "const"
%token <ASTNode*> WHILE "while"
%token <ASTNode*> DO "do"
%token <ASTNode*> FOR "for"
%token <ASTNode*> IN "in"
%token <ASTNode*> OUT "out"
%token <ASTNode*> INOUT "inout"
%token <ASTNode*> TYPE "type"
%token <ASTNode*> INLINE "inline"
%token <ASTNode*> OVERRIDE "override"
%token <ASTNode*> PROC "proc"
%token <ASTNode*> ITER "iter"
%token <ASTNode*> WHERE "where"
%token <ASTNode*> ZIP "zip"
%token <ASTNode*> NEW "new"
%token <ASTNode*> IDENTIFIER
%token <ASTNode*> INTEGER_LITERAL
%token <ASTNode*> BOOL_LITERAL
%token <ASTNode*> REAL_LITERAL
%token <ASTNode*> IMAGINARY_LITERAL
%token <ASTNode*> INTERPRETED_STRING_LITERAL
%token <ASTNode*> UNINTERPRETED_STRING_LITERAL
%token <ASTNode*> INTERPRETED_BYTES_LITERAL
%token <ASTNode*> UNINTERPRETED_BYTES_LITERAL

%nterm <ASTNode*> literal_expression
%nterm <ASTNode*> range_literal
%nterm <ASTNode*> variable_expression
%nterm <ASTNode*> expression
%nterm <ASTNode*> parenthesized_expression
%nterm <ASTNode*> unary_expression
%nterm <ASTNode*> binary_expression
%nterm <ASTNode*> lvalue_expression
%nterm <ASTNode*> call_expression
%nterm <ASTNode*> named_expression_list
%nterm <ASTNode*> named_expression
%nterm <ASTNode*> member_access_expression
%nterm <ASTNode*> field_access_expression
%nterm <ASTNode*> method_call_expression
%nterm <ASTNode*> new_expression
%nterm <ASTNode*> block_statement
%nterm <ASTNode*> expression_statement
%nterm <ASTNode*> assignment_statement
%nterm <ASTNode*> conditional_statement
%nterm <ASTNode*> else_part_opt
%nterm <ASTNode*> ctrl_decl
%nterm <ASTNode*> while_do_statement
%nterm <ASTNode*> do_while_statement
%nterm <ASTNode*> for_statement
%nterm <ASTNode*> index_var_decl
%nterm <ASTNode*> tuple_grouped_identifier_list
%nterm <ASTNode*> identifier_list
%nterm <ASTNode*> iterable_expression
%nterm <ASTNode*> expression_list
%nterm <ASTNode*> variable_declaration_statement
%nterm <ASTNode*> privacy_specifier_opt
%nterm <ASTNode*> config_extern_or_export_opt
%nterm <ASTNode*> variable_kind
%nterm <ASTNode*> variable_declaration_list
%nterm <ASTNode*> variable_declaration
%nterm <ASTNode*> type_part_opt
%nterm <ASTNode*> type_expression
%nterm <ASTNode*> primitive_type
%nterm <ASTNode*> primitive_type_parameter_part_opt
%nterm <ASTNode*> initialization_part_opt
%nterm <ASTNode*> class_declaration_statement
%nterm <ASTNode*> class_inherit_opt
%nterm <ASTNode*> basic_class_type
%nterm <ASTNode*> class_type
%nterm <ASTNode*> class_statement_list_opt
%nterm <ASTNode*> class_statement_list
%nterm <ASTNode*> class_statement
%nterm <ASTNode*> method_declaration_statement
%nterm <ASTNode*> procedure_kind_opt
%nterm <ASTNode*> proc_or_iter
%nterm <ASTNode*> this_intent_opt
%nterm <ASTNode*> argument_list
%nterm <ASTNode*> argument_list_opt
%nterm <ASTNode*> formals_opt
%nterm <ASTNode*> formals
%nterm <ASTNode*> formal
%nterm <ASTNode*> formal_intent_opt
%nterm <ASTNode*> default_expression_opt
%nterm <ASTNode*> variable_argument_expression
%nterm <ASTNode*> return_intent_opt
%nterm <ASTNode*> type_binding
%nterm <ASTNode*> where_clause_opt
%nterm <ASTNode*> function_body
%nterm <ASTNode*> type_declaration_statement
%nterm <ASTNode*> statement
%nterm <ASTNode*> statements_opt

%printer { yyo << *$$; } <*>;

%%
%precedence LOWEST_PREC;
%precedence ",";
%precedence "for";
%precedence "do";
%precedence "then";
%precedence "else";
%left "in";
%right "public" "private" "config" "extern" "export" ":";
%left "by" "#";
%left "||";
%left "&&";
%left EQUALITY_COMP;
%left ORDERED_COMP;
%left ".." "..<";
%left "+" "-";
%left "|";
%left "^";
%left "&";
%left BITWISE_SHIFT;
%right NEG POSITIVE_IDENTITY;
%left "*" "/" "%";
%right "!" "~";
%right "**";
%right "owned" "shared" "borrowed" "unmanaged";
%right "new";
%left "]";
%left ")";
%left ".";

%start unit;
unit: statements_opt  { drv.result = $1;};

statements_opt:
  %empty                 {$$=nullptr;}
| statements_opt statement {$$ = new ASTNode(ASTNodeType::Statements, {$1, $2});};

statement: block_statement | expression_statement | assignment_statement | conditional_statement | while_do_statement
| do_while_statement | for_statement | variable_declaration_statement | type_declaration_statement | method_declaration_statement;

block_statement: "{" statements_opt "}" { $$ = new ASTNode(ASTNodeType::BlockStatement, {$2}); delete $1; delete $3;};

expression_statement: variable_expression ";" { $$ = new ASTNode(ASTNodeType::ExpressionStatement, {$1}); delete $2;}
| call_expression ";" { $$ = new ASTNode(ASTNodeType::ExpressionStatement, {$1}); delete $2;}
| member_access_expression ";" { $$ = new ASTNode(ASTNodeType::ExpressionStatement, {$1}); delete $2;}
| new_expression ";" { $$ = new ASTNode(ASTNodeType::ExpressionStatement, {$1}); delete $2;};

assignment_statement:
  lvalue_expression "=" expression ";" { $$ = new ASTNode(ASTNodeType::AssignmentStatement, {$1, $2, $3});}
| lvalue_expression COMPOUND_ASSIGNMENT expression ";" { $$ = new ASTNode(ASTNodeType::AssignmentStatement, {$1, $2, $3});};

conditional_statement:
  "if" expression "then" statement else_part_opt { $$ = new ASTNode(ASTNodeType::ConditionalStatement, {$2, $4, $5}); delete $1; delete $3;}
| "if" expression block_statement else_part_opt { $$ = new ASTNode(ASTNodeType::ConditionalStatement, {$2, $3, $4}); delete $1;}
| "if" ctrl_decl "then" statement else_part_opt { $$ = new ASTNode(ASTNodeType::ConditionalStatement, {$2, $4, $5}); delete $1; delete $3;}
| "if" ctrl_decl block_statement else_part_opt { $$ = new ASTNode(ASTNodeType::ConditionalStatement, {$2, $3, $4}); delete $1;};

else_part_opt:
  %empty %prec "then" {$$ = nullptr;}
| "else" statement {$$ = $2; delete $1;};

ctrl_decl:
  "var" IDENTIFIER "=" expression { $$ = new ASTNode(ASTNodeType::CtrlDecl, {$1, $2, $4}); delete $3;}
| "const" IDENTIFIER "=" expression { $$ = new ASTNode(ASTNodeType::CtrlDecl, {$1, $2, $4}); delete $3;};

while_do_statement:
  "while" expression "do" statement { $$ = new ASTNode(ASTNodeType::WhileDoStatement, {$2, $4}); delete $1; delete $3;}
| "while" expression block_statement { $$ = new ASTNode(ASTNodeType::WhileDoStatement, {$2, $3}); delete $1;}
| "while" ctrl_decl "do" statement { $$ = new ASTNode(ASTNodeType::WhileDoStatement, {$2, $4}); delete $1; delete $3;}
| "while" ctrl_decl block_statement { $$ = new ASTNode(ASTNodeType::WhileDoStatement, {$2, $3}); delete $1;};

do_while_statement: "do" statement "while" expression ";" { $$ = new ASTNode(ASTNodeType::DoWhileStatement, {$2, $4}); delete $1; delete $3; delete $5;};

for_statement:
  "for" index_var_decl "in" iterable_expression "do" statement { $$ = new ASTNode(ASTNodeType::ForStatement, {$2, $4, $6}); delete $1; delete $3; delete $5;}
| "for" index_var_decl "in" iterable_expression block_statement { $$ = new ASTNode(ASTNodeType::ForStatement, {$2, $4, $5}); delete $1; delete $3;}
| "for" iterable_expression "do" statement { $$ = new ASTNode(ASTNodeType::ForStatement, {$2, $4}); delete $1; delete $3;}
| "for" iterable_expression block_statement { $$ = new ASTNode(ASTNodeType::ForStatement, {$2, $3}); delete $1;};

index_var_decl:
  IDENTIFIER
| tuple_grouped_identifier_list ;

tuple_grouped_identifier_list: "(" identifier_list ")" { $$ = new ASTNode(ASTNodeType::TupleGroupedIdentifierList, {$2}); delete $1; delete $3;};

identifier_list:
  IDENTIFIER { $$ = new ASTNode(ASTNodeType::IdentifierList, {$1});}
| IDENTIFIER "," identifier_list { $$ = new ASTNode(ASTNodeType::IdentifierList, {$1, $3}); delete $2;}
| tuple_grouped_identifier_list
| tuple_grouped_identifier_list "," identifier_list { $$ = new ASTNode(ASTNodeType::IdentifierList, {$1, $3}); delete $2;};

iterable_expression:
  expression
| "zip" "(" expression_list ")" { $$ = $3; delete $1; delete $2; delete $4;};

expression_list:
  expression { $$ = new ASTNode(ASTNodeType::ExpressionList, {$1});}
| expression "," expression_list { $$ = new ASTNode(ASTNodeType::ExpressionList, {$1, $3}); delete $2;};

variable_declaration_statement: privacy_specifier_opt config_extern_or_export_opt variable_kind variable_declaration_list ";" { $$ = new ASTNode(ASTNodeType::VariableDeclarationStatement, {$1, $2, $3, $4});};

privacy_specifier_opt:
  %empty %prec LOWEST_PREC {$$ = nullptr;}
| "public" | "private";

config_extern_or_export_opt:
  %empty %prec LOWEST_PREC {$$ = nullptr;}
| "config" | "extern" | "export" ;

variable_kind:
  "param" { $$ = new ASTNode(ASTNodeType::VariableKind, {$1});}
| "const" { $$ = new ASTNode(ASTNodeType::VariableKind, {$1});}
| "var" { $$ = new ASTNode(ASTNodeType::VariableKind, {$1});}
| "ref" { $$ = new ASTNode(ASTNodeType::VariableKind, {$1});}
| "const" "ref" { $$ = new ASTNode(ASTNodeType::VariableKind, {$1, $2});};

variable_declaration_list:
  variable_declaration { $$ = new ASTNode(ASTNodeType::VariableDeclarationList, {$1});}
| variable_declaration "," variable_declaration_list { $$ = new ASTNode(ASTNodeType::VariableDeclarationList, {$1, $3}); delete $2;};

variable_declaration: identifier_list type_part_opt initialization_part_opt { $$ = new ASTNode(ASTNodeType::VariableDeclaration, {$1, $2, $3});};

type_part_opt:
  %empty %prec LOWEST_PREC {$$ = nullptr;}
| ":" type_expression {$$ = $2; delete $1;};

type_expression: primitive_type | class_type;

primitive_type:
  "void" { $$ = new ASTNode(ASTNodeType::PrimitiveType, {$1});}
| "nothing" { $$ = new ASTNode(ASTNodeType::PrimitiveType, {$1});}
| "bool" { $$ = new ASTNode(ASTNodeType::PrimitiveType, {$1});}
| "int" primitive_type_parameter_part_opt { $$ = new ASTNode(ASTNodeType::PrimitiveType, {$1, $2});}
| "uint" primitive_type_parameter_part_opt { $$ = new ASTNode(ASTNodeType::PrimitiveType, {$1, $2});}
| "real" primitive_type_parameter_part_opt { $$ = new ASTNode(ASTNodeType::PrimitiveType, {$1, $2});}
| "imag" primitive_type_parameter_part_opt { $$ = new ASTNode(ASTNodeType::PrimitiveType, {$1, $2});}
| "complex" primitive_type_parameter_part_opt { $$ = new ASTNode(ASTNodeType::PrimitiveType, {$1, $2});}
| "string" { $$ = new ASTNode(ASTNodeType::PrimitiveType, {$1});}
| "bytes" { $$ = new ASTNode(ASTNodeType::PrimitiveType, {$1});}
| "enum" { $$ = new ASTNode(ASTNodeType::PrimitiveType, {$1});}
| "record" { $$ = new ASTNode(ASTNodeType::PrimitiveType, {$1});}
| "class" { $$ = new ASTNode(ASTNodeType::PrimitiveType, {$1});}
| "owned" { $$ = new ASTNode(ASTNodeType::PrimitiveType, {$1});}
| "shared" { $$ = new ASTNode(ASTNodeType::PrimitiveType, {$1});}
| "unmanaged" { $$ = new ASTNode(ASTNodeType::PrimitiveType, {$1});}
| "borrowed" { $$ = new ASTNode(ASTNodeType::PrimitiveType, {$1});};

primitive_type_parameter_part_opt:
  %empty {$$ = nullptr;}
| parenthesized_expression;

initialization_part_opt:
  %empty %prec LOWEST_PREC {$$ = nullptr;}
| "=" expression {$$ = $2; delete $1;};

class_declaration_statement: "class" IDENTIFIER class_inherit_opt "{" class_statement_list_opt "}" {$$ = new ASTNode(ASTNodeType::ClassDeclarationStatement, {$2, $3, $5}); delete $1; delete $4; delete $6;}

class_inherit_opt:
  %empty %prec LOWEST_PREC {$$ = nullptr;}
| ":" basic_class_type {$$ = $2; delete $1;};

basic_class_type:
  IDENTIFIER { $$ = new ASTNode(ASTNodeType::ClassType, {$1});}
| IDENTIFIER "(" named_expression_list ")" { $$ = new ASTNode(ASTNodeType::ClassType, {$1, $3}); delete $2; delete $4;};

class_type:
basic_class_type
| "owned" basic_class_type { $$ = new ASTNode(ASTNodeType::ClassType, {$1, $2});}
| "shared" basic_class_type { $$ = new ASTNode(ASTNodeType::ClassType, {$1, $2});}
| "borrowed" basic_class_type { $$ = new ASTNode(ASTNodeType::ClassType, {$1, $2});}
| "unmanaged" basic_class_type { $$ = new ASTNode(ASTNodeType::ClassType, {$1, $2});}

class_statement_list_opt:
  %empty {$$ = nullptr;}
| class_statement_list;

class_statement_list:
  class_statement { $$ = new ASTNode(ASTNodeType::ClassStatementList, {$1});}
| class_statement class_statement_list { $$ = new ASTNode(ASTNodeType::ClassStatementList, {$1, $2});};

class_statement: variable_declaration_statement | method_declaration_statement | type_declaration_statement;

method_declaration_statement: procedure_kind_opt proc_or_iter this_intent_opt IDENTIFIER argument_list_opt return_intent_opt type_part_opt where_clause_opt function_body
 { $$ = new ASTNode(ASTNodeType::MethodDeclarationStatement, {$1, $2, $3, nullptr, $4, $5, $6, $7, $8, $9});}
| procedure_kind_opt proc_or_iter this_intent_opt type_binding IDENTIFIER argument_list_opt return_intent_opt type_part_opt where_clause_opt function_body
   { $$ = new ASTNode(ASTNodeType::MethodDeclarationStatement, {$1, $2, $3, $4, $5, $6, $7, $8, $9, $10});};

procedure_kind_opt:
  %empty {$$ = nullptr;}
| "inline"
| "export"
| "extern"
| "override";

proc_or_iter: "proc" | "iter";

this_intent_opt:
%empty {$$ = nullptr;}
| "param"  { $$ = new ASTNode(ASTNodeType::Intent, {$1});}
| "type" { $$ = new ASTNode(ASTNodeType::Intent, {$1});}
| "ref" { $$ = new ASTNode(ASTNodeType::Intent, {$1});}
| "const" "ref" { $$ = new ASTNode(ASTNodeType::Intent, {$1, $2});}
| "const" { $$ = new ASTNode(ASTNodeType::Intent, {$1});};

argument_list_opt:
%empty {$$ = nullptr;}
| argument_list;

argument_list: "(" formals_opt ")" { $$ = new ASTNode(ASTNodeType::ArgumentList, {$2}); delete $1; delete $3;}

formals_opt:
%empty {$$ = nullptr;}
| formals;

formals:
  formal { $$ = new ASTNode(ASTNodeType::ArgumentList, {$1});}
| formal "," formals { $$ = new ASTNode(ASTNodeType::ArgumentList, {$1, $2});};

formal:
  formal_intent_opt IDENTIFIER type_part_opt default_expression_opt { $$ = new ASTNode(ASTNodeType::Formal, {$1, $2, $3, $4});}
| formal_intent_opt IDENTIFIER type_part_opt variable_argument_expression { $$ = new ASTNode(ASTNodeType::Formal, {$1, $2, $3, $4});}
| formal_intent_opt tuple_grouped_identifier_list type_part_opt default_expression_opt { $$ = new ASTNode(ASTNodeType::Formal, {$1, $2, $3, $4});}
| formal_intent_opt tuple_grouped_identifier_list type_part_opt variable_argument_expression { $$ = new ASTNode(ASTNodeType::Formal, {$1, $2, $3, $4});};

formal_intent_opt:
%empty {$$ = nullptr;}
| "const"  { $$ = new ASTNode(ASTNodeType::Intent, {$1});}
| "const" "in" { $$ = new ASTNode(ASTNodeType::Intent, {$1, $2});}
| "const" "ref" { $$ = new ASTNode(ASTNodeType::Intent, {$1, $2});}
| "in" { $$ = new ASTNode(ASTNodeType::Intent, {$1});}
| "out" { $$ = new ASTNode(ASTNodeType::Intent, {$1});}
| "inout" { $$ = new ASTNode(ASTNodeType::Intent, {$1});}
| "ref" { $$ = new ASTNode(ASTNodeType::Intent, {$1});}
| "param" { $$ = new ASTNode(ASTNodeType::Intent, {$1});}
| "type" { $$ = new ASTNode(ASTNodeType::Intent, {$1});};

default_expression_opt:
  %empty %prec LOWEST_PREC {$$ = nullptr;}
| "=" expression {$$ = new ASTNode(ASTNodeType::DefaultExpression, {$2}); delete $1;}

variable_argument_expression:
  "..." expression {$$ = new ASTNode(ASTNodeType::VariableArgumentExpression, {$2}); delete $1;}
| "..." {$$ = new ASTNode(ASTNodeType::VariableArgumentExpression, {nullptr}); delete $1;};

return_intent_opt: this_intent_opt;

type_binding:
  IDENTIFIER "." {$$ = new ASTNode(ASTNodeType::TypeBinding, {$1}); delete $2;}
| parenthesized_expression "." {$$ = new ASTNode(ASTNodeType::TypeBinding, {$1}); delete $2;}

where_clause_opt:
  %empty {$$ = nullptr;}
| "where" expression {$$ = new ASTNode(ASTNodeType::WhereClause, {$2}); delete $1;};

function_body:
  "do" statement {$$ = $2; delete $1;}
| block_statement {$$ = $1;}

type_declaration_statement: class_declaration_statement;

expression: literal_expression | lvalue_expression | unary_expression | binary_expression | new_expression;

literal_expression: INTEGER_LITERAL | range_literal | BOOL_LITERAL | REAL_LITERAL | IMAGINARY_LITERAL | INTERPRETED_STRING_LITERAL | UNINTERPRETED_STRING_LITERAL
| INTERPRETED_BYTES_LITERAL | UNINTERPRETED_BYTES_LITERAL;

range_literal:
  expression ".." expression { $$ = new ASTNode(ASTNodeType::RangeLiteral, {$1, $2, $3});}
| expression "..<" expression { $$ = new ASTNode(ASTNodeType::RangeLiteral, {$1, $2, $3});}
| expression ".." { $$ = new ASTNode(ASTNodeType::RangeLiteral, {$1, $2});}
| ".." expression { $$ = new ASTNode(ASTNodeType::RangeLiteral, {$1, $2});}
| "..<" expression { $$ = new ASTNode(ASTNodeType::RangeLiteral, {$1, $2});}
| ".." { $$ = new ASTNode(ASTNodeType::RangeLiteral, {$1});};

variable_expression: IDENTIFIER;

parenthesized_expression: "(" expression ")" { $$ = $2; delete $1; delete $3;};

lvalue_expression: variable_expression | parenthesized_expression | call_expression | member_access_expression;

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

method_call_expression:
  expression "." IDENTIFIER "(" named_expression_list ")" %prec "." {$$ = new ASTNode(ASTNodeType::MethodCallExpression, {$1, $3, $5}); delete $2; delete $4; delete $6;}
| expression "." IDENTIFIER "[" named_expression_list "]" %prec "." {$$ = new ASTNode(ASTNodeType::MethodCallExpression, {$1, $3, $5}); delete $2; delete $4; delete $6;};


call_expression:
  lvalue_expression "(" named_expression_list ")" { $$ = new ASTNode(ASTNodeType::CallExpression, {$1, $3}); delete $2; delete $4;}
| lvalue_expression "[" named_expression_list "]" { $$ = new ASTNode(ASTNodeType::CallExpression, {$1, $3}); delete $2; delete $4;};

named_expression_list:
  named_expression { $$ = new ASTNode(ASTNodeType::NamedExpressionList, {$1});}
| named_expression "," named_expression_list { $$ = new ASTNode(ASTNodeType::NamedExpressionList, {$1, $3}); delete $2;};

named_expression:
  expression
| IDENTIFIER "=" expression;

member_access_expression: field_access_expression | method_call_expression;


field_access_expression: expression "." IDENTIFIER {$$ = new ASTNode(ASTNodeType::FieldAccessExpression, {$1, $3}); delete $2;};

new_expression: "new" type_expression {$$ = new ASTNode(ASTNodeType::NewExpression, {$2}); delete $1;};
%%

void yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
