/***********************************************
 * Definição da estrutura utilizada            *
 ***********************************************/
typedef struct{
	int codigo;	          	// Codigo para balanceamento
	char texto[1000];		// Texto presente no NODO
}INFORMACAO;

typedef struct arv{
	INFORMACAO info;		// Dados do Registro
	arv *sube;		        // Ponteiro para o nodo da Esquerda
	arv *subd;		        // Ponteiro para o nodo da Direita
}ARVORE;
