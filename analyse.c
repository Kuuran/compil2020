#include "analyse.h"



MethodeP makeMethode(char*n, char*l, int ovrd, VarDeclP p, TypeP tr TreeP c)
{//TODO c'est nul, a refaire
  MethodeP result = NEW(1, Methode);
  result->name = strdup(n);
  result->label = strdup(l);
  result->parametres = p;
  result->corps = c;
  result->typeRetour = tr;
  result->next = NIL(MethodeP);
  result->override = ovrd;

  return result;
}

ClassP makeClass(char *n, VarDeclP param, VarDeclP ch, ClassP sc, MethodeP m);
{
  ClassP result = NEW(1, Class);

  result->name = n;
  result->parametres = parm;
  result->champs = ch;
  result->superClasse = sc; //TODO tester si la sc est définie
  result->methodes = m;

//TODO rajouter la classe a l'env des sc

}
