/******************************************************
 * Funções para a criação da árvore com base no txt   *
 ******************************************************/


/************************************************* 
 * insereNodo                                    *
 * objetivo: inserir nodo na ARVORE  			 *
 * entrada : ARVORE e cod                        *
 * saída   : ARVORE com mais um registro         *
 *************************************************/ 
 void insereNodo( ARVORE* *p, int codigo, const char texto[]){
 	
 	if(!*p){                                                  // Se raíz estiver vazia
 		ARVORE *no= (ARVORE *) malloc(sizeof(ARVORE));        // Faz alocação de memória com o malloc
 		strcpy(no->info.texto, texto);                        // O strcpy copia o que tem no info.texto e coloca texto
 		no->info.codigo= codigo;                              // No recebe código
 		no->sube= NULL;                                       // sube fica NULL
 		no->subd= NULL;                                       // subd fica NULL
 		*p= no;                                               // P recebe No
	 }
	 
	 else{                                                    // Raíz não está vazia
	 	if(codigo < (*p)->info.codigo)                        // Se o Cod for MENOR que o Cod de p
	 		insereNodo(&(*p)->sube, codigo, texto);			  // vai para esquerda
	 		
	 	else if(codigo > (*p)->info.codigo)                   // Se o Cod for MAIOR que o Cod de p
	 		insereNodo (&(*p)->subd, codigo, texto);		  // vai para direita
	 		
	 }
 }
 

/************************************************* 
 * copiaDados                                    *
 * objetivo: copiar os dados do arquivo txt e 	 *
 * colocar na árvore                             *
 * entrada : dados e Arvore                      *
 * saída   : Arvore completa                     *
 *************************************************/  
void copiaDados( FILE *dados, ARVORE* *r ){
 	char auxTexto[1000];          										
 	int auxCod, i;              										
 	
 	if(dados == NULL){            											// Se não existir um arquivo ou ele estiver vazio
 		printf("Arquivo está vazio ou não foi encontrado \n");
 		getche();                 											// retorna ao Menu 
 		return;
	 } else{
	 	for(i = 0; i < 64; i++) {                                        	// repetir enquanto i for menor de 64 (pois temos 63 NODOS no total)
	 		fscanf(dados, "%d", &auxCod);                               	// Faz a cópia do código do arquivo
	 		insereNodo(&(*r), auxCod, fgets(auxTexto, 200, dados));    		// chama a função de inserir na árvore para inserir o nó
		 }
	 }
}
 
