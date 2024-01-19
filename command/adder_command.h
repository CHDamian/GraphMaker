#ifndef GRAPHMAKER_ADDER_COMMAND_H
#define GRAPHMAKER_ADDER_COMMAND_H

#include "../graph.h"
using graph_t = std::shared_ptr<graph>;

class adder_command {
protected:
    graph_t graph_ptr;

public:
    virtual void add() = 0;
    virtual void undo() noexcept = 0;
};


#endif //GRAPHMAKER_ADDER_COMMAND_H
