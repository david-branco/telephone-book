/*
**Funções Auxiliares
*/

/*
**Lista de Contactos
*/

//Inserir um contacto numa lista ordenada por identificação.
AptCont inserirCont (AptCont novo, AptCont c) {

	if (c == NULL) {												//Se a lista está vazia, insere logo.
		c = novo;
	}
	
	  else {
	  	if (strcmp(novo->nome , c->nome)< 0) {						//Se o nome do contacto é menor alfabeticamente que o primeiro da lista, insere antes.
	  		novo->seg = c;
	  		c = novo;
	  	}
	  
	    else {c->seg = inserirCont(novo, c->seg);}					//Senão vai procurar no próximo contacto da lista, se é a sua posição de inserção.
	  }
	return c;
}

//Permite consultar a informação de um contacto, através da identificação.
void consultaInfoContNome (char nome[], AptCont c) {						

	if (c == NULL) {printf("\n%s não pertence á lista de contactos!!\n", nome);}		//Se a lista está vazia, o contacto não pertence á lista.	

	else {  	
  		if(strcmp(c->nome, nome) == 0) {												//Se encontrou, imprime no monitor a informação do contacto
  			printf("\nNome: %s\nNumero Principal: %s", c->nome, c->num);
  			printf("\nNumero Secundario: %s\nMorada: %s\nEmail: %s\n", c->num2, c->mor, c->email);
  		}
  		
  		else {
  			if(strcmp(c->nome, nome) < 0) { 									/*Se o nome do contacto que procura for menor alfabeticamente que o  vai*/ 																					/*actual procurar ainda no próximo contacto da lista, se é o que procura.*/
  				consultaInfoContNome(nome, c->seg);
  			}  
  			
  			else { 										 							//Senão encontrar em nenhum caso, não pertence á lista.
  				printf("\n%s não pertence á lista de contactos!!\n", nome);
  			}
  		}
  	}
}

//Permite consultar a informação de um contacto, através dos dois números.
void consultaInfoContNum (char numero[], AptCont c) {

	if (c == NULL) { printf("\n%s não pertence á lista de contactos!!\n", numero);}				//Se a lista está vazia, o contacto não pertence á lista.

	else {  
		if (strcmp(c->num, numero) == 0 || strcmp(c->num2, numero) == 0) {							/*Se o um dos números do contacto for igual ao actual*/
  			printf("\nNome: %s\nNumero Principal: %s", c->nome, c->num);							/*da lista, então imrpime a informação no monitor.*/
  			printf("\nNumero Secundario: %s\nMorada: %s\nEmail: %s\n", c->num2, c->mor, c->email);
  		}		

  		else {
 			consultaInfoContNum(numero, c->seg);										//Senão tenta continua a comparar com o próximo elemento da lista.
	  		if (strcmp(c->num, numero) != 0 || strcmp(c->num2, numero) != 0) {			//Senão encontrar em nenhum caso, o contacto não pertence á lista.
	  			printf("\n%s não pertence á lista de contactos!!\n", numero);
	  		}
  		
  		}
	}
}

	
//Reencaminha para uma função que permite consultar a informação do contacto através da identificação ou de os dois números.
void consultaInfoCont (char info[], AptCont c) {

	if (info[1] > '0' && info[1] < '9') {						/*Se o 2º valor do array for um número (não o primeiro pois, por exemplo, os indicativos*/ 													    			/*internacionais (+351 por exemplo), contêm um '+' na 1ª posição.*/
		consultaInfoContNum (info, c);							//Vai procurar através dos números.
	}
	
	else {consultaInfoContNome (info, c);}						//Vai procurar através da identificação.
	
}
		  	
//Imprime todos os contactos de uma lista.
//Se a lista não for vazia, imprime no monitor a informação do primeiro contacto. A seguir ver para o próximo contacto. Quando acabarem, para.
void imprimeCont (AptCont c)  {

	if (c != NULL) {
		printf("\nNome: %s\nNumero Principal: %s", c->nome, c->num);
		printf("\nNumero Secundario: %s\nMorada: %s\nEmail: %s\n", c->num2, c->mor, c->email);
		imprimeCont(c->seg);
	}
	printf("\n");
}


//Procura um contacto pela identificação, e altera os seus campos.
//Se o utilizador não pretender alterar, basta carregar em enter e mantêm os anteriores.
void alterarCont (char nome[], AptCont c)  {
	char nomeAux[MAXnome], numAux[MAXnum], numAux2[MAXnum], morAux[MAXmor], emailAux[MAXemail];
	
	if (c == NULL) { printf("\n%s não pertence á lista de contactos!!\n",nome);}		//Se a lista está vazia, não ha contactos para serem alterados.

	else {  	
  		if(strcmp(c->nome, nome) == 0) {													//Se encontrou, então recebe a informação e altera o contacto.
  			printf("\nAviso: Prima enter para os campos que não pretende alterar!!\n");
  			printf("Indique o novo nome: ");
			fgets(nomeAux, MAXnome, stdin); nomeAux[strlen(nomeAux)-1] = '\0';
			if (strcmp(nomeAux, "") == 0) {strcpy(nomeAux, c->nome);}
			printf("Indique o novo numero principal: "); 
			fgets(numAux, MAXnum, stdin); numAux[strlen(numAux)-1] = '\0';
			if (strcmp(numAux, "") == 0) {strcpy(numAux, c->num);}
			printf("Indique o novo numero secundário: "); 
			fgets(numAux2, MAXnum, stdin); numAux2[strlen(numAux2)-1] = '\0';
			if (strcmp(numAux2, "") == 0) {strcpy(numAux2, c->num2);}
			printf("Indique a nova morada: "); 
			fgets(morAux, MAXmor, stdin); morAux[strlen(morAux)-1] = '\0';
			if (strcmp(morAux, "") == 0) {strcpy(morAux, c->mor);}
			printf("Indique o novo endereço eletronico: "); 
			fgets(emailAux, MAXemail, stdin); emailAux[strlen(emailAux)-1] = '\0';
			if (strcmp(emailAux, "") == 0) {strcpy(emailAux, c->email);}
			
			strcpy(c->nome, nomeAux);
			strcpy(c->num, numAux);
			strcpy(c->num2, numAux2);
			strcpy(c->mor, morAux);
			strcpy(c->email, emailAux);
			printf("\nNome: %s\nNumero Principal: %s", c->nome, c->num);					//Imprime no ecrã a informação do contacto depois de alterado.
  			printf("\nNumero Secundario: %s\nMorada: %s\nEmail: %s\n", c->num2, c->mor, c->email);
  		}
  		
  		else {
  			if(strcmp(c->nome, nome) < 0) { 							/*Senão encontrou o contacto, mas a  sua identificação for alfabeticamente menor 																			que contacto actual na lista de procura, então vai invocar de novo a função e ser 																			comparado com o próximo contacto da lista.*/
  				alterarCont(nome, c->seg);
  			}  
  			
  			else {
  				printf("\n%s não pertence á lista de contactos!!\n",nome);			//Senão encontrou em nenhum caso, não ha contacto para alterar.
  			}
  		}
  	}
}

//Procura um contacto na lista, por nome, e remove-o.
AptCont removerCont (char nome[], AptCont c, AptCont ant)  {
	AptCont aux = c;															/*Apontador para a estrutura auxíliar, que vai ser usado para ligar os 																					  contactos á volta do removido.*/
		
	if (c == NULL) { printf("\n%s não pertence á lista de contactos!!\n",nome);}		//Se a lista está vazia, não ha contactos para serem removidos.

	else {
	  	if(strcmp(c->nome, nome) < 0) { 								/*Se a identificação do contacto for menor alfabeticamente que a do actual da*/ 			ant = c;													/*lista que se está a comparar, vai se procurar para o próximo, e o contacto*/ 				c = c->seg;													/*anterior fica a ser o actual.*/
	  		removerCont(nome, c, ant);
  		}  	
  		
  		else {															//Se encontrou o contacto:
			if(strcmp(c->nome, nome) == 0) {							
		  		if(ant == NULL) {										//e o anterior ficou a apontar para NULL, então o auxíliar liga-se ao seguitnte.
		  			aux = c->seg;										
		  		}
		  		
		  		else {													/*então o anterior vai estar ligado ao próximo do elemento, é guardada a ligação 																			ao próximo do elemento para ser retornada e o elemento é removido */
		  			ant->seg = aux->seg;
					aux->seg = c->seg;
					free(c);
				}
			}

	  		else {
	  			printf("\n%s não pertence á lista de contactos!!\n",nome);
	  		}
	  	}
  	}
  	return aux;
}


//Contar número de contactos
//Função útil para mais tarde quando se for guardar os contactos num ficheiro externo.
int contaCont (AptCont c)  {
	AptCont aux;
	int j;

	for (aux = c; aux != NULL; aux = aux->seg) {						//Para todos os contactos até ao fim, incrementa a variável j.
		j++;
	}
	
	return j;
}

//Guarda uma lista de contactos num ficheiro, passado o nome por parâmetro	
void guardaContactos (AptCont c, int totalCont, char nome[]) {
	FILE *fLCont;
		
	fLCont = fopen (nome, "w");											//Abre o ficheiro de nome recebido por parâmetro.

	fprintf(fLCont, "%d", totalCont);
	while(c != NULL) {													//Enquanto houver contactos na lista, põe no ficheiro a sua informção. 
		fprintf(fLCont, "%s\n", c->nome);
		fprintf(fLCont, "%s\n", c->num);
		fprintf(fLCont, "%s\n", c->num2);
		fprintf(fLCont, "%s\n", c->mor);
		fprintf(fLCont, "%s\n", c->email);
		c = c->seg;
	}
	
	fclose(fLCont);														//Fecha o ficheiro.
	printf("Lista guardada com sucesso!!\n");
}


//Lê uma lista de contactos a partir de um ficheiro
AptCont leContactos (char nome[]) {
    FILE *fLCont;
    char nomeAux[MAXnome], numAux[MAXnum], numAux2[MAXnum], morAux[MAXmor], emailAux[MAXemail];
    AptCont c = NULL, novo;
    int totalCont; 												//Variável para o inteiro guardado no ficheiro, que indica quantos contactos a lista têm.
    int i = 0;										
   
    fLCont = fopen(nome,"r"); 									//Abre o ficheiro de nome recebido por parâmetro.
    
    if (fLCont != NULL) {
        fscanf(fLCont, "%d", &totalCont);						//Lê o inteiro referido anteriormente.
	
    	while(i< totalCont) {									//Enquanto o número de contactos não for 0, vai lendo e guarda numa célula.
																//A célula vai ser inserida ordenadamente numa lista de contactos.
			fgets(nomeAux, MAXnome, fLCont); nomeAux[strlen(nomeAux)-1] = '\0';
			fgets(numAux, MAXnum, fLCont); numAux[strlen(numAux)-1] = '\0';
			fgets(numAux2, MAXnum, fLCont); numAux2[strlen(numAux2)-1] = '\0';
			fgets(morAux, MAXmor, fLCont); morAux[strlen(morAux)-1] = '\0';
			fgets(emailAux, MAXemail, fLCont); emailAux[strlen(emailAux)-1] = '\0';
		   
			novo = (AptCont) malloc(sizeof(Contacto));
			strcpy(novo->nome, nomeAux);
			strcpy(novo->num, numAux);
			strcpy(novo->num2, numAux2);
			strcpy(novo->mor, morAux);
			strcpy(novo->email, emailAux);
			
			c = inserirCont(novo, c);							/*Apesar de o ficheiro guardar por ordem crescente de nome, ao ler vai acabar por pôr em 																	ordem decrescente, logo é necessário chamar esta função(outra opção seria ler tudo, e no 																	fim inverter).*/			
			i++;
		}
	   
		imprimeCont (c); printf("\n");
    	fclose(fLCont);											//Fecha o ficheiro.
    	printf("Lista carregada com sucesso!!\n");
    }
  
  	else {
  		printf("Não foi possivel carregar a lista!!\n");		//Se o nome do ficheiro  não coicidir com nenhum na directoria, então não é possivel abrir.
  	}
       
    return c;   
}

//Gera página HTML dos contactos
void guardaContactosHTML(AptCont c) {
     FILE *fLCont;
 
     fLCont = fopen ("lContactos.html", "w");
 
     fprintf(fLCont, "<hmtl>");
     fprintf(fLCont, "\t<head>");
     fprintf(fLCont, "\t\t<tittle>Lista de contactos HTML</title>");
     fprintf(fLCont, "\t</head>");
     fprintf(fLCont, "\t<body>");
     fprintf(fLCont, "\t\t<table border=1>");
     while(c != NULL) {
         fprintf(fLCont, "\t\t\t<tr>");
         fprintf(fLCont, "\t\t\t<td>%s\n</td>", c->nome);
         fprintf(fLCont, "\t\t\t<td>%s</td>", c->num);
         fprintf(fLCont, "\t\t\t<td>%s</td>", c->num2);
         fprintf(fLCont, "\t\t\t<td>%s</td>", c->mor);
         fprintf(fLCont, "\t\t\t<td>%s</td>", c->email);
         fprintf(fLCont, "\t\t\t<tr>");
         c = c->seg;
     }
     fprintf(fLCont, "\t\t</table>");
     fprintf(fLCont, "\t</body>");
     fprintf(fLCont, "</html>");
     
     printf("Página gerada !!\n");
 
    fclose(fLCont);                                                     
    //Fecha o ficheiro.
}

/*
**Lista de Chamadas
*/

//Vai buscar a hora do sistema, e preenche no respectivo campo de uma chamada.
void relogio (Chamada *nova) {
	int hor, min, seg;
	char relog[MAXhora];
	struct tm *aux;
	time_t tempo;
	tempo = time(NULL);
	aux = localtime(&tempo);
	
	seg = aux->tm_sec;
	min = aux->tm_min;
	hor = aux->tm_hour;
	
	sprintf(relog,"%dh %dm %ds", hor, min, seg);
	strcpy(nova->hora,relog);
}

//Vai buscar a data do sistema, e preenche no respectivo campo de uma chamada.
void calendario (Chamada *nova) {
	int ano, mes, dia;
	char calend[MAXdata];
	struct tm *aux;
	time_t tempo;
	tempo = time(NULL);
	aux = localtime(&tempo);
	
	ano = aux->tm_year+1900;
	mes = aux->tm_mon+1;
	dia = aux->tm_mday;
	
	sprintf(calend,"%d-%d-%d", ano, mes, dia);
	strcpy(nova->data,calend);
}


//Insere uma chamada á cabeça num array de estruturas circular.
void inserirCham(Chamada nova, Chamada stack[], int *iBase, int *iTopo) {

	stack[*iTopo].tipo = nova.tipo;													//Insere a informação no posição do array iTopo;
	strcpy( stack[*iTopo].ident, nova.ident);
	strcpy( stack[*iTopo].data, nova.data);
	strcpy( stack[*iTopo].hora, nova.hora);
	
	*iTopo = (*iTopo + 1) % MAXstack;												//Altera o iTopo para o valor do resto da divisão com o MAXstack.

	if (*iTopo == *iBase) {														/*Se a posição do iTopo (seguinte) e do iBase for a mesma, então*/ 			*iBase = (*iBase + 1) % MAXstack;										/*altera o valor do iBase no mesmo sistema que a do iTopo anterior,*/
	}																			/*que por outras palavras poderá ser dito como ir incrementando */   																					/*uma posição até á ultima do array, e depois voltar a 0 e seguir o  																					/*mesmo processo.*/
}	


//Mostra no ecrã as chamadas efectuadas ou recebidas que foram feitas.
void consultarCham  (Chamada stack[], int iBase, int iTopo) {
	
	while (iTopo != iBase) {														//Enquanto o iTopo e o iBase forem diferentes, imprime-se informação.
		if (iTopo == 0) {iTopo = MAXstack-1;}										/*Se o iTopo estiver a zero, o próximo será o que estiver na 
																					ultima posição do arrayn (MAXstack-1).*/
		else {iTopo = iTopo -1;}													//Senão esta a zero, então decrementa uma posição iTopo.

		printf("Identificação chamada : %s\n", stack[iTopo].ident);					//Imprime no ecrâ a informação.
		printf("Data : %s\n", stack[iTopo].data);
		printf("Hora : %s\n\n", stack[iTopo].hora);
		}
}

//Remove uma chamada da cabeça de um array de estruturas circular.
void removerCham (Chamada stack[], int iBase, int *iTopo)  {						
	int res = 0;																	//Variável que permite escolher um de entre dois prints.

	 if (*iTopo == iBase) {															//Se iTopo e iBase forem iguais, então a lista está vazia.
        printf("\n\nLista está vazia!!\n\n");
        res = 1;																	//Altera o res, para não ser mostrado outro print.
	}
	
    else {																			//Senão está vazia:
        if (*iTopo == 0) {															//e o iTopo for 0, então o próximo iTopo vai ser o último da stack.
        	*iTopo = MAXstack-1;
        }
        
        else{*iTopo = *iTopo -1;}													//e o iTopo não é zero, então decrementa uma posição ao iTopo.
   }
   
   	if (*iTopo == iBase && res == 0) {												//Se após isto, o iTopo for igual ao iBase, então a lista ficou vazia.
		printf("\n\nLista ficou vazia !!\n\n");										/*A variável res permite que se o primeiro print tiver sido mostrado, 																						este já não é necessário, pois se a stack estava vazia e vai continar 																						a estar.*/
	}

}
	
