#include <iostream>
#include <QImage>
#include <array>

using namespace std;

void Numero_Caracter(int, char[]);

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

void Numero_Caracter(int numero, char numero_car[3] ){
    int cifras = 1, cont = 0, tem_numero = 0, restador = 10, cont2 = 0;
    if(numero == 0){
        numero_car[0] = '0';
    }
    else {
        for(int i = 0; i < 9; i++){
            if((numero/cifras) != 0){
                cifras *= 10;
                cont++;
            }
        }
        for(int c = cont-1; c >= 0; c--){
            tem_numero = numero%restador;
            numero /= restador;
            cont2 = 0;
            for(int n = 48; n < 58; n++){
                if((tem_numero) == cont2){
                    *(numero_car+c) = char(n);
                }
                cont2++;
            }
        }
    }
}
