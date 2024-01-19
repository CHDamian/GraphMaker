#include "adder_edge.h"

void adder_edge::add() {
    edge1 = graph->add_edge(id1, id2, weight);
    edge2 = graph->add_edge(id2, id1, weight);
}

void adder_edge::undo() noexcept {
    graph->del_edge(edge1);
    graph->del_edge(edge2);
}
