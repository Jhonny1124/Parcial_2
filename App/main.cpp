#include <iostream>
#include <QImage>
#include <array>
#include <string>

using namespace std;

string Numero_Caracter(int);

#define ImageName "../Parcial_2/Imagenes/Prueba4.jpg"
int main()
{
    QImage imagen(ImageName);

    array<int,144> Rojo;
    array<int,144> Verde;
    array<int,144> Azul;

    unsigned short int ancho = imagen.width(), alto = imagen.height();
    int SumaRojo = 0, SumaVerde = 0, SumaAzul = 0, cont1 = -1, cont2 = -1, indice = -1;
    while(cont1 < 11){
        ++cont1;
        cont2 = -1;
        while(cont2 < 11){
            SumaRojo = 0, SumaVerde = 0, SumaAzul = 0;
            ++cont2;
            for(int i = (alto/12)*cont1; i < (alto/12)*(cont1+1); i++){
               for(int l = (ancho/12)*cont2; l < (ancho/12)*(cont2+1); l++){
                   SumaRojo += imagen.pixelColor(l, i).red();
                   SumaVerde += imagen.pixelColor(l, i).green();
                   SumaAzul += imagen.pixelColor(l, i).blue();
               }
           }
           SumaRojo /= ((ancho/12)*(alto/12));
           SumaVerde /= ((ancho/12)*(alto/12));
           SumaAzul /= ((ancho/12)*(alto/12));

           indice++;
           Rojo.at(indice) = SumaRojo;
           Azul.at(indice) = SumaAzul;
           Verde.at(indice) = SumaVerde;
           //cout << "Panel_Led.setPixelColor(" << ++indice << "," << SumaRojo << "," << SumaVerde << "," << SumaAzul << ")" << ";" <<endl;
        }
    }


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
