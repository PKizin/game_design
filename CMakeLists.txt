cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
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
    domain/random/*.cpp
    domain/classifier/src/*.cpp
    domain/creature/src/*.cpp
    domain/params/src/*.cpp
    domain/item/src/*.cpp
    domain/item_container/*.cpp
    domain/factory/src/*.cpp
    domain/strategy/src/*.cpp
    database/*.cpp
)

include_directories(
    domain/object
    domain/random
    domain/classifier/inc
    domain/creature/inc
    domain/params/inc
    domain/item/inc
    domain/item_container/inc
    domain/factory/inc
    domain/strategy/inc
    database/
    ${PostgreSQL_INCLUDE_DIR}
)

link_directories(${PostgreSQL_LIBRARY_DIR})

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} pq)
