#ifndef TS_H
#define TS_H

#include <stdio.h>
#include <string.h>

#define MAX_SYMBOLES 1000
#define TAILLE_ID 50

/* ================= TYPES DU LANGAGE ================= */

typedef enum {
    T_BIT,
    T_NIBBLE,
    T_BYTE,
    T_WORD,
    T_DWORD,
    T_QWORD,
    T_PLAIN,
    T_CIPHER,
    T_HASH,
    T_KEY128,
    T_KEY256,
    T_KEY512,
    T_PACKET
} TypeCL;

/* ================= NATURE DU SYMBOLE ================= */

typedef enum {
    SYM_VAR,         // variable simple
    SYM_ARRAY,       // tableau
    SYM_PACKET,      // structure
    SYM_FIELD        // champ de structure
} NatureCL;

/* ================= SYMBOLE ================= */

typedef struct {
    char nom[TAILLE_ID];
    TypeCL type;
    NatureCL nature;
    int taille;          // pour les tableaux
} Symbole;

/* ================= TABLE ================= */

extern Symbole table[MAX_SYMBOLES];
extern int nbSymboles;

/* ================= FONCTIONS ================= */

void initTable();
int rechercher(char *nom);
int inserer(char *nom, TypeCL type, NatureCL nature, int taille);
void afficherTable();
const char* typeToString(TypeCL type);
const char* natureToString(NatureCL nature);
int verifierDeclaration(char *nom);
TypeCL getType(char *nom);
int verifierAffectation(char *nom, TypeCL typeExpr);
int verifierTableau(char *nom);

#endif