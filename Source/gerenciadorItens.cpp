/*Funcoes do modulo*/
#include <iostream>
#include "item.h"

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

	//REALIZA FOPEN EM ARQUIVO itens.txt
	//FORMATO DO ITEM NO ARQUIVO: <id>;<codBarras>;<nomeItem>\n
	//PESQUISAR Item NO ARQUIVO
	//CASO ENCONTRE O ARQUIVO, ATUALIZAR OS VALORES DE encontrado.codBarras e encontrado.nomeItem
	//FCLOSE
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

	string codBarras;
	cout << "Insira o código de barras do Item:\n";
	cin >> codBarras;
	
	item pesquisado = (pesquisaItemPorCodBarras(codBarras)); //Retornar o Item, caso exista
	if (pesquisado.codBarras == "") { //o Item não foi encontrado
		cout << "Item já cadastrado\n";
		return;
	}

	string name;
	cout << "1. Insira o nome do Item: \n";
	cin >> name;


	cout << "2. Cadastrar objeto\n";
	cout << "0. Encerrar programa\n";

	insereItem(pesquisado);
	
	int opcao;
	cin >> opcao;

}