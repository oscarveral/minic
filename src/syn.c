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
#line 1 "src/syn.y"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "lex.h"
#include "syn.h"
#include "sem.h"
#include "master.h"
#include "codegen.h"

extern int yylex(void); 
extern char *yytext;
extern int yylineno;

int syntax_errors = 0;

FILE *syntax_file = NULL;

void semantic_inform(char *lexema, semantic_action_t action);
void semantic_debug(void);

ListaC codegen_num(char *lexema);
ListaC codegen_id(char *lexema);
ListaC codegen_expr(ListaC llist, operation_t operacion, ListaC rlist);
ListaC codegen_unary(operation_t operacion, ListaC list);
ListaC codegen_read(char *lexema);
ListaC codegen_multiread(ListaC list, char *lexema);
ListaC codegen_print_str(char *lexema);
ListaC codegen_print_num(ListaC list);
ListaC codegen_assign(char *lexema, ListaC list);
ListaC codegen_if(ListaC condition, ListaC statement);
ListaC codegen_if_else(ListaC condition, ListaC first_statements, ListaC second_statements);
ListaC codegen_while(ListaC condition, ListaC statement);
ListaC codegen_do_while(ListaC statements, ListaC condition);
ListaC codegen_for(char *lexema, ListaC expresion, ListaC condition, ListaC statements);
ListaC codegen_for_extended(char *lexema, ListaC expresion, ListaC condition, ListaC increment, ListaC statements);
ListaC codegen_program(ListaC declarations, ListaC statements);
ListaC codegen_data(void);

void syntax_inform(syntax_reduction_t red);
void syntax_debug(syntax_reduction_t red);
void yyerror(char const *s);


#line 119 "src/syn.c"

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

#include "tokens.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_WHITESPACE = 3,                 /* WHITESPACE  */
  YYSYMBOL_LINE_COMMENT = 4,               /* LINE_COMMENT  */
  YYSYMBOL_MULTILINE_COMMENT = 5,          /* MULTILINE_COMMENT  */
  YYSYMBOL_VOID = 6,                       /* VOID  */
  YYSYMBOL_VAR = 7,                        /* VAR  */
  YYSYMBOL_CONST = 8,                      /* CONST  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_ELSE = 10,                      /* ELSE  */
  YYSYMBOL_WHILE = 11,                     /* WHILE  */
  YYSYMBOL_PRINT = 12,                     /* PRINT  */
  YYSYMBOL_READ = 13,                      /* READ  */
  YYSYMBOL_DO = 14,                        /* DO  */
  YYSYMBOL_FOR = 15,                       /* FOR  */
  YYSYMBOL_SEMICOLON = 16,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 17,                     /* COMMA  */
  YYSYMBOL_ASSIGN = 18,                    /* ASSIGN  */
  YYSYMBOL_LPARENTHESIS = 19,              /* LPARENTHESIS  */
  YYSYMBOL_RPARENTHESIS = 20,              /* RPARENTHESIS  */
  YYSYMBOL_LBRACE = 21,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 22,                    /* RBRACE  */
  YYSYMBOL_BAD_NUM = 23,                   /* BAD_NUM  */
  YYSYMBOL_BAD_ID = 24,                    /* BAD_ID  */
  YYSYMBOL_BAD_STRING = 25,                /* BAD_STRING  */
  YYSYMBOL_PARTIAL_STRING = 26,            /* PARTIAL_STRING  */
  YYSYMBOL_PARTIAL_COMMENT = 27,           /* PARTIAL_COMMENT  */
  YYSYMBOL_UNRECOGNIZED = 28,              /* UNRECOGNIZED  */
  YYSYMBOL_NUM = 29,                       /* NUM  */
  YYSYMBOL_STRING = 30,                    /* STRING  */
  YYSYMBOL_ID = 31,                        /* ID  */
  YYSYMBOL_LTE = 32,                       /* LTE  */
  YYSYMBOL_GTE = 33,                       /* GTE  */
  YYSYMBOL_LT = 34,                        /* LT  */
  YYSYMBOL_GT = 35,                        /* GT  */
  YYSYMBOL_EQ = 36,                        /* EQ  */
  YYSYMBOL_NEQ = 37,                       /* NEQ  */
  YYSYMBOL_PLUS = 38,                      /* PLUS  */
  YYSYMBOL_MINUS = 39,                     /* MINUS  */
  YYSYMBOL_MULT = 40,                      /* MULT  */
  YYSYMBOL_DIVIDE = 41,                    /* DIVIDE  */
  YYSYMBOL_UMINUS = 42,                    /* UMINUS  */
  YYSYMBOL_LOGICAL_NEG = 43,               /* LOGICAL_NEG  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_programa = 45,                  /* programa  */
  YYSYMBOL_46_1 = 46,                      /* $@1  */
  YYSYMBOL_47_2 = 47,                      /* $@2  */
  YYSYMBOL_declarations = 48,              /* declarations  */
  YYSYMBOL_49_3 = 49,                      /* $@3  */
  YYSYMBOL_50_4 = 50,                      /* $@4  */
  YYSYMBOL_identifier_list = 51,           /* identifier_list  */
  YYSYMBOL_asig = 52,                      /* asig  */
  YYSYMBOL_53_5 = 53,                      /* $@5  */
  YYSYMBOL_statement_list = 54,            /* statement_list  */
  YYSYMBOL_statement = 55,                 /* statement  */
  YYSYMBOL_56_6 = 56,                      /* $@6  */
  YYSYMBOL_print_list = 57,                /* print_list  */
  YYSYMBOL_print_item = 58,                /* print_item  */
  YYSYMBOL_read_list = 59,                 /* read_list  */
  YYSYMBOL_expression = 60                 /* expression  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   255

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  54
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  117

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    92,    92,    92,    92,    94,    95,    95,    96,    96,
      98,    99,   100,   101,   103,   104,   104,   106,   107,   109,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     120,   121,   122,   123,   125,   126,   128,   129,   130,   131,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147
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
  "\"end of file\"", "error", "\"invalid token\"", "WHITESPACE",
  "LINE_COMMENT", "MULTILINE_COMMENT", "VOID", "VAR", "CONST", "IF",
  "ELSE", "WHILE", "PRINT", "READ", "DO", "FOR", "SEMICOLON", "COMMA",
  "ASSIGN", "LPARENTHESIS", "RPARENTHESIS", "LBRACE", "RBRACE", "BAD_NUM",
  "BAD_ID", "BAD_STRING", "PARTIAL_STRING", "PARTIAL_COMMENT",
  "UNRECOGNIZED", "NUM", "STRING", "ID", "LTE", "GTE", "LT", "GT", "EQ",
  "NEQ", "PLUS", "MINUS", "MULT", "DIVIDE", "UMINUS", "LOGICAL_NEG",
  "$accept", "programa", "$@1", "$@2", "declarations", "$@3", "$@4",
  "identifier_list", "asig", "$@5", "statement_list", "statement", "$@6",
  "print_list", "print_item", "read_list", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-31)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-16)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -31,     3,     4,   -31,   -15,   -31,    -7,     6,     2,   -31,
      -1,   -31,   -31,   133,    10,    10,     9,    11,    23,    12,
      62,    32,   -31,   -31,   -31,   -31,   -31,    52,    33,   -31,
      42,   -14,   -14,   -31,   -14,   -31,   -31,   -31,   -14,   -14,
      47,   -31,    85,   -31,   -31,    71,    61,    48,   147,    67,
      73,   -31,    13,   -31,   150,   160,   182,   -31,   -31,   -31,
      26,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,
     -14,   -31,    17,    63,    76,   -31,   -14,   -14,   -31,   -31,
      62,    62,   -31,   -31,   -31,   -19,   -19,   -19,   -19,   -19,
     -19,    87,    87,   -31,   -31,   -31,   -31,   -14,   -14,    74,
      85,    79,   -31,   192,   100,   -31,    62,   -31,   -14,   -31,
      64,   -14,    62,   214,   -31,    62,   -31
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,     3,     0,     0,     0,     5,
      17,     6,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    17,     4,    19,    18,    13,    14,     0,    10,
       0,     0,     0,    33,     0,    53,    35,    54,     0,     0,
       0,    30,    34,    39,    36,     0,     0,     0,     0,     0,
       0,     7,     0,     9,     0,     0,     0,    50,    51,    28,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    29,     0,     0,     0,    21,     0,     0,    12,    11,
       0,     0,    52,    32,    31,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    38,    37,     0,     0,     0,
      16,    23,    24,     0,     0,    20,     0,    25,     0,    22,
       0,     0,     0,     0,    27,     0,    26
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -31,   -31,   -31,   -31,   -31,   -31,   -31,   114,    78,   -31,
     109,   -20,   -31,   -31,    83,   -31,   -30
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     6,    10,    14,    15,    28,    29,    50,
      13,    25,    49,    40,    41,    45,    42
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      46,    54,    55,     3,    56,    34,    11,    12,    57,    58,
       4,    26,     7,    43,    78,    35,     5,    37,    95,    67,
      68,    69,    70,     9,    33,    38,     8,    83,    31,    39,
      32,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    27,    34,    44,    27,    34,    99,   100,    96,    51,
      52,    47,    35,    36,    37,    35,    36,    37,    53,    52,
     101,   102,    38,    59,    60,    38,    39,   103,   104,    39,
     -15,    16,    73,    17,    18,    19,    20,    21,   110,    74,
     111,   113,    97,    22,   112,    76,   109,    71,    72,   106,
     105,    77,   114,    24,    98,   116,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,   108,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    69,    70,    30,
      79,    48,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    16,    84,    17,    18,    19,    20,    21,     0,
       0,     0,     0,     0,    22,    23,    16,     0,    17,    18,
      19,    20,    21,     0,    24,     0,     0,     0,    22,    75,
      80,     0,     0,     0,     0,     0,     0,     0,    24,     0,
      81,     0,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   107,     0,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,   115,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70
};

static const yytype_int8 yycheck[] =
{
      20,    31,    32,     0,    34,    19,     7,     8,    38,    39,
       6,     1,    19,     1,     1,    29,    31,    31,     1,    38,
      39,    40,    41,    21,     1,    39,    20,     1,    19,    43,
      19,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    31,    19,    31,    31,    19,    76,    77,    31,    16,
      17,    19,    29,    30,    31,    29,    30,    31,    16,    17,
      80,    81,    39,    16,    17,    39,    43,    97,    98,    43,
      18,     9,    11,    11,    12,    13,    14,    15,   108,    31,
      16,   111,    19,    21,    20,    18,   106,    16,    17,    10,
      16,    18,   112,    31,    18,   115,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    16,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    40,    41,    15,
      52,    22,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     9,    60,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    21,    22,     9,    -1,    11,    12,
      13,    14,    15,    -1,    31,    -1,    -1,    -1,    21,    22,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      20,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    45,    46,     0,     6,    31,    47,    19,    20,    21,
      48,     7,     8,    54,    49,    50,     9,    11,    12,    13,
      14,    15,    21,    22,    31,    55,     1,    31,    51,    52,
      51,    19,    19,     1,    19,    29,    30,    31,    39,    43,
      57,    58,    60,     1,    31,    59,    55,    19,    54,    56,
      53,    16,    17,    16,    60,    60,    60,    60,    60,    16,
      17,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    16,    17,    11,    31,    22,    18,    18,     1,    52,
      20,    20,    20,     1,    58,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,     1,    31,    19,    18,    60,
      60,    55,    55,    60,    60,    16,    10,    20,    16,    55,
      60,    16,    20,    60,    55,    20,    55
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    46,    47,    45,    48,    49,    48,    50,    48,
      51,    51,    51,    51,    52,    53,    52,    54,    54,    56,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      57,    57,    57,    57,    58,    58,    59,    59,    59,    59,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,    10,     0,     0,     5,     0,     5,
       1,     3,     3,     1,     1,     0,     4,     0,     2,     0,
       5,     3,     7,     5,     5,     6,    11,     9,     3,     3,
       1,     3,     3,     1,     1,     1,     1,     3,     3,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     3,     1,     1
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
  case 2: /* $@1: %empty  */
#line 92 "src/syn.y"
                    { tablaSimbolos = creaLS(); registros=crea_registros(); }
#line 1264 "src/syn.c"
    break;

  case 3: /* $@2: %empty  */
#line 92 "src/syn.y"
                                                                                      { free((yyvsp[0].lexema)); }
#line 1270 "src/syn.c"
    break;

  case 4: /* programa: $@1 VOID ID $@2 LPARENTHESIS RPARENTHESIS LBRACE declarations statement_list RBRACE  */
#line 92 "src/syn.y"
                                                                                                                                                                        { syntax_inform(PROGRAMA); semantic_debug(); codigo_generado = codegen_program((yyvsp[-2].codigo), (yyvsp[-1].codigo)); libera_registros(registros); }
#line 1276 "src/syn.c"
    break;

  case 5: /* declarations: %empty  */
#line 94 "src/syn.y"
                    { syntax_inform(EMPTY_DECL); (yyval.codigo) = creaLC(); }
#line 1282 "src/syn.c"
    break;

  case 6: /* $@3: %empty  */
#line 95 "src/syn.y"
                                                         { tipoSemantico = VARIABLE; }
#line 1288 "src/syn.c"
    break;

  case 7: /* declarations: declarations VAR $@3 identifier_list SEMICOLON  */
#line 95 "src/syn.y"
                                                                                                                 { syntax_inform(VAR_DECL); (yyval.codigo) = concatenaSeguraLC((yyvsp[-4].codigo), (yyvsp[-1].codigo)); }
#line 1294 "src/syn.c"
    break;

  case 8: /* $@4: %empty  */
#line 96 "src/syn.y"
                                                           { tipoSemantico = CONSTANTE; }
#line 1300 "src/syn.c"
    break;

  case 9: /* declarations: declarations CONST $@4 identifier_list SEMICOLON  */
#line 96 "src/syn.y"
                                                                                                                    { syntax_inform(CONST_DECL); (yyval.codigo) = concatenaSeguraLC((yyvsp[-4].codigo), (yyvsp[-1].codigo));  }
#line 1306 "src/syn.c"
    break;

  case 10: /* identifier_list: asig  */
#line 98 "src/syn.y"
                             { syntax_inform(DECLARATION_RED); (yyval.codigo) = (yyvsp[0].codigo); }
#line 1312 "src/syn.c"
    break;

  case 11: /* identifier_list: identifier_list COMMA asig  */
#line 99 "src/syn.y"
                                                                   { syntax_inform(MULTIPLE_DECLARATION); (yyval.codigo) = concatenaSeguraLC((yyvsp[-2].codigo), (yyvsp[0].codigo));  }
#line 1318 "src/syn.c"
    break;

  case 12: /* identifier_list: identifier_list COMMA error  */
#line 100 "src/syn.y"
                                                                    { syntax_inform(MULTIPLE_DECLARATION_ERROR); (yyval.codigo) = (yyvsp[-2].codigo); yyerrok; }
#line 1324 "src/syn.c"
    break;

  case 13: /* identifier_list: error  */
#line 101 "src/syn.y"
                                              { syntax_inform(DECLARATION_ERROR); (yyval.codigo) = creaLC(); yyerrok; yyclearin; }
#line 1330 "src/syn.c"
    break;

  case 14: /* asig: ID  */
#line 103 "src/syn.y"
                                   { syntax_inform(ASIG_DECL); semantic_inform((yyvsp[0].lexema), DECLARATION); free((yyvsp[0].lexema)); (yyval.codigo)  = creaLC(); }
#line 1336 "src/syn.c"
    break;

  case 15: /* $@5: %empty  */
#line 104 "src/syn.y"
                                           { semantic_inform((yyvsp[0].lexema), INITIALIZATION); }
#line 1342 "src/syn.c"
    break;

  case 16: /* asig: ID $@5 ASSIGN expression  */
#line 104 "src/syn.y"
                                                                                                      { syntax_inform(ASIG_INIT); (yyval.codigo) = codegen_assign((yyvsp[-3].lexema), (yyvsp[0].codigo)); }
#line 1348 "src/syn.c"
    break;

  case 17: /* statement_list: %empty  */
#line 106 "src/syn.y"
                        { syntax_inform(EMPTY_STMT_LIST); (yyval.codigo) = creaLC(); }
#line 1354 "src/syn.c"
    break;

  case 18: /* statement_list: statement_list statement  */
#line 107 "src/syn.y"
                                                                 { syntax_inform(STMT_LIST); (yyval.codigo) = concatenaSeguraLC((yyvsp[-1].codigo), (yyvsp[0].codigo)); }
#line 1360 "src/syn.c"
    break;

  case 19: /* $@6: %empty  */
#line 109 "src/syn.y"
                                   { semantic_inform((yyvsp[0].lexema), ASSIGNATION); }
#line 1366 "src/syn.c"
    break;

  case 20: /* statement: ID $@6 ASSIGN expression SEMICOLON  */
#line 109 "src/syn.y"
                                                                                                     { syntax_inform(ASSIGN_STMT); (yyval.codigo) = codegen_assign((yyvsp[-4].lexema), (yyvsp[-1].codigo)); }
#line 1372 "src/syn.c"
    break;

  case 21: /* statement: LBRACE statement_list RBRACE  */
#line 110 "src/syn.y"
                                                                     { syntax_inform(BRACES_STMT); (yyval.codigo) = (yyvsp[-1].codigo); }
#line 1378 "src/syn.c"
    break;

  case 22: /* statement: IF LPARENTHESIS expression RPARENTHESIS statement ELSE statement  */
#line 111 "src/syn.y"
                                                                                                         { syntax_inform(IF_ELSE_STMT); (yyval.codigo) = codegen_if_else((yyvsp[-4].codigo), (yyvsp[-2].codigo), (yyvsp[0].codigo)); }
#line 1384 "src/syn.c"
    break;

  case 23: /* statement: IF LPARENTHESIS expression RPARENTHESIS statement  */
#line 112 "src/syn.y"
                                                                                          { syntax_inform(IF_STMT); (yyval.codigo) = codegen_if((yyvsp[-2].codigo), (yyvsp[0].codigo)); }
#line 1390 "src/syn.c"
    break;

  case 24: /* statement: WHILE LPARENTHESIS expression RPARENTHESIS statement  */
#line 113 "src/syn.y"
                                                                                             { syntax_inform(WHILE_STMT); (yyval.codigo) = codegen_while((yyvsp[-2].codigo), (yyvsp[0].codigo)); }
#line 1396 "src/syn.c"
    break;

  case 25: /* statement: DO statement WHILE LPARENTHESIS expression RPARENTHESIS  */
#line 114 "src/syn.y"
                                                                                                { syntax_inform(DO_WHILE_STMT); (yyval.codigo) = codegen_do_while((yyvsp[-4].codigo), (yyvsp[-1].codigo)); }
#line 1402 "src/syn.c"
    break;

  case 26: /* statement: FOR LPARENTHESIS ID ASSIGN expression SEMICOLON expression SEMICOLON expression RPARENTHESIS statement  */
#line 115 "src/syn.y"
                                                                                                                                               { syntax_inform(FOR_EXT_STMT); semantic_inform((yyvsp[-8].lexema), ASSIGNATION); (yyval.codigo) = codegen_for_extended((yyvsp[-8].lexema), (yyvsp[-6].codigo), (yyvsp[-4].codigo), (yyvsp[-2].codigo), (yyvsp[0].codigo)); }
#line 1408 "src/syn.c"
    break;

  case 27: /* statement: FOR LPARENTHESIS ID ASSIGN expression SEMICOLON expression RPARENTHESIS statement  */
#line 116 "src/syn.y"
                                                                                                                          { syntax_inform(FOR_STMT); semantic_inform((yyvsp[-6].lexema), ASSIGNATION); (yyval.codigo) = codegen_for((yyvsp[-6].lexema), (yyvsp[-4].codigo), (yyvsp[-2].codigo) ,(yyvsp[0].codigo)); }
#line 1414 "src/syn.c"
    break;

  case 28: /* statement: PRINT print_list SEMICOLON  */
#line 117 "src/syn.y"
                                                                   { syntax_inform(PRINT_STMT); (yyval.codigo) = (yyvsp[-1].codigo); }
#line 1420 "src/syn.c"
    break;

  case 29: /* statement: READ read_list SEMICOLON  */
#line 118 "src/syn.y"
                                                                 { syntax_inform(READ_STMT); (yyval.codigo) = (yyvsp[-1].codigo); }
#line 1426 "src/syn.c"
    break;

  case 30: /* print_list: print_item  */
#line 120 "src/syn.y"
                                           { syntax_inform(PRINT_ITEM_RED); (yyval.codigo) = (yyvsp[0].codigo); }
#line 1432 "src/syn.c"
    break;

  case 31: /* print_list: print_list COMMA print_item  */
#line 121 "src/syn.y"
                                                                    { syntax_inform(MULTIPLE_PRINT); (yyval.codigo) = concatenaSeguraLC((yyvsp[-2].codigo), (yyvsp[0].codigo)); }
#line 1438 "src/syn.c"
    break;

  case 32: /* print_list: print_list COMMA error  */
#line 122 "src/syn.y"
                                                               { syntax_inform(MULTIPLE_PRINT_FORMAT_ERROR); (yyval.codigo) = (yyvsp[-2].codigo); yyerrok; }
#line 1444 "src/syn.c"
    break;

  case 33: /* print_list: error  */
#line 123 "src/syn.y"
                                              { syntax_inform(PRINT_FORMAT_ERROR); (yyval.codigo) = creaLC() ; yyerrok; }
#line 1450 "src/syn.c"
    break;

  case 34: /* print_item: expression  */
#line 125 "src/syn.y"
                                           { syntax_inform(PRINT_EXPR); (yyval.codigo) = codegen_print_num((yyvsp[0].codigo)); }
#line 1456 "src/syn.c"
    break;

  case 35: /* print_item: STRING  */
#line 126 "src/syn.y"
                                               { syntax_inform(PRINT_ITEM); semantic_inform((yyvsp[0].lexema), STRING_SYMBOL); (yyval.codigo) = codegen_print_str((yyvsp[0].lexema)); }
#line 1462 "src/syn.c"
    break;

  case 36: /* read_list: ID  */
#line 128 "src/syn.y"
                                   { syntax_inform(SINGLE_READ); semantic_inform((yyvsp[0].lexema), ASSIGNATION); (yyval.codigo) = codegen_read((yyvsp[0].lexema)); }
#line 1468 "src/syn.c"
    break;

  case 37: /* read_list: read_list COMMA ID  */
#line 129 "src/syn.y"
                                                           { syntax_inform(MULTIPLE_READ); semantic_inform((yyvsp[0].lexema), ASSIGNATION); (yyval.codigo) = codegen_multiread((yyvsp[-2].codigo), (yyvsp[0].lexema)); }
#line 1474 "src/syn.c"
    break;

  case 38: /* read_list: read_list COMMA error  */
#line 130 "src/syn.y"
                                                              { syntax_inform(MULTIPLE_READ_FORMAT_ERROR); (yyval.codigo) = (yyvsp[-2].codigo) ; yyerrok; }
#line 1480 "src/syn.c"
    break;

  case 39: /* read_list: error  */
#line 131 "src/syn.y"
                                              { syntax_inform(READ_FORMAT_ERROR); (yyval.codigo) = creaLC(); yyerrok; }
#line 1486 "src/syn.c"
    break;

  case 40: /* expression: expression LTE expression  */
#line 133 "src/syn.y"
                                                          { syntax_inform(LTE_EXPR); (yyval.codigo) = codegen_expr((yyvsp[-2].codigo), SLE, (yyvsp[0].codigo)); }
#line 1492 "src/syn.c"
    break;

  case 41: /* expression: expression GTE expression  */
#line 134 "src/syn.y"
                                                                  { syntax_inform(GTE_EXPR); (yyval.codigo) = codegen_expr((yyvsp[-2].codigo), SGE, (yyvsp[0].codigo)); }
#line 1498 "src/syn.c"
    break;

  case 42: /* expression: expression LT expression  */
#line 135 "src/syn.y"
                                                                 { syntax_inform(LT_EXPR); (yyval.codigo) = codegen_expr((yyvsp[-2].codigo), SLT, (yyvsp[0].codigo)); }
#line 1504 "src/syn.c"
    break;

  case 43: /* expression: expression GT expression  */
#line 136 "src/syn.y"
                                                                 { syntax_inform(GT_EXPR); (yyval.codigo) = codegen_expr((yyvsp[-2].codigo), SGT, (yyvsp[0].codigo)); }
#line 1510 "src/syn.c"
    break;

  case 44: /* expression: expression EQ expression  */
#line 137 "src/syn.y"
                                                                 { syntax_inform(EQ_EXPR); (yyval.codigo) = codegen_expr((yyvsp[-2].codigo), SEQ, (yyvsp[0].codigo)); }
#line 1516 "src/syn.c"
    break;

  case 45: /* expression: expression NEQ expression  */
#line 138 "src/syn.y"
                                                                  { syntax_inform(NEQ_EXPR); (yyval.codigo) = codegen_expr((yyvsp[-2].codigo), SNE, (yyvsp[0].codigo)); }
#line 1522 "src/syn.c"
    break;

  case 46: /* expression: expression PLUS expression  */
#line 139 "src/syn.y"
                                                                   { syntax_inform(PLUS_EXPR); (yyval.codigo) = codegen_expr((yyvsp[-2].codigo), ADD, (yyvsp[0].codigo)); }
#line 1528 "src/syn.c"
    break;

  case 47: /* expression: expression MINUS expression  */
#line 140 "src/syn.y"
                                                                    { syntax_inform(MINUS_EXPR); (yyval.codigo) = codegen_expr((yyvsp[-2].codigo), SUB, (yyvsp[0].codigo)); }
#line 1534 "src/syn.c"
    break;

  case 48: /* expression: expression MULT expression  */
#line 141 "src/syn.y"
                                                                   { syntax_inform(MULT_EXPR); (yyval.codigo) = codegen_expr((yyvsp[-2].codigo), MUL, (yyvsp[0].codigo)); }
#line 1540 "src/syn.c"
    break;

  case 49: /* expression: expression DIVIDE expression  */
#line 142 "src/syn.y"
                                                                     { syntax_inform(DIV_EXPR); (yyval.codigo) = codegen_expr((yyvsp[-2].codigo), DIV, (yyvsp[0].codigo)); }
#line 1546 "src/syn.c"
    break;

  case 50: /* expression: MINUS expression  */
#line 143 "src/syn.y"
                                                                      { syntax_inform(UMINUS_EXPR); (yyval.codigo) = codegen_unary(NEG, (yyvsp[0].codigo)); }
#line 1552 "src/syn.c"
    break;

  case 51: /* expression: LOGICAL_NEG expression  */
#line 144 "src/syn.y"
                                                               { syntax_inform(NEG_EXPR); (yyval.codigo) = codegen_unary(NOT, (yyvsp[0].codigo)); }
#line 1558 "src/syn.c"
    break;

  case 52: /* expression: LPARENTHESIS expression RPARENTHESIS  */
#line 145 "src/syn.y"
                                                                             { syntax_inform(PAREN_EXPR); (yyval.codigo) = (yyvsp[-1].codigo); }
#line 1564 "src/syn.c"
    break;

  case 53: /* expression: NUM  */
#line 146 "src/syn.y"
                                            { syntax_inform(NUM_EXPR); (yyval.codigo) = codegen_num((yyvsp[0].lexema)); }
#line 1570 "src/syn.c"
    break;

  case 54: /* expression: ID  */
#line 147 "src/syn.y"
                                           { syntax_inform(ID_EXPR); semantic_inform((yyvsp[0].lexema), USE); (yyval.codigo) = codegen_id((yyvsp[0].lexema)); }
#line 1576 "src/syn.c"
    break;


#line 1580 "src/syn.c"

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

#line 149 "src/syn.y"


void semantic_inform(char *lexema, semantic_action_t action)
{
	switch(action)
	{
		case DECLARATION:
			if (perteneceTablaS(tablaSimbolos, lexema))
			{
				semantic_errors += 1;
				fprintf(error_file, semantic_error_msg[DOUBLE_DECLARATION], yylineno, lexema);
			}
			else
			{
				añadeEntrada(tablaSimbolos, lexema, tipoSemantico, false);
				if (debug_level & WARNINGS)
					fprintf(error_file, semantic_error_msg[WARN_NO_INITIALIZED], yylineno, lexema);
			}
			break;

		case INITIALIZATION:
			if (perteneceTablaS(tablaSimbolos, lexema))
			{
				semantic_errors += 1;
				fprintf(error_file, semantic_error_msg[DOUBLE_DECLARATION], yylineno, lexema);
			}
			else
				añadeEntrada(tablaSimbolos, lexema, tipoSemantico, true);
			
			break;

		case ASSIGNATION:
			if (!perteneceTablaS(tablaSimbolos, lexema))
			{
				semantic_errors += 1;
				fprintf(error_file, semantic_error_msg[UNDECLARED], yylineno, lexema);
			}
			else if (esConstante(tablaSimbolos, lexema))
			{
				semantic_errors += 1;
				fprintf(error_file, semantic_error_msg[CONST_ASSIGN], yylineno, lexema);
			}
			break;

		case USE:
			if (!perteneceTablaS(tablaSimbolos, lexema))
			{
				semantic_errors += 1;
				fprintf(error_file, semantic_error_msg[UNDECLARED], yylineno, lexema);
			}
			break;

		case STRING_SYMBOL:
			if (!perteneceTablaS(tablaSimbolos, lexema))
				añadeEntrada(tablaSimbolos, lexema, CADENA, true);
			
			break;

		default:
			abort();
			break;
	}
}

void semantic_debug(void)
{
	if (debug_level & DBG_SEMANTIC) 
		imprimirTablaS(tablaSimbolos, semantic_file);
}

ListaC codegen_num(char *lexema)
{
	int res = reserva_registro(registros);
	if (res == ERROR)
	{
		codegen_errors += 1;
		fprintf(error_file, REGISTER_EXHAUSTION_ERROR, yylineno);
		free(lexema);
		return NULL;
	}

	ListaC codigo = creaLC();

	Operacion operation = { 
		.op = operation_str[LOAD_INMEDIATE], 
		.res = registros_str[res],
		.arg1 = lexema,
		.arg2 = NULL
	};
	insertaLC(codigo, finalLC(codigo), operation);
	guardaResLC(codigo, res);

	return codigo;
}

ListaC codegen_id(char *lexema)
{
	int res = reserva_registro(registros);
	if (res == ERROR)
	{
		codegen_errors += 1;
		fprintf(error_file, REGISTER_EXHAUSTION_ERROR, yylineno);
		free(lexema);
		return NULL;
	}

	ListaC codigo = creaLC();

	Operacion operation = { 
		.op = operation_str[LOAD_WORD], 
		.res = registros_str[res],
		.arg1 = genera_id(lexema),
		.arg2 = NULL
	};
	insertaLC(codigo, finalLC(codigo), operation);
	guardaResLC(codigo, res);

	free(lexema);
	return codigo;
}

ListaC codegen_expr(ListaC llist, operation_t operacion, ListaC rlist)
{
	if (codegen_errors != 0)
	{
		if (llist != NULL) liberaCompletaLC(llist);
		if (rlist != NULL) liberaCompletaLC(rlist);
		return NULL;
	}

	ListaC codigo = creaLC();

	int llist_res = recuperaResLC(llist);
	int rlist_res = recuperaResLC(rlist);
	 
	concatenaLC(codigo, llist);
	concatenaLC(codigo, rlist);

	Operacion operation;
	operation.res = registros_str[llist_res];
	operation.arg1 = registros_str[llist_res];
	operation.arg2 = registros_str[rlist_res];

	switch(operacion)
	{
		case ADD:
		case SUB:
		case MUL:
		case DIV:
		case SEQ:
		case SGE:
		case SGT:
		case SLE:
		case SLT:
		case SNE:
			operation.op = operation_str[operacion];
			break;

		default:
			abort();
			break;
	}

	insertaLC(codigo, finalLC(codigo), operation);

	guardaResLC(codigo, llist_res);
	libera_registro(registros, rlist_res);

	liberaLC(llist);
	liberaLC(rlist);

	return codigo;	
}

ListaC codegen_unary(operation_t operacion, ListaC list)
{
	if (codegen_errors != 0)
	{
		if (list != NULL) liberaCompletaLC(list);
		return NULL;
	}

	ListaC codigo = creaLC();

	int list_res = recuperaResLC(list);

	concatenaLC(codigo, list);

	Operacion operation;
	operation.res = registros_str[list_res];
	operation.arg1 = registros_str[list_res];
	operation.arg2 = NULL;

	switch(operacion)
	{
		case NEG:
			operation.op=operation_str[NEG];
			break;

		case NOT:
			operation.op=operation_str[NOT];
			operation.arg2=ZERO_REGISTER;
			break;

		default:
			abort();
			break;
	}

	insertaLC(codigo, finalLC(codigo), operation);
	guardaResLC(codigo, list_res);

	liberaLC(list);

	return codigo;
}

ListaC codegen_read(char *lexema)
{
	if (codegen_errors != 0)
	{
		free(lexema);
		return NULL;
	}
	ListaC codigo = creaLC();

	Operacion syscall_load = {
		.op = operation_str[LOAD_INMEDIATE],
		.res = SYSCALL_REGISTER,
		.arg1 = strdup(READ_SYSCALL),
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), syscall_load);

	Operacion syscall = {
		.op = operation_str[SYSCALL],
		.res = NULL,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), syscall);

	Operacion save = {
		.op = operation_str[SAVE_WORD],
		.res = SYSCALL_REGISTER,
		.arg1 = genera_id(lexema),
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), save);

	free(lexema);
	return codigo;
}

ListaC codegen_multiread(ListaC list, char *lexema)
{
	if (codegen_errors != 0)
	{
		if (list != NULL) liberaCompletaLC(list);
		free(lexema);
		return NULL;
	}

	ListaC codigo = list;

	ListaC lectura = codegen_read(lexema);

	concatenaLC(codigo, lectura);

	liberaLC(lectura);

	return codigo;
}

ListaC codegen_print_str(char *lexema)
{
	if (codegen_errors != 0)
	{
		free(lexema);
		return NULL;
	}

	ListaC codigo = creaLC();

	Operacion syscall_load = {
		.op = operation_str[LOAD_INMEDIATE],
		.res = SYSCALL_REGISTER,
		.arg1 = strdup(PRINT_STR_SYSCALL),
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), syscall_load);

	Operacion syscall_arg = {
		.op = operation_str[LOAD_ADDRESS],
		.res = SYSCALL_ARG_REGISTER,
		.arg1 = genera_str(recupera_valor(tablaSimbolos, lexema)),
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), syscall_arg);
	
	Operacion syscall = {
		.op = operation_str[SYSCALL],
		.res = NULL,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), syscall);

	free(lexema);

	return codigo;
}

ListaC codegen_print_num(ListaC list)
{
	if (codegen_errors != 0)
	{
		if (list != NULL) liberaCompletaLC(list);
		return NULL;
	}

	ListaC codigo = list;

	Operacion syscall_load = {
		.op = operation_str[LOAD_INMEDIATE],
		.res = SYSCALL_REGISTER,
		.arg1 = strdup(PRINT_NUM_SYSCALL),
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), syscall_load);

	int list_res = recuperaResLC(list);

	Operacion syscall_arg = {
		.op = operation_str[MOVE],
		.res = SYSCALL_ARG_REGISTER,
		.arg1 = registros_str[list_res],
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), syscall_arg);
	
	Operacion syscall = {
		.op = operation_str[SYSCALL],
		.res = NULL,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), syscall);

	libera_registro(registros, list_res);
	
	return codigo;
}

ListaC codegen_assign(char *lexema, ListaC list)
{
	if (codegen_errors != 0)
	{
		if (list != NULL) liberaCompletaLC(list);
		free(lexema);
		return NULL;
	}

	ListaC codigo = list;

	int list_res = recuperaResLC(list);

	Operacion save = {
		.op = operation_str[SAVE_WORD],
		.res = registros_str[list_res],
		.arg1 = genera_id(lexema),
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), save);

	libera_registro(registros, list_res);

	free(lexema);
	return codigo;
}

ListaC codegen_if(ListaC condition, ListaC statement)
{
	if (codegen_errors != 0)
	{
		if (condition != NULL) liberaCompletaLC(condition);
		if (statement != NULL) liberaCompletaLC(statement);
		return NULL;
	}

	ListaC codigo = condition;

	int list_res = recuperaResLC(condition);

	char *etiqueta_salto = genera_etiqueta();
	char *etiqueta_et_salto = genera_etiqueta_et();

	Operacion comparar = {
		.op = operation_str[BEQZ],
		.res = registros_str[list_res],
		.arg1 = etiqueta_salto,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), comparar);
	concatenaLC(codigo, statement);

	Operacion etiqueta = {
		.op = etiqueta_et_salto,
		.res = NULL,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), etiqueta);

	liberaLC(statement);

	libera_registro(registros, list_res);

	return codigo;
}

ListaC codegen_if_else(ListaC condition, ListaC first_statements, ListaC second_statements)
{
	if (codegen_errors != 0)
	{
		if (condition != NULL) liberaCompletaLC(condition);
		if (first_statements!= NULL) liberaCompletaLC(first_statements);
		if (second_statements != NULL) liberaCompletaLC(second_statements);
		return NULL;
	}

	ListaC codigo = condition;

	int list_res = recuperaResLC(condition);

	char *etiqueta_else = genera_etiqueta();
	char *etiqueta_et_else = genera_etiqueta_et();
	char *etiqueta_fin = genera_etiqueta();
	char *etiqueta_et_fin = genera_etiqueta_et();

	Operacion comparar = {
		.op = operation_str[BEQZ],
		.res = registros_str[list_res],
		.arg1 = etiqueta_else,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), comparar);

	concatenaLC(codigo, first_statements);

	Operacion salto = {
		.op = operation_str[BRANCH],
		.res = etiqueta_fin,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), salto);

	Operacion et_else = {
		.op = etiqueta_et_else,
		.res = NULL,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), et_else);

	concatenaLC(codigo, second_statements);

	Operacion et_fin = {
		.op = etiqueta_et_fin,
		.res = NULL,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), et_fin);

	libera_registro(registros, list_res);

	liberaLC(first_statements);
	liberaLC(second_statements);
	
	return codigo;
}

ListaC codegen_while(ListaC condition, ListaC statement)
{
	if (codegen_errors != 0)
	{
		if (condition != NULL) liberaCompletaLC(condition);
		if (statement!= NULL) liberaCompletaLC(statement);
		return NULL;
	}
	
	ListaC codigo = creaLC();

	int list_res = recuperaResLC(condition);

	char *etiqueta_while = genera_etiqueta();
	char *etiqueta_et_while = genera_etiqueta_et();
	char *etiqueta_fin = genera_etiqueta();
	char *etiqueta_et_fin = genera_etiqueta_et();

	Operacion et_while = {
		.op = etiqueta_et_while,
		.res = NULL,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), et_while);

	concatenaLC(codigo, condition);

	Operacion salto_fin = {
		.op = operation_str[BEQZ],
		.res = registros_str[list_res],
		.arg1 = etiqueta_fin,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), salto_fin);

	concatenaLC(codigo,statement);

	Operacion iterar = {
		.op = operation_str[BRANCH],
		.res = etiqueta_while,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), iterar);

	Operacion et_fin = {
		.op = etiqueta_et_fin,
		.res = NULL,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), et_fin);

	libera_registro(registros, list_res);

	liberaLC(condition);
	liberaLC(statement);

	return codigo;
}

ListaC codegen_do_while(ListaC statements, ListaC condition)
{
	if (codegen_errors != 0)
	{
		if (condition != NULL) liberaCompletaLC(condition);
		if (statements != NULL) liberaCompletaLC(statements);
		return NULL;
	}
	ListaC codigo = creaLC();

	int list_res = recuperaResLC(condition); 

	char *etiqueta_et_while = genera_etiqueta_et();
	char *etiqueta_while = genera_etiqueta();

	Operacion etiqueta = {
		.op = etiqueta_et_while,
		.res = NULL,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), etiqueta);

	concatenaLC(codigo, statements);
	concatenaLC(codigo, condition);

	Operacion salto = {
		.op = operation_str[BNEZ],
		.res = registros_str[list_res],
		.arg1 = etiqueta_while,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), salto);

	libera_registro(registros, list_res);

	liberaLC(statements);
	liberaLC(condition);

	return codigo;
}

ListaC codegen_for(char *lexema, ListaC expresion, ListaC condition, ListaC statements)
{
	if (codegen_errors != 0)
	{
		if (condition != NULL) liberaCompletaLC(condition);
		if (expresion != NULL) liberaCompletaLC(expresion);
		if (statements != NULL) liberaCompletaLC(statements);
		free(lexema);
		return NULL;
	}

	ListaC codigo = expresion;

	int reg_tmp = reserva_registro(registros);
	if (reg_tmp == ERROR)
	{
		codegen_errors += 1;
		fprintf(error_file, REGISTER_EXHAUSTION_ERROR, yylineno);
		liberaCompletaLC(expresion);
		liberaCompletaLC(condition);
		liberaCompletaLC(statements);
		free(lexema);
		return creaLC();
	}


	int expr_res = recuperaResLC(expresion);
	int cond_res = recuperaResLC(condition); 

	char *etiqueta_condition = genera_etiqueta();
	char *etiqueta_et_condition = genera_etiqueta_et();
	char *etiqueta_statement = genera_etiqueta();
	char *etiqueta_et_statement = genera_etiqueta_et();

	Operacion save = {
		.op = operation_str[SAVE_WORD],
		.res = registros_str[expr_res],
		.arg1 = genera_id(lexema),
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), save);

	Operacion salto_comienzo = {
		.op = operation_str[BRANCH],
		.res = etiqueta_condition,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), salto_comienzo);

	Operacion et_estatement = {
		.op = etiqueta_et_statement,
		.res = NULL,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), et_estatement);

	concatenaLC(codigo, statements);

	Operacion carga = {
		.op = operation_str[LOAD_WORD],
		.res = registros_str[reg_tmp],
		.arg1 = genera_id(lexema),
		.arg2 = NULL,
	};
	Operacion incremento = {
		.op = operation_str[ADDI],
		.res = registros_str[reg_tmp],
		.arg1 = registros_str[reg_tmp],
		.arg2 = "1",
	};
	Operacion guarda = {
		.op = operation_str[SAVE_WORD],
		.res = registros_str[reg_tmp],
		.arg1 = genera_id(lexema),
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), carga);
	insertaLC(codigo, finalLC(codigo), incremento);
	insertaLC(codigo, finalLC(codigo), guarda);

	libera_registro(registros, reg_tmp);

	Operacion et_condition = {
		.op = etiqueta_et_condition,
		.res = NULL,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), et_condition);

	concatenaLC(codigo, condition);

	Operacion salto = {
		.op = operation_str[BNEZ],
		.res = registros_str[cond_res],
		.arg1 = etiqueta_statement,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), salto);

	libera_registro(registros, expr_res);
	libera_registro(registros, cond_res);

	liberaLC(condition);
	liberaLC(statements);

	free(lexema);

	return codigo;
}

ListaC codegen_for_extended(char *lexema, ListaC expresion, ListaC condition, ListaC increment, ListaC statements)
{
	if (codegen_errors != 0)
	{
		if (condition != NULL) liberaCompletaLC(condition);
		if (expresion != NULL) liberaCompletaLC(expresion);
		if (increment != NULL) liberaCompletaLC(increment);
		if (statements != NULL) liberaCompletaLC(statements);
		free(lexema);
		return NULL;
	}

	int reg_tmp = reserva_registro(registros);
	if (reg_tmp == ERROR)
	{
		codegen_errors += 1;
		fprintf(error_file, REGISTER_EXHAUSTION_ERROR, yylineno);
		liberaCompletaLC(expresion);
		liberaCompletaLC(condition);
		liberaCompletaLC(increment);
		liberaCompletaLC(statements);
		free(lexema);
		return creaLC();
	}

	ListaC codigo = expresion;

	int expr_res = recuperaResLC(expresion);
	int cond_res = recuperaResLC(condition); 
	int incr_res = recuperaResLC(increment);

	char *etiqueta_condition = genera_etiqueta();
	char *etiqueta_et_condition = genera_etiqueta_et();
	char *etiqueta_statement = genera_etiqueta();
	char *etiqueta_et_statement = genera_etiqueta_et();

	Operacion save = {
		.op = operation_str[SAVE_WORD],
		.res = registros_str[expr_res],
		.arg1 = genera_id(lexema),
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), save);

	Operacion salto_comienzo = {
		.op = operation_str[BRANCH],
		.res = etiqueta_condition,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), salto_comienzo);

	Operacion et_estatement = {
		.op = etiqueta_et_statement,
		.res = NULL,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), et_estatement);

	concatenaLC(codigo, statements);

	concatenaLC(codigo, increment);

	Operacion carga = {
		.op = operation_str[LOAD_WORD],
		.res = registros_str[reg_tmp],
		.arg1 = genera_id(lexema),
		.arg2 = NULL,
	};
	Operacion incremento = {
		.op = operation_str[ADD],
		.res = registros_str[reg_tmp],
		.arg1 = registros_str[reg_tmp],
		.arg2 = registros_str[incr_res],
	};
	Operacion guarda = {
		.op = operation_str[SAVE_WORD],
		.res = registros_str[reg_tmp],
		.arg1 = genera_id(lexema),
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), carga);
	insertaLC(codigo, finalLC(codigo), incremento);
	insertaLC(codigo, finalLC(codigo), guarda);

	Operacion et_condition = {
		.op = etiqueta_et_condition,
		.res = NULL,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), et_condition);

	concatenaLC(codigo, condition);

	Operacion salto = {
		.op = operation_str[BNEZ],
		.res = registros_str[cond_res],
		.arg1 = etiqueta_statement,
		.arg2 = NULL,
	};
	insertaLC(codigo, finalLC(codigo), salto);

	libera_registro(registros, expr_res);
	libera_registro(registros, cond_res);
	libera_registro(registros, incr_res);

	liberaLC(condition);
	liberaLC(increment);
	liberaLC(statements);

	free(lexema);

	return codigo;
}

ListaC codegen_program(ListaC declarations, ListaC statements)
{
	if (codegen_errors != 0)
	{
		if (declarations != NULL) liberaCompletaLC(declarations);
		if (statements != NULL) liberaCompletaLC(statements);
		return NULL;
	}

	ListaC programa = codegen_data();

	Operacion header = {
		.op = CODE_HEADER,
		.res = NULL,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(programa, finalLC(programa), header);

	concatenaLC(programa, declarations);
	concatenaLC(programa, statements);

	liberaLC(declarations);
	liberaLC(statements);

	header.op = END_HEADER;
	header.res = NULL;
	header.arg1 = NULL;
	header.arg2 = NULL;
	insertaLC(programa, finalLC(programa), header);

	Operacion fin = {
		.op = operation_str[LOAD_INMEDIATE],
		.res = SYSCALL_REGISTER,
		.arg1 = strdup(END_SYSCALL),
		.arg2 = NULL,
	};
	insertaLC(programa, finalLC(programa), fin);

	Operacion syscall = {
		.op = operation_str[SYSCALL],
		.res = NULL,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(programa, finalLC(programa), syscall);

	return programa;
}

ListaC codegen_data(void)
{
	ListaC data = creaLC();

	Operacion header = {
		.op = DATA_HEADER,
		.res = NULL,
		.arg1 = NULL,
		.arg2 = NULL,
	};
	insertaLC(data, finalLC(data), header);

	Operacion dato;
	PosicionLista aux = inicioLS(tablaSimbolos)->sig;
	while (aux != NULL)
	{
		if (aux->dato.tipo == CADENA)
		{
			dato.op = genera_etiqueta_str(aux->dato.valor);
			dato.res = NULL;
			dato.arg1 = NULL;
			dato.arg2 = NULL;
			insertaLC(data, finalLC(data), dato);

			dato.op = STR_INSTR;
			dato.res = aux->dato.nombre;
			dato.arg1 = NULL;
			dato.arg2 = NULL;
			insertaLC(data, finalLC(data), dato);
		}

		aux = aux->sig;
	}

	header.op = VARIABLES_SUBHEADER;
	header.res = NULL;
	header.arg1 = NULL;
	header.arg2 = NULL;
	insertaLC(data, finalLC(data), header);

	aux = inicioLS(tablaSimbolos)->sig;
	while (aux != NULL)
	{
		if (aux->dato.tipo != CADENA)
		{
			dato.op = genera_etiqueta_id(aux->dato.nombre);
			dato.res = NULL;
			dato.arg1 = NULL;
			dato.arg2 = NULL;
			insertaLC(data, finalLC(data), dato);

			dato.op = WORD_INSTR;
			dato.res = NULL;
			dato.arg1 = NULL;
			dato.arg2 = NULL;
			insertaLC(data, finalLC(data), dato);
		}
		
		aux = aux->sig;
	}

	return data;
}

void syntax_inform(syntax_reduction_t red)
{
	if (debug_level & DBG_SYNTAX)
		syntax_debug(red);

	switch (red)
	{
		case MULTIPLE_DECLARATION_ERROR:
		case DECLARATION_ERROR:
		case MULTIPLE_PRINT_FORMAT_ERROR:
		case PRINT_FORMAT_ERROR:
		case MULTIPLE_READ_FORMAT_ERROR:
		case READ_FORMAT_ERROR:
			fprintf(error_file, syn_err_msg[red], yylineno);
			break;
	}
}

void syntax_debug(syntax_reduction_t red)
{
	fprintf(syntax_file, "%s", syntax_reduction_msg[red]);
}

void yyerror(const char *s)
{
	syntax_errors += 1;
	fprintf(error_file, "%s!\n",s);
}
