#include "adder_node.h"

void adder_node::add() {
    created_node = graph->add_node(id);
}

void adder_node::undo() noexcept {
    graph->del_node(created_node);
}