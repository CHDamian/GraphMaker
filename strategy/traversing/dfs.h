#ifndef GRAPHMAKER_DFS_H
#define GRAPHMAKER_DFS_H

#include "traversing.h"


class dfs : public traversing {
public:

        /**
     * @brief Wykonuje algorytm DFS na grafie.
     * @param[in] graph_ptr - Wskaźnik do grafu.
     * @param[in] node_id - Id wierzcholka grafu na ktorym rozpoczyna sie przeszukiwanie.
     * @return ...
     * @throws node_not_exist_exception Jeśli wierzchołek nie istnieje w grafie.
     */
    virtual graph_t execute(graph_t graph_ptr, int node_id);
};


#endif //GRAPHMAKER_DFS_H
