/*  Guardar las reglas en un vector<tuple<int,int>>, ¿o en un árbol?.
    Guardar las impresiones en un vector<int>.
    Recorrer las impresiones con todas las reglas y verificar que ande bonito.
*/

#include <iostream>
#include <fstream>
#include <string>


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

    if (pagIzquierda < nodo->pagIzquierda) {
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

    std::cout << "Izquierda: " << nodo->pagIzquierda << "    Derecha: " << nodo->pagDerecha << '\n';
    
    printEnOrden(nodo->derecha);
}

int main() {
    std::ifstream rulesDocument("Rules.txt");
    std::string lineaRules { "" };
    struct nodo* raizArbol { NULL };
    const std::size_t INICIO_REGLA { 0 };
    const std::size_t POSICION_SEPARADOR { 2 };
    const std::size_t TAMANO_REGLAS { 5 };

    while (!rulesDocument.eof()) {
        std::getline(rulesDocument, lineaRules);
        if (lineaRules.size() == TAMANO_REGLAS && lineaRules.find( '|' ) == POSICION_SEPARADOR) {
            int pagIzquierda { std::stoi(lineaRules.substr(INICIO_REGLA, POSICION_SEPARADOR)) };
            std::string prueba {lineaRules.substr(POSICION_SEPARADOR + 1)};
            int pagDerecha { std::stoi(lineaRules.substr(POSICION_SEPARADOR + 1)) };
            
            if (raizArbol == NULL) {
                raizArbol = insertar(raizArbol, pagIzquierda, pagDerecha);
            } else {
                insertar(raizArbol, pagIzquierda, pagDerecha);
            }
        } else {
            // Guardar las impresiones en el vector<int>.

        }

    }

    printEnOrden(raizArbol);
}