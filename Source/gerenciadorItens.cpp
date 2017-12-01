/*Funcoes do modulo*/
#include <iostream>
#include <fstream>
#include <ncurses.h>
#include <fstream>
#include "item.h"
#include "common.h"
#include <string>

#define SIZENAME 200
#define SIZEBARRAS 13

using namespace std;

void insereItem(item novoItem) {

	//REALIZA FOPEN EM ARQUIVO itens.txt
	//FORMATO DO ITEM NO ARQUIVO: <id>;<codBarras>;<nomeItem>\n
	//INSERE Item NO ARQUIVO
	//FCLOSE
	return;
}

item pesquisaItemPorCodBarras(string codBarras) {
	item encontrado;
	encontrado.codBarras = ""; //inicializar struct com valores nulos
	encontrado.nomeItem = "";
	
	string line;
	ifstream myfile ("itens.txt");

	while (getline (myfile,line)) { //para cada line
		const char* lineChar = line.c_str();
		printw("%s\n", lineChar);

		//string nameItem = line.substr(0, str.find(";"));
		//printf("%s\n", nameItem);

	}
	//REALIZA FOPEN EM ARQUIVO itens.txt
	//FORMATO DO ITEM NO ARQUIVO: <id>;<codBarras>;<nomeItem>\n
	//PESQUISAR Item NO ARQUIVO
	//CASO ENCONTRE O ARQUIVO, ATUALIZAR OS VALORES DE encontrado.codBarras e encontrado.nomeItem
	//FCLOSE

    myfile.close();
	return encontrado;
}

item pesquisaItemPorNome(string nomeItem) {
	item encontrado;
	encontrado.codBarras = ""; //inicializar struct com valores nulos
	encontrado.nomeItem = "";

	//REALIZA FOPEN EM ARQUIVO itens.txt
	//FORMATO DO ARQUIVO: <id>;<codBarras>;<nomeItem>\n
	//PESQUISAR Item NO ARQUIVO
	//CASO ENCONTRE O ARQUIVO, ATUALIZAR OS VALORES DE encontrado.codBarras e encontrado.nomeItem
	//FCLOSE
	return encontrado;
}

void menu_cadastrar_item() {

	refresh();
	clear(); //limpar tela
	
	char codBarras[SIZEBARRAS];
	printw("Insira o código de barras do Item:\n");
	getnstr(codBarras, SIZEBARRAS);
	clear();
	
	item pesquisado = (pesquisaItemPorCodBarras(codBarras)); //Retornar o Item, caso exista
	if (pesquisado.codBarras == "") { //o Item não foi encontrado
		printw("Item de código %s já está cadastrado\n\n", codBarras);
		return;
	}

	/*cadastrar item*/
	char name[SIZENAME];
	printw("Insira o nome do Item: \n");
	getnstr(name, SIZENAME);

	insereItem(pesquisado);
	clear();

	printw("Item %s de código de barras %s cadastrado com sucesso: \n", name, codBarras);

	endwin(); //finaliza o ncurses
}