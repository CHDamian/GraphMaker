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
    void dfs_check_edges(std::map<std::pair<int, int>, std::pair<int, bool>> &edge_checker,
                         std::set<int> &visited, graph::node_iterator_t nod, graph::node_iterator_t parent) const;

protected:
    graph_tree(std::shared_ptr<graph> graph_ptr): graph_decorator(graph_ptr){}


public:
    graph_tree() = delete;

    /** @brief Pobierz wierzcholek.
         * Pobiera wierzcholek o podanym @param[in] id
         * @param[in] id - id pobieranego wierzcholka
         * @return Wierzcholek o podanym id
         *  bez zadnych konfilktow.
         */
    virtual bool is_valid() const;

    friend class factory_tree;
};


#endif //GRAPHMAKER_GRAPH_TREE_H
