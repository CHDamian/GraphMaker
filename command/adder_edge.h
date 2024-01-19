#ifndef GRAPHMAKER_ADDER_EDGE_H
#define GRAPHMAKER_ADDER_EDGE_H

#include "../graph.h"
#include "adder_command.h"

class adder_edge : public adder_command {
protected:
    node::edge_iterator_t edge1, edge2;
    graph::node_iterator_t node1, node2;
    int id1, id2, weight;
public:
    adder_edge(std::shared_ptr<graph> graph_ptr, int id1, int id2, int weight): id1(id1), id2(id2), weight(weight)
    {
        this->graph_ptr = graph_ptr;
        node1 = NULL;
        node2 = NULL;
        edge1 = NULL;
        edge2 = NULL;
    }

    virtual void add();
    virtual void undo() noexcept;
};


#endif //GRAPHMAKER_ADDER_EDGE_H
