#include "analyse.h"



MethodeP makeMethode(char*n, char*l, VarDeclP p, TypeP tr TreeP c)
{
  MethodeP result = NEW(1, Methode);
  result.name = strdup(n);
  result.label = strdup(l);
  result.parametres = p;
  result.corps = c;
  result.typeRetour = tr;

  return result;
}


