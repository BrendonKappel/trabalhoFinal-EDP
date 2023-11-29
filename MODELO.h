/***********************************************
 * Definição da estrutura utilizada            *
 ***********************************************/
 
 
typedef struct{
	int codigo;	          	// Codigo do nodo para balancear a árvore
	char texto[1000];		// Texto do nodo (pode ser tanto a pergunta como a resposta)
}INFORMACAO;

typedef struct arv{
	INFORMACAO info;		// estrutura aninhada (tem o codigo e o texto)
	arv *sube;		        // Ponteiro para o nodo da Esquerda
	arv *subd;		        // Ponteiro para o nodo da Direita
}ARVORE;
