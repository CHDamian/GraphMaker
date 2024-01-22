/** @file
 * Deklaracja commanda krawedzi
 *
 * @author Damian Chanko, Maciej Chanko, Pawel Krol
 * @date 21.01.2024
 */

#ifndef GRAPHMAKER_ADDER_EDGE_H
#define GRAPHMAKER_ADDER_EDGE_H

#include "../graph.h"
#include "adder_command.h"

class adder_edge : public adder_command {
protected:
    graph::node_egde_pair edge1, edge2; /**< Dodane krawedzie */
    int id1, id2, weight; /**< Zrodlo, cel i dodawanej krawedzi */
public:
    adder_edge(std::shared_ptr<graph> graph_ptr, int id1, int id2, int weight): id1(id1), id2(id2), weight(weight)
    {
        this->graph_ptr = graph_ptr;
        edge1 = {NULL, NULL};
        edge2 = {NULL, NULL};
    }
    /** @brief Dodawanie krawedzi.
    * Dodaje krawedz do grafu
    */
    virtual void add();
    /** @brief Cofanie krawedzi.
    * Cofa krawedz stworzona za pomoca funkcji add
    *  bez zadnych konfilktow.
    */
    virtual void undo() noexcept;
};


#endif //GRAPHMAKER_ADDER_EDGE_H
