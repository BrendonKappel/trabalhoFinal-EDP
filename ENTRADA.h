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
		fflush(stdin);                       // Limpa o buffer do teclado
 }
