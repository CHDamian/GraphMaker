//
// Created by damia on 21.01.2024.
//

#ifndef GRAPHMAKER_BELLMAN_FORD_H
#define GRAPHMAKER_BELLMAN_FORD_H


#include "distance.h"

class negative_cycle_exception : public std::exception{
public:
    [[nodiscard]] const char *what() const noexcept override {
        return "Graph does not contain starting node!";
    }
};

class bellman_ford : public distance
{
    void bellman_ford_cycle(graph_t graph_ptr, distance_result_t result);
    void detect_negative_cycle(graph_t graph_ptr, distance_result_t result);

public:
    virtual distance_result_t execute(graph_t graph_ptr, int start_point);

    static bellman_ford& get_instance()
    {
        static bellman_ford* instance = new bellman_ford();
        return *instance;
    }
};


#endif //GRAPHMAKER_BELLMAN_FORD_H
