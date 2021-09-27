#include "escritura.h"
#define TamMatriz 12
#define File "../Parcial_2/App/"
Escritura::Escritura(array<string, TamMatriz*TamMatriz> Rojo, array<string, TamMatriz*TamMatriz> Verde, array<string, TamMatriz*TamMatriz> Azul){
    ofstream out;
    out.open(File+Archivo);

    if (!out.is_open()){
        cout << "Error abriendo el archivo" << endl;
        exit(1);
    }
    out << "short int Colors[3][" << TamMatriz*TamMatriz << "] = {{";

    for(int i = 0; i < (TamMatriz*TamMatriz); i++){
        out << Rojo.at(i) << ",";
    }
    out << "},{";

    for(int i = 0; i < (TamMatriz*TamMatriz); i++){
        out << Verde.at(i) << ",";
    }
    out << "},{";
    for(int i = 0; i < (TamMatriz*TamMatriz); i++){
        out << Azul.at(i) << ",";
    }
    out << "}};";

    out.close();
}
