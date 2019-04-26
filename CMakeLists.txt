cmake_minimum_required(VERSION 3.13)
project(POMmier)

set(CMAKE_CXX_STANDARD 14)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

# Create the list of src files for gkit
# Not reccomended practice by cmake developer
file(GLOB_RECURSE MODEL_SRC_FILES
        "src/Model/*")

add_executable(POMmier.exe src/main.cpp
        ${MODEL_SRC_FILES}
        src/Controller/WorldController.cpp
        src/Controller/WorldController.h)

add_executable(POMmierWinTxt.exe src/mainWinTxt.cpp
        include/WinTxt/winTxt.h
        include/WinTxt/winTxt.cpp
        ${MODEL_SRC_FILES}
        src/Controller/WorldController.cpp
        src/Controller/WorldController.h
        src/View/WinTxt/SimulationTxt.cpp
        src/View/WinTxt/SimulationTxt.h
        src/View/WinTxt/CompleteSquareAreaView.cpp
        src/View/WinTxt/CompleteSquareAreaView.h
        src/View/WinTxt/GenericView.h
        src/View/WinTxt/SquareView.cpp
        src/View/WinTxt/SquareView.h)


# Find the QtWidgets library
find_package(Qt5Widgets CONFIG REQUIRED)

add_executable(POMmierQt.exe src/mainQt.cpp
        ${MODEL_SRC_FILES} src/View/Qt/SimulationQT.h src/Model/QtModel/SimulationModel.cpp src/Model/QtModel/SimulationModel.h src/Model/QtModel/QtVegetation.cpp src/Model/QtModel/QtVegetation.h src/View/Qt/SimulationQT.cpp src/View/Qt/QtVegetationView.cpp src/View/Qt/QtVegetationView.h)

target_link_libraries(POMmierQt.exe Qt5::Widgets)