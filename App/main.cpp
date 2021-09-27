#include <iostream>
#include <QImage>
#include <array>
#include <string>
#include "escalamiento.h"

using namespace std;

string Numero_Caracter(int);

#define ImageName "../Parcial_2/Imagenes/Prueba5.jpg"
#define TamMatriz 12
int main()
{
    QImage imagen(ImageName);

    array<string,(TamMatriz*TamMatriz)> Rojo;
    array<string,(TamMatriz*TamMatriz)> Verde;
    array<string,(TamMatriz*TamMatriz)> Azul;

    Escalamiento numero(imagen);

    return 0;
}

string Numero_Caracter(int numero){
    if(numero == 0){
        return "0";
    }

    int digitos = 0, aux = numero;
    char cadena[3];
    string numero_cad;

    while(aux > 0){
        aux /= 10;
        digitos++;
    }
    int pos = digitos-1, digit;
    while(pos >= 0){
        digit = numero % 10;
        numero /= 10;
        cadena[pos] = char(digit + '0');
        pos--;
    }
    numero_cad = cadena;
    return numero_cad;
}
