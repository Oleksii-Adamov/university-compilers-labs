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

%token <ASTNode*> BINARY_OPERATOR
%token <ASTNode*> IDENTIFIER
%token <ASTNode*> INTEGER_LITERAL
%token <ASTNode*> STATEMENT_SEPARATOR
%nterm <ASTNode*> literal_expression
%nterm <ASTNode*> variable_expression
%nterm <ASTNode*> expression
%nterm <ASTNode*> binary_expression
%nterm <ASTNode*> statement
%nterm <ASTNode*> statements

%printer { yyo << *$$; } <*>;

%%
%start unit;
unit: statements  { drv.result = $1; std::cout << "Start symbol " << *$1 << "\n";};

statements:
  %empty                 {$$ = new ASTNode("nothing", {}); std::cout << *$$ << " " << $$ << "\n";}
| statements statement {$$ = new ASTNode("statements", {$1, $2}); std::cout << *$$ << " " << $$ << "\n";};

statement: expression STATEMENT_SEPARATOR { $$ = new ASTNode("statement", {$1, $2});  std::cout << *$$ << " " << $$ << "\n";};

expression:
  literal_expression { $$ = $1;  std::cout << *$$ << " " << $$ << "\n";}
| variable_expression { $$ = $1;  std::cout << *$$ << " " << $$ << "\n";}
| binary_expression { $$ = $1;  std::cout << *$$ << " " << $$ << "\n";};

literal_expression: INTEGER_LITERAL { $$ = new ASTNode("literal_expression", {$1});  std::cout << *$$ << " " << $$ << "\n";};
variable_expression: IDENTIFIER { $$ = new ASTNode("variable_expression", {$1});  std::cout << *$$ << " " << $$ << "\n";};
binary_expression: expression BINARY_OPERATOR expression { $$ = new ASTNode("binary_expression", {$1, $2, $3});  std::cout << *$$ << " " << $$ << "\n";};
%%

void yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
