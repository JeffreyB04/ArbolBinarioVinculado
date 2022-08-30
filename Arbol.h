//
// Created by jeffr on 29/8/2022.
//

#ifndef ARBOLBINARIOVINCULADO_ARBOL_H
#define ARBOLBINARIOVINCULADO_ARBOL_H
#include"Nodo.h"

class Arbol {
private:
    Nodo *raiz;
    int cant;
public:
    Arbol();
    virtual ~Arbol();

    int getCant() const;
    void setCant(int cant);

    int size();
    bool empty();
    bool isroot(Nodo *nodo);
    bool isExternal(Nodo * nodo);
    void inserta(int valor);
    Nodo* busca(int valor);
    void preOrden(Nodo *t);
protected:
    void insertaRecur(Nodo* nodo, int valor);
    void destruyeArbol(Nodo* nodo);
    Nodo* buscaRecur(int valor, Nodo *leaf);
};


#endif //ARBOLBINARIOVINCULADO_ARBOL_H
