#include "adder_single_edge.h"

void adder_single_edge::add() {
    edge1 = graph->add_edge(id1, id2, weight);
}

void adder_single_edge::undo() noexcept {
    graph->del_edge(edge1);
}
