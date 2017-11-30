

/*IMPORTANTE*/
%define api.pure full
/*IMPORTANTE*/
%lex-param {void * scanner}
/*IMPORTANTE*/
%parse-param {void * scanner}

%{
#include <stdio.h>
/*IMPORTANTE*/
#include <string>
/*IMPORTANTE: SUSTITUIR CALC POR EL NOMBRE DEL ARCHIVO .y*/
#include "calc.tab.h"
/*IMPORTANTE: SUSTITUIR CALC POR EL NOMBRE DEL ARCHIVO .l*/
#include "calc.flex.h"
/*IMPORTANTE*/
#include "FlexBisonUnityDll.h"
/*IMPORTANTE*/
void yyerror(yyscan_t scanner, char const *msg)
{
}
%}
/*IMPORTANTE*/
%code requires
{
	typedef int YYSTYPE;
}

%token NUMBER
%token ADD SUB MUL DIV
%token OP CP
%token EOL
	
%%
calclist: 
| calclist exp EOL {std::string out = std::to_string($2);
BisonOut(out);}
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
/*CODIGO DE EJEMPLO
PARA HACER OTRO HAY QUE UTILIZAR LO QUE SE REFIERA AQUI COMO IMPORTANTE
Y POR UTILIZAR ME REFIERO A COPIAR Y PEGAR DIRECTAMENTE
*/