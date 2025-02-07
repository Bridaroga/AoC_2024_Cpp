/*  Guardar en un array o vector N x N.
    Buscar y contar las ocurrencias de "X-MAS", es decir, 2 "MAS" en diagonal,
        en cualquier dirección.
    Al buscar, se pueden omitir las direcciones hacia los bordes si está 
        muy cerca de alguno (borde >= 4).*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::ifstream crosswordDocument("Crossword.txt");
    std::string lineaCrossword { "" };
    std::vector<std::string> crossword {};

    while (!crosswordDocument.eof()) {
        std::getline(crosswordDocument, lineaCrossword);
        crossword.push_back(lineaCrossword);
    }

    int conteoXMAS { 0 };
    const std::string mas { "MAS" };
    const std::size_t POSICION_A { 1 };
    const std::size_t BORDE { 1 };
    for (std::size_t i = 1; i < crossword.size() - BORDE; i++) {
        for (std::size_t j = 1; j < crossword[i].size() - BORDE; j++) {
            if (mas[POSICION_A] == crossword[i][j]) {
                // 1) Arriba-derecha, Abajo-derecha.
                char charPalabra[] = { crossword[i + 1][j - 1],
                                       crossword[i][j],
                                       crossword[i - 1][j + 1],
                                       '\0' };
                char charPalabra2[] = { crossword[i - 1][j - 1],
                                        crossword[i][j],
                                        crossword[i + 1][j + 1],
                                        '\0' };
                std::string palabra { charPalabra };
                std::string palabra2 { charPalabra2 };
                if (mas == palabra && mas == palabra2) {
                    conteoXMAS++;
                }

                // 2) Arriba-derecha, Arriba-izquierda.
                std::reverse(palabra2.begin(), palabra2.end());
                if (mas == palabra && mas == palabra2) {
                    conteoXMAS++;
                }
            }
        }
    }

    std::cout << conteoXMAS << '\n';
}