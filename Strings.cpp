/*****************************************************
 * Trabalho final de PED usando arvores binárias 	 *
 * O programa consiste em um modelo de recomendações *
 * de bebidas com base nas respostas do usuário      *
/*****************************************************/ 

#include <stdio.h>		// funções básicas do C
#include <locale.h>		// Alfabeto em português (pt-BR)
#include <string.h>		// Manipulação de strings 
#include <stdlib.h>		// encerrar o programa
#include <conio.h>      // funções que facilitam a interação com o console
#include <windows.h>    // funções do sistema
#include "MODELO.h"     // biblioteca própria da estrutura do código

 
 /************************************************* 
 * insereNodo                                    *
 * objetivo: rotina para inserir nodo na ARVORE  *
 * entrada : ARVORE e cod                        *
 * saída   : ARVORE com mais um registro         *
 *************************************************/ 
 void insereNodo( ARVORE **p, int codigo, const char texto[]){
 	
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
 
void copiaDados( FILE *dados, ARVORE **r ){
 	char textoaux[1000];          // auxiliar para textos
 	int codaux, i=0;              // auxiliar para codigos e i
 	
 	if(dados == NULL){            // caso o arquivo não seja encontrado
 		printf("Impossível abrir o arquivo.\n");
 		getche();                 // retorna ao Menu Principal
 		return;
	 } else{
	 	while( i < 64 ){                                                // repetir enquanto i for menor de 64 (pois temos 63 NODOS no total)
	 		fscanf(dados, "%d", &codaux);                               // copia o código do arquivo
	 		//const char *textoaux2 = fgets(textoaux, 200, dados);        // copia o texto do arquivo
	 		insereNodo(&(*r), codaux, fgets(textoaux, 200, dados));                       // insere na árvore
	 		i++;                                                        // i aumenta 1
		 }
	 	
	 }
}
 
 
/************************************************* 
 * recomendacoes                                 *
 * objetivo: Percorrer a base de dados (txt) por 
 * meio das respostas do usuário, a fim de indicar 
 * uma bebida para o mesmo
 * entrada : ARVORE                              *
 * saída   : bebida indicada ao usuário          *
 *************************************************/ 
 
 
 void recomendacoes( ARVORE **p ){
 	int option;
 	
 	if(p == NULL){                                                        // se a raíz estiver vazia
 		printf("A raíz está vazia!\n");
 		printf("\nAperte qualquer tecla para voltar ao menu principal.");
 		return;
    }
	 
	 else{
	 	printf("%s \n", (*p)->info.texto);                                // se não, printar um registro
	 	
	 }
 	
 	if((*p)->subd == NULL && (*p)->sube == NULL){                         // se for um registro folha(uma música)
 		printf("Aperte qualquer tecla para voltar ao menu principal");
 		getche();                                                         // limpa a tela e volta ao registro inicial
 		system("cls");
 		return;
 		
	 }
	 
	 fflush(stdin);                                                      // limpa o buffer do teclado
	 scanf("%d", &option);                                               // registra a opção escolhida
	 system("cls");                                                      // limpa a tela do console
	 
	 switch(option){
	 	
	 	case 1:                                                          // se a resposta for 1, descer a esquerda
	 		recomendacoes( &(*p)->sube );
	 		break;
	 	
	 	case 2:                                                          // se a resposta for 2, descer a direita
	 		recomendacoes( &(*p)-> subd );
	 		break;
	 		
	 	default:                                                         // se não for nenhuma, repetir a pergunta
	 		printf("Opção inválida. Tnete novamente\n\n");
	 		recomendacoes( &(*p) );
	 }
	 
 	
 }
 
 
/***********************************************
 * Programa Principal                          *
 ***********************************************/

int main(void){
	setlocale(LC_ALL, "Portuguese");      // Altera o idioma para Português
	int op, cod;                          // Registra a opção selecionada no Menu
	FILE *dados= fopen("dados.txt", "r"); // Adiciona o arquivo Dados ao código para ser lido
	ARVORE *r = NULL, *p = NULL;          // Declaração das Árvores
	copiaDados( dados, &r );              // Copia os dados do arquivo

	
	while( 1 ){
		printf("\n        Kit Maker, Redefinindo a Arte de Brindar.        \n");
		printf("\n       ¦¦¦¦¦¦¦¦¦                                           "); 
		printf("\n        ¦¦¦¦¦¦¦                                            "); 
		printf("\n        ¦¦¦¦¦¦¦                                            "); 
		printf("\n        ¦¦¦¦¦¦¦                                            "); 
		printf("\n       ¦¦¦¦¦¦¦¦¦                                           "); 
		printf("\n      ¦¦¦¦¦¦¦¦¦¦¦                                          "); 
		printf("\n     ¦¦¦¦¦¦¦¦¦¦¦¦¦             [1] Recomendações de bebida "); 
		printf("\n    ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦                                        "); 
		printf("\n    ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦                                        "); 
		printf("\n    ¦¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦¦¦¦¦                                   "); 
		printf("\n    ¦¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦¦¦¦¦                                   "); 
		printf("\n    ¦¦¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦¦¦                                    "); 
		printf("\n    ¦¦¦¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦                                     "); 
		printf("\n    ¦¦¦¦¦¦¦¦¦¦¦ ¦¦¦¦¦          [0] Sair do programa        "); 
		printf("\n    ¦¦¦¦¦¦¦¦¦¦¦¦ ¦¦¦                                       "); 
		printf("\n    ¦¦¦¦¦¦¦¦¦¦¦¦ ¦¦¦                                       "); 
		printf("\n    ¦¦¦¦¦¦¦¦¦¦¦¦ ¦¦¦                                       "); 
		printf("\n    ¦¦¦¦¦¦¦¦¦¦¦¦ ¦¦¦                                       "); 
		printf("\n    ¦¦¦¦¦¦¦¦¦¦¦¦ ¦¦¦                                       "); 
		printf("\n    ¦¦¦¦¦¦¦¦¦¦¦ ¦¦¦¦¦                                      "); 
		printf("\n    ¦¦¦¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦                                   \n");
		printf("\n\n Escolha alguma opção: ");
		scanf("%d", &op);                    // Tecla de opção do menu
		fflush(stdin);                       // Limpa o buffer do teclado
		
		switch(op){
			case 1:
				system("cls");                    // Limpa a tela do console
				recomendacoes(&r);             // Chama a Função de perguntas ao usuário
				break;
			
			case 0:
				printf("\nENCERRANDO...\n");
				exit(1);                                                        // Fecha o PED
				break;
				
			default:                                                            // Caso o usuário não digite 1, 2, 3 ou 0
				system("cls");
				printf("\nNúmero inválido! Tente novamente\n\n");
		}
	}
	
}




 

