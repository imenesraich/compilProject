#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ts.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int line_number;
extern int column_number;
extern int token_count;
extern int error_count;
extern int keyword_count;
extern int identifier_count;
extern int operator_count;
extern int literal_count;
extern int delimiter_count;
extern int comment_count;

void print_header(const char* filename);
void print_statistics();

typedef enum {
    MODE_LEXER_ONLY,    
    MODE_PARSER_ONLY,   
    MODE_FULL           
} CompilationMode;

void print_usage(const char* program_name) {
    printf("Usage: %s [OPTIONS] <fichier.crypt>\n", program_name);
    printf("\nOptions:\n");
    printf("  -l, --lexer      Mode lexer uniquement\n");
    printf("  -p, --parser     Mode parser uniquement\n");
    printf("  -f, --full       Mode compilation complète (défaut)\n");
    printf("  -h, --help       Afficher cette aide\n");
    printf("\nExemples:\n");
    printf("  %s programme.crypt          # Compilation complète\n", program_name);
    printf("  %s -l programme.crypt       # Analyse lexicale seulement\n", program_name);
    printf("  %s -p programme.crypt       # Analyse syntaxique seulement\n", program_name);
}

int main(int argc, char** argv) {
    CompilationMode mode = MODE_FULL;
    char* input_file = NULL;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-l") == 0 || strcmp(argv[i], "--lexer") == 0) {
            mode = MODE_LEXER_ONLY;
        }
        else if (strcmp(argv[i], "-p") == 0 || strcmp(argv[i], "--parser") == 0) {
            mode = MODE_PARSER_ONLY;
        }
        else if (strcmp(argv[i], "-f") == 0 || strcmp(argv[i], "--full") == 0) {
            mode = MODE_FULL;
        }
        else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            print_usage(argv[0]);
            return 0;
        }
        else if (argv[i][0] != '-') {
            input_file = argv[i];
        }
        else {
            fprintf(stderr, "Option inconnue: %s\n", argv[i]);
            print_usage(argv[0]);
            return 1;
        }
    }

    if (input_file) {
        yyin = fopen(input_file, "r");
        if (!yyin) {
            fprintf(stderr, "Erreur: impossible d'ouvrir le fichier '%s'\n", input_file);
            return 1;
        }
    } else {
        fprintf(stderr, "Erreur: aucun fichier d'entrée spécifié\n");
        print_usage(argv[0]);
        return 1;
    }

    initTable();

    int result = 0;

    switch (mode) {
        case MODE_LEXER_ONLY:

            print_header(input_file);

            int token;
            while ((token = yylex()) != 0) {
            }

            print_statistics();
            result = (error_count > 0) ? 1 : 0;
            break;

        case MODE_PARSER_ONLY:
        case MODE_FULL:

            printf("\n");
            printf("===================================================================\n");
            printf("          CRYPTOLANG COMPILER                                     \n");
            printf("===================================================================\n");
            printf(" Mode: %s                                                         \n", 
                   mode == MODE_PARSER_ONLY ? "Parser Only" : "Full Compilation");
            printf(" File: %-54s\n", input_file);
            printf("===================================================================\n");
            printf("\n");

            result = yyparse();

            if (result == 0) {
                printf("\n");
                printf("===================================================================\n");
                printf("  COMPILATION TERMINÉE AVEC SUCCÈS                                \n");
                printf("===================================================================\n");

                printf("\n");
                afficherTable();

                printf("\n");
                printf("===================================================================\n");
                printf("  Statistiques:                                                   \n");
                printf("    - Variables déclarées: %-6d                                   \n", nbSymboles);
                printf("    - Lignes analysées:    %-6d                                   \n", line_number);
                printf("===================================================================\n");
            } else {
                printf("\n");
                printf("===================================================================\n");
                printf("  COMPILATION ÉCHOUÉE                                             \n");
                printf("===================================================================\n");
                printf("  Des erreurs ont été détectées pendant l'analyse.                \n");
                printf("===================================================================\n");
            }
            break;
    }

    if (yyin && yyin != stdin) {
        fclose(yyin);
    }

    return result;
}

