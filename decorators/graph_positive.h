/** @file
 * Deklaracja dekoratora grafu dodatniego
 *
 * @author Damian Chanko, Maciej Chanko, Pawel Krol
 * @date 21.01.2024
 */
#ifndef GRAPHMAKER_GRAPH_POSITIVE_H
#define GRAPHMAKER_GRAPH_POSITIVE_H


#include "graph_decorator.h"

/**< Dekorator grafu dodatniego */
class graph_positive : public graph_decorator
{
protected:
    graph_positive(std::shared_ptr<graph> graph_ptr): graph_decorator(graph_ptr){}

public:
    graph_positive() = delete;

    /** @brief Dodaj krawedz.
     * Dodaje krawedz do grafu.
     * @param[in] src - wierzcholek wychodzacy
     * @param[in] dest - wierzcholek wchodzacy
     * @param[in] weight - waga krawedzi
     * @return Para iteratorow do wierzcholka wychodzacego i krawedzi.
     */
    virtual node_egde_pair add_edge(int src, int dest, int weight);

    friend class factory_positive;
};

#endif //GRAPHMAKER_GRAPH_POSITIVE_H
