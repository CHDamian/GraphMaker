//
// Created by macie on 1/20/2024.
//

#ifndef GRAPHMAKER_FACTORY_CONNECTED_H
#define GRAPHMAKER_FACTORY_CONNECTED_H


#include "factory.h"

class factory_connected : public factory
{
protected:
    factory_connected() = default;

public:

    /** @brief Operator porownania elementow.
             * Operator sprawdzajacy czy porownywane elementy sa rowne
             * @param[in] rhs – ... .
             *  bez zadnych konfilktow.
             */
    static factory& get_instance()
    {
        static factory_connected* instance = new factory_connected();
        return *instance;
    }

    /** @brief Pobierz wierzcholek.
    * Pobiera wierzcholek o podanym @param[in] id
    * @param[in] id - id pobieranego wierzcholka
    * @return Wierzcholek o podanym id
    *  bez zadnych konfilktow.
    */
    virtual std::shared_ptr<graph> create(std::shared_ptr<graph> graph_ptr);
};


#endif //GRAPHMAKER_FACTORY_CONNECTED_H
