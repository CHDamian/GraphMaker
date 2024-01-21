#ifndef GRAPHMAKER_BFS_H
#define GRAPHMAKER_BFS_H

#include "traversing.h"

class bfs : public traversing {
public:
    virtual graph_t execute(graph_t graph_ptr, int node_id);
};


#endif //GRAPHMAKER_BFS_H