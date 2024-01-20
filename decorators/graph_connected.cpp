//
// Created by macie on 1/20/2024.
//


#include <vector>
#include "graph_connected.h"


void dfs_sort(std::map<int, std::vector<int>>& visited, int& num_of_nodes, int& last_node
              , graph::node_iterator_t nod)
{

}

bool dfs_check()
{
    return true;
}


bool graph_connected::is_valid()
{
    std::map<int, std::vector<int>> visited;
    int num_of_nodes = 0;
    int last_node;

    if(*(graph_decorator::node_begin()) == *(graph_decorator::node_end()))
        return graph_decorator::is_valid();

    //for(auto it = graph_decorator::node_begin(); )

    return true;
}