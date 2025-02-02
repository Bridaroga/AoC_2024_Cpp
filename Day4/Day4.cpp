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
    std::vector<std::vector<std::string>> crossword {};

    while (!crosswordDocument.eof()) {
        std::getline(crosswordDocument, lineaCrossword);
        std::vector<std::string> vectorLinea {};
        vectorLinea.push_back(lineaCrossword);
        crossword.push_back(vectorLinea);
    }

    /* for (size_t i = 0; i < crossword.size(); i++) {
        for (size_t j = 0; j < crossword[i].size(); j++) {
            std::cout << crossword[i][j];
        }
        std::cout << '\n';
    } */

   
}