/** @file */
/**
 * Módulo de funções de gerenciamento das listas.
 */

/**
 * Bibliotecas utilizadas do C e C++.
 */ 
#include "lista.h"			  ///< struct lista.
#include "common.h"			  ///< importa modulo de funcoes comuns.
#include "gerenciadorItens.h" ///< importa modulo que gerencia itens da lista.
#include <fstream>			  ///< manipular arquivos com a funcao getline().
#include <ncurses.h> 		  ///< interface grafica.
#include <string.h>			  ///< manipulação de strings.
#include <stdlib.h>			  ///< para utilizar a função atof().

/**
 * Define MACROS de tamanhos para o sistema e duas variaveis globais.
 */
#define SIZE_NAME_ITEM 200
#define SIZE_ID_LISTA 4
#define SIZE_ID_USER 2
#define SIZE_CODBARRAS 13
static const char *LISTAS_FILE = "listas.txt";
static const char* TEMP_FILE = "temp.txt";

/**
 * Namespace padrao do C++.
 */
using namespace std;

/**
  * @brief Mostra items da lista na tela, o numero de itens e o dono na lista.
  * @params listaExibida eh o objeto da lista a ser inserida.
  * @return void.
  */
void exibirLista(lista listaExibida) {
	printw("------\n");
	printw("Código da lista: %s\n", listaExibida.codLista.c_str());
	printw("Código do usuário dono da lista: %s\n", listaExibida.codUsuario.c_str());
	printw("Número de elementos: %d\n", listaExibida.numElementos);
	printw("Código dos elementos: %s\n\n", listaExibida.elementos.c_str());
	string barrasElementoAtual;

	for (int i = 0; i < listaExibida.numElementos; i++) { //Para cada elemento da lista...
		barrasElementoAtual = listaExibida.elementos.substr((14*i),13);
		item itemAtual = pesquisaItemPorCodBarras(barrasElementoAtual);
		if (strlen(nomeItem.c_str()) > 0) {
			exibirItem(itemAtual);
		}
		else {
			printw("Item %d incoerente: Código de barras %s não está cadastrado\n", i, barrasElementoAtual.c_str());
		}

	}

	printw("------\n");
	return;
}

/**
  * @brief Função que adicona um item na lista.
  * @params adicionado é objeto item a ser adicionado na lista.
  * @params listaCompras é objeto lista onde o item sera adicionado.
  * @return lista atualizada.
  */
lista adicionaNaLista(item adicionado, lista listaCompras) {

	/**
	 * TODO: SE ITEM EXISTE ANTES DE SAIR ADICIONANDO
	 */

	lista novaLista = listaCompras;
	string listaNova;
	string listaAntiga = listaCompras.elementos;
	if(novaLista.numElementos != 0)
		listaNova = listaAntiga + "," + adicionado.codBarras;
	else
		listaNova = listaAntiga + adicionado.codBarras;
	novaLista.elementos = listaNova;
	novaLista.numElementos = novaLista.numElementos + 1;
	return novaLista;
}

/**
  * @brief Função que remove a primeira ocorrencia de um item na lista.
  * @params itemRemovido é nome do item a ser removido
  * @params listaCompras é o objeto lista aonde se encontra o item 
  * @return lista atualizada.
  */
lista removeDaLista(string itemRemovido, lista listaCompras) {
 	int j=0,Achouitem=0;
 	lista listaNova = listaCompras;
 	string listatemporaria = "",listatemporaria1;

	/**
	 * loop: percorre todas os elementos da lista.
	 */
	for (int i = 0; i < listaCompras.numElementos; i++) { 
		string barrasElementoAtual = listaCompras.elementos.substr((14*i),13);
		item itemAtual = pesquisaItemPorCodBarras(barrasElementoAtual);
		if (itemAtual.nomeItem == itemRemovido){
			j = j+1;
			Achouitem=1;
		}
		if (j != 1)
			listatemporaria = listatemporaria + barrasElementoAtual + ",";
		if(Achouitem == 1)
			j++;
	}	
	listatemporaria1 = listatemporaria.substr(0, listatemporaria.size()-1);
	if (Achouitem == 0){
		clear();
		printw("O produto não existe na lista\n");
		return listaNova;
	}
	listaNova.elementos = listatemporaria1;
	//printw("A lista nova eh %s\n", listatemporaria.c_str()); //debug
	printw("Produto removido da lista");
	listaNova.numElementos = listaNova.numElementos - 1;
	clear();
	printw("Produto removido com sucesso\n");
	return listaNova;

}

/**
  * @brief Função que procura uma lista pelo seu codigo.
  * @params codListaRecuperada é o codigo da lista a ser recuperada.
  * @return lista buscada.
  */
lista recuperarListaPorCod(string codListaRecuperada){
	lista listaEncontrada, temp; 
	listaEncontrada.codLista = "";
	listaEncontrada.codUsuario = "";
	listaEncontrada.numElementos = -1;
	listaEncontrada.elementos = "";
	
	string line;
	ifstream myfile (LISTAS_FILE);

	/**
	 * loop: percorre todas as linhas do banco de dados.
	 */
	while (getline (myfile,line)) {

		temp.codLista = line.substr(0,4);
		temp.codUsuario = line.substr(5, 2);
		/**
		 * substring convertida para inteiro usando atoi.
		 */
		temp.numElementos = atoi(line.substr(8, 3).c_str()); 
		temp.elementos = line.substr(12);

		/** 
		 * conditional: Checa se a lista pesquisada foi encontrada
		 * true => armazena a lista e quebra o loop.
		 * false => nada acontece.
		 */
		if (codListaRecuperada.compare(temp.codLista) == 0) {
			listaEncontrada = temp;
			break; ///< interrompe while
		}
	}
    myfile.close();
	return listaEncontrada;
}

/**
  * @brief Função que apaga a lista no banco de dados e retorna seu nome.
  * @params stringCodLista é o codigo da lista a ser apagada.
  * @return nome da lista apagada.
  */
string apagarLista(string stringCodLista) {
	
	string line, listaRemovida;
	ifstream arqListas;
	ofstream arqTemp;
	arqListas.open(LISTAS_FILE);
	arqTemp.open(TEMP_FILE);

	/**
 	 * loop: percorre todas as linhas do banco de dados.
 	 */
	while (getline(arqListas,line)) {
		/** 
		 * conditional: Checa se a lista atual é a que deve ser apagada
		 * true => armazena a lista e mostra uma mensagem ao usuário.
		 * false => procura na proxima linha
		 */
		if (stringCodLista.compare(line.substr(0,4)) == 0) {
			printw("Lista %s removida do arquivo\n", stringCodLista.c_str());
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

/**
  * @brief Função que atualiza os dados da lista no banco de dados.
  * @params listaFinal é o objeto lista a ser atualizado.
  * @return void. Modifica o arquivo de banco de dados.
  */
void salvarLista(lista listaFinal) {
	
	FILE* fpointer;
	fpointer = fopen(LISTAS_FILE, "a");
	fprintf(fpointer, "%04d;%02d;%03d;%s\n", atoi(listaFinal.codLista.c_str()), atoi(listaFinal.codUsuario.c_str()), listaFinal.numElementos, listaFinal.elementos.c_str());
	fclose(fpointer);

}

/**
  * @brief Função da interface que exibe o menu da lista. Opções mostradas são 
  * as de criar ou editar itens ja cadastrados na lista.
  * @return void. Printa na tela o menu.
  */
void menu_lista() { 

	string codListaString;
	char codListaRecuperada[SIZE_ID_LISTA], numUsuario[SIZE_ID_LISTA];

	clear();
	printw("Insira o código do usuário dono da lista (1~99)\n");
	getnstr(numUsuario,SIZE_ID_LISTA);
	/**
	 * Cria string a partir do const char* para usar compare.
	 */
	string numUsuarioString = string((2-length(numUsuario)), '0').append(numUsuario); 

	clear();
	printw("Usuário inserido: %s\n\n", numUsuarioString.c_str());
	printw("Insira a opção desejada\n");
	printw("1. Criar nova lista \n");
	printw("2. Editar lista existente \n");
	printw("Qualquer outro valor para encerrar\n");
	char opcao = getch();

	lista listaAtual;

	switch(opcao) {
		case '1':
			clear();
			printw("Criando lista\n");
			printw("Insira o código da nova lista (1~9999)\n");
			getnstr(codListaRecuperada,SIZE_ID_LISTA);
			/**
			 * Concatena zeros a esquerda se necessario.
			 */
			codListaString = string((4-length(codListaRecuperada)), '0').append(codListaRecuperada); 
			printw("Lista possui código: %s\n\n", codListaString.c_str());

			if (recuperarListaPorCod(codListaString).numElementos != -1) {
				clear();
				printw("Já existe uma lista cadastrada com código %s\n\n", codListaRecuperada);
				return;
			}

			listaAtual.numElementos = 0;
			listaAtual.codLista = codListaString;
			listaAtual.codUsuario = numUsuarioString;
			break;
		case '2':
			clear();
			printw("Insira o código da lista (1~9999)\n");
			getnstr(codListaRecuperada,SIZE_ID_LISTA);
			/**
			 * Concatena zeros a esquerda se necessario.
			 */
			codListaString = string((4-length(codListaRecuperada)), '0').append(codListaRecuperada);
			/**
			 * Atualiza listaAtual para valor obtido do banco de dados.
			 */
			listaAtual = recuperarListaPorCod(codListaString);
			/** 
			 * conditional: Checa se lista existe
			 * true => limpa a tela, printa mensagem de erro e sai da funcao
			 * false => nada acontece
			 */
			if (listaAtual.numElementos == -1) {
				clear();
				printw("Lista de código %s não encontrada\n\n", codListaString.c_str());
				return;
			}

			clear();

			if (numUsuarioString.compare(listaAtual.codUsuario) != 0) {
				clear();
				printw("Usuário inválido para a lista em questão\n\n");
				return;
			}
			/**
			 * Apaga a lista atual; será adicionada posteriormente após as edições
			 */
			apagarLista(codListaString);
			break;
		default:
			clear();
			return;
	}
	
	//clear();

	/**
	 * Nesse ponto, listaAtual já contem a lista do cliente.
	 */
	while (true) {
		printw("Insira a opção desejada\n");
		printw("1. Inserir produto \n");
		printw("2. Remover produto \n");
		printw("3. Exibir lista \n");
		printw("Qualquer outro valor para encerrar\n");
		opcao = getch();
		char itemRemovido[SIZE_NAME_ITEM], itemAdicionado[SIZE_NAME_ITEM];
		item novoItem;
		clear();

		switch(opcao) {
			case '1':
				printw("Insira o nome do produto que deseja inserir\n");
				getnstr(itemAdicionado,SIZE_NAME_ITEM);
				novoItem = pesquisaItemPorNome (itemAdicionado);

				/** 
				 * conditional: Checa se oitem não foi encontrado na pesquisa 
				 * por nome
				 * true => limpa a tela, printa mensagem de erro, salva estado 
				 * atual da lista e sai da funcao.
				 * false => limpa a tela e printa mensagem de que deu certo.
				 */
				if (novoItem.preco.compare("0000.00") == 0) { 
					clear();
					printw("\nItem de nome %s não foi encontrado no cadastro de itens\n", itemAdicionado);
					printw("Utilize a opção 2 no menu principal para cadastrá-lo.\n\n");
					salvarLista(listaAtual);
					return;
				} else {
					clear();
					printw("Item inserido com sucesso\n");
				}

				//printw("Lista de compras antes: %s\n", listaAtual.elementos.c_str()); //debug

				/**
				 * Atualiza lista com novo elemento.
				 */
				listaAtual = adicionaNaLista(novoItem, listaAtual);

				//printw("Lista de compras depois: %s\n", listaAtual.elementos.c_str()); //debug
				break;
			case '2':
				printw("Insira o nome do produto a ser removido da lista\n");
				getnstr(itemRemovido,SIZE_NAME_ITEM);
				listaAtual = removeDaLista(itemRemovido, listaAtual);
				break;
			case '3':
				/**
				 * Mostra a lista para o cliente.
				 */
				exibirLista(listaAtual); 
				break;
			default:
				clear();
				/**
				 * Salva lista no arquivo apenas ao finalizar todas as iterações. 
				 */
				salvarLista(listaAtual);
				return;
		}
	}

	endwin();
	return; ///< finalizar operação
}

/**
  * @brief Mostra o menu de compras no supermercado. 
  * @return void.
  */
void menu_compra() {
	lista listaAtual;
	listaAtual.codLista = ""; ///< inicializa com valor inválido.
	char codListaRecuperada[SIZE_ID_LISTA], numUsuario[SIZE_ID_LISTA];

	/**
	 * Verifica como os dados são lidos. 
	 */
	string codListaString;

	clear();
	printw("Insira o código da lista cujas compras serão realizadas (1~9999)\n");
	getnstr(codListaRecuperada,SIZE_ID_LISTA);
	/**
	 * Concatena zeros a esquerda se necessario.
	 */
	codListaString = string((4-length(codListaRecuperada)), '0').append(codListaRecuperada);
	/**
	 * Atualiza listaAtual para valor obtido de listas.txt.
	 */
	listaAtual = recuperarListaPorCod(codListaString);

	/** 
	 * conditional: Checa se o codigo de barras inserido eh valido
	 * true => limpa tela, printa mensagem de erro e sai da funcao
	 * false => nada acontece
	 */
	if (listaAtual.numElementos == -1) {
		clear();
		printw("Lista de código %s não encontrada\n\n", codListaString.c_str());
		return;
	}

	clear();
	printw("Insira o código do usuário (1~99)\n");
	getnstr(numUsuario,SIZE_ID_LISTA);
	/**
	 * Criar string a partir do const char* para usar compare.
	 */
	string numUsuarioString = string((2-length(numUsuario)), '0').append(numUsuario); 

	if (listaAtual.codUsuario.compare(numUsuarioString) != 0) {
		clear();
		printw("Usuário %s inválido para a lista em questão\n\n", numUsuarioString.c_str());
		return;
	}
	string barrasElementoAtual;
	float precototal = 0;
	clear();
	/**
	 * loop: percorre todas os elementos da lista.
	 */
	for (int i = 0; i < listaAtual.numElementos; i++) { 
		barrasElementoAtual = listaAtual.elementos.substr((14*i),13);
		item itemAtual = pesquisaItemPorCodBarras(barrasElementoAtual);
		float precoProduto = strtof((itemAtual.preco).c_str(),0);
		precototal = precototal + precoProduto;
	}
	printw("O preco total da lista é: %.02f\n\n", precototal);

	printw("Insira a opção desejada\n");
	printw("1. Manter lista no sistema\n");
	printw("2. Remover lista do sistema\n");
	printw("Qualquer outro valor para encerrar\n");
	char opcao = getch();

	switch(opcao) {
		case '2':
			apagarLista(listaAtual.codLista);
			clear();
			printw("Lista de código %s apagada com sucesso\n\n", codListaString.c_str());
			return;
		default:
			clear();
			break;
	}


	endwin();
	return; ///< finalizar operação
}