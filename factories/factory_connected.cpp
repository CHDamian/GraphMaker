//
// Created by macie on 1/20/2024.
//

#include "factory_connected.h"
#include "../decorators/graph_connected.h"

/** @brief Pobierz wierzcholek.
         * Pobiera wierzcholek o podanym @param[in] id
         * @param[in] id - id pobieranego wierzcholka
         * @return Wierzcholek o podanym id
         *  bez zadnych konfilktow.
         */
std::shared_ptr<graph> factory_connected::create(std::shared_ptr<graph> graph_ptr)
{
    return std::shared_ptr<graph>(new graph_connected(graph_ptr));
}