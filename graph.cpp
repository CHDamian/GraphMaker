#include "graph.h"

graph::node_iterator_t graph::add_node(int id)
{
    if(nodes.find(id) != nodes.end())
    {
        throw new multiple_nodes_adding_exception();
    }
    auto new_node = std::shared_ptr<node>(new node(id));
    auto it = nodes.insert({id, new_node}).first;
    return node_iterator_t(new graph::node_iterator(it));
}