/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_HEADER_TOKENS_H_INCLUDED
# define YY_YY_HEADER_TOKENS_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 50 "src/syn.y"

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <assert.h>

	#include "lex.h"
	#include "syn.h"
	#include "sem.h"
	#include "master.h"
	#include "codegen.h"

#line 62 "header/tokens.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    WHITESPACE = 258,              /* WHITESPACE  */
    LINE_COMMENT = 259,            /* LINE_COMMENT  */
    MULTILINE_COMMENT = 260,       /* MULTILINE_COMMENT  */
    VOID = 261,                    /* VOID  */
    VAR = 262,                     /* VAR  */
    CONST = 263,                   /* CONST  */
    IF = 264,                      /* IF  */
    ELSE = 265,                    /* ELSE  */
    WHILE = 266,                   /* WHILE  */
    PRINT = 267,                   /* PRINT  */
    READ = 268,                    /* READ  */
    DO = 269,                      /* DO  */
    FOR = 270,                     /* FOR  */
    SEMICOLON = 271,               /* SEMICOLON  */
    COMMA = 272,                   /* COMMA  */
    ASSIGN = 273,                  /* ASSIGN  */
    LPARENTHESIS = 274,            /* LPARENTHESIS  */
    RPARENTHESIS = 275,            /* RPARENTHESIS  */
    LBRACE = 276,                  /* LBRACE  */
    RBRACE = 277,                  /* RBRACE  */
    BAD_NUM = 278,                 /* BAD_NUM  */
    BAD_ID = 279,                  /* BAD_ID  */
    BAD_STRING = 280,              /* BAD_STRING  */
    PARTIAL_STRING = 281,          /* PARTIAL_STRING  */
    PARTIAL_COMMENT = 282,         /* PARTIAL_COMMENT  */
    UNRECOGNIZED = 283,            /* UNRECOGNIZED  */
    NUM = 284,                     /* NUM  */
    STRING = 285,                  /* STRING  */
    ID = 286,                      /* ID  */
    LTE = 287,                     /* LTE  */
    GTE = 288,                     /* GTE  */
    LT = 289,                      /* LT  */
    GT = 290,                      /* GT  */
    EQ = 291,                      /* EQ  */
    NEQ = 292,                     /* NEQ  */
    PLUS = 293,                    /* PLUS  */
    MINUS = 294,                   /* MINUS  */
    MULT = 295,                    /* MULT  */
    DIVIDE = 296,                  /* DIVIDE  */
    UMINUS = 297,                  /* UMINUS  */
    LOGICAL_NEG = 298              /* LOGICAL_NEG  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 64 "src/syn.y"

	char *lexema;
	ListaC codigo;

#line 127 "header/tokens.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_HEADER_TOKENS_H_INCLUDED  */
