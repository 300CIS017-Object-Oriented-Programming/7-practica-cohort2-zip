#include "Venta.h"
#include <iostream>
#include <iomanip>

Venta::Venta(Cliente* cliente, int id) : cliente(cliente), id(id) {}

Venta::~Venta() {
}

void Venta::agregarProductoVendido(Producto* producto, int cantidad) {
    productosVendidos.push_back({producto, cantidad});
}

float Venta::calcularTotal() const {
    float total = 0.0;
    for(auto &pv : productosVendidos){
        total += pv.first->getPrecio() * pv.second;
    }
    return total;
}

void Venta::mostrarDetalleVenta() const {
    std::cout << "Venta ID: " << id << "\n";
    std::cout << "Cliente: " << cliente->getNombre() << " (ID: " << cliente->getId() << ")\n";
    std::cout << "Productos:\n";
    for(auto &pv : productosVendidos){
        std::cout << " - " << pv.first->getNombre() << " | Cantidad: " << pv.second
                  << " | Precio Unitario: " << std::fixed << std::setprecision(2) << pv.first->getPrecio() << "\n";
    }
    std::cout << "Total de la venta: $" << std::fixed << std::setprecision(2) << calcularTotal() << "\n";
}

int Venta::getId() const {
    return id;
}
