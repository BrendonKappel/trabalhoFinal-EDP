/*****************************************************
 * Trabalho final de PED usando arvores binárias 	 *
 * O programa consiste em um modelo de recomendações *
 * de bebidas com base nas respostas do usuário      *
/*****************************************************/ 

// BIBLIOTECAS DO SISTEMA
#include <stdio.h>		// funções básicas do C
#include <locale.h>		// Alfabeto em português (pt-BR)
#include <string.h>		// Manipulação de strings 
#include <stdlib.h>		// encerrar o programa
#include <conio.h>      // funções que facilitam a interação com o console
#include <windows.h>    // funções do sistema
#include <time.h>       // biblioteca para gerar numero aleatorio

// BIBLIOTECAS DO PROJETO
#include "MODELO.h"     // biblioteca própria da estrutura do código
#include "ENTRADA.h"    // biblioteca própria para entrada de dados do usuário
#include "ARVORE.h"     // biblioteca própria criação da árvore no sistema
#include "FUNCOES.h"    // biblioteca própria para as funções principais do sistema
 
 
 
/***********************************************
 * Programa Principal                          *
 ***********************************************/
int main(){
	setlocale(LC_ALL, "Portuguese");       // Alfabeto em Português
	int op, cod, cont;                          
	FILE *dados= fopen("dados.txt", "r");  // Adiciona o arquivo Dados ao código para ser lido
	ARVORE *r = NULL, *p = NULL;          
	copiaDados( dados, &r );               // Copia os dados do arquivo

	
	while( 1 ){
		
		menu_principal( &op ); 											// função para exibir o menu principal e ler a opção
		
		switch(op){
			case 1:
				recomendacoes(&r);             							// Chama a Função de perguntas ao usuário
				break;
				
			case 2:
				cont = 0;											// precisa zerar o contador na main pois é funcao recursiva
				printf("\n\t\tCARDÁPIO\n");
				imprime_cardapio( r, &cont ); 						// funçao para imprimir todas as folhas (opções de bebida)
				getche();              								// congela a tela
				break;
				
			case 3:
				break;
			
			case 0:
				printf("\nENCERRANDO...\n");
				exit(1);                                               // Fecha o programa
				break;
				
			default:                                                  // Caso seja digitado um número inválido
				printf("\nNúmero inválido! Tente novamente\n");
				printf("\nAperte qualquer tecla para voltar ao menu.\n");
				getche();  
		} 
	}
	
}




 

