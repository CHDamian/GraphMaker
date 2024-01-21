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

    std::set<int> used_nodes_set;
    used_nodes_set.insert(node_id);

    std::stack<int> dfs_stack;
    dfs_stack.push(node_id);

    while(!dfs_stack.empty()) {
        int actual_node = dfs_stack.top();
        dfs_stack.pop();

        auto actual_node_it = graph_ptr->get_node(actual_node);
        for(auto edge_it = actual_node_it->edge_begin();edge_it != actual_node_it->edge_end();++(*edge_it)) {
            int next_node_id = edge_it->get_node_id();
            if(used_nodes_set.find(next_node_id) != used_nodes_set.end()) {
                continue;
            }

            used_nodes_set.insert(next_node_id);
            int weight = edge_it->get_weight();
            result_builder.add_node(next_node_id);
            result_builder.add_single_edge(actual_node, next_node_id, weight);

            auto next_node_it = graph_ptr->get_node(next_node_id);
            for(auto next_edge_it = next_node_it->edge_begin();next_edge_it != next_node_it->edge_end();++(*next_edge_it)) {
                if(used_nodes_set.find(next_edge_it->get_node_id()) != used_nodes_set.end()) {
                    continue;
                }

                dfs_stack.push(next_edge_it->get_node_id());
            }
        }
    }

    return result_builder.build();
}
