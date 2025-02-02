#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <vector>

struct Funcion {
    int posicion;
    std::string instruccion;
    int valor;
};

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

std::vector<Funcion> posicionFuncion(const std::string& linea, const std::regex& reg, bool numeros) {
    std::vector<Funcion> posicion {};
    auto inicioLinea = std::sregex_iterator(linea.begin(), linea.end(), reg);
    auto finLinea = std::sregex_iterator();

    for (std::sregex_iterator i = inicioLinea; i != finLinea; i++) {
        std::smatch match = *i;
        int pos { static_cast<int>(match.position()) };
        std::string instruccion { match.str() };
        int valor { 0 };
        if (numeros) {
            valor = multiplicacion(instruccion); // O pasar a 0 y calcular después.
        }
        posicion.push_back( {pos, instruccion, valor} );
    }

    return posicion;
}

int main() {
    std::ifstream memoriaDocument("Memoria.txt");
    std::string lineaMemoria { "" };
    std::regex regexMul("(mul\\(\\d+,\\d+\\))");
    std::regex regexDo("(do\\(\\))");
    std::regex regexDont("(don't\\(\\))");
    int sumaMultiplicacion { 0 };
    bool sumar { true };

    while (!memoriaDocument.eof()) {
        std::getline(memoriaDocument, lineaMemoria);

        std::vector<Funcion> lineaFunciones = posicionFuncion(lineaMemoria, regexMul, true);
        std::vector<Funcion> lineaDo = posicionFuncion(lineaMemoria, regexDo, false);
        std::vector<Funcion> lineaDont = posicionFuncion(lineaMemoria, regexDont, false);

        int contadorDo { 0 };
        int contadorDont { 0 };
        for (std::size_t i { 0 }; i < lineaFunciones.size(); i++) {
            bool sumaHecha = false;
            if (contadorDont < lineaDont.size()) {
                if (lineaFunciones[i].posicion < lineaDont[contadorDont].posicion) {
                    if (sumar) {
                        sumaMultiplicacion += lineaFunciones[i].valor;
                        sumaHecha = true;
                    }
                } else {
                    sumar = false;
                    contadorDont++;
                }
            } else {
                if (sumar) {
                    sumaMultiplicacion += lineaFunciones[i].valor;
                    sumaHecha = true;
                }
            }

            if (contadorDo < lineaDo.size()) {
                if (lineaFunciones[i].posicion > lineaDo[contadorDo].posicion) {
                    if (!sumaHecha) {
                        sumaMultiplicacion += lineaFunciones[i].valor;
                    }
                    sumar = true;
                    contadorDo++;
                }
            } else {
                if (!sumaHecha && sumar) {
                    sumaMultiplicacion += lineaFunciones[i].valor;
                }
            }
        }
    }

    std::cout << sumaMultiplicacion << '\n';
}