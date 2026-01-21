/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/lexer/cryptolang.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ts.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int line_number;
extern int error_count;

void yyerror(const char* s);

#line 86 "build/y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "y.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOKEN_IDENTIFIER = 3,           /* TOKEN_IDENTIFIER  */
  YYSYMBOL_TOKEN_STRING = 4,               /* TOKEN_STRING  */
  YYSYMBOL_TOKEN_HEX = 5,                  /* TOKEN_HEX  */
  YYSYMBOL_TOKEN_INTEGER = 6,              /* TOKEN_INTEGER  */
  YYSYMBOL_TOKEN_PROTOCOL = 7,             /* TOKEN_PROTOCOL  */
  YYSYMBOL_TOKEN_ENDPROTOCOL = 8,          /* TOKEN_ENDPROTOCOL  */
  YYSYMBOL_TOKEN_IMPORT = 9,               /* TOKEN_IMPORT  */
  YYSYMBOL_TOKEN_KEYSPACE = 10,            /* TOKEN_KEYSPACE  */
  YYSYMBOL_TOKEN_MAIN = 11,                /* TOKEN_MAIN  */
  YYSYMBOL_TOKEN_LOOP = 12,                /* TOKEN_LOOP  */
  YYSYMBOL_TOKEN_FOR = 13,                 /* TOKEN_FOR  */
  YYSYMBOL_TOKEN_ROTATE = 14,              /* TOKEN_ROTATE  */
  YYSYMBOL_TOKEN_ROUNDS = 15,              /* TOKEN_ROUNDS  */
  YYSYMBOL_TOKEN_STEP = 16,                /* TOKEN_STEP  */
  YYSYMBOL_TOKEN_PACKET = 17,              /* TOKEN_PACKET  */
  YYSYMBOL_TOKEN_BIT = 18,                 /* TOKEN_BIT  */
  YYSYMBOL_TOKEN_NIBBLE = 19,              /* TOKEN_NIBBLE  */
  YYSYMBOL_TOKEN_BYTE = 20,                /* TOKEN_BYTE  */
  YYSYMBOL_TOKEN_WORD = 21,                /* TOKEN_WORD  */
  YYSYMBOL_TOKEN_DWORD = 22,               /* TOKEN_DWORD  */
  YYSYMBOL_TOKEN_QWORD = 23,               /* TOKEN_QWORD  */
  YYSYMBOL_TOKEN_PLAIN = 24,               /* TOKEN_PLAIN  */
  YYSYMBOL_TOKEN_CIPHER = 25,              /* TOKEN_CIPHER  */
  YYSYMBOL_TOKEN_HASH = 26,                /* TOKEN_HASH  */
  YYSYMBOL_TOKEN_KEY128 = 27,              /* TOKEN_KEY128  */
  YYSYMBOL_TOKEN_KEY256 = 28,              /* TOKEN_KEY256  */
  YYSYMBOL_TOKEN_KEY512 = 29,              /* TOKEN_KEY512  */
  YYSYMBOL_TOKEN_SECURE_ASSIGN = 30,       /* TOKEN_SECURE_ASSIGN  */
  YYSYMBOL_TOKEN_DECLARE = 31,             /* TOKEN_DECLARE  */
  YYSYMBOL_TOKEN_ASSIGN_LOOP = 32,         /* TOKEN_ASSIGN_LOOP  */
  YYSYMBOL_TOKEN_IF = 33,                  /* TOKEN_IF  */
  YYSYMBOL_TOKEN_ELIF = 34,                /* TOKEN_ELIF  */
  YYSYMBOL_TOKEN_OUTPUT = 35,              /* TOKEN_OUTPUT  */
  YYSYMBOL_TOKEN_INPUT = 36,               /* TOKEN_INPUT  */
  YYSYMBOL_TOKEN_PLUS = 37,                /* TOKEN_PLUS  */
  YYSYMBOL_TOKEN_MINUS = 38,               /* TOKEN_MINUS  */
  YYSYMBOL_TOKEN_MULT = 39,                /* TOKEN_MULT  */
  YYSYMBOL_TOKEN_DIV = 40,                 /* TOKEN_DIV  */
  YYSYMBOL_TOKEN_MOD = 41,                 /* TOKEN_MOD  */
  YYSYMBOL_TOKEN_ASSIGN = 42,              /* TOKEN_ASSIGN  */
  YYSYMBOL_TOKEN_EQ = 43,                  /* TOKEN_EQ  */
  YYSYMBOL_TOKEN_NEQ = 44,                 /* TOKEN_NEQ  */
  YYSYMBOL_TOKEN_LT = 45,                  /* TOKEN_LT  */
  YYSYMBOL_TOKEN_GT = 46,                  /* TOKEN_GT  */
  YYSYMBOL_TOKEN_LEQ = 47,                 /* TOKEN_LEQ  */
  YYSYMBOL_TOKEN_GEQ = 48,                 /* TOKEN_GEQ  */
  YYSYMBOL_TOKEN_AND = 49,                 /* TOKEN_AND  */
  YYSYMBOL_TOKEN_OR = 50,                  /* TOKEN_OR  */
  YYSYMBOL_TOKEN_XOR_LOGIC = 51,           /* TOKEN_XOR_LOGIC  */
  YYSYMBOL_TOKEN_NOT = 52,                 /* TOKEN_NOT  */
  YYSYMBOL_TOKEN_POWER = 53,               /* TOKEN_POWER  */
  YYSYMBOL_TOKEN_BIT_AND = 54,             /* TOKEN_BIT_AND  */
  YYSYMBOL_TOKEN_BIT_OR = 55,              /* TOKEN_BIT_OR  */
  YYSYMBOL_TOKEN_BIT_XOR = 56,             /* TOKEN_BIT_XOR  */
  YYSYMBOL_TOKEN_BIT_NOT = 57,             /* TOKEN_BIT_NOT  */
  YYSYMBOL_TOKEN_ROTATE_LEFT = 58,         /* TOKEN_ROTATE_LEFT  */
  YYSYMBOL_TOKEN_ROTATE_RIGHT = 59,        /* TOKEN_ROTATE_RIGHT  */
  YYSYMBOL_TOKEN_SHIFT_LEFT = 60,          /* TOKEN_SHIFT_LEFT  */
  YYSYMBOL_TOKEN_SHIFT_RIGHT = 61,         /* TOKEN_SHIFT_RIGHT  */
  YYSYMBOL_TOKEN_ENCRYPT = 62,             /* TOKEN_ENCRYPT  */
  YYSYMBOL_TOKEN_DECRYPT = 63,             /* TOKEN_DECRYPT  */
  YYSYMBOL_TOKEN_HASH_CALC = 64,           /* TOKEN_HASH_CALC  */
  YYSYMBOL_TOKEN_HASH_VERIFY = 65,         /* TOKEN_HASH_VERIFY  */
  YYSYMBOL_TOKEN_SIGN = 66,                /* TOKEN_SIGN  */
  YYSYMBOL_TOKEN_VERIFY_SIGN = 67,         /* TOKEN_VERIFY_SIGN  */
  YYSYMBOL_TOKEN_LBRACE = 68,              /* TOKEN_LBRACE  */
  YYSYMBOL_TOKEN_RBRACE = 69,              /* TOKEN_RBRACE  */
  YYSYMBOL_TOKEN_LBRACKET = 70,            /* TOKEN_LBRACKET  */
  YYSYMBOL_TOKEN_RBRACKET = 71,            /* TOKEN_RBRACKET  */
  YYSYMBOL_TOKEN_LPAREN = 72,              /* TOKEN_LPAREN  */
  YYSYMBOL_TOKEN_RPAREN = 73,              /* TOKEN_RPAREN  */
  YYSYMBOL_TOKEN_SEMICOLON = 74,           /* TOKEN_SEMICOLON  */
  YYSYMBOL_TOKEN_COMMA = 75,               /* TOKEN_COMMA  */
  YYSYMBOL_TOKEN_DOT = 76,                 /* TOKEN_DOT  */
  YYSYMBOL_TOKEN_COLON = 77,               /* TOKEN_COLON  */
  YYSYMBOL_YYACCEPT = 78,                  /* $accept  */
  YYSYMBOL_program = 79,                   /* program  */
  YYSYMBOL_imports = 80,                   /* imports  */
  YYSYMBOL_keyspace_block = 81,            /* keyspace_block  */
  YYSYMBOL_global_declarations = 82,       /* global_declarations  */
  YYSYMBOL_global_declaration = 83,        /* global_declaration  */
  YYSYMBOL_variable_declaration = 84,      /* variable_declaration  */
  YYSYMBOL_packet_definition = 85,         /* packet_definition  */
  YYSYMBOL_struct_fields = 86,             /* struct_fields  */
  YYSYMBOL_struct_definitions = 87,        /* struct_definitions  */
  YYSYMBOL_type_name = 88,                 /* type_name  */
  YYSYMBOL_main_block = 89,                /* main_block  */
  YYSYMBOL_block = 90,                     /* block  */
  YYSYMBOL_instructions = 91,              /* instructions  */
  YYSYMBOL_instruction = 92,               /* instruction  */
  YYSYMBOL_assignment = 93,                /* assignment  */
  YYSYMBOL_lvalue = 94,                    /* lvalue  */
  YYSYMBOL_io_statement = 95,              /* io_statement  */
  YYSYMBOL_control_structure = 96,         /* control_structure  */
  YYSYMBOL_if_statement = 97,              /* if_statement  */
  YYSYMBOL_else_part = 98,                 /* else_part  */
  YYSYMBOL_loop_statement = 99,            /* loop_statement  */
  YYSYMBOL_expression = 100,               /* expression  */
  YYSYMBOL_term = 101,                     /* term  */
  YYSYMBOL_argument_list = 102             /* argument_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1176

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  78
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  247

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   332


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    66,    66,    75,    76,    77,    81,    84,    85,    89,
      90,    95,   101,   107,   112,   117,   125,   129,   130,   131,
     133,   135,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   153,   157,   160,   161,   165,   166,
     167,   168,   169,   173,   174,   178,   179,   180,   181,   185,
     186,   187,   188,   192,   193,   197,   200,   201,   202,   206,
     208,   214,   219,   224,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   274,   275,   276
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TOKEN_IDENTIFIER",
  "TOKEN_STRING", "TOKEN_HEX", "TOKEN_INTEGER", "TOKEN_PROTOCOL",
  "TOKEN_ENDPROTOCOL", "TOKEN_IMPORT", "TOKEN_KEYSPACE", "TOKEN_MAIN",
  "TOKEN_LOOP", "TOKEN_FOR", "TOKEN_ROTATE", "TOKEN_ROUNDS", "TOKEN_STEP",
  "TOKEN_PACKET", "TOKEN_BIT", "TOKEN_NIBBLE", "TOKEN_BYTE", "TOKEN_WORD",
  "TOKEN_DWORD", "TOKEN_QWORD", "TOKEN_PLAIN", "TOKEN_CIPHER",
  "TOKEN_HASH", "TOKEN_KEY128", "TOKEN_KEY256", "TOKEN_KEY512",
  "TOKEN_SECURE_ASSIGN", "TOKEN_DECLARE", "TOKEN_ASSIGN_LOOP", "TOKEN_IF",
  "TOKEN_ELIF", "TOKEN_OUTPUT", "TOKEN_INPUT", "TOKEN_PLUS", "TOKEN_MINUS",
  "TOKEN_MULT", "TOKEN_DIV", "TOKEN_MOD", "TOKEN_ASSIGN", "TOKEN_EQ",
  "TOKEN_NEQ", "TOKEN_LT", "TOKEN_GT", "TOKEN_LEQ", "TOKEN_GEQ",
  "TOKEN_AND", "TOKEN_OR", "TOKEN_XOR_LOGIC", "TOKEN_NOT", "TOKEN_POWER",
  "TOKEN_BIT_AND", "TOKEN_BIT_OR", "TOKEN_BIT_XOR", "TOKEN_BIT_NOT",
  "TOKEN_ROTATE_LEFT", "TOKEN_ROTATE_RIGHT", "TOKEN_SHIFT_LEFT",
  "TOKEN_SHIFT_RIGHT", "TOKEN_ENCRYPT", "TOKEN_DECRYPT", "TOKEN_HASH_CALC",
  "TOKEN_HASH_VERIFY", "TOKEN_SIGN", "TOKEN_VERIFY_SIGN", "TOKEN_LBRACE",
  "TOKEN_RBRACE", "TOKEN_LBRACKET", "TOKEN_RBRACKET", "TOKEN_LPAREN",
  "TOKEN_RPAREN", "TOKEN_SEMICOLON", "TOKEN_COMMA", "TOKEN_DOT",
  "TOKEN_COLON", "$accept", "program", "imports", "keyspace_block",
  "global_declarations", "global_declaration", "variable_declaration",
  "packet_definition", "struct_fields", "struct_definitions", "type_name",
  "main_block", "block", "instructions", "instruction", "assignment",
  "lvalue", "io_statement", "control_structure", "if_statement",
  "else_part", "loop_statement", "expression", "term", "argument_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-126)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-49)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,    78,    82,  -126,  -126,    68,    87,    12,  -126,    17,
    -126,    -9,    93,   178,    29,   100,  -126,    96,  -126,     3,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,     4,  -126,  -126,    43,
    -126,   111,   115,   121,   126,   122,  -126,    63,    81,    34,
      89,   264,  -126,  -126,  -126,    69,    83,    91,    27,    27,
     159,    27,    27,  -126,    27,  -126,  -126,  -126,    56,  -126,
    -126,  -126,  -126,   304,  -126,   263,  -126,   133,    27,  -126,
     134,    66,    27,   163,    27,   164,    27,    30,   559,   336,
     -49,    94,   116,   116,   528,    27,    27,    27,    27,    27,
      27,    27,    27,    27,    27,    27,    27,    27,    27,    27,
      27,    27,    27,    27,    27,    27,    27,    27,    27,    27,
      27,    27,    27,  -126,    27,    27,    27,  -126,    97,     5,
     167,   368,   169,    81,   594,   975,   -68,    59,   629,   141,
     213,    27,   173,    29,  -126,    27,   174,  -126,  -126,   400,
     432,   464,   496,   -24,   -24,   116,   116,   116,  1056,  1056,
    1081,  1081,  1081,  1081,  1006,  1031,   270,   116,  1115,  1115,
    1090,   -28,   -28,   -28,   -28,   975,   975,   975,   975,   975,
    -126,   175,   177,   106,  -126,   110,    77,  -126,    27,    27,
      29,    27,   114,   664,   118,   -12,   699,   119,  -126,  -126,
    -126,  -126,   112,   142,  -126,  -126,   975,   734,  -126,   944,
      29,  -126,    27,    29,    27,  -126,  -126,    27,  -126,   161,
      80,    27,  -126,   769,  -126,   804,   839,   187,   171,  -126,
      29,  -126,   149,    27,    29,   223,   -12,  -126,   874,  -126,
      27,  -126,    29,   909,  -126,    29,  -126
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     3,     1,     0,     0,     0,    20,     5,
       7,     0,     0,     0,     0,     0,    21,     0,     4,     0,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,     6,     8,     9,    10,     0,    36,    34,     0,
       2,     0,     0,     0,     0,     0,    17,     0,     0,     0,
       0,    95,    98,    97,    96,     0,     0,     0,     0,     0,
       0,     0,     0,    35,     0,    38,    37,    39,     0,    40,
      41,    53,    54,     0,    64,     0,    14,     0,     0,    12,
       0,     0,   104,     0,     0,     0,     0,    95,     0,     0,
      45,     0,    80,    84,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    91,     0,     0,     0,    42,     0,     0,
       0,     0,     0,    96,     0,   105,     0,   101,     0,     0,
       0,     0,     0,     0,    49,     0,     0,    50,    99,     0,
       0,     0,     0,    65,    66,    67,    68,    69,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    70,    81,    82,
      83,    87,    88,    85,    86,    89,    90,    92,    93,    94,
      16,     0,     0,     0,    11,     0,   100,   103,     0,     0,
       0,     0,     0,     0,   101,    56,     0,    47,    44,    51,
      52,    43,     0,     0,    15,    13,   106,     0,    59,     0,
       0,   100,     0,     0,     0,    55,    46,     0,    18,     0,
     102,     0,    63,     0,    57,     0,     0,     0,     0,   102,
       0,    48,     0,     0,     0,     0,    56,    19,     0,    62,
       0,    58,     0,     0,    61,     0,    60
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -126,  -126,  -126,  -126,  -126,  -126,   148,   227,  -126,  -126,
     166,  -126,  -125,  -126,  -126,  -126,   183,  -126,  -126,  -126,
       8,  -126,   -58,  -126,  -126
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     5,     8,    13,    33,    34,    16,    75,    11,
      36,    17,    38,    45,    66,    67,    68,    69,    70,    71,
     215,    72,    73,    74,   136
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      88,    89,    14,    92,    93,   187,    94,   188,    15,    99,
     100,   101,   102,   103,     1,   101,   102,   103,   195,   213,
     131,   145,   214,   134,   135,   113,   138,   146,   140,   113,
      87,    52,    53,    54,    41,    43,   181,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   208,   177,   178,   179,    87,
      52,    53,   133,    42,    44,   182,    78,     6,     7,    61,
      10,     3,     4,   193,    62,   222,    95,   196,   224,   -47,
       9,    96,    97,    12,   -47,   -47,    18,    37,    98,    64,
     141,   -47,    82,    39,    40,   236,   142,   -46,    79,   239,
     -48,    46,   -46,   -46,    47,   -48,   -48,   244,    61,   -46,
     246,    48,   -48,    62,    49,    51,    52,    53,    54,   189,
     206,   207,    50,   209,    55,    56,    57,    76,    64,    84,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    77,    85,   223,    58,   225,    59,    60,   226,
      80,    86,    90,   228,   130,   132,   137,   139,   147,   113,
     183,   180,   185,   191,    61,   238,   194,   197,   202,    62,
     204,    19,   243,   203,   205,   210,   218,   233,   212,   217,
     232,    63,   227,    65,    64,    15,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    99,   100,
     101,   102,   103,   219,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   237,   113,   114,   115,   116,   192,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   240,
      35,   129,   234,    91,   241,     0,     0,    32,   235,     0,
      99,   100,   101,   102,   103,     0,   104,   105,   106,   107,
     108,   109,   110,   111,   112,     0,   113,   114,   115,   116,
       0,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,     0,   -45,    41,     0,     0,     0,   -45,
     -45,     0,     0,     0,     0,     0,   -45,    99,   100,   101,
     102,   103,     0,   104,   105,   106,   107,   108,   109,   110,
     111,     0,     0,   113,   114,   115,   116,     0,   117,   118,
     119,   120,   128,     0,    81,     0,    82,     0,     0,     0,
      83,    99,   100,   101,   102,   103,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   112,     0,   113,   114,   115,
     116,     0,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,     0,    99,   100,   101,   102,   103,   127,   104,
     105,   106,   107,   108,   109,   110,   111,   112,     0,   113,
     114,   115,   116,     0,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,     0,    99,   100,   101,   102,   103,
     144,   104,   105,   106,   107,   108,   109,   110,   111,   112,
       0,   113,   114,   115,   116,     0,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,     0,    99,   100,   101,
     102,   103,   184,   104,   105,   106,   107,   108,   109,   110,
     111,   112,     0,   113,   114,   115,   116,     0,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,     0,    99,
     100,   101,   102,   103,   198,   104,   105,   106,   107,   108,
     109,   110,   111,   112,     0,   113,   114,   115,   116,     0,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
       0,    99,   100,   101,   102,   103,   199,   104,   105,   106,
     107,   108,   109,   110,   111,   112,     0,   113,   114,   115,
     116,     0,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,     0,    99,   100,   101,   102,   103,   200,   104,
     105,   106,   107,   108,   109,   110,   111,   112,     0,   113,
     114,   115,   116,     0,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,     0,    99,   100,   101,   102,   103,
     201,   104,   105,   106,   107,   108,   109,   110,   111,   112,
       0,   113,   114,   115,   116,     0,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    99,   100,   101,   102,
     103,   148,   104,   105,   106,   107,   108,   109,   110,   111,
     112,     0,   113,   114,   115,   116,     0,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,     0,     0,     0,
     143,    99,   100,   101,   102,   103,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   112,     0,   113,   114,   115,
     116,     0,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,     0,     0,     0,   186,    99,   100,   101,   102,
     103,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,     0,   113,   114,   115,   116,     0,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,     0,     0,     0,
     190,    99,   100,   101,   102,   103,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   112,     0,   113,   114,   115,
     116,     0,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,     0,     0,     0,   211,    99,   100,   101,   102,
     103,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,     0,   113,   114,   115,   116,     0,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,     0,     0,     0,
     216,    99,   100,   101,   102,   103,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   112,     0,   113,   114,   115,
     116,     0,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,     0,     0,     0,   220,    99,   100,   101,   102,
     103,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,     0,   113,   114,   115,   116,     0,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,     0,     0,     0,
     229,    99,   100,   101,   102,   103,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   112,     0,   113,   114,   115,
     116,     0,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,     0,     0,     0,   230,    99,   100,   101,   102,
     103,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,     0,   113,   114,   115,   116,     0,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,     0,     0,     0,
     231,    99,   100,   101,   102,   103,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   112,     0,   113,   114,   115,
     116,     0,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,     0,     0,     0,   242,    99,   100,   101,   102,
     103,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,     0,   113,   114,   115,   116,     0,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,     0,     0,   221,
     245,    99,   100,   101,   102,   103,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   112,     0,   113,   114,   115,
     116,     0,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,    99,   100,   101,   102,   103,     0,   104,   105,
     106,   107,   108,   109,   110,   111,   112,     0,   113,   114,
     115,   116,     0,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    99,   100,   101,   102,   103,     0,   104,
     105,   106,   107,   108,   109,     0,   111,     0,     0,   113,
     114,   115,   116,     0,   117,   118,   119,   120,    99,   100,
     101,   102,   103,     0,   104,   105,   106,   107,   108,   109,
       0,     0,     0,     0,   113,   114,   115,   116,     0,   117,
     118,   119,   120,    99,   100,   101,   102,   103,     0,     0,
       0,   106,   107,   108,   109,     0,     0,     0,     0,   113,
     114,   115,   116,     0,   117,   118,   119,   120,    99,   100,
     101,   102,   103,     0,     0,     0,     0,    99,   100,   101,
     102,   103,     0,     0,   113,   114,   115,   116,     0,   117,
     118,   119,   120,   113,   114,   115,     0,     0,   117,   118,
     119,   120,    99,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   113,     0,
       0,     0,     0,   117,   118,   119,   120
};

static const yytype_int16 yycheck[] =
{
      58,    59,    11,    61,    62,    73,    64,    75,    17,    37,
      38,    39,    40,    41,     7,    39,    40,    41,   143,    31,
      78,    70,    34,    81,    82,    53,    84,    76,    86,    53,
       3,     4,     5,     6,    31,    31,    31,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   190,   124,   125,   126,     3,
       4,     5,     6,    70,    70,    70,    42,     9,    10,    52,
      68,     3,     0,   141,    57,   210,    30,   145,   213,    30,
       3,    35,    36,    76,    35,    36,     3,    68,    42,    72,
      70,    42,    72,     3,     8,   230,    76,    30,    74,   234,
      30,    68,    35,    36,     3,    35,    36,   242,    52,    42,
     245,     6,    42,    57,     3,     3,     4,     5,     6,    70,
     188,   189,     6,   191,    12,    13,    14,    74,    72,    70,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    71,    70,   212,    33,   214,    35,    36,   217,
      71,    70,     3,   221,    31,    31,     3,     3,    74,    53,
       3,    74,     3,    32,    52,   233,     3,     3,     3,    57,
      74,     3,   240,     6,    74,    71,    74,    16,    70,    70,
       3,    69,    31,    45,    72,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    37,    38,
      39,    40,    41,    71,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    74,    53,    54,    55,    56,    15,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    16,
      13,    75,    71,    60,   236,    -1,    -1,    69,    77,    -1,
      37,    38,    39,    40,    41,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    -1,    53,    54,    55,    56,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    30,    31,    -1,    -1,    -1,    35,
      36,    -1,    -1,    -1,    -1,    -1,    42,    37,    38,    39,
      40,    41,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    -1,    53,    54,    55,    56,    -1,    58,    59,
      60,    61,    69,    -1,    70,    -1,    72,    -1,    -1,    -1,
      76,    37,    38,    39,    40,    41,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    -1,    53,    54,    55,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    37,    38,    39,    40,    41,    74,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    -1,    53,
      54,    55,    56,    -1,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    37,    38,    39,    40,    41,
      74,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      -1,    53,    54,    55,    56,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    37,    38,    39,
      40,    41,    74,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    -1,    53,    54,    55,    56,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    37,
      38,    39,    40,    41,    74,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    -1,    53,    54,    55,    56,    -1,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    37,    38,    39,    40,    41,    74,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    -1,    53,    54,    55,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    37,    38,    39,    40,    41,    74,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    -1,    53,
      54,    55,    56,    -1,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    37,    38,    39,    40,    41,
      74,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      -1,    53,    54,    55,    56,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    37,    38,    39,    40,
      41,    73,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    -1,    53,    54,    55,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    37,    38,    39,    40,    41,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    -1,    53,    54,    55,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    71,    37,    38,    39,    40,
      41,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    -1,    53,    54,    55,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    37,    38,    39,    40,    41,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    -1,    53,    54,    55,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    71,    37,    38,    39,    40,
      41,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    -1,    53,    54,    55,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    37,    38,    39,    40,    41,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    -1,    53,    54,    55,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    71,    37,    38,    39,    40,
      41,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    -1,    53,    54,    55,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    37,    38,    39,    40,    41,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    -1,    53,    54,    55,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    71,    37,    38,    39,    40,
      41,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    -1,    53,    54,    55,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    37,    38,    39,    40,    41,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    -1,    53,    54,    55,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    71,    37,    38,    39,    40,
      41,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    -1,    53,    54,    55,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    35,
      71,    37,    38,    39,    40,    41,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    -1,    53,    54,    55,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    37,    38,    39,    40,    41,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    -1,    53,    54,
      55,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    37,    38,    39,    40,    41,    -1,    43,
      44,    45,    46,    47,    48,    -1,    50,    -1,    -1,    53,
      54,    55,    56,    -1,    58,    59,    60,    61,    37,    38,
      39,    40,    41,    -1,    43,    44,    45,    46,    47,    48,
      -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,    58,
      59,    60,    61,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    45,    46,    47,    48,    -1,    -1,    -1,    -1,    53,
      54,    55,    56,    -1,    58,    59,    60,    61,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    37,    38,    39,
      40,    41,    -1,    -1,    53,    54,    55,    56,    -1,    58,
      59,    60,    61,    53,    54,    55,    -1,    -1,    58,    59,
      60,    61,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    58,    59,    60,    61
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,    79,     3,     0,    80,     9,    10,    81,     3,
      68,    87,    76,    82,    11,    17,    85,    89,     3,     3,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    69,    83,    84,    85,    88,    68,    90,     3,
       8,    31,    70,    31,    70,    91,    68,     3,     6,     3,
       6,     3,     4,     5,     6,    12,    13,    14,    33,    35,
      36,    52,    57,    69,    72,    84,    92,    93,    94,    95,
      96,    97,    99,   100,   101,    86,    74,    71,    42,    74,
      71,    70,    72,    76,    70,    70,    70,     3,   100,   100,
       3,    94,   100,   100,   100,    30,    35,    36,    42,    37,
      38,    39,    40,    41,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    53,    54,    55,    56,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    74,    69,    88,
      31,   100,    31,     6,   100,   100,   102,     3,   100,     3,
     100,    70,    76,    71,    74,    70,    76,    74,    73,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
      74,    31,    70,     3,    74,     3,    71,    73,    75,    70,
      71,    32,    15,   100,     3,    90,   100,     3,    74,    74,
      74,    74,     3,     6,    74,    74,   100,   100,    90,   100,
      71,    71,    70,    31,    34,    98,    71,    70,    74,    71,
      71,    35,    90,   100,    90,   100,   100,    31,   100,    71,
      71,    71,     3,    16,    71,    77,    90,    74,   100,    90,
      16,    98,    71,   100,    90,    71,    90
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    78,    79,    80,    80,    80,    81,    82,    82,    83,
      83,    84,    84,    84,    84,    84,    85,    86,    86,    86,
      87,    87,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    89,    90,    91,    91,    92,    92,
      92,    92,    92,    93,    93,    94,    94,    94,    94,    95,
      95,    95,    95,    96,    96,    97,    98,    98,    98,    99,
      99,    99,    99,    99,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   102,   102,   102
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     7,     0,     5,     3,     4,     0,     2,     1,
       1,     6,     4,     7,     4,     7,     6,     0,     5,     8,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     3,     0,     2,     1,     1,
       1,     1,     2,     4,     4,     1,     4,     3,     6,     3,
       3,     4,     4,     1,     1,     5,     0,     2,     5,     5,
      12,    11,     9,     6,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     2,     3,     3,     3,     1,     1,     1,     1,     3,
       4,     3,     6,     4,     0,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: TOKEN_PROTOCOL TOKEN_IDENTIFIER imports keyspace_block struct_definitions main_block TOKEN_ENDPROTOCOL  */
#line 67 "src/lexer/cryptolang.y"
    { 
        printf("\n===================================================================\n");
        printf("  COMPILATION SUCCESS\n");
        printf("===================================================================\n");
        afficherTable();
    }
#line 1536 "build/y.tab.c"
    break;

  case 11: /* variable_declaration: type_name TOKEN_DECLARE TOKEN_IDENTIFIER TOKEN_ASSIGN expression TOKEN_SEMICOLON  */
#line 96 "src/lexer/cryptolang.y"
    { 
        inserer((yyvsp[-3].sval), (yyvsp[-5].type), SYM_VAR, 1);
        printf("[PARSER] Global Var: %s initialized\n", (yyvsp[-3].sval)); 
    }
#line 1545 "build/y.tab.c"
    break;

  case 12: /* variable_declaration: type_name TOKEN_DECLARE TOKEN_IDENTIFIER TOKEN_SEMICOLON  */
#line 102 "src/lexer/cryptolang.y"
    { 
        inserer((yyvsp[-1].sval), (yyvsp[-3].type), SYM_VAR, 1);
        printf("[PARSER] Global Var: %s\n", (yyvsp[-1].sval)); 
    }
#line 1554 "build/y.tab.c"
    break;

  case 13: /* variable_declaration: type_name TOKEN_LBRACKET TOKEN_INTEGER TOKEN_RBRACKET TOKEN_DECLARE TOKEN_IDENTIFIER TOKEN_SEMICOLON  */
#line 108 "src/lexer/cryptolang.y"
    { 
        inserer((yyvsp[-1].sval), (yyvsp[-6].type), SYM_ARRAY, (yyvsp[-4].ival));
        printf("[PARSER] Global Array: %s[%d]\n", (yyvsp[-1].sval), (yyvsp[-4].ival)); 
    }
#line 1563 "build/y.tab.c"
    break;

  case 14: /* variable_declaration: TOKEN_IDENTIFIER TOKEN_DECLARE TOKEN_IDENTIFIER TOKEN_SEMICOLON  */
#line 113 "src/lexer/cryptolang.y"
    { 
        inserer((yyvsp[-1].sval), T_PLAIN, SYM_VAR, 1); 
        printf("[PARSER] Struct Instance: %s (Type: %s)\n", (yyvsp[-1].sval), (yyvsp[-3].sval)); 
    }
#line 1572 "build/y.tab.c"
    break;

  case 15: /* variable_declaration: TOKEN_IDENTIFIER TOKEN_LBRACKET TOKEN_INTEGER TOKEN_RBRACKET TOKEN_DECLARE TOKEN_IDENTIFIER TOKEN_SEMICOLON  */
#line 118 "src/lexer/cryptolang.y"
    { 
        inserer((yyvsp[-1].sval), T_PLAIN, SYM_ARRAY, (yyvsp[-4].ival));
        printf("[PARSER] Struct Array: %s[%d]\n", (yyvsp[-1].sval), (yyvsp[-4].ival)); 
    }
#line 1581 "build/y.tab.c"
    break;

  case 16: /* packet_definition: TOKEN_PACKET TOKEN_IDENTIFIER TOKEN_LBRACE struct_fields TOKEN_RBRACE TOKEN_SEMICOLON  */
#line 126 "src/lexer/cryptolang.y"
    { printf("[PARSER] Packet Definition: %s\n", (yyvsp[-4].sval)); }
#line 1587 "build/y.tab.c"
    break;

  case 22: /* type_name: TOKEN_BIT  */
#line 138 "src/lexer/cryptolang.y"
                   { (yyval.type) = T_BIT; }
#line 1593 "build/y.tab.c"
    break;

  case 23: /* type_name: TOKEN_NIBBLE  */
#line 139 "src/lexer/cryptolang.y"
                   { (yyval.type) = T_NIBBLE; }
#line 1599 "build/y.tab.c"
    break;

  case 24: /* type_name: TOKEN_BYTE  */
#line 140 "src/lexer/cryptolang.y"
                   { (yyval.type) = T_BYTE; }
#line 1605 "build/y.tab.c"
    break;

  case 25: /* type_name: TOKEN_WORD  */
#line 141 "src/lexer/cryptolang.y"
                   { (yyval.type) = T_WORD; }
#line 1611 "build/y.tab.c"
    break;

  case 26: /* type_name: TOKEN_DWORD  */
#line 142 "src/lexer/cryptolang.y"
                   { (yyval.type) = T_DWORD; }
#line 1617 "build/y.tab.c"
    break;

  case 27: /* type_name: TOKEN_QWORD  */
#line 143 "src/lexer/cryptolang.y"
                   { (yyval.type) = T_QWORD; }
#line 1623 "build/y.tab.c"
    break;

  case 28: /* type_name: TOKEN_PLAIN  */
#line 144 "src/lexer/cryptolang.y"
                   { (yyval.type) = T_PLAIN; }
#line 1629 "build/y.tab.c"
    break;

  case 29: /* type_name: TOKEN_CIPHER  */
#line 145 "src/lexer/cryptolang.y"
                   { (yyval.type) = T_CIPHER; }
#line 1635 "build/y.tab.c"
    break;

  case 30: /* type_name: TOKEN_HASH  */
#line 146 "src/lexer/cryptolang.y"
                   { (yyval.type) = T_HASH; }
#line 1641 "build/y.tab.c"
    break;

  case 31: /* type_name: TOKEN_KEY128  */
#line 147 "src/lexer/cryptolang.y"
                   { (yyval.type) = T_KEY128; }
#line 1647 "build/y.tab.c"
    break;

  case 32: /* type_name: TOKEN_KEY256  */
#line 148 "src/lexer/cryptolang.y"
                   { (yyval.type) = T_KEY256; }
#line 1653 "build/y.tab.c"
    break;

  case 33: /* type_name: TOKEN_KEY512  */
#line 149 "src/lexer/cryptolang.y"
                   { (yyval.type) = T_KEY512; }
#line 1659 "build/y.tab.c"
    break;

  case 59: /* loop_statement: TOKEN_LOOP TOKEN_LBRACKET expression TOKEN_RBRACKET block  */
#line 207 "src/lexer/cryptolang.y"
    { printf("[PARSER] Loop: WHILE\n"); }
#line 1665 "build/y.tab.c"
    break;

  case 60: /* loop_statement: TOKEN_FOR TOKEN_LBRACKET TOKEN_IDENTIFIER TOKEN_ASSIGN_LOOP expression TOKEN_OUTPUT expression TOKEN_COLON TOKEN_STEP expression TOKEN_RBRACKET block  */
#line 209 "src/lexer/cryptolang.y"
    { 

        inserer((yyvsp[-9].sval), T_DWORD, SYM_VAR, 1); 
        printf("[PARSER] Loop: FOR (Explicit Step)\n"); 
    }
#line 1675 "build/y.tab.c"
    break;

  case 61: /* loop_statement: TOKEN_FOR TOKEN_LBRACKET TOKEN_IDENTIFIER TOKEN_ASSIGN_LOOP expression TOKEN_OUTPUT expression TOKEN_STEP expression TOKEN_RBRACKET block  */
#line 215 "src/lexer/cryptolang.y"
    { 
        inserer((yyvsp[-8].sval), T_DWORD, SYM_VAR, 1);
        printf("[PARSER] Loop: FOR (No Colon Step)\n"); 
    }
#line 1684 "build/y.tab.c"
    break;

  case 62: /* loop_statement: TOKEN_FOR TOKEN_LBRACKET TOKEN_IDENTIFIER TOKEN_ASSIGN_LOOP expression TOKEN_OUTPUT expression TOKEN_RBRACKET block  */
#line 220 "src/lexer/cryptolang.y"
    { 
        inserer((yyvsp[-6].sval), T_DWORD, SYM_VAR, 1);
        printf("[PARSER] Loop: FOR (Default Step)\n"); 
    }
#line 1693 "build/y.tab.c"
    break;

  case 63: /* loop_statement: TOKEN_ROTATE TOKEN_LBRACKET expression TOKEN_ROUNDS TOKEN_RBRACKET block  */
#line 225 "src/lexer/cryptolang.y"
    { printf("[PARSER] Loop: ROTATE\n"); }
#line 1699 "build/y.tab.c"
    break;


#line 1703 "build/y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 279 "src/lexer/cryptolang.y"


void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error: %s at Line %d\n", s, line_number);
    error_count++;
}
