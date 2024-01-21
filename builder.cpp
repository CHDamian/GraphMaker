#include "builder.h"
#include "memory"
#include "command/adder_node.h"
#include "command/adder_edge.h"
#include "command/adder_single_edge.h"

#include "factories/factories.h"

void builder::add_node(int id) {
    auto command = std::make_shared<adder_node>(graph_ptr, id);
    command->add();
    command_stack.push(command);
}

void builder::add_edge(int id_1, int id_2, int weight) {
    auto command = std::make_shared<adder_edge>(graph_ptr, id_1, id_2, weight);
    command->add();
    command_stack.push(command);
}

void builder::add_single_edge(int id_1, int id_2, int weight) {
    auto command = std::make_shared<adder_single_edge>(graph_ptr, id_1, id_2, weight);
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

void builder::make_connected() {
    graph_ptr = factory_connected::get_instance().create(graph_ptr);
}

void builder::make_tree() {
    graph_ptr = factory_tree::get_instance().create(graph_ptr);
}

void builder::make_positive() {
    graph_ptr = factory_positive::get_instance().create(graph_ptr);
}

graph_t builder::build() {
    if(!graph_ptr->is_valid()) {
        throw graph_invalid_exception();
    }
    graph_ptr->set_prototype(false);
    return graph_ptr;
}
