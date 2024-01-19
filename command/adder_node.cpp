#include "adder_node.h"

void adder_node::add() {
    created_node = graph_ptr->add_node(id);
}

void adder_node::undo() noexcept {
    graph_ptr->del_node(created_node);
}