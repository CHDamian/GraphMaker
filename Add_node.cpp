#include "Add_node.h"

void Add_node::add() {
    created_node = this->graph->add_node(this->id);
}

void Add_node::undo() noexcept {
    this->graph->del_node(created_node);
}