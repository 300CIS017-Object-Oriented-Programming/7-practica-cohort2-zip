#include "Tienda.h"
#include <iostream>

Tienda::Tienda() : contadorVentas(1) {}

Tienda::~Tienda() {
    // Liberar memoria de productos
    for(auto p : productos) {
        delete p;
    }
    // Liberar memoria de clientes
    for(auto c : clientes) {
        delete c;
    }
    // Liberar memoria de ventas
    for(auto v : ventas) {
        delete v;
    }
}

void Tienda::agregarProducto(string codigo, string nombre, float precio, int stockInicial) {
    if(buscarProducto(codigo) != nullptr) {
        std::cout << "El producto con codigo " << codigo << " ya existe.\n";
        return;
    }
    Producto* nuevoProducto = new Producto(codigo, nombre, precio, stockInicial);
    productos.push_back(nuevoProducto);
    std::cout << "Producto agregado exitosamente.\n";
}

void Tienda::agregarCliente(int id, string nombre) {
    if(buscarCliente(id) != nullptr) {
        std::cout << "El cliente con id " << id << " ya existe.\n";
        return;
    }
    Cliente* nuevoCliente = new Cliente(id, nombre);
    clientes.push_back(nuevoCliente);
    std::cout << "Cliente agregado exitosamente.\n";
}

Producto* Tienda::buscarProducto(string codigo) {
    for(auto p : productos){
        if(p->getCodigo() == codigo)
            return p;
    }
    return nullptr;
}

Cliente* Tienda::buscarCliente(int idCliente) {
    for(auto c : clientes){
        if(c->getId() == idCliente)
            return c;
    }
    return nullptr;
}

void Tienda::registrarVenta(int idCliente) {
    Cliente* cliente = buscarCliente(idCliente);
    if(cliente == nullptr) {
        std::cout << "Cliente no encontrado.\n";
        return;
    }
    Venta* venta = new Venta(cliente, contadorVentas++);
    int opcion = 0;
    do {
        std::string codigo;
        int cantidad;
        std::cout << "Ingrese codigo del producto a vender (0 para finalizar): ";
        std::cin >> codigo;
        if(codigo == "0") break;
        Producto* prod = buscarProducto(codigo);
        if(prod == nullptr) {
            std::cout << "Producto no encontrado.\n";
            continue;
        }
        std::cout << "Ingrese cantidad a vender: ";
        std::cin >> cantidad;
        if(prod->descontarStock(cantidad)) {
            venta->agregarProductoVendido(prod, cantidad);
            std::cout << "Producto agregado a la venta.\n";
        } else {
            std::cout << "Stock insuficiente.\n";
        }
    } while(true);

    ventas.push_back(venta);
    cliente->agregarCompra(venta);
    std::cout << "Venta registrada con total: $" << venta->calcularTotal() << "\n";
}

void Tienda::reabastecerProducto(string codigoProducto, int cantidad) {
    Producto* prod = buscarProducto(codigoProducto);
    if(prod == nullptr) {
        std::cout << "Producto no encontrado.\n";
        return;
    }
    prod->agregarStock(cantidad);
    std::cout << "Producto reabastecido exitosamente.\n";
}

void Tienda::listarProductos() const {
    std::cout << "Productos en inventario:\n";
    for(auto p : productos) {
        std::cout << p->obtenerInfo() << "\n";
    }
}

void Tienda::mostrarVentas() const {
    if(ventas.empty()){
        std::cout << "No se han registrado ventas.\n";
        return;
    }
    for(auto v : ventas) {
        v->mostrarDetalleVenta();
        std::cout << "-------------------------\n";
    }
}

float Tienda::calcularValorInventario() const {
    float valorTotal = 0.0;
    for(auto p : productos){
        valorTotal += p->getPrecio() * p->getStock();
    }
    return valorTotal;
}
