//
// Created by macie on 1/20/2024.
//

#ifndef GRAPHMAKER_FACTORY_TREE_H
#define GRAPHMAKER_FACTORY_TREE_H


#include "factory.h"
#include <set>

/**< Fabryka do tworzenia drzew */
class factory_tree : public factory
{
protected:

    factory_tree() = default;

private:

    /** @brief Sprawdza poprawnosc krawedzi.
    * Sprawdza czy aktualny uklad krawedzi moze pozniej stworzyc drzewo.
    * @param[in] graph_ptr - sprawdzany graf
    * @param[in] edge_checker - mapa weryfikacji krawedzi
    * @param[in] visited - zbior odwiedzonych wierzcholkow
    * @param[in] nod - sprawdzany wierzcholek
    * @param[in] parent - ojciec wierzcholka w przejsciu dfs
    */
    void dfs_check_edges(std::shared_ptr<graph> graph_ptr, std::map<std::pair<int, int>, std::pair<int, bool>> &edge_checker,
                         std::set<int> &visited, graph::node_iterator_t nod, graph::node_iterator_t parent);

public:

    /** @brief Pobierz instancje klasy.
    * Pobiera instancje klasy
    * @return Jedyny obiekt klasy factory_tree
    *  bez zadnych konfilktow.
    */
    static factory& get_instance()
    {
        static factory_tree* instance = new factory_tree();
        return *instance;
    }

    /** @brief Stworz drzewo.
    * Opakowuje otrzymany graf w dekorator drzewa
    * @param[in] graph_ptr - wskaznik do grafu ktory nalezy opakowac
    * @return Graf opakowany w dekorator drzewa.
    */
    virtual std::shared_ptr<graph> create(std::shared_ptr<graph> graph_ptr);

};

#endif //GRAPHMAKER_FACTORY_TREE_H
