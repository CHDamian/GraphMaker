
#include "bellman_ford.h"

void bellman_ford::bellman_ford_cycle(graph_t graph_ptr, distance_result_t result)
{
    for(auto it = graph_ptr->node_begin(); *it != *(graph_ptr->node_end()); ++(*it))
    {
        int nod = it->get_id();
        if(get_dist(result, nod) == distance_result::INFINITY_DISTANCE)continue;
        for(auto edge_it = it->edge_begin(); *edge_it != *(it->edge_end()); ++(*edge_it))
        {
            int new_dist = get_dist(result, nod) + edge_it->get_weight();
            if(get_dist(result, edge_it->get_node_id()) > new_dist)
                add_dist(result, edge_it->get_node_id(),new_dist);
        }
    }
}

void bellman_ford::detect_negative_cycle(graph_t graph_ptr, distance_result_t result)
{
    for(auto it = graph_ptr->node_begin(); *it != *(graph_ptr->node_end()); ++(*it))
    {
        int nod = it->get_id();
        if(get_dist(result, nod) == distance_result::INFINITY_DISTANCE)continue;
        for(auto edge_it = it->edge_begin(); *edge_it != *(it->edge_end()); ++(*edge_it))
        {
            int new_dist = get_dist(result, nod) + edge_it->get_weight();
            if(get_dist(result, edge_it->get_node_id()) > new_dist)throw negative_cycle_exception();
        }
    }
}

distance_result_t bellman_ford::execute(graph_t graph_ptr, int start_point)
{
    if(*(graph_ptr->get_node(start_point)) == *(graph_ptr->node_end()))throw starting_node_not_exist();

    distance_result_t result = distance_result_t(new distance_result());
    int num_of_nodes = 0;
    for(auto it = graph_ptr->node_begin(); *it != *graph_ptr->node_end(); ++(*it)) {
        add_dist(result, it->get_id());
        num_of_nodes++;
    }
    add_dist(result, start_point, 0);

    for(int i=0; i<num_of_nodes; i++)bellman_ford_cycle(graph_ptr, result);
    detect_negative_cycle(graph_ptr, result);

    return result;
}
