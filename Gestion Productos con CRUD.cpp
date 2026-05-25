//Gestion de productos//
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Estudiante {
    int carnet;
    char nombre[30];
    float nota;
    bool activo;
};

const char* ARCHIVO = "estudiantes.dat";

void Menu();
void crearEstudiante();
void listarEstudiantes();
void buscarEstudiante();
void actualizarEstudiante();
void eliminarEstudiante();
bool existeEstudiante(int carnet);


void Menu() {
int Opcion;

do {
    cout << "\nCreacion de Estudiante\n";
    cout << "1. Crear Estudiante";
    cout << "2. Listar estudiante registrados";
    cout << "3. Busqueda de Estudiante";
    cout << "4. Actualizar estudiante";
    cout << "5. Eliminar Estudiante";
    cout << "6. Finalizar Programa";
    cout << "Seleccione una de las opciones "
}
}
