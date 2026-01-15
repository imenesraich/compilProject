#include "ts.h"

int main() {
    initTable();

    inserer("flag", T_BIT, SYM_VAR, 1);
    inserer("message", T_PLAIN, SYM_VAR, 0);
    inserer("vecteur", T_BYTE, SYM_ARRAY, 16);
    inserer("flag", T_BYTE, SYM_VAR, 1);

    afficherTable();

    return 0;
}