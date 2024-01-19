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

graph::node_egde_pair graph::add_edge(int src, int dest, int weight) {
    auto src_it = nodes.find(src);
    auto dest_it = nodes.find(dest);
    if(src_it == nodes.end() || dest_it == nodes.end())return {NULL, NULL};
    if(src_it->second->edges.find(dest) != src_it->second->edges.end())return {NULL, NULL};

    graph::node_iterator_t node_it = get_node(src);

    node::edge_iterator_t edge_it = src_it->second->add_edge(dest, weight);

    return {node_it, edge_it};
}

void graph::del_edge(graph::node_egde_pair edge_to_del) noexcept {
    if(!edge_to_del.first)return;
    edge_to_del.first->it->second->del_edge(edge_to_del.second);
}

