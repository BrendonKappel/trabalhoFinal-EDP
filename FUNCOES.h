/******************************************************
 * Funções principais do sistema                      *
 ******************************************************/
 
 
/************************************************* 
 * recomendacoes                                 *
 * objetivo: Percorrer a base de dados (txt) por 
 * meio das respostas do usuário, a fim de indicar 
 * uma bebida para o mesmo
 * entrada : ARVORE                              *
 * saída   : bebida indicada ao usuário          *
 *************************************************/ 
 void recomendacoes( ARVORE* *p ){
 	int option;
 	
 	if(p == NULL){                                                        // se a raíz estiver vazia
 		printf("\nA árvore não possui elementos");
 		printf("\nAperte qualquer tecla para voltar ao menu principal.");
 		return;
    }
	 
	 else{
	 	printf("%s \n", (*p)->info.texto);                                // se não, printar um registro
	 	
	 }
 	
 	if((*p)->subd == NULL && (*p)->sube == NULL){                         // se for um registro folha(uma música)
 		printf("Aperte qualquer tecla para voltar ao menu principal");
 		getche();                                                         // limpa a tela e volta ao registro inicial
 		system("cls");
 		return;
 		
	 }
	 
	 fflush(stdin);                                                      // limpa o buffer do teclado
	 scanf("%d", &option);                                               // registra a opção escolhida
	 system("cls");                                                      // limpa a tela do console
	 
	 switch(option){
	 	
	 	case 1:                                                          // se a resposta for 1, descer a esquerda
	 		recomendacoes( &(*p)->sube );
	 		break;
	 	
	 	case 2:                                                          // se a resposta for 2, descer a direita
	 		recomendacoes( &(*p)-> subd );
	 		break;
	 		
	 	default:                                                         // se não for nenhuma, repetir a pergunta
	 		printf("Opção inválida. Tente novamente\n\n");
	 		recomendacoes( &(*p) );
	 }
	 
 	
 }
 
 
 /************************************************* 
 * recomendacoes                                  *
 * objetivo: Mostrar todas as bebidas disponíveis *
 * no cardápio  								  *
 * entrada : ARVORE                               *
 * saída   : todas as folhas da arvore            *
 *************************************************/ 
 void imprime_cardapio( ARVORE* r ) { // percorre arvore e imprime suas folhas
 	if( r != NULL ) {
 		imprime_cardapio( r->subd );
 		
 		if( r->subd == NULL && r->sube == NULL) 
 			printf("\n%s", r->info.texto);
 			
		imprime_cardapio( r->sube ); 	
	 } 
 }

 
