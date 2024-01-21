//
// Created by macie on 1/19/2024.
//

#include "graph_decorator.h"

graph::node_iterator_t graph_decorator::node_begin()
{
    return graph_ptr->node_begin();
}

graph::node_iterator_t graph_decorator::node_end()
{
    return graph_ptr->node_end();
}

/** @brief Pobierz wierzcholek.
         * Pobiera wierzcholek o podanym @param[in] id
         * @param[in] id - id pobieranego wierzcholka
         * @return Wierzcholek o podanym id
         *  bez zadnych konfilktow.
         */
graph::node_iterator_t graph_decorator::get_node(int id)
{
    return graph_ptr->get_node(id);
}

/** @brief Dodaj wierzcholek.
         * Dodaje wierzcholek o podanym @param[in] id
         * @param[in] id - id dodawanego wierzcholka
         * @return Wierzcholek o podanym id
         *  bez zadnych konfilktow.
         */
graph::node_iterator_t graph_decorator::add_node(int id)
{
    return graph_ptr->add_node(id);
}

/** @brief Dodaj krawedz.
         * Dodaje krawedz o podanym @param[in] id
         * @param[in] src - ...
         * @param[in] dest - ...
         * @param[in] weight - waga krawedzi
         * @return Krawedz
         *  bez zadnych konfilktow.
         */
graph::node_egde_pair graph_decorator::add_edge(int src, int dest, int weight)
{
    return graph_ptr->add_edge(src, dest, weight);
}

/** @brief Usun krawedz.
         * Usuwa podana krawedz
         *  bez zadnych konfilktow.
         */
void graph_decorator::del_edge(node_egde_pair edge_to_del) noexcept
{
    return graph_ptr->del_edge(edge_to_del);
}

/** @brief Usun wierzcholek.
         * Usuwa podany wierzcholek
         * @param[in] node_to_del - usuwany wierzcholek
         *  bez zadnych konfilktow.
         */
bool graph_decorator::is_valid() const
{
    return graph_ptr->is_valid();
}

/** @brief Usun wierzcholek.
         * Usuwa podany wierzcholek
         * @param[in] node_to_del - usuwany wierzcholek
         *  bez zadnych konfilktow.
         */
void graph_decorator::set_prototype(bool prototype) noexcept
{
    return graph_ptr->set_prototype(prototype);
}

/** @brief Usun wierzcholek.
         * Usuwa podany wierzcholek
         * @param[in] node_to_del - usuwany wierzcholek
         *  bez zadnych konfilktow.
         */
void graph_decorator::del_node(node_iterator_t node_to_del) noexcept
{
    return graph_ptr->del_node(node_to_del);
}