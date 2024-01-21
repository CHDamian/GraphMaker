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
            if(edge.first == edge.second)throw graph_not_tree_exception();
            if(edge_it->get_node_id() != parent->get_id())throw graph_not_tree_exception();
            if(edge_checker[edge].first != edge_it->get_weight())throw graph_not_tree_exception();
            if(edge_checker[edge].second)throw graph_not_tree_exception();
            edge_checker[edge].second = true;
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

    for(auto it = graph_ptr->node_begin(); *it != *(graph_ptr->node_end()); ++(*it))
    {
        try {
            if (visited.find(it->get_id()) == visited.end())dfs_check_edges(edge_checker, visited, it, it);
        }catch (std::exception e)
        {
            return false;
        }
    }
    for(auto it : edge_checker)
    {
        if(!(it.second.second))return false;
    }
    return graph_decorator::is_valid();
}


int graph_tree::find_parent(int id)
{
    if(united[id] < id)united[id] = find_parent(united[id]);
    return united[id];
}
int graph_tree::union_child(int parent, int child)
{
    if(united[child] <= united[parent])united[parent] = united[child];
    else united[child] = united[parent];
    return united[parent];
}


graph::node_egde_pair graph_tree::add_edge(int src, int dest, int weight)
{
    int src_group = find_parent(src);
    int dest_group = find_parent(dest);
    if(src_group == dest_group)throw graph_not_tree_exception();
    graph::node_egde_pair pr = graph_decorator::add_edge(src, dest, weight);
    union_child(src_group, dest_group);
    return pr;
}

graph::node_iterator_t graph_tree::add_node(int id)
{
    graph::node_iterator_t it = graph_decorator::add_node(id);
    united[id] = id;
    return it;
}

void graph_tree::del_node(graph::node_iterator_t node_to_del) noexcept
{
    graph_decorator::del_node(node_to_del);
    united.erase(node_to_del->get_id());
}

void graph_tree::del_edge(graph::node_egde_pair edge_to_del) noexcept
{
    graph_decorator::del_edge(edge_to_del);
    find_and_union();
}

void graph_tree::find_and_union() noexcept
{
    united.clear();
    for(auto it = graph_ptr->node_begin(); *it != *(graph_ptr->node_end()); ++(*it))
    {
        int child = it->get_id();
        united[child] = child;
        for(auto edge_it = it->edge_begin(); *edge_it != *(it->edge_end()); ++(*edge_it))
        {
            int found = edge_it->get_node_id();
            if(united.find(found) == united.end())continue;
            found = find_parent(found);
            union_child(found, child);
        }
    }
}