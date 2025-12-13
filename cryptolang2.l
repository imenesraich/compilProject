%{


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokens.h"

/* ============================================================================
 * VARIABLES GLOBALES
 * ============================================================================ */

/* Suivi de la position dans le fichier source */
int line_number = 1;           /* Numero de ligne courante */
int column_number = 1;         /* Numero de colonne courante */
int prev_column = 1;           /* Colonne du debut du token courant */

/* Compteurs statistiques */
int token_count = 0;           /* Nombre total de tokens reconnus */
int error_count = 0;           /* Nombre d'erreurs lexicales detectees */
int comment_count = 0;         /* Nombre de commentaires */

/* Compteurs par categorie de tokens */
int keyword_count = 0;         /* Mots-cles */
int identifier_count = 0;      /* Identifiants */
int operator_count = 0;        /* Operateurs */
int literal_count = 0;         /* Litteraux */
int delimiter_count = 0;       /* Delimiteurs */

/* Buffer pour les messages d'erreur */
char error_buffer[256];

/* Mode verbeux pour le debugging */
int verbose_mode = 1;

/* ============================================================================
 * STRUCTURES DE DONNEES
 * ============================================================================ */

/* Structure pour stocker les informations d'un token */
typedef struct {
    int type;
    char* value;
    int line;
    int column;
} Token;

/* Liste chainee pour stocker tous les tokens */
typedef struct TokenNode {
    Token* token;
    struct TokenNode* next;
} TokenNode;

TokenNode* token_list_head = NULL;
TokenNode* token_list_tail = NULL;

/* ============================================================================
 * FONCTIONS UTILITAIRES
 * ============================================================================ */

/* Creer un nouveau token */
Token* create_token(int type, const char* value) {
    Token* token = (Token*)malloc(sizeof(Token));
    if (!token) {
        fprintf(stderr, "Error: Memory allocation failed for token\n");
        exit(1);
    }
    token->type = type;
    token->value = strdup(value);
    token->line = line_number;
    token->column = prev_column;
    return token;
}

/* Ajouter un token a la liste */
void add_token_to_list(Token* token) {
    TokenNode* node = (TokenNode*)malloc(sizeof(TokenNode));
    if (!node) {
        fprintf(stderr, "Error: Memory allocation failed for token node\n");
        exit(1);
    }
    node->token = token;
    node->next = NULL;
    
    if (token_list_tail == NULL) {
        token_list_head = token_list_tail = node;
    } else {
        token_list_tail->next = node;
        token_list_tail = node;
    }
}

/* Obtenir le nom d'un type de token */
const char* get_token_name(int type) {
    switch(type) {
        /* Mots-cles de structure */
        case TOKEN_PROTOCOL:      return "PROTOCOL";
        case TOKEN_ENDPROTOCOL:   return "ENDPROTOCOL";
        case TOKEN_IMPORT:        return "IMPORT";
        case TOKEN_KEYSPACE:      return "KEYSPACE";
        case TOKEN_MAIN:          return "MAIN";
        
        /* Mots-cles de controle */
        case TOKEN_LOOP:          return "LOOP";
        case TOKEN_FOR:           return "FOR";
        case TOKEN_ROTATE:        return "ROTATE";
        case TOKEN_STEP:          return "STEP";
        case TOKEN_ROUNDS:        return "ROUNDS";
        
        /* Types de base */
        case TOKEN_BIT:           return "TYPE_BIT";
        case TOKEN_NIBBLE:        return "TYPE_NIBBLE";
        case TOKEN_BYTE:          return "TYPE_BYTE";
        case TOKEN_WORD:          return "TYPE_WORD";
        case TOKEN_DWORD:         return "TYPE_DWORD";
        case TOKEN_QWORD:         return "TYPE_QWORD";
        
        /* Types cryptographiques */
        case TOKEN_PLAIN:         return "TYPE_PLAIN";
        case TOKEN_CIPHER:        return "TYPE_CIPHER";
        case TOKEN_HASH:          return "TYPE_HASH";
        case TOKEN_KEY128:        return "TYPE_KEY128";
        case TOKEN_KEY256:        return "TYPE_KEY256";
        case TOKEN_KEY512:        return "TYPE_KEY512";
        
        /* Structures */
        case TOKEN_PACKET:        return "PACKET";
        
        /* Operateurs de declaration */
        case TOKEN_DECLARE:       return "DECLARE";
        case TOKEN_ASSIGN:        return "ASSIGN";
        case TOKEN_SECURE_ASSIGN: return "SECURE_ASSIGN";
        
        /* Operateurs conditionnels */
        case TOKEN_IF:            return "IF";
        case TOKEN_ELIF:          return "ELIF";
        case TOKEN_ELSE:          return "ELSE";
        
        /* Operateurs arithmetiques */
        case TOKEN_PLUS:          return "PLUS";
        case TOKEN_MINUS:         return "MINUS";
        case TOKEN_MULT:          return "MULT";
        case TOKEN_DIV:           return "DIV";
        case TOKEN_MOD:           return "MOD";
        case TOKEN_POWER:         return "POWER";
        
        /* Operateurs de comparaison */
        case TOKEN_EQ:            return "EQUAL";
        case TOKEN_NEQ:           return "NOT_EQUAL";
        case TOKEN_LT:            return "LESS_THAN";
        case TOKEN_GT:            return "GREATER_THAN";
        case TOKEN_LEQ:           return "LESS_EQUAL";
        case TOKEN_GEQ:           return "GREATER_EQUAL";
        
        /* Operateurs logiques */
        case TOKEN_AND:           return "LOGICAL_AND";
        case TOKEN_OR:            return "LOGICAL_OR";
        case TOKEN_NOT:           return "LOGICAL_NOT";
        case TOKEN_XOR_LOGIC:     return "LOGICAL_XOR";
        
        /* Operateurs bitwise */
        case TOKEN_BIT_AND:       return "BITWISE_AND";
        case TOKEN_BIT_XOR:       return "BITWISE_XOR";
        case TOKEN_BIT_NOT:       return "BITWISE_NOT";
        case TOKEN_SHIFT_LEFT:    return "SHIFT_LEFT";
        case TOKEN_SHIFT_RIGHT:   return "SHIFT_RIGHT";
	case TOKEN_ROTATE_LEFT:    return "ROTATE_LEFT(<<<)"; // Ajout
        case TOKEN_ROTATE_RIGHT:   return "ROTATE_RIGHT(>>>)"; // Ajout        
        /* Operateurs cryptographiques */
        case TOKEN_ENCRYPT:       return "ENCRYPT";
        case TOKEN_DECRYPT:       return "DECRYPT";
        case TOKEN_HASH_CALC:     return "HASH_CALC";
        case TOKEN_HASH_VERIFY:   return "HASH_VERIFY";
        case TOKEN_SIGN:          return "SIGN";
        case TOKEN_VERIFY_SIGN:   return "VERIFY_SIGN";
        
        /* Entrees/Sorties */
        case TOKEN_OUTPUT:        return "OUTPUT";
        case TOKEN_INPUT:         return "INPUT";
        
        /* Delimiteurs */
        case TOKEN_LBRACE:        return "LBRACE";
        case TOKEN_RBRACE:        return "RBRACE";
        case TOKEN_LBRACKET:      return "LBRACKET";
        case TOKEN_RBRACKET:      return "RBRACKET";
        case TOKEN_LPAREN:        return "LPAREN";
        case TOKEN_RPAREN:        return "RPAREN";
        case TOKEN_SEMICOLON:     return "SEMICOLON";
        case TOKEN_COMMA:         return "COMMA";
        case TOKEN_DOT:           return "DOT";
        case TOKEN_COLON:         return "COLON";
        
        /* Litteraux */
        case TOKEN_IDENTIFIER:    return "IDENTIFIER";
        case TOKEN_INTEGER:       return "INTEGER";
        case TOKEN_HEX:           return "HEXADECIMAL";
        case TOKEN_STRING:        return "STRING";
        
        default:                  return "UNKNOWN";
    }
}

/* Afficher un token */
/* Afficher un token */
/* Afficher un token */
void print_token(int type, const char* value) {
    token_count++;

    /* ==========================================================
     * CATEGORISATION BASÉE SUR LES PLAGES DE TOKENS.H
     * ========================================================== */

    // 1. MOTS-CLÉS (258 à 280)
    if (type >= TOKEN_PROTOCOL && type <= TOKEN_KEY512) {
        keyword_count++;
        printf("[DEBUG] Mots-cles compte: %s\n", get_token_name(type));
    } 
    // 2. OPÉRATEURS COMPLEXES (281 à 304)
    else if (type >= TOKEN_DECLARE && type <= TOKEN_INPUT) {
        operator_count++;
        printf("[DEBUG] Operateurs (Complexes) compte: %s\n", get_token_name(type));
    } 
    // 3. LITTÉRAUX (310 à 313)
    else if (type >= TOKEN_IDENTIFIER && type <= TOKEN_STRING) {
        if (type == TOKEN_IDENTIFIER) {
            identifier_count++;
            printf("[DEBUG] Identifiant compte: %s -> '%s'\n", get_token_name(type), value);
        } else {
            literal_count++;
            printf("[DEBUG] Literal compte: %s -> '%s'\n", get_token_name(type), value);
        }
    } 
    // 4. OPÉRATEURS SIMPLES (ASCII : +, -, =, <, etc.)
    else if (type == TOKEN_PLUS || type == TOKEN_MINUS || type == TOKEN_MULT || 
             type == TOKEN_DIV || type == TOKEN_MOD || type == TOKEN_LT || 
             type == TOKEN_GT || type == TOKEN_NOT || type == TOKEN_BIT_AND || 
             type == TOKEN_BIT_XOR || type == TOKEN_BIT_NOT || type == TOKEN_COLON || 
             type == TOKEN_ASSIGN) { 
        operator_count++;
        printf("[DEBUG] Operateurs (Simples) compte: %s\n", get_token_name(type));
    }
    // 5. DÉLIMITEURS (ASCII : {, }, [, ], (, ), ;, ,, .)
    else if (type == TOKEN_LBRACE || type == TOKEN_RBRACE || type == TOKEN_LBRACKET || 
             type == TOKEN_RBRACKET || type == TOKEN_LPAREN || type == TOKEN_RPAREN || 
             type == TOKEN_SEMICOLON || type == TOKEN_COMMA || type == TOKEN_DOT) {
        delimiter_count++;
        printf("[DEBUG] Delimiteur compte: %s\n", get_token_name(type));
    } else {
        // Cas par défaut si un jeton n'est pas catégorisé (cela ne devrait pas arriver)
        printf("[DEBUG] ATTENTION: Token non categorise: %s\n", get_token_name(type));
    }

    /* ==========================================================
     * AFFICHAGE DÉTAILLÉ (unchangé)
     * ========================================================== */
    if (verbose_mode) {
        printf("Line %3d, Col %3d: %-18s", line_number, prev_column, get_token_name(type));
        
        /* Afficher la valeur pour certains types */
        if (type == TOKEN_IDENTIFIER || type == TOKEN_INTEGER || 
            type == TOKEN_HEX || type == TOKEN_STRING) {
            printf(" -> '%s'", value);
        }
        printf("\n");
    }
    
    /* Creer et stocker le token */
    Token* token = create_token(type, value);
    add_token_to_list(token);
}
void lexical_error(const char* message) {
    error_count++;
    fprintf(stderr, "\n");
    fprintf(stderr, "===================================================================\n");
    fprintf(stderr, " LEXICAL ERROR                                                     \n");
    fprintf(stderr, "===================================================================\n");
    fprintf(stderr, " File: input.crypt                                                 \n");
    fprintf(stderr, " Line: %-3d  Character: %-3d                                       \n", 
            line_number, prev_column);
    fprintf(stderr, " Error: %-54s \n", message);
    fprintf(stderr, "===================================================================\n");
    fprintf(stderr, "\n");
}

/* Mettre a jour la colonne */
void update_column() {
    prev_column = column_number;
    column_number += yyleng;
}

/* Liberer la memoire de la liste de tokens */
void free_token_list() {
    TokenNode* current = token_list_head;
    while (current != NULL) {
        TokenNode* next = current->next;
        free(current->token->value);
        free(current->token);
        free(current);
        current = next;
    }
}

/* Afficher les statistiques detaillees */
void print_statistics() {
    printf("\n");
    printf("===================================================================\n");
    printf("                    ANALYSIS SUMMARY                              \n");
    printf("===================================================================\n");
    printf("                                                                   \n");
    printf("  Total Tokens Recognized:  %-6d                                  \n", token_count);
    printf("                                                                   \n");
    printf("  Token Breakdown:                                                \n");
    printf("    - Keywords:       %-6d                                        \n", keyword_count);
    printf("    - Identifiers:    %-6d                                        \n", identifier_count);
    printf("    - Operators:      %-6d                                        \n", operator_count);
    printf("    - Literals:       %-6d                                        \n", literal_count);
    printf("    - Delimiters:     %-6d                                        \n", delimiter_count);
    printf("    - Comments:       %-6d                                        \n", comment_count);
    printf("                                                                   \n");
    printf("  Lexical Errors:       %-6d                                      \n", error_count);
    printf("                                                                   \n");
    if (error_count == 0) {
        printf("  Status: SUCCESS - Lexical analysis completed successfully!    \n");
    } else {
        printf("  Status: ERROR - Lexical analysis completed with errors.       \n");
    }
    printf("                                                                   \n");
    printf("===================================================================\n");
}

/* Afficher le header */
void print_header(const char* filename) {
    printf("\n");
    printf("===================================================================\n");
    printf("          CRYPTOLANG LEXICAL ANALYZER (FLEX)                      \n");
    printf("===================================================================\n");
    printf(" Project:  Compilateur CryptoLang                                 \n");
    printf(" Version:  1.0.0                                                  \n");
    printf(" Authors:  Hamadache, Allag, Foudili, Rabia                       \n");
    printf(" File:     %-51s\n", filename ? filename : "stdin");
    printf("===================================================================\n");
    printf("\n");
    printf("-------------------------------------------------------------------\n");
    printf("                      TOKEN ANALYSIS                              \n");
    printf("-------------------------------------------------------------------\n");
}

%}

/* ============================================================================
 * DEFINITIONS DE MOTIFS
 * ============================================================================ */

DIGIT           [0-9]
HEXDIGIT        [0-9A-Fa-f]
LETTER          [a-zA-Z_]
ALPHANUM        [a-zA-Z0-9_]
WHITESPACE      [ \t\r]
NEWLINE         \n

/* ============================================================================
 * OPTIONS FLEX
 * ============================================================================ */

%option noyywrap
%option yylineno

%%
"//".*                      { 
                                comment_count++;
                                update_column(); 
                            }

"/*"                        {
                                comment_count++;
                                update_column();
                                int c;
                                int start_line = line_number;
                                int start_col = prev_column;
                                
                                while (1) {
                                    c = input();
                                    if (c == EOF) {
                                        sprintf(error_buffer, 
                                                "unterminated comment starting at line %d, column %d",
                                                start_line, start_col);
                                        lexical_error(error_buffer);
                                        break;
                                    }
                                    if (c == '\n') {
                                        line_number++;
                                        column_number = 1;
                                    } else {
                                        column_number++;
                                    }
                                    if (c == '*') {
                                        c = input();
                                        if (c == '/') {
                                            column_number++;
                                            break;
                                        }
                                        unput(c);
                                    }
                                }
                            }

"#!".*                      { 
                                comment_count++;
                                update_column(); 
                            }

    /* =====================================================================
     * MOTS-CLES DE STRUCTURE
     * ===================================================================== */

"@protocol"                 { update_column(); print_token(TOKEN_PROTOCOL, yytext); return TOKEN_PROTOCOL; }
"@endprotocol"              { update_column(); print_token(TOKEN_ENDPROTOCOL, yytext); return TOKEN_ENDPROTOCOL; }
"@import"                   { update_column(); print_token(TOKEN_IMPORT, yytext); return TOKEN_IMPORT; }
"@keyspace"                 { update_column(); print_token(TOKEN_KEYSPACE, yytext); return TOKEN_KEYSPACE; }
"@main"                     { update_column(); print_token(TOKEN_MAIN, yytext); return TOKEN_MAIN; }

    /* =====================================================================
     * MOTS-CLES DE CONTROLE
     * ===================================================================== */

"@loop"                     { update_column(); print_token(TOKEN_LOOP, yytext); return TOKEN_LOOP; }
"@for"                      { update_column(); print_token(TOKEN_FOR, yytext); return TOKEN_FOR; }
"@rotate"                   { update_column(); print_token(TOKEN_ROTATE, yytext); return TOKEN_ROTATE; }
"step"                      { update_column(); print_token(TOKEN_STEP, yytext); return TOKEN_STEP; }
"rounds"                    { update_column(); print_token(TOKEN_ROUNDS, yytext); return TOKEN_ROUNDS; }

    /* =====================================================================
     * TYPES DE BASE
     * ===================================================================== */

"bit"                       { update_column(); print_token(TOKEN_BIT, yytext); return TOKEN_BIT; }
"nibble"                    { update_column(); print_token(TOKEN_NIBBLE, yytext); return TOKEN_NIBBLE; }
"byte"                      { update_column(); print_token(TOKEN_BYTE, yytext); return TOKEN_BYTE; }
"word"                      { update_column(); print_token(TOKEN_WORD, yytext); return TOKEN_WORD; }
"dword"                     { update_column(); print_token(TOKEN_DWORD, yytext); return TOKEN_DWORD; }
"qword"                     { update_column(); print_token(TOKEN_QWORD, yytext); return TOKEN_QWORD; }

    /* =====================================================================
     * TYPES CRYPTOGRAPHIQUES
     * ===================================================================== */

"plain"                     { update_column(); print_token(TOKEN_PLAIN, yytext); return TOKEN_PLAIN; }
"cipher"                    { update_column(); print_token(TOKEN_CIPHER, yytext); return TOKEN_CIPHER; }
"hash"                      { update_column(); print_token(TOKEN_HASH, yytext); return TOKEN_HASH; }
"key128"                    { update_column(); print_token(TOKEN_KEY128, yytext); return TOKEN_KEY128; }
"key256"                    { update_column(); print_token(TOKEN_KEY256, yytext); return TOKEN_KEY256; }
"key512"                    { update_column(); print_token(TOKEN_KEY512, yytext); return TOKEN_KEY512; }

    /* =====================================================================
     * STRUCTURES
     * ===================================================================== */

"packet"                    { update_column(); print_token(TOKEN_PACKET, yytext); return TOKEN_PACKET; }

    /* =====================================================================
     * OPERATEURS SPECIAUX (ordre important!)
     * ===================================================================== */

"::="                       { update_column(); print_token(TOKEN_SECURE_ASSIGN, yytext); return TOKEN_SECURE_ASSIGN; }
"::"                        { update_column(); print_token(TOKEN_DECLARE, yytext); return TOKEN_DECLARE; }
"?["                        { update_column(); print_token(TOKEN_IF, yytext); return TOKEN_IF; }
":["                        { update_column(); print_token(TOKEN_ELIF, yytext); return TOKEN_ELIF; }

    /* =====================================================================
     * OPERATEURS CRYPTOGRAPHIQUES
     * ===================================================================== */

"@>"                        { update_column(); print_token(TOKEN_ENCRYPT, yytext); return TOKEN_ENCRYPT; }
"<@"                        { update_column(); print_token(TOKEN_DECRYPT, yytext); return TOKEN_DECRYPT; }
"#>"                        { update_column(); print_token(TOKEN_HASH_CALC, yytext); return TOKEN_HASH_CALC; }
"@#"                        { update_column(); print_token(TOKEN_HASH_VERIFY, yytext); return TOKEN_HASH_VERIFY; }
"&>"                        { update_column(); print_token(TOKEN_SIGN, yytext); return TOKEN_SIGN; }
"<&"                        { update_column(); print_token(TOKEN_VERIFY_SIGN, yytext); return TOKEN_VERIFY_SIGN; }
    /* =====================================================================
     * OPERATEURS COMPOSES
     * ===================================================================== */

"**"                        { update_column(); print_token(TOKEN_POWER, yytext); return TOKEN_POWER; }
"=="                        { update_column(); print_token(TOKEN_EQ, yytext); return TOKEN_EQ; }
"!="                        { update_column(); print_token(TOKEN_NEQ, yytext); return TOKEN_NEQ; }
"<="                        { update_column(); print_token(TOKEN_LEQ, yytext); return TOKEN_LEQ; }
">="                        { update_column(); print_token(TOKEN_GEQ, yytext); return TOKEN_GEQ; }
"&&"                        { update_column(); print_token(TOKEN_AND, yytext); return TOKEN_AND; }
"||"                        { update_column(); print_token(TOKEN_OR, yytext); return TOKEN_OR; }
"^^"                        { update_column(); print_token(TOKEN_XOR_LOGIC, yytext); return TOKEN_XOR_LOGIC; }
"<<"                        { update_column(); print_token(TOKEN_SHIFT_LEFT, yytext); return TOKEN_SHIFT_LEFT; }
">>"                        { update_column(); print_token(TOKEN_SHIFT_RIGHT, yytext); return TOKEN_SHIFT_RIGHT; }
"->"                        { update_column(); print_token(TOKEN_OUTPUT, yytext); return TOKEN_OUTPUT; }
"<-"                        { update_column(); print_token(TOKEN_INPUT, yytext); return TOKEN_INPUT; }
"<<<"                          { update_column(); print_token(TOKEN_ROTATE_LEFT, yytext); return TOKEN_ROTATE_LEFT; }
">>>"                          { update_column(); print_token(TOKEN_ROTATE_RIGHT, yytext); return TOKEN_ROTATE_RIGHT; }
    /* =====================================================================
     * OPERATEURS SIMPLES
     * ===================================================================== */

"+"                         { update_column(); print_token(TOKEN_PLUS, yytext); return TOKEN_PLUS; }
"-"                         { update_column(); print_token(TOKEN_MINUS, yytext); return TOKEN_MINUS; }
"*"                         { update_column(); print_token(TOKEN_MULT, yytext); return TOKEN_MULT; }
"/"                         { update_column(); print_token(TOKEN_DIV, yytext); return TOKEN_DIV; }
"%"                         { update_column(); print_token(TOKEN_MOD, yytext); return TOKEN_MOD; }
"="                         { update_column(); print_token(TOKEN_ASSIGN, yytext); return TOKEN_ASSIGN; }
"<"                         { update_column(); print_token(TOKEN_LT, yytext); return TOKEN_LT; }
">"                         { update_column(); print_token(TOKEN_GT, yytext); return TOKEN_GT; }
"!"                         { update_column(); print_token(TOKEN_NOT, yytext); return TOKEN_NOT; }
"&"                         { update_column(); print_token(TOKEN_BIT_AND, yytext); return TOKEN_BIT_AND; }
"^"                         { update_column(); print_token(TOKEN_BIT_XOR, yytext); return TOKEN_BIT_XOR; }
"~"                         { update_column(); print_token(TOKEN_BIT_NOT, yytext); return TOKEN_BIT_NOT; }

    /* =====================================================================
     * DELIMITEURS
     * ===================================================================== */

"{"                         { update_column(); print_token(TOKEN_LBRACE, yytext); return TOKEN_LBRACE; }
"}"                         { update_column(); print_token(TOKEN_RBRACE, yytext); return TOKEN_RBRACE; }
"["                         { update_column(); print_token(TOKEN_LBRACKET, yytext); return TOKEN_LBRACKET; }
"]"                         { update_column(); print_token(TOKEN_RBRACKET, yytext); return TOKEN_RBRACKET; }
"("                         { update_column(); print_token(TOKEN_LPAREN, yytext); return TOKEN_LPAREN; }
")"                         { update_column(); print_token(TOKEN_RPAREN, yytext); return TOKEN_RPAREN; }
";"                         { update_column(); print_token(TOKEN_SEMICOLON, yytext); return TOKEN_SEMICOLON; }
","                         { update_column(); print_token(TOKEN_COMMA, yytext); return TOKEN_COMMA; }
"."                         { update_column(); print_token(TOKEN_DOT, yytext); return TOKEN_DOT; }
":"                         { update_column(); print_token(TOKEN_COLON, yytext); return TOKEN_COLON; }

    /* =====================================================================
     * LITTERAUX
     * ===================================================================== */

"0x"{HEXDIGIT}+             { 
                                update_column(); 
                                if (yyleng > 66) {
                                    lexical_error("hexadecimal literal too long");
                                }
                                print_token(TOKEN_HEX, yytext); 
                                return TOKEN_HEX; 
                            }

{DIGIT}+                    { 
                                update_column(); 
                                if (yyleng > 20) {
                                    lexical_error("integer literal too long");
                                }
                                print_token(TOKEN_INTEGER, yytext); 
                                return TOKEN_INTEGER; 
                            }

\"([^\\\"\n]|\\.)*\"        { 
                                update_column(); 
                                print_token(TOKEN_STRING, yytext); 
                                return TOKEN_STRING; 
                            }

    /* =====================================================================
     * IDENTIFIANTS
     * ===================================================================== */

{LETTER}{ALPHANUM}*         { 
                                update_column(); 
                                if (yyleng > 255) {
                                    lexical_error("identifier too long (max 255 characters)");
                                }
                                print_token(TOKEN_IDENTIFIER, yytext); 
                                return TOKEN_IDENTIFIER; 
                            }

    /* =====================================================================
     * ESPACES BLANCS
     * ===================================================================== */

{WHITESPACE}+               { update_column(); }
{NEWLINE}                   { line_number++; column_number = 1; }

    /* =====================================================================
     * ERREURS
     * ===================================================================== */

\"([^\\\"\n]|\\.)*          { 
                                update_column(); 
                                lexical_error("unterminated string literal");
                            }

.                           { 
                                sprintf(error_buffer, 
                                        "unrecognized character '%c' (ASCII: %d)", 
                                        yytext[0], (unsigned char)yytext[0]);
                                update_column();
                                lexical_error(error_buffer);
                            }

%%

/* ============================================================================
 * FONCTION PRINCIPALE
 * ============================================================================ */

int main(int argc, char** argv) {
    FILE* input_file = NULL;
    char* filename = NULL;
    
    if (argc > 1) {
        filename = argv[1];
        input_file = fopen(filename, "r");
        if (!input_file) {
            fprintf(stderr, "Error: Cannot open file '%s'\n", filename);
            fprintf(stderr, "Usage: %s [input_file.crypt]\n", argv[0]);
            return 1;
        }
        yyin = input_file;
    } else {
        filename = "stdin";
        yyin = stdin;
    }
    
    print_header(filename);
    
    while(yylex() != 0);
    
    print_statistics();
    
    if (input_file) {
        fclose(input_file);
    }
    free_token_list();
    
    return (error_count > 0) ? 1 : 0;
}
