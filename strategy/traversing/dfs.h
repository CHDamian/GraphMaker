#ifndef GRAPHMAKER_DFS_H
#define GRAPHMAKER_DFS_H

#include "traversing.h"


class dfs : public traversing {
public:
    virtual graph_t execute(graph_t graph_ptr, int node_id);
};


#endif //GRAPHMAKER_DFS_H
