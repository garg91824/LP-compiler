%{
#include <stdio.h>
#include <stdlib.h>
int ans;
int power(int ,int);
%}
%union
{
  struct 
   {
	int val;
	int neg;
	int pos;
   }attrs;
   int value;
}
%type <attrs> num,list,sign,bit
%token <int> NUMBER
%start num
%%
num : sign list {
			$2.pos=0;
			if ($1.neg)
				$$.val = -$2.val;
			else
				$$.val = $2.val;
			ans = $2.val;
			printf("value : %d",ans );
		};
sign : '+' {	$$.neg = 0;	}
	| '-' { $$.neg = 1;		};
list : list bit  { $1.pos = $$.pos+1;
		    $2.pos = $$.pos;
		    $$.val = $1.val + $2.val;	
			 }
	| bit {	$$.val=$1.val;
		$1.pos = $$.pos; };
bit : NUMBER {if(NUMBER==0)
		 $$.val = 0 ;
	      if(NUMBER.value==1)
	        $$.val = power(2,$$.pos); };
%%
int power(int i,int j)
{
        int ans1=1,k=0;
        for(k=0;k<j;k++)
                ans = ans * i;
        return ans1;
}

int yyerror(char *msg)
{
	printf("Invalid expression \n");
	exit(0);
}
main()
{
	printf("Enter the expression \n");
	yyparse();
}
