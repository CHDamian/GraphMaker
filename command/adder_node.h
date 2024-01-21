#ifndef GRAPHMAKER_ADDER_NODE_H
#define GRAPHMAKER_ADDER_NODE_H

#include "../graph.h"
#include "adder_command.h"

class adder_node : public adder_command {
private:
    graph::node_iterator_t created_node; /**< Dodany wierzcholek */
    int id; /**< Id dodawanego wierzcholka */
public:
    adder_node(graph_t graph_ptr, int id) : id(id)
    {
        this->graph_ptr = graph_ptr;
    }
    /** @brief Dodawanie wierzcholka.
    * Dodaje wierzcholek do grafu
    */
    virtual void add();
    /** @brief Cofanie wierzcholka.
    * Cofa wierzcholek stworzony za pomoca funkcji add
    *  bez zadnych konfilktow.
    */
    virtual void undo() noexcept;
};


#endif //GRAPHMAKER_ADDER_NODE_H
