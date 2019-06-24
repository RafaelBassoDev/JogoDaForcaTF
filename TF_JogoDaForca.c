#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include "conio2.c"

#define CIMA 72
#define BAIXO 80
#define ENTER 13

static int __BACKGROUND = BLACK;
static int __FOREGROUND = LIGHTGRAY;

textcolor2 (int color){
    __FOREGROUND = color;
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
    color + (__BACKGROUND << 4));
    
}

void mgotoxy(int x, int y){
	COORD p={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void drawWalls(){
	int x;
	
	textcolor(LIGHTCYAN);
	
	mgotoxy(0,0);
	printf("%c", 201);
	
	for(x=0; x<30; x++){ // Linha da Esquerda
		if(x!=0){
			mgotoxy(0, x);
			printf("%c", 186);
		}
	}
	
	for(x=1; x<90; x++){ // linha de Cima
		mgotoxy(x, 0);
		printf("%c", 205);
	}
	
	for(x=1; x<30; x++){ // Linha Direita
		if(x==1){
			printf("%c", 187);
		} else {
			mgotoxy(90, x-1);
			printf("%c", 186);
		}
	}
	
	for(x=0; x<91; x++){ // Linha de Baixo
		if(x==0){
			printf("\n%c", 200);
		} else {
			if(x==90){
				printf("%c", 188);
			} else {	
				mgotoxy(x, 29);
				printf("%c", 205);
			}
		}
	}
	
	mgotoxy(2, 28);
	textcolor(WHITE);
	printf("Beta 1.0 (jun-2019)");
}

void drawLogo(int selecaoCor){
	if(selecaoCor = 0){
		textcolor(LIGHTCYAN);
		mgotoxy(24, 2);
		printf("   ___                         _        ");
		mgotoxy(24, 3);
		printf("  |_  |                       | |       ");
		mgotoxy(24, 4);
		printf("    | | ___   __ _  ___     __| | __ _  ");
		mgotoxy(24, 5);
		printf("    | |/ _ \\ / _` |/ _ \\   / _` |/ _` | ");
		mgotoxy(24, 6);
		printf("/\\__/ / (_) | (_| | (_) | | (_| | (_| | ");
		mgotoxy(24, 7);
		printf("\\____/ \\___/ \\__, |\\___/   \\__,_|\\__,_| ");
		mgotoxy(24, 8);
		printf("              __/ |                     ");
		mgotoxy(24, 9);
		printf("             |___/                      ");
		mgotoxy(26, 10);
		printf("       ______                           ");
		mgotoxy(26, 11);
		printf("      |  ___|                           ");
		mgotoxy(26, 12);
		printf("      | |_ ___  _ __ ___ __ _           ");
		mgotoxy(26, 13);
		printf("      |  _/ _ \\| '__/ __/ _` |         ");
		mgotoxy(26, 14);
		printf("      | || (_) | | | (_| (_| |          ");
		mgotoxy(26, 15);
		printf("      \\_| \\___/|_|  \\___\\__,_|      ");
	} else {
		mgotoxy(24, 2);
		printf("   ___                         _        ");
		mgotoxy(24, 3);
		printf("  |_  |                       | |       ");
		mgotoxy(24, 4);
		printf("    | | ___   __ _  ___     __| | __ _  ");
		mgotoxy(24, 5);
		printf("    | |/ _ \\ / _` |/ _ \\   / _` |/ _` | ");
		mgotoxy(24, 6);
		printf("/\\__/ / (_) | (_| | (_) | | (_| | (_| | ");
		mgotoxy(24, 7);
		printf("\\____/ \\___/ \\__, |\\___/   \\__,_|\\__,_| ");
		mgotoxy(24, 8);
		printf("              __/ |                     ");
		mgotoxy(24, 9);
		printf("             |___/                      ");
		mgotoxy(26, 10);
		printf("       ______                           ");
		mgotoxy(26, 11);
		printf("      |  ___|                           ");
		mgotoxy(26, 12);
		printf("      | |_ ___  _ __ ___ __ _           ");
		mgotoxy(26, 13);
		printf("      |  _/ _ \\| '__/ __/ _` |         ");
		mgotoxy(26, 14);
		printf("      | || (_) | | | (_| (_| |          ");
		mgotoxy(26, 15);
		printf("      \\_| \\___/|_|  \\___\\__,_|      ");
	}
}

void drawMenuOptions(){
	textcolor(WHITE);
	mgotoxy(40, 19);
	printf("Iniciar");
	mgotoxy(40, 20);
	printf("Ajuda");
	mgotoxy(40, 21);
	printf("Sobre");
	mgotoxy(40, 22);
	printf("Sair");
}

void drawSobre(){
	system("cls");
	drawWalls(0);
	
	textcolor(LIGHTCYAN);
	mgotoxy(36, 4);
	printf("~ Sobre o criador ~");
	textcolor(WHITE);
	mgotoxy(16, 7);
	printf("Nome: Rafael Coracini Basso");
	mgotoxy(16, 9);
	printf("Idade: 17 Anos");
	
	mgotoxy(36, 14);
	textcolor(LIGHTCYAN);
	printf("~ Sobre o Projeto ~", 135, 198);
	mgotoxy(20, 17);
	textcolor(WHITE);
	printf("Este projeto foi desenvolvido como Trabalho Final(TF), para a");
	mgotoxy(16, 18);
	printf("mat%cria  de \"Algoritimos de Programa%cao\", do curso  de Ci%cncia da", 130, 135, 136);
	mgotoxy(16, 19);
	printf("Computa%cao da Universidade Cat%clica de Bras%clia.", 135, 162, 161);
	
	mgotoxy(26, 23);
	printf("\"Se for para fazer algo, fa%ca bem feito\"", 135);
	
	mgotoxy(74, 25);
	printf("Voltar");
}

void drawAjuda(){
	system("cls");
	drawWalls(0);
	
	textcolor(WHITE);
	mgotoxy(40, 3);
	printf("~ AJUDA ~");
	mgotoxy(5, 6);
	
	textcolor(LIGHTCYAN);
	printf("Defini%cao:", 135);
	textcolor(WHITE);
	mgotoxy(17, 6);
	printf("O jogo da forca %c um jogo em que o jogador tem que acertar qual %c a", 130, 130);
	mgotoxy(5, 7);
	printf("palavra proposta, tendo como dica o n%cmero de letras e o tema ligado %c palavra.", 163, 133);
	mgotoxy(5, 8);
	printf("A cada letra errada, %c desenhada  uma  parte  do  corpo  do  enforcado.  O jogo", 130);
	mgotoxy(5, 9);
	printf("termina ou com o acerto da palavra ou com o t%crmino do preenchimento das partes", 130);
	mgotoxy(5, 10);
	printf("corp%creas do enforcado.", 162);
	
	mgotoxy(5, 12);
	textcolor(LIGHTCYAN);
	printf("Como jogar:");
	mgotoxy(7, 14);
	printf("1%c", 167);
	mgotoxy(7, 17);
	printf("2%c", 167);
	mgotoxy(7, 23);
	printf("3%c", 167);
	textcolor(WHITE);
	mgotoxy(10, 14);
	printf("O jogador pode selecionar um tema e deixar a m%cquina escolher uma palavra,", 160);
	mgotoxy(10, 15);
	printf("ou pode escrever um tema e uma palavra para que outra pessoa tente acertar");
	mgotoxy(10, 17);
	printf("A pessoa que estiver jogando deve inserir uma letra. Caso ela nao  estiver");
	mgotoxy(10, 18);
	printf("contida na palavra,  uma parte do boneco (de um total de 6) ser%c desenhada", 160);
	mgotoxy(10, 19);
	printf("e a letra ficar%c  em evid%cncia. Caso contr%crio,  a letra  aparecer%c  no(s)", 160, 136, 160, 160);
	mgotoxy(10, 20);
	printf("devido(s)  lugar(es)  dentro da palavra  escolhida. A pessoa  tamb%cm  pode", 130);
	mgotoxy(10, 21);
	printf("digitar \"*\" para fazer uma tentativa perigosa e arriscar tudo.");
	mgotoxy(10, 23);
	printf("Perde quem tiver 6 erros e ganha quem acertar todas as letras");
	
	mgotoxy(74, 25);
	printf("Voltar");
}

void drawMainMenu(){
	drawWalls();
	drawLogo(0);
	drawMenuOptions();
}

void drawOpcoesJogo(int tipo){
	
	if(tipo == 0){
		system("cls");
		
		drawWalls();
		
		textcolor(LIGHTCYAN);
		mgotoxy(6, 5);
		printf("ESCOLHA SEU TEMA");
		mgotoxy(6, 20);
		printf("DIGITE SEU TEMA");
		
		textcolor(WHITE);
		mgotoxy(27, 8);
		printf("1 - Objetos");
		mgotoxy(27, 10);
		printf("2 - Alimentos");
		mgotoxy(27, 12);
		printf("3 - Animais");
		mgotoxy(27, 14);
		printf("4 - Pa%cses", 161);
		mgotoxy(27, 16);
		printf("5 - Carros");
		mgotoxy(48, 8);
		printf("6 - Jogos");
		mgotoxy(48, 10);
		printf("7 - Estados");
		mgotoxy(48, 12);
		printf("8 - Cor");
		mgotoxy(48, 14);
		printf("9 - Profissao");
		mgotoxy(48, 16);
		printf("0 - Aleat%crio", 162);
		
		mgotoxy(13, 22);
		printf("Tema          :");
		mgotoxy(13, 24);
		printf("Palavra-chave :");
	} else if(tipo == 1){
		
		textcolor(GREEN);
		mgotoxy(6, 5);
		printf("ESCOLHA SEU TEMA");
		textcolor(LIGHTCYAN);
		mgotoxy(6, 20);
		printf("DIGITE SEU TEMA");
		
		textcolor(WHITE);
		mgotoxy(27, 8);
		printf("1 - Objetos");
		mgotoxy(27, 10);
		printf("2 - Alimentos");
		mgotoxy(27, 12);
		printf("3 - Animais");
		mgotoxy(27, 14);
		printf("4 - Pa%cses", 161);
		mgotoxy(27, 16);
		printf("5 - Carros");
		mgotoxy(48, 8);
		printf("6 - Jogos");
		mgotoxy(48, 10);
		printf("7 - Estados");
		mgotoxy(48, 12);
		printf("8 - Cor");
		mgotoxy(48, 14);
		printf("9 - Profissao");
		mgotoxy(48, 16);
		printf("0 - Aleat%crio", 162);
		
		mgotoxy(13, 22);
		printf("Tema          :");
		mgotoxy(13, 24);
		printf("Palavra-chave :");
	} else if(tipo == 2){
		
		textcolor(LIGHTCYAN);
		mgotoxy(6, 5);
		printf("ESCOLHA SEU TEMA");
		textcolor(GREEN);
		mgotoxy(6, 20);
		printf("DIGITE SEU TEMA");
		
		textcolor(WHITE);
		mgotoxy(27, 8);
		printf("1 - Objetos");
		mgotoxy(27, 10);
		printf("2 - Alimentos");
		mgotoxy(27, 12);
		printf("3 - Animais");
		mgotoxy(27, 14);
		printf("4 - Pa%cses", 161);
		mgotoxy(27, 16);
		printf("5 - Carros");
		mgotoxy(48, 8);
		printf("6 - Jogos");
		mgotoxy(48, 10);
		printf("7 - Estados");
		mgotoxy(48, 12);
		printf("8 - Cor");
		mgotoxy(48, 14);
		printf("9 - Profissao");
		mgotoxy(48, 16);
		printf("0 - Aleat%crio", 162);
		
		mgotoxy(13, 22);
		printf("Tema          :");
		mgotoxy(13, 24);
		printf("Palavra-chave :");
	}
}

void drawVidas(int quantidadeVidas){
	int i, x = 10;
	
	//  VIDAS: <3 <3 <3 <3 <3 <3
	
	mgotoxy(3, 2);
	textcolor(WHITE);
	printf("VIDAS:");
	
	mgotoxy(10, 2);
	printf("                  ");
	
	for(i=0; i<quantidadeVidas; i++){
		textcolor(LIGHTRED);
		if(i==0){
			mgotoxy(x, 2);
			printf("%c3", 60);
			x += 3;
		} else {
			mgotoxy(x, 2);
			printf("%c3", 60);
			x += 3;
		}
	}
}

void drawPersonagem(int qntErros){
	
	textcolor(WHITE);
	
	switch(qntErros){
		case 0:
			mgotoxy(14, 8);
			printf("%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
			mgotoxy(14, 9);
			printf("%c         %c", 179, 179);
			mgotoxy(14, 10);
			printf("%c", 179);
			mgotoxy(14, 11);
			printf("%c", 179);
			mgotoxy(14, 12);
			printf("%c", 179);
			mgotoxy(14, 13);
			printf("%c", 179);
			mgotoxy(14, 14);
			printf("%c", 179);
			mgotoxy(14, 15);
			printf("%c", 179);
			mgotoxy(11, 16);
			printf("%c%c%c%c%c%c%c", 196, 196, 196, 193, 196, 196, 196);
			break;
		case 1:
			mgotoxy(24, 10);
			printf("O");
			break;
		case 2:
			mgotoxy(24, 11);
			printf("|");
			break;
		case 3:
			mgotoxy(23, 11);
			printf("/");
			break;
		case 4:
			mgotoxy(25, 11);
			printf("\\");
			break;
		case 5:
			mgotoxy(23, 12);
			printf("/");
			break;
		case 6:
			textcolor(RED);
			mgotoxy(24, 10);
			printf("O");
			mgotoxy(24, 11);
			printf("|");
			mgotoxy(23, 11);
			printf("/");
			mgotoxy(25, 11);
			printf("\\");
			mgotoxy(23, 12);
			printf("/");
			mgotoxy(25, 12);
			printf("\\");
			mgotoxy(91, 29);
			break;
	}
	textcolor(WHITE);
}

void drawTema(char tema[][26]){
	
	mgotoxy(68, 2);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
	mgotoxy(68, 3);
	printf("%c      TEMA       %c", 179, 179);
	mgotoxy(68, 4);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 195, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 180);
	mgotoxy(68, 5);
	printf("%c %s", 179, tema[0]);
	mgotoxy(86, 5);
	printf("%c", 179);
	mgotoxy(68, 6);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
}

void drawLetrasUsadas(char letra, int quantidadeErros){
	int i;

	mgotoxy(68, 7);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
	mgotoxy(68, 8);
	printf("%c  LETRAS USADAS  %c", 179, 179);
	mgotoxy(68, 9);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 195, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 180);
	for(i=9; i<=18; i++){
		mgotoxy(68, i);
		printf("%c", 179);
		mgotoxy(86, i);
		printf("%c", 179);
	}
	mgotoxy(68, 19);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
			
	switch(quantidadeErros){
		case 0:
			mgotoxy(72, 10);
			printf("%c", letra);
			break;
		case 1:
			mgotoxy(77, 10);
			printf("%c", letra);
			break;
		case 2:
			mgotoxy(82, 10);
			printf("%c", letra);
			break;
		case 3:
			mgotoxy(72, 11);
			printf("%c", letra);
			break;
		case 4:
			mgotoxy(77, 11);
			printf("%c", letra);
			break;	
		case 5:
			mgotoxy(82, 11);
			printf("%c", letra);
			break;
		case 6:
			mgotoxy(72, 12);
			printf("%c", letra);
			break;
		case 7:
			mgotoxy(77, 12);
			printf("%c", letra);
			break;	
		case 8:
			mgotoxy(82, 12);
			printf("%c", letra);
			break;
		case 9:
			mgotoxy(72, 13);
			printf("%c", letra);
			break;
		case 10:
			mgotoxy(77, 13);
			printf("%c", letra);
			break;	
		case 11:
			mgotoxy(82, 13);
			printf("%c", letra);
			break;
		case 12:
			mgotoxy(72, 14);
			printf("%c", letra);
			break;
		case 13:
			mgotoxy(77, 14);
			printf("%c", letra);
			break;	
		case 14:
			mgotoxy(82, 14);
			printf("%c", letra);
			break;
		case 15:
			mgotoxy(72, 15);
			printf("%c", letra);
			break;
		case 16:
			mgotoxy(77, 15);
			printf("%c", letra);
			break;	
		case 17:
			mgotoxy(82, 15);
			printf("%c", letra);
			break;
		case 18:
			mgotoxy(72, 16);
			printf("%c", letra);
			break;
		case 19:
			mgotoxy(77, 16);
			printf("%c", letra);
			break;	
		case 20:
			mgotoxy(82, 16);
			printf("%c", letra);
			break;
		case 21:
			mgotoxy(72, 17);
			printf("%c", letra);
			break;
		case 22:
			mgotoxy(77, 17);
			printf("%c", letra);
			break;	
		case 23:
			mgotoxy(82, 17);
			printf("%c", letra);
			break;
		case 24:
			mgotoxy(72, 18);
			printf("%c", letra);
			break;
		case 25:
			mgotoxy(77, 18);
			printf("%c", letra);
			break;
	}
}

int getTeclaMenuPrincipal(){
	short cima, baixo, enter;
	
	do{
		textcolor(rand() % 15);
		Sleep(150);
		drawLogo(1);
		
		mgotoxy(91, 29);
		
		fflush(stdin);
		
		cima = GetAsyncKeyState(VK_UP);
		baixo = GetAsyncKeyState(VK_DOWN);
		enter = GetAsyncKeyState(VK_RETURN);
	
		if(cima){
			return CIMA;
		} else if(baixo) {
			return BAIXO;
		} else if(enter) {
			return ENTER;
		}
	}while(!enter); // enter == 0
}

int getTeclaSobreAjuda(){
	int tecla=0, pisca=0;
	short enter;
	
	do{	
		mgotoxy(72, 25);
		Sleep(400);
		if(pisca == 0){
			textcolor(WHITE);
			printf("%c", 175);
			pisca++;
		} else {
			textcolor(BLACK);
			printf("%c", 175);
			pisca--;
		}
		mgotoxy(91, 29);
		
		enter = GetAsyncKeyState(VK_RETURN);
	
		if(enter) {
			tecla = ENTER;
		}
	}while(!enter); // enter == 0
	
	return tecla;
}

void clearLine(int inicio, int fim){
	int i;
	
	for(i=inicio; i<=fim; i++){
		mgotoxy(38, i);
		printf(" ");
	}
}

int loadingScreen(){
	int x, i;
	float c;
	char loading[30], a=176, b=219; // "a" e "b" são caracteres da animação de loading.
	
	for(x=0; x<30; x++){
		loading[x] = a;
		mgotoxy(30+x, 14);
		printf("%c", loading[x]);
	}
	
	for(x=0; x<30; x++){
		
		c = x;
		
		Sleep(45);
		mgotoxy(37, 13);
		printf("Carregando %.1f%c \n", c*3.448, 37);
		loading[x]= b;
		for(i=0; i<30; i++){
			if(loading[i] == b){
				mgotoxy(30+i, 14);
				textcolor(LIGHTCYAN);
			} else {
				textcolor(WHITE);
			}
			printf("%c", loading[i]);
		}
	}
	
	Sleep(250);
	system("cls");
	return 1;
}

int selecaoMenu(int posicao, int tecla, int contador){
	int posicaoFinal;
	
	textcolor(WHITE);
	
	if(contador == 0){
		mgotoxy(38, 19);
		printf("%c", 175);
		posicaoFinal = 19;
		mgotoxy(91, 29);
		return posicaoFinal;
	} else {
		clearLine(19, 22);
	}
	
	switch(posicao){
		case 19:
			clearLine(19, 22);
			if(tecla == CIMA){
				mgotoxy(38, 22);
				printf("%c", 175);
				posicaoFinal = 22;
			} else if(tecla == BAIXO){
				mgotoxy(38, 20);
				printf("%c", 175);
				posicaoFinal = 20;
			}
			break;
		case 20:
			if(tecla == CIMA){
				mgotoxy(38, 19);
				printf("%c", 175);
				posicaoFinal = 19;
			} else if(tecla == BAIXO){
				mgotoxy(38, 21);
				printf("%c", 175);
				posicaoFinal = 21;
			}
			break;
		case 21:
			if(tecla == CIMA){
				mgotoxy(38, 20);
				printf("%c", 175);
				posicaoFinal = 20;
			} else if(tecla == BAIXO){
				mgotoxy(38, 22);
				printf("%c", 175);
				posicaoFinal = 22;
			}
			break;
		case 22:
			if(tecla == CIMA){
				mgotoxy(38, 21);
				printf("%c", 175);
				posicaoFinal = 21;
			} else if(tecla == BAIXO){
				mgotoxy(38, 19);
				printf("%c", 175);
				posicaoFinal = 19;
			}
			break;
	}
	
	mgotoxy(91, 29);
	return posicaoFinal;
}

void opcoesJogo(char temaPalavra[][26]){
	char objetos[5][15] = {"ABAJUR", "BONECA", "GAITA", "FACA", "MARTELO"};
	char alimentos[5][15] = {"ARROZ", "BATATA", "PUDIM", "LASANHA", "CHOCOLATE"};
	char animais[5][15] = {"CAVALO", "RINOCERONTE", "PATO", "MORCEGO", "COBRA"};
	char paises[5][15] = {"BRASIL", "ARGENTINA", "ALEMANHA", "AFRICA DO SUL", "ESPANHA"};
	char carros[5][15] = {"MUSTANG", "FUSCA", "COROLLA", "UNO", "DUSTER"};
	char jogos[5][20] = {"LEAGUE OF LEGENDS", "COUNTER STRIKE", "TIBIA", "RUNESCAPE", "THE WITCHER"};
	char estados[5][15] = {"BAHIA", "SANTA CATARINA", "PARANA", "MATO GROSSO", "PERNAMBUCO"};
	char cor[5][15] = {"VERMELHO", "AZUL", "VERDE", "BRANCO", "ROXO"};
	char profissao[5][15] = {"MEDICO", "ENGENHEIRO", "ADVOGADO", "POLICIAL", "DENTISTA"};
	int escolheu, selecaoTema, i=0, posicao=0;
	
	escolheu = 0;
	
	getche(); 
	
	escolheu = escolhaOpcoesJogo(&posicao);
	
	if(escolheu == 0){
		drawOpcoesJogo(1);
		selecaoTema = getEscolhaTema();
		
		if(selecaoTema == 9){
			do{
				selecaoTema = rand()%9;
			} while(selecaoTema == 0);
		}
		
		switch(selecaoTema){
			case 0:
				strcpy(temaPalavra[0], "    Objetos");
				i = rand()%5;
				strcpy(temaPalavra[1], objetos[i]);
				break;
				
			case 1:
				strcpy(temaPalavra[0], "   Alimentos");
				i = rand()%5;
				strcpy(temaPalavra[1], alimentos[i]);
				break;
				
			case 2:
				strcpy(temaPalavra[0], "    Animais");
				i = rand()%5;
				strcpy(temaPalavra[1], animais[i]);
				break;
				
			case 3:
				strcpy(temaPalavra[0], "    Paises");
				i = rand()%5;
				strcpy(temaPalavra[1], paises[i]);
				break;
				
			case 4:
				strcpy(temaPalavra[0], "    Carros");
				i = rand()%5;
				strcpy(temaPalavra[1], carros[i]);
				break;
				
			case 5:
				strcpy(temaPalavra[0], "    Jogos");
				i = rand()%5;
				strcpy(temaPalavra[1], jogos[i]);
				break;
				
			case 6:
				strcpy(temaPalavra[0], "    Estados");
				i = rand()%5;
				strcpy(temaPalavra[1], estados[i]);
				break;
				
			case 7:
				strcpy(temaPalavra[0], "      Cor");
				i = rand()%5;
				strcpy(temaPalavra[1], cor[i]);
				break;
				
			case 8:
				strcpy(temaPalavra[0], "   Profissao");
				i = rand()%5;
				strcpy(temaPalavra[1], profissao[i]);
				break;
		}
	} else if(escolheu == 1){
		drawOpcoesJogo(2);
		
		fflush(stdin);
		fflush(stdout);
		
		mgotoxy(29, 22);
		scanf("%[^\n]", temaPalavra[0]); // Pega o TEMA
		
		do{
			fflush(stdin);
			fflush(stdout);
			
			mgotoxy(29, 24);
			scanf("%[^\n]",  temaPalavra[1]);// Pega a PALAVRA
			
			if(strlen(temaPalavra[1]) >= 25){
				mgotoxy(29, 24);
				printf("                                                        ");
				mgotoxy(30, 24);
				printf("~ Palavra inv%clida!", 160);
				Sleep(500);
				mgotoxy(29, 24);
				printf("                              ");
			}
		}while(strlen(temaPalavra[1]) >= 25);
		

		
		for(i=0; i<strlen(temaPalavra[1]); i++){
			if(temaPalavra[1][i] >= 97){
				temaPalavra[1][i] -= 32;
			}
		}
	}
	
	mgotoxy(91, 29);
	Sleep(1000);
}

int getEscolhaTema(){
	int escolhido=0, valido=0;
	
	do{
		mgotoxy(91, 29);
		escolhido = getch();
		
		switch(escolhido){
			case 49:
				mgotoxy(25, 8);
				printf("%c", 175);
				valido = 0;
				escolhido = 0;
				break;
				
			case 50:
				mgotoxy(25, 10);
				printf("%c", 175);
				valido = 0;
				escolhido = 1;
				break;
				
			case 51:
				mgotoxy(25, 12);
				printf("%c", 175);
				valido = 0;
				escolhido = 2;
				break;
				
			case 52:
				mgotoxy(25, 14);
				printf("%c", 175);
				valido = 0;
				escolhido = 3;
				break;
				
			case 53:
				mgotoxy(25, 16);
				printf("%c", 175);
				valido = 0;
				escolhido = 4;
				break;
				
			case 54:
				mgotoxy(46, 8);
				printf("%c", 175);
				valido = 0;
				escolhido = 5;
				break;
			case 55:
				mgotoxy(46, 10);
				printf("%c", 175);
				valido = 0;
				escolhido = 6;
				break;
				
			case 56:
				mgotoxy(46, 12);
				printf("%c", 175);
				valido = 0;
				escolhido = 7;
				break;
				
			case 57:
				mgotoxy(46, 14);
				printf("%c", 175);
				valido = 0;
				escolhido = 8;
				break;
				
			case 48:
				mgotoxy(46, 16);
				printf("%c", 175);
				valido = 0;
				escolhido = 9;
				break;
			
			default:
				valido = 1;
				break;
		}
	}while(valido);
	
	mgotoxy(91, 29);
	return escolhido;
}

int selecaoOpcoesJogo(int tecla, int posicao){
	int posicaoEscolhida=0;
	
	mgotoxy(4, 5);
	printf(" ");
	mgotoxy(4, 20);
	printf(" ");
	
	switch(posicao){
		case 0:
			posicaoEscolhida = 1;
			if(tecla == CIMA){
				mgotoxy(4, 20);
				printf("%c", 175);
				break;
			} else if(tecla == BAIXO){
				mgotoxy(4, 20);
				printf("%c", 175);
				break;
			}
			
		case 1:	
			posicaoEscolhida = 0;
			if(tecla == CIMA){
				mgotoxy(4, 5);
				printf("%c", 175);
				break;
			} else if(tecla == BAIXO){
				mgotoxy(4, 5);
				printf("%c", 175);
				break;
			}
	}
	
	mgotoxy(91, 29);
	return posicaoEscolhida;
}

int escolhaOpcoesJogo(int *posicao){
	int escolha=0, continua=0;
	
	mgotoxy(4, 5);
	printf("%c", 175);
	mgotoxy(91, 29);
	
	do{
		
		escolha = selecionaOpcoesJogo();
		
		if(escolha == ENTER){
			if(*posicao == 0){
				return 0;
			} else if(*posicao == 1){
				return 1;
			}
			continua = 0;
		} else if(escolha == CIMA){
			*posicao = selecaoOpcoesJogo(escolha, *posicao);
			continua = 1;
		} else if(escolha == BAIXO){
			*posicao = selecaoOpcoesJogo(escolha, *posicao);
			continua = 1;
		}
	}while(1);
}

int selecionaOpcoesJogo(){
	int tecla=0, tmp=0, continua=0;
	short cima, baixo, enter;
		
	do{	
		fflush(stdin);
		fflush(stdout);
			
		tmp = 0;
		tecla = 0;
		
		tmp = getch();
		
		if(tmp == 224){
			tecla = getch();
			continua=0;
		} else if(tmp == 13){
			tecla = 13;
			continua=0;
		} else {
			continua = 1;
		}
	}while(continua == 1);
	
	return tecla;
}

char leValidaLetra(){
	int letraValida=0;
	char letraDigitada;
	
	do{
		letraValida = 0;
		
		fflush(stdin);
		mgotoxy(37, 21);
		printf("                  ");
		mgotoxy(37, 21);
		scanf("%c", &letraDigitada);
		
		if(letraDigitada >= 97 && letraDigitada <= 122){
			letraDigitada -= 32;
		} else {
			if(letraDigitada >= 65 && letraDigitada <= 90){
				letraValida = 0;
			} else if(letraDigitada == '*'){
				letraValida = 0;
			} else{
				mgotoxy(39, 21);
				printf("~ Letra inv%clida!", 160);
				Sleep(500);
				mgotoxy(39, 21);
				printf("                  ");
				letraValida++;
			}
		}
	}while(letraValida > 0);
	
	return letraDigitada;
}

int validaLetraUsada(int iteracoes, char letrasUsadas[26], char letraDigitada){
	int letraInvalida, i;
	
	letraInvalida = 0;
	
	for(i=0; i<iteracoes; i++){
		if(letraDigitada == letrasUsadas[i]){
			letraInvalida++;
			break;
		} else {
			letraInvalida = 0;
		}
	}
	
	if(letraInvalida > 0){ //Se a letra já foi usada
		return 0;
	} else {
		return 1;
	}
}

int comecaJogo(){
	
	char temaEPalavra[2][26], letrasUsadas[26], vetorComparacao[strlen(temaEPalavra[1]) + 1], letraDigitada, tentativaArriscada[26];
	int quantidadeDeVidas, quantidadeErros, i, estaNaPalavra, qntLetrasDigitadas, eValida, acertouTodas, foiArriscada;
	
	quantidadeDeVidas = 6;
	quantidadeErros = 0;
	qntLetrasDigitadas = 0;
	acertouTodas = 0;
	foiArriscada = 0;
	
	drawOpcoesJogo(0);
	opcoesJogo(temaEPalavra);
	system("cls");
	drawWalls();
	drawTema(temaEPalavra);
	drawLetrasUsadas(' ', 0);
	
	for(i=0; i<strlen(temaEPalavra[1]); i++){ // Trocas as letras da palavra-chave por "_"
		if(temaEPalavra[1][i] == 32){
			strcat(vetorComparacao, " ");
		}
		if(temaEPalavra[1][i] >= 65 && temaEPalavra[1][i] <= 90){
			strcat(vetorComparacao, "_");
		}
	}
	
	mgotoxy(35, 21);
	printf("%c", 175); // Printa uma seta para sinalizar o local de entrada das letras
	
	do{
		estaNaPalavra = 0;
		acertouTodas = 0;
		
		mgotoxy(35, 19);
		textcolor(WHITE);
		puts(vetorComparacao); // Printa na tela a palavra chave codificada
		drawVidas(quantidadeDeVidas);
		drawPersonagem(quantidadeErros);
		
		if(quantidadeErros == 6){
			mgotoxy(29, 19);
			printf("A palavra era: %s", temaEPalavra[1]);
			mgotoxy(35, 21);
			printf("       ");
			break;
		}
		
		do{
			letraDigitada = leValidaLetra();
			if(letraDigitada == '*'){
				break;
			}
			eValida = validaLetraUsada(qntLetrasDigitadas, letrasUsadas, letraDigitada);
			if(eValida == 0){
				mgotoxy(39, 21);
				printf("~Letra j%c foi utilizada!", 160);
				Sleep(500);
				mgotoxy(39, 21);
				printf("                         ");
			} else if(eValida == 1){
				letrasUsadas[qntLetrasDigitadas] = letraDigitada;
				for(i=0; i<=qntLetrasDigitadas; i++){
					drawLetrasUsadas(letrasUsadas[i], i); // Escreve as letras que já foram usadas
				}
				qntLetrasDigitadas++;
			}
		}while(eValida == 0);
		
		if(letraDigitada == '*'){
			
			foiArriscada = 1;
			fflush(stdin);
			fflush(stdout);
			
			mgotoxy(23, 21);
			printf("Voc%c optou pela tentativa arriscada!", 136);
			mgotoxy(35, 23);
			printf("%c", 175);
			mgotoxy(37, 23);
			scanf("%[^\n]", tentativaArriscada);
			
			for(i=0; i<strlen(tentativaArriscada); i++){
				if(tentativaArriscada[i] >= 97){
					tentativaArriscada[i] -= 32;
				}
			}
			
			mgotoxy(23, 21);
			printf("                                     ");
			mgotoxy(35, 23);
			printf("                                     ");
			
			if(strcmp(tentativaArriscada, temaEPalavra[1]) == 0){ // Acertou a palavra
				mgotoxy(35, 19);
				textcolor(GREEN);
				puts(temaEPalavra[1]);
				textcolor(WHITE);
				mgotoxy(28, 21);
				printf("PARABENS! Voc%c acertou!!!", 136);
				acertouTodas = 1;
				Sleep(1000);
				break;
			} else { // Errou a palavra
				mgotoxy(35, 19);
				textcolor(LIGHTRED);
				puts(temaEPalavra[1]);
				textcolor(WHITE);
				mgotoxy(34, 21);
				printf("Voc%c ERROU!", 136);
				mgotoxy(28, 23);
				printf("Palavra digitada: %s", tentativaArriscada);
				mgotoxy(28, 24);
				printf("Palavra-chave   : %s", temaEPalavra[1]);
				quantidadeErros = 6;
				Sleep(2000);
				break;
			}
		}
		
		for(i=0; i<strlen(temaEPalavra[1]); i++){
			if(letraDigitada == temaEPalavra[1][i]){
				vetorComparacao[i] = letraDigitada;
				estaNaPalavra++;
				mgotoxy(35, 19);
				textcolor(GREEN);
				puts(vetorComparacao);
				Sleep(300);
				textcolor(WHITE);
				mgotoxy(35, 19);
				puts(vetorComparacao);
			}
		}
		
		if(estaNaPalavra == 0){
			quantidadeErros++;
			quantidadeDeVidas--;
		}
		
		for(i=0; i<strlen(vetorComparacao); i++){
			if(vetorComparacao[i] == '_'){
				acertouTodas++;
			}
		}
		
		if(acertouTodas > 0){
			acertouTodas = 0;
		} else if(acertouTodas == 0){
			acertouTodas = 1;
		}
	} while(quantidadeErros <= 6 && acertouTodas == 0);
	
	if(quantidadeErros == 6){
		Sleep(2400);
		system("cls");
	}
	
	if(acertouTodas == 1 && foiArriscada == 0){
		mgotoxy(35, 19);
		textcolor(GREEN);
		puts(vetorComparacao);
		textcolor(WHITE);
		Sleep(500);
		system("cls");
	} else if(acertouTodas == 1 && foiArriscada == 1){
		Sleep(500);
		system("cls");
	}
	
	if(quantidadeErros == 6){
		return 0; // Perdeu
	} else if(acertouTodas == 1){
		return 1; // Ganhou
	}
}

void vitoria(){
	int i;
	
	drawWalls();
	
	for(i=0; i <= 9; i++){
		if(i==0){
			textcolor(YELLOW);
			mgotoxy(31, 15);
			printf("       ___________      ");
			mgotoxy(31, 16);
			printf("      '._==_==_=_.'     ");
			mgotoxy(31, 17);
			printf("      .-\\:      /-.    ");
			mgotoxy(31, 18);
			printf("     | (|:.     |) |    ");
			mgotoxy(31, 19);
			printf("      '-|:.     |-'     ");
			mgotoxy(31, 20);
			printf("        \\::.    /      ");
			mgotoxy(31, 21);
			printf("         '::. .'        ");
			mgotoxy(31, 22);
			printf("           ) (          ");
			mgotoxy(31, 23);
			printf("         _.' '._        ");
			mgotoxy(31, 24);
			printf("        '-------'       ");
		} else {
			Sleep(800);
		}
		
		if(i%2 == 0){
			mgotoxy(67, 15); // apaga figura 2
			printf("       ");
			mgotoxy(67, 16);
			printf("       ");
			mgotoxy(67, 17);
			printf("       ");
			mgotoxy(67, 18);
			printf("       ");
			mgotoxy(67, 19);
			printf("       ");
			
			textcolor(LIGHTBLUE);
			mgotoxy(18, 15); // desenha figura 1
			printf(" .''. ");
			mgotoxy(18, 16);
			printf(":_\\/_:");
			mgotoxy(18, 17);
			printf(": /\\ :");
			mgotoxy(18, 18);
			printf(" '..'");
			
			textcolor(WHITE);
			mgotoxy(5, 3);
			printf("$$\\     $$\\                     ");
			mgotoxy(5, 4);
			printf("\\$$\\   $$  |                    ");
			mgotoxy(5, 5);
			printf(" \\$$\\ $$  /$$$$$$\\  $$\\   $$\\");
			mgotoxy(5, 6);
			printf("  \\$$$$  /$$  __$$\\ $$ |  $$ |  ");
			mgotoxy(5, 7);
			printf("   \\$$  / $$ /  $$ |$$ |  $$ |   ");
			mgotoxy(5, 8);
			printf("    $$ |  $$ |  $$ |$$ |  $$ |    ");
			mgotoxy(5, 9);
			printf("    $$ |  \\$$$$$$  |\\$$$$$$  |  ");
			mgotoxy(5, 10);
			printf("    \\__|   \\______/  \\______/  ");
			
			mgotoxy(56, 3);
			printf("$$\\      $$\\ $$\\           ");
			mgotoxy(56, 4);
			printf("$$ | $\\  $$ |\\__|          ");
			mgotoxy(56, 5);
			printf("$$ |$$$\\ $$ |$$\\ $$$$$$$\\  ");
			mgotoxy(56, 6);
			printf("$$ $$ $$\\$$ |$$ |$$  __$$\\ ");
			mgotoxy(56, 7);
			printf("$$$$  _$$$$ |$$ |$$ |  $$ |");
			mgotoxy(56, 8);
			printf("$$$  / \\$$$ |$$ |$$ |  $$ |");
			mgotoxy(56, 9);
			printf("$$  /   \\$$ |$$ |$$ |  $$ |");
			mgotoxy(56, 10);
			printf("\\__/     \\__|\\__|\\__|  \\__|");
			mgotoxy(91, 29);
		} else {
			mgotoxy(18, 15);  // Apaga fogos 1
			printf("      ");
			mgotoxy(18, 16);
			printf("      ");
			mgotoxy(18, 17);
			printf("      ");
			mgotoxy(18, 18);
			printf("      ");
			
			textcolor(LIGHTRED);
			mgotoxy(67, 15); // Desenha fogos2
			printf("   .   ");
			mgotoxy(67, 16);
			printf(".'.:.'.");
			mgotoxy(67, 17);
			printf("-=:o:=-");
			mgotoxy(67, 18);
			printf("'.':'.'");
			mgotoxy(67, 19);
			printf("   '   ");
			
			mgotoxy(34, 3); // Apaga linha que estava atrapalhando no print da primeira imagem
			printf(" ");
			mgotoxy(34, 4);
			printf(" ");
			mgotoxy(34, 5);
			printf(" ");
			mgotoxy(34, 6);
			printf(" ");
			mgotoxy(34, 7);
			printf(" ");
			mgotoxy(34, 8);
			printf(" ");
			mgotoxy(34, 9);
			printf(" ");
			mgotoxy(34, 10);
			printf(" ");
			
			textcolor(WHITE);
			mgotoxy(5, 3);
			printf(" /$$     /$$                 ");
			mgotoxy(5, 4);
			printf("|  $$   /$$/                 ");
			mgotoxy(5, 5);
			printf(" \\  $$ /$$//$$$$$$  /$$   /$$");
			mgotoxy(5, 6);
			printf("  \\  $$$$//$$__  $$| $$  | $$");
			mgotoxy(5, 7);
			printf("   \\  $$/| $$  \\ $$| $$  | $$");
			mgotoxy(5, 8);
			printf("    | $$ | $$  | $$| $$  | $$");
			mgotoxy(5, 9);
			printf("    | $$ |  $$$$$$/|  $$$$$$/");
			mgotoxy(5, 10);
			printf("    |__/  \\______/  \\______/ ");
			
			mgotoxy(56, 3);
			printf(" /$$      /$$ /$$          ");
			mgotoxy(56, 4);
			printf("| $$  /$ | $$|__/          ");
			mgotoxy(56, 5);
			printf("| $$ /$$$| $$ /$$ /$$$$$$$ ");
			mgotoxy(56, 6);
			printf("| $$/$$ $$ $$| $$| $$__  $$");
			mgotoxy(56, 7);
			printf("| $$$$_  $$$$| $$| $$  \\ $$");
			mgotoxy(56, 8);
			printf("| $$$/ \\  $$$| $$| $$  | $$");
			mgotoxy(56, 9);
			printf("| $$/   \\  $$| $$| $$  | $$");
			mgotoxy(56, 10);
			printf("|__/     \\__/|__/|__/  |__/");
			mgotoxy(91 , 29);
		}
		textcolor(WHITE);
		switch(i){
			case 7:
				mgotoxy(30, 25);
				printf("Voltando para o menu em 3...");
				break;
			case 8:
				mgotoxy(30, 25);
				printf("Voltando para o menu em 2..");
				break;
			case 9:
				mgotoxy(30, 25);
				printf("Voltando para o menu em 1.");
				break;
		}
		mgotoxy(91, 29);
	}
	
	Sleep(500);
	system("cls");
}

void derrota(){
	int i=0;
	short enter;
	
	system("cls");
	drawWalls();
	
	for(i=0; i<=10; i++){
		Sleep(500);
		textcolor(RED);
		if(i%2 == 0){
			mgotoxy(42, 2);
			printf("                    ################      ");
			mgotoxy(42, 3);
			printf("                 ######################   ");
			mgotoxy(42, 4);
			printf("                ########################  ");
			mgotoxy(42, 5);
			printf("               ########################## ");
			mgotoxy(42, 6);
			printf("              ########################### ");
			mgotoxy(42, 7);
			printf("             #############################");
			mgotoxy(42, 8);
			printf("             #############################");
			mgotoxy(42, 9);
			printf("             #############################");
			mgotoxy(42, 10);
			printf("             #############################");
			mgotoxy(42, 11);
			printf("             #############################");
			mgotoxy(42, 12);
			printf("             #############################");
			mgotoxy(42, 13);
			printf("             ## #       #######       # ##");
			mgotoxy(42, 14);
			printf("             # #         #####         # #");
			mgotoxy(42, 15);
			printf("             ##          #####          ##");
			mgotoxy(42, 16);
			printf("             ###       #########       ###");
			mgotoxy(42, 17);
			printf("              ############   ############ ");
			mgotoxy(42, 18);
			printf("               ##########     ##########  ");
			mgotoxy(42, 19);
			printf("                    #####  #  ####        ");
			mgotoxy(42, 20);
			printf("                   # ############  #      ");
			mgotoxy(42, 21);
			printf("                   #   # #  # #    #      ");
			mgotoxy(42, 22);
			printf("                   #              ##      ");
			mgotoxy(42, 23);
			printf("                   ### # #  # # ###       ");
			mgotoxy(42, 24);
			printf("                    ##############        ");
			mgotoxy(42, 25);
			printf("                     ############         ");
			mgotoxy(42, 26);
			printf("                       ########           ");
			mgotoxy(42, 27);
			printf("                                          ");
			
			textcolor(WHITE);
			mgotoxy(5, 4);
			printf("                                         ");
			mgotoxy(5, 5);
			printf("  ######      ###    ##     ## ########  ");
			mgotoxy(5, 6);
			printf(" ##    ##    ## ##   ###   ### ##        ");
			mgotoxy(5, 7);
			printf(" ##         ##   ##  #### #### ##        ");
			mgotoxy(5, 8);
			printf(" ##   #### ##     ## ## ### ## ######    ");
			mgotoxy(5, 9);
			printf(" ##    ##  ######### ##     ## ##        ");
			mgotoxy(5, 10);
			printf(" ##    ##  ##     ## ##     ## ##        ");
			mgotoxy(5, 11);
			printf("  ######   ##     ## ##     ## ########  ");
			mgotoxy(5, 12);
			printf("                                         ");
			mgotoxy(5, 13);
			printf("  #######  ##     ## ######## ########   ");
			mgotoxy(5, 14);
			printf(" ##     ## ##     ## ##       ##     ##  ");
			mgotoxy(5, 15);
			printf(" ##     ## ##     ## ##       ##     ##  ");
			mgotoxy(5, 16);
			printf(" ##     ## ##     ## ######   ########   ");
			mgotoxy(5, 17);
			printf(" ##     ##  ##   ##  ##       ##   ##    ");
			mgotoxy(5, 18);
			printf(" ##     ##   ## ##   ##       ##    ##   ");
			mgotoxy(5, 19);
			printf("  #######     ###    ######## ##     ##  ");
			mgotoxy(5, 20);
			printf("                                         ");
			
			mgotoxy(91, 29);
		} else {
			mgotoxy(42, 2);
			printf("                    ################      ");
			mgotoxy(42, 3);
			printf("                 ######################   ");
			mgotoxy(42, 4);
			printf("                ########################  ");
			mgotoxy(42, 5);
			printf("               ########################## ");
			mgotoxy(42, 6);
			printf("              ########################### ");
			mgotoxy(42, 7);
			printf("             #############################");
			mgotoxy(42, 8);
			printf("             #############################");
			mgotoxy(42, 9);
			printf("             #############################");
			mgotoxy(42, 10);
			printf("             #############################");
			mgotoxy(42, 11);
			printf("             #############################");
			mgotoxy(42, 12);
			printf("             #############################");
			mgotoxy(42, 13);
			printf("             ## #       #######       # ##");
			mgotoxy(42, 14);
			printf("             # #         #####         # #");
			mgotoxy(42, 15);
			printf("             ##          #####          ## ");
			mgotoxy(42, 16);
			printf("             ###       #########       ###");
			mgotoxy(42, 17);
			printf("              ############   ############ ");
			mgotoxy(42, 18);
			printf("               ##########     ##########  ");
			mgotoxy(42, 19);
			printf("                    #####  #  ####        ");
			mgotoxy(42, 20);
			printf("                     ############         ");
			mgotoxy(42, 21);
			printf("                   #   # #  # #    #      ");
			mgotoxy(42, 22);
			printf("                   #               #");
			mgotoxy(42, 23);
			printf("                   ##             ##      ");
			mgotoxy(42, 24);
			printf("                    ## # #  # # ##        ");
			mgotoxy(42, 25);
			printf("                    ##############        ");
			mgotoxy(42, 26);
			printf("                     ############         ");
			mgotoxy(42, 27);
			printf("                       ########           ");
			
			textcolor(WHITE);
			mgotoxy(5, 4);
			printf("........................................");
			mgotoxy(5, 5);
			printf("..######......###....##.....##.########.");
			mgotoxy(5, 6);
			printf(".##....##....##.##...###...###.##.......");
			mgotoxy(5, 7);
			printf(".##.........##...##..####.####.##.......");
			mgotoxy(5, 8);
			printf(".##...####.##.....##.##.###.##.######...");
			mgotoxy(5, 9);
			printf(".##....##..#########.##.....##.##.......");
			mgotoxy(5, 10);
			printf(".##....##..##.....##.##.....##.##.......");
			mgotoxy(5, 11);
			printf("..######...##.....##.##.....##.########.");
			mgotoxy(5, 12);
			printf("........................................");
			mgotoxy(5, 13);
			printf("..#######..##.....##.########.########..");
			mgotoxy(5, 14);
			printf(".##.....##.##.....##.##.......##.....##.");
			mgotoxy(5, 15);
			printf(".##.....##.##.....##.##.......##.....##.");
			mgotoxy(5, 16);
			printf(".##.....##.##.....##.######...########..");
			mgotoxy(5, 17);
			printf(".##.....##..##...##..##.......##...##...");
			mgotoxy(5, 18);
			printf(".##.....##...##.##...##.......##....##..");
			mgotoxy(5, 19);
			printf("..#######.....###....########.##.....##.");
			mgotoxy(5, 20);
			printf("........................................");
			
			mgotoxy(91, 29);
		}
		
		textcolor(WHITE);
		switch(i){
			case 8:
				mgotoxy(11, 24);
				printf("Voltando para o menu em 3...");
				break;
			case 9:
				mgotoxy(11, 24);
				printf("Voltando para o menu em 2..");
				break;
			case 10:
				mgotoxy(11, 24);
				printf("Voltando para o menu em 1.");
				break;
		}
		mgotoxy(91, 29);
	}
	
	Sleep(1000);
	system("cls");
}

int main(){
	
	_setcursortype(0); 
	int pressionada, posicaoY, *posy, primeiraIteracao=0, finalizar=1, ganhouPerdeu;
	
	setlocale(LC_ALL, NULL);
	system("MODE con cols=91 lines=30");
	
	posicaoY = 20; // Posição inicial para o menu principal (Aponta para "iniciar")
	posy = &posicaoY;

	do{
		fflush(stdin);
		if(primeiraIteracao == 0){
			drawMainMenu();
			pressionada = 19;
			posicaoY = selecaoMenu(*posy, pressionada, primeiraIteracao);
			primeiraIteracao++;
		} else {
			pressionada = getTeclaMenuPrincipal();
			if(pressionada == ENTER){
				switch(posicaoY){
					case 19:
						system("cls");
						drawWalls();
						if(loadingScreen()){
							ganhouPerdeu = comecaJogo();
							if(ganhouPerdeu == 1){
								vitoria();
							} else if(ganhouPerdeu == 0){
								derrota();
							}
							drawMainMenu();
							posicaoY = selecaoMenu(20, CIMA, 1); // Retorna para o menu principal e coloca um ponteiro em "iniciar".
						}
						break;
					case 20:
						drawAjuda();
						if(getTeclaSobreAjuda() == ENTER){
							system("cls");
							drawMainMenu();
							posicaoY = selecaoMenu(19, BAIXO, 1); // Retorna para o menu principal e coloca um ponteiro em "Ajuda".
						}
						break;
					case 21:
						drawSobre();
						if(getTeclaSobreAjuda() == ENTER){
							system("cls");
							drawMainMenu();
							posicaoY = selecaoMenu(20, BAIXO, 1); // Retorna para o menu principal e coloca um ponteiro em "Sobre".
						}
						break;
					case 22:
						system("cls");
						finalizar = 0;
						break;
				}
			} else {
				posicaoY = selecaoMenu(*posy, pressionada, primeiraIteracao);
			}
		}
	} while(finalizar);
	
	return 0;
}

