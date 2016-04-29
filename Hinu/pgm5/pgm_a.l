d[0-9]
P[+]
N[-]
%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int l,max=0;

%}

%%

({P}+(0|00)?{N}+) {

	if(yyleng > max)
	{
		max=l;
		printf("maximal is ( %s ) of length %d \n",yytext,yyleng);
        fprintf(yyout,"( %s )",yytext);
	}

}
%%
int yywrap()
{
	return 1;
}

int main(int argc,char *argv[])
{
    yyin = fopen("out.txt","r");
    yyout = fopen("final_out.txt","w");
    yylex();
    fclose(yyin);
    fclose(yyout);
    return 0;
}