/** @file
 * Deklaracja modulu rezultatu algorytmow odleglosci
 *
 * @author Damian Chanko, Maciej Chanko, Pawel Krol
 * @date 21.01.2024
 */

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
    static const int INFINITY_DISTANCE = INT32_MAX; /**< Odleglosc nieskonczonosc */
    static const int NEG_INFINITY_DISTANCE = INT32_MIN; /**< Odleglosc minus nieskonczonosc */

    using distance_iterator = std::map<int, int>::const_iterator; /**< Const Iterator struktury */

    /** @brief Poczatek listy wynikowej.
     * Zwraca const iterator na poczatek listy wynikowej
     * @return Const iterator na poczatek listy.
     */
    distance_iterator begin() const;

    /** @brief Koniec listy wynikowej.
     * Zwraca const iterator na koniec listy wynikowej
     * @return Const iterator na koniec listy.
     */
    distance_iterator end() const;

    /** @brief Zwraca informacje o wierzcholku.
     * Zwraca const iterator na szukany wierzcholek lub koniec listy
     * jezeli wierzcholek nie istnieje.
     * @return Const iterator na wierzcholek.
     */
    distance_iterator find(int id) const;

    friend class distance;
};

using distance_result_t = std::shared_ptr<distance_result>;

#endif //GRAPHMAKER_DISTANCE_RESULT_H
