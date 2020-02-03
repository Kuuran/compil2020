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
%type<T>   const	
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
%type<T>   superieuregal
%type<T>   inferieuregal
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

axiome:		%empty{$$ = makeTree(Evide, 0);}
		|	
		listclasse bloc {}
		|
		bloc{analyseSem($1);
		debut_code();
		code($1, NIL(VarDecl));
		fin_code();}
		|
		axiome error{
			erreursyntx=true;
                        fprintf(stderr,"\tERREUR : Erreur de syntaxe a la ligne %d.\n",lineno);
                       
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
			%empty{};

declconstructeur: 	TOK_DEF identclass TOK_PARENTHESEG listparamclass TOK_PARENTHESED TOK_IS bloc{}
			|
			TOK_DEF identclass TOK_PARENTHESEG listparamclass TOK_PARENTHESED TOK_DEUXPOINTS identclass TOK_PARENTHESEG listargs TOK_PARENTHESED TOK_IS bloc{};


listparamclass:		paramclass TOK_VIRGULE listparamclass{}
			|
			paramclass{}
			|
			%empty{};
  
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
			%empty{};

listparammethod: 	parammethod TOK_VIRGULE listparammethod{}
			|
			parammethod{}
			|
			%empty{};
			
parammethod:		identval TOK_DEUXPOINTS identclass{};

listargs: 		expression TOK_VIRGULE listargs{}
			|
			expression{}
			|
			%empty{};

expression:		identclass{} 
			|
			identval{$$ = makeLeafStr(Eidvar, $1);}
			|
			const{$$ = $1;}
			|
			TOK_PARENTHESEG TOK_AS identclass TOK_DEUXPOINTS expression TOK_PARENTHESED{}
			|
			TOK_PARENTHESEG expression TOK_PARENTHESED{$$=$2;}
			|
			selection{}
			|
			instanciation{}
			|
			envoimsg{}
			|
			expwithop{$$ = $1;};

instruction:	affectation{$$ = $1;}
		|
		expression TOK_POINTVIRGULE {$$=$1;}
		|
		bloc{$$ = $1;}
		|
		TOK_RETURN TOK_POINTVIRGULE{}
		|
		TOK_IF expression TOK_THEN instruction TOK_ELSE instruction{$$=makeTree(Eite, 3, $2, $4, $6);};

identclass: 		TOK_NOMCLASSE{$$ = $1;}
	
identval: 		TOK_THIS{$$ = "this";}
			|
			TOK_SUPER{$$ = "super";}
           		|
        		TOK_RESULT{$$ = "result";}
			|
			TOK_NOM {$$ = $1;}


selection:		expression TOK_POINT identval{}



const:			TOK_CHAINECARAC{$$ = makeLeafStr(Estr, $1);}
			|
			TOK_NOMBRE{$$ = makeLeafInt(Econst, $1);};

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

concat: 		expression TOK_CONCAT expression{$$ = makeTree(Econcat, 2, $1, $3);};
nonegalite: 		expression TOK_DIFFERENCE expression{$$ = makeTree(Eneq, 2, $1, $3);};
egalite: 		expression TOK_EGALITE expression{$$ = makeTree(Eeq, 2, $1, $3);};
moinsunaire: 		TOK_MOINS expression{$$ = makeTree(Eaddu, 1, $2);};
plusunaire: 		TOK_PLUS expression{$$ = makeTree(Eminusu, 1, $2);};
addition: 		expression TOK_PLUS expression{$$ = makeTree(Eadd, 2, $1, $3);};
soustraction: 		expression TOK_MOINS expression{$$ = makeTree(Eminus, 2, $1, $3);};
multiplication: 	expression TOK_FOIS expression{$$ = makeTree(Emult, 2, $1, $3);};
superieur: 		expression TOK_SUPERIEUR expression{$$ = makeTree(Esup, 2, $1, $3);};
inferieur: 		expression TOK_INFERIEUR expression{$$ = makeTree(Einf, 2, $1, $3);};
division: 		expression TOK_DIVISION expression{$$ = makeTree(Ediv, 2, $1, $3);};
superieuregal: 		expression TOK_SUPERIEUREGAL expression{$$ = makeTree(Esupeq, 2, $1, $3);};
inferieuregal: 		expression TOK_INFERIEUREGAL expression{$$ = makeTree(Einfeq, 2, $1, $3);};


bloc:	TOK_CROCHETG listinstructionsOpt TOK_CROCHETD{$$= makeTree(Ebloc, 2, makeTree(Evide, 0), $2);}
	|
	TOK_CROCHETG listdeclarationvar TOK_IS listinstructions TOK_CROCHETD{$$= makeTree(Ebloc, 2, makeLeafVar(Edecl, $2), $4);}


declarationvar:		identval TOK_DEUXPOINTS identclass TOK_POINTVIRGULE{$$ = makeVar((char*)$1, (char*)$3, INSTANCE);}
			|
			identval TOK_DEUXPOINTS identclass TOK_AFFECTATION expression TOK_POINTVIRGULE{};

affectation:		expression TOK_AFFECTATION expression TOK_POINTVIRGULE{$$ = makeTree(Eaff, 2, $1, $3);};


listdeclarationvar: 	declarationvar listdeclarationvar{$$ = addToScope($1, $2);}
			|
			%empty{$$ = NIL(VarDecl);};

listinstructionsOpt:	instruction listinstructionsOpt{$$ = makeTree(Elist, 2, $1, $2);}
			|
			%empty{$$ = makeTree(Evide, 0);};
listinstructions:       instruction listinstructionsOpt{$$ = makeTree(Elist, 2, $1, $2);};

%%


