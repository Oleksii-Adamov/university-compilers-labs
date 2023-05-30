// A Bison parser, made by GNU Bison 3.8.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.tab.hh"


// Unqualified %code blocks.
#line 26 "parser.yy"

# include "driver.hh"

#line 50 "parser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 142 "parser.tab.cc"

  /// Build a parser object.
  parser::parser (driver& drv_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yy_lac_established_ (false),
      drv (drv_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_PLUS: // "+"
      case symbol_kind::S_MINUS: // "-"
      case symbol_kind::S_MULTIPLICATION: // "*"
      case symbol_kind::S_DIVISION: // "/"
      case symbol_kind::S_MODULUS: // "%"
      case symbol_kind::S_EXPONENTIATION: // "**"
      case symbol_kind::S_BITWISE_COMPLEMENT: // "~"
      case symbol_kind::S_BITWISE_AND: // "&"
      case symbol_kind::S_BITWISE_OR: // "|"
      case symbol_kind::S_BITWISE_XOR: // "^"
      case symbol_kind::S_BITWISE_SHIFT: // BITWISE_SHIFT
      case symbol_kind::S_EXCLAMATION_MARK: // "!"
      case symbol_kind::S_LOGICAL_AND: // "&&"
      case symbol_kind::S_LOGICAL_OR: // "||"
      case symbol_kind::S_ORDERED_COMP: // ORDERED_COMP
      case symbol_kind::S_EQUALITY_COMP: // EQUALITY_COMP
      case symbol_kind::S_BY: // "by"
      case symbol_kind::S_RANGE_COUNT: // "#"
      case symbol_kind::S_ASSIGNMENT: // "="
      case symbol_kind::S_COMPOUND_ASSIGNMENT: // COMPOUND_ASSIGNMENT
      case symbol_kind::S_STATEMENT_SEPARATOR: // ";"
      case symbol_kind::S_EXPRESSION_SEPARATOR: // ","
      case symbol_kind::S_LEFT_ROUND_BRACKET: // "("
      case symbol_kind::S_RIGHT_ROUND_BRACKET: // ")"
      case symbol_kind::S_LEFT_CURLY_BRACKET: // "{"
      case symbol_kind::S_RIGHT_CURLY_BRACKET: // "}"
      case symbol_kind::S_LEFT_SQUARE_BRACKET: // "["
      case symbol_kind::S_RIGHT_SQUARE_BRACKET: // "]"
      case symbol_kind::S_RANGE_SPECIFIER: // ".."
      case symbol_kind::S_HALF_OPEN_RANGE_SPECIFIER: // "..<"
      case symbol_kind::S_MEMBER_ACCESS: // "."
      case symbol_kind::S_VARIABLE_ARGUMENT_LISTS: // "..."
      case symbol_kind::S_COLUMN: // ":"
      case symbol_kind::S_PUBLIC: // "public"
      case symbol_kind::S_PRIVATE: // "private"
      case symbol_kind::S_CONFIG: // "config"
      case symbol_kind::S_EXTERN: // "extern"
      case symbol_kind::S_EXPORT: // "export"
      case symbol_kind::S_PARAM: // "param"
      case symbol_kind::S_REF: // "ref"
      case symbol_kind::S_VOID: // "void"
      case symbol_kind::S_NOTHING: // "nothing"
      case symbol_kind::S_BOOL: // "bool"
      case symbol_kind::S_INT: // "int"
      case symbol_kind::S_UINT: // "uint"
      case symbol_kind::S_REAL: // "real"
      case symbol_kind::S_IMAG: // "imag"
      case symbol_kind::S_COMPLEX: // "complex"
      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_BYTES: // "bytes"
      case symbol_kind::S_ENUM: // "enum"
      case symbol_kind::S_RECORD: // "record"
      case symbol_kind::S_CLASS: // "class"
      case symbol_kind::S_OWNED: // "owned"
      case symbol_kind::S_SHARED: // "shared"
      case symbol_kind::S_UNMANAGED: // "unmanaged"
      case symbol_kind::S_BORROWED: // "borrowed"
      case symbol_kind::S_IF: // "if"
      case symbol_kind::S_THEN: // "then"
      case symbol_kind::S_ELSE: // "else"
      case symbol_kind::S_VAR: // "var"
      case symbol_kind::S_CONST: // "const"
      case symbol_kind::S_WHILE: // "while"
      case symbol_kind::S_DO: // "do"
      case symbol_kind::S_FOR: // "for"
      case symbol_kind::S_IN: // "in"
      case symbol_kind::S_ZIP: // "zip"
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_INTEGER_LITERAL: // INTEGER_LITERAL
      case symbol_kind::S_statements_opt: // statements_opt
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_block_statement: // block_statement
      case symbol_kind::S_expression_statement: // expression_statement
      case symbol_kind::S_assignment_statement: // assignment_statement
      case symbol_kind::S_conditional_statement: // conditional_statement
      case symbol_kind::S_else_part_opt: // else_part_opt
      case symbol_kind::S_ctrl_decl: // ctrl_decl
      case symbol_kind::S_while_do_statement: // while_do_statement
      case symbol_kind::S_do_while_statement: // do_while_statement
      case symbol_kind::S_for_statement: // for_statement
      case symbol_kind::S_index_var_decl: // index_var_decl
      case symbol_kind::S_tuple_grouped_identifier_list: // tuple_grouped_identifier_list
      case symbol_kind::S_identifier_list: // identifier_list
      case symbol_kind::S_iterable_expression: // iterable_expression
      case symbol_kind::S_expression_list: // expression_list
      case symbol_kind::S_variable_declaration_statement: // variable_declaration_statement
      case symbol_kind::S_privacy_specifier_opt: // privacy_specifier_opt
      case symbol_kind::S_config_extern_or_export_opt: // config_extern_or_export_opt
      case symbol_kind::S_variable_kind: // variable_kind
      case symbol_kind::S_variable_declaration_list: // variable_declaration_list
      case symbol_kind::S_variable_declaration: // variable_declaration
      case symbol_kind::S_type_part_opt: // type_part_opt
      case symbol_kind::S_type_expression: // type_expression
      case symbol_kind::S_primitive_type: // primitive_type
      case symbol_kind::S_primitive_type_parameter_part_opt: // primitive_type_parameter_part_opt
      case symbol_kind::S_initialization_part_opt: // initialization_part_opt
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_literal_expression: // literal_expression
      case symbol_kind::S_range_literal: // range_literal
      case symbol_kind::S_variable_expression: // variable_expression
      case symbol_kind::S_parenthesized_expression: // parenthesized_expression
      case symbol_kind::S_lvalue_expression: // lvalue_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_binary_expression: // binary_expression
      case symbol_kind::S_method_call_expression: // method_call_expression
      case symbol_kind::S_call_expression: // call_expression
      case symbol_kind::S_named_expression_list: // named_expression_list
      case symbol_kind::S_named_expression: // named_expression
      case symbol_kind::S_member_access_expression: // member_access_expression
      case symbol_kind::S_field_access_expression: // field_access_expression
        value.YY_MOVE_OR_COPY< ASTNode* > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_PLUS: // "+"
      case symbol_kind::S_MINUS: // "-"
      case symbol_kind::S_MULTIPLICATION: // "*"
      case symbol_kind::S_DIVISION: // "/"
      case symbol_kind::S_MODULUS: // "%"
      case symbol_kind::S_EXPONENTIATION: // "**"
      case symbol_kind::S_BITWISE_COMPLEMENT: // "~"
      case symbol_kind::S_BITWISE_AND: // "&"
      case symbol_kind::S_BITWISE_OR: // "|"
      case symbol_kind::S_BITWISE_XOR: // "^"
      case symbol_kind::S_BITWISE_SHIFT: // BITWISE_SHIFT
      case symbol_kind::S_EXCLAMATION_MARK: // "!"
      case symbol_kind::S_LOGICAL_AND: // "&&"
      case symbol_kind::S_LOGICAL_OR: // "||"
      case symbol_kind::S_ORDERED_COMP: // ORDERED_COMP
      case symbol_kind::S_EQUALITY_COMP: // EQUALITY_COMP
      case symbol_kind::S_BY: // "by"
      case symbol_kind::S_RANGE_COUNT: // "#"
      case symbol_kind::S_ASSIGNMENT: // "="
      case symbol_kind::S_COMPOUND_ASSIGNMENT: // COMPOUND_ASSIGNMENT
      case symbol_kind::S_STATEMENT_SEPARATOR: // ";"
      case symbol_kind::S_EXPRESSION_SEPARATOR: // ","
      case symbol_kind::S_LEFT_ROUND_BRACKET: // "("
      case symbol_kind::S_RIGHT_ROUND_BRACKET: // ")"
      case symbol_kind::S_LEFT_CURLY_BRACKET: // "{"
      case symbol_kind::S_RIGHT_CURLY_BRACKET: // "}"
      case symbol_kind::S_LEFT_SQUARE_BRACKET: // "["
      case symbol_kind::S_RIGHT_SQUARE_BRACKET: // "]"
      case symbol_kind::S_RANGE_SPECIFIER: // ".."
      case symbol_kind::S_HALF_OPEN_RANGE_SPECIFIER: // "..<"
      case symbol_kind::S_MEMBER_ACCESS: // "."
      case symbol_kind::S_VARIABLE_ARGUMENT_LISTS: // "..."
      case symbol_kind::S_COLUMN: // ":"
      case symbol_kind::S_PUBLIC: // "public"
      case symbol_kind::S_PRIVATE: // "private"
      case symbol_kind::S_CONFIG: // "config"
      case symbol_kind::S_EXTERN: // "extern"
      case symbol_kind::S_EXPORT: // "export"
      case symbol_kind::S_PARAM: // "param"
      case symbol_kind::S_REF: // "ref"
      case symbol_kind::S_VOID: // "void"
      case symbol_kind::S_NOTHING: // "nothing"
      case symbol_kind::S_BOOL: // "bool"
      case symbol_kind::S_INT: // "int"
      case symbol_kind::S_UINT: // "uint"
      case symbol_kind::S_REAL: // "real"
      case symbol_kind::S_IMAG: // "imag"
      case symbol_kind::S_COMPLEX: // "complex"
      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_BYTES: // "bytes"
      case symbol_kind::S_ENUM: // "enum"
      case symbol_kind::S_RECORD: // "record"
      case symbol_kind::S_CLASS: // "class"
      case symbol_kind::S_OWNED: // "owned"
      case symbol_kind::S_SHARED: // "shared"
      case symbol_kind::S_UNMANAGED: // "unmanaged"
      case symbol_kind::S_BORROWED: // "borrowed"
      case symbol_kind::S_IF: // "if"
      case symbol_kind::S_THEN: // "then"
      case symbol_kind::S_ELSE: // "else"
      case symbol_kind::S_VAR: // "var"
      case symbol_kind::S_CONST: // "const"
      case symbol_kind::S_WHILE: // "while"
      case symbol_kind::S_DO: // "do"
      case symbol_kind::S_FOR: // "for"
      case symbol_kind::S_IN: // "in"
      case symbol_kind::S_ZIP: // "zip"
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_INTEGER_LITERAL: // INTEGER_LITERAL
      case symbol_kind::S_statements_opt: // statements_opt
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_block_statement: // block_statement
      case symbol_kind::S_expression_statement: // expression_statement
      case symbol_kind::S_assignment_statement: // assignment_statement
      case symbol_kind::S_conditional_statement: // conditional_statement
      case symbol_kind::S_else_part_opt: // else_part_opt
      case symbol_kind::S_ctrl_decl: // ctrl_decl
      case symbol_kind::S_while_do_statement: // while_do_statement
      case symbol_kind::S_do_while_statement: // do_while_statement
      case symbol_kind::S_for_statement: // for_statement
      case symbol_kind::S_index_var_decl: // index_var_decl
      case symbol_kind::S_tuple_grouped_identifier_list: // tuple_grouped_identifier_list
      case symbol_kind::S_identifier_list: // identifier_list
      case symbol_kind::S_iterable_expression: // iterable_expression
      case symbol_kind::S_expression_list: // expression_list
      case symbol_kind::S_variable_declaration_statement: // variable_declaration_statement
      case symbol_kind::S_privacy_specifier_opt: // privacy_specifier_opt
      case symbol_kind::S_config_extern_or_export_opt: // config_extern_or_export_opt
      case symbol_kind::S_variable_kind: // variable_kind
      case symbol_kind::S_variable_declaration_list: // variable_declaration_list
      case symbol_kind::S_variable_declaration: // variable_declaration
      case symbol_kind::S_type_part_opt: // type_part_opt
      case symbol_kind::S_type_expression: // type_expression
      case symbol_kind::S_primitive_type: // primitive_type
      case symbol_kind::S_primitive_type_parameter_part_opt: // primitive_type_parameter_part_opt
      case symbol_kind::S_initialization_part_opt: // initialization_part_opt
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_literal_expression: // literal_expression
      case symbol_kind::S_range_literal: // range_literal
      case symbol_kind::S_variable_expression: // variable_expression
      case symbol_kind::S_parenthesized_expression: // parenthesized_expression
      case symbol_kind::S_lvalue_expression: // lvalue_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_binary_expression: // binary_expression
      case symbol_kind::S_method_call_expression: // method_call_expression
      case symbol_kind::S_call_expression: // call_expression
      case symbol_kind::S_named_expression_list: // named_expression_list
      case symbol_kind::S_named_expression: // named_expression
      case symbol_kind::S_member_access_expression: // member_access_expression
      case symbol_kind::S_field_access_expression: // field_access_expression
        value.move< ASTNode* > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_PLUS: // "+"
      case symbol_kind::S_MINUS: // "-"
      case symbol_kind::S_MULTIPLICATION: // "*"
      case symbol_kind::S_DIVISION: // "/"
      case symbol_kind::S_MODULUS: // "%"
      case symbol_kind::S_EXPONENTIATION: // "**"
      case symbol_kind::S_BITWISE_COMPLEMENT: // "~"
      case symbol_kind::S_BITWISE_AND: // "&"
      case symbol_kind::S_BITWISE_OR: // "|"
      case symbol_kind::S_BITWISE_XOR: // "^"
      case symbol_kind::S_BITWISE_SHIFT: // BITWISE_SHIFT
      case symbol_kind::S_EXCLAMATION_MARK: // "!"
      case symbol_kind::S_LOGICAL_AND: // "&&"
      case symbol_kind::S_LOGICAL_OR: // "||"
      case symbol_kind::S_ORDERED_COMP: // ORDERED_COMP
      case symbol_kind::S_EQUALITY_COMP: // EQUALITY_COMP
      case symbol_kind::S_BY: // "by"
      case symbol_kind::S_RANGE_COUNT: // "#"
      case symbol_kind::S_ASSIGNMENT: // "="
      case symbol_kind::S_COMPOUND_ASSIGNMENT: // COMPOUND_ASSIGNMENT
      case symbol_kind::S_STATEMENT_SEPARATOR: // ";"
      case symbol_kind::S_EXPRESSION_SEPARATOR: // ","
      case symbol_kind::S_LEFT_ROUND_BRACKET: // "("
      case symbol_kind::S_RIGHT_ROUND_BRACKET: // ")"
      case symbol_kind::S_LEFT_CURLY_BRACKET: // "{"
      case symbol_kind::S_RIGHT_CURLY_BRACKET: // "}"
      case symbol_kind::S_LEFT_SQUARE_BRACKET: // "["
      case symbol_kind::S_RIGHT_SQUARE_BRACKET: // "]"
      case symbol_kind::S_RANGE_SPECIFIER: // ".."
      case symbol_kind::S_HALF_OPEN_RANGE_SPECIFIER: // "..<"
      case symbol_kind::S_MEMBER_ACCESS: // "."
      case symbol_kind::S_VARIABLE_ARGUMENT_LISTS: // "..."
      case symbol_kind::S_COLUMN: // ":"
      case symbol_kind::S_PUBLIC: // "public"
      case symbol_kind::S_PRIVATE: // "private"
      case symbol_kind::S_CONFIG: // "config"
      case symbol_kind::S_EXTERN: // "extern"
      case symbol_kind::S_EXPORT: // "export"
      case symbol_kind::S_PARAM: // "param"
      case symbol_kind::S_REF: // "ref"
      case symbol_kind::S_VOID: // "void"
      case symbol_kind::S_NOTHING: // "nothing"
      case symbol_kind::S_BOOL: // "bool"
      case symbol_kind::S_INT: // "int"
      case symbol_kind::S_UINT: // "uint"
      case symbol_kind::S_REAL: // "real"
      case symbol_kind::S_IMAG: // "imag"
      case symbol_kind::S_COMPLEX: // "complex"
      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_BYTES: // "bytes"
      case symbol_kind::S_ENUM: // "enum"
      case symbol_kind::S_RECORD: // "record"
      case symbol_kind::S_CLASS: // "class"
      case symbol_kind::S_OWNED: // "owned"
      case symbol_kind::S_SHARED: // "shared"
      case symbol_kind::S_UNMANAGED: // "unmanaged"
      case symbol_kind::S_BORROWED: // "borrowed"
      case symbol_kind::S_IF: // "if"
      case symbol_kind::S_THEN: // "then"
      case symbol_kind::S_ELSE: // "else"
      case symbol_kind::S_VAR: // "var"
      case symbol_kind::S_CONST: // "const"
      case symbol_kind::S_WHILE: // "while"
      case symbol_kind::S_DO: // "do"
      case symbol_kind::S_FOR: // "for"
      case symbol_kind::S_IN: // "in"
      case symbol_kind::S_ZIP: // "zip"
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_INTEGER_LITERAL: // INTEGER_LITERAL
      case symbol_kind::S_statements_opt: // statements_opt
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_block_statement: // block_statement
      case symbol_kind::S_expression_statement: // expression_statement
      case symbol_kind::S_assignment_statement: // assignment_statement
      case symbol_kind::S_conditional_statement: // conditional_statement
      case symbol_kind::S_else_part_opt: // else_part_opt
      case symbol_kind::S_ctrl_decl: // ctrl_decl
      case symbol_kind::S_while_do_statement: // while_do_statement
      case symbol_kind::S_do_while_statement: // do_while_statement
      case symbol_kind::S_for_statement: // for_statement
      case symbol_kind::S_index_var_decl: // index_var_decl
      case symbol_kind::S_tuple_grouped_identifier_list: // tuple_grouped_identifier_list
      case symbol_kind::S_identifier_list: // identifier_list
      case symbol_kind::S_iterable_expression: // iterable_expression
      case symbol_kind::S_expression_list: // expression_list
      case symbol_kind::S_variable_declaration_statement: // variable_declaration_statement
      case symbol_kind::S_privacy_specifier_opt: // privacy_specifier_opt
      case symbol_kind::S_config_extern_or_export_opt: // config_extern_or_export_opt
      case symbol_kind::S_variable_kind: // variable_kind
      case symbol_kind::S_variable_declaration_list: // variable_declaration_list
      case symbol_kind::S_variable_declaration: // variable_declaration
      case symbol_kind::S_type_part_opt: // type_part_opt
      case symbol_kind::S_type_expression: // type_expression
      case symbol_kind::S_primitive_type: // primitive_type
      case symbol_kind::S_primitive_type_parameter_part_opt: // primitive_type_parameter_part_opt
      case symbol_kind::S_initialization_part_opt: // initialization_part_opt
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_literal_expression: // literal_expression
      case symbol_kind::S_range_literal: // range_literal
      case symbol_kind::S_variable_expression: // variable_expression
      case symbol_kind::S_parenthesized_expression: // parenthesized_expression
      case symbol_kind::S_lvalue_expression: // lvalue_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_binary_expression: // binary_expression
      case symbol_kind::S_method_call_expression: // method_call_expression
      case symbol_kind::S_call_expression: // call_expression
      case symbol_kind::S_named_expression_list: // named_expression_list
      case symbol_kind::S_named_expression: // named_expression
      case symbol_kind::S_member_access_expression: // member_access_expression
      case symbol_kind::S_field_access_expression: // field_access_expression
        value.copy< ASTNode* > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_PLUS: // "+"
      case symbol_kind::S_MINUS: // "-"
      case symbol_kind::S_MULTIPLICATION: // "*"
      case symbol_kind::S_DIVISION: // "/"
      case symbol_kind::S_MODULUS: // "%"
      case symbol_kind::S_EXPONENTIATION: // "**"
      case symbol_kind::S_BITWISE_COMPLEMENT: // "~"
      case symbol_kind::S_BITWISE_AND: // "&"
      case symbol_kind::S_BITWISE_OR: // "|"
      case symbol_kind::S_BITWISE_XOR: // "^"
      case symbol_kind::S_BITWISE_SHIFT: // BITWISE_SHIFT
      case symbol_kind::S_EXCLAMATION_MARK: // "!"
      case symbol_kind::S_LOGICAL_AND: // "&&"
      case symbol_kind::S_LOGICAL_OR: // "||"
      case symbol_kind::S_ORDERED_COMP: // ORDERED_COMP
      case symbol_kind::S_EQUALITY_COMP: // EQUALITY_COMP
      case symbol_kind::S_BY: // "by"
      case symbol_kind::S_RANGE_COUNT: // "#"
      case symbol_kind::S_ASSIGNMENT: // "="
      case symbol_kind::S_COMPOUND_ASSIGNMENT: // COMPOUND_ASSIGNMENT
      case symbol_kind::S_STATEMENT_SEPARATOR: // ";"
      case symbol_kind::S_EXPRESSION_SEPARATOR: // ","
      case symbol_kind::S_LEFT_ROUND_BRACKET: // "("
      case symbol_kind::S_RIGHT_ROUND_BRACKET: // ")"
      case symbol_kind::S_LEFT_CURLY_BRACKET: // "{"
      case symbol_kind::S_RIGHT_CURLY_BRACKET: // "}"
      case symbol_kind::S_LEFT_SQUARE_BRACKET: // "["
      case symbol_kind::S_RIGHT_SQUARE_BRACKET: // "]"
      case symbol_kind::S_RANGE_SPECIFIER: // ".."
      case symbol_kind::S_HALF_OPEN_RANGE_SPECIFIER: // "..<"
      case symbol_kind::S_MEMBER_ACCESS: // "."
      case symbol_kind::S_VARIABLE_ARGUMENT_LISTS: // "..."
      case symbol_kind::S_COLUMN: // ":"
      case symbol_kind::S_PUBLIC: // "public"
      case symbol_kind::S_PRIVATE: // "private"
      case symbol_kind::S_CONFIG: // "config"
      case symbol_kind::S_EXTERN: // "extern"
      case symbol_kind::S_EXPORT: // "export"
      case symbol_kind::S_PARAM: // "param"
      case symbol_kind::S_REF: // "ref"
      case symbol_kind::S_VOID: // "void"
      case symbol_kind::S_NOTHING: // "nothing"
      case symbol_kind::S_BOOL: // "bool"
      case symbol_kind::S_INT: // "int"
      case symbol_kind::S_UINT: // "uint"
      case symbol_kind::S_REAL: // "real"
      case symbol_kind::S_IMAG: // "imag"
      case symbol_kind::S_COMPLEX: // "complex"
      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_BYTES: // "bytes"
      case symbol_kind::S_ENUM: // "enum"
      case symbol_kind::S_RECORD: // "record"
      case symbol_kind::S_CLASS: // "class"
      case symbol_kind::S_OWNED: // "owned"
      case symbol_kind::S_SHARED: // "shared"
      case symbol_kind::S_UNMANAGED: // "unmanaged"
      case symbol_kind::S_BORROWED: // "borrowed"
      case symbol_kind::S_IF: // "if"
      case symbol_kind::S_THEN: // "then"
      case symbol_kind::S_ELSE: // "else"
      case symbol_kind::S_VAR: // "var"
      case symbol_kind::S_CONST: // "const"
      case symbol_kind::S_WHILE: // "while"
      case symbol_kind::S_DO: // "do"
      case symbol_kind::S_FOR: // "for"
      case symbol_kind::S_IN: // "in"
      case symbol_kind::S_ZIP: // "zip"
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_INTEGER_LITERAL: // INTEGER_LITERAL
      case symbol_kind::S_statements_opt: // statements_opt
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_block_statement: // block_statement
      case symbol_kind::S_expression_statement: // expression_statement
      case symbol_kind::S_assignment_statement: // assignment_statement
      case symbol_kind::S_conditional_statement: // conditional_statement
      case symbol_kind::S_else_part_opt: // else_part_opt
      case symbol_kind::S_ctrl_decl: // ctrl_decl
      case symbol_kind::S_while_do_statement: // while_do_statement
      case symbol_kind::S_do_while_statement: // do_while_statement
      case symbol_kind::S_for_statement: // for_statement
      case symbol_kind::S_index_var_decl: // index_var_decl
      case symbol_kind::S_tuple_grouped_identifier_list: // tuple_grouped_identifier_list
      case symbol_kind::S_identifier_list: // identifier_list
      case symbol_kind::S_iterable_expression: // iterable_expression
      case symbol_kind::S_expression_list: // expression_list
      case symbol_kind::S_variable_declaration_statement: // variable_declaration_statement
      case symbol_kind::S_privacy_specifier_opt: // privacy_specifier_opt
      case symbol_kind::S_config_extern_or_export_opt: // config_extern_or_export_opt
      case symbol_kind::S_variable_kind: // variable_kind
      case symbol_kind::S_variable_declaration_list: // variable_declaration_list
      case symbol_kind::S_variable_declaration: // variable_declaration
      case symbol_kind::S_type_part_opt: // type_part_opt
      case symbol_kind::S_type_expression: // type_expression
      case symbol_kind::S_primitive_type: // primitive_type
      case symbol_kind::S_primitive_type_parameter_part_opt: // primitive_type_parameter_part_opt
      case symbol_kind::S_initialization_part_opt: // initialization_part_opt
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_literal_expression: // literal_expression
      case symbol_kind::S_range_literal: // range_literal
      case symbol_kind::S_variable_expression: // variable_expression
      case symbol_kind::S_parenthesized_expression: // parenthesized_expression
      case symbol_kind::S_lvalue_expression: // lvalue_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_binary_expression: // binary_expression
      case symbol_kind::S_method_call_expression: // method_call_expression
      case symbol_kind::S_call_expression: // call_expression
      case symbol_kind::S_named_expression_list: // named_expression_list
      case symbol_kind::S_named_expression: // named_expression
      case symbol_kind::S_member_access_expression: // member_access_expression
      case symbol_kind::S_field_access_expression: // field_access_expression
        value.move< ASTNode* > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        switch (yykind)
    {
      case symbol_kind::S_PLUS: // "+"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 746 "parser.tab.cc"
        break;

      case symbol_kind::S_MINUS: // "-"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 752 "parser.tab.cc"
        break;

      case symbol_kind::S_MULTIPLICATION: // "*"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 758 "parser.tab.cc"
        break;

      case symbol_kind::S_DIVISION: // "/"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 764 "parser.tab.cc"
        break;

      case symbol_kind::S_MODULUS: // "%"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 770 "parser.tab.cc"
        break;

      case symbol_kind::S_EXPONENTIATION: // "**"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 776 "parser.tab.cc"
        break;

      case symbol_kind::S_BITWISE_COMPLEMENT: // "~"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 782 "parser.tab.cc"
        break;

      case symbol_kind::S_BITWISE_AND: // "&"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 788 "parser.tab.cc"
        break;

      case symbol_kind::S_BITWISE_OR: // "|"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 794 "parser.tab.cc"
        break;

      case symbol_kind::S_BITWISE_XOR: // "^"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 800 "parser.tab.cc"
        break;

      case symbol_kind::S_BITWISE_SHIFT: // BITWISE_SHIFT
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 806 "parser.tab.cc"
        break;

      case symbol_kind::S_EXCLAMATION_MARK: // "!"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 812 "parser.tab.cc"
        break;

      case symbol_kind::S_LOGICAL_AND: // "&&"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 818 "parser.tab.cc"
        break;

      case symbol_kind::S_LOGICAL_OR: // "||"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 824 "parser.tab.cc"
        break;

      case symbol_kind::S_ORDERED_COMP: // ORDERED_COMP
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 830 "parser.tab.cc"
        break;

      case symbol_kind::S_EQUALITY_COMP: // EQUALITY_COMP
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 836 "parser.tab.cc"
        break;

      case symbol_kind::S_BY: // "by"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 842 "parser.tab.cc"
        break;

      case symbol_kind::S_RANGE_COUNT: // "#"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 848 "parser.tab.cc"
        break;

      case symbol_kind::S_ASSIGNMENT: // "="
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 854 "parser.tab.cc"
        break;

      case symbol_kind::S_COMPOUND_ASSIGNMENT: // COMPOUND_ASSIGNMENT
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 860 "parser.tab.cc"
        break;

      case symbol_kind::S_STATEMENT_SEPARATOR: // ";"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 866 "parser.tab.cc"
        break;

      case symbol_kind::S_EXPRESSION_SEPARATOR: // ","
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 872 "parser.tab.cc"
        break;

      case symbol_kind::S_LEFT_ROUND_BRACKET: // "("
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 878 "parser.tab.cc"
        break;

      case symbol_kind::S_RIGHT_ROUND_BRACKET: // ")"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 884 "parser.tab.cc"
        break;

      case symbol_kind::S_LEFT_CURLY_BRACKET: // "{"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 890 "parser.tab.cc"
        break;

      case symbol_kind::S_RIGHT_CURLY_BRACKET: // "}"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 896 "parser.tab.cc"
        break;

      case symbol_kind::S_LEFT_SQUARE_BRACKET: // "["
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 902 "parser.tab.cc"
        break;

      case symbol_kind::S_RIGHT_SQUARE_BRACKET: // "]"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 908 "parser.tab.cc"
        break;

      case symbol_kind::S_RANGE_SPECIFIER: // ".."
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 914 "parser.tab.cc"
        break;

      case symbol_kind::S_HALF_OPEN_RANGE_SPECIFIER: // "..<"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 920 "parser.tab.cc"
        break;

      case symbol_kind::S_MEMBER_ACCESS: // "."
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 926 "parser.tab.cc"
        break;

      case symbol_kind::S_VARIABLE_ARGUMENT_LISTS: // "..."
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 932 "parser.tab.cc"
        break;

      case symbol_kind::S_COLUMN: // ":"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 938 "parser.tab.cc"
        break;

      case symbol_kind::S_PUBLIC: // "public"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 944 "parser.tab.cc"
        break;

      case symbol_kind::S_PRIVATE: // "private"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 950 "parser.tab.cc"
        break;

      case symbol_kind::S_CONFIG: // "config"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 956 "parser.tab.cc"
        break;

      case symbol_kind::S_EXTERN: // "extern"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 962 "parser.tab.cc"
        break;

      case symbol_kind::S_EXPORT: // "export"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 968 "parser.tab.cc"
        break;

      case symbol_kind::S_PARAM: // "param"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 974 "parser.tab.cc"
        break;

      case symbol_kind::S_REF: // "ref"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 980 "parser.tab.cc"
        break;

      case symbol_kind::S_VOID: // "void"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 986 "parser.tab.cc"
        break;

      case symbol_kind::S_NOTHING: // "nothing"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 992 "parser.tab.cc"
        break;

      case symbol_kind::S_BOOL: // "bool"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 998 "parser.tab.cc"
        break;

      case symbol_kind::S_INT: // "int"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1004 "parser.tab.cc"
        break;

      case symbol_kind::S_UINT: // "uint"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1010 "parser.tab.cc"
        break;

      case symbol_kind::S_REAL: // "real"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1016 "parser.tab.cc"
        break;

      case symbol_kind::S_IMAG: // "imag"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1022 "parser.tab.cc"
        break;

      case symbol_kind::S_COMPLEX: // "complex"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1028 "parser.tab.cc"
        break;

      case symbol_kind::S_STRING: // "string"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1034 "parser.tab.cc"
        break;

      case symbol_kind::S_BYTES: // "bytes"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1040 "parser.tab.cc"
        break;

      case symbol_kind::S_ENUM: // "enum"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1046 "parser.tab.cc"
        break;

      case symbol_kind::S_RECORD: // "record"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1052 "parser.tab.cc"
        break;

      case symbol_kind::S_CLASS: // "class"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1058 "parser.tab.cc"
        break;

      case symbol_kind::S_OWNED: // "owned"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1064 "parser.tab.cc"
        break;

      case symbol_kind::S_SHARED: // "shared"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1070 "parser.tab.cc"
        break;

      case symbol_kind::S_UNMANAGED: // "unmanaged"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1076 "parser.tab.cc"
        break;

      case symbol_kind::S_BORROWED: // "borrowed"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1082 "parser.tab.cc"
        break;

      case symbol_kind::S_IF: // "if"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1088 "parser.tab.cc"
        break;

      case symbol_kind::S_THEN: // "then"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1094 "parser.tab.cc"
        break;

      case symbol_kind::S_ELSE: // "else"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1100 "parser.tab.cc"
        break;

      case symbol_kind::S_VAR: // "var"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1106 "parser.tab.cc"
        break;

      case symbol_kind::S_CONST: // "const"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1112 "parser.tab.cc"
        break;

      case symbol_kind::S_WHILE: // "while"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1118 "parser.tab.cc"
        break;

      case symbol_kind::S_DO: // "do"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1124 "parser.tab.cc"
        break;

      case symbol_kind::S_FOR: // "for"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1130 "parser.tab.cc"
        break;

      case symbol_kind::S_IN: // "in"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1136 "parser.tab.cc"
        break;

      case symbol_kind::S_ZIP: // "zip"
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1142 "parser.tab.cc"
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1148 "parser.tab.cc"
        break;

      case symbol_kind::S_INTEGER_LITERAL: // INTEGER_LITERAL
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1154 "parser.tab.cc"
        break;

      case symbol_kind::S_statements_opt: // statements_opt
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1160 "parser.tab.cc"
        break;

      case symbol_kind::S_statement: // statement
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1166 "parser.tab.cc"
        break;

      case symbol_kind::S_block_statement: // block_statement
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1172 "parser.tab.cc"
        break;

      case symbol_kind::S_expression_statement: // expression_statement
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1178 "parser.tab.cc"
        break;

      case symbol_kind::S_assignment_statement: // assignment_statement
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1184 "parser.tab.cc"
        break;

      case symbol_kind::S_conditional_statement: // conditional_statement
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1190 "parser.tab.cc"
        break;

      case symbol_kind::S_else_part_opt: // else_part_opt
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1196 "parser.tab.cc"
        break;

      case symbol_kind::S_ctrl_decl: // ctrl_decl
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1202 "parser.tab.cc"
        break;

      case symbol_kind::S_while_do_statement: // while_do_statement
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1208 "parser.tab.cc"
        break;

      case symbol_kind::S_do_while_statement: // do_while_statement
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1214 "parser.tab.cc"
        break;

      case symbol_kind::S_for_statement: // for_statement
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1220 "parser.tab.cc"
        break;

      case symbol_kind::S_index_var_decl: // index_var_decl
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1226 "parser.tab.cc"
        break;

      case symbol_kind::S_tuple_grouped_identifier_list: // tuple_grouped_identifier_list
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1232 "parser.tab.cc"
        break;

      case symbol_kind::S_identifier_list: // identifier_list
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1238 "parser.tab.cc"
        break;

      case symbol_kind::S_iterable_expression: // iterable_expression
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1244 "parser.tab.cc"
        break;

      case symbol_kind::S_expression_list: // expression_list
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1250 "parser.tab.cc"
        break;

      case symbol_kind::S_variable_declaration_statement: // variable_declaration_statement
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1256 "parser.tab.cc"
        break;

      case symbol_kind::S_privacy_specifier_opt: // privacy_specifier_opt
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1262 "parser.tab.cc"
        break;

      case symbol_kind::S_config_extern_or_export_opt: // config_extern_or_export_opt
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1268 "parser.tab.cc"
        break;

      case symbol_kind::S_variable_kind: // variable_kind
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1274 "parser.tab.cc"
        break;

      case symbol_kind::S_variable_declaration_list: // variable_declaration_list
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1280 "parser.tab.cc"
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1286 "parser.tab.cc"
        break;

      case symbol_kind::S_type_part_opt: // type_part_opt
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1292 "parser.tab.cc"
        break;

      case symbol_kind::S_type_expression: // type_expression
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1298 "parser.tab.cc"
        break;

      case symbol_kind::S_primitive_type: // primitive_type
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1304 "parser.tab.cc"
        break;

      case symbol_kind::S_primitive_type_parameter_part_opt: // primitive_type_parameter_part_opt
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1310 "parser.tab.cc"
        break;

      case symbol_kind::S_initialization_part_opt: // initialization_part_opt
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1316 "parser.tab.cc"
        break;

      case symbol_kind::S_expression: // expression
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1322 "parser.tab.cc"
        break;

      case symbol_kind::S_literal_expression: // literal_expression
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1328 "parser.tab.cc"
        break;

      case symbol_kind::S_range_literal: // range_literal
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1334 "parser.tab.cc"
        break;

      case symbol_kind::S_variable_expression: // variable_expression
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1340 "parser.tab.cc"
        break;

      case symbol_kind::S_parenthesized_expression: // parenthesized_expression
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1346 "parser.tab.cc"
        break;

      case symbol_kind::S_lvalue_expression: // lvalue_expression
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1352 "parser.tab.cc"
        break;

      case symbol_kind::S_unary_expression: // unary_expression
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1358 "parser.tab.cc"
        break;

      case symbol_kind::S_binary_expression: // binary_expression
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1364 "parser.tab.cc"
        break;

      case symbol_kind::S_method_call_expression: // method_call_expression
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1370 "parser.tab.cc"
        break;

      case symbol_kind::S_call_expression: // call_expression
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1376 "parser.tab.cc"
        break;

      case symbol_kind::S_named_expression_list: // named_expression_list
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1382 "parser.tab.cc"
        break;

      case symbol_kind::S_named_expression: // named_expression
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1388 "parser.tab.cc"
        break;

      case symbol_kind::S_member_access_expression: // member_access_expression
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1394 "parser.tab.cc"
        break;

      case symbol_kind::S_field_access_expression: // field_access_expression
#line 144 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1400 "parser.tab.cc"
        break;

      default:
        break;
    }
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // Discard the LAC context in case there still is one left from a
    // previous invocation.
    yy_lac_discard_ ("init");

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (drv));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;

        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    yy_lac_discard_ ("shift");
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_PLUS: // "+"
      case symbol_kind::S_MINUS: // "-"
      case symbol_kind::S_MULTIPLICATION: // "*"
      case symbol_kind::S_DIVISION: // "/"
      case symbol_kind::S_MODULUS: // "%"
      case symbol_kind::S_EXPONENTIATION: // "**"
      case symbol_kind::S_BITWISE_COMPLEMENT: // "~"
      case symbol_kind::S_BITWISE_AND: // "&"
      case symbol_kind::S_BITWISE_OR: // "|"
      case symbol_kind::S_BITWISE_XOR: // "^"
      case symbol_kind::S_BITWISE_SHIFT: // BITWISE_SHIFT
      case symbol_kind::S_EXCLAMATION_MARK: // "!"
      case symbol_kind::S_LOGICAL_AND: // "&&"
      case symbol_kind::S_LOGICAL_OR: // "||"
      case symbol_kind::S_ORDERED_COMP: // ORDERED_COMP
      case symbol_kind::S_EQUALITY_COMP: // EQUALITY_COMP
      case symbol_kind::S_BY: // "by"
      case symbol_kind::S_RANGE_COUNT: // "#"
      case symbol_kind::S_ASSIGNMENT: // "="
      case symbol_kind::S_COMPOUND_ASSIGNMENT: // COMPOUND_ASSIGNMENT
      case symbol_kind::S_STATEMENT_SEPARATOR: // ";"
      case symbol_kind::S_EXPRESSION_SEPARATOR: // ","
      case symbol_kind::S_LEFT_ROUND_BRACKET: // "("
      case symbol_kind::S_RIGHT_ROUND_BRACKET: // ")"
      case symbol_kind::S_LEFT_CURLY_BRACKET: // "{"
      case symbol_kind::S_RIGHT_CURLY_BRACKET: // "}"
      case symbol_kind::S_LEFT_SQUARE_BRACKET: // "["
      case symbol_kind::S_RIGHT_SQUARE_BRACKET: // "]"
      case symbol_kind::S_RANGE_SPECIFIER: // ".."
      case symbol_kind::S_HALF_OPEN_RANGE_SPECIFIER: // "..<"
      case symbol_kind::S_MEMBER_ACCESS: // "."
      case symbol_kind::S_VARIABLE_ARGUMENT_LISTS: // "..."
      case symbol_kind::S_COLUMN: // ":"
      case symbol_kind::S_PUBLIC: // "public"
      case symbol_kind::S_PRIVATE: // "private"
      case symbol_kind::S_CONFIG: // "config"
      case symbol_kind::S_EXTERN: // "extern"
      case symbol_kind::S_EXPORT: // "export"
      case symbol_kind::S_PARAM: // "param"
      case symbol_kind::S_REF: // "ref"
      case symbol_kind::S_VOID: // "void"
      case symbol_kind::S_NOTHING: // "nothing"
      case symbol_kind::S_BOOL: // "bool"
      case symbol_kind::S_INT: // "int"
      case symbol_kind::S_UINT: // "uint"
      case symbol_kind::S_REAL: // "real"
      case symbol_kind::S_IMAG: // "imag"
      case symbol_kind::S_COMPLEX: // "complex"
      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_BYTES: // "bytes"
      case symbol_kind::S_ENUM: // "enum"
      case symbol_kind::S_RECORD: // "record"
      case symbol_kind::S_CLASS: // "class"
      case symbol_kind::S_OWNED: // "owned"
      case symbol_kind::S_SHARED: // "shared"
      case symbol_kind::S_UNMANAGED: // "unmanaged"
      case symbol_kind::S_BORROWED: // "borrowed"
      case symbol_kind::S_IF: // "if"
      case symbol_kind::S_THEN: // "then"
      case symbol_kind::S_ELSE: // "else"
      case symbol_kind::S_VAR: // "var"
      case symbol_kind::S_CONST: // "const"
      case symbol_kind::S_WHILE: // "while"
      case symbol_kind::S_DO: // "do"
      case symbol_kind::S_FOR: // "for"
      case symbol_kind::S_IN: // "in"
      case symbol_kind::S_ZIP: // "zip"
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_INTEGER_LITERAL: // INTEGER_LITERAL
      case symbol_kind::S_statements_opt: // statements_opt
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_block_statement: // block_statement
      case symbol_kind::S_expression_statement: // expression_statement
      case symbol_kind::S_assignment_statement: // assignment_statement
      case symbol_kind::S_conditional_statement: // conditional_statement
      case symbol_kind::S_else_part_opt: // else_part_opt
      case symbol_kind::S_ctrl_decl: // ctrl_decl
      case symbol_kind::S_while_do_statement: // while_do_statement
      case symbol_kind::S_do_while_statement: // do_while_statement
      case symbol_kind::S_for_statement: // for_statement
      case symbol_kind::S_index_var_decl: // index_var_decl
      case symbol_kind::S_tuple_grouped_identifier_list: // tuple_grouped_identifier_list
      case symbol_kind::S_identifier_list: // identifier_list
      case symbol_kind::S_iterable_expression: // iterable_expression
      case symbol_kind::S_expression_list: // expression_list
      case symbol_kind::S_variable_declaration_statement: // variable_declaration_statement
      case symbol_kind::S_privacy_specifier_opt: // privacy_specifier_opt
      case symbol_kind::S_config_extern_or_export_opt: // config_extern_or_export_opt
      case symbol_kind::S_variable_kind: // variable_kind
      case symbol_kind::S_variable_declaration_list: // variable_declaration_list
      case symbol_kind::S_variable_declaration: // variable_declaration
      case symbol_kind::S_type_part_opt: // type_part_opt
      case symbol_kind::S_type_expression: // type_expression
      case symbol_kind::S_primitive_type: // primitive_type
      case symbol_kind::S_primitive_type_parameter_part_opt: // primitive_type_parameter_part_opt
      case symbol_kind::S_initialization_part_opt: // initialization_part_opt
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_literal_expression: // literal_expression
      case symbol_kind::S_range_literal: // range_literal
      case symbol_kind::S_variable_expression: // variable_expression
      case symbol_kind::S_parenthesized_expression: // parenthesized_expression
      case symbol_kind::S_lvalue_expression: // lvalue_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_binary_expression: // binary_expression
      case symbol_kind::S_method_call_expression: // method_call_expression
      case symbol_kind::S_call_expression: // call_expression
      case symbol_kind::S_named_expression_list: // named_expression_list
      case symbol_kind::S_named_expression: // named_expression
      case symbol_kind::S_member_access_expression: // member_access_expression
      case symbol_kind::S_field_access_expression: // field_access_expression
        yylhs.value.emplace< ASTNode* > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // unit: statements_opt
#line 174 "parser.yy"
                      { drv.result = yystack_[0].value.as < ASTNode* > ();}
#line 1776 "parser.tab.cc"
    break;

  case 3: // statements_opt: %empty
#line 177 "parser.yy"
                         {/*$$ = new ASTNode(ASTNodeType::Statements, {nullptr})*/nullptr;}
#line 1782 "parser.tab.cc"
    break;

  case 4: // statements_opt: statements_opt statement
#line 178 "parser.yy"
                           {yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::Statements, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1788 "parser.tab.cc"
    break;

  case 5: // statement: block_statement
#line 180 "parser.yy"
           { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1794 "parser.tab.cc"
    break;

  case 6: // statement: expression_statement
#line 180 "parser.yy"
                             { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1800 "parser.tab.cc"
    break;

  case 7: // statement: assignment_statement
#line 180 "parser.yy"
                                                    { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1806 "parser.tab.cc"
    break;

  case 8: // statement: conditional_statement
#line 180 "parser.yy"
                                                                           { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1812 "parser.tab.cc"
    break;

  case 9: // statement: while_do_statement
#line 180 "parser.yy"
                                                                                                   { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1818 "parser.tab.cc"
    break;

  case 10: // statement: do_while_statement
#line 181 "parser.yy"
  { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1824 "parser.tab.cc"
    break;

  case 11: // statement: for_statement
#line 181 "parser.yy"
                       { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1830 "parser.tab.cc"
    break;

  case 12: // statement: variable_declaration_statement
#line 181 "parser.yy"
                                       { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1836 "parser.tab.cc"
    break;

  case 13: // block_statement: "{" statements_opt "}"
#line 183 "parser.yy"
                                        { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BlockStatement, {yystack_[1].value.as < ASTNode* > ()}); delete yystack_[2].value.as < ASTNode* > (); delete yystack_[0].value.as < ASTNode* > ();}
#line 1842 "parser.tab.cc"
    break;

  case 14: // expression_statement: variable_expression ";"
#line 185 "parser.yy"
                                              { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::ExpressionStatement, {yystack_[1].value.as < ASTNode* > ()}); delete yystack_[0].value.as < ASTNode* > ();}
#line 1848 "parser.tab.cc"
    break;

  case 15: // expression_statement: call_expression ";"
#line 186 "parser.yy"
                      { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::ExpressionStatement, {yystack_[1].value.as < ASTNode* > ()}); delete yystack_[0].value.as < ASTNode* > ();}
#line 1854 "parser.tab.cc"
    break;

  case 16: // expression_statement: member_access_expression ";"
#line 187 "parser.yy"
                               { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::ExpressionStatement, {yystack_[1].value.as < ASTNode* > ()}); delete yystack_[0].value.as < ASTNode* > ();}
#line 1860 "parser.tab.cc"
    break;

  case 17: // assignment_statement: lvalue_expression "=" expression ";"
#line 190 "parser.yy"
                                       { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::AssignmentStatement, {yystack_[3].value.as < ASTNode* > (), yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > ()});}
#line 1866 "parser.tab.cc"
    break;

  case 18: // assignment_statement: lvalue_expression COMPOUND_ASSIGNMENT expression ";"
#line 191 "parser.yy"
                                                       { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::AssignmentStatement, {yystack_[3].value.as < ASTNode* > (), yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > ()});}
#line 1872 "parser.tab.cc"
    break;

  case 19: // conditional_statement: "if" expression "then" statement else_part_opt
#line 194 "parser.yy"
                                                 { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::ConditionalStatement, {yystack_[3].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[4].value.as < ASTNode* > (); delete yystack_[2].value.as < ASTNode* > ();}
#line 1878 "parser.tab.cc"
    break;

  case 20: // conditional_statement: "if" expression block_statement else_part_opt
#line 195 "parser.yy"
                                                { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::ConditionalStatement, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[3].value.as < ASTNode* > ();}
#line 1884 "parser.tab.cc"
    break;

  case 21: // conditional_statement: "if" ctrl_decl "then" statement else_part_opt
#line 196 "parser.yy"
                                                { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::ConditionalStatement, {yystack_[3].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[4].value.as < ASTNode* > (); delete yystack_[2].value.as < ASTNode* > ();}
#line 1890 "parser.tab.cc"
    break;

  case 22: // conditional_statement: "if" ctrl_decl block_statement else_part_opt
#line 197 "parser.yy"
                                               { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::ConditionalStatement, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[3].value.as < ASTNode* > ();}
#line 1896 "parser.tab.cc"
    break;

  case 23: // else_part_opt: %empty
#line 200 "parser.yy"
                      {yylhs.value.as < ASTNode* > () = nullptr;}
#line 1902 "parser.tab.cc"
    break;

  case 24: // else_part_opt: "else" statement
#line 201 "parser.yy"
                   {yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); delete yystack_[1].value.as < ASTNode* > ();}
#line 1908 "parser.tab.cc"
    break;

  case 25: // ctrl_decl: "var" IDENTIFIER "=" expression
#line 204 "parser.yy"
                                  { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::CtrlDecl, {yystack_[3].value.as < ASTNode* > (), yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[1].value.as < ASTNode* > ();}
#line 1914 "parser.tab.cc"
    break;

  case 26: // ctrl_decl: "const" IDENTIFIER "=" expression
#line 205 "parser.yy"
                                    { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::CtrlDecl, {yystack_[3].value.as < ASTNode* > (), yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[1].value.as < ASTNode* > ();}
#line 1920 "parser.tab.cc"
    break;

  case 27: // while_do_statement: "while" expression "do" statement
#line 208 "parser.yy"
                                    { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::WhileDoStatement, {yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[3].value.as < ASTNode* > (); delete yystack_[1].value.as < ASTNode* > ();}
#line 1926 "parser.tab.cc"
    break;

  case 28: // while_do_statement: "while" expression block_statement
#line 209 "parser.yy"
                                     { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::WhileDoStatement, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[2].value.as < ASTNode* > ();}
#line 1932 "parser.tab.cc"
    break;

  case 29: // while_do_statement: "while" ctrl_decl "do" statement
#line 210 "parser.yy"
                                   { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::WhileDoStatement, {yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[3].value.as < ASTNode* > (); delete yystack_[1].value.as < ASTNode* > ();}
#line 1938 "parser.tab.cc"
    break;

  case 30: // while_do_statement: "while" ctrl_decl block_statement
#line 211 "parser.yy"
                                    { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::WhileDoStatement, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[2].value.as < ASTNode* > ();}
#line 1944 "parser.tab.cc"
    break;

  case 31: // do_while_statement: "do" statement "while" expression ";"
#line 213 "parser.yy"
                                                          { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::DoWhileStatement, {yystack_[3].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > ()}); delete yystack_[4].value.as < ASTNode* > (); delete yystack_[2].value.as < ASTNode* > (); delete yystack_[0].value.as < ASTNode* > ();}
#line 1950 "parser.tab.cc"
    break;

  case 32: // for_statement: "for" index_var_decl "in" iterable_expression "do" statement
#line 216 "parser.yy"
                                                               { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::ForStatement, {yystack_[4].value.as < ASTNode* > (), yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[5].value.as < ASTNode* > (); delete yystack_[3].value.as < ASTNode* > (); delete yystack_[1].value.as < ASTNode* > ();}
#line 1956 "parser.tab.cc"
    break;

  case 33: // for_statement: "for" index_var_decl "in" iterable_expression block_statement
#line 217 "parser.yy"
                                                                { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::ForStatement, {yystack_[3].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[4].value.as < ASTNode* > (); delete yystack_[2].value.as < ASTNode* > ();}
#line 1962 "parser.tab.cc"
    break;

  case 34: // for_statement: "for" iterable_expression "do" statement
#line 218 "parser.yy"
                                           { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::ForStatement, {yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[3].value.as < ASTNode* > (); delete yystack_[1].value.as < ASTNode* > ();}
#line 1968 "parser.tab.cc"
    break;

  case 35: // for_statement: "for" iterable_expression block_statement
#line 219 "parser.yy"
                                            { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::ForStatement, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[2].value.as < ASTNode* > ();}
#line 1974 "parser.tab.cc"
    break;

  case 36: // index_var_decl: IDENTIFIER
#line 222 "parser.yy"
  { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1980 "parser.tab.cc"
    break;

  case 37: // index_var_decl: tuple_grouped_identifier_list
#line 223 "parser.yy"
  { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1986 "parser.tab.cc"
    break;

  case 38: // tuple_grouped_identifier_list: "(" identifier_list ")"
#line 225 "parser.yy"
                                                       { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::TupleGroupedIdentifierList, {yystack_[1].value.as < ASTNode* > ()}); delete yystack_[2].value.as < ASTNode* > (); delete yystack_[0].value.as < ASTNode* > ();}
#line 1992 "parser.tab.cc"
    break;

  case 39: // identifier_list: IDENTIFIER
#line 228 "parser.yy"
             { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::IdentifierList, {yystack_[0].value.as < ASTNode* > ()});}
#line 1998 "parser.tab.cc"
    break;

  case 40: // identifier_list: IDENTIFIER "," identifier_list
#line 229 "parser.yy"
                                 { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::IdentifierList, {yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[1].value.as < ASTNode* > ();}
#line 2004 "parser.tab.cc"
    break;

  case 41: // identifier_list: tuple_grouped_identifier_list
#line 230 "parser.yy"
  { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 2010 "parser.tab.cc"
    break;

  case 42: // identifier_list: tuple_grouped_identifier_list "," identifier_list
#line 231 "parser.yy"
                                                    { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::IdentifierList, {yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[1].value.as < ASTNode* > ();}
#line 2016 "parser.tab.cc"
    break;

  case 43: // iterable_expression: expression
#line 234 "parser.yy"
  { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 2022 "parser.tab.cc"
    break;

  case 44: // iterable_expression: "zip" "(" expression_list ")"
#line 235 "parser.yy"
                                { yylhs.value.as < ASTNode* > () = yystack_[1].value.as < ASTNode* > (); delete yystack_[3].value.as < ASTNode* > (); delete yystack_[2].value.as < ASTNode* > (); delete yystack_[0].value.as < ASTNode* > ();}
#line 2028 "parser.tab.cc"
    break;

  case 45: // expression_list: expression
#line 238 "parser.yy"
             { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::ExpressionList, {yystack_[0].value.as < ASTNode* > ()});}
#line 2034 "parser.tab.cc"
    break;

  case 46: // expression_list: expression "," expression_list
#line 239 "parser.yy"
                                 { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::ExpressionList, {yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[1].value.as < ASTNode* > ();}
#line 2040 "parser.tab.cc"
    break;

  case 47: // variable_declaration_statement: privacy_specifier_opt config_extern_or_export_opt variable_kind variable_declaration_list ";"
#line 241 "parser.yy"
                                                                                                                              { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::VariableDeclarationStatement, {yystack_[4].value.as < ASTNode* > (), yystack_[3].value.as < ASTNode* > (), yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > ()});}
#line 2046 "parser.tab.cc"
    break;

  case 48: // privacy_specifier_opt: %empty
#line 244 "parser.yy"
                    {yylhs.value.as < ASTNode* > () = nullptr;}
#line 2052 "parser.tab.cc"
    break;

  case 49: // privacy_specifier_opt: "public"
#line 245 "parser.yy"
  { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 2058 "parser.tab.cc"
    break;

  case 50: // privacy_specifier_opt: "private"
#line 245 "parser.yy"
             { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 2064 "parser.tab.cc"
    break;

  case 51: // config_extern_or_export_opt: %empty
#line 248 "parser.yy"
                    {yylhs.value.as < ASTNode* > () = nullptr;}
#line 2070 "parser.tab.cc"
    break;

  case 52: // config_extern_or_export_opt: "config"
#line 249 "parser.yy"
  { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 2076 "parser.tab.cc"
    break;

  case 53: // config_extern_or_export_opt: "extern"
#line 249 "parser.yy"
             { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 2082 "parser.tab.cc"
    break;

  case 54: // config_extern_or_export_opt: "export"
#line 249 "parser.yy"
                        { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 2088 "parser.tab.cc"
    break;

  case 55: // variable_kind: "param"
#line 252 "parser.yy"
          { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::VariableKind, {yystack_[0].value.as < ASTNode* > ()});}
#line 2094 "parser.tab.cc"
    break;

  case 56: // variable_kind: "const"
#line 253 "parser.yy"
          { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::VariableKind, {yystack_[0].value.as < ASTNode* > ()});}
#line 2100 "parser.tab.cc"
    break;

  case 57: // variable_kind: "var"
#line 254 "parser.yy"
        { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::VariableKind, {yystack_[0].value.as < ASTNode* > ()});}
#line 2106 "parser.tab.cc"
    break;

  case 58: // variable_kind: "ref"
#line 255 "parser.yy"
        { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::VariableKind, {yystack_[0].value.as < ASTNode* > ()});}
#line 2112 "parser.tab.cc"
    break;

  case 59: // variable_kind: "const" "ref"
#line 256 "parser.yy"
                { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::VariableKind, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 2118 "parser.tab.cc"
    break;

  case 60: // variable_declaration_list: variable_declaration
#line 259 "parser.yy"
                       { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::VariableDeclarationList, {yystack_[0].value.as < ASTNode* > ()});}
#line 2124 "parser.tab.cc"
    break;

  case 61: // variable_declaration_list: variable_declaration "," variable_declaration_list
#line 260 "parser.yy"
                                                     { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::VariableDeclarationList, {yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[1].value.as < ASTNode* > ();}
#line 2130 "parser.tab.cc"
    break;

  case 62: // variable_declaration: identifier_list type_part_opt initialization_part_opt
#line 262 "parser.yy"
                                                                            { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::VariableDeclaration, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 2136 "parser.tab.cc"
    break;

  case 63: // type_part_opt: %empty
#line 265 "parser.yy"
                    {yylhs.value.as < ASTNode* > () = nullptr;}
#line 2142 "parser.tab.cc"
    break;

  case 64: // type_part_opt: ":" type_expression
#line 266 "parser.yy"
                      {yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); delete yystack_[1].value.as < ASTNode* > ();}
#line 2148 "parser.tab.cc"
    break;

  case 65: // type_expression: primitive_type
#line 268 "parser.yy"
                 { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 2154 "parser.tab.cc"
    break;

  case 66: // type_expression: expression
#line 268 "parser.yy"
                                  { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 2160 "parser.tab.cc"
    break;

  case 67: // primitive_type: "void"
#line 271 "parser.yy"
         { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::PrimitiveType, {yystack_[0].value.as < ASTNode* > ()});}
#line 2166 "parser.tab.cc"
    break;

  case 68: // primitive_type: "nothing"
#line 272 "parser.yy"
            { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::PrimitiveType, {yystack_[0].value.as < ASTNode* > ()});}
#line 2172 "parser.tab.cc"
    break;

  case 69: // primitive_type: "bool"
#line 273 "parser.yy"
         { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::PrimitiveType, {yystack_[0].value.as < ASTNode* > ()});}
#line 2178 "parser.tab.cc"
    break;

  case 70: // primitive_type: "int" primitive_type_parameter_part_opt
#line 274 "parser.yy"
                                          { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::PrimitiveType, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 2184 "parser.tab.cc"
    break;

  case 71: // primitive_type: "uint" primitive_type_parameter_part_opt
#line 275 "parser.yy"
                                           { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::PrimitiveType, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 2190 "parser.tab.cc"
    break;

  case 72: // primitive_type: "real" primitive_type_parameter_part_opt
#line 276 "parser.yy"
                                           { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::PrimitiveType, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 2196 "parser.tab.cc"
    break;

  case 73: // primitive_type: "imag" primitive_type_parameter_part_opt
#line 277 "parser.yy"
                                           { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::PrimitiveType, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 2202 "parser.tab.cc"
    break;

  case 74: // primitive_type: "complex" primitive_type_parameter_part_opt
#line 278 "parser.yy"
                                              { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::PrimitiveType, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 2208 "parser.tab.cc"
    break;

  case 75: // primitive_type: "string"
#line 279 "parser.yy"
           { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::PrimitiveType, {yystack_[0].value.as < ASTNode* > ()});}
#line 2214 "parser.tab.cc"
    break;

  case 76: // primitive_type: "bytes"
#line 280 "parser.yy"
          { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::PrimitiveType, {yystack_[0].value.as < ASTNode* > ()});}
#line 2220 "parser.tab.cc"
    break;

  case 77: // primitive_type: "enum"
#line 281 "parser.yy"
         { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::PrimitiveType, {yystack_[0].value.as < ASTNode* > ()});}
#line 2226 "parser.tab.cc"
    break;

  case 78: // primitive_type: "record"
#line 282 "parser.yy"
           { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::PrimitiveType, {yystack_[0].value.as < ASTNode* > ()});}
#line 2232 "parser.tab.cc"
    break;

  case 79: // primitive_type: "class"
#line 283 "parser.yy"
          { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::PrimitiveType, {yystack_[0].value.as < ASTNode* > ()});}
#line 2238 "parser.tab.cc"
    break;

  case 80: // primitive_type: "owned"
#line 284 "parser.yy"
          { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::PrimitiveType, {yystack_[0].value.as < ASTNode* > ()});}
#line 2244 "parser.tab.cc"
    break;

  case 81: // primitive_type: "shared"
#line 285 "parser.yy"
           { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::PrimitiveType, {yystack_[0].value.as < ASTNode* > ()});}
#line 2250 "parser.tab.cc"
    break;

  case 82: // primitive_type: "unmanaged"
#line 286 "parser.yy"
              { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::PrimitiveType, {yystack_[0].value.as < ASTNode* > ()});}
#line 2256 "parser.tab.cc"
    break;

  case 83: // primitive_type: "borrowed"
#line 287 "parser.yy"
             { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::PrimitiveType, {yystack_[0].value.as < ASTNode* > ()});}
#line 2262 "parser.tab.cc"
    break;

  case 84: // primitive_type_parameter_part_opt: %empty
#line 290 "parser.yy"
         {yylhs.value.as < ASTNode* > () = nullptr;}
#line 2268 "parser.tab.cc"
    break;

  case 85: // primitive_type_parameter_part_opt: parenthesized_expression
#line 291 "parser.yy"
  { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 2274 "parser.tab.cc"
    break;

  case 86: // initialization_part_opt: %empty
#line 294 "parser.yy"
                    {yylhs.value.as < ASTNode* > () = nullptr;}
#line 2280 "parser.tab.cc"
    break;

  case 87: // initialization_part_opt: "=" expression
#line 295 "parser.yy"
                 {yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); delete yystack_[1].value.as < ASTNode* > ();}
#line 2286 "parser.tab.cc"
    break;

  case 88: // expression: literal_expression
#line 297 "parser.yy"
            { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 2292 "parser.tab.cc"
    break;

  case 89: // expression: lvalue_expression
#line 297 "parser.yy"
                                 { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 2298 "parser.tab.cc"
    break;

  case 90: // expression: unary_expression
#line 297 "parser.yy"
                                                     { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 2304 "parser.tab.cc"
    break;

  case 91: // expression: binary_expression
#line 297 "parser.yy"
                                                                        { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 2310 "parser.tab.cc"
    break;

  case 92: // literal_expression: INTEGER_LITERAL
#line 299 "parser.yy"
                    { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 2316 "parser.tab.cc"
    break;

  case 93: // literal_expression: range_literal
#line 299 "parser.yy"
                                      { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 2322 "parser.tab.cc"
    break;

  case 94: // range_literal: expression ".." expression
#line 302 "parser.yy"
                             { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::RangeLiteral, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 2328 "parser.tab.cc"
    break;

  case 95: // range_literal: expression "..<" expression
#line 303 "parser.yy"
                              { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::RangeLiteral, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 2334 "parser.tab.cc"
    break;

  case 96: // range_literal: expression ".."
#line 304 "parser.yy"
                  { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::RangeLiteral, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 2340 "parser.tab.cc"
    break;

  case 97: // range_literal: ".." expression
#line 305 "parser.yy"
                  { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::RangeLiteral, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 2346 "parser.tab.cc"
    break;

  case 98: // range_literal: "..<" expression
#line 306 "parser.yy"
                   { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::RangeLiteral, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 2352 "parser.tab.cc"
    break;

  case 99: // range_literal: ".."
#line 307 "parser.yy"
       { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::RangeLiteral, {yystack_[0].value.as < ASTNode* > ()});}
#line 2358 "parser.tab.cc"
    break;

  case 100: // variable_expression: IDENTIFIER
#line 309 "parser.yy"
                     { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 2364 "parser.tab.cc"
    break;

  case 101: // parenthesized_expression: "(" expression ")"
#line 311 "parser.yy"
                                             { yylhs.value.as < ASTNode* > () = yystack_[1].value.as < ASTNode* > (); delete yystack_[2].value.as < ASTNode* > (); delete yystack_[0].value.as < ASTNode* > ();}
#line 2370 "parser.tab.cc"
    break;

  case 102: // lvalue_expression: variable_expression
#line 313 "parser.yy"
                   { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 2376 "parser.tab.cc"
    break;

  case 103: // lvalue_expression: parenthesized_expression
#line 313 "parser.yy"
                                         { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 2382 "parser.tab.cc"
    break;

  case 104: // lvalue_expression: call_expression
#line 313 "parser.yy"
                                                                    { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 2388 "parser.tab.cc"
    break;

  case 105: // lvalue_expression: member_access_expression
#line 313 "parser.yy"
                                                                                      { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 2394 "parser.tab.cc"
    break;

  case 106: // unary_expression: "+" expression
#line 316 "parser.yy"
                                         { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::UnaryExpression, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 2400 "parser.tab.cc"
    break;

  case 107: // unary_expression: "-" expression
#line 317 "parser.yy"
                           { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::UnaryExpression, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 2406 "parser.tab.cc"
    break;

  case 108: // unary_expression: "~" expression
#line 318 "parser.yy"
                 { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::UnaryExpression, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 2412 "parser.tab.cc"
    break;

  case 109: // unary_expression: "!" expression
#line 319 "parser.yy"
                 { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::UnaryExpression, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 2418 "parser.tab.cc"
    break;

  case 110: // binary_expression: expression "+" expression
#line 322 "parser.yy"
                            { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 2424 "parser.tab.cc"
    break;

  case 111: // binary_expression: expression "-" expression
#line 323 "parser.yy"
                            { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 2430 "parser.tab.cc"
    break;

  case 112: // binary_expression: expression "*" expression
#line 324 "parser.yy"
                            { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 2436 "parser.tab.cc"
    break;

  case 113: // binary_expression: expression "/" expression
#line 325 "parser.yy"
                            { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 2442 "parser.tab.cc"
    break;

  case 114: // binary_expression: expression "%" expression
#line 326 "parser.yy"
                            { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 2448 "parser.tab.cc"
    break;

  case 115: // binary_expression: expression "**" expression
#line 327 "parser.yy"
                             { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 2454 "parser.tab.cc"
    break;

  case 116: // binary_expression: expression "&" expression
#line 328 "parser.yy"
                            { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 2460 "parser.tab.cc"
    break;

  case 117: // binary_expression: expression "|" expression
#line 329 "parser.yy"
                            { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 2466 "parser.tab.cc"
    break;

  case 118: // binary_expression: expression "^" expression
#line 330 "parser.yy"
                            { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 2472 "parser.tab.cc"
    break;

  case 119: // binary_expression: expression BITWISE_SHIFT expression
#line 331 "parser.yy"
                                      { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 2478 "parser.tab.cc"
    break;

  case 120: // binary_expression: expression "&&" expression
#line 332 "parser.yy"
                             { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 2484 "parser.tab.cc"
    break;

  case 121: // binary_expression: expression "||" expression
#line 333 "parser.yy"
                             { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 2490 "parser.tab.cc"
    break;

  case 122: // binary_expression: expression EQUALITY_COMP expression
#line 334 "parser.yy"
                                      { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 2496 "parser.tab.cc"
    break;

  case 123: // binary_expression: expression ORDERED_COMP expression
#line 335 "parser.yy"
                                     { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 2502 "parser.tab.cc"
    break;

  case 124: // binary_expression: expression "by" expression
#line 336 "parser.yy"
                             { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 2508 "parser.tab.cc"
    break;

  case 125: // binary_expression: expression "#" expression
#line 337 "parser.yy"
                            { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 2514 "parser.tab.cc"
    break;

  case 126: // method_call_expression: expression "." IDENTIFIER "(" named_expression_list ")"
#line 340 "parser.yy"
                                                                    {yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::MethodCallExpression, {yystack_[5].value.as < ASTNode* > (), yystack_[3].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > ()}); delete yystack_[4].value.as < ASTNode* > (); delete yystack_[2].value.as < ASTNode* > (); delete yystack_[0].value.as < ASTNode* > ();}
#line 2520 "parser.tab.cc"
    break;

  case 127: // method_call_expression: expression "." IDENTIFIER "[" named_expression_list "]"
#line 341 "parser.yy"
                                                                    {yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::MethodCallExpression, {yystack_[5].value.as < ASTNode* > (), yystack_[3].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > ()}); delete yystack_[4].value.as < ASTNode* > (); delete yystack_[2].value.as < ASTNode* > (); delete yystack_[0].value.as < ASTNode* > ();}
#line 2526 "parser.tab.cc"
    break;

  case 128: // call_expression: lvalue_expression "(" named_expression_list ")"
#line 345 "parser.yy"
                                                  { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::CallExpression, {yystack_[3].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > ()}); delete yystack_[2].value.as < ASTNode* > (); delete yystack_[0].value.as < ASTNode* > ();}
#line 2532 "parser.tab.cc"
    break;

  case 129: // call_expression: lvalue_expression "[" named_expression_list "]"
#line 346 "parser.yy"
                                                  { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::CallExpression, {yystack_[3].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > ()}); delete yystack_[2].value.as < ASTNode* > (); delete yystack_[0].value.as < ASTNode* > ();}
#line 2538 "parser.tab.cc"
    break;

  case 130: // named_expression_list: named_expression
#line 349 "parser.yy"
                   { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::NamedExpressionList, {yystack_[0].value.as < ASTNode* > ()});}
#line 2544 "parser.tab.cc"
    break;

  case 131: // named_expression_list: named_expression "," named_expression_list
#line 350 "parser.yy"
                                             { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::NamedExpressionList, {yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[1].value.as < ASTNode* > ();}
#line 2550 "parser.tab.cc"
    break;

  case 132: // named_expression: expression
#line 353 "parser.yy"
  { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 2556 "parser.tab.cc"
    break;

  case 133: // named_expression: IDENTIFIER "=" expression
#line 354 "parser.yy"
  { yylhs.value.as < ASTNode* > () = yystack_[2].value.as < ASTNode* > (); }
#line 2562 "parser.tab.cc"
    break;

  case 134: // member_access_expression: field_access_expression
#line 356 "parser.yy"
                          { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 2568 "parser.tab.cc"
    break;

  case 135: // member_access_expression: method_call_expression
#line 356 "parser.yy"
                                                    { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 2574 "parser.tab.cc"
    break;

  case 136: // field_access_expression: expression "." IDENTIFIER
#line 359 "parser.yy"
                                                   {yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::  FieldAccessExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[1].value.as < ASTNode* > ();}
#line 2580 "parser.tab.cc"
    break;


#line 2584 "parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      yy_lac_discard_ ("error recovery");
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    static const char *const yy_sname[] =
    {
    "end of file", "error", "invalid token", "+", "-", "*", "/", "%", "**",
  "~", "&", "|", "^", "BITWISE_SHIFT", "!", "&&", "||", "ORDERED_COMP",
  "EQUALITY_COMP", "by", "#", "=", "COMPOUND_ASSIGNMENT", ";", ",", "(",
  ")", "{", "}", "[", "]", "..", "..<", ".", "...", ":", "public",
  "private", "config", "extern", "export", "param", "ref", "void",
  "nothing", "bool", "int", "uint", "real", "imag", "complex", "string",
  "bytes", "enum", "record", "class", "owned", "shared", "unmanaged",
  "borrowed", "if", "then", "else", "var", "const", "while", "do", "for",
  "in", "zip", "IDENTIFIER", "INTEGER_LITERAL", "NEG", "POSITIVE_IDENTITY",
  "$accept", "unit", "statements_opt", "statement", "block_statement",
  "expression_statement", "assignment_statement", "conditional_statement",
  "else_part_opt", "ctrl_decl", "while_do_statement", "do_while_statement",
  "for_statement", "index_var_decl", "tuple_grouped_identifier_list",
  "identifier_list", "iterable_expression", "expression_list",
  "variable_declaration_statement", "privacy_specifier_opt",
  "config_extern_or_export_opt", "variable_kind",
  "variable_declaration_list", "variable_declaration", "type_part_opt",
  "type_expression", "primitive_type", "primitive_type_parameter_part_opt",
  "initialization_part_opt", "expression", "literal_expression",
  "range_literal", "variable_expression", "parenthesized_expression",
  "lvalue_expression", "unary_expression", "binary_expression",
  "method_call_expression", "call_expression", "named_expression_list",
  "named_expression", "member_access_expression",
  "field_access_expression", YY_NULLPTR
    };
    return yy_sname[yysymbol];
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

#if YYDEBUG
    // Execute LAC once. We don't care if it is successful, we
    // only do it for the sake of debugging output.
    if (!yyparser_.yy_lac_established_)
      yyparser_.yy_lac_check_ (yyla_.kind ());
#endif

    for (int yyx = 0; yyx < YYNTOKENS; ++yyx)
      {
        symbol_kind_type yysym = YY_CAST (symbol_kind_type, yyx);
        if (yysym != symbol_kind::S_YYerror
            && yysym != symbol_kind::S_YYUNDEF
            && yyparser_.yy_lac_check_ (yysym))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
      }
    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }




  bool
  parser::yy_lac_check_ (symbol_kind_type yytoken) const
  {
    // Logically, the yylac_stack's lifetime is confined to this function.
    // Clear it, to get rid of potential left-overs from previous call.
    yylac_stack_.clear ();
    // Reduce until we encounter a shift and thereby accept the token.
#if YYDEBUG
    YYCDEBUG << "LAC: checking lookahead " << symbol_name (yytoken) << ':';
#endif
    std::ptrdiff_t lac_top = 0;
    while (true)
      {
        state_type top_state = (yylac_stack_.empty ()
                                ? yystack_[lac_top].state
                                : yylac_stack_.back ());
        int yyrule = yypact_[+top_state];
        if (yy_pact_value_is_default_ (yyrule)
            || (yyrule += yytoken) < 0 || yylast_ < yyrule
            || yycheck_[yyrule] != yytoken)
          {
            // Use the default action.
            yyrule = yydefact_[+top_state];
            if (yyrule == 0)
              {
                YYCDEBUG << " Err\n";
                return false;
              }
          }
        else
          {
            // Use the action from yytable.
            yyrule = yytable_[yyrule];
            if (yy_table_value_is_error_ (yyrule))
              {
                YYCDEBUG << " Err\n";
                return false;
              }
            if (0 < yyrule)
              {
                YYCDEBUG << " S" << yyrule << '\n';
                return true;
              }
            yyrule = -yyrule;
          }
        // By now we know we have to simulate a reduce.
        YYCDEBUG << " R" << yyrule - 1;
        // Pop the corresponding number of values from the stack.
        {
          std::ptrdiff_t yylen = yyr2_[yyrule];
          // First pop from the LAC stack as many tokens as possible.
          std::ptrdiff_t lac_size = std::ptrdiff_t (yylac_stack_.size ());
          if (yylen < lac_size)
            {
              yylac_stack_.resize (std::size_t (lac_size - yylen));
              yylen = 0;
            }
          else if (lac_size)
            {
              yylac_stack_.clear ();
              yylen -= lac_size;
            }
          // Only afterwards look at the main stack.
          // We simulate popping elements by incrementing lac_top.
          lac_top += yylen;
        }
        // Keep top_state in sync with the updated stack.
        top_state = (yylac_stack_.empty ()
                     ? yystack_[lac_top].state
                     : yylac_stack_.back ());
        // Push the resulting state of the reduction.
        state_type state = yy_lr_goto_state_ (top_state, yyr1_[yyrule]);
        YYCDEBUG << " G" << int (state);
        yylac_stack_.push_back (state);
      }
  }

  // Establish the initial context if no initial context currently exists.
  bool
  parser::yy_lac_establish_ (symbol_kind_type yytoken)
  {
    /* Establish the initial context for the current lookahead if no initial
       context is currently established.

       We define a context as a snapshot of the parser stacks.  We define
       the initial context for a lookahead as the context in which the
       parser initially examines that lookahead in order to select a
       syntactic action.  Thus, if the lookahead eventually proves
       syntactically unacceptable (possibly in a later context reached via a
       series of reductions), the initial context can be used to determine
       the exact set of tokens that would be syntactically acceptable in the
       lookahead's place.  Moreover, it is the context after which any
       further semantic actions would be erroneous because they would be
       determined by a syntactically unacceptable token.

       yy_lac_establish_ should be invoked when a reduction is about to be
       performed in an inconsistent state (which, for the purposes of LAC,
       includes consistent states that don't know they're consistent because
       their default reductions have been disabled).

       For parse.lac=full, the implementation of yy_lac_establish_ is as
       follows.  If no initial context is currently established for the
       current lookahead, then check if that lookahead can eventually be
       shifted if syntactic actions continue from the current context.  */
    if (yy_lac_established_)
      return true;
    else
      {
#if YYDEBUG
        YYCDEBUG << "LAC: initial context established for "
                 << symbol_name (yytoken) << '\n';
#endif
        yy_lac_established_ = true;
        return yy_lac_check_ (yytoken);
      }
  }

  // Discard any previous initial lookahead context.
  void
  parser::yy_lac_discard_ (const char* event)
  {
   /* Discard any previous initial lookahead context because of Event,
      which may be a lookahead change or an invalidation of the currently
      established initial context for the current lookahead.

      The most common example of a lookahead change is a shift.  An example
      of both cases is syntax error recovery.  That is, a syntax error
      occurs when the lookahead is syntactically erroneous for the
      currently established initial context, so error recovery manipulates
      the parser stacks to try to find a new initial context in which the
      current lookahead is syntactically acceptable.  If it fails to find
      such a context, it discards the lookahead.  */
    if (yy_lac_established_)
      {
        YYCDEBUG << "LAC: initial context discarded due to "
                 << event << '\n';
        yy_lac_established_ = false;
      }
  }


  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
         In the first two cases, it might appear that the current syntax
         error should have been detected in the previous state when
         yy_lac_check was invoked.  However, at that time, there might
         have been a different syntax error that discarded a different
         initial context during error recovery, leaving behind the
         current lookahead.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short parser::yypact_ninf_ = -161;

  const signed char parser::yytable_ninf_ = -40;

  const short
  parser::yypact_[] =
  {
    -161,    21,   190,  -161,   377,   377,   377,   377,   377,  -161,
     167,   377,  -161,  -161,   308,   308,   293,   343,  -161,  -161,
    -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,   109,
     676,  -161,  -161,    12,  -161,    11,  -161,  -161,  -161,    15,
      19,  -161,    97,  -161,     5,  -161,  -161,    97,     8,     8,
     521,   278,   724,   724,   -26,   -16,     4,   490,   -13,   454,
      -9,   385,    37,    24,    25,  -161,    -3,   676,  -161,  -161,
    -161,   156,   377,   377,   377,   377,   377,   377,   377,   377,
     377,   377,   377,   377,   377,   377,   377,   377,   167,   377,
      17,  -161,   377,   377,   421,   421,  -161,  -161,  -161,  -161,
      76,    78,   293,    45,   293,    45,   293,  -161,   293,  -161,
     377,    -1,    85,    87,   377,   352,   293,  -161,  -161,  -161,
    -161,    82,   -20,   200,   200,     8,     8,     8,     8,   127,
     693,   801,    97,   755,   738,   787,   772,   707,   707,   724,
     724,    14,   552,   583,    99,   676,   101,   107,   106,   377,
     377,    45,   293,  -161,    45,  -161,  -161,  -161,   614,   -20,
     -20,  -161,   112,   645,     1,  -161,  -161,   -20,   118,   115,
     130,   131,   421,   421,  -161,  -161,   377,  -161,   421,  -161,
     676,   676,  -161,  -161,  -161,  -161,  -161,  -161,  -161,   377,
     293,  -161,   220,   136,  -161,   -20,   133,   134,   676,  -161,
    -161,  -161,  -161,  -161,  -161,   138,   138,   138,   138,   138,
    -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,
    -161,   676,   377,  -161,  -161,  -161,  -161,  -161,  -161,  -161,
    -161,  -161,  -161,   676
  };

  const unsigned char
  parser::yydefact_[] =
  {
       3,     0,    48,     1,     0,     0,     0,     0,     0,     3,
      99,     0,    49,    50,     0,     0,    48,     0,   100,    92,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    51,
       0,    88,    93,   102,   103,    89,    90,    91,   135,   104,
     105,   134,   106,   102,    89,   104,   105,   107,   108,   109,
       0,    48,    97,    98,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,     0,    37,     0,    43,    52,    53,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    96,     0,
       0,    14,     0,     0,     0,     0,    15,    16,   101,    13,
       0,     0,    48,    23,    48,    23,    48,    30,    48,    28,
       0,   100,    41,     0,     0,     0,    48,    35,    55,    58,
      57,    56,     0,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   123,   122,   124,   125,    94,
      95,   136,     0,     0,   100,   132,     0,   130,     0,     0,
       0,    23,    48,    22,    23,    20,    29,    27,     0,     0,
       0,    38,     0,    45,     0,    34,    59,     0,    39,    63,
       0,    60,     0,     0,    17,    18,     0,   128,     0,   129,
      25,    26,    21,    24,    19,    31,    40,    42,    44,     0,
      48,    33,     0,    86,    47,     0,     0,     0,   133,   131,
      46,    32,    67,    68,    69,    84,    84,    84,    84,    84,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    64,
      65,    66,     0,    62,    61,   126,   127,    70,    85,    71,
      72,    73,    74,    87
  };

  const short
  parser::yypgoto_[] =
  {
    -161,  -161,   152,    -8,   -39,  -161,  -161,  -161,   -96,   158,
    -161,  -161,  -161,  -161,   150,  -100,    60,   -12,  -161,  -161,
    -161,  -161,   -17,  -161,  -161,  -161,  -161,  -160,  -161,    -4,
    -161,  -161,    10,   198,    13,  -161,  -161,  -161,    35,   -50,
    -161,    50,  -161
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     1,     2,    20,    21,    22,    23,    24,   153,    56,
      25,    26,    27,    64,   112,   113,    66,   162,    28,    29,
      71,   122,   170,   171,   193,   219,   220,   227,   223,    30,
      31,    32,    43,    34,    44,    36,    37,    38,    45,   146,
     147,    46,    41
  };

  const short
  parser::yytable_[] =
  {
      42,    47,    48,    49,    50,   167,    52,    53,    60,   155,
      57,    59,    33,    67,     9,    35,    77,   103,   105,   107,
     109,     3,   169,   159,     9,   -39,    33,   117,     9,    35,
      94,     9,    92,    93,    95,    91,    94,    39,    96,   172,
      95,    90,    97,   173,   100,   148,   229,   230,   231,   232,
     168,    39,    40,   106,   101,   182,   110,    50,   184,   186,
     187,    33,   114,   116,    35,   102,    40,   190,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,    39,   141,   142,   143,
     145,   145,   -36,   115,   151,   169,   154,   149,   156,   150,
     157,    40,    74,    75,    76,    77,   158,   152,   165,   160,
     163,    67,    33,   161,    33,    35,    33,    35,    33,    35,
     176,    35,   196,   197,   166,   191,    33,   177,   199,    35,
      90,   178,    74,    75,    76,    77,   179,    39,   188,    39,
      81,    39,   159,    39,   183,   180,   181,    68,    69,    70,
     192,    39,    40,   194,    40,   195,    40,   222,    40,   225,
      90,    51,    33,     8,   226,    35,    40,    65,   145,   145,
       4,     5,   198,    58,   145,   164,     6,   200,   224,     0,
       0,     7,   201,     0,     0,   163,     0,    39,   221,     0,
      -2,     0,     8,     4,     5,     0,     0,   118,   119,     6,
      33,     0,    40,    35,     7,    74,    75,    76,    77,     0,
      78,    79,    80,    81,     0,     8,     0,     9,   233,   120,
     121,    10,    11,     4,     5,    39,    12,    13,     0,     6,
       0,     0,     0,    90,     7,     0,     0,    18,    19,     0,
      40,     0,     0,     0,     0,     8,     0,     0,     0,     0,
      14,    10,    11,     0,     0,    15,    16,    17,     0,     0,
      18,    19,     0,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
       0,     4,     5,     0,     0,     0,     0,     6,     0,     0,
      18,    19,     7,     0,     0,     0,     4,     5,     0,     0,
       0,     0,     6,     8,     0,     9,    99,     7,     0,    10,
      11,     4,     5,     0,    12,    13,     0,     6,     8,     0,
       9,     0,     7,     0,    10,    11,     0,     0,     0,    12,
      13,     0,     0,     8,     0,     0,     0,     0,    14,    10,
      11,     0,     0,    15,    16,    17,     4,     5,    18,    19,
       0,     0,     6,    14,     0,     4,     5,     7,    15,    16,
      17,     6,     0,    18,    19,     0,     7,     0,    61,     0,
       0,    54,    55,     0,    10,    11,     0,     8,    18,    19,
       4,     5,     0,    10,    11,     0,     6,     0,     4,     5,
       0,     7,     0,     0,     6,     0,     0,     0,     0,     7,
       0,     0,     8,   228,   228,   228,   228,   228,    10,    11,
      61,     0,    62,    63,    19,     0,    10,    11,     0,     0,
       0,    62,    18,    19,     4,     5,     0,     0,     0,     0,
       6,     0,     0,     0,     0,     7,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     8,    18,    19,     0,
       0,     0,    10,    11,     0,   111,    19,    72,    73,    74,
      75,    76,    77,     0,    78,    79,    80,    81,     0,    82,
      83,    84,    85,    86,    87,     0,     0,     0,     0,     0,
       0,     9,     0,     0,     0,    88,    89,    90,     0,     0,
       0,   144,    19,    72,    73,    74,    75,    76,    77,     0,
      78,    79,    80,    81,     0,    82,    83,    84,    85,    86,
      87,     0,     0,     0,     0,     0,     0,     9,     0,     0,
     108,    88,    89,    90,    72,    73,    74,    75,    76,    77,
       0,    78,    79,    80,    81,     0,    82,    83,    84,    85,
      86,    87,     0,     0,     0,     0,     0,    98,     0,     0,
       0,   104,    88,    89,    90,    72,    73,    74,    75,    76,
      77,     0,    78,    79,    80,    81,     0,    82,    83,    84,
      85,    86,    87,     0,     0,   174,     0,     0,     0,     0,
       0,     0,     0,    88,    89,    90,    72,    73,    74,    75,
      76,    77,     0,    78,    79,    80,    81,     0,    82,    83,
      84,    85,    86,    87,     0,     0,   175,     0,     0,     0,
       0,     0,     0,     0,    88,    89,    90,    72,    73,    74,
      75,    76,    77,     0,    78,    79,    80,    81,     0,    82,
      83,    84,    85,    86,    87,     0,     0,   185,     0,     0,
       0,     0,     0,     0,     0,    88,    89,    90,    72,    73,
      74,    75,    76,    77,     0,    78,    79,    80,    81,     0,
      82,    83,    84,    85,    86,    87,     0,     0,     0,   189,
       0,     0,     0,     0,     0,     0,    88,    89,    90,    72,
      73,    74,    75,    76,    77,     0,    78,    79,    80,    81,
       0,    82,    83,    84,    85,    86,    87,     0,    74,    75,
      76,    77,     0,    78,     0,    80,    81,    88,    89,    90,
      72,    73,    74,    75,    76,    77,     0,    78,    79,    80,
      81,     0,    82,    83,    84,    85,    90,    72,    73,    74,
      75,    76,    77,     0,    78,    79,    80,    81,    88,    89,
      90,    72,    73,    74,    75,    76,    77,     0,    78,    79,
      80,    81,     0,    82,     0,    84,    85,    90,    72,    73,
      74,    75,    76,    77,     0,    78,    79,    80,    81,    88,
      89,    90,    84,    85,     0,    72,    73,    74,    75,    76,
      77,     0,    78,    79,    80,    81,    88,    89,    90,    84,
      72,    73,    74,    75,    76,    77,     0,    78,    79,    80,
      81,     0,     0,    88,    89,    90,    74,    75,    76,    77,
       0,    78,     0,     0,    81,     0,     0,     0,    88,    89,
      90,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90
  };

  const short
  parser::yycheck_[] =
  {
       4,     5,     6,     7,     8,    25,    10,    11,    16,   105,
      14,    15,     2,    17,    27,     2,     8,    56,    57,    58,
      59,     0,   122,    24,    27,    26,    16,    66,    27,    16,
      25,    27,    21,    22,    29,    23,    25,     2,    23,    25,
      29,    33,    23,    29,    70,    95,   206,   207,   208,   209,
      70,    16,     2,    66,    70,   151,    65,    61,   154,   159,
     160,    51,    25,    66,    51,    61,    16,    66,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    51,    70,    92,    93,
      94,    95,    68,    68,   102,   195,   104,    21,   106,    21,
     108,    51,     5,     6,     7,     8,   110,    62,   116,    24,
     114,   115,   102,    26,   104,   102,   106,   104,   108,   106,
      21,   108,   172,   173,    42,   164,   116,    26,   178,   116,
      33,    24,     5,     6,     7,     8,    30,   102,    26,   104,
      13,   106,    24,   108,   152,   149,   150,    38,    39,    40,
      35,   116,   102,    23,   104,    24,   106,    21,   108,    26,
      33,     9,   152,    25,    30,   152,   116,    17,   172,   173,
       3,     4,   176,    15,   178,   115,     9,   189,   195,    -1,
      -1,    14,   190,    -1,    -1,   189,    -1,   152,   192,    -1,
       0,    -1,    25,     3,     4,    -1,    -1,    41,    42,     9,
     190,    -1,   152,   190,    14,     5,     6,     7,     8,    -1,
      10,    11,    12,    13,    -1,    25,    -1,    27,   222,    63,
      64,    31,    32,     3,     4,   190,    36,    37,    -1,     9,
      -1,    -1,    -1,    33,    14,    -1,    -1,    70,    71,    -1,
     190,    -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,
      60,    31,    32,    -1,    -1,    65,    66,    67,    -1,    -1,
      70,    71,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,     3,     4,    -1,    -1,    -1,    -1,     9,    -1,    -1,
      70,    71,    14,    -1,    -1,    -1,     3,     4,    -1,    -1,
      -1,    -1,     9,    25,    -1,    27,    28,    14,    -1,    31,
      32,     3,     4,    -1,    36,    37,    -1,     9,    25,    -1,
      27,    -1,    14,    -1,    31,    32,    -1,    -1,    -1,    36,
      37,    -1,    -1,    25,    -1,    -1,    -1,    -1,    60,    31,
      32,    -1,    -1,    65,    66,    67,     3,     4,    70,    71,
      -1,    -1,     9,    60,    -1,     3,     4,    14,    65,    66,
      67,     9,    -1,    70,    71,    -1,    14,    -1,    25,    -1,
      -1,    63,    64,    -1,    31,    32,    -1,    25,    70,    71,
       3,     4,    -1,    31,    32,    -1,     9,    -1,     3,     4,
      -1,    14,    -1,    -1,     9,    -1,    -1,    -1,    -1,    14,
      -1,    -1,    25,   205,   206,   207,   208,   209,    31,    32,
      25,    -1,    69,    70,    71,    -1,    31,    32,    -1,    -1,
      -1,    69,    70,    71,     3,     4,    -1,    -1,    -1,    -1,
       9,    -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    70,    71,    -1,
      -1,    -1,    31,    32,    -1,    70,    71,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    12,    13,    -1,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    -1,    -1,    -1,    31,    32,    33,    -1,    -1,
      -1,    70,    71,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    12,    13,    -1,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,
      66,    31,    32,    33,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    61,    31,    32,    33,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    19,    20,    -1,    -1,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    33,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    12,    13,    -1,    15,    16,
      17,    18,    19,    20,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    33,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    12,    13,    -1,    15,
      16,    17,    18,    19,    20,    -1,    -1,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    33,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    12,    13,    -1,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    12,    13,
      -1,    15,    16,    17,    18,    19,    20,    -1,     5,     6,
       7,     8,    -1,    10,    -1,    12,    13,    31,    32,    33,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    12,
      13,    -1,    15,    16,    17,    18,    33,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    12,    13,    31,    32,
      33,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      12,    13,    -1,    15,    -1,    17,    18,    33,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    12,    13,    31,
      32,    33,    17,    18,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    12,    13,    31,    32,    33,    17,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    12,
      13,    -1,    -1,    31,    32,    33,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    13,    -1,    -1,    -1,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33
  };

  const signed char
  parser::yystos_[] =
  {
       0,    75,    76,     0,     3,     4,     9,    14,    25,    27,
      31,    32,    36,    37,    60,    65,    66,    67,    70,    71,
      77,    78,    79,    80,    81,    84,    85,    86,    92,    93,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     115,   116,   103,   106,   108,   112,   115,   103,   103,   103,
     103,    76,   103,   103,    63,    64,    83,   103,    83,   103,
      77,    25,    69,    70,    87,    88,    90,   103,    38,    39,
      40,    94,     3,     4,     5,     6,     7,     8,    10,    11,
      12,    13,    15,    16,    17,    18,    19,    20,    31,    32,
      33,    23,    21,    22,    25,    29,    23,    23,    26,    28,
      70,    70,    61,    78,    61,    78,    66,    78,    66,    78,
      65,    70,    88,    89,    25,    68,    66,    78,    41,    42,
      63,    64,    95,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,    70,   103,   103,    70,   103,   113,   114,   113,    21,
      21,    77,    62,    82,    77,    82,    77,    77,   103,    24,
      24,    26,    91,   103,    90,    77,    42,    25,    70,    89,
      96,    97,    25,    29,    23,    23,    21,    26,    24,    30,
     103,   103,    82,    77,    82,    23,    89,    89,    26,    24,
      66,    78,    35,    98,    23,    24,   113,   113,   103,   113,
      91,    77,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    99,
     100,   103,    21,   102,    96,    26,    30,   101,   107,   101,
     101,   101,   101,   103
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    74,    75,    76,    76,    77,    77,    77,    77,    77,
      77,    77,    77,    78,    79,    79,    79,    80,    80,    81,
      81,    81,    81,    82,    82,    83,    83,    84,    84,    84,
      84,    85,    86,    86,    86,    86,    87,    87,    88,    89,
      89,    89,    89,    90,    90,    91,    91,    92,    93,    93,
      93,    94,    94,    94,    94,    95,    95,    95,    95,    95,
      96,    96,    97,    98,    98,    99,    99,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   101,   101,   102,   102,   103,   103,
     103,   103,   104,   104,   105,   105,   105,   105,   105,   105,
     106,   107,   108,   108,   108,   108,   109,   109,   109,   109,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   111,   111,   112,   112,
     113,   113,   114,   114,   115,   115,   116
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     2,     2,     4,     4,     5,
       4,     5,     4,     0,     2,     4,     4,     4,     3,     4,
       3,     5,     6,     5,     4,     3,     1,     1,     3,     1,
       3,     1,     3,     1,     4,     1,     3,     5,     0,     1,
       1,     0,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     3,     3,     0,     2,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     3,     3,     2,     2,     2,     1,
       1,     3,     1,     1,     1,     1,     2,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     6,     6,     4,     4,
       1,     3,     1,     3,     1,     1,     3
  };




#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   174,   174,   177,   178,   180,   180,   180,   180,   180,
     181,   181,   181,   183,   185,   186,   187,   190,   191,   194,
     195,   196,   197,   200,   201,   204,   205,   208,   209,   210,
     211,   213,   216,   217,   218,   219,   222,   223,   225,   228,
     229,   230,   231,   234,   235,   238,   239,   241,   244,   245,
     245,   248,   249,   249,   249,   252,   253,   254,   255,   256,
     259,   260,   262,   265,   266,   268,   268,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   290,   291,   294,   295,   297,   297,
     297,   297,   299,   299,   302,   303,   304,   305,   306,   307,
     309,   311,   313,   313,   313,   313,   316,   317,   318,   319,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   340,   341,   345,   346,
     349,   350,   353,   354,   356,   356,   359
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 3439 "parser.tab.cc"

#line 360 "parser.yy"


void yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
