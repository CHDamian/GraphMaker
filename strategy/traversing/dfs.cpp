#include "dfs.h"
#include "../../builder.h"
#include <set>
#include <stack>

graph_t dfs::execute(graph_t graph_ptr, int node_id) {
    if(graph_ptr->get_node(node_id) == graph_ptr->node_end()) {
        throw node_not_exist_exception();
    }
    auto result_builder = builder();
    result_builder.add_node(node_id);
    std::set<int> used_nodes_set({node_id});
    std::stack<int> dfs_stack({node_id});
    while(!dfs_stack.empty()) {
        int actual_node = dfs_stack.top(); dfs_stack.pop();
        auto actual_node_it = graph_ptr->get_node(actual_node);
        for(auto edge_it = actual_node_it->edge_begin();*edge_it != *(actual_node_it->edge_end());++(*edge_it)) {
            if(used_nodes_set.find(edge_it->get_node_id()) != used_nodes_set.end()) {
                continue;
            }
            used_nodes_set.insert(edge_it->get_node_id());
            result_builder.add_node(edge_it->get_node_id());
            result_builder.add_single_edge(actual_node, edge_it->get_node_id(), edge_it->get_weight());
            dfs_stack.push(edge_it->get_node_id());
        }
    }
    return result_builder.build();
}