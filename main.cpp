#include <iostream>
#include "Tienda.h"

using std::cout;
using std::cin;
using std::endl;

void mostrarMenu() {
    cout << "\n--- Menú de Tienda ---\n";
    cout << "1. Agregar Producto\n";
    cout << "2. Agregar Cliente\n";
    cout << "3. Registrar Venta\n";
    cout << "4. Reabastecer Producto\n";
    cout << "5. Listar Productos\n";
    cout << "6. Mostrar Ventas\n";
    cout << "7. Calcular Valor Total del Inventario\n";
    cout << "8. Mostrar Historial de Compras de un Cliente\n";
    cout << "9. Salir\n";
    cout << "Seleccione una opción: ";
}

int main() {
    Tienda tienda;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;
        switch(opcion) {
            case 1: {
                std::string codigo, nombre;
                float precio;
                int stock;
                cout << "Ingrese código del producto: ";
                cin >> codigo;
                cout << "Ingrese nombre del producto: ";
                cin.ignore();
                std::getline(cin, nombre);
                cout << "Ingrese precio: ";
                cin >> precio;
                cout << "Ingrese stock inicial: ";
                cin >> stock;
                tienda.agregarProducto(codigo, nombre, precio, stock);
                break;
            }
            case 2: {
                int id;
                std::string nombre;
                cout << "Ingrese ID del cliente: ";
                cin >> id;
                cout << "Ingrese nombre del cliente: ";
                cin.ignore();
                std::getline(cin, nombre);
                tienda.agregarCliente(id, nombre);
                break;
            }
            case 3: {
                int idCliente;
                cout << "Ingrese ID del cliente para registrar venta: ";
                cin >> idCliente;
                tienda.registrarVenta(idCliente);
                break;
            }
            case 4: {
                std::string codigo;
                int cantidad;
                cout << "Ingrese código del producto a reabastecer: ";
                cin >> codigo;
                cout << "Ingrese cantidad a agregar: ";
                cin >> cantidad;
                tienda.reabastecerProducto(codigo, cantidad);
                break;
            }
            case 5:
                tienda.listarProductos();
                break;
            case 6:
                tienda.mostrarVentas();
                break;
            case 7: {
                float valor = tienda.calcularValorInventario();
                cout << "El valor total del inventario es: $" << valor << "\n";
                break;
            }
            case 8: {
                int idCliente;
                cout << "Ingrese ID del cliente: ";
                cin >> idCliente;
                Cliente* cliente = tienda.buscarCliente(idCliente);
                if(cliente) {
                    cliente->mostrarHistorialCompras();
                } else {
                    cout << "Cliente no encontrado.\n";
                }
                break;
            }
            case 9:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción inválida. Intente nuevamente.\n";
        }
    } while(opcion != 9);

    return 0;
}
