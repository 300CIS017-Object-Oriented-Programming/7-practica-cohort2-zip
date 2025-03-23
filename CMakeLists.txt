cmake_minimum_required(VERSION 3.19)
project(POOSistemaGestionVentas)

set(CMAKE_CXX_STANDARD 20)

add_executable(POOSistemaGestionVentas main.cpp
        Producto.h
        Producto.cpp
        Cliente.h
        Cliente.cpp
        Venta.h
        Venta.cpp
        Tienda.h
        Tienda.cpp)

target_link_libraries(POOSistemaGestionVentas c++)
