#include "ts.h"

Symbole table[MAX_SYMBOLES];
int nbSymboles = 0;

/* Initialisation */
void initTable() {
    nbSymboles = 0;
}

/* Recherche d’un identificateur */
int rechercher(char *nom) {
    for (int i = 0; i < nbSymboles; i++) {
        if (strcmp(table[i].nom, nom) == 0)
            return i;
    }
    return -1;
}

/* Insertion avec détection de double déclaration */
int inserer(char *nom, TypeCL type, NatureCL nature, int taille) {
    if (rechercher(nom) != -1) {
        printf("Erreur sémantique : double déclaration de '%s'\n", nom);
        return -1;
    }

    strcpy(table[nbSymboles].nom, nom);
    table[nbSymboles].type = type;
    table[nbSymboles].nature = nature;
    table[nbSymboles].taille = taille;

    nbSymboles++;
    return 0;
}

/* Conversion type vers string */
const char* typeToString(TypeCL type) {
    switch (type) {
        case T_BIT: return "bit";
        case T_NIBBLE: return "nibble";
        case T_BYTE: return "byte";
        case T_WORD: return "word";
        case T_DWORD: return "dword";
        case T_QWORD: return "qword";
        case T_PLAIN: return "plain";
        case T_CIPHER: return "cipher";
        case T_HASH: return "hash";
        case T_KEY128: return "key128";
        case T_KEY256: return "key256";
        case T_KEY512: return "key512";
        case T_PACKET: return "packet";
        default: return "unknown";
    }
}

/* Conversion nature vers string */
const char* natureToString(NatureCL nature) {
    switch (nature) {
        case SYM_VAR: return "variable";
        case SYM_ARRAY: return "array";
        case SYM_PACKET: return "packet";
        case SYM_FIELD: return "field";
        default: return "unknown";
    }
}

/* Affichage */
void afficherTable() {
    printf("\n========== TABLE DES SYMBOLES ==========\n");
    printf("%-20s %-10s %-10s %-10s\n", "Nom", "Type", "Nature", "Taille");

    for (int i = 0; i < nbSymboles; i++) {
        printf("%-20s %-10s %-10s %-10d\n",
               table[i].nom,
               typeToString(table[i].type),
               natureToString(table[i].nature),
               table[i].taille);
    }
}

/* Vérifier la déclaration */ 
int verifierDeclaration(char *nom) {
    if (rechercher(nom) == -1) {
        printf("Erreur sémantique : variable '%s' non déclarée\n", nom);
        return 0;
    }
    return 1;
}

TypeCL getType(char *nom) {
    int pos = rechercher(nom);
    if (pos == -1)
        return -1;
    return table[pos].type;
}

/* Vérifier l'affectation */
int verifierAffectation(char *nom, TypeCL typeExpr) {
    int pos = rechercher(nom);

    if (pos == -1) {
        printf("Erreur sémantique : variable '%s' non déclarée\n", nom);
        return 0;
    }

    if (table[pos].type != typeExpr) {
        printf("Erreur sémantique : incompatibilité de types (%s ← %s)\n",
               typeToString(table[pos].type),
               typeToString(typeExpr));
        return 0;
    }

    return 1;
}

/* Vérifier l'usage du tableau */
int verifierTableau(char *nom) {
    int pos = rechercher(nom);

    if (pos == -1) {
        printf("Erreur sémantique : '%s' non déclaré\n", nom);
        return 0;
    }

    if (table[pos].nature != SYM_ARRAY) {
        printf("Erreur sémantique : '%s' n’est pas un tableau\n", nom);
        return 0;
    }

    return 1;
}