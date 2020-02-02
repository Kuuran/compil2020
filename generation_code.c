#include "analyse.h"

typedef struct _HashMap {
    int addr;
    VarDeclP nom;
    struct _HashMap *next;
}HashMap, *HashMapP;


HashMapP findelisteP;           /*récupère le dernier élément de ma liste HashMap*/



void debut_code() {
    fprintf(fichier, "-- Ce fichier est généré par le compilateur -- \n\n");
    fprintf(fichier, "\t START \n");
}

void fin_code() {
    fprintf(fichier, "\t STOP \n");
}


int git;            //récupère l'@ de stockage pour une affectation

HashMapP *hash;           /*initialisation HashMap*/
hash[0] = NEW(1, HashMap);
int i=0;

void code(TreeP ast, VarDeclP list) {

    HashMapP buffer = hash[i];
    VarDeclP bufList = list;

    while(bufList->next != NIL(VarDeclP)){
        buffer->addr = i;
        buffer->nom = list->name;
        fprint(fichier,"\t ALLOC %d \n", 1);
        i++;
        buffer->next = NEW(1, HashMap);
        buffer = buffer->next;
        bufList = bufList->next;
    }

    if(ast) {
        switch(ast->op) { // On switch à partir de l'étiquette de l'AST ?
			case AXIOME:
				if(getChild(ast,0)->op == Evide)){              /*cas ou axiome vide*/
                    fprint(fichier,"\t NOP \n" );
				}else if(getChild(ast,0)->op == Ebloc){         /*cas ou juste un bloc*/
                    code(getChild(ast,0),getChild(getChild(ast,0),0)->u.var);
                }else {                                         /*cas ou on a une liste de classe suivi d'un bloc*/
                    code(getChild(ast,0),getChild(getChild(ast,0),0)->u.var);
                }
				break;
			case Eite:                                          /*if then else*/
				code(getChild(ast,0),list);
				fprint(fichier, "\t JZ else \n");  				/*else = label rentre dans le else*/
				code(getChild(ast,1),list);
				fprint(fichier, "\t JUMP fin \n");				/*fin = label fin instruction*/=
				fprint(fichier, "\t else NOP \n");
				code(getChild(ast,2),list);
				fprint(fichier, "\t fin NOP \n");
				break;
			case Eidvar:
			    buffer = hash[0];
			    while(buffer != NIL(HashMap)){
			        if(strcmp(buffer->nom , ast->u.str)){
			            break;
			        }
			        buffer = buffer->next;
			    }
				fprintf(fichier, "\t PUSHG %s \n", buffer->addr);
				break;
			case Econst:
				fprintf(fichier, "\t PUSHI %d \n", ast->u.val);
				break;
			case Estr:
				fprintf(fichier, "\t PUSHS %s \n", ast->u.str);
				break;
			case Eaff:
				code(getChild(ast,0), list);
				code(getChild(ast,1),list);
				fprintf(fichier, "\t STOREG %s \n", git);
				break;
			case Eadd:
				code(getChild(ast,0));
				code(getChild(ast,1));
				fprintf(fichier, "\t ADD \n");
				break;
            case Eaddu:
                code(getChild(ast,0),list);
                fprint(fichier, "\t PUSHI %d \n", 1);
                fprintf(fichier, "\t ADD \n");
                break;
            case Eminus:
				code(getChild(ast,0));
				code(getChild(ast,1));
				fprintf(fichier, "\t SUB \n");
				break;
            case Eminusu:
                code(getChild(ast,0),list);
                fprint(fichier, "\t PUSHI %d \n", 1);
                fprintf(fichier, "\t SUB \n");
                break;
			case Emult:
				code(getChild(ast,0));
				code(getChild(ast,1));
				fprintf(fichier, "\t MUL \n");
				break;
			case Ediv:
				code(getChild(ast,0));
				code(getChild(ast,1));
				fprintf(fichier, "\t DIV \n");
				break;
			case Eneq:
				if(typage(ast) == INTEGER){               //test d'égalité dans le cas des integer
                    code(getChild(ast,0),list);
                    code(getChild(ast,1),list);
                    fprint(fichier, "\t EQUAL \n");
                    fprint(fichier, "\t NOT \n");
                    break;
                }else {                             //test d'égalité dans le cas des string
                    buffer = hash[0];
                    while(buffer != NIL(HashMap)){
                        if(strcmp(buffer->nom , ast->u.str)){
                            break;
                        }
                        buffer = buffer->next;
                    }
                    fprintf(fichier, "\t LOAD %s \n", buffer->addr);

                    buffer2 = hash[0];
                    while(buffer2 != NIL(HashMap)){
                        if(strcmp(buffer2->nom , ast->u.str)){
                            break;
                        }
                        buffer2 = buffer2->next;
                    }
                    fprintf(fichier, "\t LOAD %s \n", buffer2->addr);
                    fprint(fichier, "\t EQUAL \n");
                    fprint(fichier, "\t NOT \n");
                    break;
				}
            case Eeq:
                if(typage(ast,list) == INTEGER){               //test d'égalité dans le cas des integer
                    code(getChild(ast,0),list);
                    code(getChild(ast,1),list);
                    fprint(fichier, "\t EQUAL \n");
                    break;
                }else {                             //test d'égalité dans le cas des string
                    buffer = hash[0];
                    while(buffer != NIL(HashMap)){
                        if(strcmp(buffer->nom , ast->u.str)){
                            break;
                        }
                        buffer = buffer->next;
                    }
                    fprintf(fichier, "\t LOAD %s \n", buffer->addr);

                    buffer2 = hash[0];
                    while(buffer2 != NIL(HashMap)){
                        if(strcmp(buffer2->nom , ast->u.str)){
                            break;
                        }
                        buffer2 = buffer2->next;
                    }
                    fprintf(fichier, "\t LOAD %s \n", buffer2->addr);
                    fprint(fichier, "\t EQUAL \n");
                    break;
                }
            case Esup:
                code(getChild(ast,0),list);
                code(getChild(ast,1),list);
                fprint(fichier, "\t SUP \n");
                break;
            case Einf:
                code(getChild(ast,0),list);
                code(getChild(ast,1),list);
                fprint(fichier, "\t INF \n");
                break;
            case Einfeq:
                code(getChild(ast,0),list);
                code(getChild(ast,1),list);
                fprint(fichier, "\t SUPEQ \n");
                break;
            case Esupeq:
                code(getChild(ast,0),list);
                code(getChild(ast,1),list);
                fprint(fichier, "\t INFEQ \n");
                break;
            case Evide:
                fprint(fichier,  "\t NOP \n");
		}
    }
}

/*TODO faire la génération de code des classes en prenant en compte les différents ALLOC*/
/*Enew : alloue espace mémoire pour une classe*/
/*Emethode : alloue espace mémoire pour une méthode*/
