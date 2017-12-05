/** @file */
/**
 * Módulo principal.
 */

/**
 * Bibliotecas utilizadas do C.
 */
#include "gerenciadorItens.h"
#include "gerenciadorListas.h"
#include <ncurses.h>

/**
 * Namespace padrao do C++.
 */
using namespace std;

int main (int argc, char* argv[]) {

	initscr(); ///< Inicializa o ncurses.
	keypad(stdscr, TRUE); ///< Habilita backspace, delete, arrows.

	/**
 	 * loop: infinito.
 	 */
	do {
		//move(2,0); #debug
		//refresh(); #debug
		printw("MENU PRINCIPAL\n");
		printw("Insira a opção desejada\n");
		printw("1. Criar/Editar lista\n");
		printw("2. Cadastrar item\n");
		printw("3. Realizar compra\n");
		printw("0. Encerrar programa\n\n");
		
		char opcao = getch();
		//printw("\n\n"); #debug

		switch(opcao) {
			case '1':
				//cout << "Gerenciando lista\n"; //debug 
				menu_lista();
				break;

			case '2':
				//cout << "Cadastrar objeto\n"; //debug
				menu_cadastrar_item();
				break;

			case '3':
				//cout << "Cadastrar objeto\n"; //debug
				menu_compra();
				break;

			case '0':
				endwin(); ///< Finaliza o ncurses.
				return 0; ///< Finaliza o programa.
				break;

			default:
				printw("Opção nao identificada\n\n");
				clear();
				break;
		}
	} while (true);
	return 0;
}