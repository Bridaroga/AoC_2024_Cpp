#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

struct Par {
    int x;
    int y;
};

Par numerosID(const std::string& linea) {
    int tempX { 0 };
    int tempY { 0 };

    for (std::size_t i = 0; i < linea.size(); i++){
        std::size_t inicioNumero { linea.find_first_of("0123456789", i) };
        std::size_t finNumero { linea.find_first_not_of("0123456789", inicioNumero) };

        if (finNumero != std::string::npos) {
            i = finNumero;
            tempX = std::stoi(linea.substr(inicioNumero, finNumero));
        } else {
            tempY = std::stoi(linea.substr(inicioNumero));
            break;
        }
    }
    return { tempX, tempY };
}

int main() {
    std::ifstream idDocument ("ID.txt");
    std::string lineaID { "" };
    std::vector<int> vectorLista1 {};
    std::vector<int> vectorLista2 {};

    while (!idDocument.eof()) {
        std::getline(idDocument, lineaID);
        Par tempPar { numerosID(lineaID) };

        vectorLista1.push_back(tempPar.x);
        vectorLista2.push_back(tempPar.y);
    }

    std::sort(vectorLista1.begin(), vectorLista1.end());
    std::sort(vectorLista2.begin(), vectorLista2.end());

    

    /* for (int i = 0; i < vectorLista1.size(); i++) {
        std::cout << vectorLista1[i] << "  " << vectorLista2[i] << '\n';
    } */
}