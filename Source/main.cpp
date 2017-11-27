#include <iostream>
#include <string>
#include <ncurses.h>
#include "gerenciadorItens.h"
#include "gerenciadorListas.h"

//MODULARIZACAO: PROGRAMA EM MULTICODIGOS
//PROGRAMA PRINCIPAL

using namespace std;

int main (int argc, char* argv[]) {

	initscr(); //inicializa o ncurses
	keypad(stdscr, TRUE); //habilita backspace, delete, arrows
	
	do {
		//move(2,0);
		//refresh();
		printw("MENU PRINCIPAL\n");
		printw("Insira a opção desejada\n");
		printw("1. Criar/Editar lista\n");
		printw("2. Cadastrar item\n");
		printw("3. Realizar compra\n");
		printw("0. Encerrar programa\n\n");
		
		char opcao = getch();
		//printw("\n\n");
		clear(); //limpa a tela

		switch(opcao) {
			case '1':
				//cout << "Gerenciando lista\n";
				menu_lista();
				break;

			case '2':
				//cout << "Cadastrar objeto\n";
				menu_cadastrar_item();
				break;

			case '3':
				//cout << "Cadastrar objeto\n";
				menu_compra();
				break;

			case '0':
				endwin(); //finaliza o ncurses
				return 0; //finaliza o programa
				break;

			default:
				printw("Opção nao identificada\n\n");
				break;
		}
	} while (true); //executa eternamente
	return 0;
}