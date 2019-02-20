cmake_minimum_required(VERSION 3.13)
project(ProjectDoGe)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProjectDoGe src/main.cpp
        src/World/World.cpp
        include/World/World.h
        include/Sky/Sky.h
        include/Ground/Ground.h
        src/Ressource/Ressource.cpp
        include/Ressource/Ressource.h src/World/Square.cpp include/World/Square.h)