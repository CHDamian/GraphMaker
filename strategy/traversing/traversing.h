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

/**< Klasa bazowa dla klas wykonujacych przejscie po grafie */
class traversing {
public:
    /**
     * @brief Funkcja wykonujaca przejscie.
     * Funkcja wykonuje przejscie na otrzymanym grafie, zaczynajac od wybranego wierzcholka.
     * @param[in] graph_ptr - wskaznik do grafu, na ktorym jest wykonywane przejscie.
     * @param[in] node_id - id wierzcholka od ktorego nalezy zaczac przeszukiwanie.
     * @return wskaznik do skierowanego drzewa utworzonego na podstawie przejscia.
     */
    virtual graph_t execute(graph_t graph_ptr, int node_id) = 0;
};

using traversing_t = std::shared_ptr<traversing>;

#endif //GRAPHMAKER_TRAVERSING_H
