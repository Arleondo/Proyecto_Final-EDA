cmake_minimum_required(VERSION 4.1)
project(Proyecto_Final_EDA)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyecto_Final_EDA main.cpp)

target_include_directories(MiProyecto PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/USearch/include)