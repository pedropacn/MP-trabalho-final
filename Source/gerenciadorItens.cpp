/*Funcoes do modulo*/
#include <iostream>
#include <fstream>
#include <ncurses.h>
#include <fstream>
#include "item.h"
#include "common.h"
#include <string>

#define SIZE_NAME_ITEM 200
#define SIZE_CODBARRAS 13

using namespace std;

bool insereItem(item novoItem) {
	//RETORNA TRUE SE ESCREVER; RETORNA FALSE SE DER MERDA

	//REALIZA FOPEN EM ARQUIVO itens.txt
	//FORMATO DO ITEM NO ARQUIVO: <id>;<codBarras>;<nomeItem>\n
	//O ID TERA SEMPRE 4 CARACTERES Ex: 0001, 0002... ate 9999
	//INSERE Item NO ARQUIVO
	//FCLOSE
	return false;
}

item pesquisaItemPorCodBarras(string codBarras) {
	item encontrado, temp;
	encontrado.codBarras = ""; //inicializar struct com valores nulos
	encontrado.nomeItem = "";
	
	string line;
	ifstream myfile ("itens.txt");

	while (getline (myfile,line)) { //para cada line

		temp.codBarras = line.substr(0, 13);
		temp.preco = line.substr(14, 7);
		temp.nomeItem = line.substr(21);

		if (codBarras.compare(temp.codBarras) == 0) { //se o pesquisado == encontrado
			encontrado = temp;
			break;
		}
	}

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
	
	char codBarras[SIZE_CODBARRAS];
	escreve("Insira o código de barras do Item:\n");
	getnstr(codBarras, SIZE_CODBARRAS); //METODO PARA LER STRING DO TECLADO
	clear();
	
	item pesquisado = (pesquisaItemPorCodBarras(codBarras)); //Retornar o Item, caso exista
	if (pesquisado.codBarras != "") { //o Item não foi encontrado
		escreve("Item de código ", codBarras, " já está cadastrado\n\n");
		return;
	}

	/*cadastrar item*/
	escreve ("Item ",codBarras," nao cadastrado\n");
	escreve("Insira o nome do item: ");
	char name[SIZE_NAME_ITEM];
	getnstr(name, SIZE_NAME_ITEM);
	clear();

	bool result = insereItem(pesquisado);
	if (result)
		escreve("Item ",name," inserido com sucesso\n"); //necessario pra mostrar variavel inserida pelo usuario
	else
		escreve("Insercao do item ",name," invalida\n"); //necessario pra mostrar variavel inserida pelo usuario
	endwin(); //finaliza o ncurses
}