/***********************************************
 * Funções de entrada de dados do usuário      *
 ***********************************************/
 
 
 /************************************************* 
 * recomendacoes                                  *
 * objetivo: exibir o menu principal e ler a opção*
 * entrada : op                                   *
 * saída   : op                                   *
 *************************************************/ 
 void menu_principal( int *op ) {
 	
 		system("cls");					// Limpa tela
 		
 		printf("\n        Kit Maker, Redefinindo a Arte de Brindar.        \n");
		printf("\n       ¦¦¦¦¦¦¦¦¦                							 "); 
		printf("\n        ¦¦¦¦¦¦¦                 							 "); 
		printf("\n        ¦¦¦¦¦¦¦               [1] Recomendações de bebida  "); 
		printf("\n        ¦¦¦¦¦¦¦                                            "); 
		printf("\n       ¦¦¦¦¦¦¦¦¦                                           "); 
		printf("\n      ¦¦¦¦¦¦¦¦¦¦¦                                          "); 
		printf("\n     ¦¦¦¦¦¦¦¦¦¦¦¦¦             							 "); 
		printf("\n    ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦           [2] Exibir cardápio completo "); 
		printf("\n    ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦                                        "); 
		printf("\n    ¦¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦¦¦¦¦                                   "); 
		printf("\n    ¦¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦¦¦¦¦                                   "); 
		printf("\n    ¦¦¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦¦¦                                    "); 
		printf("\n    ¦¦¦¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦        [3] FUNCAO                   "); 
		printf("\n    ¦¦¦¦¦¦¦¦¦¦¦ ¦¦¦¦¦                  				     "); 
		printf("\n    ¦¦¦¦¦¦¦¦¦¦¦¦ ¦¦¦                                       "); 
		printf("\n    ¦¦¦¦¦¦¦¦¦¦¦¦ ¦¦¦                                       "); 
		printf("\n    ¦¦¦¦¦¦¦¦¦¦¦¦ ¦¦¦                                       "); 
		printf("\n    ¦¦¦¦¦¦¦¦¦¦¦¦ ¦¦¦          [0] Sair do programa         "); 
		printf("\n    ¦¦¦¦¦¦¦¦¦¦¦¦ ¦¦¦                   					 "); 
		printf("\n    ¦¦¦¦¦¦¦¦¦¦¦ ¦¦¦¦¦                                      "); 
		printf("\n    ¦¦¦¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦                                   \n");
		printf("\n\n Escolha alguma opção: ");
		scanf("%d", op);                   // le a opcao que o usuario escolher
		fflush(stdin);                     // Limpa o buffer do teclado
		
		system("cls");					   // Limpa tela
 }
 
 
  /************************************************* 
 * recomendacoes                                  *
 * objetivo: Mostrar todas as bebidas disponíveis *
 * no cardápio  								  *
 * entrada : ARVORE                               *
 * saída   : todas as folhas da arvore            *
 *************************************************/ 
 void imprime_cardapio( ARVORE* r,  int *cont ) { 				// percorre arvore e imprime suas folhas
 	int numBebida, codigoNodo;
 	
 	if( *cont < 32 ) {
 		if( r != NULL ) {
 		imprime_cardapio( r->sube, cont );			   // vai para a direita 
 		
 		if( r->subd == NULL && r->sube == NULL) {    
		    (*cont)++;
 			printf("\n[%i]%s", *cont, r->info.texto); // mostra se for folha								
 			
 		}
		imprime_cardapio( r->subd, cont ); 	         // vai pra esquerda
	}
	} else {
		while( 1 ) {
			printf("\n\n Qual bebida chamou sua atenção? [1 - 32] "); 
			scanf("%i", &numBebida);
			
			if(numBebida > 0 && numBebida < 33) {
				codigoNodo = numBebida + (numBebida - 1);   // n + (n - 1) --> formula que criei p/ achar o nodo
				//procuraNodo( codigo_nodo );					 // Função p/ procurar nodo pelo codigo
				printf("%i", codigoNodo );
				break;
			} else {
				printf("\nNúmero não está na lista! Tente novamente."); 
			}
		}
		
	}
	
 }
