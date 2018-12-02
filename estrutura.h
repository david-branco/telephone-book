/*
**ESTRUTURA
*/

#define MAXnome 25												
#define MAXnum 15
#define MAXmor 100
#define MAXemail 15
#define MAXdata 10			
#define MAXhora 11			
#define MAXstack 15
#define getBarraN while(getchar() != '\n')

typedef struct sListaContactos  {
	char nome[MAXnome];														//identificação do contacto.
	char num[MAXnum];														//número principal do contacto.
	char num2[MAXnum];														//número secundário do contacto.
	char mor[MAXmor];														//morada do contacto.
	char email[MAXemail];													//email do contacto.	
	struct sListaContactos *seg; 
} Contacto, *AptCont;


typedef struct sChamada  {
	char tipo;															//Tipo da Chamada.
	char ident[MAXnome];												//Indentificação da chamada. 
	char data[MAXdata];													//Data da chamada.							
	char hora[MAXhora];													//Hora da chamada.								 
} Chamada;
