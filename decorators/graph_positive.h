//
// Created by macie on 1/20/2024.
//

#ifndef GRAPHMAKER_GRAPH_POSITIVE_H
#define GRAPHMAKER_GRAPH_POSITIVE_H


#include "graph_decorator.h"

class graph_positive : public graph_decorator
{
protected:
    graph_positive(std::shared_ptr<graph> graph_ptr): graph_decorator(graph_ptr){}

public:
    graph_positive() = delete;

    virtual node_egde_pair add_edge(int src, int dest, int weight);

    friend class factory_positive;
};

#endif //GRAPHMAKER_GRAPH_POSITIVE_H
