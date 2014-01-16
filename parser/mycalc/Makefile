#

CC	= g++
RM	= rm -f

YACC	= bison
LEX	= flex
YFLAGS	= -d
CFLAGS	= -O2

SRCS	= calcl.cxx calcy.cxx 
OBJS    = $(SRCS:%.cxx=%.o)
LIB	= libcalc.a

all:
	make lexyacc
	make calc

lexyacc:
	@echo "Making lexyacc"
	$(YACC) $(YFLAGS) calc.y
	mv calc.tab.h calc.h
	mv calc.tab.c calcy.cxx
	$(LEX) calc.l     
	mv lex.yy.c calcl.cxx


$(OBJS): %.o: %.cxx
	@echo "Making $@"
	$(CC) -c -o $@ $<

$(LIB): $(OBJS)
	ar cr $(LIB) $?
	ranlib $(LIB)

main.o: main.cxx
	$(CC) $(CFLAGS) -c main.cxx 

calc: main.o $(LIB)
	@echo "Making $@"
	$(CC) $(CFLAGS) -o $@ main.o $(LIB)

clean:
	$(RM) $(OBJS) $(LIB) main.o calc calc.h calcy.cxx calcl.cxx
