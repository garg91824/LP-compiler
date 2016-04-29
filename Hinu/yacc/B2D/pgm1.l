%{
#include <stdlib.h>
#include "y.tab.h"
#include <stdio.h>

%}
%%
[-+] { return *(yytext); }
[0-1] {  yylval.value = atoi(yytext);    
        return NUMBER ; }
%%
