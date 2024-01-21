#include "graph_facade.h"

builder_t graph_facade::make_graph() {
    return builder_t();
}

void graph_facade::set_traversing(traversing_t algorithm) noexcept {
    traversing_algorithm = algorithm;
}

void graph_facade::set_distance(distance_t algorithm) noexcept {
    distance_algorithm = algorithm;
}

distance_result_t graph_facade::execute_distance(graph_t graph_ptr) {
    return distance_algorithm->execute(graph_ptr);
}

graph_t graph_facade::execute_traversing(graph_t graph_ptr) {
    return traversing_algorithm->execute(graph_ptr);
}
