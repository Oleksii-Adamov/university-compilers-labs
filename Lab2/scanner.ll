%{ /* -*- C++ -*- */
# include <cerrno>
# include <climits>
# include <cstdlib>
# include <cstring> // strerror
# include <string>
# include "driver.hh"
# include "parser.hh"
# include "ASTNode.hh"
# include <iostream>
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
  // yy::parser::symbol_type make_NUMBER (const std::string &s, const yy::parser::location_type& loc);
%}

white_space [ \t\r\f]
identifier [a-zA-Z_][a-zA-Z_0-9$]*
digits [0-9][0-9_]*
digits_opt [0-9_]*
hexadecimal_digits [0-9A-Fa-f][0-9A-Fa-f_]*
hexadecimal_digits_opt [0-9A-Fa-f_]*
octal_digits [0-7][0-7_]*
binary_digits [0-1][0-1_]*
integer_literal  {digits}|("0"[xX]{hexadecimal_digits})|("0"[oO]{octal_digits})|("0"[bB]{binary_digits})
exponent_part [eE]([+-]?){digits}
exponent_part_opt {exponent_part}{0,1}
p_exponent_part [pP]([+-]?){digits}
p_exponent_part_opt {p_exponent_part}?
real_literal ({digits_opt}"."{digits}{exponent_part_opt})|({digits}("."?){exponent_part})|("0"[xX]{hexadecimal_digits_opt}"."{hexadecimal_digits}{p_exponent_part_opt})|("0"[xX]{hexadecimal_digits}("."?){p_exponent_part})
imaginary_literal ({integer_literal}"i")|({real_literal}"i")
string_character [^"'\n]|"\\"((['"?\\abfnrtv])|([0-9A-Fa-f]{1,2}))
interpreted_string_literal ("\""({string_character}|"'")*"\"")|("'"({string_character}|"\"")*"'")

%{
  // Code run each time a pattern is matched.
  # define YY_USER_ACTION  loc.columns (yyleng);
%}
%x comment
%x uninterpreted_string_literal
%%
%{
  // A handy shortcut to the location held by the driver.
  yy::location& loc = drv.location;
  // Code run each time yylex is called.
  loc.step ();
%}
{white_space}+   loc.step ();
\n+        loc.lines (yyleng); loc.step ();
"/*"         BEGIN(comment);
<comment>[^*\n]*        /* eat anything that's not a '*' */
<comment>"*"+[^*/\n]*   /* eat up '*'s not followed by '/'s */
<comment>\n             loc.lines();
<comment>"*"+"/"        BEGIN(INITIAL);
"//"[^\n]*              /*skip one line comments till the end of line*/
"\"\"\"" {/*ECHO;std::cout << " rule 1 \n";*/ BEGIN(uninterpreted_string_literal); yymore();}
<uninterpreted_string_literal>\n    {/*ECHO;std::cout << " rule 2 \n";*/ loc.lines(); yymore();}
<uninterpreted_string_literal>[^\"\n]* {/*ECHO; std::cout << " rule 3 \n";*/ yymore(); /* remember anything that's not a '"'*/}
<uninterpreted_string_literal>"\""{1,2}[^\"\n]* {/*ECHO; std::cout << " rule 4 \n";*/ yymore(); /* remember anything that's not a three '"' in a row*/}
<uninterpreted_string_literal>"\"\"\""  {/*ECHO; std::cout << " rule 5 \n";*/ BEGIN(INITIAL); return yy::parser::make_UNINTERPRETED_STRING_LITERAL (new ASTNode(ASTNodeType::UninterpretedStringLiteral, yytext), loc);}

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
"," return yy::parser::make_EXPRESSION_SEPARATOR (new ASTNode(ASTNodeType::ExpressionSeparator), loc);
"(" return yy::parser::make_LEFT_ROUND_BRACKET (new ASTNode(ASTNodeType::LeftRoundBracket), loc);
")" return yy::parser::make_RIGHT_ROUND_BRACKET (new ASTNode(ASTNodeType::RightRoundBracket), loc);
"{" return yy::parser::make_LEFT_CURLY_BRACKET (new ASTNode(ASTNodeType::LeftCurlyBracket), loc);
"}" return yy::parser::make_RIGHT_CURLY_BRACKET (new ASTNode(ASTNodeType::RightCurlyBracket), loc);
"[" return yy::parser::make_LEFT_SQUARE_BRACKET (new ASTNode(ASTNodeType::LeftSquareBracket), loc);
"]" return yy::parser::make_RIGHT_SQUARE_BRACKET (new ASTNode(ASTNodeType::RightSquareBracket), loc);
"..." return yy::parser::make_VARIABLE_ARGUMENT_LISTS (new ASTNode(ASTNodeType::VariableArgumentLists), loc);
".." return yy::parser::make_RANGE_SPECIFIER (new ASTNode(ASTNodeType::RangeSpecifier), loc);
"..<" return yy::parser::make_HALF_OPEN_RANGE_SPECIFIER (new ASTNode(ASTNodeType::HalfOpenRangeSpecifier), loc);
"." return yy::parser::make_MEMBER_ACCESS (new ASTNode(ASTNodeType::MemberAccess), loc);
":" return yy::parser::make_COLUMN (new ASTNode(ASTNodeType::Column), loc);
"if" return yy::parser::make_IF (new ASTNode(ASTNodeType::If), loc);
"then" return yy::parser::make_THEN (new ASTNode(ASTNodeType::Then), loc);
"else" return yy::parser::make_ELSE (new ASTNode(ASTNodeType::Else), loc);
"var" return yy::parser::make_VAR (new ASTNode(ASTNodeType::Var), loc);
"const" return yy::parser::make_CONST (new ASTNode(ASTNodeType::Const), loc);
"while" return yy::parser::make_WHILE (new ASTNode(ASTNodeType::While), loc);
"do" return yy::parser::make_DO (new ASTNode(ASTNodeType::Do), loc);
"for" return yy::parser::make_FOR (new ASTNode(ASTNodeType::For), loc);
"in" return yy::parser::make_IN (new ASTNode(ASTNodeType::In), loc);
"zip" return yy::parser::make_ZIP (new ASTNode(ASTNodeType::Zip), loc);
"public" return yy::parser::make_PUBLIC (new ASTNode(ASTNodeType::Public), loc);
"private" return yy::parser::make_PRIVATE (new ASTNode(ASTNodeType::Private), loc);
"config" return yy::parser::make_CONFIG (new ASTNode(ASTNodeType::Config), loc);
"extern" return yy::parser::make_EXTERN (new ASTNode(ASTNodeType::Extern), loc);
"export" return yy::parser::make_EXPORT (new ASTNode(ASTNodeType::Export), loc);
"param" return yy::parser::make_PARAM (new ASTNode(ASTNodeType::Param), loc);
"ref" return yy::parser::make_REF (new ASTNode(ASTNodeType::Ref), loc);
"void" return yy::parser::make_VOID (new ASTNode(ASTNodeType::Void), loc);
"nothing" return yy::parser::make_NOTHING (new ASTNode(ASTNodeType::Nothing), loc);
"bool" return yy::parser::make_BOOL (new ASTNode(ASTNodeType::Bool), loc);
"int" return yy::parser::make_INT (new ASTNode(ASTNodeType::Int), loc);
"uint" return yy::parser::make_UINT (new ASTNode(ASTNodeType::Uint), loc);
"real" return yy::parser::make_REAL (new ASTNode(ASTNodeType::Real), loc);
"imag" return yy::parser::make_IMAG (new ASTNode(ASTNodeType::Imag), loc);
"complex" return yy::parser::make_COMPLEX (new ASTNode(ASTNodeType::Complex), loc);
"string" return yy::parser::make_STRING (new ASTNode(ASTNodeType::String), loc);
"bytes" return yy::parser::make_BYTES (new ASTNode(ASTNodeType::Bytes), loc);
"enum" return yy::parser::make_ENUM (new ASTNode(ASTNodeType::Enum), loc);
"record" return yy::parser::make_RECORD (new ASTNode(ASTNodeType::Record), loc);
"class" return yy::parser::make_CLASS (new ASTNode(ASTNodeType::Class), loc);
"owned" return yy::parser::make_OWNED (new ASTNode(ASTNodeType::Owned), loc);
"shared" return yy::parser::make_SHARED (new ASTNode(ASTNodeType::Shared), loc);
"unmanaged" return yy::parser::make_UNMANAGED (new ASTNode(ASTNodeType::Unmanaged), loc);
"borrowed" return yy::parser::make_BORROWED (new ASTNode(ASTNodeType::Borrowed), loc);

"true"|"false" return yy::parser::make_BOOL_LITERAL (new ASTNode(ASTNodeType::BoolLiteral, yytext), loc);
{integer_literal} return yy::parser::make_INTEGER_LITERAL (new ASTNode(ASTNodeType::IntegerLiteral, yytext), loc);
{real_literal} return yy::parser::make_REAL_LITERAL (new ASTNode(ASTNodeType::RealLiteral, yytext), loc);
{imaginary_literal} return yy::parser::make_IMAGINARY_LITERAL (new ASTNode(ASTNodeType::ImaginaryLiteral, yytext), loc);
{interpreted_string_literal} return yy::parser::make_INTERPRETED_STRING_LITERAL (new ASTNode(ASTNodeType::InterpretedStringLiteral, yytext), loc);
{identifier} return yy::parser::make_IDENTIFIER (new ASTNode(ASTNodeType::Identifier, yytext), loc);



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
