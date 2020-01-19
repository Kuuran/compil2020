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
  //parcours de la liste de classes pour chercher si elle existe deja, sinon init a NIL
  }
  else{
  result->superClasse = NIL(Class);
  }
  result->methodes = m;

//TODO rajouter la classe a l'env des sc

//si listclass non vide aller a la fin (on check pendant le parcours qu'on a pas de classes qui ont celle ci en sc, si oui on la met dedans) puis on l'insere. sinon on l'insere au debut (DUH).


}
