
#include <unistd.h>
#include <stdarg.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "analyse.h"
#include "analyse_y.h"



MethodeP makeMethode(char* n, char* l, Bool ovrd, Bool stk, Bool cstr, VarDeclP p, TypeP tr, TreeP c)
{/*TODO c'est nul, a refaire*/
  MethodeP result = NEW(1, Methode);
  result->name = strdup(n);
  result->label = strdup(l);
  result->parametres = p;

  result->corps = c;

  result->typeRetour = tr;

  result->next = NIL(Methode); /*il faut un env de methodes (a vider une fois qu'on a cree la classe*/

  result->ovrd = ovrd;
  result->stk = stk;
  result->cstr = cstr;

  return result;
}


ClassP makeClass(char *n, VarDeclP param, VarDeclP ch, char* sc, MethodeP m)
{
  ClassP result = NEW(1, Class);

  result->name = n;
  result->parametres = param;
  result->champs = ch;

  if(strcmp(sc, "") == 0){
  /*parcours de la liste de classes pour chercher si elle existe deja, sinon on cree une classe qui a le bon nom*/
  if(!(listeClasses == ((VarDeclP)NIL(VarDecl)))){
   int i = 1;
   VarDeclP tmpList = listeClasses;
   while(i){
     if(strcmp(tmpList->val->u.classe->name, sc) == 0){
        result->superClasse = tmpList->val->u.classe;
        i = 0;
     }
     else{
       tmpList = tmpList->next;
     }
    }
  }

  }
  else{
    result->superClasse = NEW(1, Class);
    result->superClasse->name = sc;
  }

  result->methodes = m;

/* ajout de la classe a l'environement des classes, on vérifie au passage qu'elle n'est pas superclasse d'une classe déja définie (si c'est le cas on définit la sc de la classe en question)*/

  if(listeClasses == NIL(VarDecl)){
    listeClasses = NEW(1, VarDecl);
    listeClasses->val->u.classe = result;
  }
  else{
    VarDeclP tmpList = listeClasses;
    int i = 1;
    while(i){
      if(strcmp(tmpList->val->u.classe->name, result->name) == 0){
        tmpList->val->u.classe = result;
      }
      tmpList = tmpList->next;
      if(tmpList == NIL(VarDecl)){
        tmpList->val->u.classe = result;
        i = 0;
      }
    }
  }
  return result;
}

VarDeclP makeVar(char *name, char *type, enum e elmt){
  VarDeclP result = NEW(1, VarDecl);
  result->name = strdup(name);
  result->val = NEW(1, Type);

  if(!strcmp(type, "Integer")){
	result->val->t = INTEGER;
  }
  else if(!strcmp(type, "String")){
	result->val->t = STRING;
  }
  else{
	int i = 1;
	VarDeclP listeTmp = listeClasses;
	while(i){
		if(strcmp(type, listeTmp->val->u.classe->name) == 0){
			listeTmp = listeTmp->next;
		}
		else{
			result->val->t = CLASS;
			result->val->u.classe = listeTmp->val->u.classe;
			i = 0;
		}
	}
  }

  result->elmt = elmt;
  


  return result;

}

Bool analyseSem(TreeP T){
	if(!(T == NIL(Tree))){
		/*TODO rajouter les declarations de classes, pour l'instant onne traite que les blocs*/

		if(!analyseBloc(T)){
			/*TODO erreur?*/
		}
	}
	return TRUE;
}

/*analyse semantique d'un bloc, on veut pouvoir avoir acces a l'env des decls du bloc parent s'il existe, dans ce cas il faut les fusionner correctement tel qu'on ne modifie pas le bloc parent et qu'on masque les variables du bloc parent*/

Bool analyseBloc(TreeP T){
	if(!portee(((TreeP)getChild(T, 1)), ((TreeP)getChild(T, 0))->u.var)){
		return FALSE;
	}
	else if(!typage(((TreeP)getChild(T, 0)), ((TreeP)getChild(T, 1))->u.var)){
		return FALSE;
	}
	return TRUE;
}

/*TODO blocs imbriques*/
Bool portee(TreeP listinst, VarDeclP listdecl){
	int i = 0;
	
	if(!(listinst->op == Evide)){
	for(i = 0; i<listinst->nbChildren; i++){
		if(((TreeP)getChild(listinst, i))->op == Eidvar){
			if(!contient(listdecl, ((TreeP)getChild(listinst, i))->u.str)){
				return FALSE;
			}
		}else{
			if(!portee(((TreeP)getChild(listinst, i)), listdecl)){return FALSE;}
		}
	}
	}
	return TRUE;
}


Bool contient(VarDeclP listdecl, char* name){
	Bool fin = FALSE;
	VarDeclP tmp = listdecl;

	while(!fin){
		if(strcmp(tmp->name, name) == 0){return TRUE;}
		else if (tmp->next != NIL(VarDecl)) {
			tmp = tmp->next;
		}
		else {fin = TRUE;}
	}
	return FALSE;
}

/*TODO il faut rajouter la gestion des types crees par l'utilisateur*/
enum _t typage(TreeP T, VarDeclP listdecl){

	switch(T->op){
		case Eadd : case Eminus : case Emult : case Ediv : case Esup: case Esupeq : case  Einf: case Einfeq : {
			if((typage(getChild(T, 0), listdecl) == INTEGER) && (typage(getChild(T, 1), listdecl) == INTEGER)){
				return INTEGER;
			}
			else{return FALSE;}
			break;
		}

		case Eaddu : case Eminusu :{
			if((typage(getChild(T, 0), listdecl) == INTEGER)) return INTEGER;
			else return FALSE;
			break;
		}

		case Eneq : case Eeq :{
			if((typage(getChild(T, 0), listdecl) == INTEGER) && (typage(getChild(T, 1), listdecl) == INTEGER)){
				return INTEGER;
			}
			else if((typage(getChild(T, 0), listdecl) == STRING) && (typage(getChild(T, 1), listdecl) == STRING)){
				return STRING;
			}
			else{return FALSE;}
			break;
		}

		case Econcat :{
			if((typage(getChild(T, 0), listdecl) == STRING) && (typage(getChild(T, 1), listdecl) == STRING)){
				return STRING;
			}
			else{return FALSE;}
			break;
		}

		case Econst : return INTEGER; break;
		case Estr : return STRING; break;

		case Eidvar :{}


		default : return FALSE; break;
	}

}

/*TODO verification des appels de fonction (parametres, type de retour, ...
TODO verification du bon usage de this/super*/

/************* le trucs du tp du prof TODO faudra voir si c'est utile*/
extern int yyparse();
extern int yylineno;

int evalMain(TreeP tree, VarDeclP decls);
int eval(TreeP tree, VarDeclP decls);

void printAST(TreeP tree, TreeP main);


/* Niveau de 'verbosite'.
 * Par defaut, n'imprime que le resultat et les messages d'erreur
 */
bool verbose = FALSE;

/* Evaluation ou pas. Par defaut, on evalue les expressions */
bool noEval = FALSE;

/* code d'erreur a retourner: liste dans tp.h */
int errorCode = NO_ERROR;

/* yyerror:  fonction importee par Bison et a fournir explicitement.
 * Elle est appelee quand Bison detecte une erreur syntaxique.
 * Ici on se contente d'un message minimal.
 */
void yyerror(char *ignore) {
  fprintf(stderr, "Syntax error on line: %d\n", yylineno);
}


/* mémorise le code d'erreur et s'arrange pour bloquer l'évaluation */
void setError(int code) {
  errorCode = code;
  if (code != NO_ERROR) { noEval = TRUE; }
}


/*fonctions de generation de code*/


void debut_code() {
    fprintf(fichier, "-- Ce fichier est généré par le compilateur -- \n\n");
    fprintf(fichier, "\t START \n");
}

void fin_code() {
    fprintf(fichier, "\t STOP \n");
}

void code(TreeP ast, VarDeclP list) {

    HashMapP buffer = hash[lastdecl];
    VarDeclP bufList = list;

    while(bufList != (VarDeclP)NIL(VarDeclP)){
        buffer->addr = lastdecl;
	buffer->nom = NEW(1, char);
        strcpy(buffer->nom, bufList->name);
        fprintf(fichier,"\t ALLOC %d \n", 1);
        lastdecl++;
        buffer->next = NEW(1, HashMap);
        buffer = buffer->next;
        bufList = bufList->next;
    }


        switch(ast->op) { /* On switch à partir de l'étiquette de l'AST ?*/
			case AXIOME:                                                             /*génération code axiome*/
				if(getChild(ast,0)->op == Evide){                                      /*cas ou axiome vide*/
                    			fprintf(fichier,"\t NOP \n" );
				}
				else if(getChild(ast,0)->op == Ebloc){                                 /*cas ou juste un bloc*/
                    			code(getChild(ast,0),NIL(VarDecl));
                		}else{                                                                 /*cas ou on a une liste de classe suivi d'un bloc*/
                    code(getChild(ast,0),NIL(VarDecl));
                	}
				break;
/*génération code if then else*/
			case Eite:
				code(getChild(ast,0),NIL(VarDecl));
				int l = newLabel();
				int l1 = newLabel();
				fprintf(fichier, "\t JZ else%d \n", l);  /*else = label rentre dans le else*/
				code(getChild(ast,1),NIL(VarDecl));
				fprintf(fichier, "\t JUMP fin%d \n", l1);  /*fin = label fin instruction*/
				fprintf(fichier, "\t else%d: NOP \n", l);
				code(getChild(ast,2),NIL(VarDecl));
				fprintf(fichier, "\t fin%d: NOP \n", l1);
				break;
			case Eidvar:                                                            /*génération code : récupère élément en mémoire*/
			    buffer = hash[0];
			    while(buffer != NIL(HashMap)){
			        if(strcmp(buffer->nom , ast->u.str) == 0){
			            break;
			        }
			        buffer = buffer->next;
			    }
				fprintf(fichier, "\t PUSHG %d \n", buffer->addr);
				break;
			case Econst:                                                            /*génération code déclaration constante*/
				fprintf(fichier, "\t PUSHI %d \n", ast->u.val);
				break;
			case Estr:                                                              /*génération code déclaration string*/
				fprintf(fichier, "\t PUSHS %s \n", ast->u.str);
				break;
			case Eaff:                                                              /*génération code affectation*/
				buffer = hash[0];
				while(buffer != NIL(HashMap)){
					if(strcmp(buffer->nom, getChild(ast,0)->u.str) == 0){
						break;
					}
					buffer = buffer->next;
				}
				code(getChild(ast,0), NIL(VarDecl));
				code(getChild(ast,1),NIL(VarDecl));
				fprintf(fichier, "\t STOREG %d \n", buffer->addr);
				break;
			case Eadd:                                                              /*génération code addition*/
				code(getChild(ast,0), NIL(VarDecl));
				code(getChild(ast,1), NIL(VarDecl));
				fprintf(fichier, "\t ADD \n");
				break;
            case Eaddu:                                                             /*génération code itération ++*/
                code(getChild(ast,0),NIL(VarDecl));
                fprintf(fichier, "\t PUSHI %d \n", 1);
                fprintf(fichier, "\t ADD \n");
                break;
            case Eminus:                                                            /*génération code soustraction*/
				code(getChild(ast,0), NIL(VarDecl));
				code(getChild(ast,1), NIL(VarDecl));
				fprintf(fichier, "\t SUB \n");
				break;
            case Eminusu:                                                           /*génération code itération -- */
                code(getChild(ast,0),NIL(VarDecl));
                fprintf(fichier, "\t PUSHI %d \n", 1);
                fprintf(fichier, "\t SUB \n");
                break;
			case Emult:                                                             /*génération code multiplication*/
				code(getChild(ast,0), NIL(VarDecl));
				code(getChild(ast,1), NIL(VarDecl));
				fprintf(fichier, "\t MUL \n");
				break;
			case Ediv:                                                              /*génération code division*/
				code(getChild(ast,0), NIL(VarDecl));
				code(getChild(ast,1), NIL(VarDecl));
				fprintf(fichier, "\t DIV \n");
				break;
			case Eneq:                                                              /*génération code inégalité*/
				if(typage(ast, NIL(VarDecl)) == INTEGER){                                             /*test d'égalité dans le cas des integer*/
                    code(getChild(ast,0),NIL(VarDecl));
                    code(getChild(ast,1),NIL(VarDecl));
                    fprintf(fichier, "\t EQUAL \n");
                    fprintf(fichier, "\t NOT \n");
                    break;
                }else {                                                                 /*test d'égalité dans le cas des string*/
                    buffer = hash[0];
                    while(buffer != NIL(HashMap)){
                        if(strcmp(buffer->nom , ast->u.str) == 0){
                            break;
                        }
                        buffer = buffer->next;
                    }
                    fprintf(fichier, "\t LOAD %d \n", buffer->addr);

                    HashMapP buffer2 = hash[0];
                    while(buffer2 != NIL(HashMap)){
                        if(strcmp(buffer2->nom , ast->u.str) == 0){
                            break;
                        }
                        buffer2 = buffer2->next;
                    }
                    fprintf(fichier, "\t LOAD %d \n", buffer2->addr);
                    fprintf(fichier, "\t EQUAL \n");
                    fprintf(fichier, "\t NOT \n");
                    break;
				}
            case Eeq:                                                              /*génération code égalité*/
                if(typage(ast,list) == INTEGER){                                        /*test d'égalité dans le cas des integer*/
                    code(getChild(ast,0),NIL(VarDecl));
                    code(getChild(ast,1),NIL(VarDecl));
                    fprintf(fichier, "\t EQUAL \n");
                    break;
                }else {                                                                 /*test d'égalité dans le cas des string*/
                    buffer = hash[0];
                    while(buffer != NIL(HashMap)){
                        if(strcmp(buffer->nom , ast->u.str) == 0){
                            break;
                        }
                        buffer = buffer->next;
                    }
                    fprintf(fichier, "\t LOAD %d \n", buffer->addr);

                    HashMapP buffer2 = hash[0];
                    while(buffer2 != NIL(HashMap)){
                        if(strcmp(buffer2->nom , ast->u.str) == 0){
                            break;
                        }
                        buffer2 = buffer2->next;
                    }
                    fprintf(fichier, "\t LOAD %d \n", buffer2->addr);
                    fprintf(fichier, "\t EQUAL \n");
                    break;
                }
            case Esup:                                                          /*génération code supérieur*/
                code(getChild(ast,0),NIL(VarDecl));
                code(getChild(ast,1),NIL(VarDecl));
                fprintf(fichier, "\t SUP \n");
                break;
            case Einf:                                                          /*génération code inférieur*/
                code(getChild(ast,0),NIL(VarDecl));
                code(getChild(ast,1),NIL(VarDecl));
                fprintf(fichier, "\t INF \n");
                break;
            case Einfeq:                                                        /*génération code inférieur ou égale*/
                code(getChild(ast,0),NIL(VarDecl));
                code(getChild(ast,1),NIL(VarDecl));
                fprintf(fichier, "\t SUPEQ \n");
                break;
            case Esupeq:                                                        /*génération code supérieur ou égale*/
                code(getChild(ast,0),NIL(VarDecl));
                code(getChild(ast,1),NIL(VarDecl));
                fprintf(fichier, "\t INFEQ \n");
                break;
            case Evide:                                                         /*génération code vide*/
                fprintf(fichier,  "\t NOP \n");
		break;
            case Econcat:                                                       /*génération code concatenation*/
                buffer = hash[0];
                while(buffer != NIL(HashMap)){
                    if(strcmp(buffer->nom , ast->u.str) == 0){
                        break;
                    }
                    buffer = buffer->next;
                }
                fprintf(fichier, "\t LOAD %d \n", buffer->addr);

                HashMapP buffer2 = hash[0];
                while(buffer2 != NIL(HashMap)){
                    if(strcmp(buffer2->nom , ast->u.str) == 0){
                        break;
                    }
                    buffer2 = buffer2->next;
                }
                fprintf(fichier, "\t LOAD %d \n", buffer2->addr);
                fprintf(fichier, "\t CONCAT \n");
                break;
            case Ebloc:
                code(getChild(ast,1), getChild(ast,0)->u.var);
		break;
	    case Elist :
		code(getChild(ast, 0), NIL(VarDecl));
		code(getChild(ast, 1), NIL(VarDecl));
		break;
	    default :
		printf("code non pris en compte par le compilateur");
		break;
    }
		
}

int newLabel(){
	return lastLabel++;
}




/* Appel:
 *   tp [-option]* programme.txt
 * Les options doivent apparaitre avant le nom du fichier du programme.
 * Options: -[eE] -[vV] -[hH?]
 */
int main(int argc, char **argv) {
  int fi;
  int i, res;

  for(i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      switch (argv[i][1]) {
      case 'v': case 'V':
	verbose = TRUE; continue;
      case 'e': case 'E':
	noEval = TRUE; continue;
      case '?': case 'h': case 'H':
	fprintf(stderr, "Syntax: tp -e -v program.txt\n");
	exit(USAGE_ERROR);
      default:
	fprintf(stderr, "Error: Unknown Option: %c\n", argv[i][1]);
	exit(USAGE_ERROR);
      }
    } else break;
  }

  if (i == argc) {
    fprintf(stderr, "Error: Program file is missing\n");
    exit(USAGE_ERROR);
  }

  if ((fi = open(argv[i++], O_RDONLY)) == -1) {
    fprintf(stderr, "Error: Cannot open %s\n", argv[i-1]);
    exit(USAGE_ERROR);
  }

  /* redirige l'entree standard sur le fichier... */
  close(0); dup(fi); close(fi);

  if (i < argc) { /* fichier dans lequel lire les valeurs pour get() */
    fprintf(stderr, "Error: extra argument: %s\n", argv[i]);
    exit(USAGE_ERROR);
  }

  /*on initialise la map des declarations pour la generation de code*/
  hash = NEW(1, HashMapP);
  hash[0] = NEW(1, HashMap); 
  lastdecl = 0;
  lastLabel = 0;

  fichier = fopen("out.txt", "w");

  /* Lance l'analyse syntaxique de tout le source, qui appelle yylex au fur
   * et a mesure. Execute les actions semantiques en parallele avec les
   * reductions.
   * yyparse renvoie 0 si le source est syntaxiquement correct, une valeur
   * differente de 0 en cas d'erreur syntaxique (eventuellement dues a des
   * erreurs lexicales).
   * Comme l'interpretation globale est automatiquement lancee par les actions
   * associees aux reductions, une fois que yyparse a termine il n'y
   * a plus rien a faire (sauf fermer les fichiers)
   * Si le code du programme contient une erreur, on bloque l'evaluation.
   * S'il n'y a que des erreurs contextuelles on essaye de ne pas s'arreter
   * a la premiere mais de continuer l'analyse pour en trovuer d'autres, quand
   * c'est possible.
   */
  res = yyparse();
  if (res == 0 && errorCode == NO_ERROR) return 0;
  else {
    return res ? SYNTAX_ERROR : errorCode;
  }
}


/* Fonction AUXILIAIRE pour la construction d'arbre : renvoie un squelette
 * d'arbre pour 'nbChildren' fils et d'etiquette 'op' donnee. L'appelant
 * doit lui-même stocker ses fils dans la strucutre que MakeNode renvoie
 */
TreeP makeNode(int nbChildren, Etiquette op) {
  TreeP tree = NEW(1, Tree);
  tree->op = op; tree->nbChildren = nbChildren;
  tree->u.children = nbChildren > 0 ? NEW(nbChildren, TreeP) : NIL(TreeP);
  return(tree);
}


/* Construction d'un arbre a nbChildren branches, passees en parametres
 * 'op' est une etiquette symbolique qui permet de memoriser la construction
 * dans le programme source qui est representee par cet arbre.
 * Une liste preliminaire d'etiquettes est dans tp.h; il faut l'enrichir selon
 * vos besoins.
 * Cette fonction prend un nombre variable d'arguments: au moins deux.
 * Les eventuels arguments supplementaires doivent etre de type TreeP
 * (defini dans tp.h)
 */
TreeP makeTree(Etiquette op, int nbChildren, ...) {
  va_list args;
  int i;
  TreeP tree = makeNode(nbChildren, op); 
  va_start(args, nbChildren);
  for (i = 0; i < nbChildren; i++) { 
    tree->u.children[i] = va_arg(args, TreeP);
  }
  va_end(args);
  return(tree);
}


/* Retourne le i-ieme fils d'un arbre (de 0 a n-1) */
TreeP getChild(TreeP tree, int i) {
  return tree->u.children[i];
}


/* Constructeur de feuille dont la valeur est un entier */
TreeP makeLeafInt(Etiquette op, int val) {
  TreeP tree = makeNode(0, op); 
  tree->u.val = val;
  return(tree);
}


/* Constructeur de feuille dont la valeur est une chaine de caracteres.
 * Construit un doublet pour la future variable et stocke son nom dedans.
 */
TreeP makeLeafStr(Etiquette op, char *str) {
  TreeP tree = makeNode(0, op); 
  tree->u.str = str;
  return(tree);
}

/* Constructeur de feuille pour une liste de variables. */
TreeP makeLeafVar(Etiquette op, VarDeclP var){
	TreeP tree = makeNode(0, op);
	tree->u.var = var;
	return(tree);
}


/* Verifie que nouv n'apparait pas deja dans list. l'ajoute en tete et
 * renvoie la nouvelle liste. 
 */
VarDeclP addToScope(VarDeclP nouv, VarDeclP list) {
  VarDeclP p;
  for(p=list; p != NIL(VarDecl); p = p->next) {
    if (! strcmp(p->name, nouv->name)) {
      fprintf(stderr, "Error: Multiple declaration in the same scope of %s\n",
	      p->name);
      setError(CONTEXT_ERROR);
      break;
    }
  }
  /* On continue meme en cas de double declaration, pour pouvoir eventuellement
   * detecter plus d'une erreur
   */
  nouv->next=list;
  return nouv;
}


/**
 * 	A partir d'ici les fonctions ont besoin d'etre modifiees/completees
 **/

void printOpBinaire(char op) {
  switch(op) {
  case Eeq:    printf("="); break;
  case Eneq:    printf("<>"); break;
  case Esup:    printf("<"); break;
  case Esupeq:    printf(">="); break;
  case Einf:    printf("<"); break;
  case Einfeq:    printf("<="); break;
  case Eadd:  printf("+"); break;
  case Eminus:printf("-"); break;
  case Emult: printf("*"); break;
  case Ediv:  printf("/"); break;
  default:
    fprintf(stderr, "Unexpected binary operator of code: %d\n", op);
    exit(UNEXPECTED);
  }
}

void printExpr(TreeP tree) {
  switch (tree->op) {
  case Eidvar :
    printf("%s", tree->u.str); break;
  case Econst:
    printf("%d", tree->u.val); break;
  case Eite:
    printf("[ITE "); printExpr(getChild(tree, 0)); /* la condition */
    printf(", "); printExpr(getChild(tree, 1)); /* la partie 'then' */
    printf(", "); printExpr(getChild(tree, 2)); /* la partie 'else' */
    printf("]");
    break;
  case Eeq:
  case Eneq:
  case Esup:
  case Esupeq:
  case Einf:
  case Einfeq:
  case Eadd:
  case Eminus:
  case Emult:
  case Ediv:
    printf("(");
    printOpBinaire(tree->op);
    printf(" "); printExpr(getChild(tree, 0));
    printf(" "); printExpr(getChild(tree, 1));
    printf(")"); break;
  default:
    fprintf(stderr, "Erreur! etiquette indefinie: %d\n", tree->op);
    exit(UNEXPECTED);
  }
}

/* decls est l'AST représentant lapartie declarations */
void printDecls(TreeP decls) {
  if (decls == NIL(Tree)) return;
}


/* decls est l'AST représentant lapartie declarations 
 * main represente l'expression finale du programme
 */

void printAST(TreeP decls, TreeP main) {
  printDecls(decls);
  printExpr(main); printf("\n");
}


/* Avant evaluation, verifie si tout identificateur qui apparait dans tree a
 * bien ete declare (dans ce cas il doit apparaitre dans lvar).
 */
bool checkScope(TreeP tree, VarDeclP lvar) {
  fprintf(stderr, "Erreur! etiquette indefinie: %d\n", tree->op);
  exit(UNEXPECTED);
}


/* Associe une variable a l'expression qui definit sa valeur, et procede a
 * l'evaluation de cette expression, sauf si on est en mode noEval
 */
VarDeclP declVar(char *name, TreeP tree, VarDeclP decls) {
  return NIL(VarDecl);
}


/* Traite une declaration representee par l'AST 'tree'.
 * 'decls' represente la liste des couples (variable, valeur) definis par les
 * declarations qui precedaient la declaration courante dans le programme,
 * donc les variables qui peuvent apparaitre aux feuilles de 'tree'
*/
VarDeclP evalAff (TreeP tree, VarDeclP decls) {
  return NIL(VarDecl);
}

/* Ici 'tree' correspond a l'AST pour une liste de declarations. */
VarDeclP evalDecls (TreeP tree) {
  return NIL(VarDecl);
}


/* Evaluation d'un if then else
 * le premier fils represente la condition,
 * les deux autres fils correspondent respectivement aux parties then et else.
 * Attention a n'evaluer qu'un seul de ces deux sous-arbres !
 */
int evalIf(TreeP tree, VarDeclP decls) {
  fprintf(stderr, "evalIf: a definir\n");
  exit(UNEXPECTED);
}


/* retourne la valeur d'une variable: 'tree' correspond a une feuille qui
 * represente un identificateur. decls est la liste courante des couples
 * (variable, valeur). On est suppose avoir deja verifie que l'identificateur
 * etait bien declare, donc on doit trouver sa valeur.
 */
int getValue(TreeP tree, VarDeclP decls) {
  fprintf(stderr, "evalIf: a definir\n");
  exit(UNEXPECTED);
}


/* eval: parcours recursif de l'AST d'une expression en cherchant dans
 * l'environnement la valeur des variables referencee
 * tree: l'AST d'une expression
 * decls: la liste des variables deja declarées avec leur valeur.
 */
int eval(TreeP tree, VarDeclP decls) {
  fprintf(stderr, "eval: a definir\n");
  exit(UNEXPECTED);
}

/* evalMain: evaluation de l'expression finale.
 * tree: AST de l'expression comprise entre le BEGIN et le END
 * decls: l'environnement forme par les variables declarees
 */
int evalMain(TreeP tree, VarDeclP decls) {
  fprintf(stderr, "evalMain: a definir\n");
  exit(UNEXPECTED);
}



















