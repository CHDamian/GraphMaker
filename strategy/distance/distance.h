#ifndef GRAPHMAKER_DISTANCE_H
#define GRAPHMAKER_DISTANCE_H

#include "../../command/adder_command.h"
#include "distance_result.h"

class distance {
public:
    virtual distance_result execute(graph_t graph_ptr) = 0;
};


#endif //GRAPHMAKER_DISTANCE_H
