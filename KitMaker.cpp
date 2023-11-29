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
	setlocale(LC_ALL, "Portuguese");      // Altera o idioma para Portugu�s
	int op, cod;                          // Registra a op��o selecionada no Menu
	FILE *dados= fopen("dados.txt", "r"); // Adiciona o arquivo Dados ao c�digo para ser lido
	ARVORE *r = NULL, *p = NULL;          // Declara��o das �rvores
	copiaDados( dados, &r );              // Copia os dados do arquivo

	
	while( 1 ){
	
		menu_principal( &op ); // fun��o para exibir o menu principal e ler a op��o
		
		switch(op){
			case 1:
				system("cls");                   // Limpa a tela do console
				recomendacoes(&r);             // Chama a Fun��o de perguntas ao usu�rio
				break;
				
			case 2:
				system("cls");
				imprime_cardapio( r ); // fun�ao para imprimir todas as folhas (op��es de bebida)
				getche();              // congela a tela
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




 

