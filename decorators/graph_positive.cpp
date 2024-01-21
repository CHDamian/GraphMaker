//
// Created by macie on 1/20/2024.
//

#include "graph_positive.h"

/** @brief Dodaj krawedz.
         * Dodaj krawedz polaczona do wierzcholka o id rownym @param[in] id
         * oraz wadze @param[in] weight.
         * @param[in] id   – id wierzcholka, do ktorego,
         *                   polaczona zostanie nowa krawedz,
         * @param[in] weight – waga krawedzi.
         * @return Iterator do krawedzi, jezeli krawedz powstala
         *  bez zadnych konfilktow.
         */
graph::node_egde_pair graph_positive::add_edge(int src, int dest, int weight)
{
    if(weight <= 0)
    {
        throw graph_not_positive_exception();
    }
    return graph_decorator::add_edge(src, dest, weight);
}