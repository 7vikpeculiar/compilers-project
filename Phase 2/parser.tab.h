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
    NOT = 268,
    SCOMMA = 269,
    COMMA = 270,
    OF = 271,
    CF = 272,
    OC = 273,
    CC = 274,
    OS = 275,
    CS = 276,
    QUEST = 277,
    COLON = 278,
    ADD = 279,
    DIV = 280,
    EQ = 281,
    GEQ = 282,
    GT = 283,
    LEQ = 284,
    LT = 285,
    MULT = 286,
    NEQ = 287,
    SUB = 288,
    AND = 289,
    OR = 290,
    MOD = 291,
    INTL = 292,
    UINTL = 293,
    CHAR = 294,
    TRUE = 295,
    FALSE = 296,
    ID = 297,
    VOID = 298,
    TINT = 299,
    TUINT = 300,
    TCHAR = 301,
    TBOOL = 302,
    STOP = 303,
    ASGN = 304,
    PASGN = 305,
    SASGN = 306,
    STATEMENT = 307,
    LOCID = 308,
    EXPRESSIONVSEXPRESSION = 309,
    EXPRESSIONVSLOCASGNEXP = 310,
    UMINUS = 311
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 45 "parser.y" /* yacc.c:1909  */

char* value;
class ASTnode *node;

#line 116 "parser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
