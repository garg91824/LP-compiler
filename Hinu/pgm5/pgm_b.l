d[0-9]
P[+]
N[-]
%{

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int i=0,r=0,c=0,mat[10][10],curr,max=0;
char vm[256],dm[256],dm1[256];
int prev;

%}

%%
[\n] {
	c=0;
	strcat(vm,"n");
	r+=1;
	strcat(dm,"n");
	strcat(dm1,"n");
}
{d}+ {
	if(c==0)
    {
    	strcat(vm,yytext);
		prev=atoi(yytext);
		mat[r][c]=prev;
		c+=1;
	}
	else
	{
		
		curr = atoi(yytext);
		int p = curr-prev;
		mat[r][c]=curr;
		c+=1;
		prev=curr;
		strcat(vm,yytext);
		if(p>0)
			strcat(dm1,"+");
		else if(p==0)
			strcat(dm1,"0");
		else
			strcat(dm1,"-");
		sprintf(dm,"%s%d",dm,p);
	}

}
%%

int yywrap()
{
	return 1;
}

int main(int argc,char *argv[])
{
	yyin= fopen(argv[1],"r");
	yyout = fopen("out.txt","w");
    yylex();
    printf("%s \n",vm);
	printf("%s \n",dm);
	printf("%s \n",dm1);
	fclose(yyin);
    fprintf(yyout,"%s",dm1);
    fclose(yyout);
    return 0;

}