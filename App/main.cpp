#include <iostream>
#include <QImage>

using namespace std;

#define ImageName "../Parcial_2/Imagenes/Prueba2.jpg"
int main()
{
    QImage imagen(ImageName);

    unsigned short int ancho = imagen.width(), alto = imagen.height();
    unsigned short int Rojo[alto][ancho], Verde[alto][ancho], Azul[alto][ancho];
    int SumaRojo = 0, SumaVerde = 0, SumaAzul = 0;
    for(unsigned short int i = 0; i < alto; i++){
        for(unsigned short int l = 0; l < ancho; l++){
            Rojo[i][l] = imagen.pixelColor(l, i).red();
            Verde[i][l]= imagen.pixelColor(l, i).green();
            Azul[i][l] = imagen.pixelColor(l, i).blue();
        }
    }

     for(int i = 0; i < alto/12; i++){
        for(int l = 0; l < ancho/12; l++){
            SumaRojo += imagen.pixelColor(l, i).red();
            SumaVerde += imagen.pixelColor(l, i).green();
            SumaAzul += imagen.pixelColor(l, i).blue();
        }
    }
    SumaRojo /= ((ancho/12)*(alto/12));
    SumaVerde /= ((ancho/12)*(alto/12));
    SumaAzul /= ((ancho/12)*(alto/12));
     cout << SumaRojo << "," << SumaVerde << "," << SumaAzul <<endl;
    return 0;
}
