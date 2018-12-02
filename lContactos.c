/*
**Lista de Contactos
*/

void lContactos() {

	AptCont cont = NULL, novo, ant = NULL;																
	char resposta, nomeAux[MAXnome], numAux[MAXnum], numAux2[MAXnum], morAux[MAXmor], emailAux[MAXemail];		//Variáveis para guardar informação.
	int opcao;																									//Variável para controlo do switch.
	int totalCont;												//Variável utilizada para contar o numero de contactos, e depois é guardada num ficheiro.

	while (opcao != 9) {
		resposta = 'S';
		system ("clear"); menuContactos();
		printf("Opção pretendida: "); scanf("%d",&opcao); printf("\n");

		switch (opcao) {
		
		//Pede ao utilizador os dados para um novo contacto (os que não quiser preencher, é posto automaticamente Campo Vazio), e insere essa celula numa 			lista ligada.
			case 1 : getBarraN; printf("Aviso: Prima enter para os campos que não pretende preencher!!\n\n");
					 printf("Indique o nome: "); 
				     fgets(nomeAux, MAXnome, stdin); nomeAux[strlen(nomeAux)-1] = '\0';	
				     if (strcmp(nomeAux, "") == 0) {strcpy(nomeAux, "Campo Vazio");}		  
					 printf("Indique o numero principal: "); 
					 fgets(numAux, MAXnum, stdin); numAux[strlen(numAux)-1] = '\0';
					 if (strcmp(numAux, "") == 0) {strcpy(numAux, "Campo Vazio");}	
					 printf("Indique o numero secundário: "); 
					 fgets(numAux2, MAXnum, stdin); numAux2[strlen(numAux2)-1] = '\0';
					 if (strcmp(numAux2, "") == 0) {strcpy(numAux2, "Campo Vazio");}	
					 printf("Indique a morada: "); 
					 fgets(morAux, MAXmor, stdin); morAux[strlen(morAux)-1] = '\0';
					 if (strcmp(morAux, "") == 0) {strcpy(morAux, "Campo Vazio");}	
					 printf("Indique o endereço eletronico: "); 
					 fgets(emailAux, MAXemail, stdin); emailAux[strlen(emailAux)-1] = '\0';
					 if (strcmp(emailAux, "") == 0) {strcpy(emailAux, "Campo Vazio");}	

					 novo = (AptCont) malloc(sizeof(Contacto));
					 strcpy(novo->nome, nomeAux);
					 strcpy(novo->num, numAux);
					 strcpy(novo->num2, numAux2);
					 strcpy(novo->mor, morAux);
					 strcpy(novo->email, emailAux);
					 novo->seg = NULL;

					 cont = inserirCont(novo, cont);
					 printf("\nContacto Inserido !!\n");
					 printf("Prima enter para voltar ao menu anterior ..."); getBarraN;
					 break;				
			
			//Mostra a informação de um contacto, através da identificação dele passada pelo utilizador.				
			case 2 : getBarraN; printf("Indique o nome do contacto que pretende consultar: ");
					 fgets(nomeAux, MAXnome, stdin); nomeAux[strlen(nomeAux)-1] = '\0';
					 
					 consultaInfoCont(nomeAux, cont);
					 printf("Prima enter para voltar ao menu anterior ..."); getBarraN;
					 break;	
					 
			//Permite ao utilizador alterar um contacto, através da identificação dele passada pelo utilizador.  
			case 3 : getBarraN; printf("Indique o nome do contacto : "); 
					 fgets(nomeAux, MAXnome, stdin); nomeAux[strlen(nomeAux)-1] = '\0';	
		
					 alterarCont(nomeAux, cont);
					 printf("\nContacto Alterado !!\n");
					 printf("Prima enter para voltar ao menu anterior ..."); getBarraN;
			 		 break;
						
			//Permite ao utilizador remover um contacto, através da identificação dele passada pelo utilizador.  
			case 4 : getBarraN; printf("Indique o nome do contacto : "); 
					 fgets(nomeAux, MAXnome, stdin); nomeAux[strlen(nomeAux)-1] = '\0';	
		
					 cont = removerCont(nomeAux, cont, ant);
					 printf("\nContacto Removido !!\n");
					 printf("Prima enter para voltar ao menu anterior ..."); getBarraN;
			 		 break;
			 		 
			//Mostra no monitor a lista de Contactos.  		 
		    case 5 : getBarraN; printf("\t\t\tLista de Contactos "); imprimeCont (cont);
					 printf("Prima enter para voltar ao menu anterior ..."); getBarraN;
					 break;
					
			//Permite ao utilizador guarda uma lista de contactos, com nome predefinido ou passado pelo utilizador.  		
		    case 6 : getBarraN; printf("Pretende guardar a lista de contactos num ficheiro de nome predefenido ?\n");
		   		     printf("Resposta(S/N): "); scanf(" %c", &resposta); 
		   		    
		   		     if (resposta == 's'|| resposta == 'S') {
		   		     	 strcpy(nomeAux, "listaContactos.txt"); getBarraN; 
					 }
					 else {
						 getBarraN; printf("Indique o nome do ficheiro : ");
						 fgets(nomeAux, MAXnome, stdin); nomeAux[strlen(nomeAux)-1] = '\0';
					 }
					
					 totalCont = contaCont (cont); guardaContactos(cont, totalCont, nomeAux);
					 printf("Prima enter para voltar ao menu anterior ..."); getBarraN;
					 break;
					 
		    //Permite ao utilizador guarda uma lista de contactos, com nome predefinido ou passado pelo utilizador. 			
		    case 7 : getBarraN;printf("Pretende carregar a lista de contactos de um ficheiro de nome predefenido ?\n");
		   		    printf("Resposta(S/N): "); scanf(" %c", &resposta);
		   		    
		   		    if (resposta == 's'|| resposta == 'S') {
		   		    	strcpy(nomeAux, "listaContactos.txt"); getBarraN;
					}
					else {
						getBarraN; printf("Indique o nome do ficheiro : ");
						fgets(nomeAux, MAXnome, stdin); nomeAux[strlen(nomeAux)-1] = '\0';
					}
					
					cont = leContactos(nomeAux);
					printf("Prima enter para voltar ao menu anterior ..."); getBarraN;
					break;	
						
			//Gerar página html.
		    case 8 : getBarraN; guardaContactosHTML(cont);
		    		 printf("Prima enter para voltar ao menu anterior ..."); getBarraN;
					 break;
					 
		    //Voltar ao Menu Anterior.	
		    case 9 : break;
		}
	}
}
