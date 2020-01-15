%{

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "analyse.h"

int lineno= 1;
bool erreurlex=false;


//TODO set yyval pour tous les cas
//TODO quand on utilise yytext utiliser strdup psk c'est un pointeur (donc sa valeur change a chaque fois et du coup ça donnera un resultat faux)
%}

%option noyywrap

chainecarac \"(([^\"]|\\\")*[^\\])?\"
nomClasse [A-Z][[:alnum:]]*
nom [[:alpha:]][[:alnum:]]*
nombre 0|[1-9][[:digit:]]*
comment [/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]

%%

{comment} {/*pattern du commentaire donc ne rien faire*/}



{chainecarac} {
yylval.chainecarac = yytext;
return TOK_CHAINECARAC;
}


"class"  {return TOK_CLASS;}
"(" 	 {return TOK_PARENTHESEG;}
")"      {return TOK_PARENTHESED;} 
"extends"       {return TOK_EXTENDS;} 
"is"       {return TOK_IS;} 
"{"       {return TOK_CROCHETG;} 
"}"       {return TOK_CROCHETD;} 
"def"       {return TOK_DEF;} 
":"       {return TOK_DEUXPOINTS;} 
","       {return TOK_VIRGULE;} 
"var"       {return TOK_VAR;} 
";"       {return TOK_POINTVIRGULE;} 
"static"       {return TOK_STATIC;} 
"override"       {return TOK_OVERRIDE;} 
":="       {return TOK_AFFECTATION;} 
"this"       {return TOK_THIS;} 
"super"       {return TOK_SUPER;} 
"result"       {return TOK_RESULT;} 
"."       {return TOK_POINT;} 
"new"       {return TOK_NEW;} 
"&"       {return TOK_CONCAT;} 
"<>"      {return TOK_DIFFERENCE;}  
"="       {return TOK_EGALITE;} 
"-"       {return TOK_MOINS;} 
"+"       {return TOK_PLUS;} 
"*"       {return TOK_FOIS;} 
"/"       {return TOK_DIVISION;} 
"return"       {return TOK_RETURN;}  
"if"       {return TOK_IF;} 
"then"       {return TOK_THEN;} 
"else"      {return TOK_ELSE;} 
"<"  {return TOK_INFERIEUR;}
">"  {return TOK_SUPERIEUR;}
"as" {return TOK_AS;}
">=" {return TOK_SUPERIEUREGAL;}
"<=" {return TOK_INFERIEUREGAL;}

" "|"\t" {}
"\n" {lineno++;}



{nomClasse} {
yylval.chainecarac = yytext;
return TOK_NOMCLASSE;
}
{nom} {
yylval.chainecarac = yytext;
return TOK_NOM;
}
{nombre} {
yylval.nombre = sscanf(yytext, "%ld", &yylval.nombre);//TODO atoi est probablement mieux
return TOK_NOMBRE;
}

. {        fprintf(stderr,"\tERREUR : Lexeme inconnu a la ligne %d. Il s'agit de %s et comporte %d lettre(s)\n",yylineno,yytext,yyleng);
        erreurlex=true;
	   return yytext[0];
	}

%%











