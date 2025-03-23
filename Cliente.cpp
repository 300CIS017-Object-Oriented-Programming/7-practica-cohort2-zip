#include "Cliente.h"
#include <iostream>

Cliente::Cliente() : id(0), nombre("") {}

Cliente::Cliente(int id, string nombre) : id(id), nombre(nombre) {}

Cliente::~Cliente() {
    // Liberar la memoria de las ventas si es necesario.
    }

void Cliente::agregarCompra(Venta* venta) {
    compras.push_back(venta);
}

void Cliente::mostrarHistorialCompras() const {
    std::cout << "Historial de Compras para " << nombre << " (ID: " << id << "):\n";
    if(compras.empty()){
        std::cout << " No se han registrado compras.\n";
        return;
    }
    for(auto venta : compras){
        venta->mostrarDetalleVenta();
        std::cout << "-------------------------\n";
    }
}

int Cliente::getId() const {
    return id;
}

string Cliente::getNombre() const {
    return nombre;
}
