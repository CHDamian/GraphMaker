//
// Created by macie on 1/20/2024.
//

#ifndef GRAPHMAKER_GRAPH_TREE_H
#define GRAPHMAKER_GRAPH_TREE_H


#include "graph_decorator.h"

class graph_tree : public graph_decorator
{
protected:
    graph_tree(std::shared_ptr<graph> graph_ptr): graph_decorator(graph_ptr){}

public:
    graph_tree() = delete;

    virtual bool is_valid();

    virtual node_egde_pair add_edge(int src, int dest, int weight);

    friend class factory_tree;
};


#endif //GRAPHMAKER_GRAPH_TREE_H
