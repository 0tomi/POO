cmake_minimum_required(VERSION 3.5)

project(POO LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(POO main.cpp
    templates/pila.h templates/pila.cpp
    CString/TomiString.cpp CString/TomiString.h
    templates/listade.h templates/listade.cpp
    ParcialPRODUCTOS/productos.h ParcialPRODUCTOS/productos.cpp
    ParcialPRODUCTOS/productonacional.h ParcialPRODUCTOS/productonacional.cpp
    ParcialPRODUCTOS/productoextranjero.h ParcialPRODUCTOS/productoextranjero.cpp
    ParcialPRODUCTOS/productooferta.h ParcialPRODUCTOS/productooferta.cpp
)

include(GNUInstallDirs)
install(TARGETS POO
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
