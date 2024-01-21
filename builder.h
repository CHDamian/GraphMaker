/** @file
 * Deklaracja modulu budowniczego
 *
 * @author Damian Chanko, Maciej Chanko, Pawel Krol
 * @date 21.01.2024
 */

#ifndef GRAPHMAKER_BUILDER_H
#define GRAPHMAKER_BUILDER_H

#include <memory>
#include <stack>
#include "graph.h"
#include "command/adder_command.h"

using add_command_t = std::shared_ptr<adder_command>;
using command_stack_t = std::stack<add_command_t>;

/**< Budowniczy do tworzenia grafow w wygodny sposob */
class builder {
private:
    graph_t graph_ptr; /**< Wskaznik do tworzonego grafu */
    command_stack_t command_stack; /**< Stos komend wywolanych na tworzonym grafie */

    builder()
    {
        graph_ptr = graph_t(new graph());
    };

public:
    /**< Wyjatek wyrzucany w przypadku proby cofniecia komendy na pustym stosie */
    class stack_empty_exception : public std::exception {
    public:
        [[nodiscard]] const char *what() const noexcept override {
            return "There is no command to undo";
        }
    };

    /**< Wyjatek wyrzucany w przypadku. gdy tworzony graf jest niepoprawny */
    class graph_invalid_exception : public std::exception {
    public:
        [[nodiscard]] const char *what() const noexcept override {
            return "Constructed graph_ptr is invalid";
        }
    };

    /**
     * @brief Funkcja dekorujaca graf w graf spojny.
     * Funkcja opakowuje budowany graf w spojny dekorator.
     */
    void make_connected();
    /**
     * @brief Funkcja dekorujaca graf w drzewo.
     * Funkcja opakowuje budowany graf w dekorator drzewa.
     */
    void make_tree();
    /**
     * @brief Funkcja dekorujaca graf w graf dodatni.
     * Funkcja opakowuje budowany graf w dodatni dekorator.
     */
    void make_positive();

    /**
     * @brief Dodaj wierzcholek do grafu.
     * Funkcja dodaje wierzcholek o podanym id do budowanego grafu.
     * @param[in] id - id wierzcholka do stworzenia.
     */
    void add_node(int id);
    /**
     * @brief Dodaj krawedz do drzewa.
     * Funkcja dodaje krawedz o podanych parametrach do budowanego grafu.
     * @param[in] id_1 - id wierzcholka pierwszego wierzcholka.
     * @param[in] id_2 - id wierzcholka drugiego wierzcholka.
     * @param[in] weight - waga krawedzi do dodania.
     */
    void add_edge(int id_1, int id_2, int weight);
    /**
     * @brief Dodaj krawedz skierowana do drzewa.
     * Funkcja dodaje krawedz skierowana o podanych parametrach do budowanego grafu.
     * @param[in] id_1 - id wierzcholka pierwszego wierzcholka.
     * @param[in] id_2 - id wierzcholka drugiego wierzcholka.
     * @param[in] weight - waga krawedzi do dodania.
     */
    void add_single_edge(int id_1, int id_2, int weight);
    /**
     * @brief Cofnij komende.
     * Funkcja cofa ostatnio dodana rzecz do grafu.
     *  bez konfliktu
     */
    void undo();
    /**
     * @brief Zbuduj graf.
     * Funkcja zwraca graf zbudowany na podstawie wczesniej uzytych komend.
     *  bez konfliktu
     * @return Zbudowany graf.
     */
    graph_t build();

    friend class facade;
    friend class graph_facade;
    friend class dfs;
    friend class bfs;
};

using builder_t = std::shared_ptr<builder>;

#endif //GRAPHMAKER_BUILDER_H
