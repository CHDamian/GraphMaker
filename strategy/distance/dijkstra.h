//
// Created by damia on 21.01.2024.
//

#ifndef GRAPHMAKER_DIJKSTRA_H
#define GRAPHMAKER_DIJKSTRA_H

#include "distance.h"

/**< Wyjatek wyrzucany w przypadku braku poczatkowego wierzcholka w grafie */
class negative_edge_in_graph_exception : public std::exception{
public:
    [[nodiscard]] const char *what() const noexcept override {
        return "Graph does not contain starting node!";
    }
};

class dijkstra : public distance
{
    void start(graph_t graph_ptr, distance_result_t result, int start_point);
    void detect_negative_edge(graph_t graph_ptr);

public:
    virtual distance_result_t execute(graph_t graph_ptr, int start_point);

    static dijkstra& get_instance()
    {
        static dijkstra* instance = new dijkstra();
        return *instance;
    }
};


#endif //GRAPHMAKER_DIJKSTRA_H
