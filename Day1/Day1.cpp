#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <tuple>

struct par {
    int x;
    int y;
};

par numerosID(const std::string& linea) {
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

// Para organizar los vectores en orden ascendente.
void organizarVector() {

}

int main() {
    std::ifstream idDocument ("ID.txt");
    std::string lineaID { "" };
    std::vector<par> vectorLista {};
    int contador { 0 };

    while (!idDocument.eof()) {
        std::getline(idDocument, lineaID);
        
        vectorLista.push_back( numerosID(lineaID) );
        std::cout << vectorLista[contador].x << "  " << vectorLista[contador].y << '\n';
        contador++;
    }
}