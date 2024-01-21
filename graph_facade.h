#ifndef GRAPHMAKER_GRAPH_FACADE_H
#define GRAPHMAKER_GRAPH_FACADE_H

#include "strategy/distance/distance.h"
#include "strategy/traversing/traversing.h"
#include "builder.h"

class graph_facade {
private:
    traversing_t traversing_algorithm;
    distance_t distance_algorithm;

public:
    builder_t make_graph();
    void set_traversing(traversing_t algorithm) noexcept;
    void set_distance(distance_t algorithm) noexcept;
    distance_result_t execute_distance(graph_t graph_ptr);
    graph_t execute_traversing(graph_t graph_ptr);
};


#endif //GRAPHMAKER_GRAPH_FACADE_H
