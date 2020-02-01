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


 


%type<T>   axiome	
%type<T>   listclasse	
%type<D>   declclasse	
%type<T>   interieurclasse	
%type<D>   declconstructeur	
%type<T>   listparamclass	
%type<D>   paramclass	
%type<D>   declattribut	
%type<D>   declmethode	
%type<T>   listparammethod	
%type<T>   parammethod	
%type<T>   listargs	
%type<T>   expression
%type<S>   identclass	
%type<S>   identval	
%type<T>   selection	
%type<S>   const	
%type<T>   instanciation	
%type<T>   envoimsg	
%type<T>   expwithop	
%type<T>   concat	
%type<T>   nonegalite	
%type<T>   egalite	
%type<T>   moinsunaire	
%type<T>   plusunaire	
%type<T>   addition	
%type<T>   soustraction	
%type<T>   multiplication	
%type<T>   superieur	
%type<T>   inferieur	
%type<T>   division	
%type<T>   instruction	
%type<T>   bloc	
%type<D>   declarationvar	
%type<T>   affectation	
%type<D>   listdeclarationvar
%type<T>   listinstructions	
%type<T>   listinstructionsOpt


%token<S> TOK_CHAINECARAC
%token<S> TOK_NOMCLASSE
%token<S> TOK_NOM
%token<I> TOK_NOMBRE
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
		bloc{$$ = makeTree(AXIOME, 2, makeTree(Evide, 0), $1);}
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
			identval{$$ = makeLeafStr(Eidvar, $1);}
			|
			const{$$ = makeLeafStr(Econst, $1);}
			|
			TOK_PARENTHESEG TOK_AS identclass TOK_DEUXPOINTS expression TOK_PARENTHESED{}
			|
			TOK_PARENTHESEG expression TOK_PARENTHESED{$$=$2;}
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
		expression TOK_POINTVIRGULE {$$=$1;}
		|
		bloc{$$ = $1;}
		|
		TOK_RETURN TOK_POINTVIRGULE{/*$$=aller fin de boucle*/}
		|
		TOK_IF expression TOK_THEN instruction TOK_ELSE instruction{/*$$=$1,$4,$6*/};

identclass: 		TOK_NOMCLASSE{$$ = $1;}
	
identval: 		TOK_THIS{$$ = "this";}
			|
			TOK_SUPER{$$ = "super";}
           		|
        		TOK_RESULT{$$ = "result";}
			|
			TOK_NOM {$$ = $1;}


selection:		expression TOK_POINT identval{}



const:			TOK_CHAINECARAC{$$ = $1;}
			|
			TOK_NOMBRE{$$ = $1;};

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
			superieuregal{/*$$ = $1;*/}
			|
			inferieuregal{/*$$ = $1;*/};

concat: 		expression TOK_CONCAT expression{};
nonegalite: 		expression TOK_DIFFERENCE expression{};
egalite: 		expression TOK_EGALITE expression{};
moinsunaire: 		TOK_MOINS expression{};
plusunaire: 		TOK_PLUS expression{};
addition: 		expression TOK_PLUS expression{$$ = makeTree(Eadd, 2, $1, $3);};
soustraction: 		expression TOK_MOINS expression{};
multiplication: 	expression TOK_FOIS expression{};
superieur: 		expression TOK_SUPERIEUR expression{};
inferieur: 		expression TOK_INFERIEUR expression{};
division: 		expression TOK_DIVISION expression{};
superieuregal: 		expression TOK_SUPERIEUREGAL expression{};
inferieuregal: 		expression TOK_INFERIEUREGAL expression{};


bloc:	TOK_CROCHETG listinstructionsOpt TOK_CROCHETD{$$= makeTree(Ebloc, 2, makeTree(Evide, 0), $2);}
	|
	TOK_CROCHETG listdeclarationvar TOK_IS listinstructions TOK_CROCHETD{$$= makeTree(Ebloc, 2, makeLeafVar(Elist, $2), $4);}


declarationvar:		identval TOK_DEUXPOINTS identclass TOK_POINTVIRGULE{$$ = makeVar($1, $3, INSTANCE);}
			|
			identval TOK_DEUXPOINTS identclass TOK_AFFECTATION expression TOK_POINTVIRGULE{};

affectation:		expression TOK_AFFECTATION expression TOK_POINTVIRGULE{$$ = makeTree(Eaff, 2, $1, $3);};


listdeclarationvar: 	declarationvar listdeclarationvar{$$ = addToScope($1, $2);}
			|
			%empty{$$ = NIL(Tree);};

listinstructionsOpt:	instruction listinstructionsOpt{$$ = makeTree(Elist, 2, $1, $2);}
			|
			%empty{$$ = NIL(Tree);};
listinstructions:       instruction listinstructionsOpt{$$ = makeTree(Elist, 2, $1, $2);};

%%

/*int main(void){
 
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
}*/
/*void yyerror(char *s) {
	erreursyntx=true;
        fprintf(stderr, "Erreur de syntaxe a la ligne %d: %s\n", lineno, s);
}*/
		


			















	






