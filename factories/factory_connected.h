//
// Created by macie on 1/20/2024.
//

#ifndef GRAPHMAKER_FACTORY_CONNECTED_H
#define GRAPHMAKER_FACTORY_CONNECTED_H


#include "factory.h"

/**< Fabryka do tworzenia spojnych grafow */
class factory_connected : public factory
{
protected:
    factory_connected() = default;

public:

    /** @brief Pobierz instancje klasy.
    * Pobiera instancje klasy
    * @return Jedyny obiekt klasy factory_connected
    *  bez zadnych konfilktow.
    */
    static factory& get_instance()
    {
        static factory_connected* instance = new factory_connected();
        return *instance;
    }

    /** @brief Stworz graf spojny.
    * Opakowuje otrzymany graf w spojny dekorator
    * @param[in] graph_ptr - wskaznik do grafu ktory nalezy opakowac
    * @return Graf opakowany w spojny dekorator.
    */
    virtual std::shared_ptr<graph> create(std::shared_ptr<graph> graph_ptr);
};


#endif //GRAPHMAKER_FACTORY_CONNECTED_H
