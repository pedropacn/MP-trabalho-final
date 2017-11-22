#include <iostream>
#include <string>
#include "gerenciadorItens.h"
#include "gerenciadorListas.h"

//MODULARIZACAO: PROGRAMA EM MULTICODIGOS
//PROGRAMA PRINCIPAL

using namespace std;

int main (int argc, char* argv[]) {
	
	do {
		cout << "Insira a opção desejada\n";
		cout << "1. Criar/Editar lista\n";
		cout << "3. Cadastrar item\n";
		cout << "0. Encerrar programa\n";
		
		int opcao;
		cin >> opcao;
		cout <<"\n";
		
		switch(opcao) {
			case 1:
				//cout << "Gerenciando lista\n";
				menu_lista();
				break;
			case 3:
				//cout << "Cadastrar objeto\n";
				menu_cadastrar_item();
				break;
			case 0:
				return 0; //finaliza o programa
				break;
			default:
				cout << "Opção nao identificada\n";
				break;
		}
	} while (true); //executa eternamente
	
	return 0;
}