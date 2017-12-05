/** @file */
/** 
 * Arquivo com o objeto lista, implementado em uma struct.
 */

#ifndef ITEM_H
#define ITEM_H

#include<string>

struct item {
    std::string codBarras; ///< Ex: 9998885556123.
    std::string preco; ///< Ex: 9998885556123.
    std::string nomeItem; ///< Ex: Detergente Minuano.

    /*
     * O exemplo estará persistido no arquivo itens.txt na estrutura:
	 *	2;9998885556123;Detergente Minuano
     * 
     * Dessa forma, cada linha do arquivo representa um item.
     */
};

#endif