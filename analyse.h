#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
/*#include "analysesynt.tab.h"*/
int yylex(void);
void yyerror(char*);

extern char *strdup(const char *s);

/* deux macros pratiques, utilisees dans les allocations de structure
 * Pour NEW on donne le nombre et le type de la stucture a allouer (pas le type
 * du pointeur) et on recupere un pointeur sur cette structure.
 * Pour NIL: on donne de meme le type de la structure (pas le type du pointeur)
 */
#define NEW(howmany, type) (type *) calloc((unsigned) howmany, sizeof(type))
#define NIL(type) (type *) 0

#define TRUE 1
#define FALSE 0
typedef int Bool;

typedef struct _Type Type, *TypeP;
typedef struct _Class *ClassP;
typedef struct _Methode *MethodeP;
typedef struct _Decl *VarDeclP;

/* Codes d'erreurs */
#define NO_ERROR	0
#define USAGE_ERROR	1
#define LEXICAL_ERROR	2
#define SYNTAX_ERROR    3
#define CONTEXT_ERROR	4
#define EVAL_ERROR	5
#define UNEXPECTED	10

/*TODO a modif*/
/* Etiquettes pour les arbres de syntaxe abstraite */
typedef enum {
  Eadd, Eminus, Emult, Ediv,
  Eneq, Eeq, Esup, Esupeq, Einf, Einfeq,
  Econst, Eidvar, Eaff, Estr,
  Eite, Edecl, Eclass, Enew, Eresult, Emethode, Eselect, Ethis, Esuper,
  Ebloc, Elist, Evide, AXIOME
} Etiquette;


#define	Eminus		1
#define	Emult		2
#define	Ediv		3
#define	Eneq		4
#define	Eeq		5
#define	Esup		6 
#define	Esupeq		7 
#define	Einf		8
#define	Einfeq		9
#define	Econst		10
#define	Eidvar		11
#define	Eite		12
#define	Eadd		13
#define	Edecl		14
#define	Eclass		15
#define	Enew		16
#define	Eresult		17
#define	Emethode	18
#define	Eselect		19
#define Ebloc		20
#define	Ethis		21
#define	Esuper		22
#define	Eaff		23
#define	Elist		24
#define Evide		25
#define AXIOME		26
#define Estr		27



		/* Definition d'un arbre de syntaxe abstraite */

/* la structure d'un arbre (noeud ou feuille) */
typedef struct _Tree {
  Etiquette op;         /* etiquette de l'operateur courant */
  short nbChildren;     /* nombre de sous-arbres */
  union {
    char *str;         /* valeur de la feuille si op = Eidvar */
    int val;           /* valeur de la feuille si op = Econst */
    VarDeclP var;
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
  TypeP val;
  enum e {PARAM, PARAMVAR, CHAMP, INSTANCE, THIS, RESULT, CLASSE, UNKNOWN} elmt;
  struct _Decl *next;
} VarDecl, *VarDeclP;

#define	PARAM		1
#define	PARAMVAR	2
#define	CHAMP		3
#define	INSTANCE	4
#define	THIS		5
#define	RESULT		6
#define	CLASSE		7
#define	UNKNOWN		8

typedef struct _Type
{
  enum _t {CLASS, STRING, INTEGER} t;
  union{
	ClassP classe;
	char *string;
	int *integer;
	} u;
} Type, *TypeP;

#define	CLASS	1
#define	STRING	2
#define	INTEGER	3

typedef struct _Class
{ char *name;
  VarDeclP parametres;
  VarDeclP champs;
  ClassP superClasse;
  MethodeP methodes;
} Class, *ClassP;

typedef struct _Methode
{ char *name; /* pas util pour la gen de code*/
  char *label; /* label de debut de fct*/
  Bool ovrd;
  Bool stk;
  Bool cstr;

  VarDeclP parametres;/*parametres de la fonction */
  TypeP typeRetour;
  TreeP corps; /* ça c'est un bloc*/
  MethodeP next;
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
TreeP makeLeafVar(Etiquette op, VarDeclP var);	    /* feuille (liste de declarations)*/
TreeP makeTree(Etiquette op, int nbChildren, ...);  /* noeud interne */
ClassP makeClass(char *n, VarDeclP param, VarDeclP champs, char* s, MethodeP m);
MethodeP makeMethode(char *n, char *l, Bool ovrd, Bool stk, Bool cstr, VarDeclP p, TypeP tr, TreeP c); /*cree une methode*/
VarDeclP makeVar(char *name, char *type, enum e elmt);

VarDeclP addToScope(VarDeclP nouv, VarDeclP list);

VarDeclP listeClasses; /*stock toutes les classes déja faites pour permettre gerer les super classes*/
VarDeclP varGlobales;

TreeP getChild(TreeP tree, int i);

/* Impression des AST */
void printAST(TreeP decls, TreeP main);



/*fonctions pour l'analyse semantique*/



/*fonction de lancement de l'analyse*/
Bool analyseSem(TreeP T);

Bool analyseBloc(TreeP T);

/*Verification de la portee des variables d'un bloc*/
Bool portee(TreeP listinst, VarDeclP listdecl);

/*verifie si une declaration est presente dans l'environment des declarations*/
Bool contient(VarDeclP listdecl, char* name);

/*Typage d'une expression*/
enum _t typage(TreeP T);

/**/

















