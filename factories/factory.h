/** @file
 * Deklaracja modulu fabryki
 *
 * @author Damian Chanko, Maciej Chanko, Pawel Krol
 * @date 21.01.2024
 */

#ifndef GRAPHMAKER_FACTORY_H
#define GRAPHMAKER_FACTORY_H
#include "memory"
#include "../graph.h"

/**< Fabryka do tworzenia odpowiednich dekoratorow grafow */
class factory{

protected:

    factory() = default;

public:
    /**
     * @brief Funkcja tworzaca udekorowany graf.
     * Funkcja opakowuje otrzymany graf w wybrany dekorator.
     * @param[in] graph_ptr - wskaznik do grafu, ktory nalezy udekorowac.
     * @return Udekorowany graf.
     */
    virtual std::shared_ptr<graph> create(std::shared_ptr<graph> graph_ptr) = 0;
};

#endif //GRAPHMAKER_FACTORY_H
