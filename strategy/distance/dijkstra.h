//
// Created by damia on 21.01.2024.
//

#ifndef GRAPHMAKER_DIJKSTRA_H
#define GRAPHMAKER_DIJKSTRA_H

#include "distance.h"

/**< Wyjatek wyrzucany w przypadku znalezienia krawedzi ujemnej */
class negative_edge_in_graph_exception : public std::exception{
public:
    [[nodiscard]] const char *what() const noexcept override {
        return "Graph has negative edge!";
    }
};

class dijkstra : public distance
{
    /**
     * @brief Wykrywa ujemny cykl w grafie za pomoca algorytmu Bellmana-Forda.
     * @param[in] graph_ptr - Wskaznik do grafu, na ktorym ma być wykonany algorytm.
     * @param[in] result instancja wynikowa
     * @param[in] start_point punkt startowy algorytmu
     */
    void start(graph_t graph_ptr, distance_result_t result, int start_point);
    /**
     * @brief Wykrywa ujemny cykl w grafie za pomoca algorytmu Bellmana-Forda.
     * @param[in] graph_ptr - Wskaznik do grafu, na ktorym ma być wykonany algorytm.
     * @throws negative_edge_in_graph_exception Jeśli zostanie wykryta ujemna krawedz.
     */
    void detect_negative_edge(graph_t graph_ptr);

public:
    /**
    * @brief Wykonuje algorytm.
    * Wykonuje algorytm dijkstry.
    * @param[in] graph_ptr - Wskaznik do grafu, na ktorym ma być wykonany algorytm.
    * @param[in] start_point punkt startowy algorytmu
    * @return wynik algorytmu.
    */
    virtual distance_result_t execute(graph_t graph_ptr, int start_point);

    /**
    * @brief Zwraca instancje algorytmu.
    * Zwraca singletona algorytmu dijkstry.
    * @return singleton.
    */
    static dijkstra& get_instance()
    {
        static dijkstra* instance = new dijkstra();
        return *instance;
    }
};


#endif //GRAPHMAKER_DIJKSTRA_H
