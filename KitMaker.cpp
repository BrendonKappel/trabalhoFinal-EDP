/*****************************************************
 * Trabalho final de PED usando arvores bin�rias 	 *
 * O programa consiste em um modelo de recomenda��es *
 * de bebidas com base nas respostas do usu�rio      *
/*****************************************************/ 

// BIBLIOTECAS DO SISTEMA
#include <stdio.h>		// fun��es b�sicas do C
#include <locale.h>		// Alfabeto em portugu�s (pt-BR)
#include <string.h>		// Manipula��o de strings 
#include <stdlib.h>		// encerrar o programa
#include <conio.h>      // fun��es que facilitam a intera��o com o console
#include <windows.h>    // fun��es do sistema
#include <time.h>       // biblioteca para gerar numero aleatorio

// BIBLIOTECAS DO PROJETO
#include "MODELO.h"     // biblioteca pr�pria da estrutura do c�digo
#include "ENTRADA.h"    // biblioteca pr�pria para entrada de dados do usu�rio
#include "ARVORE.h"     // biblioteca pr�pria cria��o da �rvore no sistema
#include "FUNCOES.h"    // biblioteca pr�pria para as fun��es principais do sistema
 
 
 
/***********************************************
 * Programa Principal                          *
 ***********************************************/
int main(){
	setlocale(LC_ALL, "Portuguese");       // Alfabeto em Portugu�s
	int op, cod, cont;                          
	FILE *dados= fopen("dados.txt", "r");  // Adiciona o arquivo Dados ao c�digo para ser lido
	ARVORE *r = NULL, *p = NULL;          
	copiaDados( dados, &r );               // Copia os dados do arquivo

	
	while( 1 ){
		
		menu_principal( &op ); 											// fun��o para exibir o menu principal e ler a op��o
		
		switch(op){
			case 1:
				recomendacoes(&r);             							// Chama a Fun��o de perguntas ao usu�rio
				break;
				
			case 2:
				cont = 0;											// precisa zerar o contador na main pois � funcao recursiva
				printf("\n\t\tCARD�PIO\n");
				imprime_cardapio( r, &cont ); 						// fun�ao para imprimir todas as folhas (op��es de bebida)
				getche();              								// congela a tela
				break;
				
			case 3:
				break;
			
			case 0:
				printf("\nENCERRANDO...\n");
				exit(1);                                               // Fecha o programa
				break;
				
			default:                                                  // Caso seja digitado um n�mero inv�lido
				printf("\nN�mero inv�lido! Tente novamente\n");
				printf("\nAperte qualquer tecla para voltar ao menu.\n");
				getche();  
		} 
	}
	
}




 

