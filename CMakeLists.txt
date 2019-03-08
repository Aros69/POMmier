cmake_minimum_required(VERSION 3.13)
project(POMmier)

set(CMAKE_CXX_STANDARD 14)

add_executable(POMmier.exe src/main.cpp
        src/Model/World/World.cpp
        src/Model/World/World.h
        src/Model/Sky/Sky.h
        src/Model/Ground/Ground.h
        src/Model/Resource/Resource.cpp
        src/Model/Resource/Resource.h
        src/Model/World/Square.cpp
        src/Model/World/Square.h
        src/Model/Vegetation/Vegetation.cpp
        src/Model/Vegetation/Vegetation.h
        src/Model/Ground/Soil/BasicSoil.cpp
        src/Model/Ground/Soil/BasicSoil.h
        src/Model/Ground/Ground.cpp
        src/Model/Resource/BasicResource.h
        src/Model/Vegetation/BasicVegetation.cpp
        src/Model/Vegetation/BasicVegetation.h
        src/Model/World/SquareArea.cpp
        src/Model/World/SquareArea.h
        src/Controller/WorldController.cpp
        src/Controller/WorldController.h)

add_executable(POMmierWinTxt.exe src/mainWinTxt.cpp
        include/WinTxt/winTxt.h
        include/WinTxt/winTxt.cpp
        src/Model/World/World.cpp
        src/Model/World/World.h
        src/Model/Sky/Sky.h
        src/Model/Ground/Ground.h
        src/Model/Resource/Resource.cpp
        src/Model/Resource/Resource.h
        src/Model/World/Square.cpp
        src/Model/World/Square.h
        src/Model/Vegetation/Vegetation.cpp
        src/Model/Vegetation/Vegetation.h
        src/Model/Ground/Soil/BasicSoil.cpp
        src/Model/Ground/Soil/BasicSoil.h
        src/Model/Ground/Ground.cpp
        src/Model/Resource/BasicResource.h
        src/Model/Vegetation/BasicVegetation.cpp
        src/Model/Vegetation/BasicVegetation.h
        src/Model/World/SquareArea.cpp
        src/Model/World/SquareArea.h
        src/Controller/WorldController.cpp
        src/Controller/WorldController.h
        #src/View/WinTxt/JeuTXT.cpp
        #src/View/WinTxt/JeuTXT.h
        src/View/WinTxt/SimulationTxt.cpp
        src/View/WinTxt/SimulationTxt.h
        src/View/WinTxt/CompleteSquareAreaView.cpp
        src/View/WinTxt/CompleteSquareAreaView.h
        src/View/WinTxt/GenericView.h)