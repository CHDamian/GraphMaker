//
// Created by macie on 1/20/2024.
//

#ifndef GRAPHMAKER_FACTORY_POSITIVE_H
#define GRAPHMAKER_FACTORY_POSITIVE_H


#include "factory.h"


class factory_positive : public factory{
protected:
    factory_positive() = default;

public:
    
    /** @brief Operator porownania elementow.
             * Operator sprawdzajacy czy porownywane elementy sa rowne
             * @param[in] rhs – ... .
             *  bez zadnych konfilktow.
             */
    factory& get_instace()
    {
        static factory_positive* instance = new factory_positive();
        return *instance;
    }

    virtual std::shared_ptr<graph> create(std::shared_ptr<graph> graph_ptr);
};

#endif //GRAPHMAKER_FACTORY_POSITIVE_H
