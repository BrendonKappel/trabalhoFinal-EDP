/*- Trabalho PED Recomendação de Drinks com árvores binárias ---*/

/*- Bibliotecas ------------------------------------------------*/
#include <stdio.h>	  // printf e scanf
#include <locale.h>	  // setlocale
#include <string.h>	  // strcpy
#include <stdlib.h>	  // exit
#include <conio.h>    // getch
#include <windows.h>  // system("cls")

/*- Definição Estruturas ---------------------------------------*/
typedef struct {
	int cod;
	char txt[100];    //texto dos nodos
}INFORMACAO;

typedef struct arv{   
	INFORMACAO info;  //dados
	arv sube;         //ponteiro nodo esquerda
	arv subd;         //ponteiro nodo direita
}ARV;

/*- Cabeçalho das Funções --------------------------------------*/

void perguntas (ARV **p);


/*- Função principal -------------------------------------------*/

int main (){
	setlocale(LC_ALL, "Portuguese");      // Altera para português
	//variaveis aq
	int op;
		
	while (1){
		printf("Bem vindo a (nome a definir)! Iremos te auxiliar a encontrar a bebida perfeita.\n");
		printf("\n|--------------------------------|");
		printf("\n|             MENU               |");
		printf("\n|Recomendação de Drink        [1]|"); 
		printf("\n|*Todos os Drinks             [2]|"); //==
		printf("\n|*Receitas                    [3]|"); //* a ver se vai ser implementado
		printf("\n|*Drink Aleatório             [4]|"); //==
		printf("\n|Sair                         [0]|");
		printf("\n|--------------------------------|");
		printf("\n Opção:");
		scanf("%d", op);                  //pega opção selecionada
		fflush(stdin);                    //Limpa Buffer
		
		switch(op){
			case 1:                       //perguntas e recomendação no fim
				system("cls");
				perguntas (&r);
				break;
				
			case 2:                       //imprime o nome de todos os drinks
				
				break;
				
			case 3:                       //imprime a receita de algum drink
				
				break;
				
			case 4:                       //imprime algum drink aleatório
				
			break;
			
			case 0:                       //sair do programa
				("\n Até uma próxima noite de tédio! \n");
				exit(1);
				break;
				
			default: 
				system("cls");            // limpa a tela
				printf("\nDigite uma opção válida!\n\n");
		}
	}
}


/*- Funções -----------------------------------------------------*/

void perguntas (ARV **p){  //esta baseado na suposição de ursarmos um doc externo, tem que mexer.
	int opc;
	
	if (p == NULL){                                  //caso raiz estiver vazia
		printf("\nEsta vazio!");
		printf("\nAperte qualquer tecla para voltar ao menu.");
 		return;
	}
	else {
		printf("%s \n", (*p)->info.texto);           //caso nao, mostra um registro
	}
	
	if((*p)->subd == NULL && (*p)->sube == NULL){    //caso for um registro folha, vulgo drink
		printf("\nAperte qualquer tecla para voltar ao menu.");
		getche();                                    //limpa tela e volta pro menu
		system("cls");
		return;
	}
	
	 fflush(stdin);                                    // limpa o buffer
	 scanf("%d", &opc);                                // registra a opção escolhida
	 system("cls");                                    // limpa a tela

	switch (opc){
		case 1:                                        //resposta 1, desce esquerda
			perguntas ( &(*p)->sube );
			break;

		case 2:                                        //resposta 2, desce direita
			perguntas ( &(*p)->subd );
			break;

		default:                                       // se nem 1 nem 2, repetir a pergunta
	 		printf("\nDigite uma opção válida!\n\n");
	 		perguntasMusicas( &(*p) );
	}
}






