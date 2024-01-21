#ifndef GRAPHMAKER_DFS_H
#define GRAPHMAKER_DFS_H

#include "traversing.h"

class dfs : public traversing {
protected:
    dfs() = default;
public:
    virtual graph_t execute(graph_t graph_ptr, int node_id);

    static dfs& get_instance()
    {
        static dfs* instance = new dfs();
        return *instance;
    }
};


#endif //GRAPHMAKER_DFS_H
