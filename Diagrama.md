classDiagram
    class Producto {
        +int ID
        +string nombre
        +float precio
        +int cantidad
        +void actualizarStock(int cantidad)
        +string obtenerInfo()
    }

    class Cliente {
        +int ID
        +string nombre
        +list<Venta> historialCompras
        +void registrarCompra(Venta venta)
        +list<Venta> obtenerHistorial()
    }

    class Venta {
        +int ID
        +Cliente cliente
        +list<Producto> productos
        +float total
        +void calcularTotal()
        +void registrarVenta()
    }

    class Inventario {
        +list<Producto> productos
        +void agregarProducto(Producto producto)
        +void actualizarInventario(int ID, int cantidad)
        +float calcularValorTotal()
    }

    Cliente --> Venta : realiza
    Venta --> Producto : contiene
    Inventario --> Producto : gestiona
