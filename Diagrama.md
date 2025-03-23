classDiagram
    class Producto {
    -string codigo
    -string nombre
    -float precio
    -int stock
    +Producto()
    +Producto(string codigo, string nombre, float precio, int stock)
    +~Producto()
    +bool descontarStock(int cantidad)
    +void agregarStock(int cantidad)
    +string obtenerInfo()
    }

    class Cliente {
        -int id
        -string nombre
        -vector<Venta*> compras
        +Cliente()
        +Cliente(int id, string nombre)
        +~Cliente()
        +void agregarCompra(Venta* venta)
        +void mostrarHistorialCompras()
    }

    class Venta {
        -int id
        -Cliente* cliente
        -vector<pair<Producto*, int>> productosVendidos
        +Venta(Cliente* cliente)
        +~Venta()
        +void agregarProductoVendido(Producto* producto, int cantidad)
        +float calcularTotal()
        +void mostrarDetalleVenta()
    }

    class Tienda {
        -vector<Producto*> productos
        -vector<Cliente*> clientes
        -vector<Venta*> ventas
        +Tienda()
        +~Tienda()
        +void agregarProducto(string codigo, string nombre, float precio, int stockInicial)
        +void registrarVenta(int idCliente)
        +void reabastecerProducto(string codigoProducto, int cantidad)
        +Producto* buscarProducto(string codigo)
        +Cliente* buscarCliente(int idCliente)
        +void listarProductos()
        +void mostrarVentas()
        +float calcularValorInventario()
    }

    Cliente --> Venta : realiza
    Venta --> Producto : contiene
    Tienda --> Producto : gestiona
    Tienda --> Cliente : gestiona