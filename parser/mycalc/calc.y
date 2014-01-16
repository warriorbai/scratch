/* http://publib.boulder.ibm.com/infocenter/aix/v6r1/topic/com.ibm.aix.genprogc/doc/genprogc/ie_prog_4lex_yacc.htm */

%{
#include <stdio.h>

extern "C" {
/* ask c++ to keep the function name */
int yyparse(void);
int yylex(void); 
void yyerror(char *);
int yywrap();
}

int regs[26];
int base;

%}

%start list

%union { int ival; }

%type <ival> Expr
%type <ival> Number
%type <ival> DIGIT
%type <ival> LETTER

%token DIGIT LETTER

%left '|'
%left '&'
%left '+' '-'
%left '*' '/' '%'
%left UMINUS  /*supplies precedence for unary minus */

%%                   /* beginning of rules section */

list:                       /*empty */
         | list stat '\n'
         | list error '\n'
         {
           yyerrok;
         }
         ;

stat:    Expr
         {
           printf("%d\n",$1);
         }
         | LETTER '=' Expr
         {
           regs[$1] = $3;
         }

         ;

Expr:    '(' Expr ')'
         {
           $$ = $2;
         }
         | Expr '*' Expr
         {

           $$ = $1 * $3;
         }
         | Expr '/' Expr
         {
           $$ = $1 / $3;
         }
         | Expr '%' Expr
         {
           $$ = $1 % $3;
         }
         | Expr '+' Expr
         {
           $$ = $1 + $3;
         }
         | Expr '-' Expr
         {
           $$ = $1 - $3;
         }
         | Expr '&' Expr
         {
           $$ = $1 & $3;
         }
         | Expr '|' Expr
         {
           $$ = $1 | $3;
         }
         | '-' Expr %prec UMINUS
         {
           $$ = -$2;
         }
         | LETTER
         {
           $$ = regs[$1];
         }
         | Number
         ;

Number:  DIGIT
         {
           $$ = $1;
           base = ($1==0) ? 8 : 10;
         }       |
         Number DIGIT
         {
           $$ = base * $1 + $2;
         }
         ;

%%

// main() was moved to main.cxx
//main()
//{
//   return(yyparse());
//}


void yyerror(char *s)
{
    // This error-handling subroutine only prints a syntax error message.
    fprintf(stderr, "%s\n", s);
}

int yywrap()
{
    // The wrap-up subroutine that returns a value of 1 when the end of input occurs.
    return(1);
}

