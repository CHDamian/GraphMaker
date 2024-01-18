#include "builder.h"
#include "memory"
#include "Add_node.h"

void builder::add_node(int id) {
    auto command = std::make_shared<Add_node>(this->graph, id);
    command->add();
    command_stack.push(command);
}

void builder::undo() {
    if (command_stack.empty()) {
        throw stack_empty_exception();
    }

    auto command = command_stack.top();
    command->undo();
    command_stack.pop();
}

void builder::make_spojny() {
    // TODO: uzupełnić jak będą fabryki i dekoratory
}

void builder::make_acykliczny() {
    // TODO: uzupełnić jak będą fabryki i dekoratory
}

void builder::make_dodatni() {
    // TODO: uzupełnić jak będą fabryki i dekoratory
}

graph_t builder::build() {
    return graph;
}
