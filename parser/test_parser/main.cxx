#include"main.h"
extern "C" 
{ 
    int yylex(void);
} 

int main() {
    cout<<"call main function!"<<endl;
    yylex();
}
