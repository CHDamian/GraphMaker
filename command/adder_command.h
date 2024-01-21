/** @file
 * Deklaracja modulu commandow
 *
 * @author Damian Chanko, Maciej Chanko, Pawel Krol
 * @date 21.01.2024
 */

#ifndef GRAPHMAKER_ADDER_COMMAND_H
#define GRAPHMAKER_ADDER_COMMAND_H

#include "../graph.h"
using graph_t = std::shared_ptr<graph>;

class adder_command {
protected:
    graph_t graph_ptr; /**< Wskaznik do grafu */

public:
    /** @brief Dodawanie elementu.
    * Dodaje element do grafu, moze byc to wierzcholek, krawedz itd.
    */
    virtual void add() = 0;
    /** @brief Cofanie dodania.
    * Cofa dodany element do grafu, np. wierzcholek, krawedz itd.
    *  bez zadnych konfilktow.
    */
    virtual void undo() noexcept = 0;
};


#endif //GRAPHMAKER_ADDER_COMMAND_H
