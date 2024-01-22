/** @file
 * Deklaracja dekoratora grafu spojnego
 *
 * @author Damian Chanko, Maciej Chanko, Pawel Krol
 * @date 21.01.2024
 */

#ifndef GRAPHMAKER_GRAPH_CONNECTED_H
#define GRAPHMAKER_GRAPH_CONNECTED_H


#include <vector>
#include "graph_decorator.h"

/**< Dekorator grafu spojnego */
class graph_connected : public graph_decorator
{
protected:
    graph_connected(std::shared_ptr<graph> graph_ptr): graph_decorator(graph_ptr){}

public:
    graph_connected() = delete;

    /** @brief Czy graf jest ok.
     * Sprawdza, czy warunki nalozone na graf sa spelnione.
     * @return True jezeli sa spelnione, lub false w przeciwnym wypadku.
     */
    virtual bool is_valid() const;

    friend class factory_connected;

private:
    /** @brief Wykonaj sortowanie topologiczne.
     * Wykonaj pojedynczego dfsa do sortowania topologicznego
     * @param[in] visited - mapa odwiedzonych
     * @param[in] num_of_nodes - liczba odwiedzonych wierzcholkow
     * @param[in] last_node - wierzcholek ostatni co do czasu wyjscia
     * @param[in] nod - przegladany wierzcholek
     */
    void dfs_sort(std::map<int, std::vector<int>>& visited, int& num_of_nodes, int& last_node
            , graph::node_iterator_t nod) const;
};

#endif //GRAPHMAKER_GRAPH_CONNECTED_H
