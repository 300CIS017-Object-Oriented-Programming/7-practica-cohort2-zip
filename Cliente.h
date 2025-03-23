#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>
#include "Venta.h"

using std::string;
using std::vector;

class Venta;

class Cliente {
private:
    int id;
    string nombre;
    vector<Venta*> compras;
public:
    Cliente();
    Cliente(int id, string nombre);
    ~Cliente();

    void agregarCompra(Venta* venta);
    void mostrarHistorialCompras() const;

    // Getters
    int getId() const;
    string getNombre() const;
};

#endif // CLIENTE_H
