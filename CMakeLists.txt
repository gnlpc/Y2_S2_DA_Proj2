cmake_minimum_required(VERSION 3.24)
project(trabalho2)

set(CMAKE_CXX_STANDARD 17)

add_executable(trabalho2 main.cpp
        Code/include/LoadFiles.h Code/include/LoadFiles.cpp
        Code/include/Graph.h Code/include/Graph.cpp
        Code/include/VertexEdge.h Code/include/VertexEdge.cpp
        Code/include/ToyGraph.h Code/include/ToyGraph.cpp
        Code/include/MutablePriorityQueue.h
        Code/include/Functions.h Code/include/Functions.cpp
        Code/include/app.h Code/include/app.cpp)
