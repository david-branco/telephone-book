/*
**Lista de Chamadas
*/

void lChamadas(AptCont cont) {

	Chamada chamEfe[MAXstack], chamRec[MAXstack], nova;										
	int opcao;																						//Variável para controlo do switch. 
	int iBaseEfe = 0, iTopoEfe = 0,  iBaseRec = 0, iTopoRec = 0;									//Variável para os indices do array.
	char resposta;																					//Variável que vai guardar a resposta.
		
	while (opcao != 7) {
		resposta = 'S';
		system ("clear"); menuChamadas();
		printf("Opção pretendida: "); scanf("%d",&opcao); printf("\n");

		switch (opcao) {
			
			//Para as chamadas efectuadas.
			case 1: system ("clear"); menuChamEfe();
					printf("Opção pretendida: "); scanf("%d",&opcao); printf("\n");

					switch (opcao) {
					
						//Fazer uma chamada para contacto guardado.
						case 1 : printf("\t\t\tLista de Contactos "); imprimeCont(cont); getBarraN;
								 printf("Indique a quem deseja telefonar: ");
								 fgets(nova.ident, MAXnome, stdin); nova.ident[strlen(nova.ident)-1] = '\0';
								 nova.tipo = 'E'; relogio(&nova); calendario(&nova);
												
								 inserirCham(nova, chamEfe, &iBaseEfe, &iTopoEfe); 
								 break;
								 
						//Fazer uma chamada para um número não guardado.		 
					 	case 2 : printf("Indique o numero : "); getBarraN;
								 fgets(nova.ident, MAXnome, stdin); nova.ident[strlen(nova.ident)-1] = '\0';
								 nova.tipo = 'E'; relogio(&nova); calendario(&nova);
													 
								 inserirCham(nova, chamEfe, &iBaseEfe, &iTopoEfe);
								 break;
								 
						//Fazer uma chamada em Anónimo.		 							 
						case 3 : system ("clear"); getBarraN;
								 strcpy(nova.ident, "Anónimo"); nova.tipo = 'E'; relogio(&nova); calendario(&nova);
								 inserirCham(nova, chamEfe, &iBaseEfe, &iTopoEfe); 
								 break;
								 
			 			//Voltar ao Menu Anterior.										 
						case 4 : break;	
					} break;
			
			//Listar no monitor chamadas efectuadas.
			case 2 : system ("clear"); getBarraN;
					 printf("\t\t\tLista de chamadas Efectuadas:\n"); consultarCham (chamEfe, iBaseEfe, iTopoEfe);
					 printf("Prima enter para voltar ao Menu ..."); getBarraN;
					 break;
					 
			//Remove a ultima chamada efectuada.
			case 3 : removerCham (chamEfe, iBaseEfe, &iTopoEfe);  
					 break;		
			
			//Para as chamadas recebidas.	 
			case 4: system ("clear"); menuChamRec();
					printf("Opção pretendida: "); scanf("%d",&opcao); printf("\n");

					switch (opcao) {
					
						//Receber uma chamada de um contacto guardado.
						case 1 : printf("\t\t\tLista de Contactos "); imprimeCont(cont); getBarraN;
								 printf("Indique de quem deseja receber: ");
								 fgets(nova.ident, MAXnome, stdin); nova.ident[strlen(nova.ident)-1] = '\0';
								 nova.tipo = 'R'; relogio(&nova); calendario(&nova);
												
								 inserirCham(nova, chamRec, &iBaseRec, &iTopoRec);
								 break;
								 
						//Receber uma chamada de um número não guardado.		 
						case 2 : printf("Indique o numero : "); getBarraN;
								 fgets(nova.ident, MAXnome, stdin); nova.ident[strlen(nova.ident)-1] = '\0';
								 nova.tipo = 'R'; relogio(&nova); calendario(&nova);
													 
								 inserirCham(nova, chamRec, &iBaseRec, &iTopoRec); 
								 break;

						//Receber uma chamada em Anónimo.			 
						case 3 : system ("clear"); getBarraN;
								 strcpy(nova.ident, "Anónimo"); nova.tipo = 'R'; relogio(&nova); calendario(&nova);
								 inserirCham(nova, chamRec, &iBaseRec, &iTopoRec);
								 break;	
								 
						//Voltar ao Menu Anterior.			 
						case 4 : break;	
					} break; 	
						
						
			//Listar no monitor chamadas recebidas.
			case 5 : system ("clear"); getBarraN;
					 printf("\t\t\tLista de chamadas Recebidas:\n"); consultarCham (chamRec, iBaseRec, iTopoRec);
					 printf("Prima enter para voltar ao Menu ...");getBarraN;
					 break;
			
			//Remove a ultima chamada recebida.			
			case 6 : removerCham (chamRec, iBaseRec, &iTopoRec);
					 break;
					 
			//Voltar ao Menu Anterior.			 
			case 7 : break;
		

		}
	}
}




