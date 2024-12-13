#include <stdio.h>
#include "funciones.h"

int main() {
    struct libro libro[20];
    int contador=0;
    int opc;

    do {
        opc = menu();

        switch (opc) {
            case 1:
                registrarLibro(libro, &contador);
                break;
            case 2:
                buscarLibro(libro, contador);
                break;
            case 3:
                mostrarLibros(libro, contador);
                break;
            case 4:
                actualizarEstado(libro, contador);
                break;
            case 5:
                eliminarLibro(libro, &contador);
                break;
            case 6:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida. Intente nuevamente.\n");
        }
    } while (opc != 6);

    return 0;
}
