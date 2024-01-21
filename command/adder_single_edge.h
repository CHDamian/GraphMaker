#ifndef GRAPHMAKER_ADDER_SINGLE_EDGE_H
#define GRAPHMAKER_ADDER_SINGLE_EDGE_H

#include "../graph.h"
#include "adder_edge.h"

class adder_single_edge : public adder_edge {
public:
    adder_single_edge(graph_t graph_ptr, int id1, int id2, int weight): adder_edge(graph_ptr, id1, id2, weight) {}

    /** @brief Dodawanie krawedzi skierowanej.
    * Dodaje skierowana krawedz do grafu
    */
    virtual void add();
    /** @brief Cofanie krawedzi.
    * Cofa krawedz stworzona za pomoca funkcji add
    *  bez zadnych konfilktow.
    */
    virtual void undo() noexcept;
};


#endif //GRAPHMAKER_ADDER_SINGLE_EDGE_H
