//
// Created by damia on 15.01.2024.
//

#include "node.h"



int node::get_id() const
{
    return id;
}


std::shared_ptr<node::edge_iterator> node::edge_begin()
{
    return std::shared_ptr<node::edge_iterator>(new node::edge_iterator(edges.begin()));
}


std::shared_ptr<node::edge_iterator> node::edge_end()
{
    return std::shared_ptr<node::edge_iterator>(new node::edge_iterator(edges.end()));
}


std::shared_ptr<node::edge_iterator> node::add_edge(int id, int weight)
{
    if(edges.find(id) != edges.end())
    {
        throw new multiple_edges_adding_exception();
    }
    std::map<int, int>::iterator it = edges.insert({id, weight}).first;
    return std::shared_ptr<node::edge_iterator>(new node::edge_iterator(it));
}


void node::del_edge(node::edge_iterator_t edge_to_del) noexcept
{
    edges.erase(edge_to_del->it);
}
