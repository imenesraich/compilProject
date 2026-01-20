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

#ifndef YY_YY_BUILD_Y_TAB_H_INCLUDED
# define YY_YY_BUILD_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOKEN_IDENTIFIER = 258,        /* TOKEN_IDENTIFIER  */
    TOKEN_STRING = 259,            /* TOKEN_STRING  */
    TOKEN_HEX = 260,               /* TOKEN_HEX  */
    TOKEN_INTEGER = 261,           /* TOKEN_INTEGER  */
    TOKEN_PROTOCOL = 262,          /* TOKEN_PROTOCOL  */
    TOKEN_ENDPROTOCOL = 263,       /* TOKEN_ENDPROTOCOL  */
    TOKEN_IMPORT = 264,            /* TOKEN_IMPORT  */
    TOKEN_KEYSPACE = 265,          /* TOKEN_KEYSPACE  */
    TOKEN_MAIN = 266,              /* TOKEN_MAIN  */
    TOKEN_LOOP = 267,              /* TOKEN_LOOP  */
    TOKEN_FOR = 268,               /* TOKEN_FOR  */
    TOKEN_ROTATE = 269,            /* TOKEN_ROTATE  */
    TOKEN_ROUNDS = 270,            /* TOKEN_ROUNDS  */
    TOKEN_STEP = 271,              /* TOKEN_STEP  */
    TOKEN_PACKET = 272,            /* TOKEN_PACKET  */
    TOKEN_BIT = 273,               /* TOKEN_BIT  */
    TOKEN_NIBBLE = 274,            /* TOKEN_NIBBLE  */
    TOKEN_BYTE = 275,              /* TOKEN_BYTE  */
    TOKEN_WORD = 276,              /* TOKEN_WORD  */
    TOKEN_DWORD = 277,             /* TOKEN_DWORD  */
    TOKEN_QWORD = 278,             /* TOKEN_QWORD  */
    TOKEN_PLAIN = 279,             /* TOKEN_PLAIN  */
    TOKEN_CIPHER = 280,            /* TOKEN_CIPHER  */
    TOKEN_HASH = 281,              /* TOKEN_HASH  */
    TOKEN_KEY128 = 282,            /* TOKEN_KEY128  */
    TOKEN_KEY256 = 283,            /* TOKEN_KEY256  */
    TOKEN_KEY512 = 284,            /* TOKEN_KEY512  */
    TOKEN_SECURE_ASSIGN = 285,     /* TOKEN_SECURE_ASSIGN  */
    TOKEN_DECLARE = 286,           /* TOKEN_DECLARE  */
    TOKEN_ASSIGN_LOOP = 287,       /* TOKEN_ASSIGN_LOOP  */
    TOKEN_IF = 288,                /* TOKEN_IF  */
    TOKEN_ELIF = 289,              /* TOKEN_ELIF  */
    TOKEN_OUTPUT = 290,            /* TOKEN_OUTPUT  */
    TOKEN_INPUT = 291,             /* TOKEN_INPUT  */
    TOKEN_PLUS = 292,              /* TOKEN_PLUS  */
    TOKEN_MINUS = 293,             /* TOKEN_MINUS  */
    TOKEN_MULT = 294,              /* TOKEN_MULT  */
    TOKEN_DIV = 295,               /* TOKEN_DIV  */
    TOKEN_MOD = 296,               /* TOKEN_MOD  */
    TOKEN_ASSIGN = 297,            /* TOKEN_ASSIGN  */
    TOKEN_EQ = 298,                /* TOKEN_EQ  */
    TOKEN_NEQ = 299,               /* TOKEN_NEQ  */
    TOKEN_LT = 300,                /* TOKEN_LT  */
    TOKEN_GT = 301,                /* TOKEN_GT  */
    TOKEN_LEQ = 302,               /* TOKEN_LEQ  */
    TOKEN_GEQ = 303,               /* TOKEN_GEQ  */
    TOKEN_AND = 304,               /* TOKEN_AND  */
    TOKEN_OR = 305,                /* TOKEN_OR  */
    TOKEN_XOR_LOGIC = 306,         /* TOKEN_XOR_LOGIC  */
    TOKEN_NOT = 307,               /* TOKEN_NOT  */
    TOKEN_POWER = 308,             /* TOKEN_POWER  */
    TOKEN_BIT_AND = 309,           /* TOKEN_BIT_AND  */
    TOKEN_BIT_OR = 310,            /* TOKEN_BIT_OR  */
    TOKEN_BIT_XOR = 311,           /* TOKEN_BIT_XOR  */
    TOKEN_BIT_NOT = 312,           /* TOKEN_BIT_NOT  */
    TOKEN_ROTATE_LEFT = 313,       /* TOKEN_ROTATE_LEFT  */
    TOKEN_ROTATE_RIGHT = 314,      /* TOKEN_ROTATE_RIGHT  */
    TOKEN_SHIFT_LEFT = 315,        /* TOKEN_SHIFT_LEFT  */
    TOKEN_SHIFT_RIGHT = 316,       /* TOKEN_SHIFT_RIGHT  */
    TOKEN_ENCRYPT = 317,           /* TOKEN_ENCRYPT  */
    TOKEN_DECRYPT = 318,           /* TOKEN_DECRYPT  */
    TOKEN_HASH_CALC = 319,         /* TOKEN_HASH_CALC  */
    TOKEN_HASH_VERIFY = 320,       /* TOKEN_HASH_VERIFY  */
    TOKEN_SIGN = 321,              /* TOKEN_SIGN  */
    TOKEN_VERIFY_SIGN = 322,       /* TOKEN_VERIFY_SIGN  */
    TOKEN_LBRACE = 323,            /* TOKEN_LBRACE  */
    TOKEN_RBRACE = 324,            /* TOKEN_RBRACE  */
    TOKEN_LBRACKET = 325,          /* TOKEN_LBRACKET  */
    TOKEN_RBRACKET = 326,          /* TOKEN_RBRACKET  */
    TOKEN_LPAREN = 327,            /* TOKEN_LPAREN  */
    TOKEN_RPAREN = 328,            /* TOKEN_RPAREN  */
    TOKEN_SEMICOLON = 329,         /* TOKEN_SEMICOLON  */
    TOKEN_COMMA = 330,             /* TOKEN_COMMA  */
    TOKEN_DOT = 331,               /* TOKEN_DOT  */
    TOKEN_COLON = 332              /* TOKEN_COLON  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "src/lexer/cryptolang.y"

    int ival;
    char* sval;
    int type; /* On utilise int pour stocker les enum TypeCL */

#line 147 "build/y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_BUILD_Y_TAB_H_INCLUDED  */
