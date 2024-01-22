#include <queue>
#include "dijkstra.h"


void dijkstra::start(graph_t graph_ptr, distance_result_t result, int start_point)
{
    std::priority_queue<std::pair<int, int>> queue;
    queue.push({0, start_point});
    while(!queue.empty())
    {
        int nod = queue.top().second;
        int dist = queue.top().first * -1;
        queue.pop();
        if(get_dist(result, nod) < dist)continue;
        auto nod_it = graph_ptr->get_node(nod);

        for(auto edge_it = nod_it->edge_begin(); *edge_it != *(nod_it->edge_end()); ++(*edge_it))
        {
            int new_dist = get_dist(result, nod) + edge_it->get_weight();
            if(get_dist(result, edge_it->get_node_id()) > new_dist)
            {
                add_dist(result, edge_it->get_node_id(),new_dist);
                queue.push({new_dist * -1, edge_it->get_node_id()});
            }
        }
    }
}


void dijkstra::detect_negative_edge(graph_t graph_ptr)
{
    for(auto it = graph_ptr->node_begin(); *it != *graph_ptr->node_end(); ++(*it)) {
        for(auto edge_it = it->edge_begin(); *edge_it != *(it->edge_end()); ++(*edge_it))
            if(edge_it->get_weight() <= 0)throw negative_edge_in_graph_exception();
    }
}


distance_result_t dijkstra::execute(graph_t graph_ptr, int start_point)
{
    if(*(graph_ptr->get_node(start_point)) == *(graph_ptr->node_end()))throw starting_node_not_exist();
    detect_negative_edge(graph_ptr);

    distance_result_t result = distance_result_t(new distance_result());
    int num_of_nodes = 0;
    for(auto it = graph_ptr->node_begin(); *it != *graph_ptr->node_end(); ++(*it)) {
        add_dist(result, it->get_id());
        num_of_nodes++;
    }
    add_dist(result, start_point, 0);

    start(graph_ptr, result, start_point);

    return result;
}