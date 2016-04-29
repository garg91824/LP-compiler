%{
#include<stdio.h>
int i=0,yr=0,valid=0;
%}
%%
([0-2][0-9]|[3][0-1])\/((0(1|3|5|7|8))|(10|12))\/([1-2][0-9][0-9][-0-9])(.) {valid=1; printf("%s It is a valid date\n",yytext); }
([0-2][0-9]|[3][0-1])\/(Jan|March|May|July|August|October|December)\/([1-2][0-9][0-9][-0-9])(.) {valid=1; printf("%s It is a valid date\n",yytext); }

([0-2][0-9]|30)\/((0(4|6|9))|11)\/([1-2][0-9][0-9][0-9])(.) {valid=1;printf("%s It is a valid date\n",yytext);}

([0-1][0-9]|2[0-8])\/02\/([1-2][0-9][0-9][0-9])(.) {valid=1; printf("%s It is a valid date\n",yytext);}

29\/02\/([1-2][0-9][0-9][0-9])(.) { while(yytext[i]!='/')i++; i++;while(yytext[i]!='/')i++;i++;while(i<yyleng)yr=(10*yr)+(yytext[i++]-'0'); 
if(yr%4==0||(yr%100==0&&yr%400!=0))valid=1; printf("%s It is a valid date\n",yytext);}
%%
main()
{
yyin=fopen("vpn.txt","r");
yylex();
}

int yywrap()
{
return 1;
}