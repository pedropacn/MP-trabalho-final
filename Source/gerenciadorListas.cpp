/*Funcoes do modulo*/
#include <iostream>
#include "lista.h"

using namespace std;

void removeDaLista(string itemRemovido, lista listaCompras) {
	//REMOVE DE listaCompras A PRIMEIRA OCORRENCIA DO PRODUTO nomeProduto (CASO EXISTAM 2 DO PRODUTO, MANTER UM DELES)
}

lista recuperarListaPorCod(int codListaRecuperada){ //usuario inseriu Codigo da lista; retornar struct da lista

	//REALIZA FOPEN EM ARQUIVO listas.txt
	//FORMATO DA LISTA: <codigo>;<codUsuario>;<numeroDeItens>;<item1>;<item2>;...\n
	//PESQUISAR Item NO ARQUIVO
	//CASO ENCONTRE O ARQUIVO, ATUALIZAR OS VALORES DE encontrado.codBarras e encontrado.nomeItem
	//FCLOSE
}

void apagarLista(int codListaRecuperada) {
	//REALIZA FOPEN EM ARQUIVO listas.txt
	//FORMATO DA LISTA: <codigo>;<codUsuario>;<numeroDeItens>;<item1>;<item2>;...\n
	//ENCONTRAR LISTA NO ARQUIVO
	//REMOVER DO ARQUIVO TODA A LINHA CORRESPONDENTE À LISTA
	//FCLOSE	
}

void exibirLista(lista listaExibida) {

	//EXIBIR CONTEUDO DA STRUCT listaExibida
	return;
}

void salvarLista(lista listaFinal) {
	//REALIZA FOPEN EM ARQUIVO listas.txt
	//FORMATO DA LISTA: <codigo>;<codUsuario>;<numeroDeItens>;<item1>;<item2>;...\n
	//INSERE LISTA NO ARQUIVO
	//FCLOSE

}

void menu_lista() { //USUARIO DESEJA CRIAR/EDITAR LISTA DE ITENS JA CADASTRADOS

	int opcao;
	cout << "Insira a opção desejada\n";
	cout << "1. Criar nova lista \n";
	cout << "2. Editar lista existente \n";
	cout << "Qualquer outro valor para encerrar\n";
	cin >> opcao;

	lista listaAtual;
	listaAtual.codLista = -1; //inicializa com valor inválido
	int codListaRecuperada, numUsuario;

	switch(opcao) {
		case 1:
			cout << "Criando lista\n";
			break;
		case 2:
			

			cout << "Insira o código da lista\n";
			cin >> codListaRecuperada;
			cout << "Insira o código do usuário\n";
			cin >> numUsuario;

			listaAtual = recuperarListaPorCod(codListaRecuperada); //atualiza listaAtual para valor obtido de listas.txt
			if (listaAtual.codLista == -1) { //lista inexistente
				cout << "Codigo de lista inválido\n";
				return;
			}
			if (listaAtual.codUsuario != numUsuario) {
				cout << "Usuário inválido para a lista em questão\n";
				return;
			}
			apagarLista(codListaRecuperada); //apaga a lista atual; será adicionada posteriormente após as edições

			break;
		default:
			return;
	}

	//nesse ponto, listaAtual já contem a lista do cliente

	exibirLista(listaAtual); //mostra a lista para o cliente

	opcao = 0;
	cout << "Insira a opção desejada\n";
	cout << "1. Inserir produto \n";
	cout << "2. Remover produto \n";
	cout << "Qualquer outro valor para encerrar\n";
	cin >> opcao;
	string itemRemovido;

	switch(opcao) {
		case 1:
			cout << "Insira o nome do produto a ser inserido\n";
			//CRIAR UM METODO PARA VERIFICAR SE O ITEM ESTA CADASTRADO EM listaAtual
				//CASO ESTEJA, INSERIR NA LISTA E FINALIZAR: inserirItem(item, listaAtual);
				//CASO NÃO, OFERECER AO USUARIO PARA CADASTRAR O ITEM: menu_cadastrar_item();
			break;
		case 2:
			cout << "Insira o nome do produto a ser removido da lista\n";
			cin >> itemRemovido;
			removeDaLista(itemRemovido, listaAtual);
			break;
		default:
			return;
	}
	salvarLista(listaAtual);

	return; //finalizar operação
}