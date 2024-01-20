//
// Created by macie on 1/20/2024.
//

#ifndef GRAPHMAKER_FACTORY_TREE_H
#define GRAPHMAKER_FACTORY_TREE_H


#include "factory.h"

class factory_tree : public factory
{
protected:

    factory_tree() = default;

public:

    factory& get_instance()
    {
        static factory_tree* instance = new factory_tree();
        return *instance;
    }

    virtual std::shared_ptr<graph> create(std::shared_ptr<graph> graph_ptr);

};

#endif //GRAPHMAKER_FACTORY_TREE_H
