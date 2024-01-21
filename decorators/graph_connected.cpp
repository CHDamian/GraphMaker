//
// Created by macie on 1/20/2024.
//


#include <vector>
#include <set>
#include "graph_connected.h"

/** @brief Dodaj krawedz.
         * Dodaj krawedz polaczona do wierzcholka o id rownym @param[in] id
         * oraz wadze @param[in] weight.
         * @param[in] id   – id wierzcholka, do ktorego,
         *                   polaczona zostanie nowa krawedz,
         * @param[in] weight – waga krawedzi.
         * @return Iterator do krawedzi, jezeli krawedz powstala
         *  bez zadnych konfilktow.
         */
void graph_connected::dfs_sort(std::map<int, std::vector<int>>& visited, int& num_of_nodes, int& last_node
              , graph::node_iterator_t nod) const
{
    visited[nod->get_id()];
    for(auto edge_it = nod->edge_begin(); *edge_it != *(nod->edge_end()); ++(*edge_it))
    {
        auto nod_sec = graph_ptr->get_node(edge_it->get_node_id());
        if(visited.find(edge_it->get_node_id()) == visited.end())
            dfs_sort(visited, ++num_of_nodes, last_node, nod_sec);
        visited[nod_sec->get_id()].push_back(nod->get_id());
    }
    last_node = nod->get_id();
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
void dfs_check(std::map<int, std::vector<int>>& visited, std::set<int>& second_visited, int& num_of_nodes, int nod)
{
    second_visited.insert(nod);
    for(int i : visited[nod])
    {
        if(second_visited.find(i) == second_visited.end())
            dfs_check(visited, second_visited, --num_of_nodes, i);
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
bool graph_connected::is_valid() const
{
    std::map<int, std::vector<int>> visited;
    int num_of_nodes = 0;
    int last_node;

    if(*(graph_ptr->node_begin()) == *(graph_ptr->node_end()))
        return graph_decorator::is_valid();

    for(auto it = graph_ptr->node_begin(); *it != *(graph_ptr->node_end()); ++(*it)){
        if(visited.find(it->get_id()) == visited.end())
            dfs_sort(visited, ++num_of_nodes, last_node, it);
    }
    std::set<int> second_visited;

    dfs_check(visited, second_visited, --num_of_nodes, last_node);
    if(num_of_nodes != 0)return false;
    return graph_decorator::is_valid();
}