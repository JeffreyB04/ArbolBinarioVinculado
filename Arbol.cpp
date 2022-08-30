//
// Created by jeffr on 29/8/2022.
//

#include "Arbol.h"

Arbol::Arbol() {
    raiz = nullptr;
    cant = 0;
}

Arbol::~Arbol() {
    destruyeArbol(raiz);
}

int Arbol::getCant() const {
    return cant;
}

void Arbol::setCant(int cant) {
    Arbol::cant = cant;
}

int Arbol::size() {
    return getCant();
}

bool Arbol::empty() {
    return getCant() == 0;
}

bool Arbol::isroot(Nodo *nodo) {
    return nodo->getParent() == nullptr;
}

bool Arbol::isExternal(Nodo *nodo) {//hoja
    return (nodo->getLeft() == nullptr && nodo->getRight() == nullptr);
}

void Arbol::inserta(int valor) {
    if (raiz == nullptr) {
        raiz = new Nodo;
        raiz->setElemento(valor);
    } else {
        insertaRecur(raiz, valor);
    }
    setCant(getCant() + 1);
}

Nodo *Arbol::busca(int valor) {
    return buscaRecur(valor, raiz);
}

void Arbol::preOrden(Nodo *t) {
    if (t != nullptr) {
        cout << t->getElemento() << " . ";
        preOrden(t->getLeft());
        preOrden(t->getRight());
    }
}

void Arbol::insertaRecur(Nodo *nodo, int valor) {
    if (valor < nodo->getElemento()) {
        if (nodo->getLeft() == nullptr) {
            Nodo *nuevo = new Nodo(valor, nodo, nullptr, nullptr);
            nodo->setLeft(nuevo);
        } else {
            insertaRecur(nodo->getLeft(), valor);
        }
    } else {
        if (valor >= nodo->getElemento()) {
            if (nodo->getRight() == nullptr) {
                Nodo *nuevo = new Nodo(valor, nodo, nullptr, nullptr);
                nodo->setRight(nuevo);
            } else {
                insertaRecur(nodo->getRight(), valor);
            }
        }
    }
}

void Arbol::destruyeArbol(Nodo *nodo) {
    if (nodo != nullptr) {
        destruyeArbol(nodo->getLeft());
        destruyeArbol(nodo->getRight());
        delete nodo;
    }
}

Nodo *Arbol::buscaRecur(int valor, Nodo *leaf) {
    if (leaf != nullptr) {
        if (valor == leaf->getElemento())
            return leaf;
        if (valor < leaf->getElemento())
            return buscaRecur(valor, leaf->getLeft());
        else
            return buscaRecur(valor, leaf->getRight());
    }
    return nullptr;
}

