//
// Created by macie on 1/20/2024.
//

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

    /** @brief Usun wierzcholek.
         * Usuwa podany wierzcholek
         * @param[in] node_to_del - usuwany wierzcholek
         *  bez zadnych konfilktow.
         */
    virtual bool is_valid();

    friend class factory_connected;

private:
    void dfs_sort(std::map<int, std::vector<int>>& visited, int& num_of_nodes, int& last_node
            , graph::node_iterator_t nod);
};

#endif //GRAPHMAKER_GRAPH_CONNECTED_H
