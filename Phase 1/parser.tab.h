/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ARRAY = 258,
    RETURN = 259,
    BREAK = 260,
    IMPORT = 261,
    IF = 262,
    ELIF = 263,
    ELSE = 264,
    FOR = 265,
    WHILE = 266,
    DEF = 267,
    ARITOP = 268,
    BOOLOP = 269,
    NOT = 270,
    RELOP = 271,
    SCOMMA = 272,
    COMMA = 273,
    BOOL = 274,
    VOID = 275,
    OF = 276,
    CF = 277,
    OC = 278,
    CC = 279,
    OS = 280,
    CS = 281,
    ID = 282,
    CHAR = 283,
    INTL = 284,
    NL = 285,
    QUEST = 286,
    COLON = 287,
    ADD = 288,
    DIV = 289,
    EQ = 290,
    GEQ = 291,
    GT = 292,
    LEQ = 293,
    LT = 294,
    MULT = 295,
    NEQ = 296,
    SUB = 297,
    AND = 298,
    OR = 299,
    TRUE = 300,
    FALSE = 301,
    TINT = 302,
    TUINT = 303,
    TCHAR = 304,
    TBOOL = 305,
    STOP = 306,
    ASGN = 307,
    PASGN = 308,
    SASGN = 309,
    UMINUS = 310
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
