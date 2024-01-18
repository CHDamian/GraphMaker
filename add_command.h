#ifndef GRAPHMAKER_ADD_COMMAND_H
#define GRAPHMAKER_ADD_COMMAND_H

#include "builder.h"

class add_command {
private:
    graph_t graph;

public:
    virtual void add() = 0;
    virtual void undo() noexcept = 0;
};


#endif //GRAPHMAKER_ADD_COMMAND_H
