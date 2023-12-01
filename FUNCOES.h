/******************************************************
 * Fun��es principais do sistema                      *
 ******************************************************/
 
 
 /************************************************* 
 * NumeroAleatorio                                *
 * objetivo: gerar n�mero aleat�rio entre 1 e 5   *
 * entrada : nada                                 *
 * sa�da   : 1...6          					  *
 *************************************************/ 
 void numeroAleatorio( ARVORE* p, int *numero ) {
	srand(time(NULL)); 					// inicializa 
	if(p->info.codigo < 32)				// frases para bebida com �lcool (menor que 32 �  com)   
    	*numero = (rand() % 6) + 1;  	// Retorna um n�mero aleat�rio entre 1 e 6
    if(p->info.codigo > 32)				// frases para bebidas sem �lcool (maior que 32 �  sem)
    	*numero = (rand() % 6) + 7;		// Retorna um n�mero aleat�rio entre 7 e 12
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
    	// Com �lcool
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
        
		// Sem �lcool    
		case 7:
        	strcpy(frase, "Aproveite sua escolha sem �lcool, o sabor est� sempre na divers�o! Sua alma g�mea no universo das bebidas �: ");
        	break;

        case 8:
            strcpy(frase, "Seja a estrela da festa, mesmo sem �lcool. Brindemos � sua decis�o consciente! A bebida que mais combina com sua personalidade �: ");
            break;

        case 9:
            strcpy(frase, "Escolha com sabedoria, beba com alegria. Sua op��o sem �lcool � sempre bem-vinda! A bebida que melhor se adequa ao seu perfil �: ");
            break;

        case 10:
            strcpy(frase, "Sabor sem �lcool, divers�o em dobro. � sua escolha refrescante! A bebida que mais se encaixa com seu estilo �: ");
            break;

        case 11:
            strcpy(frase, "Nada como um drink sem �lcool para celebrar a vida com clareza e leveza. A bebida que faz par perfeito com voc� �: ");
            break;

       	case 12:
            strcpy(frase, "Quem disse que divers�o precisa de �lcool? Seja leve, beba com sabedoria! A bebida que melhor se encaixa na sua vibe �: ");
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
						
			numeroAleatorio( *p, &numero );										// gera numero aleatorio entre 1 e 5
	 		//printf(" %s %s\n", fraseAleatoria(numero), (*p)->info.texto);  // frase aleatoria + nome da bebida
	 		char *token = strtok((*p)->info.texto, "-");
			if (token != NULL) {
				printf("%s\n", token);
			}

			// Extract and print the steps
			while ((token = strtok(NULL, "-")) != NULL) {
			// Trim leading and trailing whitespaces
				while (*token == ' ') {
					token++;
				}
			printf("\t%s\n", token);
			}
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
 
 



 
