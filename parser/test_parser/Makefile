CC = g++
LEX = flex
YACC = bison
run: lex.yy.o main.o
	$(CC) lex.yy.o main.o -o run 

lex.yy.o: lex.yy.c
	$(CC) -c lex.yy.c

lex.yy.c: my.l
	$(LEX) my.l

main.o: main.cxx
	$(CC) -c main.cxx


clean:
	-rm  -f main.o lex.yy.o run lex.yy.c

