#ifndef TIENDA_H
#define TIENDA_H

#include <string>
#include <vector>
#include "Producto.h"
#include "Cliente.h"
#include "Venta.h"

using std::string;
using std::vector;

class Tienda {
private:
    vector<Producto*> productos;
    vector<Cliente*> clientes;
    vector<Venta*> ventas;
    int contadorVentas;
public:
    Tienda();
    ~Tienda();

    void agregarProducto(string codigo, string nombre, float precio, int stockInicial);
    void agregarCliente(int id, string nombre);
    void registrarVenta(int idCliente);
    void reabastecerProducto(string codigoProducto, int cantidad);
    Producto* buscarProducto(string codigo);
    Cliente* buscarCliente(int idCliente);
    void listarProductos() const;
    void mostrarVentas() const;
    float calcularValorInventario() const;
};

#endif // TIENDA_H
