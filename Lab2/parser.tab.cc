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
      case symbol_kind::S_call_expression: // call_expression
      case symbol_kind::S_named_expression_list: // named_expression_list
      case symbol_kind::S_named_expression: // named_expression
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
      case symbol_kind::S_call_expression: // call_expression
      case symbol_kind::S_named_expression_list: // named_expression_list
      case symbol_kind::S_named_expression: // named_expression
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
      case symbol_kind::S_call_expression: // call_expression
      case symbol_kind::S_named_expression_list: // named_expression_list
      case symbol_kind::S_named_expression: // named_expression
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
      case symbol_kind::S_call_expression: // call_expression
      case symbol_kind::S_named_expression_list: // named_expression_list
      case symbol_kind::S_named_expression: // named_expression
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
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 582 "parser.tab.cc"
        break;

      case symbol_kind::S_MINUS: // "-"
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 588 "parser.tab.cc"
        break;

      case symbol_kind::S_MULTIPLICATION: // "*"
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 594 "parser.tab.cc"
        break;

      case symbol_kind::S_DIVISION: // "/"
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 600 "parser.tab.cc"
        break;

      case symbol_kind::S_MODULUS: // "%"
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 606 "parser.tab.cc"
        break;

      case symbol_kind::S_EXPONENTIATION: // "**"
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 612 "parser.tab.cc"
        break;

      case symbol_kind::S_BITWISE_COMPLEMENT: // "~"
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 618 "parser.tab.cc"
        break;

      case symbol_kind::S_BITWISE_AND: // "&"
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 624 "parser.tab.cc"
        break;

      case symbol_kind::S_BITWISE_OR: // "|"
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 630 "parser.tab.cc"
        break;

      case symbol_kind::S_BITWISE_XOR: // "^"
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 636 "parser.tab.cc"
        break;

      case symbol_kind::S_BITWISE_SHIFT: // BITWISE_SHIFT
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 642 "parser.tab.cc"
        break;

      case symbol_kind::S_EXCLAMATION_MARK: // "!"
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 648 "parser.tab.cc"
        break;

      case symbol_kind::S_LOGICAL_AND: // "&&"
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 654 "parser.tab.cc"
        break;

      case symbol_kind::S_LOGICAL_OR: // "||"
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 660 "parser.tab.cc"
        break;

      case symbol_kind::S_ORDERED_COMP: // ORDERED_COMP
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 666 "parser.tab.cc"
        break;

      case symbol_kind::S_EQUALITY_COMP: // EQUALITY_COMP
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 672 "parser.tab.cc"
        break;

      case symbol_kind::S_BY: // "by"
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 678 "parser.tab.cc"
        break;

      case symbol_kind::S_RANGE_COUNT: // "#"
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 684 "parser.tab.cc"
        break;

      case symbol_kind::S_ASSIGNMENT: // "="
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 690 "parser.tab.cc"
        break;

      case symbol_kind::S_COMPOUND_ASSIGNMENT: // COMPOUND_ASSIGNMENT
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 696 "parser.tab.cc"
        break;

      case symbol_kind::S_STATEMENT_SEPARATOR: // ";"
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 702 "parser.tab.cc"
        break;

      case symbol_kind::S_EXPRESSION_SEPARATOR: // ","
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 708 "parser.tab.cc"
        break;

      case symbol_kind::S_LEFT_ROUND_BRACKET: // "("
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 714 "parser.tab.cc"
        break;

      case symbol_kind::S_RIGHT_ROUND_BRACKET: // ")"
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 720 "parser.tab.cc"
        break;

      case symbol_kind::S_LEFT_CURLY_BRACKET: // "{"
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 726 "parser.tab.cc"
        break;

      case symbol_kind::S_RIGHT_CURLY_BRACKET: // "}"
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 732 "parser.tab.cc"
        break;

      case symbol_kind::S_LEFT_SQUARE_BRACKET: // "["
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 738 "parser.tab.cc"
        break;

      case symbol_kind::S_RIGHT_SQUARE_BRACKET: // "]"
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 744 "parser.tab.cc"
        break;

      case symbol_kind::S_RANGE_SPECIFIER: // ".."
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 750 "parser.tab.cc"
        break;

      case symbol_kind::S_HALF_OPEN_RANGE_SPECIFIER: // "..<"
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 756 "parser.tab.cc"
        break;

      case symbol_kind::S_IF: // "if"
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 762 "parser.tab.cc"
        break;

      case symbol_kind::S_THEN: // "then"
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 768 "parser.tab.cc"
        break;

      case symbol_kind::S_ELSE: // "else"
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 774 "parser.tab.cc"
        break;

      case symbol_kind::S_VAR: // "var"
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 780 "parser.tab.cc"
        break;

      case symbol_kind::S_CONST: // "const"
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 786 "parser.tab.cc"
        break;

      case symbol_kind::S_WHILE: // "while"
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 792 "parser.tab.cc"
        break;

      case symbol_kind::S_DO: // "do"
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 798 "parser.tab.cc"
        break;

      case symbol_kind::S_FOR: // "for"
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 804 "parser.tab.cc"
        break;

      case symbol_kind::S_IN: // "in"
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 810 "parser.tab.cc"
        break;

      case symbol_kind::S_ZIP: // "zip"
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 816 "parser.tab.cc"
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 822 "parser.tab.cc"
        break;

      case symbol_kind::S_INTEGER_LITERAL: // INTEGER_LITERAL
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 828 "parser.tab.cc"
        break;

      case symbol_kind::S_statements_opt: // statements_opt
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 834 "parser.tab.cc"
        break;

      case symbol_kind::S_statement: // statement
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 840 "parser.tab.cc"
        break;

      case symbol_kind::S_block_statement: // block_statement
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 846 "parser.tab.cc"
        break;

      case symbol_kind::S_expression_statement: // expression_statement
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 852 "parser.tab.cc"
        break;

      case symbol_kind::S_assignment_statement: // assignment_statement
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 858 "parser.tab.cc"
        break;

      case symbol_kind::S_conditional_statement: // conditional_statement
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 864 "parser.tab.cc"
        break;

      case symbol_kind::S_else_part_opt: // else_part_opt
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 870 "parser.tab.cc"
        break;

      case symbol_kind::S_ctrl_decl: // ctrl_decl
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 876 "parser.tab.cc"
        break;

      case symbol_kind::S_while_do_statement: // while_do_statement
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 882 "parser.tab.cc"
        break;

      case symbol_kind::S_do_while_statement: // do_while_statement
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 888 "parser.tab.cc"
        break;

      case symbol_kind::S_for_statement: // for_statement
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 894 "parser.tab.cc"
        break;

      case symbol_kind::S_index_var_decl: // index_var_decl
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 900 "parser.tab.cc"
        break;

      case symbol_kind::S_tuple_grouped_identifier_list: // tuple_grouped_identifier_list
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 906 "parser.tab.cc"
        break;

      case symbol_kind::S_identifier_list: // identifier_list
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 912 "parser.tab.cc"
        break;

      case symbol_kind::S_iterable_expression: // iterable_expression
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 918 "parser.tab.cc"
        break;

      case symbol_kind::S_expression_list: // expression_list
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 924 "parser.tab.cc"
        break;

      case symbol_kind::S_expression: // expression
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 930 "parser.tab.cc"
        break;

      case symbol_kind::S_literal_expression: // literal_expression
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 936 "parser.tab.cc"
        break;

      case symbol_kind::S_range_literal: // range_literal
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 942 "parser.tab.cc"
        break;

      case symbol_kind::S_variable_expression: // variable_expression
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 948 "parser.tab.cc"
        break;

      case symbol_kind::S_parenthesized_expression: // parenthesized_expression
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 954 "parser.tab.cc"
        break;

      case symbol_kind::S_lvalue_expression: // lvalue_expression
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 960 "parser.tab.cc"
        break;

      case symbol_kind::S_unary_expression: // unary_expression
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 966 "parser.tab.cc"
        break;

      case symbol_kind::S_binary_expression: // binary_expression
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 972 "parser.tab.cc"
        break;

      case symbol_kind::S_call_expression: // call_expression
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 978 "parser.tab.cc"
        break;

      case symbol_kind::S_named_expression_list: // named_expression_list
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 984 "parser.tab.cc"
        break;

      case symbol_kind::S_named_expression: // named_expression
#line 105 "parser.yy"
                 { yyo << *yysym.value.template as < ASTNode* > (); }
#line 990 "parser.tab.cc"
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
      case symbol_kind::S_call_expression: // call_expression
      case symbol_kind::S_named_expression_list: // named_expression_list
      case symbol_kind::S_named_expression: // named_expression
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
#line 128 "parser.yy"
                      { drv.result = yystack_[0].value.as < ASTNode* > ();}
#line 1325 "parser.tab.cc"
    break;

  case 3: // statements_opt: %empty
#line 131 "parser.yy"
                         {yylhs.value.as < ASTNode* > () = nullptr;}
#line 1331 "parser.tab.cc"
    break;

  case 4: // statements_opt: statements_opt statement
#line 132 "parser.yy"
                           {yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::Statements, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1337 "parser.tab.cc"
    break;

  case 5: // statement: block_statement
#line 134 "parser.yy"
           { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1343 "parser.tab.cc"
    break;

  case 6: // statement: expression_statement
#line 134 "parser.yy"
                             { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1349 "parser.tab.cc"
    break;

  case 7: // statement: assignment_statement
#line 134 "parser.yy"
                                                    { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1355 "parser.tab.cc"
    break;

  case 8: // statement: conditional_statement
#line 134 "parser.yy"
                                                                           { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1361 "parser.tab.cc"
    break;

  case 9: // statement: while_do_statement
#line 134 "parser.yy"
                                                                                                   { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1367 "parser.tab.cc"
    break;

  case 10: // statement: do_while_statement
#line 135 "parser.yy"
  { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1373 "parser.tab.cc"
    break;

  case 11: // statement: for_statement
#line 135 "parser.yy"
                       { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1379 "parser.tab.cc"
    break;

  case 12: // block_statement: "{" statements_opt "}"
#line 137 "parser.yy"
                                        { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BlockStatement, {yystack_[1].value.as < ASTNode* > ()}); delete yystack_[2].value.as < ASTNode* > (); delete yystack_[0].value.as < ASTNode* > ();}
#line 1385 "parser.tab.cc"
    break;

  case 13: // expression_statement: variable_expression ";"
#line 139 "parser.yy"
                                              { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::ExpressionStatement, {yystack_[1].value.as < ASTNode* > ()}); delete yystack_[0].value.as < ASTNode* > ();}
#line 1391 "parser.tab.cc"
    break;

  case 14: // assignment_statement: lvalue_expression "=" expression ";"
#line 142 "parser.yy"
                                       { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::AssignmentStatement, {yystack_[3].value.as < ASTNode* > (), yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > ()});}
#line 1397 "parser.tab.cc"
    break;

  case 15: // assignment_statement: lvalue_expression COMPOUND_ASSIGNMENT expression ";"
#line 143 "parser.yy"
                                                       { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::AssignmentStatement, {yystack_[3].value.as < ASTNode* > (), yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > ()});}
#line 1403 "parser.tab.cc"
    break;

  case 16: // conditional_statement: "if" expression "then" statement else_part_opt
#line 146 "parser.yy"
                                                 { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::ConditionalStatement, {yystack_[3].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[4].value.as < ASTNode* > (); delete yystack_[2].value.as < ASTNode* > ();}
#line 1409 "parser.tab.cc"
    break;

  case 17: // conditional_statement: "if" expression block_statement else_part_opt
#line 147 "parser.yy"
                                                { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::ConditionalStatement, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[3].value.as < ASTNode* > ();}
#line 1415 "parser.tab.cc"
    break;

  case 18: // conditional_statement: "if" ctrl_decl "then" statement else_part_opt
#line 148 "parser.yy"
                                                { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::ConditionalStatement, {yystack_[3].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[4].value.as < ASTNode* > (); delete yystack_[2].value.as < ASTNode* > ();}
#line 1421 "parser.tab.cc"
    break;

  case 19: // conditional_statement: "if" ctrl_decl block_statement else_part_opt
#line 149 "parser.yy"
                                               { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::ConditionalStatement, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[3].value.as < ASTNode* > ();}
#line 1427 "parser.tab.cc"
    break;

  case 20: // else_part_opt: %empty
#line 152 "parser.yy"
                      {yylhs.value.as < ASTNode* > () = nullptr;}
#line 1433 "parser.tab.cc"
    break;

  case 21: // else_part_opt: "else" statement
#line 153 "parser.yy"
                   {yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); delete yystack_[1].value.as < ASTNode* > ();}
#line 1439 "parser.tab.cc"
    break;

  case 22: // ctrl_decl: "var" IDENTIFIER "=" expression
#line 156 "parser.yy"
                                  { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::CtrlDecl, {yystack_[3].value.as < ASTNode* > (), yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[1].value.as < ASTNode* > ();}
#line 1445 "parser.tab.cc"
    break;

  case 23: // ctrl_decl: "const" IDENTIFIER "=" expression
#line 157 "parser.yy"
                                    { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::CtrlDecl, {yystack_[3].value.as < ASTNode* > (), yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[1].value.as < ASTNode* > ();}
#line 1451 "parser.tab.cc"
    break;

  case 24: // while_do_statement: "while" expression "do" statement
#line 160 "parser.yy"
                                    { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::WhileDoStatement, {yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[3].value.as < ASTNode* > (); delete yystack_[1].value.as < ASTNode* > ();}
#line 1457 "parser.tab.cc"
    break;

  case 25: // while_do_statement: "while" expression block_statement
#line 161 "parser.yy"
                                     { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::WhileDoStatement, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[2].value.as < ASTNode* > ();}
#line 1463 "parser.tab.cc"
    break;

  case 26: // while_do_statement: "while" ctrl_decl "do" statement
#line 162 "parser.yy"
                                   { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::WhileDoStatement, {yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[3].value.as < ASTNode* > (); delete yystack_[1].value.as < ASTNode* > ();}
#line 1469 "parser.tab.cc"
    break;

  case 27: // while_do_statement: "while" ctrl_decl block_statement
#line 163 "parser.yy"
                                    { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::WhileDoStatement, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[2].value.as < ASTNode* > ();}
#line 1475 "parser.tab.cc"
    break;

  case 28: // do_while_statement: "do" statement "while" expression ";"
#line 165 "parser.yy"
                                                          { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::DoWhileStatement, {yystack_[3].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > ()}); delete yystack_[4].value.as < ASTNode* > (); delete yystack_[2].value.as < ASTNode* > (); delete yystack_[0].value.as < ASTNode* > ();}
#line 1481 "parser.tab.cc"
    break;

  case 29: // for_statement: "for" index_var_decl "in" iterable_expression "do" statement
#line 168 "parser.yy"
                                                               { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::ForStatement, {yystack_[4].value.as < ASTNode* > (), yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[5].value.as < ASTNode* > (); delete yystack_[3].value.as < ASTNode* > (); delete yystack_[1].value.as < ASTNode* > ();}
#line 1487 "parser.tab.cc"
    break;

  case 30: // for_statement: "for" index_var_decl "in" iterable_expression block_statement
#line 169 "parser.yy"
                                                                { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::ForStatement, {yystack_[3].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[4].value.as < ASTNode* > (); delete yystack_[2].value.as < ASTNode* > ();}
#line 1493 "parser.tab.cc"
    break;

  case 31: // for_statement: "for" iterable_expression "do" statement
#line 170 "parser.yy"
                                           { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::ForStatement, {yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[3].value.as < ASTNode* > (); delete yystack_[1].value.as < ASTNode* > ();}
#line 1499 "parser.tab.cc"
    break;

  case 32: // for_statement: "for" iterable_expression block_statement
#line 171 "parser.yy"
                                            { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::ForStatement, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[2].value.as < ASTNode* > ();}
#line 1505 "parser.tab.cc"
    break;

  case 33: // index_var_decl: IDENTIFIER
#line 174 "parser.yy"
  { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1511 "parser.tab.cc"
    break;

  case 34: // index_var_decl: tuple_grouped_identifier_list
#line 175 "parser.yy"
  { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1517 "parser.tab.cc"
    break;

  case 35: // tuple_grouped_identifier_list: "(" identifier_list ")"
#line 177 "parser.yy"
                                                       { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::TupleGroupedIdentifierList, {yystack_[1].value.as < ASTNode* > ()}); delete yystack_[2].value.as < ASTNode* > (); delete yystack_[0].value.as < ASTNode* > ();}
#line 1523 "parser.tab.cc"
    break;

  case 36: // identifier_list: IDENTIFIER
#line 180 "parser.yy"
             { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::IdentifierList, {yystack_[0].value.as < ASTNode* > ()});}
#line 1529 "parser.tab.cc"
    break;

  case 37: // identifier_list: IDENTIFIER "," identifier_list
#line 181 "parser.yy"
                                 { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::IdentifierList, {yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[1].value.as < ASTNode* > ();}
#line 1535 "parser.tab.cc"
    break;

  case 38: // identifier_list: tuple_grouped_identifier_list
#line 182 "parser.yy"
  { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1541 "parser.tab.cc"
    break;

  case 39: // identifier_list: tuple_grouped_identifier_list "," identifier_list
#line 183 "parser.yy"
                                                    { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::TupleGroupedIdentifierList, {yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[1].value.as < ASTNode* > ();}
#line 1547 "parser.tab.cc"
    break;

  case 40: // iterable_expression: expression
#line 186 "parser.yy"
  { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1553 "parser.tab.cc"
    break;

  case 41: // iterable_expression: "zip" "(" expression_list ")"
#line 187 "parser.yy"
                                { yylhs.value.as < ASTNode* > () = yystack_[1].value.as < ASTNode* > (); delete yystack_[3].value.as < ASTNode* > (); delete yystack_[2].value.as < ASTNode* > (); delete yystack_[0].value.as < ASTNode* > ();}
#line 1559 "parser.tab.cc"
    break;

  case 42: // expression_list: expression
#line 190 "parser.yy"
             { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::ExpressionList, {yystack_[0].value.as < ASTNode* > ()});}
#line 1565 "parser.tab.cc"
    break;

  case 43: // expression_list: expression "," expression_list
#line 191 "parser.yy"
                                 { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::ExpressionList, {yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[1].value.as < ASTNode* > ();}
#line 1571 "parser.tab.cc"
    break;

  case 44: // expression: literal_expression
#line 193 "parser.yy"
            { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1577 "parser.tab.cc"
    break;

  case 45: // expression: lvalue_expression
#line 193 "parser.yy"
                                 { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1583 "parser.tab.cc"
    break;

  case 46: // expression: unary_expression
#line 193 "parser.yy"
                                                     { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1589 "parser.tab.cc"
    break;

  case 47: // expression: binary_expression
#line 193 "parser.yy"
                                                                        { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1595 "parser.tab.cc"
    break;

  case 48: // literal_expression: INTEGER_LITERAL
#line 195 "parser.yy"
                    { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1601 "parser.tab.cc"
    break;

  case 49: // literal_expression: range_literal
#line 195 "parser.yy"
                                      { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1607 "parser.tab.cc"
    break;

  case 50: // range_literal: expression ".." expression
#line 198 "parser.yy"
                             { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::RangeLiteral, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1613 "parser.tab.cc"
    break;

  case 51: // range_literal: expression "..<" expression
#line 199 "parser.yy"
                              { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::RangeLiteral, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1619 "parser.tab.cc"
    break;

  case 52: // range_literal: expression ".."
#line 200 "parser.yy"
                  { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::RangeLiteral, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1625 "parser.tab.cc"
    break;

  case 53: // range_literal: ".." expression
#line 201 "parser.yy"
                  { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::RangeLiteral, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1631 "parser.tab.cc"
    break;

  case 54: // range_literal: "..<" expression
#line 202 "parser.yy"
                   { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::RangeLiteral, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1637 "parser.tab.cc"
    break;

  case 55: // range_literal: ".."
#line 203 "parser.yy"
       { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::RangeLiteral, {yystack_[0].value.as < ASTNode* > ()});}
#line 1643 "parser.tab.cc"
    break;

  case 56: // variable_expression: IDENTIFIER
#line 205 "parser.yy"
                     { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1649 "parser.tab.cc"
    break;

  case 57: // parenthesized_expression: "(" expression ")"
#line 207 "parser.yy"
                                                                { yylhs.value.as < ASTNode* > () = yystack_[1].value.as < ASTNode* > (); delete yystack_[2].value.as < ASTNode* > (); delete yystack_[0].value.as < ASTNode* > ();}
#line 1655 "parser.tab.cc"
    break;

  case 58: // lvalue_expression: variable_expression
#line 209 "parser.yy"
                   { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1661 "parser.tab.cc"
    break;

  case 59: // lvalue_expression: parenthesized_expression
#line 209 "parser.yy"
                                         { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1667 "parser.tab.cc"
    break;

  case 60: // lvalue_expression: call_expression
#line 209 "parser.yy"
                                                                    { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1673 "parser.tab.cc"
    break;

  case 61: // unary_expression: "+" expression
#line 212 "parser.yy"
                                         { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::UnaryExpression, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1679 "parser.tab.cc"
    break;

  case 62: // unary_expression: "-" expression
#line 213 "parser.yy"
                           { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::UnaryExpression, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1685 "parser.tab.cc"
    break;

  case 63: // unary_expression: "~" expression
#line 214 "parser.yy"
                 { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::UnaryExpression, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1691 "parser.tab.cc"
    break;

  case 64: // unary_expression: "!" expression
#line 215 "parser.yy"
                 { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::UnaryExpression, {yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1697 "parser.tab.cc"
    break;

  case 65: // binary_expression: expression "+" expression
#line 218 "parser.yy"
                            { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1703 "parser.tab.cc"
    break;

  case 66: // binary_expression: expression "-" expression
#line 219 "parser.yy"
                            { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1709 "parser.tab.cc"
    break;

  case 67: // binary_expression: expression "*" expression
#line 220 "parser.yy"
                            { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1715 "parser.tab.cc"
    break;

  case 68: // binary_expression: expression "/" expression
#line 221 "parser.yy"
                            { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1721 "parser.tab.cc"
    break;

  case 69: // binary_expression: expression "%" expression
#line 222 "parser.yy"
                            { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1727 "parser.tab.cc"
    break;

  case 70: // binary_expression: expression "**" expression
#line 223 "parser.yy"
                             { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1733 "parser.tab.cc"
    break;

  case 71: // binary_expression: expression "&" expression
#line 224 "parser.yy"
                            { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1739 "parser.tab.cc"
    break;

  case 72: // binary_expression: expression "|" expression
#line 225 "parser.yy"
                            { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1745 "parser.tab.cc"
    break;

  case 73: // binary_expression: expression "^" expression
#line 226 "parser.yy"
                            { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1751 "parser.tab.cc"
    break;

  case 74: // binary_expression: expression BITWISE_SHIFT expression
#line 227 "parser.yy"
                                      { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1757 "parser.tab.cc"
    break;

  case 75: // binary_expression: expression "&&" expression
#line 228 "parser.yy"
                             { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1763 "parser.tab.cc"
    break;

  case 76: // binary_expression: expression "||" expression
#line 229 "parser.yy"
                             { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1769 "parser.tab.cc"
    break;

  case 77: // binary_expression: expression EQUALITY_COMP expression
#line 230 "parser.yy"
                                      { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1775 "parser.tab.cc"
    break;

  case 78: // binary_expression: expression ORDERED_COMP expression
#line 231 "parser.yy"
                                     { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1781 "parser.tab.cc"
    break;

  case 79: // binary_expression: expression "by" expression
#line 232 "parser.yy"
                             { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1787 "parser.tab.cc"
    break;

  case 80: // binary_expression: expression "#" expression
#line 233 "parser.yy"
                            { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::BinaryExpression, {yystack_[2].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()});}
#line 1793 "parser.tab.cc"
    break;

  case 81: // call_expression: lvalue_expression "(" named_expression_list ")"
#line 236 "parser.yy"
                                                  { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::CallExpression, {yystack_[3].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > ()}); delete yystack_[2].value.as < ASTNode* > (); delete yystack_[0].value.as < ASTNode* > ();}
#line 1799 "parser.tab.cc"
    break;

  case 82: // call_expression: lvalue_expression "[" named_expression_list "]"
#line 237 "parser.yy"
                                                  { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::CallExpression, {yystack_[3].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > ()}); delete yystack_[2].value.as < ASTNode* > (); delete yystack_[0].value.as < ASTNode* > ();}
#line 1805 "parser.tab.cc"
    break;

  case 83: // named_expression_list: named_expression
#line 240 "parser.yy"
                   { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::NamedExpressionList, {yystack_[0].value.as < ASTNode* > ()});}
#line 1811 "parser.tab.cc"
    break;

  case 84: // named_expression_list: named_expression "," named_expression_list
#line 241 "parser.yy"
                                             { yylhs.value.as < ASTNode* > () = new ASTNode(ASTNodeType::NamedExpressionList, {yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ()}); delete yystack_[1].value.as < ASTNode* > ();}
#line 1817 "parser.tab.cc"
    break;

  case 85: // named_expression: expression
#line 244 "parser.yy"
  { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 1823 "parser.tab.cc"
    break;

  case 86: // named_expression: IDENTIFIER "=" expression
#line 245 "parser.yy"
  { yylhs.value.as < ASTNode* > () = yystack_[2].value.as < ASTNode* > (); }
#line 1829 "parser.tab.cc"
    break;


#line 1833 "parser.tab.cc"

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
  ")", "{", "}", "[", "]", "..", "..<", "if", "then", "else", "var",
  "const", "while", "do", "for", "in", "zip", "IDENTIFIER",
  "INTEGER_LITERAL", "NEG", "POSITIVE_IDENTITY", "HIGHEST_PREC", "$accept",
  "unit", "statements_opt", "statement", "block_statement",
  "expression_statement", "assignment_statement", "conditional_statement",
  "else_part_opt", "ctrl_decl", "while_do_statement", "do_while_statement",
  "for_statement", "index_var_decl", "tuple_grouped_identifier_list",
  "identifier_list", "iterable_expression", "expression_list",
  "expression", "literal_expression", "range_literal",
  "variable_expression", "parenthesized_expression", "lvalue_expression",
  "unary_expression", "binary_expression", "call_expression",
  "named_expression_list", "named_expression", YY_NULLPTR
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


  const short parser::yypact_ninf_ = -133;

  const signed char parser::yytable_ninf_ = -37;

  const short
  parser::yypact_[] =
  {
    -133,    14,    -9,  -133,   153,  -133,    19,    19,    -9,   149,
    -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,    -6,
    -133,    90,  -133,   153,   153,   153,   153,    57,   153,  -133,
     322,  -133,  -133,  -133,    23,  -133,  -133,   574,     6,    10,
      20,   290,   -14,   260,    21,   198,    12,    16,    17,  -133,
     -12,   472,  -133,   153,   153,   218,   218,    62,    62,    56,
      56,   518,   518,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,  -133,
      57,   153,  -133,    44,    58,    -9,    38,    -9,    38,    -9,
    -133,    -9,  -133,   153,    52,    78,    54,   153,   173,    -9,
    -133,   352,   382,    60,   472,    80,    84,    74,   246,   246,
      56,    56,    56,    56,   231,   276,    33,    62,   548,   532,
     579,   564,   502,   502,   518,   518,   153,   153,    38,    -9,
    -133,    38,  -133,  -133,  -133,   412,   -22,   -22,  -133,    88,
     442,    -7,  -133,  -133,  -133,   153,  -133,   218,  -133,   472,
     472,  -133,  -133,  -133,  -133,   -22,    92,  -133,  -133,  -133,
     153,    -9,  -133,   472,  -133,  -133,  -133
  };

  const signed char
  parser::yydefact_[] =
  {
       3,     0,     2,     1,     0,     3,     0,     0,     0,     0,
      56,     4,     5,     6,     7,     8,     9,    10,    11,    58,
      59,     0,    60,     0,     0,     0,     0,    55,     0,    48,
       0,    44,    49,    58,    45,    46,    47,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    56,     0,    34,
       0,    40,    13,     0,     0,     0,     0,    61,    62,    63,
      64,    53,    54,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
      52,     0,    12,     0,     0,     0,    20,     0,    20,     0,
      27,     0,    25,     0,    56,    38,     0,     0,     0,     0,
      32,     0,     0,    56,    85,     0,    83,     0,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      78,    77,    79,    80,    50,    51,     0,     0,    20,     0,
      19,    20,    17,    26,    24,     0,     0,     0,    35,     0,
      42,     0,    31,    14,    15,     0,    81,     0,    82,    22,
      23,    18,    21,    16,    28,     0,    36,    37,    39,    41,
       0,     0,    30,    86,    84,    43,    29
  };

  const short
  parser::yypgoto_[] =
  {
    -133,  -133,   113,    18,   -31,  -133,  -133,  -133,   -86,   116,
    -133,  -133,  -133,  -133,   111,  -132,    26,   -35,    68,  -133,
    -133,    -2,  -133,    -1,  -133,  -133,  -133,   -48,  -133
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     1,     2,    11,    12,    13,    14,    15,   130,    40,
      16,    17,    18,    48,    95,    96,    50,   139,   104,    31,
      32,    33,    20,    34,    35,    36,    22,   105,   106
  };

  const short
  parser::yytable_[] =
  {
      19,    21,   132,   155,   157,   158,    19,    21,   107,    86,
      88,    90,    92,     5,     3,     5,     4,    52,     5,   100,
       5,   156,    23,    24,     6,    89,    44,    99,    25,     7,
       8,     9,   161,    26,    10,    19,    21,    97,    65,    66,
      67,    68,   151,    69,     4,   153,    72,     5,    55,    83,
      27,    28,    56,    84,    85,    38,    39,   -33,    98,    93,
      23,    24,    10,    29,    68,   126,    25,    65,    66,    67,
      68,    26,    30,   129,    41,    43,   136,    51,   -36,   127,
     138,   145,     4,    19,    21,    19,    21,    19,    21,    19,
      21,    57,    58,    59,    60,    61,    62,    19,    21,   164,
      10,    29,   137,   128,   148,   131,   146,   133,   147,   134,
     162,    53,    54,    30,   159,    55,   136,   142,    37,    56,
      49,   101,   102,    42,   141,   165,     0,    19,    21,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   152,   124,   125,
       0,     0,    23,    24,     0,     0,    23,    24,    25,    19,
      21,   135,    25,    26,     0,   140,    51,    26,     0,     0,
       0,     0,     0,     0,    45,     0,    23,    24,     4,   166,
      27,    28,    25,     0,    27,    28,     0,    26,     0,     0,
       0,    46,    47,    29,   149,   150,    10,    29,     4,     0,
       0,    23,    24,     0,    27,    28,     0,    25,     0,     0,
       0,     0,    26,   163,     0,    46,    10,    29,     0,     0,
       0,    23,    24,    45,     0,     0,     0,    25,   140,    27,
      28,     0,    26,     0,     0,     0,    65,    66,    67,    68,
       0,    94,    29,     4,    72,     0,     0,     0,     0,    27,
      28,    65,    66,    67,    68,     0,    69,    70,    71,    72,
       0,   103,    29,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,     0,    73,    74,    75,    76,    77,
      78,    65,    66,    67,    68,     0,    69,     5,    71,    72,
       0,    80,    81,    63,    64,    65,    66,    67,    68,    91,
      69,    70,    71,    72,     0,    73,    74,    75,    76,    77,
      78,     0,     0,     0,     0,     0,     0,     5,     0,     0,
       0,    80,    81,     0,    87,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,     0,    73,    74,    75,
      76,    77,    78,     0,     0,     0,     0,     0,    79,     0,
       0,     0,     0,    80,    81,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,     0,    73,    74,    75,
      76,    77,    78,     0,     0,   143,     0,     0,     0,     0,
       0,     0,     0,    80,    81,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,     0,    73,    74,    75,
      76,    77,    78,     0,     0,   144,     0,     0,     0,     0,
       0,     0,     0,    80,    81,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,     0,    73,    74,    75,
      76,    77,    78,     0,     0,   154,     0,     0,     0,     0,
       0,     0,     0,    80,    81,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,     0,    73,    74,    75,
      76,    77,    78,     0,     0,     0,   160,     0,     0,     0,
       0,     0,     0,    80,    81,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,     0,    73,    74,    75,
      76,    77,    78,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80,    81,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,     0,    73,    74,    75,
      76,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,     0,    80,    81,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,     0,    73,     0,    75,
      76,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,     0,    80,    81,    75,    76,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,    72,     0,    80,
      81,    75,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,     0,     0,    80,    81,     0,     0,     4,
       0,     5,    82,     0,     0,     0,     0,     6,     0,     0,
      80,    81,     7,     8,     9,     0,     0,    10
  };

  const short
  parser::yycheck_[] =
  {
       2,     2,    88,    25,   136,   137,     8,     8,    56,    40,
      41,    42,    43,    27,     0,    27,    25,    23,    27,    50,
      27,    43,     3,     4,    33,    39,     8,    39,     9,    38,
      39,    40,    39,    14,    43,    37,    37,    25,     5,     6,
       7,     8,   128,    10,    25,   131,    13,    27,    25,    43,
      31,    32,    29,    43,    34,    36,    37,    41,    41,    38,
       3,     4,    43,    44,     8,    21,     9,     5,     6,     7,
       8,    14,     4,    35,     6,     7,    24,     9,    26,    21,
      26,    21,    25,    85,    85,    87,    87,    89,    89,    91,
      91,    23,    24,    25,    26,    27,    28,    99,    99,   147,
      43,    44,    24,    85,    30,    87,    26,    89,    24,    91,
     141,    21,    22,    45,    26,    25,    24,    99,     5,    29,
       9,    53,    54,     7,    98,   160,    -1,   129,   129,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,   129,    80,    81,
      -1,    -1,     3,     4,    -1,    -1,     3,     4,     9,   161,
     161,    93,     9,    14,    -1,    97,    98,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    -1,     3,     4,    25,   161,
      31,    32,     9,    -1,    31,    32,    -1,    14,    -1,    -1,
      -1,    42,    43,    44,   126,   127,    43,    44,    25,    -1,
      -1,     3,     4,    -1,    31,    32,    -1,     9,    -1,    -1,
      -1,    -1,    14,   145,    -1,    42,    43,    44,    -1,    -1,
      -1,     3,     4,    25,    -1,    -1,    -1,     9,   160,    31,
      32,    -1,    14,    -1,    -1,    -1,     5,     6,     7,     8,
      -1,    43,    44,    25,    13,    -1,    -1,    -1,    -1,    31,
      32,     5,     6,     7,     8,    -1,    10,    11,    12,    13,
      -1,    43,    44,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    12,    13,    -1,    15,    16,    17,    18,    19,
      20,     5,     6,     7,     8,    -1,    10,    27,    12,    13,
      -1,    31,    32,     3,     4,     5,     6,     7,     8,    39,
      10,    11,    12,    13,    -1,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    31,    32,    -1,    34,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,    -1,
      -1,    -1,    -1,    31,    32,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    19,    20,    -1,    -1,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    19,    20,    -1,    -1,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    19,    20,    -1,    -1,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      12,    13,    -1,    31,    32,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    12,    13,    -1,    15,    -1,    17,
      18,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      12,    13,    -1,    31,    32,    17,    18,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    12,    13,    -1,    31,
      32,    17,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    12,    13,    -1,    -1,    31,    32,    -1,    -1,    25,
      -1,    27,    28,    -1,    -1,    -1,    -1,    33,    -1,    -1,
      31,    32,    38,    39,    40,    -1,    -1,    43
  };

  const signed char
  parser::yystos_[] =
  {
       0,    49,    50,     0,    25,    27,    33,    38,    39,    40,
      43,    51,    52,    53,    54,    55,    58,    59,    60,    69,
      70,    71,    74,     3,     4,     9,    14,    31,    32,    44,
      66,    67,    68,    69,    71,    72,    73,    50,    36,    37,
      57,    66,    57,    66,    51,    25,    42,    43,    61,    62,
      64,    66,    23,    21,    22,    25,    29,    66,    66,    66,
      66,    66,    66,     3,     4,     5,     6,     7,     8,    10,
      11,    12,    13,    15,    16,    17,    18,    19,    20,    26,
      31,    32,    28,    43,    43,    34,    52,    34,    52,    39,
      52,    39,    52,    38,    43,    62,    63,    25,    41,    39,
      52,    66,    66,    43,    66,    75,    76,    75,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    21,    21,    51,    35,
      56,    51,    56,    51,    51,    66,    24,    24,    26,    65,
      66,    64,    51,    23,    23,    21,    26,    24,    30,    66,
      66,    56,    51,    56,    23,    25,    43,    63,    63,    26,
      24,    39,    52,    66,    75,    65,    51
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    48,    49,    50,    50,    51,    51,    51,    51,    51,
      51,    51,    52,    53,    54,    54,    55,    55,    55,    55,
      56,    56,    57,    57,    58,    58,    58,    58,    59,    60,
      60,    60,    60,    61,    61,    62,    63,    63,    63,    63,
      64,    64,    65,    65,    66,    66,    66,    66,    67,    67,
      68,    68,    68,    68,    68,    68,    69,    70,    71,    71,
      71,    72,    72,    72,    72,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    74,    74,    75,    75,    76,    76
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     4,     4,     5,     4,     5,     4,
       0,     2,     4,     4,     4,     3,     4,     3,     5,     6,
       5,     4,     3,     1,     1,     3,     1,     3,     1,     3,
       1,     4,     1,     3,     1,     1,     1,     1,     1,     1,
       3,     3,     2,     2,     2,     1,     1,     3,     1,     1,
       1,     2,     2,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     4,     4,     1,     3,     1,     3
  };




#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,   128,   128,   131,   132,   134,   134,   134,   134,   134,
     135,   135,   137,   139,   142,   143,   146,   147,   148,   149,
     152,   153,   156,   157,   160,   161,   162,   163,   165,   168,
     169,   170,   171,   174,   175,   177,   180,   181,   182,   183,
     186,   187,   190,   191,   193,   193,   193,   193,   195,   195,
     198,   199,   200,   201,   202,   203,   205,   207,   209,   209,
     209,   212,   213,   214,   215,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   236,   237,   240,   241,   244,   245
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
#line 2595 "parser.tab.cc"

#line 246 "parser.yy"


void yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
