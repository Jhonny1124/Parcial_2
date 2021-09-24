#include <iostream>
#include <QImage>
#include <vector>

using namespace std;

#define ImageName "../Parcial_2/Imagenes/Prueba.jpg"
int main()
{
    QImage imagen(ImageName);


    unsigned short int ancho = imagen.height(), alto = imagen.width();
    unsigned short int Rojo[alto][ancho], Verde[alto][ancho], Azul[alto][ancho];

    for(unsigned short int i = 0; i < alto; i++){
        for(unsigned short int l = 0; l < ancho; l++){
            Rojo[i][l] = imagen.pixelColor(i, l).red();
            Verde[i][l]= imagen.pixelColor(i, l).green();
            Azul[i][l] = imagen.pixelColor(i, l).blue();
        }
    }

    return 0;
}
