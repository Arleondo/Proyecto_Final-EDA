#include <iostream>
#include <vector>
#include <random>

#include <usearch/index.hpp>

int main() {

    // Número de dimensiones de cada vector
    const std::size_t dimensions = 4;

    // Crear índice USearch
    unum::usearch::index_t index(
        unum::usearch::index_config_t{}
            .dimensions(dimensions)
            .metric(unum::usearch::metric_kind_t::ip)
    );

    // Reservar espacio
    index.reserve(100);

    // Crear algunos vectores
    std::vector<float> vector1 = {
        1.0f, 0.0f, 0.0f, 0.0f
    };

    std::vector<float> vector2 = {
        0.9f, 0.1f, 0.0f, 0.0f
    };

    std::vector<float> vector3 = {
        0.0f, 0.0f, 1.0f, 0.0f
    };

    std::vector<float> vector4 = {
        0.0f, 0.0f, 0.9f, 0.1f
    };

    // Agregar vectores
    index.add(1, vector1.data());
    index.add(2, vector2.data());
    index.add(3, vector3.data());
    index.add(4, vector4.data());

    // Construir el índice HNSW
    index.build();

    // Vector que queremos consultar
    std::vector<float> query = {
        1.0f, 0.0f, 0.0f, 0.0f
    };

    // Buscar los 2 vecinos más cercanos
    auto results = index.search(query.data(), 2);

    std::cout << "Vecinos encontrados:\n";

    for (std::size_t i = 0; i < results.size(); ++i) {
        std::cout
            << "ID: "
            << results[i].first
            << " | Distancia: "
            << results[i].second
            << '\n';
    }

    return 0;
}
