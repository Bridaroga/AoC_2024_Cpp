/*  Guardar en un array o vector N x N.
    Buscar y contar las ocurrencias de "XMAS" en todas las direcciones.
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

    /* for (std::size_t i = 0; i < crossword.size(); i++) {
        for (std::size_t j = 0; j < crossword[i].size(); j++) {
            std::cout << crossword[i][j];
        }
        std::cout << '\n';
    } */
    
    int conteoXMAS { 0 };
    const std::string xmas { "XMAS" };
    const std::size_t POSICION_X { 0 };
    const std::size_t BORDE { 3 };
    for (std::size_t i = 0; i < crossword.size(); i++) {
        for (std::size_t j = 0; j < crossword[i].size(); j++) {
            if (xmas[POSICION_X] == crossword[i][j]) {
                // 1) Arriba.
                if (i >= BORDE) {
                    char charPalabra[] = { crossword[i][j],
                                           crossword[i-1][j],
                                           crossword[i-2][j],
                                           crossword[i-3][j],
                                           '\0' };
                    std::string palabra { charPalabra };
                    if (xmas == palabra) {
                        conteoXMAS++;
                    }
                }
            }
        }
        std::cout << '\n';
    }

    std::cout << conteoXMAS << '\n';
}