#include "graph.h"


/** @brief Dodaj wierzcholek.
         * Dodaje wierzcholek o podanym @param[in] id
         * @param[in] id - id dodawanego wierzcholka
         * @return Wierzcholek o podanym id
         *  bez zadnych konfilktow.
         */
graph::node_iterator_t graph::add_node(int id)
{
    if(nodes.find(id) != nodes.end())
    {
        throw multiple_nodes_adding_exception();
    }
    auto new_node = std::shared_ptr<node>(new node(id));
    auto it = nodes.insert({id, new_node}).first;
    return node_iterator_t(new graph::node_iterator(it));
}

/** @brief Dodaj wierzcholek.
         * Dodaje wierzcholek o podanym @param[in] id
         * @param[in] id - id dodawanego wierzcholka
         * @return Wierzcholek o podanym id
         *  bez zadnych konfilktow.
         */
graph::node_iterator_t graph::node_begin()
{
    return graph::node_iterator_t(new graph::node_iterator(nodes.begin()));
}

/** @brief Dodaj wierzcholek.
         * Dodaje wierzcholek o podanym @param[in] id
         * @param[in] id - id dodawanego wierzcholka
         * @return Wierzcholek o podanym id
         *  bez zadnych konfilktow.
         */
graph::node_iterator_t graph::node_end()
{
    return graph::node_iterator_t(new graph::node_iterator(nodes.end()));
}


/** @brief Dodaj wierzcholek.
         * Dodaje wierzcholek o podanym @param[in] id
         * @param[in] id - id dodawanego wierzcholka
         * @return Wierzcholek o podanym id
         *  bez zadnych konfilktow.
         */
bool graph::is_valid() const
{
    return true;
}


/** @brief Dodaj wierzcholek.
         * Dodaje wierzcholek o podanym @param[in] id
         * @param[in] id - id dodawanego wierzcholka
         * @return Wierzcholek o podanym id
         *  bez zadnych konfilktow.
         */
void graph::set_prototype(bool prototype) noexcept
{
    is_prototype = prototype;
}


/** @brief Usun wierzcholek.
         * Usuwa podany wierzcholek
         * @param[in] node_to_del - usuwany wierzcholek
         *  bez zadnych konfilktow.
         */
void graph::del_node(graph::node_iterator_t node_to_del) noexcept
{
    nodes.erase(node_to_del->it);
}


/** @brief Pobierz wierzcholek.
         * Pobiera wierzcholek o podanym @param[in] id
         * @param[in] id - id pobieranego wierzcholka
         * @return Wierzcholek o podanym id
         *  bez zadnych konfilktow.
         */
graph::node_iterator_t graph::get_node(int id)
{
    auto it = nodes.find(id);
    return node_iterator_t(new graph::node_iterator(it));
}

/** @brief Dodaj krawedz.
         * Dodaje krawedz o podanym @param[in] id
         * @param[in] src - ...
         * @param[in] dest - ...
         * @param[in] weight - waga krawedzi
         * @return Krawedz
         *  bez zadnych konfilktow.
         */
graph::node_egde_pair graph::add_edge(int src, int dest, int weight) {
    auto src_it = nodes.find(src);
    auto dest_it = nodes.find(dest);
    if(src_it == nodes.end() || dest_it == nodes.end())return {NULL, NULL};
    if(src_it->second->edges.find(dest) != src_it->second->edges.end())return {NULL, NULL};

    graph::node_iterator_t node_it = get_node(src);

    node::edge_iterator_t edge_it = src_it->second->add_edge(dest, weight);

    return {node_it, edge_it};
}

/** @brief Usun krawedz.
         * Usuwa podana krawedz
         *  bez zadnych konfilktow.
         */
void graph::del_edge(graph::node_egde_pair edge_to_del) noexcept {
    if(!edge_to_del.first)return;
    edge_to_del.first->it->second->del_edge(edge_to_del.second);
}

