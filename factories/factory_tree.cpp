//
// Created by macie on 1/20/2024.
//

#include <set>
#include "factory_tree.h"
#include "../decorators/graph_decorator.h"
#include "../decorators/graph_tree.h"


/** @brief Stworz graf dodatni.
         * Tworzy graf dodatni
         * @param[in] graph_ptr - shared pointer
         * @return ...
         *  bez zadnych konfilktow.
         */
void factory_tree::dfs_check_edges(std::shared_ptr<graph> graph_ptr, std::map<std::pair<int, int>,
        std::pair<int, bool>>& edge_checker, std::set<int> &visited, graph::node_iterator_t nod, graph::node_iterator_t parent)
{
    visited.insert(nod->get_id());
    for(auto edge_it = nod->edge_begin(); *edge_it != *(nod->edge_end()); ++(*edge_it))
    {
        std::pair<int, int> edge = std::make_pair(std::min(nod->get_id(), edge_it->get_node_id()),
                                                  std::max(nod->get_id(), edge_it->get_node_id()));
        if(visited.find(edge_it->get_node_id()) == visited.end()) {
            edge_checker[edge] = {edge_it->get_weight(), false};
            dfs_check_edges(graph_ptr, edge_checker, visited, graph_ptr->get_node(edge_it->get_node_id()), nod);
        }
        else
        {
            if(edge.first == edge.second)throw new graph_not_tree_exception();
            if(edge_it->get_node_id() != parent->get_id())throw new graph_not_tree_exception();
            if(edge_checker[edge].first != edge_it->get_weight())throw new graph_not_tree_exception();
        }
    }
}



std::shared_ptr<graph> factory_tree::create(std::shared_ptr<graph> graph_ptr)
{
    std::map<std::pair<int, int>, std::pair<int, bool>> edge_checker;
    std::set<int> visited;

    for(auto it = graph_ptr->node_begin(); it != graph_ptr->node_end(); ++(*it))
    {
        if(visited.find(it->get_id()) == visited.end())dfs_check_edges(graph_ptr, edge_checker, visited, it, it);
    }
    return std::shared_ptr<graph>(new graph_tree(graph_ptr));
}