//
// Created by macie on 1/20/2024.
//

#ifndef GRAPHMAKER_GRAPH_TREE_H
#define GRAPHMAKER_GRAPH_TREE_H


#include <set>
#include "graph_decorator.h"

class graph_tree : public graph_decorator
{
private:
    /** @brief Sprawdz stan krawedzi.
     * Zbadaj, czy ulozenie krawedzi moze dac drzewo baddz las
     * @param[in] edge_checker - mapa stanu krawedzi
     * @param[in] visited - set odwiedzonych
     * @param[in] nod - przegladany wierzcholek
     * @param[in] parent - ojciec @param[in] nod w drzewie dfs
     */
    void dfs_check_edges(std::map<std::pair<int, int>, std::pair<int, bool>> &edge_checker,
                         std::set<int> &visited, graph::node_iterator_t nod, graph::node_iterator_t parent) const;

    std::map<int, int> united; /**< Grupy find and union */

    /** @brief Znajdz grupe.
     * Znajdz grupe wierzcholka i zaktualizuj ja
     * @param[in] id - wierzcholek do sprawdzenia
     * @return Id grupy wierzcholka
     */
    int find_parent(int id);

    /** @brief Polacz w grupe.
     * Polacz dwa wierzcholki do jednej grupy
     * @param[in] parent - potencjalny ojciec
     * @param[in] child - potencjalny syn
     * @return Id grupy wierzcholkow
     */
    int union_child(int parent, int child);

    /** @brief Dokonaj find and union.
     * Wykonaj find and union na grafie grupujac po spojnych.
     */
    void find_and_union() noexcept;

protected:
    graph_tree(std::shared_ptr<graph> graph_ptr): graph_decorator(graph_ptr)
    {
        find_and_union();
    }


public:
    graph_tree() = delete;

    /** @brief Czy graf jest ok.
     * Sprawdza, czy warunki nalozone na graf sa spelnione.
     * @return True jezeli sa spelnione, lub false w przeciwnym wypadku.
     */
    virtual bool is_valid() const;

    /** @brief Dodaj wierzcholek.
     * Dodaje wierzcholek o podanym @param[in] id
     * @param[in] id - id dodawanego wierzcholka
     * @return Iterator do wierzcholka o podanym id
     */
    virtual node_iterator_t add_node(int id);

    /** @brief Dodaj krawedz.
     * Dodaje krawedz do grafu.
     * @param[in] src - wierzcholek wychodzacy
     * @param[in] dest - wierzcholek wchodzacy
     * @param[in] weight - waga krawedzi
     * @return Para iteratorow do wierzcholka wychodzacego i krawedzi.
     */
    virtual node_egde_pair add_edge(int src, int dest, int weight);

    /** @brief Usun krawedz.
     * Usun krawedz @param[in] edge_to_del
     * @param[in] edge_to_del – krawedz grafu do usuniecia z wierzcholkiem.
     */
    virtual void del_edge(node_egde_pair edge_to_del) noexcept;

    /** @brief Usun wierzcholek.
     * Usuwa podany wierzcholek
     * @param[in] node_to_del - usuwany wierzcholek
     */
    virtual void del_node(node_iterator_t node_to_del) noexcept;

    friend class factory_tree;
};


#endif //GRAPHMAKER_GRAPH_TREE_H
