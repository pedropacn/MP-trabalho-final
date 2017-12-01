/*Funcoes do modulo*/
#include <iostream>
#include <ncurses.h>
#include <string.h>
#include "lista.h"
#include "common.h"

#define SIZE_ID_LISTA 4
#define SIZE_ID_USER 2
#define SIZE_CODBARRAS 13

using namespace std;

void removeDaLista(string itemRemovido, lista listaCompras) {
	//REMOVE DE listaCompras A PRIMEIRA OCORRENCIA DO PRODUTO nomeProduto (CASO EXISTAM 2 DO PRODUTO, MANTER UM DELES)
}

lista recuperarListaPorCod(char* codListaRecuperada){ //usuario inseriu Codigo da lista; retornar struct da lista
	lista listaEncontrada; //inicializar
	listaEncontrada.codLista = NULL;
	listaEncontrada.codUsuario = NULL;
	listaEncontrada.elementos = NULL;

	//REALIZA FOPEN EM ARQUIVO listas.txt
	//FORMATO DA LISTA: <idLista>;<userID>;<numItens>;item1,item2,itemN
	//PESQUISAR Item NO ARQUIVO
	//CASO ENCONTRE O ARQUIVO, ATUALIZAR OS VALORES DE encontrado.codBarras e encontrado.nomeItem
	//FCLOSE
	return listaEncontrada;
}

void exibirLista(lista listaExibida) {

	//EXIBIR CONTEUDO DA STRUCT listaExibida
	return;
}

void apagarLista(char* codListaRecuperada) {
	//REALIZA FOPEN EM ARQUIVO listas.txt
	//FORMATO DA LISTA: <idLista>;<userID>;<numItens>;item1,item2,itemN
	//ENCONTRAR LISTA NO ARQUIVO
	//REMOVER DO ARQUIVO TODA A LINHA CORRESPONDENTE À LISTA
	//FCLOSE	
}

void salvarLista(lista listaFinal) {
	//REALIZA FOPEN EM ARQUIVO listas.txt
	//FORMATO DA LISTA: <idLista>;<userID>;<numItens>;item1,item2,itemN
	//INSERE LISTA NO ARQUIVO
	//FCLOSE

}

void menu_lista() { //USUARIO DESEJA CRIAR/EDITAR LISTA DE ITENS JA CADASTRADOS

	printw("Insira a opção desejada\n");
	printw("1. Criar nova lista \n");
	printw("2. Editar lista existente \n");
	printw("3. Editar lista existente \n");
	printw("Qualquer outro valor para encerrar\n");
	char opcao = getch();

	lista listaAtual;
	listaAtual.codLista = NULL; //inicializa com valor inválido
	char codListaRecuperada[SIZE_ID_LISTA], numUsuario[SIZE_ID_LISTA]; //VERIFICAR COMO SAO LIDOS

	switch(opcao) {
		case '1':
			printw("Criando lista\n");
			break;
		case '2':
			clear();
			printw("Insira o código da lista\n");
			getnstr(codListaRecuperada,SIZE_ID_LISTA);
			listaAtual = recuperarListaPorCod(codListaRecuperada); //atualiza listaAtual para valor obtido de listas.txt
			
			if (listaAtual.codLista == NULL) { //lista inexistente
				clear();
				printw("Lista de código %s não encontrada\n\n", codListaRecuperada);
				return;
			}

			printw("Insira o código do usuário\n");
			getnstr(numUsuario,SIZE_ID_LISTA);

			if (strcmp(listaAtual.codUsuario,numUsuario)) {
				clear();
				printw("Usuário inválido para a lista em questão\n\n");
				return;
			}
			apagarLista(codListaRecuperada); //apaga a lista atual; será adicionada posteriormente após as edições
			break;
		default:
			clear();
			return;
	}

	//nesse ponto, listaAtual já contem a lista do cliente
	clear();
	exibirLista(listaAtual); //mostra a lista para o cliente

	opcao = '0';
	printw("Insira a opção desejada\n");
	printw("1. Inserir produto \n");
	printw("2. Remover produto \n");
	printw("Qualquer outro valor para encerrar\n");
	opcao = getch();
	char itemRemovido[200];

	switch(opcao) {
		case '1':
			printw("Insira o nome do produto a ser inserido\n");
			//CRIAR UM METODO PARA VERIFICAR SE O ITEM ESTA CADASTRADO EM listaAtual
				//CASO ESTEJA, INSERIR NA LISTA E FINALIZAR: inserirItem(item, listaAtual);
				//CASO NÃO, OFERECER AO USUARIO PARA CADASTRAR O ITEM: menu_cadastrar_item();
			break;
		case '2':
			printw("Insira o nome do produto a ser removido da lista\n");
			getnstr(itemRemovido,200);
			removeDaLista(itemRemovido, listaAtual);
			break;
		default:
			clear();
			return;
	}
	salvarLista(listaAtual);

	endwin();
	return; //finalizar operação
}

void menu_compra() { //REALIZA COMPRA NO MERCADO
	lista listaAtual;
	listaAtual.codLista = NULL; //inicializa com valor inválido
	char codListaRecuperada[SIZE_ID_LISTA], numUsuario[SIZE_ID_LISTA]; //VERIFICAR COMO SAO LIDOS

	printw("Insira o código da lista cujas compras serão realizadas\n");
	getnstr(codListaRecuperada,SIZE_ID_LISTA);
	listaAtual = recuperarListaPorCod(codListaRecuperada); //atualiza listaAtual para valor obtido de listas.txt
	
	if (listaAtual.codLista == NULL) { //lista inexistente
		clear();
		printw("Lista de código %s não encontrada\n\n", codListaRecuperada);
		return;
	}

	printw("Insira o código do usuário\n");
	getnstr(numUsuario,SIZE_ID_LISTA);

	if (strcmp(listaAtual.codUsuario,numUsuario)) {
		clear();
		printw("Usuário inválido para a lista em questão\n\n");
		return;
	}

	/*INFORMAR O CUSTO TOTAL DE listaAtual*/

	

	endwin();
	return; //finalizar operação
}