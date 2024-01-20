//
// Created by macie on 1/19/2024.
//

#include "graph_decorator.h"

graph::node_iterator_t graph_decorator::node_begin()
{
    return graph_ptr->node_begin();
}

graph::node_iterator_t graph_decorator::node_end()
{
    return graph_ptr->node_end();
}

graph::node_iterator_t graph_decorator::get_node(int id)
{
    return graph_ptr->get_node(id);
}

graph::node_iterator_t graph_decorator::add_node(int id)
{
    return graph_ptr->add_node(id);
}

graph::node_egde_pair graph_decorator::add_edge(int src, int dest, int weight)
{
    return graph_ptr->add_edge(src, dest, weight);
}

void graph_decorator::del_edge(node_egde_pair edge_to_del) noexcept
{
    return del_edge(edge_to_del);
}

bool graph_decorator::is_valid() const
{
    return is_valid();
}

void graph_decorator::set_prototype(bool prototype) noexcept
{
    return set_prototype(prototype);
}

void graph_decorator::del_node(node_iterator_t node_to_del) noexcept
{
    return del_node(node_to_del);
}