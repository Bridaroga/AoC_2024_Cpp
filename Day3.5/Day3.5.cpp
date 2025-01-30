#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <vector>

int multiplicacion(const std::string& linea) {
    std::vector<int> valores {};
    std::string numero { "" };

    for (std::size_t i = 0; i < linea.size(); i++) {
        std::size_t inicioNumero { linea.find_first_of("0123456789", i) };
        std::size_t tempIndex = linea.find_first_of(",)", inicioNumero);
        
        i = tempIndex;
        numero = linea.substr(inicioNumero, tempIndex);
        valores.push_back(std::stoi(numero));

        if (linea[i] == ')') {
            break;
        }
    }

    return valores[0] * valores[1];
}

int main() {
    std::ifstream memoriaDocument("Memoria.txt");
    std::string lineaMemoria { "" };
    std::regex regexMul("(mul\\(\\d+,\\d+\\))");
    std::regex regexDo("(do\\(\\))");
    std::regex regexDont("(don't\\(\\))");
    int sumaMultiplicacion { 0 };

    while (!memoriaDocument.eof()) {
        std::getline(memoriaDocument, lineaMemoria);

        auto inicioLinea = std::sregex_iterator(lineaMemoria.begin(), lineaMemoria.end(), regexMul);
        auto finLinea = std::sregex_iterator();

        for (std::sregex_iterator i = inicioLinea; i != finLinea; i++) {
            std::smatch match = *i;
            std::string matchStr = match.str();

            sumaMultiplicacion += multiplicacion(matchStr);
        }
    }

    std::cout << sumaMultiplicacion << '\n';
}