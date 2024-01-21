//
// Created by macie on 1/20/2024.
//

#ifndef GRAPHMAKER_FACTORY_H
#define GRAPHMAKER_FACTORY_H
#include "memory"
#include "../graph.h"


class factory{

protected:

    factory();

public:

    virtual std::shared_ptr<graph> create(std::shared_ptr<graph> graph_ptr) = 0;
};

#endif //GRAPHMAKER_FACTORY_H
