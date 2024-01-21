#ifndef GRAPHMAKER_DISTANCE_H
#define GRAPHMAKER_DISTANCE_H

#include <memory>
#include "../../command/adder_command.h"
#include "distance_result.h"

class distance {
public:
    virtual distance_result_t execute(graph_t graph_ptr) = 0;
};

using distance_t = std::shared_ptr<distance>;

#endif //GRAPHMAKER_DISTANCE_H
