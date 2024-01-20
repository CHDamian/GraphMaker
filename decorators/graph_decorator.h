#ifndef GRAPHMAKER_GRAPH_DECORATOR_H
#define GRAPHMAKER_GRAPH_DECORATOR_H

#include "../graph.h"
#include "memory"

class graph_not_tree_exception : public std::exception{
public:
    [[nodiscard]] const char *what() const noexcept override {
        return "Graph is not a tree!";
    }
};

class graph_not_positive_exception : public std::exception{
public:
    [[nodiscard]] const char *what() const noexcept override {
        return "Graph is not positive!";
    }
};

class graph_decorator : public graph{
protected:
    std::shared_ptr<graph> graph_ptr;
    graph_decorator(std::shared_ptr<graph> graph_ptr)
    {
        this->graph_ptr = graph_ptr;
    }



public:
    graph_decorator() = delete;

    virtual node_iterator_t node_begin();

    virtual node_iterator_t node_end();

    virtual node_iterator_t get_node(int id);

protected:

    virtual node_iterator_t add_node(int id);

    virtual node_egde_pair add_edge(int src, int dest, int weight);

    virtual void del_edge(node_egde_pair edge_to_del) noexcept;

    virtual bool is_valid() const;

    virtual void set_prototype(bool prototype) noexcept;

    virtual void del_node(node_iterator_t node_to_del) noexcept;

};



#endif //GRAPHMAKER_GRAPH_DECORATOR_H
