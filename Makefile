OBJ=analyse.o analyse_l.o analyse_y.o
CC=gcc
CFLAGS=-Wall -ansi -I./ -g
LDFLAGS= -g -lfl
analyse : $(OBJ)
	$(CC) -o analyse $(OBJ) $(LDFLAGS)

test_lex: analyse_y.h test_lex.o analyse_l.o
	$(CC) -o test_lex  test_lex.o analyse_l.o $(LDFLAGS)

# Si absent lance yacc et fait "mv y.tab.c tp.c" ce qui ecrase notre fichier.
analyse.c :
	echo ''

analyse_l.c :analyselex.lex
	flex -o analyse_l.c analyselex.lex

analyse.o: analyse.c analyse_y.h analyse.h
	$(CC) $(CFLAGS) -c analyse.c

analyse_l.o: analyse_l.c analyse_y.h
	$(CC) $(CFLAGS) -Wno-unused-function -Wno-implicit-function-declaration -c analyse_l.c

analyse_y.o : analyse_y.c
	$(CC) $(CFLAGS) -c analyse_y.c

analyse_y.h tp_y.c : analysesynt.y analyse.h
	bison -v -d -o analyse_y.c analysesynt.y

test_lex.o : test_lex.c analyse.h analyse_y.h
	$(CC) $(CFLAGS) -c test_lex.c

.Phony: clean

clean:
	rm -f *~ analyse.exe* ./analyse *.o analyse_l.o analyse_y.* test_lex analyse_y.output analyse_l.c out.txt
