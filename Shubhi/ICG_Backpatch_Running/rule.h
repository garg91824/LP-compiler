/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

#ifndef YY_YY_RULE_H_INCLUDED
# define YY_YY_RULE_H_INCLUDED
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
    IF = 258,
    ELSE = 259,
    WHILE = 260,
    SWITCH = 261,
    CASE = 262,
    DEFAULT = 263,
    INT = 264,
    FLOAT = 265,
    BOOL = 266,
    ASSIGN = 267,
    PLUSEQ = 268,
    MINUSEQ = 269,
    TIMESEQ = 270,
    DIVIDEQ = 271,
    PLUS = 272,
    MINUS = 273,
    TIMES = 274,
    DIVIDE = 275,
    EXP = 276,
    IOR = 277,
    IAND = 278,
    INOT = 279,
    XOR = 280,
    OR = 281,
    AND = 282,
    NOT = 283,
    EQ = 284,
    NEQ = 285,
    LT = 286,
    LEQ = 287,
    GT = 288,
    GEQ = 289,
    LP = 290,
    RP = 291,
    LB = 292,
    RB = 293,
    SEMICOLON = 294,
    COLON = 295,
    DOUBLENUM = 296,
    INTNUM = 297,
    TRUE = 298,
    FALSE = 299,
    ID = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 29 "yaccrule.y" /* yacc.c:1909  */

  struct BackpatchList{
    int ins;
    BackpatchList *next;
  };

  struct marks{
    int instr;
  }mark;
  struct info{
    char *addr;
    BackpatchList *tlist;
    BackpatchList *flist;
  }exp;
  struct next{
      int instr;
      BackpatchList *nextList;
  }List;
  char *str;

#line 121 "rule.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_RULE_H_INCLUDED  */
