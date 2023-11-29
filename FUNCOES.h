/******************************************************
 * Fun��es principais do sistema                      *
 ******************************************************/
 
 
 /************************************************* 
 * NumeroAleatorio                                *
 * objetivo: gerar n�mero aleat�rio entre 1 e 5   *
 * entrada : nada                                 *
 * sa�da   : 1...6          					  *
 *************************************************/ 
 int numeroAleatorio() {
	srand(time(NULL)); 					// inicializa 
    return (rand() % 6) + 1;  			// Retorna um n�mero aleat�rio entre 1 e 6
}



 /************************************************* 
 * fraseAleatoria                                 *
 * objetivo: Escolher entre 6 diferentes frases   *
 * entrada : numero                               *
 * sa�da   : uma frase aleat�ria          		  *
 *************************************************/ 
char* fraseAleatoria(int numero) {
    static char frase[150]; 
                             
    switch (numero) {			
        case 1:
            strcpy(frase, "�s vezes eu encontro a bebida, �s vezes � a bebida que me encontra. A bebida ideal para voc� �: ");
            break;

        case 2:
            strcpy(frase, "Beba, dance, curta e viva! No outro dia, � s� colocar a culpa na bebida. A bebida que mais combina com voc� �: ");
            break;

        case 3:
            strcpy(frase, "N�o deixe para amanh� o que voc� pode beber hoje. A bebida que mais se alinha ao seu estilo �: ");
            break;

        case 4:
            strcpy(frase, "A vida � muito curta para beber apenas uma ta�a. A bebida que melhor reflete sua ess�ncia �:");
            break;

        case 5:
            strcpy(frase, "Nunca vi boa amizade nascer em leiteria. A bebida que faz par perfeito com voc� �: ");
            break;

        case 6:
            strcpy(frase, "Momentos especiais pedem brindes com as pessoas queridas. A bebida que dan�a em sintonia com sua ess�ncia �: ");
            break;
            
        default:
        	strcpy(frase, "Bebida: ");
        	break;
    }

    return frase;
}
 
 
/************************************************* 
 * recomendacoes                                 *
 * objetivo: Percorrer a base de dados (txt) por 
 * meio das respostas do usu�rio, a fim de indicar 
 * uma bebida para o mesmo
 * entrada : ARVORE                              *
 * sa�da   : bebida indicada ao usu�rio          *
 *************************************************/ 
 void recomendacoes( ARVORE* *p ){
 	int option, numero;
 	
 	
 	if(p == NULL){                                                        		// se a �rvore estiver vazia
 		printf("\nN�o temos bebidas cadastradas no momento.");
 		printf("\nAperte qualquer tecla para voltar ao menu.");
 		return;
    }
	 
	 else{ 														 			// se n�o, mostra o registro 
	 	if( (*p)->subd != NULL && (*p)->sube != NULL ) {         			// se n�o for folha, printa o texto sem complemento
	 		printf("%s \n", (*p)->info.texto);  
		} else { 															// se for folha printa o texto com complemento
						
			numero = numeroAleatorio();										// gera numero aleatorio entre 1 e 5
	 		printf(" %s %s\n", fraseAleatoria(numero), (*p)->info.texto);  // frase aleatoria + nome da bebida
		}	 									 
	 		
	 	
	 }
 	
 	if((*p)->subd == NULL && (*p)->sube == NULL){                         // acaba quando chegar na folha
 		printf("Aperte qualquer tecla para voltar ao menu principal");
 		getche();                                                         // limpa e volta ao menu
 		system("cls");
 		return;
 		
	 }
	 
	 fflush(stdin);                                                      // limpa o buffer do teclado
	 scanf("%d", &option);                                               // l� a op��o do usu�rio
	 system("cls");                                                      // limpa a tela
	 
	 switch(option){
	 	
	 	case 1:                                                          // 1 (menor) vai para a esquerda
	 		recomendacoes( &(*p)->sube );
	 		break;
	 	
	 	case 2:                                                          // 2 (maior) vai para a direita
	 		recomendacoes( &(*p)-> subd );
	 		break;
	 		
	 	default:                                                         // se n�o for 1 ou 2 repete a pergunta
	 		printf("Op��o inv�lida. Tente novamente\n\n");
	 		recomendacoes( &(*p) );
	 }
	 
 	
 }
 
 
 /************************************************* 
 * recomendacoes                                  *
 * objetivo: Mostrar todas as bebidas dispon�veis *
 * no card�pio  								  *
 * entrada : ARVORE                               *
 * sa�da   : todas as folhas da arvore            *
 *************************************************/ 
 void imprime_cardapio( ARVORE* r ) { 				// percorre arvore e imprime suas folhas
 	if( r != NULL ) {
 		imprime_cardapio( r->subd );			   // vai para a direita 
 		
 		if( r->subd == NULL && r->sube == NULL)   // mostra se for folha
 			printf("\n%s", r->info.texto);
 			
		imprime_cardapio( r->sube ); 	         // vai pra esquerda
	 } 
 }
 
 



 
