/******************************************************
 * Funções principais do sistema                      *
 ******************************************************/
 
 
 /************************************************* 
 * NumeroAleatorio                                *
 * objetivo: gerar número aleatório entre 1 e 5   *
 * entrada : nada                                 *
 * saída   : 1...6          					  *
 *************************************************/ 
 void numeroAleatorio( ARVORE* p, int *numero ) {
	srand(time(NULL)); 					// inicializa 
	if(p->info.codigo < 32)				// frases para bebida com álcool (menor que 32 é  com)   
    	*numero = (rand() % 6) + 1;  	// Retorna um número aleatório entre 1 e 6
    if(p->info.codigo > 32)				// frases para bebidas sem álcool (maior que 32 é  sem)
    	*numero = (rand() % 6) + 7;		// Retorna um número aleatório entre 7 e 12
}



 /************************************************* 
 * fraseAleatoria                                 *
 * objetivo: Escolher entre 6 diferentes frases   *
 * entrada : numero                               *
 * saída   : uma frase aleatória          		  *
 *************************************************/ 
char* fraseAleatoria(int numero) {
    static char frase[150]; 
                            
    switch (numero) {
    	// Com álcool
		case 1:
        strcpy(frase, "Às vezes eu encontro a bebida, às vezes é a bebida que me encontra. A bebida ideal para você é: ");
        break;

        case 2:
            strcpy(frase, "Beba, dance, curta e viva! No outro dia, é só colocar a culpa na bebida. A bebida que mais combina com você é: ");
            break;

        case 3:
            strcpy(frase, "Não deixe para amanhã o que você pode beber hoje. A bebida que mais se alinha ao seu estilo é: ");
            break;

        case 4:
            strcpy(frase, "A vida é muito curta para beber apenas uma taça. A bebida que melhor reflete sua essência é:");
            break;

        case 5:
            strcpy(frase, "Nunca vi boa amizade nascer em leiteria. A bebida que faz par perfeito com você é: ");
            break;

       	case 6:
            strcpy(frase, "Momentos especiais pedem brindes com as pessoas queridas. A bebida que dança em sintonia com sua essência é: ");
            break;
        
		// Sem álcool    
		case 7:
        	strcpy(frase, "Aproveite sua escolha sem álcool, o sabor está sempre na diversão! Sua alma gêmea no universo das bebidas é: ");
        	break;

        case 8:
            strcpy(frase, "Seja a estrela da festa, mesmo sem álcool. Brindemos à sua decisão consciente! A bebida que mais combina com sua personalidade é: ");
            break;

        case 9:
            strcpy(frase, "Escolha com sabedoria, beba com alegria. Sua opção sem álcool é sempre bem-vinda! A bebida que melhor se adequa ao seu perfil é: ");
            break;

        case 10:
            strcpy(frase, "Sabor sem álcool, diversão em dobro. À sua escolha refrescante! A bebida que mais se encaixa com seu estilo é: ");
            break;

        case 11:
            strcpy(frase, "Nada como um drink sem álcool para celebrar a vida com clareza e leveza. A bebida que faz par perfeito com você é: ");
            break;

       	case 12:
            strcpy(frase, "Quem disse que diversão precisa de álcool? Seja leve, beba com sabedoria! A bebida que melhor se encaixa na sua vibe é: ");
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
 * saída   : 1 linha inteira identada               *
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
 * saída   : só o nome da bebida                    *
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
 * objetivo: rotina para buscar registro por código*
 * entrada : ARVORE e cod                          *
 * saída   : ponteiro para o registro              *
 ***************************************************/ 
void busca_recursivo( ARVORE* p, int cod ){
	
	if( p == NULL )
		printf( "\n Registro não encontrado!" );
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
 * meio das respostas do usuário, a fim de indicar 
 * uma bebida para o mesmo
 * entrada : ARVORE                              *
 * saída   : bebida indicada ao usuário          *
 *************************************************/ 
 void recomendacoes( ARVORE* *p ){
 	int option, numero;
	
 	
 	
 	if(p == NULL){                                                        		// se a árvore estiver vazia
 		printf("\nNão temos bebidas cadastradas no momento.");
 		printf("\nAperte qualquer tecla para voltar ao menu.");
 		return;
    }
	 
	 else{ 														 			// se não, mostra o registro 
	 	if( (*p)->subd != NULL && (*p)->sube != NULL ) {         			// se não for folha, printa o texto sem complemento
	 		printf("%s \n", (*p)->info.texto);  
		} else { 															// se for folha printa o texto com complemento
						
			numeroAleatorio( *p, &numero );									// gera numero aleatorio entre 1 e 5
			printf("\n %s ", fraseAleatoria(numero) );						// mostra frase aleatória
			
	 		imprime_complementos( *p );
	}

}
 	
 	if((*p)->subd == NULL && (*p)->sube == NULL){                         // acaba quando chegar na folha
 		getche();                                                         // limpa e volta ao menu
 		system("cls");
 		return;
 		
	 }
	 
	 fflush(stdin);                                                      // limpa o buffer do teclado
	 scanf("%d", &option);                                               // lê a opção do usuário
	 system("cls");                                                      // limpa a tela
	 
	 switch(option){
	 	
	 	case 1:                                                          // 1 (menor) vai para a esquerda
	 		recomendacoes( &(*p)->sube );
	 		break;
	 	
	 	case 2:                                                          // 2 (maior) vai para a direita
	 		recomendacoes( &(*p)-> subd );
	 		break;
	 		
	 	default:                                                         // se não for 1 ou 2 repete a pergunta
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
			printf("\n\n Qual bebida chamou sua atenção? [1 - 32] "); 
			scanf("%i", &numBebida);
			printf("\n");
			
			if(numBebida > 0 && numBebida < 33) {
				r = aux;								// ponteiro auxiliar p/ arvore nao cair na condição de nula
				cod = numBebida + (numBebida - 1);     // n + (n - 1) --> formula que criei p/ achar o nodo
				busca_recursivo( r, cod );			  // Função p/ procurar nodo pelo codigo
				
				break;
			} else {
				printf("\nNúmero não está na lista! Tente novamente."); 
			}
		}
		
	}
	
 }
 
 
 
 

 



 
