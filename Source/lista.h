#ifndef LISTA_H
#define LISTA_H

#include <string>
#include "item.h"

struct lista {
    char* codLista; //Ex: 2
    char* codUsuario; //Ex: 1200
    char* elementos; //Ex: 1,2,3,3,5,3,4 - totalizando 7 itens

    /*O exemplo estará persistido no arquivo listas.txt na estrutura:
		2;1200;7;1,2,3,3,5,3,4

	Dessa forma, cada linha do arquivo representa uma lista
    */
};

#endif