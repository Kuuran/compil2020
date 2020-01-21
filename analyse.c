#include "analyse.h"



MethodeP makeMethode(char*n, char*l, int ovrd, int stk, VarDeclP p, TypeP tr TreeP c)
{//TODO c'est nul, a refaire
  MethodeP result = NEW(1, Methode);
  result->name = strdup(n);
  result->label = strdup(l);
  result->parametres = p;
  result->corps = c;
  result->typeRetour = tr;
  result->next = NIL(MethodeP);
  result->ovrd = ovrd;
  result->stk = stk;

  return result;
}


ClassP makeClass(char *n, VarDeclP param, VarDeclP ch, char* sc, MethodeP m);
{
  ClassP result = NEW(1, Class);

  result->name = n;
  result->parametres = parm;
  result->champs = ch;

  if(strcmp(sc, "") == 0){
  //parcours de la liste de classes pour chercher si elle existe deja, sinon on cree une classe qui a le bon nom
  if(!listeClasses == NIL(VarDecl)){
   int i = 1;
   VarDeclP tmpList = listeClasses;
   while(i){
     if(!strcmp(tmpList->val.u.classe->name, sc) == 0){
        result->superClasse = tmpList->val.u.classe;
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
    result->superClasse.name = sc;
  }
//TODO faut verifier les methodes redefinies si la sc existe, sinon faut noter qu'on la pas fait et le faire quand la sc sera declaree.
  result->methodes = m;

// ajout de la classe a l'environement des classes, on vérifie au passage qu'elle n'est pas superclasse d'une classe déja définie (si c'est le cas on définit la sc de la classe en question)

  if(listeClasses == NIL(VarDecl)){
    listClasses = NEW(1, VarDecl);
    listClasses.val.u.classe = result;
  }
  else{
    VarDeclP tmpList = listeClasses;
    int i = 1;
    while(i){
      if(!strcmp(tmpList.val.u->classe->name, result->name) == 0){
        tmpList.val.u->classe = result;
      }
      tmpList = tmpList->next;
      if(tmpList = NIL(VarDecl){
        tmpList.val.u->classe = result;
        i = 0;
      }
    }
  }
}






















