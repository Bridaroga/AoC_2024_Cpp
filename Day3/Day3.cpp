#include <iostream>
#include <string>
#include <fstream>
#include <regex>



int main() {
    std::ifstream memoriaDocument("Memoria.txt");
    std::string lineaMemoria { "" };
    std::regex reg("(mul\\(\\d+,\\d+\\))");
    // std::smatch matchString;

    while (!memoriaDocument.eof()) {
        std::getline(memoriaDocument, lineaMemoria);
        
        // Usar for() para buscar todas las coincidencias.
        // std::regex_search(lineaMemoria, matchString, reg);

        auto inicioLinea = std::sregex_iterator(lineaMemoria.begin(), lineaMemoria.end(), reg);
        auto finLinea = std::sregex_iterator();

        std::cout << "Se encontraron " << std::distance(inicioLinea, finLinea) << " coincidencias.\n";

        for (std::sregex_iterator i = inicioLinea; i != finLinea; i++) {
            std::smatch match = *i;
            std::string matchStr = match.str();
            std::cout << matchStr << '\n';
        }

        std::cout << '\n';
    }
}