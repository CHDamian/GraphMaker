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
    factory& get_instance()
    {
        static factory_connected* instance = new factory_connected();
        return *instance;
    }

    virtual std::shared_ptr<graph> create(std::shared_ptr<graph> graph_ptr);
};


#endif //GRAPHMAKER_FACTORY_CONNECTED_H
