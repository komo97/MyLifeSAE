
%{
/*IMPORTANTE*/
#include "calc.tab.h"
/*IMPORTANTE*/
extern YYSTYPE yylval;
%}
/*IMPORTANTE*/
%option reentrant bison-bridge noyywrap nodefault debug

%%
"("    {return OP;}
")"    {return CP;}
"+"    {return ADD;}
"-"    {return SUB;}
"*"    {return MUL;}
"/"    {return DIV;}
[0-9]+ {*yylval = atoi(yytext); return NUMBER;}
\n     {return EOL;}
[ \t]  {  }
%%
/*CODIGO DE EJEMPLO
PARA HACER OTRO HAY QUE UTILIZAR LO QUE SE REFIERA AQUI COMO IMPORTANTE
Y POR UTILIZAR ME REFIERO A COPIAR Y PEGAR DIRECTAMENTE
IMPORTANTISIMO, AL FINAL DE COMPILAR VA A TIRAR UN ERROR EN EL ARCHIVO
*.flex.h, ES IMPORTANTE DEFINIR HASTA ARRIBA DEL ARCHIVO 
"typedef <el tipo que se desee utilizar> YYSTYPE;"
*/