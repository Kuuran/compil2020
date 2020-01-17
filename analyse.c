#include "analyse.h"



MethodeP makeMethode(char*n, char*l, int ovrd, VarDeclP p, TypeP tr TreeP c)
{
  MethodeP result = NEW(1, Methode);
  result.name = strdup(n);
  result.label = strdup(l);
  result.parametres = p;
  result.corps = c;
  result.typeRetour = tr;
  result.next = NIL(MethodeP);
  result.override = ovrd;

  return result;
}

ClassP makeClass(char *n, VarDeclP param, VarDeclP ch, ClassP sc, MethodeP m);
{
}
