
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
     NOT = 260,
     AND = 261,
     OR = 262,
     STRING_LITERAL = 263,
     PLUS = 264,
     MINUS = 265,
     STAR = 266,
     DIV = 267,
     IN = 268,
     INOUT = 269,
     INPUT = 270,
     PRINT = 271,
     SEMICOLON = 272,
     COMMA = 273,
     COLON = 274,
     PROGRAM = 275,
     DECLARE = 276,
     DEFAULT = 277,
     FUNCTION = 278,
     PROCEDURE = 279,
     L_THAN = 280,
     G_THAN = 281,
     EQUAL = 282,
     L_EQ_THAN = 283,
     G_EQ_THAN = 284,
     NEQUAL = 285,
     LPAREN = 286,
     RPAREN = 287,
     LSQUARE_BRACK = 288,
     RSQUARE_BRACK = 289,
     LBRACK = 290,
     RBRACK = 291,
     ELSE = 292,
     IF = 293,
     RETURN = 294,
     WHILE = 295,
     DOUBLEWHILE = 296,
     LOOP = 297,
     FORCASE = 298,
     INCASE = 299,
     WHEN = 300,
     EXIT = 301,
     DEC_CONST = 302,
     IDENTIFIER = 303
   };
#endif
/* Tokens.  */
#define CALL 258
#define ASSIGN 259
#define NOT 260
#define AND 261
#define OR 262
#define STRING_LITERAL 263
#define PLUS 264
#define MINUS 265
#define STAR 266
#define DIV 267
#define IN 268
#define INOUT 269
#define INPUT 270
#define PRINT 271
#define SEMICOLON 272
#define COMMA 273
#define COLON 274
#define PROGRAM 275
#define DECLARE 276
#define DEFAULT 277
#define FUNCTION 278
#define PROCEDURE 279
#define L_THAN 280
#define G_THAN 281
#define EQUAL 282
#define L_EQ_THAN 283
#define G_EQ_THAN 284
#define NEQUAL 285
#define LPAREN 286
#define RPAREN 287
#define LSQUARE_BRACK 288
#define RSQUARE_BRACK 289
#define LBRACK 290
#define RBRACK 291
#define ELSE 292
#define IF 293
#define RETURN 294
#define WHILE 295
#define DOUBLEWHILE 296
#define LOOP 297
#define FORCASE 298
#define INCASE 299
#define WHEN 300
#define EXIT 301
#define DEC_CONST 302
#define IDENTIFIER 303




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 105 "gram.y"

	char *name;
	char *cVal;
	int iVal;
	struct treeNode *tVal;
	express expr;
    funcdef funcentr;
	int op;



/* Line 1676 of yacc.c  */
#line 160 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


