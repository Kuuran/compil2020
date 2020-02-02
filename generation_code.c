#include "analyse.h"

typedef struct _HashMap {
    int addr;
    VarDeclP nom;
    struct _HashMap *next;
}HashMap, *HashMapP;


HashMapP findelisteP;           /*récupère le dernier élément de ma liste HashMap*/

//TODO crée liste
// en longeant l'arbre ; des que j'apercois une liste de déclaration / une déclaration je remplie ma liste de hashage avec valeur et itération
// faire ALLOC




void debut_code() {
    fprintf(fichier, "-- Ce fichier est généré par le compilateur -- \n\n");
    fprintf(fichier, "\t START \n");
}

void fin_code() {
    fprintf(fichier, "\t STOP \n");
}


int git;            //récupère l'@ de stockage pour une affectation

void code(TreeP ast, VarDeclP list) {
    if(ast) {
        switch(ast->op) { // On switch à partir de l'étiquette de l'AST ?
			case AXIOME:
				if(ast->getChild(ast,0)->op == Evide)){             /*cas ou axiome vide*/
                    //fprintf(fichier, "\t START \n");
                    fprint(fichier,"\t NOP \n" );
                    //fprintf(fichier, "\t STOP \n");
				}else if(ast->getChild(ast,0)->op == Ebloc){        /*cas ou juste un bloc*/
                    //fprintf(fichier, "\t START \n");
                    code(ast->getChild(ast,0),list);
                    //fprintf(fichier, "\t STOP \n");
                }else {                                             /*cas ou on a une liste de classe suivi d'un bloc*/
                    //fprintf(fichier, "\t START \n");
                    code(ast->getChild(ast,0),ast->getChild(ast,1));                /*TODO revoir le cas de la liste de classe comment le prendre en compte ici*/
                    //fprintf(fichier, "\t STOP \n";
                }
				break;
			case Eite:                                              /*if then else*/
				code(ast->getChild(ast,0),list);
				fprint(fichier, "\t JZ else \n");  				/*else = label rentre dans le else*/
				code(ast->getChild(ast,1),list);
				fprint(fichier, "\t JUMP fin \n");				/*fin = label fin instruction*/=
				fprint(fichier, "\t else NOP \n");
				code(ast->getChild(ast,2),list);
				fprint(fichier, "\t fin NOP \n");
				break;
			case Eidvar:
			    int iteX=-1;
			    VarDeclP buffer = list;
			    while(buffer != NIL(VarDecl)){
			        iteX++;
			        //todo alloc la variable parcouru
			        //todo remplir liste de hash avec la valeur et l'itération = @ de mon élément
			        if(strcmp(buffer->name , ast->u.str)){
			            git = iteX;
			            break;
			        }
			        buffer = buffer->next;
			    }
				fprintf(fichier, "\t PUSHG %s \n", iteX);
				break;
			case Econst:
				fprintf(fichier, "\t PUSHI %d \n", ast->u.val);
				break;
			case Estr:
				fprintf(fichier, "\t PUSHS %s \n", ast->u.str);
				break;
			case Eaff:
				code(ast->getChild(ast,0), list);
				code(ast->getChild(ast,1),list);
				fprintf(fichier, "\t STOREG %s \n", git);
				break;
			case Eadd:
				code(ast->getChild(ast,0));
				code(ast->getChild(ast,1));
				fprintf(fichier, "\t ADD \n");
				break;
            case Eaddu:
                code(ast->getChild(ast,0),list);
                fprint(fichier, "\t PUSHI %d \n", 1);
                fprintf(fichier, "\t ADD \n");
                break;
            case Eminus:
				code(ast->getChild(ast,0));
				code(ast->getChild(ast,1));
				fprintf(fichier, "\t SUB \n");
				break;
            case Eminusu:
                code(ast->getChild(ast,0),list);
                fprint(fichier, "\t PUSHI %d \n", 1);
                fprintf(fichier, "\t SUB \n");
                break;
			case Emult:
				code(ast->getChild(ast,0));
				code(ast->getChild(ast,1));
				fprintf(fichier, "\t MUL \n");
				break;
			case Ediv:
				code(ast->getChild(ast,0));
				code(ast->getChild(ast,1));
				fprintf(fichier, "\t DIV \n");
				break;
			case Eneq:
				if(typage(ast) == 3){               //test d'égalité dans le cas des integer
                    code(ast->getChild(ast,0),list);
                    code(ast->getChild(ast,1),list);
                    fprint(fichier, "\t EQUAL \n");
                    fprint(fichier, "\t NOT \n");
                    break;
                }else {                             //test d'égalité dans le cas des string
				    //TODO prendre la liste des string la comparer
                    fprint(fichier, "\t EQUAL \n");
                    fprint(fichier, "\t NOT \n");
                    break;
				}
            case Eeq:
                if(typage(ast,list) == 3){               //test d'égalité dans le cas des integer
                    code(ast->getChild(ast,0),list);
                    code(ast->getChild(ast,1),list);
                    fprint(fichier, "\t EQUAL \n");
                    break;
                }else {                             //test d'égalité dans le cas des string
                    //TODO prendre la liste des string la comparer
                    fprint(fichier, "\t EQUAL \n");
                    break;
                }
            case Esup:
                code(ast->getChild(ast,0),list);
                code(ast->getChild(ast,1),list);
                fprint(fichier, "\t SUP \n");
                break;
            case Einf:
                code(ast->getChild(ast,0),list);
                code(ast->getChild(ast,1),list);
                fprint(fichier, "\t INF \n");
                break;
            case Einfeq:
                code(ast->getChild(ast,0),list);
                code(ast->getChild(ast,1),list);
                fprint(fichier, "\t SUPEQ \n");
                break;
            case Esupeq:
                code(ast->getChild(ast,0),list);
                code(ast->getChild(ast,1),list);
                fprint(fichier, "\t INFEQ \n");
                break;
            case Evide:
                fprint(fichier,  "\t NOP \n");
		}
    }
}

/*TODO faire la génération de code des classes en prenant en compte les différents ALLOC*/
