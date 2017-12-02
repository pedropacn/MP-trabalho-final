/*Funcoes do modulo*/
#include "lista.h" //struct lista
#include "common.h" //funcoes genericas para todos os .cpp
#include "gerenciadorItens.h" //gerenciar itens da lista
#include <fstream> //manipular arquivos com getline
#include <ncurses.h> //interface grafica
#include <string.h> //tipo string
#include <stdlib.h> //atoi - converter string para inteiro

#define SIZE_NAME_ITEM 200
#define SIZE_ID_LISTA 4
#define SIZE_ID_USER 2
#define SIZE_CODBARRAS 13
static const char* LISTAS_FILE = "listas.txt";
static const char* TEMP_FILE = "temp.txt";


using namespace std;

void exibirLista(lista listaExibida) {
	printw("------\n");
	printw("Codigo da lista: %s\n", listaExibida.codLista.c_str());
	printw("Codigo do usuário dono da lista: %s\n", listaExibida.codUsuario.c_str());
	printw("Numero de elementos: %d\n", listaExibida.numElementos);
	printw("Código dos elementos: %s\n\n", listaExibida.elementos.c_str());
	string barrasElementoAtual;

	for (int i = 0; i < listaExibida.numElementos; i++) { //Para cada elemento da lista...
		barrasElementoAtual = listaExibida.elementos.substr((14*i),13);
		item itemAtual = pesquisaItemPorCodBarras(barrasElementoAtual);
		string nomeItem = itemAtual.nomeItem;
		printw("Nome do elemento %d: %s\n", i, nomeItem.c_str());
		printw("Seu preço é: %s\n", itemAtual.preco.c_str());
		printw("Codigo de barras é: %s\n\n", barrasElementoAtual.c_str());

	}

	printw("------\n");
	return;
}

lista adicionaNaLista(item adicionado, lista listaCompras) { //adiciona item na lista e retorna-a
	
	//TODO: SE ITEM EXISTE ANTES DE SAIR ADICIONANDO

	lista novaLista = listaCompras;

	string listaAntiga = listaCompras.elementos;
	printw("A lista antiga era %s\n", listaAntiga.c_str());
	string listaNova = listaAntiga + "," + adicionado.codBarras;
	novaLista.elementos = listaNova;
	return novaLista;
} 

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
	ifstream myfile (LISTAS_FILE);

	while (getline (myfile,line)) { //para cada line

		temp.codLista = line.substr(0,4);
		temp.codUsuario = line.substr(5, 2);
		temp.numElementos = atoi(line.substr(8, 3).c_str()); //substring convertida para inteiro usando atoi
		temp.elementos = line.substr(12);


		if (codListaRecuperada.compare(temp.codLista) == 0) { //se o pesquisado == encontrado
			listaEncontrada = temp;
			break; //interrompe while
		}
	}
    myfile.close();
	return listaEncontrada;
}

/*Apaga a lista do arquivo .txt e retorna sua string correspondente*/
string apagarLista(char* codListaRecuperada) {
	
	string line;
	string listaRemovida;
	string stringCodLista = codListaRecuperada; //linha de percorrimento do arquivo
	
	ifstream arqListas;
	ofstream arqTemp;
	arqListas.open(LISTAS_FILE);
	arqTemp.open(TEMP_FILE);

	while (getline(arqListas,line)) { //para cada line do arquivo

		if (stringCodLista.compare(line.substr(0,4)) == 0) { //se a lista atual é a que deve ser apagada
			printw("Lista %s removida do arquivo\n", codListaRecuperada);
			listaRemovida = line;
		}
		else {
			arqTemp << line << endl;
		}
	}
	arqTemp.close();
	arqListas.close();
	remove(LISTAS_FILE);
    rename(TEMP_FILE,LISTAS_FILE);
    return listaRemovida;
}

void salvarLista(lista listaFinal) {
	
	FILE* fpointer;
	fpointer = fopen(LISTAS_FILE, "a");
	fprintf(fpointer, "%s;%s;%03d;%s\n", listaFinal.codLista.c_str(), listaFinal.codUsuario.c_str(), listaFinal.numElementos, listaFinal.elementos.c_str());
	fclose(fpointer);

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
			printw("Insira o código do usuário dono da lista\n");
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
	
	clear();
	//nesse ponto, listaAtual já contem a lista do cliente
	exibirLista(listaAtual); //mostra a lista para o cliente

	opcao = '0';
	printw("\nInsira a opção desejada\n");
	printw("1. Inserir produto \n");
	printw("2. Remover produto \n");
	printw("Qualquer outro valor para encerrar\n");
	opcao = getch();
	char itemRemovido[SIZE_NAME_ITEM], itemAdicionado[SIZE_NAME_ITEM];
	item novoItem;
	clear();

	switch(opcao) {
		case '1':
			printw("Insira o nome do produto que deseja inserir\n");
			getnstr(itemAdicionado,SIZE_NAME_ITEM);
			novoItem = pesquisaItemPorNome(itemAdicionado);

			if (novoItem.preco.compare("0000.00") == 0) { //item não foi encontrado na pesquisa por nome
				printw("Item de nome %s não foi encontrado no cadastro de itens\n", itemAdicionado);
				salvarLista(listaAtual);
				return;
			}

			printw("Lista de compras antes: %s\n", listaAtual.elementos.c_str());
			listaAtual = adicionaNaLista(novoItem, listaAtual); //atualiza lista com novo elemento
			printw("Lista de compras depois: %s\n", listaAtual.elementos.c_str());

			salvarLista(listaAtual);
			break;
		case '2':
			printw("Insira o nome do produto a ser removido da lista\n");
			getnstr(itemRemovido,SIZE_NAME_ITEM);
			removeDaLista(itemRemovido, listaAtual);
			salvarLista(listaAtual);
			break;
		default:
			clear();
			salvarLista(listaAtual);
			return;
	}

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