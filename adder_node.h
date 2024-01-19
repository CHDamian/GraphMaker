#ifndef GRAPHMAKER_ADDER_NODE_H
#define GRAPHMAKER_ADDER_NODE_H

#include "graph.h"
#include "adder_command.h"

class adder_node : public adder_command {
private:
    graph::node_iterator_t created_node;
    int id;
public:
    adder_node(graph_t graph, int id) : adder_command(graph), id(id) {}

    virtual void add();
    virtual void undo() noexcept;

    friend class builder;
};


#endif //GRAPHMAKER_ADDER_NODE_H
