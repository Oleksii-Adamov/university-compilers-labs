%{ /* -*- C++ -*- */
# include <cerrno>
# include <climits>
# include <cstdlib>
# include <cstring> // strerror
# include <string>
# include "driver.hh"
# include "parser.hh"
# include "ASTNode.hh"
%}

%{
#if defined __clang__
# define CLANG_VERSION (__clang_major__ * 100 + __clang_minor__)
#endif

// Clang and ICC like to pretend they are GCC.
#if defined __GNUC__ && !defined __clang__ && !defined __ICC
# define GCC_VERSION (__GNUC__ * 100 + __GNUC_MINOR__)
#endif

// Pacify warnings in yy_init_buffer (observed with Flex 2.6.4)
// and GCC 6.4.0, 7.3.0 with -O3.
#if defined GCC_VERSION && 600 <= GCC_VERSION
# pragma GCC diagnostic ignored "-Wnull-dereference"
#endif

// This example uses Flex's C back end, yet compiles it as C++.
// So expect warnings about C style casts and NULL.
#if defined CLANG_VERSION && 500 <= CLANG_VERSION
# pragma clang diagnostic ignored "-Wold-style-cast"
# pragma clang diagnostic ignored "-Wzero-as-null-pointer-constant"
#elif defined GCC_VERSION && 407 <= GCC_VERSION
# pragma GCC diagnostic ignored "-Wold-style-cast"
# pragma GCC diagnostic ignored "-Wzero-as-null-pointer-constant"
#endif

#define FLEX_VERSION (YY_FLEX_MAJOR_VERSION * 100 + YY_FLEX_MINOR_VERSION)

// Old versions of Flex (2.5.35) generate an incomplete documentation comment.
//
//  In file included from src/scan-code-c.c:3:
//  src/scan-code.c:2198:21: error: empty paragraph passed to '@param' command
//        [-Werror,-Wdocumentation]
//   * @param line_number
//     ~~~~~~~~~~~~~~~~~^
//  1 error generated.
#if FLEX_VERSION < 206 && defined CLANG_VERSION
# pragma clang diagnostic ignored "-Wdocumentation"
#endif

// Old versions of Flex (2.5.35) use 'register'.  Warnings introduced in
// GCC 7 and Clang 6.
#if FLEX_VERSION < 206
# if defined CLANG_VERSION && 600 <= CLANG_VERSION
#  pragma clang diagnostic ignored "-Wdeprecated-register"
# elif defined GCC_VERSION && 700 <= GCC_VERSION
#  pragma GCC diagnostic ignored "-Wregister"
# endif
#endif

#if FLEX_VERSION < 206
# if defined CLANG_VERSION
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wdocumentation"
#  pragma clang diagnostic ignored "-Wshorten-64-to-32"
#  pragma clang diagnostic ignored "-Wsign-conversion"
# elif defined GCC_VERSION
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wsign-conversion"
# endif
#endif

// Flex 2.6.4, GCC 9
// warning: useless cast to type 'int' [-Wuseless-cast]
// 1361 |   YY_CURRENT_BUFFER_LVALUE->yy_buf_size = (int) (new_size - 2);
//      |                                                 ^
#if defined GCC_VERSION && 900 <= GCC_VERSION
# pragma GCC diagnostic ignored "-Wuseless-cast"
#endif
%}

%option noyywrap nounput noinput batch debug

%{
  // A number symbol corresponding to the value in S.
  yy::parser::symbol_type
  make_NUMBER (const std::string &s, const yy::parser::location_type& loc);
%}

white_space [ \t\r\f]
identifier [a-zA-Z_][a-zA-Z_0-9$]*
digits [0-9][0-9_]*
integer_literal  {digits}


%{
  // Code run each time a pattern is matched.
  # define YY_USER_ACTION  loc.columns (yyleng);
%}
%%
%{
  // A handy shortcut to the location held by the driver.
  yy::location& loc = drv.location;
  // Code run each time yylex is called.
  loc.step ();
%}
{white_space}+   loc.step ();
\n+        loc.lines (yyleng); loc.step ();

"+" return yy::parser::make_PLUS (new ASTNode(ASTNodeType::Plus, yytext), loc);
"-" return yy::parser::make_MINUS (new ASTNode(ASTNodeType::Minus, yytext), loc);
"*" return yy::parser::make_MULTIPLICATION (new ASTNode(ASTNodeType::Multiplication, yytext), loc);
"/" return yy::parser::make_DIVISION (new ASTNode(ASTNodeType::Division, yytext), loc);
"%" return yy::parser::make_MODULUS (new ASTNode(ASTNodeType::Modulus, yytext), loc);
"**" return yy::parser::make_EXPONENTIATION (new ASTNode(ASTNodeType::Exponentiation, yytext), loc);
"~" return yy::parser::make_BITWISE_COMPLEMENT (new ASTNode(ASTNodeType::BitwiseComplement, yytext), loc);
"&" return yy::parser::make_BITWISE_AND (new ASTNode(ASTNodeType::BitwiseAnd, yytext), loc);
"|" return yy::parser::make_BITWISE_OR (new ASTNode(ASTNodeType::BitwiseOr, yytext), loc);
"^" return yy::parser::make_BITWISE_XOR (new ASTNode(ASTNodeType::BitwiseXor, yytext), loc);
"<<"|">>" return yy::parser::make_BITWISE_SHIFT (new ASTNode(ASTNodeType::BitwiseShift, yytext), loc);
"!" return yy::parser::make_EXCLAMATION_MARK (new ASTNode(ASTNodeType::ExclamationMark, yytext), loc);
"&&" return yy::parser::make_LOGICAL_AND (new ASTNode(ASTNodeType::LogicalAnd, yytext), loc);
"||" return yy::parser::make_LOGICAL_OR (new ASTNode(ASTNodeType::LogicalOr, yytext), loc);
"<="|">="|"<"|">" return yy::parser::make_ORDERED_COMP (new ASTNode(ASTNodeType::OrderedComp, yytext), loc);
"=="|"!=" return yy::parser::make_EQUALITY_COMP (new ASTNode(ASTNodeType::EqualityComp, yytext), loc);
"by" return yy::parser::make_BY (new ASTNode(ASTNodeType::By, yytext), loc);
"#" return yy::parser::make_RANGE_COUNT (new ASTNode(ASTNodeType::RangeCount, yytext), loc);
";" return yy::parser::make_STATEMENT_SEPARATOR (new ASTNode(ASTNodeType::StatementSeparator, yytext), loc);

{identifier} return yy::parser::make_IDENTIFIER (new ASTNode(ASTNodeType::Identifier, yytext), loc);

{integer_literal} return yy::parser::make_INTEGER_LITERAL (new ASTNode(ASTNodeType::IntegerLiteral, yytext), loc);



. {
             throw yy::parser::syntax_error
               (loc, "invalid character: " + std::string(yytext));
}
<<EOF>> return yy::parser::make_YYEOF (loc);
%%

void driver::scan_begin ()
{
  yy_flex_debug = trace_scanning;
  if (file.empty () || file == "-")
    yyin = stdin;
  else if (!(yyin = fopen (file.c_str (), "r")))
    {
      std::cerr << "cannot open " << file << ": " << strerror (errno) << '\n';
      exit (EXIT_FAILURE);
    }
}

void driver::scan_end ()
{
  fclose (yyin);
}
