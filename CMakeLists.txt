cmake_minimum_required(VERSION 3.16)
project(GraphMaker)

set(CMAKE_CXX_STANDARD 20)

add_executable(GraphMaker main.cpp node.cpp node.h graph.cpp graph.h graph_maker.h
        builder.cpp
        builder.h
        add_command.cpp
        add_command.h)
