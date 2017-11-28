
%{
#include "calc.tab.h"

%}

%%
"arriba"	 {return arriba;}
"abajo"		 {return abajo;}
"izquierda"  {return izquierda;}
"derecha"    {return derecha;}
","    {return coma;}
\n     {return EOL;}
[ \t]  {  }
%%

/*


%%
"("    {return OP;}
")"    {return CP;}
"+"    {return ADD;}
"-"    {return SUB;}
"*"    {return MUL;}
"/"    {return DIV;}
[0-9]+ {yylval = atoi(yytext); return NUMBER;}
\n     {return EOL;}
[ \t]  {  }
%%

	En el paso uno el flex reconoce los tokens de la expresion(ademas de asignar una accion)
	y se los pasa al analizador sintactico (o parser) para construir la estructura de datos, 
	por ejemplo un árbol de análisis;
	 
	 2.2.1 Definición de gramaticas
		Una gramática libre de contexto tiene cuatro componentes:
		1. Un conjunto de símbolos terminales, a los que algunas veces se les conoce como “tokens”.
			Los terminales son los símbolos elementales del lenguaje definido por la gramática. 
		2. Un conjunto de no terminales, a las que algunas veces se les conoce como ‘Variables sintácticas”. 
		3. Un conjunto de producciones, en donde cada producción consiste en un no terminal, 
			llamada encabezado o lado izquierdo de la producción, una flecha y una secuencia de
			terminales y no terminales, llamada cuerpo o lado derecho de la producción. 
			La intención intuitiva de una producción es especificar una de las formas escritas de una instrucción; 
			si el no terminal del encabezado representa a una instrucción, 
			entonces el cuerpo representa una forma escrita de la instrucción. 
		4. Una designación de una de los no terminales como el símbolo inicial
	 Ejemplo:
	 Queremos una gramatica que reconozca operaciones del siguiente estilo
	 -3*-4+5
	
	Los tokens serian 	+,-,*,/,NUM
	El conjunto de no terminales serian EXPRESION,TERMINO,DIGITO
	El simbolo inicial
	
	INICIAL -> EXPRESION 
    EXPRESION ->	EXPRESION '+' TERMINO 		
				| EXPRESION '-' TERMINO  			
				| TERMINO
	TERMINO ->	TERMINO '*' DIGITO 
			| TERMINO '/' DIGITO 
			| DIGITO				
	DIGITO -> '(' EXPRESION ')'
			| '-' DIGITO						
			| NUM	

	
										INICIAL
								|				    	|
							EXPRESION			 		|
				|	            |                |             |                                                                                                                                                                
             EXPRESION          |                |             |                                                                                                                                                                 
                |               |                |             |                                                                                                                                                            
              TERMINO           |	             |             |  
          |      |         |         |           |             |                                                                                                                                                           
	   TERMINO   |         |         |           |             |         
	   |	     |         |         |          TERMINO        |       
      |  DIGITO  |         DIGITO    |          DIGITO         |                 
	  |  |       |         |         |           |             |       
	  -  3       *         4         +           5             \n
 -3*4+5	 
	 
	 	Pasos de compilacion 
	1.-	flex calc.l
	2.-  bison -d calc.y
	3.- g++ calc.tab.c lex.yy.c -lfl -o simple2.exe
	*/