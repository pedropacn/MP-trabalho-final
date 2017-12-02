/*Funcoes do modulo*/
#include "item.h" //struct item
#include "common.h" //funcoes genericas para todos os .cpp
#include <fstream> //manipular arquivos com getline
#include <ncurses.h> //interface grafica

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
	fprintf(fp,"%s;%s;%s",codigobarra,precos,nome);
	fclose(fp);

	//RETORNA TRUE SE ESCREVER; RETORNA FALSE SE DER MERDA

	//REALIZA FOPEN EM ARQUIVO itens.txt
	//FORMATO DO ITEM NO ARQUIVO: <id>;<codBarras>;<nomeItem>\n
	//O ID TERA SEMPRE 4 CARACTERES Ex: 0001, 0002... ate 9999
	//INSERE Item NO ARQUIVO
	//FCLOSE
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
		temp.nomeItem = line.substr(21);

		if (codBarras.compare(temp.codBarras) == 0) { //se o pesquisado == encontrado
			encontrado = temp;
			break;
		}
	}

    myfile.close();
	return encontrado;
}

item pesquisaItemPorNome(string nomeItem) { //TODO
	item encontrado;
	encontrado.codBarras = ""; //inicializar struct com valores nulos
	encontrado.nomeItem = "";
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
	escreve ("Item ",codBarras," nao esta cadastrado\n");
	escreve("Insira o nome do item: ");
	char name[SIZE_NAME_ITEM];
	getnstr(name, SIZE_NAME_ITEM);
	escreve("Insira o preco do produto: ");
	char preco[SIZE_PRECO];
	getnstr(preco, SIZE_PRECO);
	clear();

	bool result = insereItem(name,preco,codBarras);
	if (result)
		escreve("Item ",name," inserido com sucesso\n"); //necessario pra mostrar variavel inserida pelo usuario
	else
		escreve("Insercao do item ",name," invalida\n"); //necessario pra mostrar variavel inserida pelo usuario
	endwin(); //finaliza o ncurses
}