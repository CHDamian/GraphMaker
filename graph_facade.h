#ifndef GRAPHMAKER_GRAPH_FACADE_H
#define GRAPHMAKER_GRAPH_FACADE_H

#include "strategy/distance/distance.h"
#include "strategy/traversing/traversing.h"
#include "builder.h"

class graph_facade {
private:
    traversing_t traversing_algorithm;
    distance_t distance_algorithm;

public:

     /**
     * @brief Tworzy obiekt builder, który umożliwia konstrukcję grafu.
     * @return Wskaźnik do obiektu builder_t.
     */
    builder_t make_graph();

     /**
     * @brief Ustawia algorytm przechodzenia grafu.
     * @param[in] algorithm - Wskaźnik do obiektu traversing_t reprezentującego algorytm przechodzenia.
     */
    void set_traversing(traversing_t algorithm) noexcept;

     /**
     * @brief Ustawia algorytm obliczania odległości w grafie.
     * @param[in] algorithm - Wskaźnik do obiektu distance_t reprezentującego algorytm odległości.
     */
    void set_distance(distance_t algorithm) noexcept;

     /**
     * @brief Wykonuje algorytm obliczania odległości w grafie.
     * @param[in] graph_ptr - Wskaźnik do grafu, na którym ma być wykonany algorytm.
     * @param[in] start_point - Wierzchołek startowy.
     * @return Wynik zawierający odległości do wszystkich wierzchołków.
     */
    distance_result_t execute_distance(graph_t graph_ptr, int start_point);
    graph_t execute_traversing(graph_t graph_ptr, int start_point);
};


#endif //GRAPHMAKER_GRAPH_FACADE_H
