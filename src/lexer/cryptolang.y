%{
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
%}

%union {
    int ival;
    char* sval;
    int type; 
}

%token <sval> TOKEN_IDENTIFIER TOKEN_STRING TOKEN_HEX
%token <ival> TOKEN_INTEGER

%token TOKEN_PROTOCOL TOKEN_ENDPROTOCOL TOKEN_IMPORT TOKEN_KEYSPACE TOKEN_MAIN
%token TOKEN_LOOP TOKEN_FOR TOKEN_ROTATE TOKEN_ROUNDS TOKEN_STEP TOKEN_PACKET

%token TOKEN_BIT TOKEN_NIBBLE TOKEN_BYTE TOKEN_WORD TOKEN_DWORD TOKEN_QWORD
%token TOKEN_PLAIN TOKEN_CIPHER TOKEN_HASH TOKEN_KEY128 TOKEN_KEY256 TOKEN_KEY512

%token TOKEN_SECURE_ASSIGN TOKEN_DECLARE TOKEN_ASSIGN_LOOP
%token TOKEN_IF TOKEN_ELIF TOKEN_OUTPUT TOKEN_INPUT

%token TOKEN_PLUS TOKEN_MINUS TOKEN_MULT TOKEN_DIV TOKEN_MOD TOKEN_ASSIGN
%token TOKEN_EQ TOKEN_NEQ TOKEN_LT TOKEN_GT TOKEN_LEQ TOKEN_GEQ
%token TOKEN_AND TOKEN_OR TOKEN_XOR_LOGIC TOKEN_NOT TOKEN_POWER
%token TOKEN_BIT_AND TOKEN_BIT_OR TOKEN_BIT_XOR TOKEN_BIT_NOT
%token TOKEN_ROTATE_LEFT TOKEN_ROTATE_RIGHT TOKEN_SHIFT_LEFT TOKEN_SHIFT_RIGHT

%token TOKEN_ENCRYPT TOKEN_DECRYPT TOKEN_HASH_CALC TOKEN_HASH_VERIFY TOKEN_SIGN TOKEN_VERIFY_SIGN

%token TOKEN_LBRACE TOKEN_RBRACE TOKEN_LBRACKET TOKEN_RBRACKET
%token TOKEN_LPAREN TOKEN_RPAREN TOKEN_SEMICOLON TOKEN_COMMA TOKEN_DOT TOKEN_COLON

%right TOKEN_ASSIGN TOKEN_SECURE_ASSIGN
%right TOKEN_ENCRYPT TOKEN_DECRYPT TOKEN_HASH_CALC TOKEN_HASH_VERIFY TOKEN_SIGN TOKEN_VERIFY_SIGN
%left TOKEN_XOR_LOGIC
%left TOKEN_AND
%left TOKEN_OR
%left TOKEN_EQ TOKEN_NEQ
%left TOKEN_LT TOKEN_GT TOKEN_LEQ TOKEN_GEQ
%left TOKEN_BIT_XOR
%left TOKEN_BIT_AND TOKEN_BIT_OR
%left TOKEN_SHIFT_LEFT TOKEN_SHIFT_RIGHT TOKEN_ROTATE_LEFT TOKEN_ROTATE_RIGHT
%left TOKEN_PLUS TOKEN_MINUS
%left TOKEN_MULT TOKEN_DIV TOKEN_MOD
%right TOKEN_NOT TOKEN_BIT_NOT
%right TOKEN_POWER
%left TOKEN_LPAREN TOKEN_RPAREN TOKEN_LBRACKET TOKEN_RBRACKET TOKEN_DOT

%type <type> type_name

%%

program:
    TOKEN_PROTOCOL TOKEN_IDENTIFIER imports keyspace_block struct_definitions main_block TOKEN_ENDPROTOCOL
    { 
        printf("\n===================================================================\n");
        printf("  COMPILATION SUCCESS\n");
        printf("===================================================================\n");
        afficherTable();
    }
    ;

imports:
    | imports TOKEN_IMPORT TOKEN_IDENTIFIER TOKEN_DOT TOKEN_IDENTIFIER
    | imports TOKEN_IMPORT TOKEN_IDENTIFIER
    ;

keyspace_block:
    TOKEN_KEYSPACE TOKEN_LBRACE global_declarations TOKEN_RBRACE
    ;

global_declarations:
    | global_declarations global_declaration
    ;

global_declaration:
    variable_declaration
    | packet_definition
    ;

variable_declaration:

    type_name TOKEN_DECLARE TOKEN_IDENTIFIER TOKEN_ASSIGN expression TOKEN_SEMICOLON
    { 
        inserer($3, $1, SYM_VAR, 1);
        printf("[PARSER] Global Var: %s initialized\n", $3); 
    }

    | type_name TOKEN_DECLARE TOKEN_IDENTIFIER TOKEN_SEMICOLON
    { 
        inserer($3, $1, SYM_VAR, 1);
        printf("[PARSER] Global Var: %s\n", $3); 
    }

    | type_name TOKEN_LBRACKET TOKEN_INTEGER TOKEN_RBRACKET TOKEN_DECLARE TOKEN_IDENTIFIER TOKEN_SEMICOLON
    { 
        inserer($6, $1, SYM_ARRAY, $3);
        printf("[PARSER] Global Array: %s[%d]\n", $6, $3); 
    }
    | TOKEN_IDENTIFIER TOKEN_DECLARE TOKEN_IDENTIFIER TOKEN_SEMICOLON
    { 
        inserer($3, T_PLAIN, SYM_VAR, 1); 
        printf("[PARSER] Struct Instance: %s (Type: %s)\n", $3, $1); 
    }
    | TOKEN_IDENTIFIER TOKEN_LBRACKET TOKEN_INTEGER TOKEN_RBRACKET TOKEN_DECLARE TOKEN_IDENTIFIER TOKEN_SEMICOLON
    { 
        inserer($6, T_PLAIN, SYM_ARRAY, $3);
        printf("[PARSER] Struct Array: %s[%d]\n", $6, $3); 
    }
    ;

packet_definition:
    TOKEN_PACKET TOKEN_IDENTIFIER TOKEN_LBRACE struct_fields TOKEN_RBRACE TOKEN_SEMICOLON
    { printf("[PARSER] Packet Definition: %s\n", $2); }
    ;

struct_fields:
    | struct_fields type_name TOKEN_DECLARE TOKEN_IDENTIFIER TOKEN_SEMICOLON
    | struct_fields type_name TOKEN_LBRACKET TOKEN_INTEGER TOKEN_RBRACKET TOKEN_DECLARE TOKEN_IDENTIFIER TOKEN_SEMICOLON
    ;
struct_definitions:

    | struct_definitions packet_definition
    ;
type_name:
      TOKEN_BIT    { $$ = T_BIT; }
    | TOKEN_NIBBLE { $$ = T_NIBBLE; }
    | TOKEN_BYTE   { $$ = T_BYTE; }
    | TOKEN_WORD   { $$ = T_WORD; }
    | TOKEN_DWORD  { $$ = T_DWORD; }
    | TOKEN_QWORD  { $$ = T_QWORD; }
    | TOKEN_PLAIN  { $$ = T_PLAIN; }
    | TOKEN_CIPHER { $$ = T_CIPHER; }
    | TOKEN_HASH   { $$ = T_HASH; }
    | TOKEN_KEY128 { $$ = T_KEY128; }
    | TOKEN_KEY256 { $$ = T_KEY256; }
    | TOKEN_KEY512 { $$ = T_KEY512; }
    ;

main_block:
    TOKEN_MAIN block
    ;

block:
    TOKEN_LBRACE instructions TOKEN_RBRACE
    ;

instructions:
    | instructions instruction
    ;

instruction:
    variable_declaration 
    | assignment
    | io_statement
    | control_structure
    | expression TOKEN_SEMICOLON
    ;

assignment:
    lvalue TOKEN_ASSIGN expression TOKEN_SEMICOLON
    | lvalue TOKEN_SECURE_ASSIGN expression TOKEN_SEMICOLON
    ;

lvalue:
    TOKEN_IDENTIFIER
    | TOKEN_IDENTIFIER TOKEN_LBRACKET expression TOKEN_RBRACKET
    | TOKEN_IDENTIFIER TOKEN_DOT TOKEN_IDENTIFIER
    | TOKEN_IDENTIFIER TOKEN_DOT TOKEN_IDENTIFIER TOKEN_LBRACKET expression TOKEN_RBRACKET
    ;

io_statement:
    TOKEN_OUTPUT expression TOKEN_SEMICOLON
    | TOKEN_INPUT lvalue TOKEN_SEMICOLON
    | lvalue TOKEN_OUTPUT expression TOKEN_SEMICOLON
    | lvalue TOKEN_INPUT expression TOKEN_SEMICOLON
    ;

control_structure:
    if_statement
    | loop_statement
    ;

if_statement:
    TOKEN_IF expression TOKEN_RBRACKET block else_part
    ;

else_part:
    | TOKEN_DECLARE block
    | TOKEN_ELIF expression TOKEN_RBRACKET block else_part
    ;

loop_statement:
    TOKEN_LOOP TOKEN_LBRACKET expression TOKEN_RBRACKET block
    { printf("[PARSER] Loop: WHILE\n"); }
    | TOKEN_FOR TOKEN_LBRACKET TOKEN_IDENTIFIER TOKEN_ASSIGN_LOOP expression TOKEN_OUTPUT expression TOKEN_COLON TOKEN_STEP expression TOKEN_RBRACKET block
    { 

        inserer($3, T_DWORD, SYM_VAR, 1); 
        printf("[PARSER] Loop: FOR (Explicit Step)\n"); 
    }
    | TOKEN_FOR TOKEN_LBRACKET TOKEN_IDENTIFIER TOKEN_ASSIGN_LOOP expression TOKEN_OUTPUT expression TOKEN_STEP expression TOKEN_RBRACKET block
    { 
        inserer($3, T_DWORD, SYM_VAR, 1);
        printf("[PARSER] Loop: FOR (No Colon Step)\n"); 
    }
    | TOKEN_FOR TOKEN_LBRACKET TOKEN_IDENTIFIER TOKEN_ASSIGN_LOOP expression TOKEN_OUTPUT expression TOKEN_RBRACKET block
    { 
        inserer($3, T_DWORD, SYM_VAR, 1);
        printf("[PARSER] Loop: FOR (Default Step)\n"); 
    }
    | TOKEN_ROTATE TOKEN_LBRACKET expression TOKEN_ROUNDS TOKEN_RBRACKET block
    { printf("[PARSER] Loop: ROTATE\n"); }
    ;

expression:
    term
    | expression TOKEN_PLUS expression
    | expression TOKEN_MINUS expression
    | expression TOKEN_MULT expression
    | expression TOKEN_DIV expression
    | expression TOKEN_MOD expression
    | expression TOKEN_POWER expression
    | expression TOKEN_EQ expression
    | expression TOKEN_NEQ expression
    | expression TOKEN_LT expression
    | expression TOKEN_GT expression
    | expression TOKEN_LEQ expression
    | expression TOKEN_GEQ expression
    | expression TOKEN_AND expression
    | expression TOKEN_OR expression
    | expression TOKEN_XOR_LOGIC expression
    | TOKEN_NOT expression
    | expression TOKEN_BIT_AND expression
    | expression TOKEN_BIT_OR expression
    | expression TOKEN_BIT_XOR expression
    | TOKEN_BIT_NOT expression
    | expression TOKEN_SHIFT_LEFT expression
    | expression TOKEN_SHIFT_RIGHT expression
    | expression TOKEN_ROTATE_LEFT expression
    | expression TOKEN_ROTATE_RIGHT expression
    | expression TOKEN_ENCRYPT expression
    | expression TOKEN_DECRYPT expression
    | expression TOKEN_HASH_CALC
    | expression TOKEN_HASH_VERIFY expression
    | expression TOKEN_SIGN expression
    | expression TOKEN_VERIFY_SIGN expression
    ;

term:
    TOKEN_IDENTIFIER
    | TOKEN_INTEGER
    | TOKEN_HEX
    | TOKEN_STRING
    | TOKEN_LPAREN expression TOKEN_RPAREN
    | TOKEN_IDENTIFIER TOKEN_LBRACKET expression TOKEN_RBRACKET
    | TOKEN_IDENTIFIER TOKEN_DOT TOKEN_IDENTIFIER
    | TOKEN_IDENTIFIER TOKEN_DOT TOKEN_IDENTIFIER TOKEN_LBRACKET expression TOKEN_RBRACKET
    | TOKEN_IDENTIFIER TOKEN_LPAREN argument_list TOKEN_RPAREN
    ;

argument_list:
    | expression
    | argument_list TOKEN_COMMA expression
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error: %s at Line %d\n", s, line_number);
    error_count++;
}