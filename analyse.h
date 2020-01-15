#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "analysesynt.tab.h"
int yylex(void);
void yyerror(char*);


/* deux macros pratiques, utilisees dans les allocations de structure
 * Pour NEW on donne le nombre et le type de la stucture a allouer (pas le type
 * du pointeur) et on recupere un pointeur sur cette structure.
 * Pour NIL: on donne de meme le type de la structure (pas le type du pointeur)
 */
#define NEW(howmany, type) (type *) calloc((unsigned) howmany, sizeof(type))
#define NIL(type) (type *) 0

#define TRUE 1
#define FALSE 0
typedef int bool;


/* Codes d'erreurs */
#define NO_ERROR	0
#define USAGE_ERROR	1
#define LEXICAL_ERROR	2
#define SYNTAX_ERROR    3
#define CONTEXT_ERROR	4
#define EVAL_ERROR	5
#define UNEXPECTED	10

//TODO a modif
/* Etiquettes pour les arbres de syntaxe abstraite */
typedef enum {
  Eadd, Eminus, Emult, Ediv,
  Eneq, Eeq, Egt, Ege, Elt, Ele,
  Econst, Eidvar,
  Eite
} Etiquette;


		/* Definition d'un arbre de syntaxe abstraite */

/* la structure d'un arbre (noeud ou feuille) */
typedef struct _Tree {
  Etiquette op;         /* etiquette de l'operateur courant */
  short nbChildren;     /* nombre de sous-arbres */
  union {
    char *str;         /* valeur de la feuille si op = Eidvar */
    int val;           /* valeur de la feuille si op = Econst */
    struct _Tree **children; /* tableau des sous-arbres d'un noeud interne */
  } u;
} Tree, *TreeP;


/* la structure ci-dessous permet de construire des listes de paires
 * (variable, valeur).
 * On va construire des listes de la forme { (x 5), (y, 27) } au fur
 * et a mesure qu'on interprete les declarations dans un programme source.
 */
typedef struct _Decl
{ char *name;
  int val;
  struct _Decl *next;
} VarDecl, *VarDeclP;

//TODO struct classe methode et les fct pour les creer

typedef struct _Class
{ char *name;
  ClassP sClasse;
  MethodeP* methodes;
//TODO completer

} Class, *ClassP;

typedef struct _Methode
{ char *name;
  VarDeclP* parametres;//TODO pas sur
  TreeP corps;
} Methode, *MethodeP;

/* Type pour la valeur de retour de Flex et les actions de Bison
 * le premier champ est necessaire pour Flex.
 * les autres correspondent aux variantes utilisees dans les actions
 * associees aux productions de la grammaire.
*/
typedef union
{ char C;	/* caractere isole */
  char *S;	/* chaine de caractere */
  int I;	/* valeur entiere */
  VarDeclP D;	/* liste de paires (variable, valeur) */
  TreeP T;	/* AST */
} YYSTYPE;


/* necessaire sinon par defaut Bison definit YYSTYPE comme int ! */
#define YYSTYPE YYSTYPE


	/* Prototypes des fonctions (partiellement) mises a disposition */

/* construction pour les AST */
TreeP makeLeafStr(Etiquette op, char *str); 	    /* feuille (string) */
TreeP makeLeafInt(Etiquette op, int val);	    /* feuille (int) */
TreeP makeTree(Etiquette op, int nbChildren, ...);  /* noeud interne */
ClassP makeClass();//TODO params
MethodeP makeMethode(char *n, VarDeclP *p, TreeP c); //cree une methode


/* Impression des AST */
void printAST(TreeP decls, TreeP main);
