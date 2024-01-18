#ifndef GRAPHMAKER_ADD_NODE_H
#define GRAPHMAKER_ADD_NODE_H

#include "graph.h"
#include "add_command.h"

class Add_node : public add_command {
private:
    graph::node_iterator_t created_node;
    int id;
public:
    Add_node(graph_t graph, int id) : add_command(graph), id(id) {}

    virtual void add();
    virtual void undo() noexcept;

    friend class builder;
};


#endif //GRAPHMAKER_ADD_NODE_H
