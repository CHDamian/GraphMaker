#ifndef GRAPHMAKER_DISTANCE_H
#define GRAPHMAKER_DISTANCE_H

#include <memory>
#include "../../command/adder_command.h"
#include "distance_result.h"

class distance {
protected:
    void add_dist(distance_result_t result_proxy, int id);
    void add_dist(distance_result_t result_proxy, int id, int dist);
    bool exists_dist(distance_result_t result_proxy, int id) const;
    int get_dist(distance_result_t result_proxy, int id);
    void del_dist(distance_result_t result_proxy, int id);

public:
    virtual distance_result_t execute(graph_t graph_ptr, int start_point) = 0;
};

using distance_t = std::shared_ptr<distance>;

#endif //GRAPHMAKER_DISTANCE_H
