cmake_minimum_required(VERSION 3.16)

add_library(
  Seeds
  STATIC
  Seeds.hpp
  Seeds.cpp
  SunflowerSeed.hpp
  SunflowerSeed.cpp
  PeashooterSeed.hpp
  PeashooterSeed.cpp
  WallnutSeed.hpp
  WallnutSeed.cpp
  CherryBombSeed.hpp
  CherryBombSeed.cpp
  RepeaterSeed.hpp
  RepeaterSeed.cpp
  Shovel.hpp
  Shovel.cpp
  CooldownMask.hpp
  CooldownMask.cpp
)

target_link_libraries(
  Seeds  
  Framework
  GameObject
  GameWorld
)

target_include_directories(
  Seeds
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/src/Framework/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameObject/Seeds/
)