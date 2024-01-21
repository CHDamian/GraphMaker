#ifndef GRAPHMAKER_GRAPH_DECORATOR_H
#define GRAPHMAKER_GRAPH_DECORATOR_H

#include "../graph.h"
#include "memory"

/**< Wyjatek wyrzucany w przypadku gdy graf nie jest drzewem */
class graph_not_tree_exception : public std::exception{
public:
    [[nodiscard]] const char *what() const noexcept override {
        return "Graph is not a tree!";
    }
};

/**< Wyjatek wyrzucany w przypadku gdy graf nie jest dodatni */
class graph_not_positive_exception : public std::exception{
public:
    [[nodiscard]] const char *what() const noexcept override {
        return "Graph is not positive!";
    }
};

class graph_decorator : public graph{
protected:
    std::shared_ptr<graph> graph_ptr;
    graph_decorator(std::shared_ptr<graph> graph_ptr)
    {
        this->graph_ptr = graph_ptr;
    }



public:
    graph_decorator() = delete;

    virtual node_iterator_t node_begin();

    virtual node_iterator_t node_end();

    /** @brief Pobierz wierzcholek.
         * Pobiera wierzcholek o podanym @param[in] id
         * @param[in] id - id pobieranego wierzcholka
         * @return Wierzcholek o podanym id
         *  bez zadnych konfilktow.
         */
    virtual node_iterator_t get_node(int id);

protected:

    /** @brief Dodaj wierzcholek.
         * Dodaje wierzcholek o podanym @param[in] id
         * @param[in] id - id dodawanego wierzcholka
         * @return Wierzcholek o podanym id
         *  bez zadnych konfilktow.
         */
    virtual node_iterator_t add_node(int id);


    /** @brief Dodaj krawedz.
         * Dodaje krawedz o podanym @param[in] id
         * @param[in] src - ...
         * @param[in] dest - ...
         * @param[in] weight - waga krawedzi
         * @return Krawedz
         *  bez zadnych konfilktow.
         */
    virtual node_egde_pair add_edge(int src, int dest, int weight);


    /**
 * @brief Usuwa krawędź.
 * @param[in] edge_to_del - Iterator krawędzi do usunięcia.
 *  Bez konfliktów.
 */
    virtual void del_edge(node_egde_pair edge_to_del) noexcept;

    virtual bool is_valid() const;

    virtual void set_prototype(bool prototype) noexcept;

    /** @brief Usun wierzcholek.
         * Usuwa podany wierzcholek
         * @param[in] node_to_del - usuwany wierzcholek
         *  bez zadnych konfilktow.
         */
    virtual void del_node(node_iterator_t node_to_del) noexcept;

};



#endif //GRAPHMAKER_GRAPH_DECORATOR_H
