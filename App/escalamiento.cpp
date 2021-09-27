#include "escalamiento.h"
#include <array>
#include <string>
#define ImageName "../Parcial_2/Imagenes/Prueba6.jpg"
#define TamMatriz 12

Escalamiento::Escalamiento(QImage imagen){
    unsigned short int ancho = imagen.width(), alto = imagen.height(), tamano = 0;

    if((ancho*alto) <= (TamMatriz*TamMatriz)){
        tamano = 1;
    }

    if(tamano == 0){
        Submuestreo(ancho, alto, imagen);
    }
    else{
        Sobremuestreo(ancho, alto, imagen);
    }
}

string Escalamiento::Numero_Caracter(int numero){
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

void Escalamiento::Submuestreo(unsigned short _ancho, unsigned short _alto, QImage _imagen){
    int SumaRojo = 0, SumaVerde = 0, SumaAzul = 0, cont1 = -1, cont2 = -1, indice = -1;

    while(cont1 < (TamMatriz - 1)){
        ++cont1;
        cont2 = -1;
        while(cont2 < (TamMatriz - 1)){
            SumaRojo = 0, SumaVerde = 0, SumaAzul = 0;
            ++cont2;
            for(int y = (_alto/(TamMatriz))*cont1; y < (_alto/(TamMatriz))*(cont1+1); y++){
                for(int x = (_ancho/(TamMatriz))*cont2; x < (_ancho/(TamMatriz))*(cont2+1); x++){
                    SumaRojo += _imagen.pixelColor(x, y).red();
                    SumaVerde += _imagen.pixelColor(x, y).green();
                    SumaAzul += _imagen.pixelColor(x, y).blue();
                }
            }
            SumaRojo /= ((_ancho/(TamMatriz))*(_alto/(TamMatriz)));
            SumaVerde /= ((_ancho/(TamMatriz))*(_alto/(TamMatriz)));
            SumaAzul /= ((_ancho/(TamMatriz))*(_alto/(TamMatriz)));

            indice++;
            Rojo.at(indice) = Numero_Caracter(SumaRojo);
            Verde.at(indice) = Numero_Caracter(SumaVerde);
            Azul.at(indice) = Numero_Caracter(SumaAzul);
        }
    }
}

void Escalamiento::Sobremuestreo(unsigned short _ancho, unsigned short _alto, QImage _imagen){
    int cont1 = -1, indice = -1;

    int prueba = TamMatriz/_ancho, prueba2 = TamMatriz/_alto;
    if((TamMatriz%_ancho) != 0){
        prueba += 1;
    }
    if((TamMatriz%_alto) != 0){
        prueba2 += 1;
    }
    cont1 = 0;

    for(int y = 0; y < _alto; y++){

        if(Azul.at((TamMatriz*TamMatriz)-1) != "\0"){
            break;
        }

        for(int con = 0; con < prueba2; con++){
            cont1++;
            for(int x = 0; x < _ancho; x++){
                for( int l = 0; l < prueba; l++){
                    indice++;
                    Rojo.at(indice) = Numero_Caracter(_imagen.pixelColor(x, y).red());
                    Verde.at(indice) = Numero_Caracter(_imagen.pixelColor(x, y).green());
                    Azul.at(indice) = Numero_Caracter(_imagen.pixelColor(x, y).blue());
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
}
