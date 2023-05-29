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

#if defined __GNUC__ && !defined __clang__ && !defined __ICC
# define GCC_VERSION (__GNUC__ * 100 + __GNUC_MINOR__)
#endif

#if defined GCC_VERSION && 600 <= GCC_VERSION
# pragma GCC diagnostic ignored "-Wnull-dereference"
#endif

// This uses Flex's C back end, yet compiles it as C++.
// So expect warnings about C style casts and NULL.
#if defined CLANG_VERSION && 500 <= CLANG_VERSION
# pragma clang diagnostic ignored "-Wold-style-cast"
# pragma clang diagnostic ignored "-Wzero-as-null-pointer-constant"
#elif defined GCC_VERSION && 407 <= GCC_VERSION
# pragma GCC diagnostic ignored "-Wold-style-cast"
# pragma GCC diagnostic ignored "-Wzero-as-null-pointer-constant"
#endif

#define FLEX_VERSION (YY_FLEX_MAJOR_VERSION * 100 + YY_FLEX_MINOR_VERSION)

#if FLEX_VERSION < 206 && defined CLANG_VERSION
# pragma clang diagnostic ignored "-Wdocumentation"
#endif

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

"+" return yy::parser::make_PLUS (new ASTNode(ASTNodeType::Plus), loc);
"-" return yy::parser::make_MINUS (new ASTNode(ASTNodeType::Minus), loc);
"*" return yy::parser::make_MULTIPLICATION (new ASTNode(ASTNodeType::Multiplication), loc);
"/" return yy::parser::make_DIVISION (new ASTNode(ASTNodeType::Division), loc);
"%" return yy::parser::make_MODULUS (new ASTNode(ASTNodeType::Modulus), loc);
"**" return yy::parser::make_EXPONENTIATION (new ASTNode(ASTNodeType::Exponentiation), loc);
"~" return yy::parser::make_BITWISE_COMPLEMENT (new ASTNode(ASTNodeType::BitwiseComplement), loc);
"&" return yy::parser::make_BITWISE_AND (new ASTNode(ASTNodeType::BitwiseAnd), loc);
"|" return yy::parser::make_BITWISE_OR (new ASTNode(ASTNodeType::BitwiseOr), loc);
"^" return yy::parser::make_BITWISE_XOR (new ASTNode(ASTNodeType::BitwiseXor), loc);
"<<"|">>" return yy::parser::make_BITWISE_SHIFT (new ASTNode(ASTNodeType::BitwiseShift, yytext), loc);
"!" return yy::parser::make_EXCLAMATION_MARK (new ASTNode(ASTNodeType::ExclamationMark), loc);
"&&" return yy::parser::make_LOGICAL_AND (new ASTNode(ASTNodeType::LogicalAnd), loc);
"||" return yy::parser::make_LOGICAL_OR (new ASTNode(ASTNodeType::LogicalOr), loc);
"<="|">="|"<"|">" return yy::parser::make_ORDERED_COMP (new ASTNode(ASTNodeType::OrderedComp, yytext), loc);
"=="|"!=" return yy::parser::make_EQUALITY_COMP (new ASTNode(ASTNodeType::EqualityComp, yytext), loc);
"by" return yy::parser::make_BY (new ASTNode(ASTNodeType::By), loc);
"#" return yy::parser::make_RANGE_COUNT (new ASTNode(ASTNodeType::RangeCount), loc);
"=" return yy::parser::make_ASSIGNMENT (new ASTNode(ASTNodeType::Assignment, yytext), loc);
"+="|"-="|"*="|"/="|"%="|"**="|"&="|"|="|"^="|"&&="|"||="|"<<="|">>=" return yy::parser::make_COMPOUND_ASSIGNMENT (new ASTNode(ASTNodeType::CompoundAssignment, yytext), loc);
";" return yy::parser::make_STATEMENT_SEPARATOR (new ASTNode(ASTNodeType::StatementSeparator), loc);
"(" return yy::parser::make_LEFT_ROUND_BRACKET (new ASTNode(ASTNodeType::LeftRoundBracket), loc);
")" return yy::parser::make_RIGHT_ROUND_BRACKET (new ASTNode(ASTNodeType::RightRoundBracket), loc);
"{" return yy::parser::make_LEFT_CURLY_BRACKET (new ASTNode(ASTNodeType::LeftCurlyBracket), loc);
"}" return yy::parser::make_RIGHT_CURLY_BRACKET (new ASTNode(ASTNodeType::RightCurlyBracket), loc);
"if" return yy::parser::make_IF (new ASTNode(ASTNodeType::If), loc);
"then" return yy::parser::make_THEN (new ASTNode(ASTNodeType::Then), loc);
"else" return yy::parser::make_ELSE (new ASTNode(ASTNodeType::Else), loc);
"var" return yy::parser::make_VAR (new ASTNode(ASTNodeType::Var), loc);
"const" return yy::parser::make_CONST (new ASTNode(ASTNodeType::Const), loc);
"while" return yy::parser::make_WHILE (new ASTNode(ASTNodeType::While), loc);
"do" return yy::parser::make_DO (new ASTNode(ASTNodeType::Do), loc);

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
