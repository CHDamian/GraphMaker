//
// Created by damia on 15.01.2024.
//

#include "node.h"



int node::get_id() const
{
    return id;
}

/**
 * @brief Zwraca iterator wskazujący na początek kolekcji krawędzi.
 * @return Współdzielony wskaźnik do iteratora krawędzi.
 *  Bez konfliktów.
 */
std::shared_ptr<node::edge_iterator> node::edge_begin()
{
    return std::shared_ptr<node::edge_iterator>(new node::edge_iterator(edges.begin()));
}

/**
 * @brief Zwraca iterator wskazujący na koniec kolekcji krawędzi.
 * @return Współdzielony wskaźnik do iteratora krawędzi.
 *  Bez konfliktów.
 */
std::shared_ptr<node::edge_iterator> node::edge_end()
{
    return std::shared_ptr<node::edge_iterator>(new node::edge_iterator(edges.end()));
}

/**
 * @brief Dodaje krawędź do wierzchołka.
 * @param[in] id - Identyfikator krawędzi.
 * @param[in] weight - Waga krawędzi.
 * @return Współdzielony wskaźnik do iteratora krawędzi.
 *  Bez konfliktów.
 * @throws multiple_edges_adding_exception Jeśli krawędź o podanym identyfikatorze już istnieje.
 */
std::shared_ptr<node::edge_iterator> node::add_edge(int id, int weight)
{
    if(edges.find(id) != edges.end())
    {
        throw new multiple_edges_adding_exception();
    }
    std::map<int, int>::iterator it = edges.insert({id, weight}).first;
    return std::shared_ptr<node::edge_iterator>(new node::edge_iterator(it));
}

/**
 * @brief Usuwa krawędź.
 * @param[in] edge_to_del - Iterator krawędzi do usunięcia.
 *  Bez konfliktów.
 */
void node::del_edge(node::edge_iterator_t edge_to_del) noexcept
{
    edges.erase(edge_to_del->it);
}
