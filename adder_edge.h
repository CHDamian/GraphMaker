#ifndef GRAPHMAKER_ADDER_EDGE_H
#define GRAPHMAKER_ADDER_EDGE_H

#include "graph.h"
#include "adder_command.h"

class adder_edge : public adder_command {
protected:
    node::edge_iterator_t edge1, edge2;
    int id1, id2, weight;
public:
    adder_edge(graph_t graph, int id1, int id2, int weight): adder_command(graph), id1(id1), id2(id2), weight(weight) {}

    virtual void add();
    virtual void undo() noexcept;
};


#endif //GRAPHMAKER_ADDER_EDGE_H
