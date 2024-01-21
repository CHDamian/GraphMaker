#ifndef GRAPHMAKER_BFS_H
#define GRAPHMAKER_BFS_H

#include "traversing.h"

class bfs : public traversing {
public:

        /**
     * @brief Wykonuje algorytm BFS na grafie.
     * @param[in] graph_ptr - Wskaźnik do grafu.
     * @param[in] node_id - Id wierzcholka grafu na ktorym rozpoczyna sie przeszukiwanie.
     * @return ...
     * @throws node_not_exist_exception Jeśli wierzchołek nie istnieje w grafie.
     */
    virtual graph_t execute(graph_t graph_ptr, int node_id);
};


#endif //GRAPHMAKER_BFS_H
