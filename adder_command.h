#ifndef GRAPHMAKER_ADDER_COMMAND_H
#define GRAPHMAKER_ADDER_COMMAND_H

#include "builder.h"

class adder_command {
protected:
    graph_t graph;

    adder_command(graph_t graph);
public:
    virtual void add() = 0;
    virtual void undo() noexcept = 0;
};


#endif //GRAPHMAKER_ADDER_COMMAND_H
