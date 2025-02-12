cmake_minimum_required(VERSION 3.5)

project(ParcialAuxx LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ParcialAuxx main.cpp
    gestorparcialaux.cpp gestorparcialaux.h main.cpp parcialAux.pdf prodinternacional.cpp prodinternacional.h prodNacional.cpp prodNacional.h productocompuesto.cpp productocompuesto.h)

include(GNUInstallDirs)
install(TARGETS ParcialAuxx
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
