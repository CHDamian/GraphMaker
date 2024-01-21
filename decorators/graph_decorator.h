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
    std::shared_ptr<graph> graph_ptr; /**< Dekorowany graf */
    graph_decorator(std::shared_ptr<graph> graph_ptr)
    {
        this->graph_ptr = graph_ptr;
    }



public:
    graph_decorator() = delete;

    /** @brief Poczatek listy wierzcholkow.
     * Zwraca iterator na poczatek listy wierzcholkow.
     * @return Iterator na poczatek listy.
     */
    virtual node_iterator_t node_begin();

    /** @brief Koniec listy wierzcholkow.
     * Zwraca iterator na koniec listy wierzcholkow.
     * @return Iterator na koniec listy.
     */
    virtual node_iterator_t node_end();

    /** @brief Znajdz krawedz.
     * Znajdz wierzcholek o id rownym @param[in] id
     * @param[in] id   – id wierzcholka
     * @return Iterator do wierzcholka, jezeli istnieje
     *  lub koniec listy.
     */
    virtual node_iterator_t get_node(int id);

protected:

    /** @brief Dodaj wierzcholek.
     * Dodaje wierzcholek o podanym @param[in] id
     * @param[in] id - id dodawanego wierzcholka
     * @return Iterator do wierzcholka o podanym id
     */
    virtual node_iterator_t add_node(int id);


    /** @brief Dodaj krawedz.
     * Dodaje krawedz do grafu.
     * @param[in] src - wierzcholek wychodzacy
     * @param[in] dest - wierzcholek wchodzacy
     * @param[in] weight - waga krawedzi
     * @return Para iteratorow do wierzcholka wychodzacego i krawedzi.
     */
    virtual node_egde_pair add_edge(int src, int dest, int weight);


    /** @brief Usun krawedz.
     * Usun krawedz @param[in] edge_to_del
     * @param[in] edge_to_del – krawedz grafu do usuniecia z wierzcholkiem.
     */
    virtual void del_edge(node_egde_pair edge_to_del) noexcept;

    /** @brief Czy graf jest ok.
     * Sprawdza, czy warunki nalozone na graf sa spelnione.
     * @return True jezeli sa spelnione, lub false w przeciwnym wypadku.
     */
    virtual bool is_valid() const;

    /** @brief Ustawia czy graf jest w produkcji.
     * Ustawia, czy graf jest jeszcze tworzony czy juz nie
     * @param[in] prototype – Czy w trakcie tworzenia
     */
    virtual void set_prototype(bool prototype) noexcept;

    /** @brief Usun wierzcholek.
     * Usuwa podany wierzcholek
     * @param[in] node_to_del - usuwany wierzcholek
     */
    virtual void del_node(node_iterator_t node_to_del) noexcept;

};



#endif //GRAPHMAKER_GRAPH_DECORATOR_H
