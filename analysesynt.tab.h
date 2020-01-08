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

#ifndef YY_YY_ANALYSESYNT_TAB_H_INCLUDED
# define YY_YY_ANALYSESYNT_TAB_H_INCLUDED
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
    TOK_AFFECTATION = 258,
    TOK_DIFFERENCE = 259,
    TOK_EGALITE = 260,
    TOK_INFERIEUR = 261,
    TOK_SUPERIEUR = 262,
    TOK_INFERIEUREGAL = 263,
    TOK_SUPERIEUREGAL = 264,
    TOK_PLUS = 265,
    TOK_MOINS = 266,
    TOK_FOIS = 267,
    TOK_DIVISION = 268,
    TOK_CONCAT = 269,
    TOK_POINT = 270,
    TOK_PARENTHESED = 271,
    TOK_PARENTHESEG = 272,
    TOK_CHAINECARAC = 273,
    TOK_NOMCLASSE = 274,
    TOK_NOM = 275,
    TOK_NOMBRE = 276,
    TOK_CLASS = 277,
    TOK_EXTENDS = 278,
    TOK_IS = 279,
    TOK_CROCHETG = 280,
    TOK_CROCHETD = 281,
    TOK_DEF = 282,
    TOK_DEUXPOINTS = 283,
    TOK_VIRGULE = 284,
    TOK_VAR = 285,
    TOK_POINTVIRGULE = 286,
    TOK_STATIC = 287,
    TOK_OVERRIDE = 288,
    TOK_THIS = 289,
    TOK_SUPER = 290,
    TOK_RESULT = 291,
    TOK_NEW = 292,
    TOK_RETURN = 293,
    TOK_IF = 294,
    TOK_THEN = 295,
    TOK_ELSE = 296,
    TOK_AS = 297
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 11 "analysesynt.y" /* yacc.c:1909  */

	long nombre;
	char* chainecarac;


#line 103 "analysesynt.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ANALYSESYNT_TAB_H_INCLUDED  */
