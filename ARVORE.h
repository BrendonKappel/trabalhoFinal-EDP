/******************************************************
 * Fun��es para a cria��o da �rvore com base no txt   *
 ******************************************************/


/************************************************* 
 * insereNodo                                    *
 * objetivo: inserir nodo na ARVORE  			 *
 * entrada : ARVORE e cod                        *
 * sa�da   : ARVORE com mais um registro         *
 *************************************************/ 
 void insereNodo( ARVORE* *p, int codigo, const char texto[]){
 	
 	if(!*p){                                                  // Se ra�z estiver vazia
 		ARVORE *no= (ARVORE *) malloc(sizeof(ARVORE));        // Faz aloca��o de mem�ria com o malloc
 		strcpy(no->info.texto, texto);                        // O strcpy copia o que tem no info.texto e coloca texto
 		no->info.codigo= codigo;                              // No recebe c�digo
 		no->sube= NULL;                                       // sube fica NULL
 		no->subd= NULL;                                       // subd fica NULL
 		*p= no;                                               // P recebe No
	 }
	 
	 else{                                                    // Ra�z n�o est� vazia
	 	if(codigo < (*p)->info.codigo)                        // Se o Cod for MENOR que o Cod de p
	 		insereNodo(&(*p)->sube, codigo, texto);			  // vai para esquerda
	 		
	 	else if(codigo > (*p)->info.codigo)                   // Se o Cod for MAIOR que o Cod de p
	 		insereNodo (&(*p)->subd, codigo, texto);		  // vai para direita
	 		
	 }
 }
 

/************************************************* 
 * copiaDados                                    *
 * objetivo: copiar os dados do arquivo txt e 	 *
 * colocar na �rvore                             *
 * entrada : dados e Arvore                      *
 * sa�da   : Arvore completa                     *
 *************************************************/  
void copiaDados( FILE *dados, ARVORE* *r ){
 	char auxTexto[1000];          										
 	int auxCod, i;              										
 	
 	if(dados == NULL){            											// Se n�o existir um arquivo ou ele estiver vazio
 		printf("Arquivo est� vazio ou n�o foi encontrado \n");
 		getche();                 											// retorna ao Menu 
 		return;
	 } else{
	 	for(i = 0; i < 64; i++) {                                        	// repetir enquanto i for menor de 64 (pois temos 63 NODOS no total)
	 		fscanf(dados, "%d", &auxCod);                               	// Faz a c�pia do c�digo do arquivo
	 		insereNodo(&(*r), auxCod, fgets(auxTexto, 200, dados));    		// chama a fun��o de inserir na �rvore para inserir o n�
		 }
	 }
}
 
