#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "estrutura.h"														//Ficheiro com a estrutura para os contactos e chamadas.
#include "funcAux.c"														//Ficheiro com as funções auxíliares dos para os contactos e chamadas.
#include "menus.c"															//Ficheiro com os menus que aparecem no ecrã do utilizador.
#include "lContactos.c"														//Ficheiro com a parte dos contactos.
#include "lChamadas.c"														//Ficheiro com a parte das chamadas.

/*
**Main
*/

int main() {

	int opcao;																//variável para guardar a opção escolhida do menu.
	AptCont cont;															//Inicialização de um contacto, que vai ser utilizado para as chamadas.
	char resposta, nomeAux[MAXnome];										

	while (opcao != 3) {
		system ("clear"); menu();
		printf("Opção pretendida: "); scanf("%d",&opcao);
		
		switch (opcao) {
			
			//Contactos.
			case 1 : lContactos(); break;
			
			//Chamadas.
			case 2 : printf("É necessario que utilize uma lista de contactos.\n");
					 printf("AVISO: Se a lista não for carregada com sucesso, volte a este Menu e tente de\n       novo...\n");
					 printf("\nPretende carregar a lista de contactos de um ficheiro de nome predefenido ?\n");
		   		     printf("Resposta(S/N):"); scanf(" %c", &resposta); 
		   		     
		   		     if (resposta == 's'|| resposta == 'S') {
		   		     	 strcpy(nomeAux, "listaContactos.txt"); getBarraN; 
					 }
					 else {
						 getBarraN; printf("Indique o nome do ficheiro : ");
						 fgets(nomeAux, MAXnome, stdin); nomeAux[strlen(nomeAux)-1] = '\0';
					 }
					
					 cont = leContactos(nomeAux);
					 printf("\nPrima enter para continuar..."); getBarraN;
					 lChamadas(cont); break;

			//Sair.
			case 3 : system ("clear");
					 printf("\n\nADEUS !!\n\n"); break;
		}
	}
	
	return 1;
}

