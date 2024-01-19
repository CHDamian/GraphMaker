cmake_minimum_required(VERSION 3.16)
project(GraphMaker)

set(CMAKE_CXX_STANDARD 20)

add_executable(GraphMaker main.cpp node.cpp node.h graph.cpp graph.h graph_maker.h
        builder.cpp
        builder.h
        adder_command.cpp
        adder_command.h
        adder_node.cpp
        adder_node.h
        adder_edge.cpp
        adder_edge.h
        adder_single_edge.cpp
        adder_single_edge.h)
