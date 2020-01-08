%{

#include "analyse.h"

bool erreursyntx=false;
extern int lineno;
extern bool erreurlex;
bool erreursem = false;

%}

%union {
	long nombre;
	char* texte;

}




%right TOK_AFFECTATION
%left TOK_DIFFERENCE	TOK_EGALITE
%left TOK_INFERIEUR	TOK_SUPERIEUR	TOK_INFERIEUREGAL	TOK_SUPERIEUREGAL
%left TOK_PLUS	TOK_MOINS
%left TOK_FOIS	TOK_DIVISION	  TOK_CONCAT
%nonassoc TOK_POINT
%right TOK_PARENTHESED    TOK_PARENTHESEG

 


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
%type<texte>    identinstance //this et super  TODO wtf c'est la merde faut que je fasse rentrer this et super dans la grammaire


%token<texte> TOK_CHAINECARAC
%token<texte> TOK_NOMCLASSE
%token<texte> TOK_NOM
%token<nombre> TOK_NOMBRE
%token TOK_CLASS
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

axiome:		%empty{}
		|	
		listclasse bloc {printf("Classe et bloc\n\n");}
		|
		bloc{printf("Bloc\n\n");}
		|
		axiome error{ //todo est-ce que c'est utile/valide?
			erreursyntx=true;
                        fprintf(stderr,"\tERREUR : Erreur de syntaxe a la ligne %d.\n",lineno);
                        erreursem=true;
                       
		};      

listclasse:	declclasse listclasse{}
		|
		declclasse{};

declclasse:	TOK_CLASS identclass TOK_PARENTHESEG listparamclass TOK_PARENTHESED TOK_IS TOK_CROCHETG interieurclasse TOK_CROCHETD{}
		|
		TOK_CLASS identclass TOK_PARENTHESEG listparamclass TOK_PARENTHESED TOK_EXTENDS identclass TOK_IS TOK_CROCHETG interieurclasse TOK_CROCHETD{};

interieurclasse: 	declattribut interieurclasse{}
			|
			declmethode interieurclasse{}
			|
			declconstructeur interieurclasse{}
			|				
			%empty{/*todo check*/};

declconstructeur: 	TOK_DEF identclass TOK_PARENTHESEG listparamclass TOK_PARENTHESED TOK_IS bloc{}
			|
			TOK_DEF identclass TOK_PARENTHESEG listparamclass TOK_PARENTHESED TOK_DEUXPOINTS identclass TOK_PARENTHESEG listargs TOK_PARENTHESED TOK_IS bloc{};


listparamclass:		paramclass TOK_VIRGULE listparamclass{}
			|
			paramclass{}
			|
			%empty{/*todo check*/};

paramclass:		identval TOK_DEUXPOINTS identclass{}
			|
			TOK_VAR identval TOK_DEUXPOINTS identclass{};

declattribut:		TOK_VAR identval TOK_DEUXPOINTS identclass TOK_POINTVIRGULE{}
			|
			TOK_VAR TOK_STATIC identval TOK_DEUXPOINTS identclass TOK_POINTVIRGULE{};
			|
			TOK_VAR identval TOK_DEUXPOINTS identclass TOK_AFFECTATION expression TOK_POINTVIRGULE{}	
			|
			TOK_VAR TOK_STATIC identval TOK_DEUXPOINTS identclass TOK_AFFECTATION expression TOK_POINTVIRGULE{};

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
			%empty{/*todo check*/};

listparammethod: 	parammethod TOK_VIRGULE listparammethod{}
			|
			parammethod{}
			|
			%empty{/*todo check*/};
			
parammethod:		identval TOK_DEUXPOINTS identclass{};

listargs: 		expression TOK_VIRGULE listargs{}
			|
			expression{}
			|
			%empty{/*todo check*/};

expression:		identclass{} 
			|
			identval{}
			|
			const{}
			|
			TOK_PARENTHESEG TOK_AS identclass TOK_DEUXPOINTS expression TOK_PARENTHESED{}
			|
			TOK_PARENTHESEG expression TOK_PARENTHESED{}
			|
			selection{}
			|
			instanciation{}
			|
			envoimsg{}
			|
			expwithop{};

instruction:	affectation{}
		|
		expression TOK_POINTVIRGULE {}
		|
		bloc{}
		|
		TOK_RETURN TOK_POINTVIRGULE{}
		|
		TOK_IF expression TOK_THEN instruction TOK_ELSE instruction{};

identclass: 		TOK_NOMCLASSE{};

identval: 		TOK_RESULT{}
			|
			TOK_NOM {}


selection:		expression TOK_POINT identval{}



const:			TOK_CHAINECARAC{}
			|
			TOK_NOMBRE{};

instanciation:		TOK_NEW identclass TOK_PARENTHESEG listargs TOK_PARENTHESED{};

envoimsg:  		expression TOK_POINT identval TOK_PARENTHESEG listargs TOK_PARENTHESED{}


expwithop:		superieur{}
			|
			inferieur{}
			|
			egalite{}
			|
			nonegalite{}
			|
			concat{}
			|
			moinsunaire{}
			|
			plusunaire{}
			|
			addition{}
			|
			soustraction{}
			|
			multiplication{}
			|
			division{}
			|
			superieuregal{}
			|
			inferieuregal{};

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


bloc:	TOK_CROCHETG listinstructionsOpt TOK_CROCHETD{}
	|
	TOK_CROCHETG listdeclarationvar TOK_IS listinstructions TOK_CROCHETD{}


declarationvar:		identval TOK_DEUXPOINTS identclass TOK_POINTVIRGULE{}
			|
			identval TOK_DEUXPOINTS identclass TOK_AFFECTATION expression TOK_POINTVIRGULE{};

affectation:		expression TOK_AFFECTATION expression TOK_POINTVIRGULE{};


listdeclarationvar: 	declarationvar listdeclarationvar{}
			|
			%empty{/*todo check*/};

listinstructionsOpt:	instruction listinstructions{}
			|
			%empty{};

listinstructions:	instruction listinstructions{}

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












	






