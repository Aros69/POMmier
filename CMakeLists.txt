cmake_minimum_required(VERSION 3.13)
project(POMmier)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProjectDoGe src/main.cpp
        src/World/World.cpp
        include/World/World.h
        include/Sky/Sky.h
        include/Ground/Ground.h
        src/Resource/Resource.cpp
        include/Resource/Resource.h src/World/Square.cpp include/World/Square.h src/Vegetation/Vegetation.cpp include/Vegetation/Vegetation.h src/Ground/Soil/BasicSoil.cpp include/Ground/Soil/BasicSoil.h src/Ground/Ground.cpp include/Resource/BasicResource.h src/Vegetation/BasicVegetation.cpp include/Vegetation/BasicVegetation.h)