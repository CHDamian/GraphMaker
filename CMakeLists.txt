cmake_minimum_required(VERSION 3.16)
project(GraphMaker)

set(CMAKE_CXX_STANDARD 20)

add_executable(GraphMaker main.cpp node.cpp node.h graph.cpp graph.h graph_maker.h
        builder.cpp
        builder.h
        command/adder_command.cpp
        command/adder_command.h
        command/adder_node.cpp
        command/adder_node.h
        command/adder_edge.cpp
        command/adder_edge.h
        command/adder_single_edge.cpp
        command/adder_single_edge.h
        decorators/graph_decorator.cpp
        decorators/graph_decorator.h
        decorators/graph_connected.cpp
        decorators/graph_connected.h
        decorators/graph_tree.cpp
        decorators/graph_tree.h
        decorators/graph_positive.cpp
        decorators/graph_positive.h
        factories/factory.cpp
        factories/factory.h
        factories/factory_tree.cpp
        factories/factory_tree.h
        factories/factory_connected.cpp
        factories/factory_connected.h
        factories/factory_positive.cpp
        factories/factory_positive.h
        command/commands.h
        graph_facade.cpp
        graph_facade.h
        strategy/distance/distance.cpp
        strategy/distance/distance.h
        strategy/traversing/traversing.cpp
        strategy/traversing/traversing.h
        strategy/distance/distance_result.cpp
        strategy/distance/distance_result.h)
