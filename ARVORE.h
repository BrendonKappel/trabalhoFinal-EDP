/******************************************************
 * Funções para a criação da árvore com base no txt   *
 ******************************************************/


/************************************************* 
 * insereNodo                                    *
 * objetivo: rotina para inserir nodo na ARVORE  *
 * entrada : ARVORE e cod                        *
 * saída   : ARVORE com mais um registro         *
 *************************************************/ 
 void insereNodo( ARVORE* *p, int codigo, const char texto[]){
 	
 	if(!*p){                                                  // Caso a raíz esteja vazia
 		ARVORE *no= (ARVORE *) malloc(sizeof(ARVORE));        // Aloca espaço para Registro Auxiliar
 		strcpy(no->info.texto, texto);                        // Copia no->info.texto para colar em texto
 		no->info.codigo= codigo;                              // No recebe código
 		no->sube= NULL;                                       // No esquerdo aponta para NULL
 		no->subd= NULL;                                       // No direito aponta para NULL
 		*p= no;                                               // P recebe No
	 }
	 
	 else{                                                    // Caso a raíz já tenha conteúdo
	 	if(codigo < (*p)->info.codigo)                        // Se o Cod for menor que o Cod de p, vai para esquerda
	 		insereNodo(&(*p)->sube, codigo, texto);
	 		
	 	else if(codigo > (*p)->info.codigo)                   // Se o Cod for maior que o Cod de p, vai para direita
	 		insereNodo (&(*p)->subd, codigo, texto);
	 		
	 }
 }
 

/************************************************* 
 * copiaDados                                    *
 * objetivo: copiar os dados do arquivo e botar  *
 * na árvore                                     *
 * entrada : dados e Arvore                      *
 * saída   : Arvore com registros                *
 *************************************************/  
void copiaDados( FILE *dados, ARVORE* *r ){
 	char textoaux[1000];          // auxiliar para textos
 	int codaux, i;              // auxiliar para codigos e i
 	
 	if(dados == NULL){            // caso o arquivo não seja encontrado
 		printf("Arquivo vazio! \n");
 		getche();                 // retorna ao Menu Principal
 		return;
	 } else{
	 	for(i = 0; i < 64; i++) {                                        // repetir enquanto i for menor de 64 (pois temos 63 NODOS no total)
	 		fscanf(dados, "%d", &codaux);                               // copia o código do arquivo
	 		insereNodo(&(*r), codaux, fgets(textoaux, 200, dados));    // insere na árvore
		 }
	 }
}
 
