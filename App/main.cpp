#include <QImage>
#include "escalamiento.h"

using namespace std;

//Macro donde se indica la ubicacion de la imagen que se desea procesar
#define ImageName "../Parcial_2/Imagenes/Prueba4.jpg"

int main()
{
    QImage imagen(ImageName);
    Escalamiento numero(imagen);

    return 0;
}

