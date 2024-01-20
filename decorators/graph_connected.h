//
// Created by macie on 1/20/2024.
//

#ifndef GRAPHMAKER_GRAPH_CONNECTED_H
#define GRAPHMAKER_GRAPH_CONNECTED_H


#include "graph_decorator.h"

class graph_connected : public graph_decorator
{
protected:
    graph_connected(std::shared_ptr<graph> graph_ptr): graph_decorator(graph_ptr){}

public:
    graph_connected() = delete;

    virtual bool is_valid();

    friend class factory_connected;
};

#endif //GRAPHMAKER_GRAPH_CONNECTED_H
