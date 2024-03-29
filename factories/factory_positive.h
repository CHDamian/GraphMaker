/** @file
 * Deklaracja fabryki grafow dodatnich
 *
 * @author Damian Chanko, Maciej Chanko, Pawel Krol
 * @date 21.01.2024
 */

#ifndef GRAPHMAKER_FACTORY_POSITIVE_H
#define GRAPHMAKER_FACTORY_POSITIVE_H


#include "factory.h"

/**< Fabryka do tworzenia dodatnich grafow */
class factory_positive : public factory{
protected:
    factory_positive() = default;

public:

    /** @brief Pobierz instancje klasy.
    * Pobiera instancje klasy
    * @return Jedyny obiekt klasy factory_positive
    *  bez zadnych konfilktow.
    */
    static factory& get_instance()
    {
        static factory_positive* instance = new factory_positive();
        return *instance;
    }

    /** @brief Stworz graf dodatni.
    * Opakowuje otrzymany graf w dodatni dekorator
    * @param[in] graph_ptr - wskaznik do grafu ktory nalezy opakowac
    * @return Graf opakowany w dodatni dekorator.
    */
    virtual std::shared_ptr<graph> create(std::shared_ptr<graph> graph_ptr);
};

#endif //GRAPHMAKER_FACTORY_POSITIVE_H
