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
                // 1) Arriba.
                if (i >= BORDE) {
                    char charPalabra[] = { crossword[i][j],
                                           crossword[i - 1][j],
                                           crossword[i - 2][j],
                                           crossword[i - 3][j],
                                           '\0' };
                    std::string palabra { charPalabra };
                    if (mas == palabra) {
                        conteoXMAS++;
                    }
                }
                // 2) Arriba-derecha.
                if (i >= BORDE && j < crossword[i].size() - BORDE) {
                    char charPalabra[] = { crossword[i][j],
                                           crossword[i - 1][j + 1],
                                           crossword[i - 2][j + 2],
                                           crossword[i - 3][j + 3],
                                           '\0' };
                    std::string palabra { charPalabra };
                    if (mas == palabra) {
                        conteoXMAS++;
                    }
                }
                // 3) Derecha.
                if (j < crossword[i].size() - BORDE) {
                    char charPalabra[] = { crossword[i][j],
                                           crossword[i][j + 1],
                                           crossword[i][j + 2],
                                           crossword[i][j + 3],
                                           '\0' };
                    std::string palabra { charPalabra };
                    if (mas == palabra) {
                        conteoXMAS++;
                    }
                }
                // 4) Abajo-derecha.
                if (j < crossword[i].size() - BORDE && i < crossword.size() - BORDE) {
                    char charPalabra[] = { crossword[i][j],
                                           crossword[i + 1][j + 1],
                                           crossword[i + 2][j + 2],
                                           crossword[i + 3][j + 3],
                                           '\0' };
                    std::string palabra { charPalabra };
                    if (mas == palabra) {
                        conteoXMAS++;
                    }
                }
                // 5) Abajo.
                if (i < crossword.size() - BORDE) {
                    char charPalabra[] = { crossword[i][j],
                                           crossword[i + 1][j],
                                           crossword[i + 2][j],
                                           crossword[i + 3][j],
                                           '\0' };
                    std::string palabra { charPalabra };
                    if (mas == palabra) {
                        conteoXMAS++;
                    }
                }
                // 6) Abajo-izquierda.
                if (i < crossword.size() - BORDE && j >= BORDE) {
                    char charPalabra[] = { crossword[i][j],
                                           crossword[i + 1][j - 1],
                                           crossword[i + 2][j - 2],
                                           crossword[i + 3][j - 3],
                                           '\0' };
                    std::string palabra { charPalabra };
                    if (mas == palabra) {
                        conteoXMAS++;
                    }
                }
                // 7) Izquierda.
                if (j >= BORDE) {
                    char charPalabra[] = { crossword[i][j],
                                           crossword[i][j - 1],
                                           crossword[i][j - 2],
                                           crossword[i][j - 3],
                                           '\0' };
                    std::string palabra { charPalabra };
                    if (mas == palabra) {
                        conteoXMAS++;
                    }
                }
                // 8) Arriba-izquierda.
                if (j >= BORDE && i >= BORDE) {
                    char charPalabra[] = { crossword[i][j],
                                           crossword[i - 1][j - 1],
                                           crossword[i - 2][j - 2],
                                           crossword[i - 3][j - 3],
                                           '\0' };
                    std::string palabra { charPalabra };
                    if (mas == palabra) {
                        conteoXMAS++;
                    }
                }
            }
        }
    }

    std::cout << conteoXMAS << '\n';
}