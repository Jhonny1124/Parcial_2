#ifndef ESCALAMIENTO_H
#define ESCALAMIENTO_H
#include <array>
#include <string>
#include <iostream>
#include <QImage>
#define TamMatriz 12

using namespace std;

class Escalamiento
{
public:

    Escalamiento(QImage imagen);

    string Numero_Caracter(int numero);

    void Submuestreo(unsigned short int _ancho, unsigned short int _alto, QImage _imagen);

    void Sobremuestreo(unsigned short int _ancho, unsigned short int _alto, QImage _imagen);

private:
    array<string,(TamMatriz*TamMatriz)> Rojo;
    array<string,(TamMatriz*TamMatriz)> Verde;
    array<string,(TamMatriz*TamMatriz)> Azul;
};

#endif // ESCALAMIENTO_H
