#include "analyse.h"



MethodeP makeMethode(char*n, char*l, Bool ovrd, Bool stk, Bool cstr, VarDeclP p, TypeP tr, TreeP c)
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
  if(!listeClasses == NIL(VarDecl)){
   int i = 1;
   VarDeclP tmpList = listeClasses;
   while(i){
     if(!strcmp(tmpList->val->u.classe->name, sc) == 0){
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
      if(!strcmp(tmpList->val->u.classe->name, result->name) == 0){
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





















