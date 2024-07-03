cmake_minimum_required(VERSION 3.16)

add_library(
  Sun
  STATIC
  Sun.hpp
  Sun.cpp
  SkySun.hpp
  SkySun.cpp
  FlowerSun.hpp
  FlowerSun.cpp
)

target_link_libraries(
  Sun  
  Framework
  GameObject
  GameWorld
)

target_include_directories(
  Sun
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/src/Framework/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameObject/Sun/
)