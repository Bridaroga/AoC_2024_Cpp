/*  Guardar en un array o vector N x N.
    Buscar y contar las ocurrencias de "XMAS" en todas las direcciones.
    Al buscar, se pueden omitir las direcciones hacia los bordes si está 
        muy cerca de alguno (borde >= 4).*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::ifstream crosswordDocument("Crossword2.txt");
    std::string lineaCrossword { "" };
    std::vector<std::string> crossword {};

    while (!crosswordDocument.eof()) {
        std::getline(crosswordDocument, lineaCrossword);
        crossword.push_back(lineaCrossword);
    }
    
    int conteoXMAS { 0 };
    const std::string xmas { "XMAS" };
    const std::size_t POSICION_X { 0 };
    const std::size_t BORDE { 3 };
    const int WIDTH { 140 };
    for (std::size_t i = 0; i < crossword.size(); i++) {
        int conteoLinea { 0 };
        std::cout << "Línea " << i + 1 << ":";
        for (std::size_t j = 0; j < crossword[i].size(); j++) {
            if (xmas[POSICION_X] == crossword[i][j]) {
                // 1) Arriba.
                if (i >= BORDE) {
                    char charPalabra[] = { crossword[i][j],
                                           crossword[i - 1][j],
                                           crossword[i - 2][j],
                                           crossword[i - 3][j],
                                           '\0' };
                    std::string palabra { charPalabra };
                    if (xmas == palabra) {
                        conteoXMAS++;
                        conteoLinea++;
                        std::cout << " " << (i * WIDTH) + j;
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
                    if (xmas == palabra) {
                        conteoXMAS++;
                        conteoLinea++;
                        std::cout << " " << (i * WIDTH) + j;
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
                    if (xmas == palabra) {
                        conteoXMAS++;
                        conteoLinea++;
                        std::cout << " " << (i * WIDTH) + j;
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
                    if (xmas == palabra) {
                        conteoXMAS++;
                        conteoLinea++;
                        std::cout << " " << (i * WIDTH) + j;
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
                    if (xmas == palabra) {
                        conteoXMAS++;
                        conteoLinea++;
                        std::cout << " " << (i * WIDTH) + j;
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
                    if (xmas == palabra) {
                        conteoXMAS++;
                        conteoLinea++;
                        std::cout << " " << (i * WIDTH) + j;
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
                    if (xmas == palabra) {
                        conteoXMAS++;
                        conteoLinea++;
                        std::cout << " " << (i * WIDTH) + j;
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
                    if (xmas == palabra) {
                        conteoXMAS++;
                        conteoLinea++;
                        std::cout << " " << (i * WIDTH) + j;
                    }
                }
            }
        }
        std::cout << " => " << conteoLinea << '\n';
    }

    std::cout << conteoXMAS << '\n';
}