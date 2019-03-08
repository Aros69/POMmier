cmake_minimum_required(VERSION 3.13)
project(POMmier)

set(CMAKE_CXX_STANDARD 14)

add_executable(POMmier.exe src/main.cpp
        src/World/World.cpp
        include/World/World.h
        include/Sky/Sky.h
        include/Ground/Ground.h
        src/Resource/Resource.cpp
        include/Resource/Resource.h
        src/World/Square.cpp
        include/World/Square.h
        src/Vegetation/Vegetation.cpp
        include/Vegetation/Vegetation.h
        src/Ground/Soil/BasicSoil.cpp
        include/Ground/Soil/BasicSoil.h
        src/Ground/Ground.cpp
        include/Resource/BasicResource.h
        src/Vegetation/BasicVegetation.cpp
        include/Vegetation/BasicVegetation.h
        src/World/SquareArea.cpp
        include/World/SquareArea.h
        src/Controller/WorldController.cpp
        src/Controller/WorldController.h)

add_executable(POMmierWinTxt.exe src/mainWinTxt.cpp
        include/WinTxt/winTxt.h
        include/WinTxt/winTxt.cpp
        src/World/World.cpp
        include/World/World.h
        include/Sky/Sky.h
        include/Ground/Ground.h
        src/Resource/Resource.cpp
        include/Resource/Resource.h
        src/World/Square.cpp
        include/World/Square.h
        src/Vegetation/Vegetation.cpp
        include/Vegetation/Vegetation.h
        src/Ground/Soil/BasicSoil.cpp
        include/Ground/Soil/BasicSoil.h
        src/Ground/Ground.cpp
        include/Resource/BasicResource.h
        src/Vegetation/BasicVegetation.cpp
        include/Vegetation/BasicVegetation.h
        src/World/SquareArea.cpp
        include/World/SquareArea.h
        src/Controller/WorldController.cpp
        src/Controller/WorldController.h
        #src/View/WinTxt/JeuTXT.cpp
        #src/View/WinTxt/JeuTXT.h
        src/View/WinTxt/SimulationTxt.cpp
        src/View/WinTxt/SimulationTxt.h
        src/View/WinTxt/CompleteSquareAreaView.cpp
        src/View/WinTxt/CompleteSquareAreaView.h
        src/View/WinTxt/GenericView.h)