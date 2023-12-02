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
 
 
  /***************************************************
 * busca_recursivo                                 *
 * objetivo: rotina para buscar registro por código*
 * entrada : ARVORE e cod                          *
 * saída   : ponteiro para o registro              *
 ***************************************************/ 
void busca_recursivo( ARVORE* p, int cod ){
	//1. se encontrou cod, informar
	if( p == NULL )
		printf( "\n Registro não encontrado!" );
	else
		//2. percorre para esquerda ou direita 
		if( p->info.codigo > cod )
			busca_recursivo( p->sube, cod );
		else
			if( p->info.codigo < cod )
				busca_recursivo( p->subd, cod );
			else
				if( p->info.codigo == cod )
					printf( "\n Bebida: %s", p->info.texto );
					// imprime_partes( p->info.texto ); // para imprimir receita e modo separadamente
} 

 
  /************************************************* 
 * recomendacoes                                  *
 * objetivo: Mostrar todas as bebidas disponíveis *
 * no cardápio  								  *
 * entrada : ARVORE                               *
 * saída   : todas as folhas da arvore            *
 *************************************************/ 
 void imprime_cardapio( ARVORE* r, ARVORE* aux, int *cont ) { 		// percorre arvore e imprime suas folhas                           				
 	int numBebida, cod;
 	
 	if( *cont < 32 ) {
 		if( r != NULL ) {
 		imprime_cardapio( r->sube, aux, cont );			   // vai para a direita 
 		
 		if( r->subd == NULL && r->sube == NULL) {    
		    (*cont)++;
 			printf("\n[%i]%s", *cont, r->info.texto); // mostra se for folha								
 			
 		}
		imprime_cardapio( r->subd, aux, cont ); 	         // vai pra esquerda
	}
	} else {
		while( 1 ) {
			printf("\n\n Qual bebida chamou sua atenção? [1 - 32] "); 
			scanf("%i", &numBebida);
			
			if(numBebida > 0 && numBebida < 33) {
				r = aux;								// ponteiro auxiliar p/ arvore nao cair na condição de nula
				cod = numBebida + (numBebida - 1);   // n + (n - 1) --> formula que criei p/ achar o nodo
				busca_recursivo( r, cod );					 // Função p/ procurar nodo pelo codigo
				//printf("%i", cod );
				break;
			} else {
				printf("\nNúmero não está na lista! Tente novamente."); 
			}
		}
		
	}
	
 }
 
 

