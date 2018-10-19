cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_VERBOSE_MAKEFILE true)

project(my_game)

# About linking to PostgreSQL
# 1) CMake must be updated, module FindPostgreSQL must contains versions 10 and 10.5
# 2) CMake and PostgreSQL must be built on the same architecture (x86 or x64)

if(WIN32)
    set(PostgreSQL_TYPE_INCLUDE_DIR "C:/Program Files (x86)/PostgreSQL/10/include/server/catalog")
    set(PostgreSQL_INCLUDE_DIR "C:/Program Files (x86)/PostgreSQL/10/include")
    set(PostgreSQL_LIBRARY_DIR "C:/Program Files (x86)/PostgreSQL/10/lib")
    set(PostgreSQL_LIBRARY "C:/Program Files (x86)/PostgreSQL/10/lib/libpq.lib")
endif()
if(UNIX)
    set(PostgreSQL_TYPE_INCLUDE_DIR "")
    set(PostgreSQL_INCLUDE_DIR "")
    set(PostgreSQL_LIBRARY_DIR "")
    set(PostgreSQP_LIBRARY "")
endif()

find_package(PostgreSQL REQUIRED)

file(GLOB SOURCES
    *.cpp
    random/*.cpp
    classifier/src/*.cpp
    params/src/*.cpp
    item/src/*.cpp
    factory/src/*.cpp
)

include_directories(
    object
    random
    classifier/inc
    params/inc
    item/inc
    factory/inc
    ${PostgreSQL_INCLUDE_DIR}
)

link_directories(${PostgreSQL_LIBRARY_DIR})

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} pq)
