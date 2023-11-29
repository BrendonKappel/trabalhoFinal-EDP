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
	srand(time(NULL)); // inicializa 
    return (rand() % 6) + 1;  // Retorna um n�mero aleat�rio entre 1 e 6
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
 	
 	
 	if(p == NULL){                                                        // se a ra�z estiver vazia
 		printf("\nA �rvore n�o possui elementos");
 		printf("\nAperte qualquer tecla para voltar ao menu principal.");
 		return;
    }
	 
	 else{ 														 			// se n�o, printar um registro 
	 	if( (*p)->subd != NULL && (*p)->sube != NULL ) {         			// se n�o for folha, printa o texto sem complemento
	 		printf("%s \n", (*p)->info.texto);  
		} else { 															// se for folha printa o texto com complemento
						
			numero = numeroAleatorio();										// gera numero aleatorio entre 1 e 5
	 		printf(" %s %s\n", fraseAleatoria(numero), (*p)->info.texto);  // frase aleatoria + nome da bebida
		}	 									 
	 		
	 	
	 }
 	
 	if((*p)->subd == NULL && (*p)->sube == NULL){                         // se for um registro folha(uma m�sica)
 		printf("Aperte qualquer tecla para voltar ao menu principal");
 		getche();                                                         // limpa a tela e volta ao registro inicial
 		system("cls");
 		return;
 		
	 }
	 
	 fflush(stdin);                                                      // limpa o buffer do teclado
	 scanf("%d", &option);                                               // registra a op��o escolhida
	 system("cls");                                                      // limpa a tela do console
	 
	 switch(option){
	 	
	 	case 1:                                                          // se a resposta for 1, descer a esquerda
	 		recomendacoes( &(*p)->sube );
	 		break;
	 	
	 	case 2:                                                          // se a resposta for 2, descer a direita
	 		recomendacoes( &(*p)-> subd );
	 		break;
	 		
	 	default:                                                         // se n�o for nenhuma, repetir a pergunta
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
 void imprime_cardapio( ARVORE* r ) { // percorre arvore e imprime suas folhas
 	if( r != NULL ) {
 		imprime_cardapio( r->subd );
 		
 		if( r->subd == NULL && r->sube == NULL) 
 			printf("\n%s", r->info.texto);
 			
		imprime_cardapio( r->sube ); 	
	 } 
 }
 
 



 
