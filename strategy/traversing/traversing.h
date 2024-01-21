#ifndef GRAPHMAKER_TRAVERSING_H
#define GRAPHMAKER_TRAVERSING_H

#include "../../command/adder_command.h"

class traversing {
public:
    virtual graph_t execute(graph_t graph_ptr) = 0;
};

using traversing_t = std::shared_ptr<traversing>;

#endif //GRAPHMAKER_TRAVERSING_H
