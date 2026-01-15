#include <stdio.h>
#include <stdlib.h>
#include "lexer/tokens.h"

/* Flex lexer declarations */
extern int yylex(void);
extern FILE* yyin;

/* helper functions*/
void print_header(const char* filename);
void print_statistics(void);
void free_token_list(void);

extern int error_count;
extern int line_number;
extern int column_number;

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