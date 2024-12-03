#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::vector<int> stringAVector(const std::string& linea) {
    std::vector<int> valores {};
    std::string numero { "" };

    for (std::size_t i = 0; i < linea.size(); i++) {
        std::size_t inicioNumero { linea.find_first_of("0123456789", i) };
        std::size_t tempIndex = linea.find(' ', inicioNumero);
        if (tempIndex != std::string::npos) {
            i = tempIndex;
            numero = linea.substr(inicioNumero, tempIndex);
            valores.push_back(std::stoi(numero));
            inicioNumero = tempIndex;
        } else {
            i = linea.size();
            numero = linea.substr(inicioNumero);
            valores.push_back(std::stoi(numero));
        }
        
        numero = "";
    }

    return valores;
}

int verificarReporte(std::vector<int> linea) {
    int delta { 0 };
    int dirección { 99 };
    int tempDirección { 99 };
    for (int i = 0; i < linea.size() - 1; i++) {
        delta = linea[i + 1] - linea[i];
        if (dirección != 99) {
            tempDirección = dirección;
        }

        if (delta < 0 && delta > -4) {
            dirección = -1;
        } else if (delta > 0 && delta < 4) {
            dirección = 1;
        } else {
            return 0;
        }

        if (tempDirección != 99 && tempDirección != dirección) {
            return 0;
        }
    }

    return dirección;
}

int main() {
    std::ifstream reportesDocument("Reportes.txt");
    std::string lineaReporte { "" };
    std::vector<int> vectorReporte { 0 };
    int contador { 0 };

    while (!reportesDocument.eof()) {
        std::getline(reportesDocument, lineaReporte);
        vectorReporte = stringAVector(lineaReporte);

        if (verificarReporte(vectorReporte) != 0) {
            contador++;
        }
    }

    std::cout << contador << '\n';
}