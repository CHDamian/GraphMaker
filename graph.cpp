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

graph::node_iterator_t graph::node_begin()
{
    return graph::node_iterator_t(new graph::node_iterator(nodes.begin()));
}
graph::node_iterator_t graph::node_end()
{
    return graph::node_iterator_t(new graph::node_iterator(nodes.end()));
}

bool graph::is_valid() const
{
    return true;
}

void graph::set_prototype(bool prototype) noexcept
{
    is_prototype = prototype;
}

void graph::del_node(graph::node_iterator_t node_to_del) noexcept
{
    nodes.erase(node_to_del->it);
}

graph::node_iterator_t graph::get_node(int id)
{
    auto it = nodes.find(id);
    return node_iterator_t(new graph::node_iterator(it));
}

node::edge_iterator_t graph::add_edge(int src, int dest, int weight) {
    // TODO: do implementacji
    return node::edge_iterator_t();
}

void graph::del_edge(node::edge_iterator_t edge_to_del) {
    // TODO: do implementacji
}

