#include "funciones.h"
#include <stdio.h>
#include <string.h>

int menu() {
    int opc;
    printf("\nGestion de Biblioteca\n");
    printf("1. Registrar libro\n");
    printf("2. Buscar libro\n");
    printf("3. Mostrar todos los libros\n");
    printf("4. Actualizar estado de un libro\n");
    printf("5. Eliminar libro\n");
    printf("6. Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opc);
    fflush(stdin);
    return opc;
}

void registrarLibro(struct libro libro[], int *contador) {
    if (*contador >= 20) {
        printf("La biblioteca está llena.\n");
        return;
    }

    struct libro nuevoLibro;
    char idInput[20];

    printf("Ingrese el ID del libro: ");
    fflush(stdin);
    fgets(idInput, sizeof(idInput), stdin);
    idInput[strcspn(idInput, "\n")] = '\0';

    if (!esNumero(idInput)) {
        printf("Error: El ID debe contener solo números.\n");
        return;
    }
    nuevoLibro.id = convertirAEntero(idInput);

    for (int i = 0; i < *contador; i++) {
        if (libro[i].id == nuevoLibro.id) {
            printf("El ID ya existe. Intente con otro.\n");
            return;
        }
    }

    printf("Ingrese el título del libro: ");
    fflush(stdin);
    fgets(nuevoLibro.titulo, sizeof(nuevoLibro.titulo), stdin);
    nuevoLibro.titulo[strcspn(nuevoLibro.titulo, "\n")] = '\0';

    printf("Ingrese el autor del libro: ");
    fflush(stdin);
    fgets(nuevoLibro.autor, sizeof(nuevoLibro.autor), stdin);
    nuevoLibro.autor[strcspn(nuevoLibro.autor, "\n")] = '\0';

    // Validación del año de publicación
    while (1) {
        printf("Ingrese el año de publicación: ");
        if (scanf("%d", &nuevoLibro.anio) == 1 && nuevoLibro.anio > 0|| 1 && nuevoLibro.anio < 2024) {
            if (scanf("%d", &nuevoLibro.anio)  ) {
            break;
        }
        else {
            printf("Error: Año inválido. Intente nuevamente.\n");
            while (getchar() != '\n'); // Limpiar el búfer de entrada
        }
    }

    strcpy(nuevoLibro.estado, "Disponible");
    libro[*contador] = nuevoLibro;
    (*contador)++;
    printf("Libro registrado exitosamente.\n");
}


void mostrarLibros(const struct libro libro[], int contador) {
    if (contador == 0) {
        printf("No hay libros en la biblioteca.\n");
        return;
    }

    printf("%-10s %-30s %-20s %-10s %-15s\n", "ID", "Titulo", "Autor", "Anio", "Estado");
    for (int i = 0; i < contador; i++) {
        printf("%-10d %-30s %-20s %-10d %-15s\n",
               libro[i].id,
               libro[i].titulo,
               libro[i].autor,
               libro[i].anio,
               libro[i].estado);
    }
}

void buscarLibro(const struct libro libro[], int contador) {
    char criterio[100];
    printf("Ingrese el titulo o ID del libro: ");
    fflush(stdin);
    fgets(criterio, sizeof(criterio), stdin);
    criterio[strcspn(criterio, "\n")] = '\0';

    for (int i = 0; i < contador; i++) {
        if (strcmp(libro[i].titulo, criterio) == 0 ||
            (esNumero(criterio) && convertirAEntero(criterio) == libro[i].id)) {
            printf("Libro encontrado:\n");
            printf("ID: %d\nTitulo: %s\nAutor: %s\nAnio: %d\nEstado: %s\n",
                   libro[i].id,
                   libro[i].titulo,
                   libro[i].autor,
                   libro[i].anio,
                   libro[i].estado);
            return;
        }
    }
    printf("Libro no encontrado.\n");
}

void actualizarEstado(struct libro libro[], int contador) {
    int id;
    printf("Ingrese el ID del libro: ");
    scanf("%d", &id);
    fflush(stdin);

    for (int i = 0; i < contador; i++) {
        if (libro[i].id == id) {
            if (strcmp(libro[i].estado, "Disponible") == 0) {
                strcpy(libro[i].estado, "Prestado");
            } else {
                strcpy(libro[i].estado, "Disponible");
            }
            printf("Estado actualizado a: %s\n", libro[i].estado);
            return;
        }
    }
    printf("Libro no encontrado.\n");
}

void eliminarLibro(struct libro libro[], int *contador) {
    int id;
    printf("Ingrese el ID del libro: ");
    scanf("%d", &id);
    fflush(stdin);
    for (int i = 0; i < *contador; i++) {
        if (libro[i].id == id) {
            for (int j = i; j < *contador - 1; j++) {
                libro[j] = libro[j + 1];
            }
            (*contador)--;
            printf("Libro eliminado.\n");
            return;
        }
    }
    printf("Libro no encontrado.\n");
}

int esNumero(const char *cadena) {
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] < '0' || cadena[i] > '9') {
            return 0;
        }
    }
    return 1;
}

int convertirAEntero(const char *cadena) {
    int numero = 0;
    for (int i = 0; cadena[i] != '\0'; i++) {
        numero = numero * 10 + (cadena[i] - '0');
    }
    return numero;
}
