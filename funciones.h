// Estructura del libro
struct libro {
    int id;
    char titulo[100];
    char autor[50];
    int anio;
    char estado[10]; // "Disponible" o "Prestado"
};

// Declaraciones de funciones
int menu();
void limpiarBuffer();
void inicializarBiblioteca(struct libro biblioteca[], int *contador);
void registrarLibro(struct libro biblioteca[], int *contador);
void mostrarLibros(const struct libro biblioteca[], int contador);
void buscarLibro(const struct libro biblioteca[], int contador);
void actualizarEstado(struct libro biblioteca[], int contador);
void eliminarLibro(struct libro biblioteca[], int *contador);
int esNumero(const char *cadena);
int convertirAEntero(const char *cadena);
