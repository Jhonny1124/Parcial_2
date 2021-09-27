#ifndef ESCRITURA_H
#define ESCRITURA_H
#include <string>
#include <array>
#include <fstream>
#include <iostream>
#define TamMatriz 12
using namespace std;
class Escritura
{
public:
    Escritura(array<string,(TamMatriz*TamMatriz)> Rojo, array<string,(TamMatriz*TamMatriz)> Verde, array<string,(TamMatriz*TamMatriz)> Azul);

private:
    string Archivo = "Salida.txt";
};

#endif // ESCRITURA_H
