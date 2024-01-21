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

    std::map<int, int> united;

    int find_parent(int id);
    int union_child(int parent, int child);

    void find_and_union() noexcept;

protected:
    graph_tree(std::shared_ptr<graph> graph_ptr): graph_decorator(graph_ptr)
    {
        find_and_union();
    }


public:
    graph_tree() = delete;

    virtual bool is_valid() const;

    virtual node_iterator_t add_node(int id);

    virtual node_egde_pair add_edge(int src, int dest, int weight);

    virtual void del_edge(node_egde_pair edge_to_del) noexcept;

    virtual void del_node(node_iterator_t node_to_del) noexcept;

    friend class factory_tree;
};


#endif //GRAPHMAKER_GRAPH_TREE_H
