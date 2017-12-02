/*Funcoes do modulo*/
#include "item.h" //struct item
#include "common.h" //funcoes genericas para todos os .cpp
#include <fstream> //manipular arquivos com getline
#include <ncurses.h> //interface grafica
#include <string.h> //manipulação de strings

#define SIZE_NAME_ITEM 200
#define SIZE_CODBARRAS 13
#define SIZE_PRECO 	   7
static const char* ITENS_FILE = "itens.txt";

using namespace std;

bool insereItem(std::string name,std::string preco,std::string codBarras) {
	FILE* fp;
	fp =fopen(ITENS_FILE,"a");
	if (fp ==NULL){
		escreve("Erro na inserção");
		return false;
	}
	const char* nome = name.c_str();
	const char* codigobarra = codBarras.c_str();
	const char* precos = preco.c_str();
	
	if (strlen(codigobarra)!=13){
		escreve("Codigo de barras deve ter 13 caracteres\n");
		return false;
	}
	if (strlen(precos)!=7){
		escreve("Precos deve ter 7 caracteres\n");
		return false;
	}

	fprintf(fp,"%s;%s;%s\n",codigobarra,precos,nome);
	fclose(fp);
	return true;
}

item pesquisaItemPorCodBarras(string codBarras) { //OK
	
	item encontrado, temp;
	encontrado.codBarras = ""; //inicializar struct com valores nulos
	encontrado.nomeItem = "";
	
	string line;
	ifstream myfile (ITENS_FILE);

	while (getline (myfile,line)) { //para cada line

		temp.codBarras = line.substr(0, 13);
		temp.preco = line.substr(14, 7);
		temp.nomeItem = line.substr(22);

		if (codBarras.compare(temp.codBarras) == 0) { //se o pesquisado == encontrado
			encontrado = temp;
			break;
		}
	}

    myfile.close();
	return encontrado;
}

item pesquisaItemPorNome(string nomeItem) {
	item encontrado, temp;
	encontrado.codBarras = ""; //inicializar struct com valores nulos
	encontrado.nomeItem = "";
	encontrado.preco = "0000.00";
	
	string line;
	ifstream myfile ("itens.txt");

	while (getline (myfile,line)) { //para cada line

		temp.codBarras = line.substr(0, 13);
		temp.preco = line.substr(14, 7);
		temp.nomeItem = line.substr(22);

		if (nomeItem.compare(temp.nomeItem) == 0) { //se o pesquisado == encontrado
			encontrado = temp;
			break;
		}
	}

    myfile.close();
	return encontrado;
}

void exibirItem(item mostrar) {
	printw("------\n");
	printw("Nome do item: %s\n", mostrar.nomeItem.c_str());
	printw("Codigo de barras: %s\n", mostrar.codBarras.c_str());
	printw("Preco registrado: %s\n", mostrar.preco.c_str());
	printw("------\n");
}

void menu_cadastrar_item() {

	refresh();
	clear(); //limpar tela
	
	char codBarras[SIZE_CODBARRAS];
	escreve("Insira o código de barras do Item(13 digitos):\n");
	getnstr(codBarras, SIZE_CODBARRAS); //METODO PARA LER STRING DO TECLADO
	clear();
	
	item pesquisado = (pesquisaItemPorCodBarras(codBarras)); //Retornar o Item, caso exista
	if (pesquisado.codBarras != "") { //o Item não foi encontrado
		escreve("Item de código ", codBarras, " já está cadastrado\n\n");
		return;
	}

	/*cadastrar item*/
	escreve ("Item ",codBarras," nao esta cadastrado\n");
	escreve("Insira o nome do item: ");
	char name[SIZE_NAME_ITEM];
	getnstr(name, SIZE_NAME_ITEM);
	escreve("Insira o preco do produto(7 digitos): ");
	char preco[SIZE_PRECO];
	getnstr(preco, SIZE_PRECO);
	clear();

	bool result = insereItem(name,preco,codBarras);
	if (result)
		escreve("Item ",name," inserido com sucesso\n"); //necessario pra mostrar variavel inserida pelo usuario
	else
		escreve("Insercao do item '",name,"' eh invalida\n"); //necessario pra mostrar variavel inserida pelo usuario
	endwin(); //finaliza o ncurses
}