#include "adder_single_edge.h"

void adder_single_edge::add() {
    edge1 = graph_ptr->add_edge(id1, id2, weight);
}

void adder_single_edge::undo() noexcept {
    graph_ptr->del_edge(edge1);
}
