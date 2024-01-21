//
// Created by macie on 1/20/2024.
//

#include "graph_positive.h"

graph::node_egde_pair graph_positive::add_edge(int src, int dest, int weight)
{
    if(weight <= 0)
    {
        throw graph_not_positive_exception();
    }
    return graph_decorator::add_edge(src, dest, weight);
}