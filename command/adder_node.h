#ifndef GRAPHMAKER_ADDER_NODE_H
#define GRAPHMAKER_ADDER_NODE_H

#include "../graph.h"
#include "adder_command.h"

class adder_node : public adder_command {
private:
    graph::node_iterator_t created_node;
    int id;
public:
    adder_node(graph_t graph_ptr, int id) : id(id)
    {
        this->graph_ptr = graph_ptr;
    }

    virtual void add();
    virtual void undo() noexcept;
};


#endif //GRAPHMAKER_ADDER_NODE_H
