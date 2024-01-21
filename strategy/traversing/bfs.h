#ifndef GRAPHMAKER_BFS_H
#define GRAPHMAKER_BFS_H

#include "traversing.h"

/**< Klasa implementujaca algorytm bfs */
class bfs : public traversing {
protected:
    bfs() = default;
public:

     /**
     * @brief Wykonuje algorytm BFS na grafie.
     * @param[in] graph_ptr - Wskaźnik do grafu.
     * @param[in] node_id - Id wierzcholka grafu na ktorym rozpoczyna sie przeszukiwanie.
     * @return wynik przeszukiwania bfs, czyli wskaznik do skierowanego drzewa utworzonego na podstawie przejscia
     * @throws node_not_exist_exception Jeśli wierzchołek nie istnieje w grafie.
     */
    virtual graph_t execute(graph_t graph_ptr, int node_id);

    /** @brief Pobierz instancje klasy.
    * Pobiera instancje klasy
    * @return Jedyny obiekt klasy bfs
    *  bez zadnych konfilktow.
    */
    static bfs& get_instance()
    {
        static bfs* instance = new bfs();
        return *instance;
    }
};


#endif //GRAPHMAKER_BFS_H
