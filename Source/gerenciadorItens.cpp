/** @file */
/**
 * Módulo de funções de gerenciamento dos itens por lista.
 */

/**
 * Bibliotecas utilizadas do C e C++.
 */
#include "item.h" 		///< importa struct do item.
#include "common.h" 	///< importa modulo de funcoes comuns.
#include <fstream> 		///< manipular arquivos com a funcao getline().
#include <ncurses.h> 	///< interface grafica.
#include <string.h> 	///< manipulação de strings.
#include <stdlib.h> 	///< para utilizar a função atof().

/**
 * Define MACROS de tamanhos para o sistema e uma variavel global.
 */
#define SIZE_NAME_ITEM 200
#define SIZE_CODBARRAS 13
#define SIZE_PRECO 	   7
static const char* ITENS_FILE = "itens.txt";

/**
 * Namespace padrao do C++.
 */
using namespace std;

/**
  * @brief Função que insere um item na lista da compras.
  * @params name eh o nome do item a ser inserido.
  * @params preco eh o preco do item a ser inserido.
  * @params codBarras eh o codigo de barras do item a ser inserido.
  * @return true se o item foi inserido com sucesso, falso caso contrário.
  */
bool insereItem(string name, string preco, string codBarras) {
	FILE* fp;
	fp = fopen(ITENS_FILE, "a"); ///< abre o banco de dados
	if (fp ==NULL){
		escreve("Erro na inserção");
		return false;
	}
	const char* nome = name.c_str();
	const char* codigobarra = codBarras.c_str();
	const char* precos = preco.c_str();
	double precoLido = atof(precos); ///< converte o preco de string para numero

	/** 
	 * conditional: Checa se o codigo de barras inserido eh valido
	 * true => printa mensagem de erro e sai da funcao
	 * false => nada acontece
	 */ 
	if (strlen(codigobarra)!=13){
		escreve("Código de barras deve ter 13 caracteres\n");
		return false;
	}

	fprintf(fp,"%s;%07.2f;%s\n",codigobarra,precoLido,nome);
	fclose(fp);
	return true;
}

/**
  * @brief Função que realiza a pesquisa do item pelo seu codigo de barras e 
  * retorna o item encocntrado.
  * @params codBarras é a entrada a ser analisada.
  * @return item encontrado.
  */
item pesquisaItemPorCodBarras(string codBarras) {
	
	item encontrado, temp;
	encontrado.codBarras = ""; ///< inicializar struct com valores nulos.
	encontrado.nomeItem = "";
	
	string line;
	ifstream myfile (ITENS_FILE);

	/**
 	 * loop: percorre todas as linhas do banco de dados.
 	 */
	while (getline (myfile,line)) {

		temp.codBarras = line.substr(0, 13);
		temp.preco = line.substr(14, 7);
		temp.nomeItem = line.substr(22);

		/** 
		 * conditional: Checa se o codigo de barras do banco de dados é o mesmo
		 * do argumento
		 * true => armazena o item e quebra o loop
		 * false => nada acontece
		 */
		if (codBarras.compare(temp.codBarras) == 0) { 
			encontrado = temp;
			break;
		}
	}

    myfile.close();
	return encontrado;
}

/**
  * @brief Função que pesquisa o item pelo seu nome e retorna o item encontrado.
  * @params nomeItem é o nome do item a ser buscado.
  * @return item encontrado.
  */
item pesquisaItemPorNome(string nomeItem) {
	item encontrado, temp;
	encontrado.codBarras = ""; ///< inicializar struct com valores nulos.
	encontrado.nomeItem = "";
	encontrado.preco = "0000.00";
	
	string line;
	ifstream myfile ("itens.txt");

	while (getline (myfile,line)) { ///< loop para cada linha.

		temp.codBarras = line.substr(0, 13);
		temp.preco = line.substr(14, 7);
		temp.nomeItem = line.substr(22);

		/** 
		 * conditional: Checa se o nome do banco de dados é o mesmo
		 * do argumento
		 * true => armazena o item e quebra o loop
		 * false => nada acontece
		 */
		if (nomeItem.compare(temp.nomeItem) == 0) {
			encontrado = temp;
			break;
		}
	}

    myfile.close();
	return encontrado;
}

/**
  * @brief Função da interface que exibe as prorpriedades de cada item.
  * @params mostrar é o objeto item a ser mostrado.
  * @return void. Printa na tela as propriedades.
  */
void exibirItem(item mostrar) {
	printw("------\n");
	printw("Nome do item: %s\n", mostrar.nomeItem.c_str());
	printw("Código de barras: %s\n", mostrar.codBarras.c_str());
	printw("Preço registrado: %s\n", mostrar.preco.c_str());
	printw("------\n");
}

/**
  * @brief Função da interface que exibe o menu do item.
  * @return void. Printa na tela o menu.
  */
void menu_cadastrar_item() {

	refresh();
	clear(); ///< limpa a tela
	
	char codBarras[SIZE_CODBARRAS];
	escreve("Insira o código de barras do item (13 digitos):\n");
	getnstr(codBarras, SIZE_CODBARRAS); ///< metodo para ler string do teclado.
	clear();

	/**
	 * Retornar o Item, caso exista.
	 */
	item pesquisado = (pesquisaItemPorCodBarras(codBarras));

	/** 
	 * conditional: Checa se o Item não foi encontrado
	 * true => printa mensagem de aviso e sai da funcao.
	 * false => nada acontece.
	 */
	if (pesquisado.codBarras != "") {
		escreve("Item de código ", codBarras, " já está cadastrado\n\n");
		return;
	}

	/**
	 * Cadastrar item.
	 */
	escreve ("Item ",codBarras," não está cadastrado\n");
	char name[SIZE_NAME_ITEM], preco[SIZE_PRECO];
	
	escreve("Insira o nome do item: ");
	getnstr(name, SIZE_NAME_ITEM);
	
	escreve("Insira o preço do produto: ");
	getnstr(preco, SIZE_PRECO);
	clear();

	bool result = insereItem(name,preco,codBarras);
	/** 
	 * conditional: Checa se o item foi inserido corretamente
	 * true => printa mensagem de que deu tudo certo
	 * false => printa mensagem de erro
	 */
	if (result)
		escreve("Item ",name," inserido com sucesso\n");
	else
		escreve("Inserção do item '",name,"' é inválida\n");
	endwin(); ///< finaliza o ncurses
}