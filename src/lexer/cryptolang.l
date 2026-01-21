%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ts.h"      
#include "y.tab.h"   

int line_number = 1;       
int column_number = 1;     
int error_count = 0;       

void count() {
    column_number += yyleng;
}

void print_header(const char* filename) {
    printf("-------------------------------------------------------------------\n");
    printf(" LEXICAL ANALYSIS : %s\n", filename ? filename : "stdin");
    printf("-------------------------------------------------------------------\n");
}

void print_statistics() {
    printf("-------------------------------------------------------------------\n");
    printf(" Analysis Complete (Lines: %d, Errors: %d)\n", line_number, error_count);
    printf("-------------------------------------------------------------------\n");
}

void yyerror(const char *s); 

%}

%option noyywrap
%option yylineno

DIGIT       [0-9]
HEX         0x[0-9A-Fa-f]+
ID          [a-zA-Z_][a-zA-Z0-9_]*
STRING      \"([^\\\"]|\\.)*\"

%%

\n                      { line_number++; column_number = 1; }
[ \t\r]+                { count(); }

"//".* { count(); }
"#!".* { count(); }
"/*"([^*]|(\*+[^*/]))*\*+"/" { 
    char *p = yytext;
    while (*p) {
        if (*p == '\n') { line_number++; column_number = 1; }
        else column_number++;
        p++;
    }
}

"@protocol"             { count(); return TOKEN_PROTOCOL; }
"@endprotocol"          { count(); return TOKEN_ENDPROTOCOL; }
"@import"               { count(); return TOKEN_IMPORT; }
"@keyspace"             { count(); return TOKEN_KEYSPACE; }
"@main"                 { count(); return TOKEN_MAIN; }

"@loop"                 { count(); return TOKEN_LOOP; }
"@for"                  { count(); return TOKEN_FOR; }
"@rotate"               { count(); return TOKEN_ROTATE; }
"rounds"                { count(); return TOKEN_ROUNDS; }
"step"                  { count(); return TOKEN_STEP; }
"packet"                { count(); return TOKEN_PACKET; }

"bit"                   { count(); return TOKEN_BIT; }
"nibble"                { count(); return TOKEN_NIBBLE; }
"byte"                  { count(); return TOKEN_BYTE; }
"word"                  { count(); return TOKEN_WORD; }
"dword"                 { count(); return TOKEN_DWORD; }
"qword"                 { count(); return TOKEN_QWORD; }

"plain"                 { count(); return TOKEN_PLAIN; }
"cipher"                { count(); return TOKEN_CIPHER; }
"hash"                  { count(); return TOKEN_HASH; }
"key128"                { count(); return TOKEN_KEY128; }
"key256"                { count(); return TOKEN_KEY256; }
"key512"                { count(); return TOKEN_KEY512; }

"::="                   { count(); return TOKEN_SECURE_ASSIGN; }
"::"                    { count(); return TOKEN_DECLARE; }
":="                    { count(); return TOKEN_ASSIGN_LOOP; } 
"?["                    { count(); return TOKEN_IF; }          
":["                    { count(); return TOKEN_ELIF; }        
"->"                    { count(); return TOKEN_OUTPUT; }
"<-"                    { count(); return TOKEN_INPUT; }

"<<<"                   { count(); return TOKEN_ROTATE_LEFT; }
">>>"                   { count(); return TOKEN_ROTATE_RIGHT; }
"<<"                    { count(); return TOKEN_SHIFT_LEFT; }
">>"                    { count(); return TOKEN_SHIFT_RIGHT; }
"&&"                    { count(); return TOKEN_AND; }
"||"                    { count(); return TOKEN_OR; }
"^^"                    { count(); return TOKEN_XOR_LOGIC; }
"**"                    { count(); return TOKEN_POWER; }

"=="                    { count(); return TOKEN_EQ; }
"!="                    { count(); return TOKEN_NEQ; }
"<="                    { count(); return TOKEN_LEQ; }
">="                    { count(); return TOKEN_GEQ; }

"@>"                    { count(); return TOKEN_ENCRYPT; }
"<@"                    { count(); return TOKEN_DECRYPT; }
"#>"                    { count(); return TOKEN_HASH_CALC; }
"@#"                    { count(); return TOKEN_HASH_VERIFY; }
"&>"                    { count(); return TOKEN_SIGN; }
"<&"                    { count(); return TOKEN_VERIFY_SIGN; }

"+"                     { count(); return TOKEN_PLUS; }
"-"                     { count(); return TOKEN_MINUS; }
"*"                     { count(); return TOKEN_MULT; }
"/"                     { count(); return TOKEN_DIV; }
"%"                     { count(); return TOKEN_MOD; }
"="                     { count(); return TOKEN_ASSIGN; }
"<"                     { count(); return TOKEN_LT; }
">"                     { count(); return TOKEN_GT; }
"!"                     { count(); return TOKEN_NOT; }
"&"                     { count(); return TOKEN_BIT_AND; }
"|"                     { count(); return TOKEN_OR; }
"^"                     { count(); return TOKEN_BIT_XOR; }
"~"                     { count(); return TOKEN_BIT_NOT; }

"{"                     { count(); return TOKEN_LBRACE; }
"}"                     { count(); return TOKEN_RBRACE; }
"["                     { count(); return TOKEN_LBRACKET; }
"]"                     { count(); return TOKEN_RBRACKET; }
"("                     { count(); return TOKEN_LPAREN; }
")"                     { count(); return TOKEN_RPAREN; }
";"                     { count(); return TOKEN_SEMICOLON; }
","                     { count(); return TOKEN_COMMA; }
"."                     { count(); return TOKEN_DOT; }
":"                     { count(); return TOKEN_COLON; }

{HEX}                   { 
                          count(); 
                          yylval.sval = strdup(yytext); 
                          return TOKEN_HEX; 
                        }

{DIGIT}+                { 
                          count(); 
                          yylval.ival = atoi(yytext); 
                          return TOKEN_INTEGER; 
                        }

{STRING}                { 
                          count(); 
                          yylval.sval = strdup(yytext); 
                          return TOKEN_STRING; 
                        }

{ID}                    { 
                          count(); 
                          yylval.sval = strdup(yytext); 
                          return TOKEN_IDENTIFIER; 
                        }

.                       { 
                          printf("Lexical Error: Unknown character '%s' at line %d\n", yytext, line_number); 
                          error_count++; 
                        }

%%