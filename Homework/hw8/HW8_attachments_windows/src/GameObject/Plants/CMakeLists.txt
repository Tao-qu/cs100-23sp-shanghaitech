cmake_minimum_required(VERSION 3.16)

add_library(
    Plants
    STATIC
    Plants.hpp
    Plants.cpp
    Sunflower.hpp
    Sunflower.cpp
    Peashooter.hpp
    Peashooter.cpp
    Wallnut.hpp
    Wallnut.cpp
    CherryBomb.hpp
    CherryBomb.cpp
    Repeater.hpp
    Repeater.cpp
)

target_link_libraries(
    Plants
    Framework
    GameObject
    GameWorld
)

target_include_directories(
    Plants
    PUBLIC 
    ${CMAKE_SOURCE_DIR}/src/
    ${CMAKE_SOURCE_DIR}/src/Framework/
    ${CMAKE_SOURCE_DIR}/src/GameWorld/
    ${CMAKE_SOURCE_DIR}/src/GameObject/
    ${CMAKE_SOURCE_DIR}/src/GameObject/Plants/
)