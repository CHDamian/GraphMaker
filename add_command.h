#ifndef GRAPHMAKER_ADD_COMMAND_H
#define GRAPHMAKER_ADD_COMMAND_H

#include "builder.h"

class add_command {
protected:
    graph_t graph;

    add_command(graph_t graph);
public:
    virtual void add() = 0;
    virtual void undo() noexcept = 0;
};


#endif //GRAPHMAKER_ADD_COMMAND_H
