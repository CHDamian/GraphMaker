#ifndef GRAPHMAKER_TRAVERSING_H
#define GRAPHMAKER_TRAVERSING_H

#include "../../command/adder_command.h"

/**< Wyjatek wyrzucany w przypadku braku wierzcholka o podanym id */
class node_not_exist_exception : public std::exception {
public:
    [[nodiscard]] const char *what() const noexcept override {
        return "No node with such id";
    }
};

class traversing {
public:
    virtual graph_t execute(graph_t graph_ptr, int node_id) = 0;
};

using traversing_t = std::shared_ptr<traversing>;

#endif //GRAPHMAKER_TRAVERSING_H
