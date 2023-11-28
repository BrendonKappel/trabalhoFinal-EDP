/***********************************************
 * Trabalho PED de �rvore Bin�ria              *
 * Objetivo: Fazer um fluxograma para auxiliar *
 * no aprendizdo de m�sicas na guitarra/baixo  *
 * Programador: Guilherme A. Barbian           *
 * Professora: Daniela Bagatini                *
/***********************************************/ 

#include <stdio.h>		// printf e scanf
#include <locale.h>		// setlocale
#include <string.h>		// strcpy
#include <stdlib.h>		// exit
#include <conio.h>      // getch
#include <windows.h>    // system("cls")


/***********************************************
 * Defini��o dos Registros                     *
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


/***********************************************
 * Defini��o das Fun��es                       *
 ***********************************************/
 
void insereNodo( ARVORE **r , int cod, const char texto[600]);                // Fun��o para inserir Registro na �rvore
void copiaDados( FILE *dados, ARVORE **r);                                    // Fun��o para copiar os dados do arquivo Dados
void perguntasMusicas( ARVORE **p );                                          // Fun��o para rodar o fluxograma
void imprimeMusicas( ARVORE *r );                                             // Fun��o para imprimir todas as m�sicas
void imprimeInformacoes();                                                    // Fun��o para imprimir informa��es sobre os instrumentos dispon�veis

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
		printf("Ol�, seja bem vindo ao STRINGS, aqui vamos te auxiliar no aprendizado de instrumentos musicais!\n");
		printf("\n |---------------------------------------------------|");
		printf("\n |STRINGS                                        Menu|");
		printf("\n |Pressione [1]                Recomenda��o de M�sica|");
		printf("\n |Pressione [2]              Mostrar todas as M�sicas|");
		printf("\n |Pressione [3]        Informa��es Sobre Instrumentos|");
		printf("\n |Pressione [0]                       Sair do STRINGS|");
		printf("\n |---------------------------------------------------|");
		printf("\n\n Op��o: ");
		scanf("%d", &op);                    // Tecla de op��o do menu
		fflush(stdin);                       // Limpa o buffer do teclado
		
		switch(op){
			case 1:
				system("cls");                    // Limpa a tela do console
				perguntasMusicas(&r);             // Chama a Fun��o de perguntas ao usu�rio
				break;
			
			case 2:
				system("cls");                                                   // Limpa a tela do console
				printf("Biblioteca de m�sicas do STRINGS\n");
				imprimeMusicas(r);                                               // Imprime todas as m�sicas presentes na biblioteca
				printf("Aperte qualquer tecla para voltar ao Menu Principal");   
				getche();                                                        // Volta ao menu principal
				system("cls");
				break;
			
			case 3:
				system("cls");                                                   // Limpa a tela do console
				imprimeInformacoes();                                            // Imprime informa��es dos instrumentos
				break;
				
			case 0:
				printf("\n Adeus! At� a pr�xima vez!\n");
				exit(1);                                                        // Fecha o PED
				break;
				
			default:                                                            // Caso o usu�rio n�o digite 1, 2, 3 ou 0
				system("cls");
				printf("\nDigite um n�mero v�lido.\n\n");
		}
	}
	
}



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
 * perguntasMusicas                              *
 * objetivo: Rodar o fluxograma de perguntas ao  *
 * usu�rio para descobrir a m�sica indicada      *
 * entrada : ARVORE                              *
 * sa�da   : M�sica indicada ao usu�rio          *
 *************************************************/ 
 
 
 void perguntasMusicas( ARVORE **p ){
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
	 		perguntasMusicas( &(*p)->sube );
	 		break;
	 	
	 	case 2:                                                          // se a resposta for 2, descer a direita
	 		perguntasMusicas( &(*p)-> subd );
	 		break;
	 		
	 	default:                                                         // se n�o for nenhuma, repetir a pergunta
	 		printf("Digite uma op��o v�lida\n\n");
	 		perguntasMusicas( &(*p) );
	 }
	 
 	
 }
 
 
 /*************************************************
  * imprimiMusicas                                *
  * objetivo: Rodar o fluxograma de perguntas ao  *
  * usu�rio para descobrir a m�sica indicada      *
  * entrada : ARVORE                              *
  * sa�da   : M�sica indicada ao usu�rio          *
  *************************************************/ 
 
 
void imprimeMusicas( ARVORE *p ){

 	if( p != NULL){                              // se a ra�z n�o estiver vazia
 		if(p->subd == NULL && p->sube == NULL){  // imprime nodes folha(m�sicas)
 			printf("\n---------------------------------------------------");
 			printf("\n%s", p->info.texto);       // printa as m�sicas
 			printf("---------------------------------------------------\n");
		 }
		imprimeMusicas(p->subd);                 // procura nodes folha � direita
		imprimeMusicas(p->sube);                 // procura nodes folha � esquerda 
	 }
 }
 
 
 /************************************************* 
 * imprimeInformacoes                            *
 * objetivo: Mostrar informa��es �teis           *
 * entrada : None                                *
 * sa�da   : Informa��es                         *
 *************************************************/ 
 
 void imprimeInformacoes(){
 	int po;
 	
 	system("cls");                               // limpa a tela do console
 	printf("Sobre qual desses instrumentos voc� quer saber sobre?\n[1]Baixo\n[2]Guitarra Base\n\n");
 	printf("Digite sua op��o: ");
	scanf("%d", &po);                            // registra a op��o
	fflush(stdin);                               // limpa o buffer do teclado
	
	switch(po){
		case 1:                                  // se for op��o 1, imprimir informa��es sobre o contrabaixo
			system("cls");
			printf("\n |---------------------------------------------------|");
			printf("\n |                                                   |");
			printf("\n |             Informa��es sobre o Baixo             |");
			printf("\n |                                                   |");
			printf("\n |---------------------------------------------------|");
			printf("\n\nO Baixo El�trico � a vers�o moderna do Contrabaixo, instrumento utilizado para tocar\nas notas mais graves da m�sica, fazendo assim um 'base' para que os instrumentos\nde frequ�ncia m�dia-alta(teclado, guitarra, voz) harmonizem melhor e tenham mais\nliberdade na hora de tocar suas melodias.\nAssim como no passado o Baixo El�trico substituiu o Contrabaixo, hoje em dia �\ncomum vermos o este ser substituido por 808's, especialmente na m�sica POP.\n\nAlguns baixistas que fizeram hist�ria: \n\nNikki Sixx, M�tley Cr�e\nNikki foi um dos principais baixistas e compositores dos anos 80, junto de sua\nbanda, criou um dos g�neros mais populares da �poca, o Glam Metal.\n\nHumberto Gessinger, Engenheiros do Hawaii\nHumberto foi um dos maiores baixistas da hist�ria do Brasil, fundou com amigos a\nEngenheiros do Hawaii, banda que marcou a hist�ria do Rock Nacional, ap�s alguns\nanos, se especializou em sua carreira solo, onde toca guitarra, mas seu legado �\ninquestion�vel.\n\nChampignon, Charlie Brown Jr.\nChampignon foi, talvez, o maior baixista da hist�ria do Brasil, vencedor do pr�mio\nde melhor baixista da Am�rica Latina duas vezes, marcou uma gera��o inteira com suas\nlinhas din�micas, expressivas e mel�dicas. Champignon faleceu em 2013, deixando para tr�s\num legado imensur�vel para a hist�ria da m�sica brasileira.\n\n\nDigite qualquer tecla para voltar ao Menu Principal.");
			getche();                            // limpa a tela e volta ao menu principal
			system("cls");
			return;
			break;
			
		case 2:                                   // se for op��o 2, imprimir informa��es sobre a guitarra  
			system("cls");
			printf("\n |---------------------------------------------------|");
			printf("\n |                                                   |");
			printf("\n |          Informa��es sobre a Guitarra             |");
			printf("\n |                                                   |");
			printf("\n |---------------------------------------------------|");	
			printf("\n\nA Guitarra � um dos instrumentos mais famosos do mundo inteiro, sua hist�ria come�a\ncom o viol�o, instrumento de seis cordas que toca desde fr�nquencias m�dias at� agudas, a populariza��o\ndo instrumento se deu por conta do g�nero precursor da maioria dos g�neros famosos hoje,\no Blues.\nAlguns anos no futuro, foi criada a guitarra el�trica, que dava mais diversidade e\nflexibilidade aos instrumentistas na hora de fazer sons diferentes e n�o convencionais.\nA guitarra encontrou seu brilho m�ximo no Rock n' Roll, onde o seu som tanto agressivo\nquanto angelical poderia ser explorado da maneira mais inventiva poss�vel.\nAlguns guitarristas que fizeram hist�ria:\n\nSlash, Guns n' Roses\nImposs�vel n�o falar de Slash quando falamos sobre guitarristas famosos, a estrela\ndo Guns n' Roses fez alguns dos solos e riffs mais conhecidos da hist�ria do\ninstrumento, Slash comp�s desde m�sicas r�pidas e agressivas como You Could be Mine\nat� baladas lentas e emocionantes como Don't Cry.\n\nJohnny Ramone, Ramones\nUm dos mais influentes guitarristas do Punk Rock, Johnny mostrou que nem s� com\nt�cnincas avan�adas se faz um bom show. O rockeiro popularizou a ideia do DIY\n(Do It Yourself) na m�sica, compondo m�sicas de apenas tr�s power chords e solos\nde literalmente... uma nota... O que importava nas m�sicas dos Ramones eram as suas\nletras cheias de cr�ticas e sua atitude anarquista nos palcos\n\n\nDigite qualquer tecla para voltar ao Menu Principal.");
			getche();                            // limpa a tela e volta ao menu principal
			system("cls");
			return;
			break;
	}
 }
