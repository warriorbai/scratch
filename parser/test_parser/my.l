%{
#include"main.h"

extern "C" {
    int yylex(void);
}
%}

%%
"+"    { cout<<"plus"<<endl; }  
"-"    { cout<<"minus"<<endl; }
"*"    { cout<<"multiply"<<endl; }
"/"    { cout<<"divide"<<endl; }
[0-9]+ { cout<<"number"<<endl; }

%%
int yywrap () {

    cout<<"call yywrap"<<endl;

}
