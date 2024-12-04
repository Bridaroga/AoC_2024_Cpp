#include <iostream>
#include <string>
#include <fstream>



int main() {
    std::ifstream memoriaDocument("Memoria.txt");
    std::string lineaMemoria { "" };

    while (!memoriaDocument.eof()) {
        std::getline(memoriaDocument, lineaMemoria);
        
    }
}