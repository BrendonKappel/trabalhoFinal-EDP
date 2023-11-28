/*****************************************************
 * Trabalho final de PED usando arvores bin�rias 	 *
 * O programa consiste em um modelo de recomenda��es *
 * de bebidas com base nas respostas do usu�rio      *
/*****************************************************/ 

#include <stdio.h>		// fun��es b�sicas do C
#include <locale.h>		// Alfabeto em portugu�s (pt-BR)
#include <string.h>		// Manipula��o de strings 
#include <stdlib.h>		// encerrar o programa
#include <conio.h>      // fun��es que facilitam a intera��o com o console
#include <windows.h>    // fun��es do sistema
#include "MODELO.h"     // biblioteca pr�pria da estrutura do c�digo

 
 /************************************************* 
 * insereNodo                                    *
 * objetivo: rotina para inserir nodo na ARVORE  *
 * entrada : ARVORE e cod                        *
 * sa�da   : ARVORE com mais um registro         *
 *************************************************/ 
 void insereNodo( ARVORE **p, int codigo, const char texto[]){
 	
 	if(!*p){                                                  // Caso a ra�z esteja vazia
 		ARVORE *no= (ARVORE *) malloc(sizeof(ARVORE));        // Aloca espa�o para Registro Auxiliar
 		strcpy(no->info.texto, texto);                        // Copia no->info.texto para colar em texto
 		no->info.codigo= codigo;                              // No recebe c�digo
 		no->sube= NULL;                                       // No esquerdo aponta para NULL
 		no->subd= NULL;                                       // No direito aponta para NULL
 		*p= no;                                               // P recebe No
	 }
	 
	 else{                                                    // Caso a ra�z j� tenha conte�do
	 	if(codigo < (*p)->info.codigo)                        // Se o Cod for menor que o Cod de p, vai para esquerda
	 		insereNodo(&(*p)->sube, codigo, texto);
	 		
	 	else if(codigo > (*p)->info.codigo)                   // Se o Cod for maior que o Cod de p, vai para direita
	 		insereNodo (&(*p)->subd, codigo, texto);
	 		
	 }
 }
 

/************************************************* 
 * copiaDados                                    *
 * objetivo: copiar os dados do arquivo e botar  *
 * na �rvore                                     *
 * entrada : dados e Arvore                      *
 * sa�da   : Arvore com registros                *
 *************************************************/  
 
void copiaDados( FILE *dados, ARVORE **r ){
 	char textoaux[1000];          // auxiliar para textos
 	int codaux, i=0;              // auxiliar para codigos e i
 	
 	if(dados == NULL){            // caso o arquivo n�o seja encontrado
 		printf("Imposs�vel abrir o arquivo.\n");
 		getche();                 // retorna ao Menu Principal
 		return;
	 } else{
	 	while( i < 64 ){                                                // repetir enquanto i for menor de 64 (pois temos 63 NODOS no total)
	 		fscanf(dados, "%d", &codaux);                               // copia o c�digo do arquivo
	 		//const char *textoaux2 = fgets(textoaux, 200, dados);        // copia o texto do arquivo
	 		insereNodo(&(*r), codaux, fgets(textoaux, 200, dados));                       // insere na �rvore
	 		i++;                                                        // i aumenta 1
		 }
	 	
	 }
}
 
 
/************************************************* 
 * recomendacoes                                 *
 * objetivo: Percorrer a base de dados (txt) por 
 * meio das respostas do usu�rio, a fim de indicar 
 * uma bebida para o mesmo
 * entrada : ARVORE                              *
 * sa�da   : bebida indicada ao usu�rio          *
 *************************************************/ 
 
 
 void recomendacoes( ARVORE **p ){
 	int option;
 	
 	if(p == NULL){                                                        // se a ra�z estiver vazia
 		printf("A ra�z est� vazia!\n");
 		printf("\nAperte qualquer tecla para voltar ao menu principal.");
 		return;
    }
	 
	 else{
	 	printf("%s \n", (*p)->info.texto);                                // se n�o, printar um registro
	 	
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
	 		printf("Op��o inv�lida. Tnete novamente\n\n");
	 		recomendacoes( &(*p) );
	 }
	 
 	
 }
 
 
/***********************************************
 * Programa Principal                          *
 ***********************************************/

int main(void){
	setlocale(LC_ALL, "Portuguese");      // Altera o idioma para Portugu�s
	int op, cod;                          // Registra a op��o selecionada no Menu
	FILE *dados= fopen("dados.txt", "r"); // Adiciona o arquivo Dados ao c�digo para ser lido
	ARVORE *r = NULL, *p = NULL;          // Declara��o das �rvores
	copiaDados( dados, &r );              // Copia os dados do arquivo

	
	while( 1 ){
		printf("\n        Kit Maker, Redefinindo a Arte de Brindar.        \n");
		printf("\n       ���������                                           "); 
		printf("\n        �������                                            "); 
		printf("\n        �������                                            "); 
		printf("\n        �������                                            "); 
		printf("\n       ���������                                           "); 
		printf("\n      �����������                                          "); 
		printf("\n     �������������             [1] Recomenda��es de bebida "); 
		printf("\n    ���������������                                        "); 
		printf("\n    ���������������                                        "); 
		printf("\n    �������� �����������                                   "); 
		printf("\n    �������� �����������                                   "); 
		printf("\n    ��������� ���������                                    "); 
		printf("\n    ���������� �������                                     "); 
		printf("\n    ����������� �����          [0] Sair do programa        "); 
		printf("\n    ������������ ���                                       "); 
		printf("\n    ������������ ���                                       "); 
		printf("\n    ������������ ���                                       "); 
		printf("\n    ������������ ���                                       "); 
		printf("\n    ������������ ���                                       "); 
		printf("\n    ����������� �����                                      "); 
		printf("\n    ���������� �������                                   \n");
		printf("\n\n Escolha alguma op��o: ");
		scanf("%d", &op);                    // Tecla de op��o do menu
		fflush(stdin);                       // Limpa o buffer do teclado
		
		switch(op){
			case 1:
				system("cls");                    // Limpa a tela do console
				recomendacoes(&r);             // Chama a Fun��o de perguntas ao usu�rio
				break;
			
			case 0:
				printf("\nENCERRANDO...\n");
				exit(1);                                                        // Fecha o PED
				break;
				
			default:                                                            // Caso o usu�rio n�o digite 1, 2, 3 ou 0
				system("cls");
				printf("\nN�mero inv�lido! Tente novamente\n\n");
		}
	}
	
}




 

