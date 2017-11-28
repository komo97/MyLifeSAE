%{
#include <stdio.h>
#include "calc.flex.h"

int kodigo=0;

int yywrap(void)
{
return 0;
}
void yyerror(const char *)
{
}
%}
%token arriba izquierda abajo derecha
%token coma
%token EOL
%%
exp: arriba coma arriba coma abajo coma EOL {kodigo=1;}
;
%%









/*
%token NUMBER
%token ADD SUB MUL DIV
%token OP CP
%token EOL

%%
calclist: 
| calclist exp EOL {printf("= %d\n", $2);}
;
exp: factor
| exp ADD factor { $$ = $1 + $3; }
| exp SUB factor { $$ = $1 - $3; }
;
factor: term
| factor MUL term { $$ = $1 * $3; }
| factor DIV term { $$ = $1 / $3; }
;
term: NUMBER
| OP exp CP { $$ = $2; }
;
%%

*/


	/*
	You call the function yyparse to cause parsing to occur. This function reads tokens, executes actions, and ultimately returns when it encounters end-of-input or an unrecoverable syntax error. You can also write an action which directs yyparse to return immediately without reading further.

Function: int yyparse (void)
The value returned by yyparse is 0 if parsing was successful (return is due to end-of-input).

The value is 1 if parsing failed because of invalid input, i.e., input that contains a syntax error or that causes YYABORT to be invoked.

The value is 2 if parsing failed due to memory exhaustion.

In an action, you can cause immediate return from yyparse by using these macros:
*/