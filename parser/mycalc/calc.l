/* http://publib.boulder.ibm.com/infocenter/aix/v6r1/topic/com.ibm.aix.genprogc/doc/genprogc/ie_prog_4lex_yacc.htm */

%{
 
#include <stdio.h>
#include "calc.h"

extern "C" {int yylex(void);}

int c;
/* extern YYSTYPE yylval; */ /* bison does this automatically, but not yacc */

%}

ALPHA    [a-z]
DIGIT    [0-9]
SPACE    [ \r\t]

%%

SPACE       ;
ALPHA     {
            c = yytext[0];
            yylval.ival = (int) (c - 'a');
            return(LETTER);
          }
DIGIT     {
            c = yytext[0];
            yylval.ival = (int) (c - '0');
            return(DIGIT);
          }
[^a-z0-9\b]    {
                 c = yytext[0];
                 return(c);
              }

