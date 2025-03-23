#ifndef VENTA_H
#define VENTA_H

#include <vector>
#include <utility>
#include <string>
#include "Producto.h"
#include "Cliente.h"

using std::vector;
using std::pair;
using std::string;

class Cliente;

class Venta {
private:
    int id;
    Cliente* cliente;
    // Se guarda cada producto vendido junto con la cantidad
    vector<pair<Producto*, int>> productosVendidos;
public:

    Venta(Cliente* cliente, int id);
    ~Venta();

    void agregarProductoVendido(Producto* producto, int cantidad);
    float calcularTotal() const;
    void mostrarDetalleVenta() const;

    int getId() const;
};

#endif
