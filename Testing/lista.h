#ifndef LISTA_H
#define LISTA_H

#include <string>
#include "item.h"

struct lista {
    std::string codLista; //Ex: 0200
    std::string codUsuario; //Ex: 05
    int numElementos; //Ex: 3
    std::string elementos; //Ex: 9789563530766,0009563530766,9789563530766 - totalizando 3 itens

    /*O exemplo estará persistido no arquivo listas.txt na estrutura:
		0200;05;003;9789563530766,0009563530766,9789563530766;

	Dessa forma, cada linha do arquivo representa uma lista
    */
};

#endif