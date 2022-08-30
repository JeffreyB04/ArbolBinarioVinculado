#include <iostream>
#include "Arbol.h"

int main() {
    Arbol *arbin = new Arbol;
    arbin->inserta(10);
    cout<<arbin->size()<<endl;
    return 0;
}
