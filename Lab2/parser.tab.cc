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
#line 27 "parser.yy"

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
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 602 "parser.tab.cc"
        break;

      case symbol_kind::S_MINUS: // "-"
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 608 "parser.tab.cc"
        break;

      case symbol_kind::S_MULTIPLICATION: // "*"
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 614 "parser.tab.cc"
        break;

      case symbol_kind::S_DIVISION: // "/"
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 620 "parser.tab.cc"
        break;

      case symbol_kind::S_MODULUS: // "%"
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 626 "parser.tab.cc"
        break;

      case symbol_kind::S_EXPONENTIATION: // "**"
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 632 "parser.tab.cc"
        break;

      case symbol_kind::S_BITWISE_COMPLEMENT: // "~"
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 638 "parser.tab.cc"
        break;

      case symbol_kind::S_BITWISE_AND: // "&"
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 644 "parser.tab.cc"
        break;

      case symbol_kind::S_BITWISE_OR: // "|"
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 650 "parser.tab.cc"
        break;

      case symbol_kind::S_BITWISE_XOR: // "^"
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 656 "parser.tab.cc"
        break;

      case symbol_kind::S_BITWISE_SHIFT: // BITWISE_SHIFT
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 662 "parser.tab.cc"
        break;

      case symbol_kind::S_EXCLAMATION_MARK: // "!"
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 668 "parser.tab.cc"
        break;

      case symbol_kind::S_LOGICAL_AND: // "&&"
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 674 "parser.tab.cc"
        break;

      case symbol_kind::S_LOGICAL_OR: // "||"
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 680 "parser.tab.cc"
        break;

      case symbol_kind::S_ORDERED_COMP: // ORDERED_COMP
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 686 "parser.tab.cc"
        break;

      case symbol_kind::S_EQUALITY_COMP: // EQUALITY_COMP
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 692 "parser.tab.cc"
        break;

      case symbol_kind::S_BY: // "by"
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 698 "parser.tab.cc"
        break;

      case symbol_kind::S_RANGE_COUNT: // "#"
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 704 "parser.tab.cc"
        break;

      case symbol_kind::S_ASSIGNMENT: // "="
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 710 "parser.tab.cc"
        break;

      case symbol_kind::S_COMPOUND_ASSIGNMENT: // COMPOUND_ASSIGNMENT
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 716 "parser.tab.cc"
        break;

      case symbol_kind::S_STATEMENT_SEPARATOR: // ";"
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 722 "parser.tab.cc"
        break;

      case symbol_kind::S_EXPRESSION_SEPARATOR: // ","
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 728 "parser.tab.cc"
        break;

      case symbol_kind::S_LEFT_ROUND_BRACKET: // "("
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 734 "parser.tab.cc"
        break;

      case symbol_kind::S_RIGHT_ROUND_BRACKET: // ")"
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 740 "parser.tab.cc"
        break;

      case symbol_kind::S_LEFT_CURLY_BRACKET: // "{"
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 746 "parser.tab.cc"
        break;

      case symbol_kind::S_RIGHT_CURLY_BRACKET: // "}"
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 752 "parser.tab.cc"
        break;

      case symbol_kind::S_LEFT_SQUARE_BRACKET: // "["
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 758 "parser.tab.cc"
        break;

      case symbol_kind::S_RIGHT_SQUARE_BRACKET: // "]"
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 764 "parser.tab.cc"
        break;

      case symbol_kind::S_RANGE_SPECIFIER: // ".."
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 770 "parser.tab.cc"
        break;

      case symbol_kind::S_HALF_OPEN_RANGE_SPECIFIER: // "..<"
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 776 "parser.tab.cc"
        break;

      case symbol_kind::S_MEMBER_ACCESS: // "."
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 782 "parser.tab.cc"
        break;

      case symbol_kind::S_VARIABLE_ARGUMENT_LISTS: // "..."
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 788 "parser.tab.cc"
        break;

      case symbol_kind::S_IF: // "if"
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 794 "parser.tab.cc"
        break;

      case symbol_kind::S_THEN: // "then"
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 800 "parser.tab.cc"
        break;

      case symbol_kind::S_ELSE: // "else"
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 806 "parser.tab.cc"
        break;

      case symbol_kind::S_VAR: // "var"
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 812 "parser.tab.cc"
        break;

      case symbol_kind::S_CONST: // "const"
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 818 "parser.tab.cc"
        break;

      case symbol_kind::S_WHILE: // "while"
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 824 "parser.tab.cc"
        break;

      case symbol_kind::S_DO: // "do"
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 830 "parser.tab.cc"
        break;

      case symbol_kind::S_FOR: // "for"
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 836 "parser.tab.cc"
        break;

      case symbol_kind::S_IN: // "in"
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 842 "parser.tab.cc"
        break;

      case symbol_kind::S_ZIP: // "zip"
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 848 "parser.tab.cc"
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 854 "parser.tab.cc"
        break;

      case symbol_kind::S_INTEGER_LITERAL: // INTEGER_LITERAL
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 860 "parser.tab.cc"
        break;

      case symbol_kind::S_statements_opt: // statements_opt
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 866 "parser.tab.cc"
        break;

      case symbol_kind::S_statement: // statement
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 872 "parser.tab.cc"
        break;

      case symbol_kind::S_block_statement: // block_statement
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 878 "parser.tab.cc"
        break;

      case symbol_kind::S_expression_statement: // expression_statement
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 884 "parser.tab.cc"
        break;

      case symbol_kind::S_assignment_statement: // assignment_statement
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 890 "parser.tab.cc"
        break;

      case symbol_kind::S_conditional_statement: // conditional_statement
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 896 "parser.tab.cc"
        break;

      case symbol_kind::S_else_part_opt: // else_part_opt
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 902 "parser.tab.cc"
        break;

      case symbol_kind::S_ctrl_decl: // ctrl_decl
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 908 "parser.tab.cc"
        break;

      case symbol_kind::S_while_do_statement: // while_do_statement
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 914 "parser.tab.cc"
        break;

      case symbol_kind::S_do_while_statement: // do_while_statement
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 920 "parser.tab.cc"
        break;

      case symbol_kind::S_for_statement: // for_statement
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 926 "parser.tab.cc"
        break;

      case symbol_kind::S_index_var_decl: // index_var_decl
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 932 "parser.tab.cc"
        break;

      case symbol_kind::S_tuple_grouped_identifier_list: // tuple_grouped_identifier_list
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 938 "parser.tab.cc"
        break;

      case symbol_kind::S_identifier_list: // identifier_list
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 944 "parser.tab.cc"
        break;

      case symbol_kind::S_iterable_expression: // iterable_expression
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 950 "parser.tab.cc"
        break;

      case symbol_kind::S_expression_list: // expression_list
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 956 "parser.tab.cc"
        break;

      case symbol_kind::S_expression: // expression
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 962 "parser.tab.cc"
        break;

      case symbol_kind::S_literal_expression: // literal_expression
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 968 "parser.tab.cc"
        break;

      case symbol_kind::S_range_literal: // range_literal
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 974 "parser.tab.cc"
        break;

      case symbol_kind::S_variable_expression: // variable_expression
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 980 "parser.tab.cc"
        break;

      case symbol_kind::S_parenthesized_expression: // parenthesized_expression
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 986 "parser.tab.cc"
        break;

      case symbol_kind::S_lvalue_expression: // lvalue_expression
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 992 "parser.tab.cc"
        break;

      case symbol_kind::S_unary_expression: // unary_expression
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 998 "parser.tab.cc"
        break;

      case symbol_kind::S_binary_expression: // binary_expression
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1004 "parser.tab.cc"
        break;

      case symbol_kind::S_method_call_expression: // method_call_expression
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1010 "parser.tab.cc"
        break;

      case symbol_kind::S_call_expression: // call_expression
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1016 "parser.tab.cc"
        break;

      case symbol_kind::S_named_expression_list: // named_expression_list
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1022 "parser.tab.cc"
        break;

      case symbol_kind::S_named_expression: // named_expression
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1028 "parser.tab.cc"
        break;

      case symbol_kind::S_member_access_expression: // member_access_expression
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1034 "parser.tab.cc"
        break;

      case symbol_kind::S_field_access_expression: // field_access_expression
#line 109 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 1040 "parser.tab.cc"
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
#line 138 "parser.yy"
                      { drv.result = yystack_[0].value.as < ASTNode* > ();}
#line 1380 "parser.tab.cc"
    break;

  case 3: // statements_opt: %empty
#line 141 "parser.yy"
                         {yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::Statements, {nullptr});}
#line 1386 "parser.tab.cc"
    break;

  case 4: // statements_opt: statements_opt statement
#line 142 "parser.yy"
                           {yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::Statements, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1392 "parser.tab.cc"
    break;

  case 5: // statement: block_statement
#line 144 "parser.yy"
           { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1398 "parser.tab.cc"
    break;

  case 6: // statement: expression_statement
#line 144 "parser.yy"
                             { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1404 "parser.tab.cc"
    break;

  case 7: // statement: assignment_statement
#line 144 "parser.yy"
                                                    { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1410 "parser.tab.cc"
    break;

  case 8: // statement: conditional_statement
#line 144 "parser.yy"
                                                                           { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1416 "parser.tab.cc"
    break;

  case 9: // statement: while_do_statement
#line 144 "parser.yy"
                                                                                                   { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1422 "parser.tab.cc"
    break;

  case 10: // statement: do_while_statement
#line 145 "parser.yy"
  { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1428 "parser.tab.cc"
    break;

  case 11: // statement: for_statement
#line 145 "parser.yy"
                       { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1434 "parser.tab.cc"
    break;

  case 12: // block_statement: "{" statements_opt "}"
#line 147 "parser.yy"
                                        { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BlockStatement, {yystack_[1].value.as < ASTNode* > ()}); delete yystack_[2].value.as < ASTNode* > (); delete yystack_[0].value.as < ASTNode* > ();}
#line 1440 "parser.tab.cc"
    break;

  case 13: // expression_statement: variable_expression ";"
#line 149 "parser.yy"
                                              { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::ExpressionStatement, {yystack_[1].value.as < ASTNode* > ()}); delete yystack_[0].value.as < ASTNode* > ();}
#line 1446 "parser.tab.cc"
    break;

  case 14: // expression_statement: call_expression ";"
#line 150 "parser.yy"
                      { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::ExpressionStatement, {yystack_[1].value.as < ASTNode* > ()}); delete yystack_[0].value.as < ASTNode* > ();}
#line 1452 "parser.tab.cc"
    break;

  case 15: // expression_statement: member_access_expression ";"
#line 151 "parser.yy"
                               { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::ExpressionStatement, {yystack_[1].value.as < ASTNode* > ()}); delete yystack_[0].value.as < ASTNode* > ();}
#line 1458 "parser.tab.cc"
    break;

  case 16: // assignment_statement: lvalue_expression "=" expression ";"
#line 154 "parser.yy"
                                       { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::AssignmentStatement, {yystack_[3].value.as < ASTNode* > (), yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > ()});}
#line 1464 "parser.tab.cc"
    break;

  case 17: // assignment_statement: lvalue_expression COMPOUND_ASSIGNMENT expression ";"
#line 155 "parser.yy"
                                                       { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::AssignmentStatement, {yystack_[3].value.as < ASTNode* > (), yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > ()});}
#line 1470 "parser.tab.cc"
    break;

  case 18: // conditional_statement: "if" expression "then" statement else_part_opt
#line 158 "parser.yy"
                                                 { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::ConditionalStatement, {yystack_[3].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[4].value.as < ASTNode* > (); delete yystack_[2].value.as < ASTNode* > ();}
#line 1476 "parser.tab.cc"
    break;

  case 19: // conditional_statement: "if" expression block_statement else_part_opt
#line 159 "parser.yy"
                                                { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::ConditionalStatement, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[3].value.as < ASTNode* > ();}
#line 1482 "parser.tab.cc"
    break;

  case 20: // conditional_statement: "if" ctrl_decl "then" statement else_part_opt
#line 160 "parser.yy"
                                                { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::ConditionalStatement, {yystack_[3].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[4].value.as < ASTNode* > (); delete yystack_[2].value.as < ASTNode* > ();}
#line 1488 "parser.tab.cc"
    break;

  case 21: // conditional_statement: "if" ctrl_decl block_statement else_part_opt
#line 161 "parser.yy"
                                               { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::ConditionalStatement, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[3].value.as < ASTNode* > ();}
#line 1494 "parser.tab.cc"
    break;

  case 22: // else_part_opt: %empty
#line 164 "parser.yy"
                      {yylhs.value.as < ASTNode* > () = nullptr;}
#line 1500 "parser.tab.cc"
    break;

  case 23: // else_part_opt: "else" statement
#line 165 "parser.yy"
                   {yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); delete yystack_[1].value.as < ASTNode* > ();}
#line 1506 "parser.tab.cc"
    break;

  case 24: // ctrl_decl: "var" IDENTIFIER "=" expression
#line 168 "parser.yy"
                                  { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::CtrlDecl, {yystack_[3].value.as < ASTNode* > (), yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[1].value.as < ASTNode* > ();}
#line 1512 "parser.tab.cc"
    break;

  case 25: // ctrl_decl: "const" IDENTIFIER "=" expression
#line 169 "parser.yy"
                                    { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::CtrlDecl, {yystack_[3].value.as < ASTNode* > (), yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[1].value.as < ASTNode* > ();}
#line 1518 "parser.tab.cc"
    break;

  case 26: // while_do_statement: "while" expression "do" statement
#line 172 "parser.yy"
                                    { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::WhileDoStatement, {yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[3].value.as < ASTNode* > (); delete yystack_[1].value.as < ASTNode* > ();}
#line 1524 "parser.tab.cc"
    break;

  case 27: // while_do_statement: "while" expression block_statement
#line 173 "parser.yy"
                                     { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::WhileDoStatement, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[2].value.as < ASTNode* > ();}
#line 1530 "parser.tab.cc"
    break;

  case 28: // while_do_statement: "while" ctrl_decl "do" statement
#line 174 "parser.yy"
                                   { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::WhileDoStatement, {yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[3].value.as < ASTNode* > (); delete yystack_[1].value.as < ASTNode* > ();}
#line 1536 "parser.tab.cc"
    break;

  case 29: // while_do_statement: "while" ctrl_decl block_statement
#line 175 "parser.yy"
                                    { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::WhileDoStatement, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[2].value.as < ASTNode* > ();}
#line 1542 "parser.tab.cc"
    break;

  case 30: // do_while_statement: "do" statement "while" expression ";"
#line 177 "parser.yy"
                                                          { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::DoWhileStatement, {yystack_[3].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > ()}); delete yystack_[4].value.as < ASTNode* > (); delete yystack_[2].value.as < ASTNode* > (); delete yystack_[0].value.as < ASTNode* > ();}
#line 1548 "parser.tab.cc"
    break;

  case 31: // for_statement: "for" index_var_decl "in" iterable_expression "do" statement
#line 180 "parser.yy"
                                                               { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::ForStatement, {yystack_[4].value.as < ASTNode* > (), yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[5].value.as < ASTNode* > (); delete yystack_[3].value.as < ASTNode* > (); delete yystack_[1].value.as < ASTNode* > ();}
#line 1554 "parser.tab.cc"
    break;

  case 32: // for_statement: "for" index_var_decl "in" iterable_expression block_statement
#line 181 "parser.yy"
                                                                { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::ForStatement, {yystack_[3].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[4].value.as < ASTNode* > (); delete yystack_[2].value.as < ASTNode* > ();}
#line 1560 "parser.tab.cc"
    break;

  case 33: // for_statement: "for" iterable_expression "do" statement
#line 182 "parser.yy"
                                           { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::ForStatement, {yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[3].value.as < ASTNode* > (); delete yystack_[1].value.as < ASTNode* > ();}
#line 1566 "parser.tab.cc"
    break;

  case 34: // for_statement: "for" iterable_expression block_statement
#line 183 "parser.yy"
                                            { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::ForStatement, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[2].value.as < ASTNode* > ();}
#line 1572 "parser.tab.cc"
    break;

  case 35: // index_var_decl: IDENTIFIER
#line 186 "parser.yy"
  { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1578 "parser.tab.cc"
    break;

  case 36: // index_var_decl: tuple_grouped_identifier_list
#line 187 "parser.yy"
  { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1584 "parser.tab.cc"
    break;

  case 37: // tuple_grouped_identifier_list: "(" identifier_list ")"
#line 189 "parser.yy"
                                                       { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::TupleGroupedIdentifierList, {yystack_[1].value.as < ASTNode* > ()}); delete yystack_[2].value.as < ASTNode* > (); delete yystack_[0].value.as < ASTNode* > ();}
#line 1590 "parser.tab.cc"
    break;

  case 38: // identifier_list: IDENTIFIER
#line 192 "parser.yy"
             { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::IdentifierList, {yystack_[0].value.as < ASTNode* > ()});}
#line 1596 "parser.tab.cc"
    break;

  case 39: // identifier_list: IDENTIFIER "," identifier_list
#line 193 "parser.yy"
                                 { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::IdentifierList, {yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[1].value.as < ASTNode* > ();}
#line 1602 "parser.tab.cc"
    break;

  case 40: // identifier_list: tuple_grouped_identifier_list
#line 194 "parser.yy"
  { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1608 "parser.tab.cc"
    break;

  case 41: // identifier_list: tuple_grouped_identifier_list "," identifier_list
#line 195 "parser.yy"
                                                    { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::TupleGroupedIdentifierList, {yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[1].value.as < ASTNode* > ();}
#line 1614 "parser.tab.cc"
    break;

  case 42: // iterable_expression: expression
#line 198 "parser.yy"
  { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1620 "parser.tab.cc"
    break;

  case 43: // iterable_expression: "zip" "(" expression_list ")"
#line 199 "parser.yy"
                                { yylhs.value.as < ASTNode* > () = yystack_[1].value.as < ASTNode* > (); delete yystack_[3].value.as < ASTNode* > (); delete yystack_[2].value.as < ASTNode* > (); delete yystack_[0].value.as < ASTNode* > ();}
#line 1626 "parser.tab.cc"
    break;

  case 44: // expression_list: expression
#line 202 "parser.yy"
             { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::ExpressionList, {yystack_[0].value.as < ASTNode* > ()});}
#line 1632 "parser.tab.cc"
    break;

  case 45: // expression_list: expression "," expression_list
#line 203 "parser.yy"
                                 { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::ExpressionList, {yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[1].value.as < ASTNode* > ();}
#line 1638 "parser.tab.cc"
    break;

  case 46: // expression: literal_expression
#line 205 "parser.yy"
            { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1644 "parser.tab.cc"
    break;

  case 47: // expression: lvalue_expression
#line 205 "parser.yy"
                                 { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1650 "parser.tab.cc"
    break;

  case 48: // expression: unary_expression
#line 205 "parser.yy"
                                                     { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1656 "parser.tab.cc"
    break;

  case 49: // expression: binary_expression
#line 205 "parser.yy"
                                                                        { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1662 "parser.tab.cc"
    break;

  case 50: // literal_expression: INTEGER_LITERAL
#line 207 "parser.yy"
                    { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1668 "parser.tab.cc"
    break;

  case 51: // literal_expression: range_literal
#line 207 "parser.yy"
                                      { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1674 "parser.tab.cc"
    break;

  case 52: // range_literal: expression ".." expression
#line 210 "parser.yy"
                             { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::RangeLiteral, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1680 "parser.tab.cc"
    break;

  case 53: // range_literal: expression "..<" expression
#line 211 "parser.yy"
                              { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::RangeLiteral, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1686 "parser.tab.cc"
    break;

  case 54: // range_literal: expression ".."
#line 212 "parser.yy"
                  { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::RangeLiteral, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1692 "parser.tab.cc"
    break;

  case 55: // range_literal: ".." expression
#line 213 "parser.yy"
                  { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::RangeLiteral, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1698 "parser.tab.cc"
    break;

  case 56: // range_literal: "..<" expression
#line 214 "parser.yy"
                   { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::RangeLiteral, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1704 "parser.tab.cc"
    break;

  case 57: // range_literal: ".."
#line 215 "parser.yy"
       { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::RangeLiteral, {yystack_[0].value.as < ASTNode* > ()});}
#line 1710 "parser.tab.cc"
    break;

  case 58: // variable_expression: IDENTIFIER
#line 217 "parser.yy"
                     { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1716 "parser.tab.cc"
    break;

  case 59: // parenthesized_expression: "(" expression ")"
#line 219 "parser.yy"
                                             { yylhs.value.as < ASTNode* > () = yystack_[1].value.as < ASTNode* > (); delete yystack_[2].value.as < ASTNode* > (); delete yystack_[0].value.as < ASTNode* > ();}
#line 1722 "parser.tab.cc"
    break;

  case 60: // lvalue_expression: variable_expression
#line 221 "parser.yy"
                   { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1728 "parser.tab.cc"
    break;

  case 61: // lvalue_expression: parenthesized_expression
#line 221 "parser.yy"
                                         { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1734 "parser.tab.cc"
    break;

  case 62: // lvalue_expression: call_expression
#line 221 "parser.yy"
                                                                    { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1740 "parser.tab.cc"
    break;

  case 63: // lvalue_expression: member_access_expression
#line 221 "parser.yy"
                                                                                      { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1746 "parser.tab.cc"
    break;

  case 64: // unary_expression: "+" expression
#line 224 "parser.yy"
                                         { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::UnaryExpression, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1752 "parser.tab.cc"
    break;

  case 65: // unary_expression: "-" expression
#line 225 "parser.yy"
                           { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::UnaryExpression, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1758 "parser.tab.cc"
    break;

  case 66: // unary_expression: "~" expression
#line 226 "parser.yy"
                 { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::UnaryExpression, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1764 "parser.tab.cc"
    break;

  case 67: // unary_expression: "!" expression
#line 227 "parser.yy"
                 { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::UnaryExpression, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1770 "parser.tab.cc"
    break;

  case 68: // binary_expression: expression "+" expression
#line 230 "parser.yy"
                            { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1776 "parser.tab.cc"
    break;

  case 69: // binary_expression: expression "-" expression
#line 231 "parser.yy"
                            { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1782 "parser.tab.cc"
    break;

  case 70: // binary_expression: expression "*" expression
#line 232 "parser.yy"
                            { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1788 "parser.tab.cc"
    break;

  case 71: // binary_expression: expression "/" expression
#line 233 "parser.yy"
                            { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1794 "parser.tab.cc"
    break;

  case 72: // binary_expression: expression "%" expression
#line 234 "parser.yy"
                            { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1800 "parser.tab.cc"
    break;

  case 73: // binary_expression: expression "**" expression
#line 235 "parser.yy"
                             { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1806 "parser.tab.cc"
    break;

  case 74: // binary_expression: expression "&" expression
#line 236 "parser.yy"
                            { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1812 "parser.tab.cc"
    break;

  case 75: // binary_expression: expression "|" expression
#line 237 "parser.yy"
                            { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1818 "parser.tab.cc"
    break;

  case 76: // binary_expression: expression "^" expression
#line 238 "parser.yy"
                            { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1824 "parser.tab.cc"
    break;

  case 77: // binary_expression: expression BITWISE_SHIFT expression
#line 239 "parser.yy"
                                      { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1830 "parser.tab.cc"
    break;

  case 78: // binary_expression: expression "&&" expression
#line 240 "parser.yy"
                             { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1836 "parser.tab.cc"
    break;

  case 79: // binary_expression: expression "||" expression
#line 241 "parser.yy"
                             { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1842 "parser.tab.cc"
    break;

  case 80: // binary_expression: expression EQUALITY_COMP expression
#line 242 "parser.yy"
                                      { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1848 "parser.tab.cc"
    break;

  case 81: // binary_expression: expression ORDERED_COMP expression
#line 243 "parser.yy"
                                     { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1854 "parser.tab.cc"
    break;

  case 82: // binary_expression: expression "by" expression
#line 244 "parser.yy"
                             { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1860 "parser.tab.cc"
    break;

  case 83: // binary_expression: expression "#" expression
#line 245 "parser.yy"
                            { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1866 "parser.tab.cc"
    break;

  case 84: // method_call_expression: expression "." IDENTIFIER "(" named_expression_list ")"
#line 248 "parser.yy"
                                                                    {yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::MethodCallExpression, {yystack_[5].value.as < ASTNode* > (), yystack_[3].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > ()}); delete yystack_[4].value.as < ASTNode* > (); delete yystack_[2].value.as < ASTNode* > (); delete yystack_[0].value.as < ASTNode* > ();}
#line 1872 "parser.tab.cc"
    break;

  case 85: // method_call_expression: expression "." IDENTIFIER "[" named_expression_list "]"
#line 249 "parser.yy"
                                                                    {yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::MethodCallExpression, {yystack_[5].value.as < ASTNode* > (), yystack_[3].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > ()}); delete yystack_[4].value.as < ASTNode* > (); delete yystack_[2].value.as < ASTNode* > (); delete yystack_[0].value.as < ASTNode* > ();}
#line 1878 "parser.tab.cc"
    break;

  case 86: // call_expression: lvalue_expression "(" named_expression_list ")"
#line 253 "parser.yy"
                                                  { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::CallExpression, {yystack_[3].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > ()}); delete yystack_[2].value.as < ASTNode* > (); delete yystack_[0].value.as < ASTNode* > ();}
#line 1884 "parser.tab.cc"
    break;

  case 87: // call_expression: lvalue_expression "[" named_expression_list "]"
#line 254 "parser.yy"
                                                  { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::CallExpression, {yystack_[3].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > ()}); delete yystack_[2].value.as < ASTNode* > (); delete yystack_[0].value.as < ASTNode* > ();}
#line 1890 "parser.tab.cc"
    break;

  case 88: // named_expression_list: named_expression
#line 257 "parser.yy"
                   { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::NamedExpressionList, {yystack_[0].value.as < ASTNode* > ()});}
#line 1896 "parser.tab.cc"
    break;

  case 89: // named_expression_list: named_expression "," named_expression_list
#line 258 "parser.yy"
                                             { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::NamedExpressionList, {yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[1].value.as < ASTNode* > ();}
#line 1902 "parser.tab.cc"
    break;

  case 90: // named_expression: expression
#line 261 "parser.yy"
  { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1908 "parser.tab.cc"
    break;

  case 91: // named_expression: IDENTIFIER "=" expression
#line 262 "parser.yy"
  { yylhs.value.as < ASTNode* > () = yystack_[2].value.as < ASTNode* > (); }
#line 1914 "parser.tab.cc"
    break;

  case 92: // member_access_expression: field_access_expression
#line 264 "parser.yy"
                          { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1920 "parser.tab.cc"
    break;

  case 93: // member_access_expression: method_call_expression
#line 264 "parser.yy"
                                                    { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1926 "parser.tab.cc"
    break;

  case 94: // field_access_expression: expression "." IDENTIFIER
#line 267 "parser.yy"
                                                   {yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::  FieldAccessExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[1].value.as < ASTNode* > ();}
#line 1932 "parser.tab.cc"
    break;


#line 1936 "parser.tab.cc"

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
  ")", "{", "}", "[", "]", "..", "..<", ".", "...", "if", "then", "else",
  "var", "const", "while", "do", "for", "in", "zip", "IDENTIFIER",
  "INTEGER_LITERAL", "NEG", "POSITIVE_IDENTITY", "$accept", "unit",
  "statements_opt", "statement", "block_statement", "expression_statement",
  "assignment_statement", "conditional_statement", "else_part_opt",
  "ctrl_decl", "while_do_statement", "do_while_statement", "for_statement",
  "index_var_decl", "tuple_grouped_identifier_list", "identifier_list",
  "iterable_expression", "expression_list", "expression",
  "literal_expression", "range_literal", "variable_expression",
  "parenthesized_expression", "lvalue_expression", "unary_expression",
  "binary_expression", "method_call_expression", "call_expression",
  "named_expression_list", "named_expression", "member_access_expression",
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


  const signed char parser::yypact_ninf_ = -95;

  const signed char parser::yytable_ninf_ = -39;

  const short
  parser::yypact_[] =
  {
     -95,    24,   220,   -95,   310,   310,   310,   310,   310,   -95,
      18,   310,   265,   265,   220,     6,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   599,   -95,   -95,    -5,
     -95,   168,   -95,   -95,   -95,    11,    13,   -95,    34,   -95,
      -6,   -95,   -95,    34,     0,     0,   444,    45,   122,   122,
       8,    33,    39,   410,   -16,   378,    20,   322,    58,    41,
      46,   -95,    30,   599,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
      18,   310,    43,   -95,   310,   310,   334,   334,   -95,   -95,
     -95,   -95,    80,    81,   220,    67,   220,    67,   220,   -95,
     220,   -95,   310,    32,    96,    79,   310,   277,   220,   -95,
     152,   152,     0,     0,     0,     0,   162,   616,   111,    34,
     678,   661,   710,   695,   630,   630,   122,   122,     1,   475,
     506,   110,   599,   123,   112,   121,   310,   310,    67,   220,
     -95,    67,   -95,   -95,   -95,   537,    10,    10,   -95,   126,
     568,    38,   -95,   334,   334,   -95,   -95,   310,   -95,   334,
     -95,   599,   599,   -95,   -95,   -95,   -95,    10,   132,   -95,
     -95,   -95,   310,   220,   -95,   140,   131,   599,   -95,   -95,
     -95,   -95,   -95
  };

  const signed char
  parser::yydefact_[] =
  {
       3,     0,     2,     1,     0,     0,     0,     0,     0,     3,
      57,     0,     0,     0,     0,     0,    58,    50,     4,     5,
       6,     7,     8,     9,    10,    11,     0,    46,    51,    60,
      61,    47,    48,    49,    93,    62,    63,    92,    64,    60,
      47,    62,    63,    65,    66,    67,     0,     0,    55,    56,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
       0,    36,     0,    42,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,     0,     0,    13,     0,     0,     0,     0,    14,    15,
      59,    12,     0,     0,     0,    22,     0,    22,     0,    29,
       0,    27,     0,    58,    40,     0,     0,     0,     0,    34,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    81,    80,    82,    83,    52,    53,    94,     0,
       0,    58,    90,     0,    88,     0,     0,     0,    22,     0,
      21,    22,    19,    28,    26,     0,     0,     0,    37,     0,
      44,     0,    33,     0,     0,    16,    17,     0,    86,     0,
      87,    24,    25,    20,    23,    18,    30,     0,    38,    39,
      41,    43,     0,     0,    32,     0,     0,    91,    89,    45,
      31,    84,    85
  };

  const short
  parser::yypgoto_[] =
  {
     -95,   -95,   164,    86,   -48,   -95,   -95,   -95,   -94,   161,
     -95,   -95,   -95,   -95,   163,   -65,    69,     5,   135,   -95,
     -95,    -2,   -95,    -1,   -95,   -95,   -95,    14,   -85,   -95,
      15,   -95
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     1,     2,    18,    19,    20,    21,    22,   140,    52,
      23,    24,    25,    60,   104,   105,    62,   149,    26,    27,
      28,    39,    30,    40,    32,    33,    34,    41,   133,   134,
      42,    37
  };

  const short
  parser::yytable_[] =
  {
      29,    31,   135,   142,    95,    97,    99,   101,    69,     4,
       5,     9,    29,    31,   109,     6,    35,    36,    83,    86,
       7,     4,     5,    87,     3,    98,   153,     6,    35,    36,
     154,    57,     7,    82,    88,   167,    89,    10,    11,    66,
      67,    68,    69,     8,   163,    29,    31,   165,     4,     5,
      58,    59,    17,    92,     6,   168,   146,     9,   -38,     7,
     102,    35,    36,    16,    17,     9,     9,    82,   175,   176,
       8,   108,     9,    91,   178,    94,    10,    11,    93,   173,
      12,   169,   170,   106,   -35,    13,    14,    15,   128,   107,
      16,    17,    29,    31,    29,    31,    29,    31,    29,    31,
      56,   136,   137,   174,   139,   148,    29,    31,    35,    36,
      35,    36,    35,    36,    35,    36,    66,    67,    68,    69,
     147,    70,    35,    36,    73,    64,    65,    66,    67,    68,
      69,   157,    70,    71,    72,    73,   159,    29,    31,    38,
      43,    44,    45,    46,    82,    48,    49,    53,    55,   158,
      63,   160,   171,    35,    36,    82,   146,    66,    67,    68,
      69,   182,    70,    71,    72,    73,   181,    66,    67,    68,
      69,    29,    31,    47,    54,    73,   151,   179,    61,     0,
     138,     0,   141,     0,   143,    82,   144,    35,    36,    84,
      85,     0,    46,    86,   152,    82,     0,    87,     0,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,     0,     0,   129,
     130,   132,   132,     4,     5,   164,     0,     0,     0,     6,
       0,     0,     0,     0,     7,     0,     0,   145,     0,     0,
       0,   150,    63,     0,     0,     8,     0,     9,     0,     0,
       0,    10,    11,     0,     0,    12,     0,     0,     0,   180,
      13,    14,    15,     0,     0,    16,    17,     0,     4,     5,
       0,   161,   162,     0,     6,     0,     0,     0,     0,     7,
       4,     5,     0,     0,     0,     0,     6,     0,   132,   132,
       8,     7,   177,     0,   132,     0,    10,    11,     0,     0,
       0,     0,     8,    50,    51,     0,     0,   150,    10,    11,
      16,    17,     0,     4,     5,     0,     0,     0,     0,     6,
       0,    58,    16,    17,     7,     4,     5,     0,     0,     0,
       0,     6,     0,     0,     0,     8,     7,     4,     5,     0,
       0,    10,    11,     6,     0,     0,     0,    57,     7,     0,
       0,     0,     0,    10,    11,    16,    17,     0,     0,     8,
       0,     0,     0,     0,     0,    10,    11,   103,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   131,
      17,    64,    65,    66,    67,    68,    69,     0,    70,    71,
      72,    73,     0,    74,    75,    76,    77,    78,    79,     0,
       0,     0,     0,     0,     0,     9,     0,     0,     0,    80,
      81,    82,     0,    64,    65,    66,    67,    68,    69,   100,
      70,    71,    72,    73,     0,    74,    75,    76,    77,    78,
      79,     0,     0,     0,     0,     0,     0,     9,     0,     0,
       0,    80,    81,    82,     0,     0,    96,    64,    65,    66,
      67,    68,    69,     0,    70,    71,    72,    73,     0,    74,
      75,    76,    77,    78,    79,     0,     0,     0,     0,     0,
      90,     0,     0,     0,     0,    80,    81,    82,    64,    65,
      66,    67,    68,    69,     0,    70,    71,    72,    73,     0,
      74,    75,    76,    77,    78,    79,     0,     0,   155,     0,
       0,     0,     0,     0,     0,     0,    80,    81,    82,    64,
      65,    66,    67,    68,    69,     0,    70,    71,    72,    73,
       0,    74,    75,    76,    77,    78,    79,     0,     0,   156,
       0,     0,     0,     0,     0,     0,     0,    80,    81,    82,
      64,    65,    66,    67,    68,    69,     0,    70,    71,    72,
      73,     0,    74,    75,    76,    77,    78,    79,     0,     0,
     166,     0,     0,     0,     0,     0,     0,     0,    80,    81,
      82,    64,    65,    66,    67,    68,    69,     0,    70,    71,
      72,    73,     0,    74,    75,    76,    77,    78,    79,     0,
       0,     0,   172,     0,     0,     0,     0,     0,     0,    80,
      81,    82,    64,    65,    66,    67,    68,    69,     0,    70,
      71,    72,    73,     0,    74,    75,    76,    77,    78,    79,
       0,    66,    67,    68,    69,     0,    70,     0,    72,    73,
      80,    81,    82,    64,    65,    66,    67,    68,    69,     0,
      70,    71,    72,    73,     0,    74,    75,    76,    77,    82,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,    81,    82,    64,    65,    66,    67,    68,    69,
       0,    70,    71,    72,    73,     0,    74,     0,    76,    77,
       0,    64,    65,    66,    67,    68,    69,     0,    70,    71,
      72,    73,    80,    81,    82,    76,    77,     0,    64,    65,
      66,    67,    68,    69,     0,    70,    71,    72,    73,    80,
      81,    82,    76,    64,    65,    66,    67,    68,    69,     0,
      70,    71,    72,    73,     0,     0,    80,    81,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,    81,    82
  };

  const short
  parser::yycheck_[] =
  {
       2,     2,    87,    97,    52,    53,    54,    55,     8,     3,
       4,    27,    14,    14,    62,     9,     2,     2,    23,    25,
      14,     3,     4,    29,     0,    41,    25,     9,    14,    14,
      29,    25,    14,    33,    23,    25,    23,    31,    32,     5,
       6,     7,     8,    25,   138,    47,    47,   141,     3,     4,
      44,    45,    46,    45,     9,    45,    24,    27,    26,    14,
      40,    47,    47,    45,    46,    27,    27,    33,   153,   154,
      25,    41,    27,    28,   159,    36,    31,    32,    45,    41,
      35,   146,   147,    25,    43,    40,    41,    42,    45,    43,
      45,    46,    94,    94,    96,    96,    98,    98,   100,   100,
      14,    21,    21,   151,    37,    26,   108,   108,    94,    94,
      96,    96,    98,    98,   100,   100,     5,     6,     7,     8,
      24,    10,   108,   108,    13,     3,     4,     5,     6,     7,
       8,    21,    10,    11,    12,    13,    24,   139,   139,     4,
       5,     6,     7,     8,    33,    10,    11,    12,    13,    26,
      15,    30,    26,   139,   139,    33,    24,     5,     6,     7,
       8,    30,    10,    11,    12,    13,    26,     5,     6,     7,
       8,   173,   173,     9,    13,    13,   107,   172,    15,    -1,
      94,    -1,    96,    -1,    98,    33,   100,   173,   173,    21,
      22,    -1,    57,    25,   108,    33,    -1,    29,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    -1,    -1,    84,
      85,    86,    87,     3,     4,   139,    -1,    -1,    -1,     9,
      -1,    -1,    -1,    -1,    14,    -1,    -1,   102,    -1,    -1,
      -1,   106,   107,    -1,    -1,    25,    -1,    27,    -1,    -1,
      -1,    31,    32,    -1,    -1,    35,    -1,    -1,    -1,   173,
      40,    41,    42,    -1,    -1,    45,    46,    -1,     3,     4,
      -1,   136,   137,    -1,     9,    -1,    -1,    -1,    -1,    14,
       3,     4,    -1,    -1,    -1,    -1,     9,    -1,   153,   154,
      25,    14,   157,    -1,   159,    -1,    31,    32,    -1,    -1,
      -1,    -1,    25,    38,    39,    -1,    -1,   172,    31,    32,
      45,    46,    -1,     3,     4,    -1,    -1,    -1,    -1,     9,
      -1,    44,    45,    46,    14,     3,     4,    -1,    -1,    -1,
      -1,     9,    -1,    -1,    -1,    25,    14,     3,     4,    -1,
      -1,    31,    32,     9,    -1,    -1,    -1,    25,    14,    -1,
      -1,    -1,    -1,    31,    32,    45,    46,    -1,    -1,    25,
      -1,    -1,    -1,    -1,    -1,    31,    32,    45,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      12,    13,    -1,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    33,    -1,     3,     4,     5,     6,     7,     8,    41,
      10,    11,    12,    13,    -1,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    31,    32,    33,    -1,    -1,    36,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    12,    13,    -1,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    -1,    -1,    -1,    31,    32,    33,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    12,    13,    -1,
      15,    16,    17,    18,    19,    20,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    12,    13,
      -1,    15,    16,    17,    18,    19,    20,    -1,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    12,
      13,    -1,    15,    16,    17,    18,    19,    20,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
      33,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      12,    13,    -1,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    33,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    12,    13,    -1,    15,    16,    17,    18,    19,    20,
      -1,     5,     6,     7,     8,    -1,    10,    -1,    12,    13,
      31,    32,    33,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    12,    13,    -1,    15,    16,    17,    18,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    33,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    12,    13,    -1,    15,    -1,    17,    18,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      12,    13,    31,    32,    33,    17,    18,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    12,    13,    31,
      32,    33,    17,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    12,    13,    -1,    -1,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    33
  };

  const signed char
  parser::yystos_[] =
  {
       0,    50,    51,     0,     3,     4,     9,    14,    25,    27,
      31,    32,    35,    40,    41,    42,    45,    46,    52,    53,
      54,    55,    56,    59,    60,    61,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    79,    80,    67,    70,
      72,    76,    79,    67,    67,    67,    67,    51,    67,    67,
      38,    39,    58,    67,    58,    67,    52,    25,    44,    45,
      62,    63,    65,    67,     3,     4,     5,     6,     7,     8,
      10,    11,    12,    13,    15,    16,    17,    18,    19,    20,
      31,    32,    33,    23,    21,    22,    25,    29,    23,    23,
      26,    28,    45,    45,    36,    53,    36,    53,    41,    53,
      41,    53,    40,    45,    63,    64,    25,    43,    41,    53,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    45,    67,
      67,    45,    67,    77,    78,    77,    21,    21,    52,    37,
      57,    52,    57,    52,    52,    67,    24,    24,    26,    66,
      67,    65,    52,    25,    29,    23,    23,    21,    26,    24,
      30,    67,    67,    57,    52,    57,    23,    25,    45,    64,
      64,    26,    24,    41,    53,    77,    77,    67,    77,    66,
      52,    26,    30
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    49,    50,    51,    51,    52,    52,    52,    52,    52,
      52,    52,    53,    54,    54,    54,    55,    55,    56,    56,
      56,    56,    57,    57,    58,    58,    59,    59,    59,    59,
      60,    61,    61,    61,    61,    62,    62,    63,    64,    64,
      64,    64,    65,    65,    66,    66,    67,    67,    67,    67,
      68,    68,    69,    69,    69,    69,    69,    69,    70,    71,
      72,    72,    72,    72,    73,    73,    73,    73,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    75,    75,    76,    76,    77,    77,
      78,    78,    79,    79,    80
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     2,     2,     4,     4,     5,     4,
       5,     4,     0,     2,     4,     4,     4,     3,     4,     3,
       5,     6,     5,     4,     3,     1,     1,     3,     1,     3,
       1,     3,     1,     4,     1,     3,     1,     1,     1,     1,
       1,     1,     3,     3,     2,     2,     2,     1,     1,     3,
       1,     1,     1,     1,     2,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     6,     6,     4,     4,     1,     3,
       1,     3,     1,     1,     3
  };




#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   138,   138,   141,   142,   144,   144,   144,   144,   144,
     145,   145,   147,   149,   150,   151,   154,   155,   158,   159,
     160,   161,   164,   165,   168,   169,   172,   173,   174,   175,
     177,   180,   181,   182,   183,   186,   187,   189,   192,   193,
     194,   195,   198,   199,   202,   203,   205,   205,   205,   205,
     207,   207,   210,   211,   212,   213,   214,   215,   217,   219,
     221,   221,   221,   221,   224,   225,   226,   227,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   248,   249,   253,   254,   257,   258,
     261,   262,   264,   264,   267
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
#line 2736 "parser.tab.cc"

#line 268 "parser.yy"


void yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
