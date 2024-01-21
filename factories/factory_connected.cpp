//
// Created by macie on 1/20/2024.
//

#include "factory_connected.h"
#include "../decorators/graph_connected.h"

std::shared_ptr<graph> factory_connected::create(std::shared_ptr<graph> graph_ptr)
{
    return std::shared_ptr<graph>(new graph_connected(graph_ptr));
}