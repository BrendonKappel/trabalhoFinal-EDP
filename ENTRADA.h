/***********************************************
 * Fun��es de entrada de dados do usu�rio      *
 ***********************************************/
 
 
 /************************************************* 
 * recomendacoes                                  *
 * objetivo: exibir o menu principal e ler a op��o*
 * entrada : op                                   *
 * sa�da   : op                                   *
 *************************************************/ 
 void menu_principal( int *op ) {
 		printf("\n        Kit Maker, Redefinindo a Arte de Brindar.        \n");
		printf("\n       ���������                							 "); 
		printf("\n        �������                 							 "); 
		printf("\n        �������               [1] Recomenda��es de bebida  "); 
		printf("\n        �������                                            "); 
		printf("\n       ���������                                           "); 
		printf("\n      �����������                                          "); 
		printf("\n     �������������             							 "); 
		printf("\n    ���������������           [2] Exibir card�pio completo "); 
		printf("\n    ���������������                                        "); 
		printf("\n    �������� �����������                                   "); 
		printf("\n    �������� �����������                                   "); 
		printf("\n    ��������� ���������                                    "); 
		printf("\n    ���������� �������        [3] FUNCAO                   "); 
		printf("\n    ����������� �����                  				     "); 
		printf("\n    ������������ ���                                       "); 
		printf("\n    ������������ ���                                       "); 
		printf("\n    ������������ ���                                       "); 
		printf("\n    ������������ ���          [0] Sair do programa         "); 
		printf("\n    ������������ ���                   					 "); 
		printf("\n    ����������� �����                                      "); 
		printf("\n    ���������� �������                                   \n");
		printf("\n\n Escolha alguma op��o: ");
		scanf("%d", op);                   // le a opcao que o usuario escolher
		fflush(stdin);                       // Limpa o buffer do teclado
 }
