cmake_minimum_required(VERSION 3.16)
project(GraphMaker)

set(CMAKE_CXX_STANDARD 20)

add_executable(GraphMaker main.cpp node.cpp node.h graph.cpp graph.h graph_maker.h
        builder.cpp
        builder.h
        add_command.cpp
        add_command.h
        Add_node.cpp
        Add_node.h
        add_edge.cpp
        add_edge.h
        add_single_edge.cpp
        add_single_edge.h)
