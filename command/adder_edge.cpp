#include "adder_edge.h"

void adder_edge::add() {
    edge1 = graph_ptr->add_edge(id1, id2, weight);
    try {
        edge2 = graph_ptr->add_edge(id2, id1, weight);
    }catch (std::exception e)
    {
        graph_ptr->del_edge(edge1);
    }
}

void adder_edge::undo() noexcept {
    graph_ptr->del_edge(edge1);
    graph_ptr->del_edge(edge2);
}
