%{

#include "analyse.h"

bool erreursyntx=false;
extern int lineno;
extern bool erreurlex;

%}

%union {
	long nombre;
	char* chainecarac;

}





%nonassoc TOK_DIFFERENCE	TOK_EGALITE
%nonassoc TOK_INFERIEUR	TOK_SUPERIEUR	TOK_INFERIEUREGAL	TOK_SUPERIEUREGAL
%left TOK_PLUS	TOK_MOINS
%left TOK_FOIS	TOK_DIVISION TOK_CONCAT
%nonassoc TOK_POINT


 


%type<texte>   axiome	
%type<texte>   listclasse	
%type<texte>   declclasse	
%type<texte>   interieurclasse	
%type<texte>   declconstructeur	
%type<texte>   listparamclass	
%type<texte>   paramclass	
%type<texte>   declattribut	
%type<texte>   declmethode	
%type<texte>   listparammethod	
%type<texte>   parammethod	
%type<texte>   listargs	
%type<texte>   expression
%type<texte>   identclass	
%type<texte>   identval	
%type<texte>   selection	
%type<texte>   const	
%type<texte>   instanciation	
%type<texte>   envoimsg	
%type<texte>   expwithop	
%type<texte>   concat	
%type<texte>   nonegalite	
%type<texte>   egalite	
%type<texte>   moinsunaire	
%type<texte>   plusunaire	
%type<texte>   addition	
%type<texte>   soustraction	
%type<texte>   multiplication	
%type<texte>   superieur	
%type<texte>   inferieur	
%type<texte>   division	
%type<texte>   instruction	
%type<texte>   bloc	
%type<texte>   declarationvar	
%type<texte>   affectation	
%type<texte>   listdeclarationvar
%type<texte>   listinstructions	
%type<texte>   listinstructionsOpt


%token<texte> TOK_CHAINECARAC
%token<texte> TOK_NOMCLASSE
%token<texte> TOK_NOM
%token<texte> TOK_NOMBRE
%token TOK_AFFECTATION
%token TOK_PARENTHESED
%token TOK_PARENTHESEG
%token TOK_CLASS
%token TOK_CONCAT
%token TOK_EXTENDS
%token TOK_IS
%token TOK_CROCHETG
%token TOK_CROCHETD
%token TOK_DEF
%token TOK_DEUXPOINTS
%token TOK_VIRGULE
%token TOK_VAR
%token TOK_POINTVIRGULE
%token TOK_STATIC
%token TOK_OVERRIDE
%token TOK_THIS
%token TOK_SUPER
%token TOK_RESULT
%token TOK_POINT
%token TOK_NEW
%token TOK_RETURN
%token TOK_IF
%token TOK_THEN
%token TOK_ELSE
%token TOK_AS


%%

//PAS DE CLASSES POUR LE MOMENT



axiome:		%empty{$$ = NIL(Tree);}
		|	
		listclasse bloc {/*$$ = $1, $2;*/}
		|
		bloc{$$ = $1;}
		|
		axiome error{
			erreursyntx=true;
                        fprintf(stderr,"\tERREUR : Erreur de syntaxe a la ligne %d.\n",lineno);
                       
		};      

listclasse:	declclasse listclasse{/*$$ = $1, $2;*/}
		|
		declclasse{/*$$ = $1*/};

declclasse:	TOK_CLASS identclass TOK_PARENTHESEG listparamclass TOK_PARENTHESED TOK_IS TOK_CROCHETG interieurclasse TOK_CROCHETD{/*$$=makeClass($2,$4,$8.champ,NIL(ClassP),$8.method)*/}
		|
		TOK_CLASS identclass TOK_PARENTHESEG listparamclass TOK_PARENTHESED TOK_EXTENDS identclass TOK_IS TOK_CROCHETG interieurclasse TOK_CROCHETD{/*$$=makeClass($2,$4,$7,$10.champ,$,$8.method)*/};

interieurclasse: 	declattribut interieurclasse{/*$$ = $1, $2;*/}
			|
			declmethode interieurclasse{/*$$ = $1, $2;*/}
			|
			declconstructeur interieurclasse{/*$$ = $1, $2;*/}
			|				
			%empty{/*$$ = NIL(Tree);*/};

declconstructeur: 	TOK_DEF identclass TOK_PARENTHESEG listparamclass TOK_PARENTHESED TOK_IS bloc{}
			|
			TOK_DEF identclass TOK_PARENTHESEG listparamclass TOK_PARENTHESED TOK_DEUXPOINTS identclass TOK_PARENTHESEG listargs TOK_PARENTHESED TOK_IS bloc{};


listparamclass:		paramclass TOK_VIRGULE listparamclass{/*$$= $1, $3;*/}
			|
			paramclass{/*$$ = $1;*/}
			|
			%empty{/*$$ = NIL(Tree);*/};
  
paramclass:		identval TOK_DEUXPOINTS identclass{/*$$=makeval($1.val,$1.type,0), $3;*/} 
			|
			TOK_VAR identval TOK_DEUXPOINTS identclass{/*$$=makeattribut($2.val,$1.type,0), $4;*/}; 

declattribut:		TOK_VAR identval TOK_DEUXPOINTS identclass TOK_POINTVIRGULE{/*$$=makeattribut($2.val,$4,0);*/}
			|
			TOK_VAR TOK_STATIC identval TOK_DEUXPOINTS identclass TOK_POINTVIRGULE{/*$$=makeattribut($3.val,$5,1);*/};  //1 correspond au booléen statique
			|
			TOK_VAR identval TOK_DEUXPOINTS identclass TOK_AFFECTATION expression TOK_POINTVIRGULE{/*$$=makeattribut($2.val,$4)*/}	
			|
			TOK_VAR TOK_STATIC identval TOK_DEUXPOINTS identclass TOK_AFFECTATION expression TOK_POINTVIRGULE{/*$$=makeattribut($2.val,$4)*/};

declmethode:		TOK_DEF staticoverideoption identval TOK_PARENTHESEG listparammethod TOK_PARENTHESED TOK_DEUXPOINTS identclass TOK_AFFECTATION expression{}
			|
			TOK_DEF staticoverideoption identval TOK_PARENTHESEG listparammethod TOK_PARENTHESED TOK_IS bloc{}
			|
			TOK_DEF staticoverideoption identval TOK_PARENTHESEG listparammethod TOK_PARENTHESED TOK_DEUXPOINTS identclass TOK_IS bloc{};

staticoverideoption:   	TOK_STATIC{}
			|
			TOK_OVERRIDE{}
			|
			TOK_STATIC TOK_OVERRIDE{}
			|
			%empty{/*$$ = NIL(Tree);*/};

listparammethod: 	parammethod TOK_VIRGULE listparammethod{}
			|
			parammethod{/*$$ = $1;*/}
			|
			%empty{/*$$ = NIL(Tree);*/};
			
parammethod:		identval TOK_DEUXPOINTS identclass{};

listargs: 		expression TOK_VIRGULE listargs{}
			|
			expression{/*$$ = $1;*/}
			|
			%empty{/*$$ = NIL(Tree);*/};

expression:		identclass{/*$$ = $1;*/} 
			|
			identval{$$ = $1;}
			|
			const{$$ = $1;}
			|
			TOK_PARENTHESEG TOK_AS identclass TOK_DEUXPOINTS expression TOK_PARENTHESED{}
			|
			TOK_PARENTHESEG expression TOK_PARENTHESED{$$=$2}
			|
			selection{/*$$ = $1;*/}
			|
			instanciation{/*$$ = $1;*/}
			|
			envoimsg{/*$$ = $1;*/}
			|
			expwithop{$$ = $1;};

instruction:	affectation{$$ = $1;}
		|
		expression TOK_POINTVIRGULE {$$=$1}
		|
		bloc{$$ = $1;}
		|
		TOK_RETURN TOK_POINTVIRGULE{$$=/*aller fin de boucle*/}
		|
		TOK_IF expression TOK_THEN instruction TOK_ELSE instruction{$$=$1,$4,$6};

identclass: 
			TOK_NOMCLASSE{/*$$ = makeLeafStr(, $1);*/};
	
identval: 		TOK_THIS{/*$$ = makeLeafStr(, $1);*/}
			|
			TOK_SUPER{/*$$ = makeLeafStr(, $1);*/}
           		|
        		TOK_RESULT{/*$$ = makeLeafStr(, $1);*/}
			|
			TOK_NOM {$$ = makeLeafStr(/*TODO etiquette*/, $1);}


selection:		expression TOK_POINT identval{}



const:			TOK_CHAINECARAC{$$=$1.yylval;}
			|
			TOK_NOMBRE{$$=$1.yylval;};

instanciation:		TOK_NEW identclass TOK_PARENTHESEG listargs TOK_PARENTHESED{};

envoimsg:  		expression TOK_POINT identval TOK_PARENTHESEG listargs TOK_PARENTHESED{};


expwithop:		superieur{$$ = $1;}
			|
			inferieur{$$ = $1;}
			|
			egalite{$$ = $1;}
			|
			nonegalite{$$ = $1;}
			|
			concat{$$ = $1;}
			|
			moinsunaire{$$ = $1;}
			|
			plusunaire{$$ = $1;}
			|
			addition{$$ = $1;}
			|
			soustraction{$$ = $1;}
			|
			multiplication{$$ = $1;}
			|
			division{$$ = $1;}
			|
			superieuregal{$$ = $1;}
			|
			inferieuregal{$$ = $1;};

concat: 		expression TOK_CONCAT expression{};
nonegalite: 		expression TOK_DIFFERENCE expression{};
egalite: 		expression TOK_EGALITE expression{};
moinsunaire: 		TOK_MOINS expression{};
plusunaire: 		TOK_PLUS expression{};
addition: 		expression TOK_PLUS expression{};
soustraction: 		expression TOK_MOINS expression{};
multiplication: 	expression TOK_FOIS expression{};
superieur: 		expression TOK_SUPERIEUR expression{};
inferieur: 		expression TOK_INFERIEUR expression{};
division: 		expression TOK_DIVISION expression{};
superieuregal: 		expression TOK_SUPERIEUREGAL expression{};
inferieuregal: 		expression TOK_INFERIEUREGAL expression{};


bloc:	TOK_CROCHETG listinstructionsOpt TOK_CROCHETD{$$=$2}
	|
	TOK_CROCHETG listdeclarationvar TOK_IS listinstructions TOK_CROCHETD{$$=$2,$4}


declarationvar:		identval TOK_DEUXPOINTS identclass TOK_POINTVIRGULE{}
			|
			identval TOK_DEUXPOINTS identclass TOK_AFFECTATION expression TOK_POINTVIRGULE{};

affectation:		expression TOK_AFFECTATION expression TOK_POINTVIRGULE{};


listdeclarationvar: 	declarationvar listdeclarationvar{}
			|
			%empty{$$ = NIL(Tree);};

listinstructionsOpt:	instruction listinstructionsOpt{}
			|
			%empty{$$ = NIL(Tree);};
listinstructions:       instruction listinstructionsOpt{};

%%

int main(void){
 
        printf("Debut de l'analyse syntaxique :\n");
        yyparse();
        printf("Fin de l'analyse !\n");
        printf("Resultat :\n");
        if(erreurlex){
                printf("\t-- Echec : Certains lexemes ne font pas partie du lexique du langage ! --\n");
                printf("\t-- Echec a l'analyse lexicale --\n");
        }
        else{
                printf("\t-- Succes a l'analyse lexicale ! --\n");
        }
        if(erreursyntx){
                printf("\t-- Echec : Certaines phrases sont syntaxiquement incorrectes ! --\n");
                printf("\t-- Echec a l'analyse syntaxique --\n");
        }
        else{
                printf("\t-- Succes a l'analyse syntaxique ! --\n");
		bool error_semantical=true;
                if(error_semantical){
                        printf("\t-- Echec : Certaines phrases sont semantiquement incorrectes ! --\n");
                        printf("\t-- Echec a l'analyse semantique --\n");
                }
                else{
                        printf("\t-- Succes a l'analyse semantique ! --\n");
                }
        }

        return EXIT_SUCCESS;
}
void yyerror(char *s) {
	erreursyntx=true;
        fprintf(stderr, "Erreur de syntaxe a la ligne %d: %s\n", lineno, s);
}
		


			















	






