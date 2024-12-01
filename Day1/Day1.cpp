#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <tuple>

struct par {
    int x;
    int y;
};

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
        int tempX { 0 };
        int tempY { 0 };
        // auto tempID = numerosID(lineaID);
        // vectorLista1.push_back(std::get<0>(tempID));

        for (std::size_t i = 0; i < lineaID.size(); i++){
            std::size_t inicioNumero { lineaID.find_first_of("0123456789", i) };
            std::size_t finNumero { lineaID.find_first_not_of("0123456789", inicioNumero) };

            if (finNumero != std::string::npos) {
                i = finNumero;
                tempX = std::stoi(lineaID.substr(inicioNumero, finNumero));
            } else {
                tempY = std::stoi(lineaID.substr(inicioNumero));
                break;
            }
        }
        vectorLista.push_back( {tempX, tempY} );
        std::cout << vectorLista[contador].x << "  " << vectorLista[contador].y << '\n';
        contador++;
    }
}