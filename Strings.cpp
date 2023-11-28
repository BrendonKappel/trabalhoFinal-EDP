/***********************************************
 * Trabalho PED de Árvore Binária              *
 * Objetivo: Fazer um fluxograma para auxiliar *
 * no aprendizdo de músicas na guitarra/baixo  *
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
 * Definição dos Registros                     *
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
 * Definição das Funções                       *
 ***********************************************/
 
void insereNodo( ARVORE **r , int cod, const char texto[600]);                // Função para inserir Registro na Árvore
void copiaDados( FILE *dados, ARVORE **r);                                    // Função para copiar os dados do arquivo Dados
void perguntasMusicas( ARVORE **p );                                          // Função para rodar o fluxograma
void imprimeMusicas( ARVORE *r );                                             // Função para imprimir todas as músicas
void imprimeInformacoes();                                                    // Função para imprimir informações sobre os instrumentos disponíveis

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
		printf("Olá, seja bem vindo ao STRINGS, aqui vamos te auxiliar no aprendizado de instrumentos musicais!\n");
		printf("\n |---------------------------------------------------|");
		printf("\n |STRINGS                                        Menu|");
		printf("\n |Pressione [1]                Recomendação de Música|");
		printf("\n |Pressione [2]              Mostrar todas as Músicas|");
		printf("\n |Pressione [3]        Informações Sobre Instrumentos|");
		printf("\n |Pressione [0]                       Sair do STRINGS|");
		printf("\n |---------------------------------------------------|");
		printf("\n\n Opção: ");
		scanf("%d", &op);                    // Tecla de opção do menu
		fflush(stdin);                       // Limpa o buffer do teclado
		
		switch(op){
			case 1:
				system("cls");                    // Limpa a tela do console
				perguntasMusicas(&r);             // Chama a Função de perguntas ao usuário
				break;
			
			case 2:
				system("cls");                                                   // Limpa a tela do console
				printf("Biblioteca de músicas do STRINGS\n");
				imprimeMusicas(r);                                               // Imprime todas as músicas presentes na biblioteca
				printf("Aperte qualquer tecla para voltar ao Menu Principal");   
				getche();                                                        // Volta ao menu principal
				system("cls");
				break;
			
			case 3:
				system("cls");                                                   // Limpa a tela do console
				imprimeInformacoes();                                            // Imprime informações dos instrumentos
				break;
				
			case 0:
				printf("\n Adeus! Até a próxima vez!\n");
				exit(1);                                                        // Fecha o PED
				break;
				
			default:                                                            // Caso o usuário não digite 1, 2, 3 ou 0
				system("cls");
				printf("\nDigite um número válido.\n\n");
		}
	}
	
}



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
 * perguntasMusicas                              *
 * objetivo: Rodar o fluxograma de perguntas ao  *
 * usuário para descobrir a música indicada      *
 * entrada : ARVORE                              *
 * saída   : Música indicada ao usuário          *
 *************************************************/ 
 
 
 void perguntasMusicas( ARVORE **p ){
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
	 		perguntasMusicas( &(*p)->sube );
	 		break;
	 	
	 	case 2:                                                          // se a resposta for 2, descer a direita
	 		perguntasMusicas( &(*p)-> subd );
	 		break;
	 		
	 	default:                                                         // se não for nenhuma, repetir a pergunta
	 		printf("Digite uma opção válida\n\n");
	 		perguntasMusicas( &(*p) );
	 }
	 
 	
 }
 
 
 /*************************************************
  * imprimiMusicas                                *
  * objetivo: Rodar o fluxograma de perguntas ao  *
  * usuário para descobrir a música indicada      *
  * entrada : ARVORE                              *
  * saída   : Música indicada ao usuário          *
  *************************************************/ 
 
 
void imprimeMusicas( ARVORE *p ){

 	if( p != NULL){                              // se a raíz não estiver vazia
 		if(p->subd == NULL && p->sube == NULL){  // imprime nodes folha(músicas)
 			printf("\n---------------------------------------------------");
 			printf("\n%s", p->info.texto);       // printa as músicas
 			printf("---------------------------------------------------\n");
		 }
		imprimeMusicas(p->subd);                 // procura nodes folha à direita
		imprimeMusicas(p->sube);                 // procura nodes folha à esquerda 
	 }
 }
 
 
 /************************************************* 
 * imprimeInformacoes                            *
 * objetivo: Mostrar informações úteis           *
 * entrada : None                                *
 * saída   : Informações                         *
 *************************************************/ 
 
 void imprimeInformacoes(){
 	int po;
 	
 	system("cls");                               // limpa a tela do console
 	printf("Sobre qual desses instrumentos você quer saber sobre?\n[1]Baixo\n[2]Guitarra Base\n\n");
 	printf("Digite sua opção: ");
	scanf("%d", &po);                            // registra a opção
	fflush(stdin);                               // limpa o buffer do teclado
	
	switch(po){
		case 1:                                  // se for opção 1, imprimir informações sobre o contrabaixo
			system("cls");
			printf("\n |---------------------------------------------------|");
			printf("\n |                                                   |");
			printf("\n |             Informações sobre o Baixo             |");
			printf("\n |                                                   |");
			printf("\n |---------------------------------------------------|");
			printf("\n\nO Baixo Elétrico é a versão moderna do Contrabaixo, instrumento utilizado para tocar\nas notas mais graves da música, fazendo assim um 'base' para que os instrumentos\nde frequência média-alta(teclado, guitarra, voz) harmonizem melhor e tenham mais\nliberdade na hora de tocar suas melodias.\nAssim como no passado o Baixo Elétrico substituiu o Contrabaixo, hoje em dia é\ncomum vermos o este ser substituido por 808's, especialmente na música POP.\n\nAlguns baixistas que fizeram história: \n\nNikki Sixx, Mötley Crüe\nNikki foi um dos principais baixistas e compositores dos anos 80, junto de sua\nbanda, criou um dos gêneros mais populares da época, o Glam Metal.\n\nHumberto Gessinger, Engenheiros do Hawaii\nHumberto foi um dos maiores baixistas da história do Brasil, fundou com amigos a\nEngenheiros do Hawaii, banda que marcou a história do Rock Nacional, após alguns\nanos, se especializou em sua carreira solo, onde toca guitarra, mas seu legado é\ninquestionável.\n\nChampignon, Charlie Brown Jr.\nChampignon foi, talvez, o maior baixista da história do Brasil, vencedor do prêmio\nde melhor baixista da América Latina duas vezes, marcou uma geração inteira com suas\nlinhas dinâmicas, expressivas e melódicas. Champignon faleceu em 2013, deixando para trás\num legado imensurável para a história da música brasileira.\n\n\nDigite qualquer tecla para voltar ao Menu Principal.");
			getche();                            // limpa a tela e volta ao menu principal
			system("cls");
			return;
			break;
			
		case 2:                                   // se for opção 2, imprimir informações sobre a guitarra  
			system("cls");
			printf("\n |---------------------------------------------------|");
			printf("\n |                                                   |");
			printf("\n |          Informações sobre a Guitarra             |");
			printf("\n |                                                   |");
			printf("\n |---------------------------------------------------|");	
			printf("\n\nA Guitarra é um dos instrumentos mais famosos do mundo inteiro, sua história começa\ncom o violão, instrumento de seis cordas que toca desde frênquencias médias até agudas, a popularização\ndo instrumento se deu por conta do gênero precursor da maioria dos gêneros famosos hoje,\no Blues.\nAlguns anos no futuro, foi criada a guitarra elétrica, que dava mais diversidade e\nflexibilidade aos instrumentistas na hora de fazer sons diferentes e não convencionais.\nA guitarra encontrou seu brilho máximo no Rock n' Roll, onde o seu som tanto agressivo\nquanto angelical poderia ser explorado da maneira mais inventiva possível.\nAlguns guitarristas que fizeram história:\n\nSlash, Guns n' Roses\nImpossível não falar de Slash quando falamos sobre guitarristas famosos, a estrela\ndo Guns n' Roses fez alguns dos solos e riffs mais conhecidos da história do\ninstrumento, Slash compôs desde músicas rápidas e agressivas como You Could be Mine\naté baladas lentas e emocionantes como Don't Cry.\n\nJohnny Ramone, Ramones\nUm dos mais influentes guitarristas do Punk Rock, Johnny mostrou que nem só com\ntécnincas avançadas se faz um bom show. O rockeiro popularizou a ideia do DIY\n(Do It Yourself) na música, compondo músicas de apenas três power chords e solos\nde literalmente... uma nota... O que importava nas músicas dos Ramones eram as suas\nletras cheias de críticas e sua atitude anarquista nos palcos\n\n\nDigite qualquer tecla para voltar ao Menu Principal.");
			getche();                            // limpa a tela e volta ao menu principal
			system("cls");
			return;
			break;
	}
 }
