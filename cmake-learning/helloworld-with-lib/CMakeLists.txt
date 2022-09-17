cmake_minimum_required(VERSION 3.17)

PROJECT(helloworld)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(swapper)

target_link_libraries(${PROJECT_NAME} swapper)
