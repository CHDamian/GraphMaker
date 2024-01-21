//
// Created by macie on 1/20/2024.
//

#include "graph_tree.h"

/** @brief Dodaj krawedz.
         * Dodaj krawedz polaczona do wierzcholka o id rownym @param[in] id
         * oraz wadze @param[in] weight.
         * @param[in] id   – id wierzcholka, do ktorego,
         *                   polaczona zostanie nowa krawedz,
         * @param[in] weight – waga krawedzi.
         * @return Iterator do krawedzi, jezeli krawedz powstala
         *  bez zadnych konfilktow.
         */
void graph_tree::dfs_check_edges(std::map<std::pair<int, int>, std::pair<int, bool>> &edge_checker,
                     std::set<int> &visited, graph::node_iterator_t nod, graph::node_iterator_t parent) const
{
    visited.insert(nod->get_id());
    for(auto edge_it = nod->edge_begin(); *edge_it != *(nod->edge_end()); ++(*edge_it))
    {
        std::pair<int, int> edge = std::make_pair(std::min(nod->get_id(), edge_it->get_node_id()),
                                                  std::max(nod->get_id(), edge_it->get_node_id()));
        if(visited.find(edge_it->get_node_id()) == visited.end()) {
            edge_checker[edge] = {edge_it->get_weight(), false};
            dfs_check_edges(edge_checker, visited, graph_ptr->get_node(edge_it->get_node_id()), nod);
        }
        else
        {
            if(edge.first == edge.second)throw new graph_not_tree_exception();
            if(edge_it->get_node_id() != parent->get_id())throw new graph_not_tree_exception();
            if(edge_checker[edge].first != edge_it->get_weight())throw new graph_not_tree_exception();
        }
    }
}

/** @brief Dodaj krawedz.
         * Dodaj krawedz polaczona do wierzcholka o id rownym @param[in] id
         * oraz wadze @param[in] weight.
         * @param[in] id   – id wierzcholka, do ktorego,
         *                   polaczona zostanie nowa krawedz,
         * @param[in] weight – waga krawedzi.
         * @return Iterator do krawedzi, jezeli krawedz powstala
         *  bez zadnych konfilktow.
         */
bool graph_tree::is_valid() const
{
    std::map<std::pair<int, int>, std::pair<int, bool>> edge_checker;
    std::set<int> visited;

    for(auto it = graph_ptr->node_begin(); it != graph_ptr->node_end(); ++(*it))
    {
        if(visited.find(it->get_id()) == visited.end())dfs_check_edges(edge_checker, visited, it, it);
    }
}