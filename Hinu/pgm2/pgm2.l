space[\t\n]
%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

%}
%%
[ \n\t]+         {
	                 yytext[1]='\0';
	                 fprintf(yyout,"%s",yytext); 
                     

                  }
[^\n\t]   {
	    fprintf(yyout,"%s",yytext); 
    }
%%
int yywrap()
{
	return 1;
}
int main(int argc,char *argv[])
{
	yyin=fopen(argv[1],"r");
    yyout = fopen("out.c","w");
    yylex();
    return 0;

}
