#include <stdlib.h>
#include <stdio.h>

extern "C" { int yyparse (void); } // defined in calc.tab.cxx (calc.y)

// The required main program that calls the yyparse subroutine to start the program.
int main ()
{
    return yyparse();
}
