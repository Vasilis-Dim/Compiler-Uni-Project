
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CALL = 258,
     ASSIGN = 259,
     DEC_CONST = 260,
     IDENTIFIER = 261,
     NOT = 262,
     AND = 263,
     OR = 264,
     STRING_LITERAL = 265,
     PLUS = 266,
     MINUS = 267,
     STAR = 268,
     DIV = 269,
     IN = 270,
     INOUT = 271,
     INPUT = 272,
     PRINT = 273,
     SEMICOLON = 274,
     COMMA = 275,
     COLON = 276,
     PROGRAM = 277,
     DECLARE = 278,
     DEFAULT = 279,
     FUNCTION = 280,
     PROCEDURE = 281,
     L_THAN = 282,
     G_THAN = 283,
     EQUAL = 284,
     L_EQ_THAN = 285,
     G_EQ_THAN = 286,
     NEQUAL = 287,
     LPAREN = 288,
     RPAREN = 289,
     LSQUARE_BRACK = 290,
     RSQUARE_BRACK = 291,
     LBRACK = 292,
     RBRACK = 293,
     ELSE = 294,
     IF = 295,
     RETURN = 296,
     WHILE = 297,
     DOUBLEWHILE = 298,
     LOOP = 299,
     FORCASE = 300,
     INCASE = 301,
     WHEN = 302,
     EXIT = 303
   };
#endif
/* Tokens.  */
#define CALL 258
#define ASSIGN 259
#define DEC_CONST 260
#define IDENTIFIER 261
#define NOT 262
#define AND 263
#define OR 264
#define STRING_LITERAL 265
#define PLUS 266
#define MINUS 267
#define STAR 268
#define DIV 269
#define IN 270
#define INOUT 271
#define INPUT 272
#define PRINT 273
#define SEMICOLON 274
#define COMMA 275
#define COLON 276
#define PROGRAM 277
#define DECLARE 278
#define DEFAULT 279
#define FUNCTION 280
#define PROCEDURE 281
#define L_THAN 282
#define G_THAN 283
#define EQUAL 284
#define L_EQ_THAN 285
#define G_EQ_THAN 286
#define NEQUAL 287
#define LPAREN 288
#define RPAREN 289
#define LSQUARE_BRACK 290
#define RSQUARE_BRACK 291
#define LBRACK 292
#define RBRACK 293
#define ELSE 294
#define IF 295
#define RETURN 296
#define WHILE 297
#define DOUBLEWHILE 298
#define LOOP 299
#define FORCASE 300
#define INCASE 301
#define WHEN 302
#define EXIT 303




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 12 "grammar.y"

char *name;



/* Line 1676 of yacc.c  */
#line 154 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


