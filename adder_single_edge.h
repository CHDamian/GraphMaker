#ifndef GRAPHMAKER_ADDER_SINGLE_EDGE_H
#define GRAPHMAKER_ADDER_SINGLE_EDGE_H

#include "graph.h"
#include "adder_edge.h"

class adder_single_edge : public adder_edge {
public:
    adder_single_edge(graph_t graph, int id1, int id2, int weight): adder_edge(graph, id1, id2, weight) {}

    virtual void add();
    virtual void undo() noexcept;
};


#endif //GRAPHMAKER_ADDER_SINGLE_EDGE_H
