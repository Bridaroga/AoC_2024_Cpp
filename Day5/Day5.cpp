/*  Guardar las reglas en un vector<tuple<int,int>>, ¿o en un árbol?.
    Guardar las impresiones en un vector<int>.
    Recorrer las impresiones con todas las reglas y verificar que ande bonito.
*/

#include <iostream>
#include <fstream>

// Nodo con solamente apuntadores a la izquierda y derecha.
struct nodo {
    int pagIzquierda;
    int pagDerecha;
    struct nodo* izquierda;
    struct nodo* derecha;
};

// Crea un nuevo nodo.
nodo* nuevoNodo(int pagIzquierda, int pagDerecha) {
    struct nodo* temporal = new struct nodo;
    temporal->pagIzquierda = pagIzquierda;
    temporal->pagDerecha = pagDerecha;
    temporal->izquierda = NULL;
    temporal->derecha = NULL;

    return temporal;
}

// Inserta un nuevo nodo.
nodo* insertar(struct nodo* nodo, int pagIzquierda, int pagDerecha) {
    if (nodo == NULL) {
        return nuevoNodo(pagIzquierda, pagDerecha);
    }

    if (pagDerecha < nodo->pagDerecha) {
        nodo->izquierda = insertar(nodo->izquierda, pagIzquierda, pagDerecha);
    }
    else {
        nodo->derecha = insertar(nodo->derecha, pagIzquierda, pagDerecha);
    }

    return nodo;
}

void printEnOrden(struct nodo* nodo) {
    if (nodo == NULL) {
        return;
    }

    printEnOrden(nodo->izquierda);

    std::cout << "Izquierda: " << nodo->pagIzquierda << "    Apuesta: " << nodo->pagDerecha << '\n';
    
    printEnOrden(nodo->derecha);
}

int main() {
    
}