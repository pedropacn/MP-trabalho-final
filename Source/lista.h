#ifndef LISTA_H
#define LISTA_H

#include<string>
#include "item.h"

struct lista {
    int codLista;
    int codUsuario;
    item* elemento;
};

#endif