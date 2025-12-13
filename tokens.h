/* * Fichier : tokens.h
 * Description : Définitions des constantes symboliques pour l'analyseur lexical (Flex)
 * et l'analyseur syntaxique (Bison) de CryptoLang.
 */

#ifndef TOKENS_H
#define TOKENS_H

/* ===============================================================
 * CATEGORIES DE TOKENS
 * =============================================================== */

/* Mots-clés de structure (Valeurs >= 258) */
#define TOKEN_PROTOCOL      258
#define TOKEN_ENDPROTOCOL   259
#define TOKEN_IMPORT        260
#define TOKEN_KEYSPACE      261
#define TOKEN_MAIN          262
#define TOKEN_PACKET        263

/* Mots-clés de contrôle */
#define TOKEN_LOOP          264
#define TOKEN_FOR           265
#define TOKEN_ROTATE        266
#define TOKEN_STEP          267
#define TOKEN_ROUNDS        268

/* Types de données de base */
#define TOKEN_BIT           269
#define TOKEN_NIBBLE        270
#define TOKEN_BYTE          271
#define TOKEN_WORD          272
#define TOKEN_DWORD         273
#define TOKEN_QWORD         274

/* Types cryptographiques */
#define TOKEN_PLAIN         275
#define TOKEN_CIPHER        276
#define TOKEN_HASH          277
#define TOKEN_KEY128        278
#define TOKEN_KEY256        279
#define TOKEN_KEY512        280

/* Opérateurs de déclaration et d'affectation */
#define TOKEN_DECLARE       281     // ::
#define TOKEN_ASSIGN        '='     // = (simple, non réservé si utilisé seul)
#define TOKEN_SECURE_ASSIGN 282     // ::=

/* Opérateurs conditionnels (Ternaire ou IF/ELIF) */
#define TOKEN_IF            283     // ?[
#define TOKEN_ELIF          284     // :[ (Utilisé ici pour l'équivalent du ELIF/ELSE dans la ternaire)
#define TOKEN_ELSE          328  // ::
/* Opérateurs cryptographiques */
#define TOKEN_ENCRYPT       285     // @>
#define TOKEN_DECRYPT       286     // <@
#define TOKEN_HASH_CALC     287     // #>
#define TOKEN_HASH_VERIFY   288     // @#
#define TOKEN_SIGN          289     // &>
#define TOKEN_VERIFY_SIGN   290     // <&

/* Opérateurs arithmétiques et de comparaison composés */
#define TOKEN_POWER         291     // **
#define TOKEN_EQ            292     // ==
#define TOKEN_NEQ           293     // !=
#define TOKEN_LEQ           294     // <=
#define TOKEN_GEQ           295     // >=

/* Opérateurs logiques */
#define TOKEN_AND           296     // &&
#define TOKEN_OR            297     // ||
#define TOKEN_XOR_LOGIC     298     // ^^

/* Opérateurs Bitwise de Décalage et Rotation (Rotation ajoutée) */
#define TOKEN_SHIFT_LEFT    299     // <<
#define TOKEN_SHIFT_RIGHT   300     // >>
#define TOKEN_ROTATE_LEFT   301     // <<<
#define TOKEN_ROTATE_RIGHT  302     // >>>

/* Entrées/Sorties */
#define TOKEN_OUTPUT        303     // ->
#define TOKEN_INPUT         304     // <-

/* Opérateurs arithmétiques/logiques/bitwise simples (valeurs ASCII) */
#define TOKEN_PLUS          '+'
#define TOKEN_MINUS         '-'
#define TOKEN_MULT          '*'
#define TOKEN_DIV           '/'
#define TOKEN_MOD           '%'
#define TOKEN_LT            '<'
#define TOKEN_GT            '>'
#define TOKEN_NOT           '!'
#define TOKEN_BIT_AND       '&'
#define TOKEN_BIT_XOR       '^'
#define TOKEN_BIT_NOT       '~'


/* Délimiteurs (valeurs ASCII) */
#define TOKEN_LBRACE        '{'
#define TOKEN_RBRACE        '}'
#define TOKEN_LBRACKET      '['
#define TOKEN_RBRACKET      ']'
#define TOKEN_LPAREN        '('
#define TOKEN_RPAREN        ')'
#define TOKEN_SEMICOLON     ';'
#define TOKEN_COMMA         ','
#define TOKEN_DOT           '.'
#define TOKEN_COLON         ':'
/* Littéraux */
#define TOKEN_IDENTIFIER    310
#define TOKEN_INTEGER       311
#define TOKEN_HEX           312
#define TOKEN_STRING        313

/* Fin de fichier */
#define TOKEN_EOF           0

#endif // TOKENS_H
