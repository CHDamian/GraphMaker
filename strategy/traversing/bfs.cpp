#include "bfs.h"
#include "../../builder.h"
#include <set>
#include <queue>

/**
 * @brief Wykonuje algorytm BFS na grafie.
 * @param[in] graph_ptr - Wskaźnik do grafu.
 * @param[in] node_id - Id wierzcholka grafu na ktorym rozpoczyna sie przeszukiwanie.
 * @return ...
 * @throws node_not_exist_exception Jeśli wierzchołek nie istnieje w grafie.
 */
graph_t bfs::execute(graph_t graph_ptr, int node_id) {
    if(graph_ptr->get_node(node_id) == graph_ptr->node_end()) {
        throw node_not_exist_exception();
    }
    auto result_builder = builder();
    result_builder.add_node(node_id);
    std::set<int> used_nodes_set({node_id});
    std::queue<int> bfs_queue({node_id});
    while(!bfs_queue.empty()) {
        int actual_node = bfs_queue.front(); bfs_queue.pop();
        auto actual_node_it = graph_ptr->get_node(actual_node);
        for(auto edge_it = actual_node_it->edge_begin();*edge_it != *(actual_node_it->edge_end());++(*edge_it)) {
            if(used_nodes_set.find(edge_it->get_node_id()) != used_nodes_set.end()) {
                continue;
            }
            used_nodes_set.insert(edge_it->get_node_id());
            result_builder.add_node(edge_it->get_node_id());
            result_builder.add_single_edge(actual_node, edge_it->get_node_id(), edge_it->get_weight());
            bfs_queue.push(edge_it->get_node_id());
        }
    }
    return result_builder.build();
}