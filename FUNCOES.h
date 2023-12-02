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


 /***************************************************
 * imprime_complementos                             *
 * objetivo: printa dados identado                  *
 * entrada : ARVORE                                 *
 * sa�da   : 1 linha inteira identada               *
 ***************************************************/ 
void imprime_complementos(ARVORE* p) {
    if (p != NULL) {
        if (p->info.texto[0] != '\0') {
            for (int i = 0; i < strlen(p->info.texto); i++) { 					 // letra por letra
                if (p->info.texto[i] == '-' && p->info.texto[i + 1] == '-') {    // com 2 "-"
                    printf("\n\n   ");    										 // para titulo 
                    i++; 
                } else if (p->info.texto[i] == '-') {      						 // com 1 "-"
                    printf("\n      ");  				   						 //para texto (ingredientes/passos)
                } else {
                	printf("%c", p->info.texto[i]);
				}
            }
        }

        printf("\n");
    }
    printf("\nAperte qualquer tecla para voltar ao menu.");
}

 /***************************************************
 * imprime_nome_bebida                              *
 * objetivo: imprimir somente o nome da bebida      *
 * entrada : ARVORE                                 *
 * sa�da   : s� o nome da bebida                    *
 ***************************************************/ 
void imprime_nome_bebida(ARVORE* p) {
    if (p != NULL) {
        int i = 0;
        while (p->info.texto[i] != '-' && p->info.texto[i] != '\0') {
            printf("%c", p->info.texto[i]);
            i++;
        }
        printf("\n");
    }
}
 
 
  /***************************************************
 * busca_recursivo                                 *
 * objetivo: rotina para buscar registro por c�digo*
 * entrada : ARVORE e cod                          *
 * sa�da   : ponteiro para o registro              *
 ***************************************************/ 
void busca_recursivo( ARVORE* p, int cod ){
	
	if( p == NULL )
		printf( "\n Registro n�o encontrado!" );
	else
		if( p->info.codigo > cod )
			busca_recursivo( p->sube, cod );
		else
			if( p->info.codigo < cod )
				busca_recursivo( p->subd, cod );
			else
				if( p->info.codigo == cod )		// encontrou o nodo (no caso do txt a linha a ser printada na tela)
					imprime_complementos( p ); // para imprimir receita e modo separadamente
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
						
			numeroAleatorio( *p, &numero );									// gera numero aleatorio entre 1 e 5
			printf("\n %s ", fraseAleatoria(numero) );						// mostra frase aleat�ria
			
	 		imprime_complementos( *p );
	}

}
 	
 	if((*p)->subd == NULL && (*p)->sube == NULL){                         // acaba quando chegar na folha
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
 void imprime_cardapio( ARVORE* r, ARVORE* aux, int *cont ) { 		// percorre arvore e imprime suas folhas                           				
 	int numBebida, cod;
 	
 	if( *cont < 32 ) {
 		if( r != NULL ) {
 		imprime_cardapio( r->sube, aux, cont );			    // vai para a direita 
 		
 		if( r->subd == NULL && r->sube == NULL) {    
		    (*cont)++;
 			printf("\n[%i]", *cont); 			// mostra se for folha	
			imprime_nome_bebida( r );							
 			
 		}
		imprime_cardapio( r->subd, aux, cont ); 	         // vai pra esquerda
	}
	} else {
		while( 1 ) {
			printf("\n\n Qual bebida chamou sua aten��o? [1 - 32] "); 
			scanf("%i", &numBebida);
			printf("\n");
			
			if(numBebida > 0 && numBebida < 33) {
				r = aux;								// ponteiro auxiliar p/ arvore nao cair na condi��o de nula
				cod = numBebida + (numBebida - 1);     // n + (n - 1) --> formula que criei p/ achar o nodo
				busca_recursivo( r, cod );			  // Fun��o p/ procurar nodo pelo codigo
				
				break;
			} else {
				printf("\nN�mero n�o est� na lista! Tente novamente."); 
			}
		}
		
	}
	
 }
 
 
 
 

 



 
