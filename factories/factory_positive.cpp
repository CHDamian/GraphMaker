//
// Created by macie on 1/20/2024.
//

#include "factory_positive.h"
#include "../decorators/graph_decorator.h"
#include "../decorators/graph_positive.h"

std::shared_ptr<graph> factory_positive::create(std::shared_ptr<graph> graph_ptr)
{
    for(auto nod_it = graph_ptr->node_begin(); *nod_it != *(graph_ptr->node_end()); ++(*nod_it))
    {
        for(auto edge_it = graph_ptr->node_begin()->edge_begin(); *edge_it != *(graph_ptr->node_end()->edge_end()); ++(*edge_it))
        {
            int weight = edge_it->get_weight();
            if(weight <= 0)
            {
                throw graph_not_positive_exception();
            }
        }
    }
    return std::shared_ptr<graph>(new graph_positive(graph_ptr));
}