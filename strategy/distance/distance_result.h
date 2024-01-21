#ifndef GRAPHMAKER_DISTANCE_RESULT_H
#define GRAPHMAKER_DISTANCE_RESULT_H

#include <memory>
#include <map>

class distance_result {
    std::map<int, int> distance_calc;

        /**
     * @brief Dodaje wierzchołek o podanym identyfikatorze do wyniku.
     * Inicjalizuje odległość na nieskończoność.
     * @param[in] id - Identyfikator wierzchołka.
     */
    void add(int id);

        /**
     * @brief Dodaje wierzchołek o podanym identyfikatorze i odległości do wyniku.
     * @param[in] id - Identyfikator wierzchołka.
     * @param[in] dist - Odległość do wierzchołka.
     */
    void add(int id, int dist);

        /**
     * @brief Sprawdza, czy odległość dla danego identyfikatora istnieje w wyniku.
     * @param[in] id - Identyfikator wierzchołka.
     * @return True, jeśli odległość istnieje; false w przeciwnym razie.
     */
    bool exists(int id) const;

        /**
     * @brief Pobiera odległość dla danego identyfikatora z wyniku.
     * @param[in] id - Identyfikator wierzchołka.
     * @return Odległość do wierzchołka.
     */
    int get(int id);

        /**
     * @brief Usuwa odległość dla danego identyfikatora z wyniku.
     * @param[in] id - Identyfikator wierzchołka.
     */
    void del(int id);

public:
    static const int INFINITY_DISTANCE = INT32_MAX;
    static const int NEG_INFINITY_DISTANCE = INT32_MIN;

    using distance_iterator = std::map<int, int>::const_iterator;

    distance_iterator begin() const;
    distance_iterator end() const;
    distance_iterator find(int id) const;

    friend class distance;
};

using distance_result_t = std::shared_ptr<distance_result>;

#endif //GRAPHMAKER_DISTANCE_RESULT_H
