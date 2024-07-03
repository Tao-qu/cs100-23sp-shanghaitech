cmake_minimum_required(VERSION 3.16)

add_library(
  GameWorld
  STATIC
  GameWorld.hpp
  GameWorld.cpp
)

target_link_libraries(
  GameWorld
  Framework
  GameObject
  Background
  PlantingSpot
  Plants
  Projectiles
  Seeds
  Sun
  Zombies
)

target_include_directories(
  GameWorld
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/src/Framework/
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameObject/Background/
  ${CMAKE_SOURCE_DIR}/src/GameObject/PlantingSpot/
  ${CMAKE_SOURCE_DIR}/src/GameObject/Plants/
  ${CMAKE_SOURCE_DIR}/src/GameObject/Projectiles/
  ${CMAKE_SOURCE_DIR}/src/GameObject/Seeds/
  ${CMAKE_SOURCE_DIR}/src/GameObject/Sun/
  ${CMAKE_SOURCE_DIR}/src/GameObject/Zombies/
)
