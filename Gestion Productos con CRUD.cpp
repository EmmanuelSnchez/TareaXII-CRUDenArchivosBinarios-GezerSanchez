//Gestion de productos//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

//Estructura//
struct Producto {
    int codigo;
    char nombre[50];
    float precio;
    int stock;
    bool activo;
};

string archivo = "productos.dat";

//Funciones y procedimientos//

//Menu principal//
void MenuPrincipal() {
    cout << "\n========== MENU PRINCIPAL ==========\n";
    cout << "1. Gestion de productos\n";
    cout << "2. Proceso de venta\n";
    cout << "3. Salir\n";
    cout << "Seleccione una opcion: ";
}

//Menu CRUD//
void MenuProductos() {
    cout << "\n======= GESTION DE PRODUCTOS =======\n";
    cout << "1. Registrar producto\n";
    cout << "2. Listar productos activos\n";
    cout << "3. Buscar producto por codigo\n";
    cout << "4. Buscar producto por nombre\n";
    cout << "5. Modificar precio\n";
    cout << "6. Actualizar stock\n";
    cout << "7. Eliminar / Desactivar producto\n";
    cout << "8. Regresar\n";
    cout << "Seleccione una opcion: ";
}

//Verificar si existe codigo//
bool ExisteCodigo(int codigoBuscar) {
    Producto p;

    ifstream archivoLectura(archivo, ios::binary);

    while (archivoLectura.read((char*)&p, sizeof(Producto))) {
        if (p.codigo == codigoBuscar && p.activo) {
            archivoLectura.close();
            return true;
        }
    }

    archivoLectura.close();
    return false;
}

//Registrar producto//
void RegistrarProducto() {

    Producto p;

    cout << "\nIngrese codigo: ";
    cin >> p.codigo;

    if (ExisteCodigo(p.codigo)) {
        cout << "El codigo ya existe.\n";
        return;
    }

    cin.ignore();

    cout << "Ingrese nombre: ";
    cin.getline(p.nombre, 50);

    cout << "Ingrese precio: ";
    cin >> p.precio;

    cout << "Ingrese stock: ";
    cin >> p.stock;

    p.activo = true;

    ofstream archivoEscritura(archivo, ios::binary | ios::app);

    archivoEscritura.write((char*)&p, sizeof(Producto));

    archivoEscritura.close();

    cout << "Producto registrado correctamente.\n";
}

//Listar productos//
void ListarProductos() {

    Producto p;

    ifstream archivoLectura(archivo, ios::binary);

    cout << "\n=========== PRODUCTOS ===========\n";

    while (archivoLectura.read((char*)&p, sizeof(Producto))) {

        if (p.activo) {

            cout << "Codigo: " << p.codigo << endl;
            cout << "Nombre: " << p.nombre << endl;
            cout << "Precio: Q" << fixed << setprecision(2) << p.precio << endl;
            cout << "Stock: " << p.stock << endl;
            cout << "----------------------------------\n";
        }
    }

    archivoLectura.close();
}

//Buscar por codigo//
void BuscarPorCodigo() {

    Producto p;
    int codigoBuscar;
    bool encontrado = false;

    cout << "\nIngrese codigo a buscar: ";
    cin >> codigoBuscar;

    ifstream archivoLectura(archivo, ios::binary);

    while (archivoLectura.read((char*)&p, sizeof(Producto))) {

        if (p.codigo == codigoBuscar && p.activo) {

            cout << "\nProducto encontrado:\n";
            cout << "Codigo: " << p.codigo << endl;
            cout << "Nombre: " << p.nombre << endl;
            cout << "Precio: Q" << fixed << setprecision(2) << p.precio << endl;
            cout << "Stock: " << p.stock << endl;

            encontrado = true;
            break;
        }
    }

    archivoLectura.close();

    if (!encontrado) {
        cout << "Producto no encontrado.\n";
    }
}

//Buscar por nombre//
void BuscarPorNombre() {

    Producto p;
    char nombreBuscar[50];
    bool encontrado = false;

    cin.ignore();

    cout << "\nIngrese nombre a buscar: ";
    cin.getline(nombreBuscar, 50);

    ifstream archivoLectura(archivo, ios::binary);

    while (archivoLectura.read((char*)&p, sizeof(Producto))) {

        if (strcmp(p.nombre, nombreBuscar) == 0 && p.activo) {

            cout << "\nProducto encontrado:\n";
            cout << "Codigo: " << p.codigo << endl;
            cout << "Nombre: " << p.nombre << endl;
            cout << "Precio: Q" << fixed << setprecision(2) << p.precio << endl;
            cout << "Stock: " << p.stock << endl;

            encontrado = true;
            break;
        }
    }

    archivoLectura.close();

    if (!encontrado) {
        cout << "Producto no encontrado.\n";
    }
}

//Modificar precio//
void ModificarPrecio() {

    Producto p;
    int codigoBuscar;
    bool encontrado = false;

    cout << "\nIngrese codigo del producto: ";
    cin >> codigoBuscar;

    fstream archivoMod(archivo, ios::binary | ios::in | ios::out);

    while (archivoMod.read((char*)&p, sizeof(Producto))) {

        if (p.codigo == codigoBuscar && p.activo) {

            cout << "Precio actual: Q" << p.precio << endl;

            cout << "Nuevo precio: ";
            cin >> p.precio;

            int posicion = archivoMod.tellg() - sizeof(Producto);

            archivoMod.seekp(posicion);

            archivoMod.write((char*)&p, sizeof(Producto));

            cout << "Precio actualizado correctamente.\n";

            encontrado = true;
            break;
        }
    }

    archivoMod.close();

    if (!encontrado) {
        cout << "Producto no encontrado.\n";
    }
}

//Actualizar stock//
void ActualizarStock() {

    Producto p;
    int codigoBuscar;
    bool encontrado = false;

    cout << "\nIngrese codigo del producto: ";
    cin >> codigoBuscar;

    fstream archivoMod(archivo, ios::binary | ios::in | ios::out);

    while (archivoMod.read((char*)&p, sizeof(Producto))) {

        if (p.codigo == codigoBuscar && p.activo) {

            cout << "Stock actual: " << p.stock << endl;

            cout << "Nuevo stock: ";
            cin >> p.stock;

            int posicion = archivoMod.tellg() - sizeof(Producto);

            archivoMod.seekp(posicion);

            archivoMod.write((char*)&p, sizeof(Producto));

            cout << "Stock actualizado correctamente.\n";

            encontrado = true;
            break;
        }
    }

    archivoMod.close();

    if (!encontrado) {
        cout << "Producto no encontrado.\n";
    }
}

//Desactivar producto//
void EliminarProducto() {

    Producto p;
    int codigoBuscar;
    bool encontrado = false;

    cout << "\nIngrese codigo del producto a eliminar: ";
    cin >> codigoBuscar;

    fstream archivoMod(archivo, ios::binary | ios::in | ios::out);

    while (archivoMod.read((char*)&p, sizeof(Producto))) {

        if (p.codigo == codigoBuscar && p.activo) {

            p.activo = false;

            int posicion = archivoMod.tellg() - sizeof(Producto);

            archivoMod.seekp(posicion);

            archivoMod.write((char*)&p, sizeof(Producto));

            cout << "Producto desactivado correctamente.\n";

            encontrado = true;
            break;
        }
    }

    archivoMod.close();

    if (!encontrado) {
        cout << "Producto no encontrado.\n";
    }
}

//Proceso de venta//
void ProcesoVenta() {

    Producto p;

    int codigoBuscar;
    int cantidad;

    bool encontrado = false;

    cout << "\nIngrese codigo del producto: ";
    cin >> codigoBuscar;

    fstream archivoVenta(archivo, ios::binary | ios::in | ios::out);

    while (archivoVenta.read((char*)&p, sizeof(Producto))) {

        if (p.codigo == codigoBuscar && p.activo) {

            encontrado = true;

            cout << "\nProducto encontrado\n";
            cout << "Nombre: " << p.nombre << endl;
            cout << "Precio: Q" << fixed << setprecision(2) << p.precio << endl;
            cout << "Stock disponible: " << p.stock << endl;

            cout << "\nIngrese cantidad: ";
            cin >> cantidad;

            if (cantidad <= 0) {
                cout << "Cantidad invalida.\n";
                break;
            }

            if (cantidad > p.stock) {
                cout << "No hay suficiente stock.\n";
                break;
            }

            float subtotal = cantidad * p.precio;
            float iva = subtotal * 0.12;
            float total = subtotal + iva;

            cout << "\n=========== FACTURA ===========\n";
            cout << "Producto: " << p.nombre << endl;
            cout << "Cantidad: " << cantidad << endl;
            cout << "Subtotal: Q" << subtotal << endl;
            cout << "IVA (12%): Q" << iva << endl;
            cout << "Total: Q" << total << endl;

            //Descontar stock//
            p.stock = p.stock - cantidad;

            int posicion = archivoVenta.tellg() - sizeof(Producto);

            archivoVenta.seekp(posicion);

            archivoVenta.write((char*)&p, sizeof(Producto));

            cout << "Venta realizada correctamente.\n";

            break;
        }
    }

    archivoVenta.close();

    if (!encontrado) {
        cout << "Producto no encontrado.\n";
    }
}


int main() {

    int opcionPrincipal;
    int opcionCRUD;

    do {

        MenuPrincipal();
        cin >> opcionPrincipal;

        switch (opcionPrincipal) {

            case 1:

                do {

                    MenuProductos();
                    cin >> opcionCRUD;

                    switch (opcionCRUD) {

                        case 1:
                            RegistrarProducto();
                            break;

                        case 2:
                            ListarProductos();
                            break;

                        case 3:
                            BuscarPorCodigo();
                            break;

                        case 4:
                            BuscarPorNombre();
                            break;

                        case 5:
                            ModificarPrecio();
                            break;

                        case 6:
                            ActualizarStock();
                            break;

                        case 7:
                            EliminarProducto();
                            break;

                        case 8:
                            cout << "Regresando al menu principal...\n";
                            break;

                        default:
                            cout << "Opcion invalida.\n";
                    }

                } while (opcionCRUD != 8);

                break;

            case 2:
                ProcesoVenta();
                break;

            case 3:
                cout << "Saliendo del sistema...\n";
                break;

            default:
                cout << "Opcion invalida.\n";
        }

    } while (opcionPrincipal != 3);

    return 0;
}