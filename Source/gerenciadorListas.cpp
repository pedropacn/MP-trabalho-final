/*Funcoes do modulo*/
#include "lista.h" //struct lista
#include "common.h" //funcoes genericas para todos os .cpp
#include <fstream> //manipular arquivos com getline
#include <ncurses.h> //interface grafica
#include <string.h> //tipo string
#include <stdlib.h> //atoi - converter string para inteiro

#define SIZE_ID_LISTA 4
#define SIZE_ID_USER 2
#define SIZE_CODBARRAS 13

using namespace std;

void removeDaLista(string itemRemovido, lista listaCompras) {
	//REMOVE DE listaCompras A PRIMEIRA OCORRENCIA DO PRODUTO nomeProduto (CASO EXISTAM 2 DO PRODUTO, MANTER UM DELES)
}

lista recuperarListaPorCod(string codListaRecuperada){ //usuario inseriu Codigo da lista; retornar struct da lista
	lista listaEncontrada, temp; //inicializar
	listaEncontrada.codLista = "";
	listaEncontrada.codUsuario = "";
	listaEncontrada.numElementos = -1;
	listaEncontrada.elementos = "";
	
	string line;
	ifstream myfile ("listas.txt");

	while (getline (myfile,line)) { //para cada line

		temp.codLista = line.substr(0,4);
		temp.codUsuario = line.substr(5, 2);
		temp.numElementos = atoi(line.substr(8, 3).c_str()); //substring convertida para inteiro usando atoi
		temp.elementos = line.substr(12);


		if (codListaRecuperada.compare(temp.codLista) == 0) { //se o pesquisado == encontrado
			listaEncontrada = temp;
			//escreve("Lista encontrada: ", listaEncontrada.codLista, "\n");
			break; //interrompe while
		}
	}
    myfile.close();
	return listaEncontrada;
}

void exibirLista(lista listaExibida) {

	//EXIBIR CONTEUDO DA STRUCT listaExibida
	return;
}

void apagarLista(char* codListaRecuperada) {
	printw("Deletando lista do arquivo\n");
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

	clear();
	printw("Insira a opção desejada\n\n");
	printw("1. Criar nova lista \n");
	printw("2. Editar lista existente \n");
	printw("Qualquer outro valor para encerrar\n");
	char opcao = getch();

	lista listaAtual;
	listaAtual.codLista = ""; //inicializa com valor inválido
	char codListaRecuperada[SIZE_ID_LISTA], numUsuario[SIZE_ID_LISTA]; //VERIFICAR COMO SAO LIDOS
	string stringNumUsuario;

	switch(opcao) {
		case '1':
			printw("Criando lista\n");
			break;
		case '2':
			clear();
			printw("Insira o código da lista\n");
			getnstr(codListaRecuperada,SIZE_ID_LISTA);
			listaAtual = recuperarListaPorCod(codListaRecuperada); //atualiza listaAtual para valor obtido de listas.txt
			
			if (listaAtual.codLista == "") { //lista inexistente
				clear();
				printw("Lista de código %s não encontrada\n\n", codListaRecuperada);
				return;
			}
			clear();
			printw("Lista %s do usuario %s possui os seguintes %d elementos: !%s!\n", listaAtual.codLista.c_str(), listaAtual.codUsuario.c_str(), listaAtual.numElementos, listaAtual.elementos.c_str()); //c_str() utilizada pra fazer printw
			printw("Insira o código do usuário\n");
			getnstr(numUsuario,SIZE_ID_LISTA);
			stringNumUsuario = numUsuario; //criar string a partir do const char* para usar compare
			clear();

			if (stringNumUsuario.compare(listaAtual.codUsuario) != 0) {

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
	listaAtual.codLista = ""; //inicializa com valor inválido
	char codListaRecuperada[SIZE_ID_LISTA], numUsuario[SIZE_ID_LISTA]; //VERIFICAR COMO SAO LIDOS

	printw("Insira o código da lista cujas compras serão realizadas\n");
	getnstr(codListaRecuperada,SIZE_ID_LISTA);
	listaAtual = recuperarListaPorCod(codListaRecuperada); //atualiza listaAtual para valor obtido de listas.txt
	
	if (listaAtual.numElementos == -1) { //lista inexistente
		clear();
		printw("Lista de código %s não encontrada\n\n", codListaRecuperada);
		return;
	}

	printw("Insira o código do usuário\n");
	getnstr(numUsuario,SIZE_ID_LISTA);

	if (listaAtual.codUsuario.compare(numUsuario)== 0) {
		clear();
		printw("Usuário inválido para a lista em questão\n\n");
		return;
	}

	/*INFORMAR O CUSTO TOTAL DE listaAtual*/

	

	endwin();
	return; //finalizar operação
}