#include "builder.h"
#include "memory"
#include "adder_node.h"
#include "adder_edge.h"
#include "adder_single_edge.h"

void builder::add_node(int id) {
    auto command = std::make_shared<adder_node>(graph, id);
    command->add();
    command_stack.push(command);
}

void builder::add_edge(int id_1, int id_2, int weight) {
    auto command = std::make_shared<adder_edge>(graph, id_1, id_2, weight);
    command->add();
    command_stack.push(command);
}

void builder::add_single_edge(int id_1, int id_2, int weight) {
    auto command = std::make_shared<adder_single_edge>(graph, id_1, id_2, weight);
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
    if(!graph->is_valid()) {
        throw graph_invalid_exception();
    }

    return graph;
}
