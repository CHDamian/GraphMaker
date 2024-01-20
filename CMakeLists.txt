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
        command/adder_single_edge.h command/commands.h)
