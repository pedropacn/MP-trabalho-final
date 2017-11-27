#ifndef ITEM_H
#define ITEM_H

#include<string>

struct item {
    int id; //Ex: 2
    std::string codBarras; //Ex: 9998885556123
    std::string nomeItem; //Ex: Detergente Minuano

    /*O exemplo estará persistido no arquivo itens.txt na estrutura:
		2;9998885556123;Detergente Minuano

	Dessa forma, cada linha do arquivo representa um item
    */
};

#endif