d[0-9]
l[a-zA-Z]
space[ \t\n]
%{
#include<stdio.h>
#include<string.h>
char line[20];
int count=0,i=0;
char a;
char arr[]="ay";

%}

%%
({d})(({l})|({d}))*   {
                            printf("%s starts with digit and converted to ",yytext);
                            a = yytext[0]; 
		                    while(i < yyleng-1)
		                    {
		                    	yytext[i]=yytext[i+1];
		                    	i++;
		                    }
		                    yytext[yyleng-1]=a;
		                    strcat(yytext,arr);
		                    printf("%s \n",yytext);
		                    strcpy(line,yytext);
		                   
		                    i=0;
                      }

{space}?(a|e|i|o|u|A|E|I|O|U)(({l})|({d}))* 
                      {
		                    printf("%s starts with vowel and converted to ",yytext);
		                    strcat(yytext,arr);
		                    printf("%s \n",yytext);
		                    strcpy(line,yytext);
		                    
                      }

%%
int yywrap()
{
    return 1;
}

int main(int argc,char *argv[])
{
	yyin=fopen(argv[1],"r");
	yylex();
	return 0;
}
