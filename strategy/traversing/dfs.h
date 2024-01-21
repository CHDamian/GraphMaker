#ifndef GRAPHMAKER_DFS_H
#define GRAPHMAKER_DFS_H

#include "traversing.h"

/**< Klasa implementujaca algorytm dfs */
class dfs : public traversing {
protected:
    dfs() = default;
public:

     /**
     * @brief Wykonuje algorytm DFS na grafie.
     * @param[in] graph_ptr - Wskaźnik do grafu.
     * @param[in] node_id - Id wierzcholka grafu na ktorym rozpoczyna sie przeszukiwanie.
     * @return wynik przeszukiwania dfs, czyli wskaznik do skierowanego drzewa utworzonego na podstawie przejscia
     * @throws node_not_exist_exception Jeśli wierzchołek nie istnieje w grafie.
     */
    virtual graph_t execute(graph_t graph_ptr, int node_id);

    /** @brief Pobierz instancje klasy.
    * Pobiera instancje klasy
    * @return Jedyny obiekt klasy dfs
    *  bez zadnych konfilktow.
    */
    static dfs& get_instance()
    {
        static dfs* instance = new dfs();
        return *instance;
    }
};


#endif //GRAPHMAKER_DFS_H
