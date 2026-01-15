#include "ts.h"

int main() {
    initTable();

    inserer("a", T_BYTE, SYM_VAR, 0);
    inserer("tab", T_BYTE, SYM_ARRAY, 10);

    verifierDeclaration("x");             // erreur
    verifierAffectation("a", T_PLAIN);    // erreur
    verifierTableau("a");                 // erreur
    verifierTableau("tab");               //ok

    afficherTable();
    return 0;
}