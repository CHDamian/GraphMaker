#ifndef GRAPHMAKER_DISTANCE_H
#define GRAPHMAKER_DISTANCE_H

#include <memory>
#include "../../command/adder_command.h"
#include "distance_result.h"

/**< Wyjatek wyrzucany w przypadku braku poczatkowego wierzcholka w grafie */
class starting_node_not_exist : public std::exception{
public:
    [[nodiscard]] const char *what() const noexcept override {
        return "Graph does not contain starting node!";
    }
};

class distance {
protected:

    /**
     * @brief Dodaje wierzchołek o podanym identyfikatorze do wyniku odległości.
     * Inicjalizuje odległość na nieskończoność.
     * @param[in] result_proxy - Wskaźnik na wynik odległości (distance_result_t).
     * @param[in] id - Identyfikator wierzchołka.
     */
    void add_dist(distance_result_t result_proxy, int id);

    /**
     * @brief Dodaje wierzchołek o podanym identyfikatorze i odległości do wyniku odległości.
     * @param[in] result_proxy - Wskaźnik na wynik odległości (distance_result_t).
     * @param[in] id - Identyfikator wierzchołka.
     * @param[in] dist - Odległość do wierzchołka.
     */
    void add_dist(distance_result_t result_proxy, int id, int dist);

    /**
     * @brief Sprawdza, czy odległość dla danego identyfikatora istnieje w wyniku odległości.
     * @param[in] result_proxy - Wskaźnik na wynik odległości (distance_result_t).
     * @param[in] id - Identyfikator wierzchołka.
     * @return True, jeśli odległość istnieje; false w przeciwnym razie.
     */
    bool exists_dist(distance_result_t result_proxy, int id) const;

    /**
     * @brief Pobiera odległość dla danego identyfikatora z wyniku odległości.
     * @param[in] result_proxy - Wskaźnik na wynik odległości (distance_result_t).
     * @param[in] id - Identyfikator wierzchołka.
     * @return Odległość do wierzchołka.
     */
    int get_dist(distance_result_t result_proxy, int id);

    /**
     * @brief Usuwa odległość dla danego identyfikatora z wyniku odległości.
     * @param[in] result_proxy - Wskaźnik na wynik odległości (distance_result_t).
     * @param[in] id - Identyfikator wierzchołka.
     */
    void del_dist(distance_result_t result_proxy, int id);

public:
    /**
    * @brief Wykonuje algorytm.
    * Wykonuje zadany algorytm.
    * @param[in] graph_ptr - Wskaznik do grafu, na ktorym ma być wykonany algorytm.
    * @param[in] start_point punkt startowy algorytmu
    * @return wynik algorytmu.
    */
    virtual distance_result_t execute(graph_t graph_ptr, int start_point) = 0;
};

using distance_t = std::shared_ptr<distance>;

#endif //GRAPHMAKER_DISTANCE_H
