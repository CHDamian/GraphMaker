#ifndef GRAPHMAKER_ADDER_EDGE_H
#define GRAPHMAKER_ADDER_EDGE_H

#include "../graph.h"
#include "adder_command.h"

class adder_edge : public adder_command {
protected:
    graph::node_egde_pair edge1, edge2;
    int id1, id2, weight;
public:
    adder_edge(std::shared_ptr<graph> graph_ptr, int id1, int id2, int weight): id1(id1), id2(id2), weight(weight)
    {
        this->graph_ptr = graph_ptr;
        edge1 = {NULL, NULL};
        edge2 = {NULL, NULL};
    }

    virtual void add();
    virtual void undo() noexcept;
};


#endif //GRAPHMAKER_ADDER_EDGE_H
