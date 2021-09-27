#include <iostream>
#include <QImage>
#include <array>
#include <string>

using namespace std;

string Numero_Caracter(int);

#define ImageName "../Parcial_2/Imagenes/Prueba6.jpg"
#define TamMatriz 12
int main()
{
    QImage imagen(ImageName);

    array<string,(TamMatriz*TamMatriz)> Rojo;
    array<string,(TamMatriz*TamMatriz)> Verde;
    array<string,(TamMatriz*TamMatriz)> Azul;
    unsigned short int ancho = imagen.width(), alto = imagen.height();
    int SumaRojo = 0, SumaVerde = 0, SumaAzul = 0, cont1 = -1, cont2 = -1, indice = -1;

    /*
    while(cont1 < (TamMatriz - 1)){
        ++cont1;
        cont2 = -1;
        while(cont2 < (TamMatriz - 1)){
            SumaRojo = 0, SumaVerde = 0, SumaAzul = 0;
            ++cont2;
            for(int y = (alto/(TamMatriz))*cont1; y < (alto/(TamMatriz))*(cont1+1); y++){
               for(int x = (ancho/(TamMatriz))*cont2; x < (ancho/(TamMatriz))*(cont2+1); x++){
                   SumaRojo += imagen.pixelColor(x, y).red();
                   SumaVerde += imagen.pixelColor(x, y).green();
                   SumaAzul += imagen.pixelColor(x, y).blue();
               }
           }
           SumaRojo /= ((ancho/(TamMatriz))*(alto/(TamMatriz)));
           SumaVerde /= ((ancho/(TamMatriz))*(alto/(TamMatriz)));
           SumaAzul /= ((ancho/(TamMatriz))*(alto/(TamMatriz)));

           indice++;
           Rojo.at(indice) = Numero_Caracter(SumaRojo);
           Verde.at(indice) = Numero_Caracter(SumaVerde);
           Azul.at(indice) = Numero_Caracter(SumaAzul);
           //cout << "Panel_Led.setPixelColor(" << ++indice << "," << SumaRojo << "," << SumaVerde << "," << SumaAzul << ")" << ";" <<endl;
        }
    }
    */
    int prueba = TamMatriz/ancho, prueba2 = TamMatriz/alto;
    if((TamMatriz%ancho) != 0){
        prueba += 1;
    }
    if((TamMatriz%alto) != 0){
        prueba2 += 1;
    }
    cont1 = 0;

    for(int y = 0; y < alto; y++){

        if(Azul.at((TamMatriz*TamMatriz)-1) != "\0"){
            break;
        }

        for(int con = 0; con < prueba2; con++){
            cont1++;
            for(int x = 0; x < ancho; x++){
                for( int l = 0; l < prueba; l++){
                    indice++;
                    Rojo.at(indice) = Numero_Caracter(imagen.pixelColor(x, y).red());
                    Verde.at(indice) = Numero_Caracter(imagen.pixelColor(x, y).green());
                    Azul.at(indice) = Numero_Caracter(imagen.pixelColor(x, y).blue());
                    if(Azul.at((TamMatriz*cont1)-1) != "\0"){
                        break;
                    }
                }
                if(Azul.at((TamMatriz*cont1)-1) != "\0"){
                    break;
                }
            }

        }
    }

    for(int i = 0; i < 144; i++){
        cout << "Panel_Led.setPixelColor(" << i << "," << Rojo.at(i) << "," << Verde.at(i) << "," << Azul.at(i) << ")" << ";" <<endl;
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
