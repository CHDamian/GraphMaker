//
// Created by damia on 21.01.2024.
//

#ifndef GRAPHMAKER_BELLMAN_FORD_H
#define GRAPHMAKER_BELLMAN_FORD_H


#include "distance.h"

/**< Wyjatek wyrzucany w przypadku braku poczatkowego wierzcholka w grafie */
class negative_cycle_exception : public std::exception{
public:
    [[nodiscard]] const char *what() const noexcept override {
        return "Graph does not contain starting node!";
    }
};

class bellman_ford : public distance
{
        /**
     * @brief Implementacja algorytmu Bellmana-Forda do obliczania najkrotszych sciezek z jednego wierzcholka.
     * @param[in] graph_ptr - Wskaznik do grafu, na którym ma być wykonany algorytm.
     * @param[out] result - Wynik zawierający odleglości do wszystkich wierzcholków.
     */
    void bellman_ford_cycle(graph_t graph_ptr, distance_result_t result);

    /**
 * @brief Wykrywa ujemny cykl w grafie za pomoca algorytmu Bellmana-Forda.
 * @param[in] graph_ptr - Wskaznik do grafu, na ktorym ma być wykonane sprawdzenie cyklu.
 * @param[in] result - Wynik zawierajacy odleglosci do wszystkich wierzcholków.
 * @throws negative_cycle_exception Jeśli zostanie wykryty ujemny cykl.
 */
    void detect_negative_cycle(graph_t graph_ptr, distance_result_t result);

public:
    virtual distance_result_t execute(graph_t graph_ptr, int start_point);

    static bellman_ford& get_instance()
    {
        static bellman_ford* instance = new bellman_ford();
        return *instance;
    }
};


#endif //GRAPHMAKER_BELLMAN_FORD_H
