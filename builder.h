#ifndef GRAPHMAKER_BUILDER_H
#define GRAPHMAKER_BUILDER_H

#include <memory>
#include <stack>
#include "graph.h"
#include "add_command.h"

using add_command_t = std::shared_ptr<add_command>;
using command_stack_t = std::stack<add_command_t>;
using graph_t = std::shared_ptr<graph>;

class builder {
private:
    graph_t graph;
    command_stack_t command_stack;

    builder() = default;

public:

    class stack_empty_exception : public std::exception {
    public:
        [[nodiscard]] const char *what() const noexcept override {
            return "There is no command to undo";
        }
    };

    void make_spojny();
    void make_acykliczny();
    void make_dodatni();

    void add_node(int id);
    void add_edge(int id_1, int id_2, int weight);
    void add_single_edge(int id_1, int id_2, int weight);
    void undo();
    graph_t build();

    friend class facade;
};


#endif //GRAPHMAKER_BUILDER_H
