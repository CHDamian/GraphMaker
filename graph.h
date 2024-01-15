//
// Created by damia on 15.01.2024.
//

#ifndef GRAPHMAKER_GRAPH_H
#define GRAPHMAKER_GRAPH_H

#include <map>
#include "node.h"

using node_map = std::map<int, node_t>;

class multiple_nodes_adding_exception : public std::exception {
public:
    [[nodiscard]] const char *what() const noexcept override {
        return "Node already exists";
    }
};

class graph{
private:
    bool is_prototype;
    node_map nodes;

    graph(): is_prototype(true){}

public:
    class node_iterator
    {
    private:
        node_map::iterator it;
        node_iterator(node_map::iterator it): it(it){}
    public:
        node_iterator() = delete;
        void operator++()
        {
            it++;
        }
        void operator--()
        {
            it--;
        }
        int get_id()
        {
            return it->first;
        }
        node::edge_iterator_t edge_begin()
        {
            return it->second->edge_begin();
        }
        node::edge_iterator_t edge_end()
        {
            return it->second->edge_end();
        }

        friend class graph;
    };

    using node_iterator_t = std::shared_ptr<node_iterator>;

    friend class builder;

protected:

    node_iterator_t add_node(int id);

};



#endif //GRAPHMAKER_GRAPH_H
