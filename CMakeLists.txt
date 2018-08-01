cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 14)

project(my_game)

file(GLOB SOURCES
    *.h
    *.cpp
    classifier/*.cpp
)

include_directories(
    classifier
)

add_executable(${PROJECT_NAME} ${SOURCES})