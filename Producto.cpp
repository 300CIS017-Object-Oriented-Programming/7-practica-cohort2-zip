#include "Producto.h"
#include <sstream>

Producto::Producto() : codigo(""), nombre(""), precio(0.0), stock(0) {}

Producto::Producto(string codigo, string nombre, float precio, int stock)
        : codigo(codigo), nombre(nombre), precio(precio), stock(stock) {}

Producto::~Producto() {}

bool Producto::descontarStock(int cantidad) {
    if(cantidad <= stock) {
        stock -= cantidad;
        return true;
    }
    return false;
}

void Producto::agregarStock(int cantidad) {
    stock += cantidad;
}

string Producto::obtenerInfo() const {
    std::ostringstream oss;
    oss << "Código: " << codigo
        << " | Nombre: " << nombre
        << " | Precio: " << precio
        << " | Stock: " << stock;
    return oss.str();
}

string Producto::getCodigo() const {
    return codigo;
}

string Producto::getNombre() const {
    return nombre;
}

float Producto::getPrecio() const {
    return precio;
}

int Producto::getStock() const {
    return stock;
}
