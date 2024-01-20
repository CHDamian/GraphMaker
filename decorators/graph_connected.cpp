//
// Created by macie on 1/20/2024.
//


#include <vector>
#include <set>
#include "graph_connected.h"


void graph_connected::dfs_sort(std::map<int, std::vector<int>>& visited, int& num_of_nodes, int& last_node
              , graph::node_iterator_t nod)
{
    visited[nod->get_id()];
    for(auto edge_it = nod->edge_begin(); *edge_it != *(nod->edge_end()); ++(*edge_it))
    {
        auto nod_sec = graph_decorator::get_node(edge_it->get_node_id());
        if(visited.find(edge_it->get_node_id()) == visited.end())
            dfs_sort(visited, ++num_of_nodes, last_node, nod_sec);
        visited[nod_sec->get_id()].push_back(edge_it->get_node_id());
    }
    last_node = nod->get_id();
}

void dfs_check(std::map<int, std::vector<int>>& visited, std::set<int>& second_visited, int& num_of_nodes, int nod)
{
    for(int i : visited[nod])
    {
        if(second_visited.find(i) == second_visited.end())
            dfs_check(visited, second_visited, --num_of_nodes, i);
    }
}


bool graph_connected::is_valid()
{
    std::map<int, std::vector<int>> visited;
    int num_of_nodes = 0;
    int last_node;

    if(*(graph_decorator::node_begin()) == *(graph_decorator::node_end()))
        return graph_decorator::is_valid();

    for(auto it = graph_decorator::node_begin(); *it != *(graph_decorator::node_end()); ++(*it)){
        if(visited.find(it->get_id()) == visited.end())
            dfs_sort(visited, ++num_of_nodes, last_node, it);
    }
    std::set<int> second_visited;

    dfs_check(visited, second_visited, --num_of_nodes, last_node);
    if(num_of_nodes != 0)return false;
    return graph_decorator::is_valid();
}