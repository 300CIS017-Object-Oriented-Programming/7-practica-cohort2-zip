#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
using std::string;

class Producto {
private:
    string codigo;
    string nombre;
    float precio;
    int stock;
public:
    Producto();
    Producto(string codigo, string nombre, float precio, int stock);
    ~Producto();

    bool descontarStock(int cantidad);
    void agregarStock(int cantidad);
    string obtenerInfo() const;

    // Métodos getters para buscar o mostrar información
    string getCodigo() const;
    string getNombre() const;
    float getPrecio() const;
    int getStock() const;
};

#endif // PRODUCTO_H
