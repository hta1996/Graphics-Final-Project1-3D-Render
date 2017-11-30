cmake_minimum_required(VERSION 3.1)
project(3D-Render)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -pthread -Wl,--no-as-needed")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O2 -O3 -Wall")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

option(YAML_CPP_BUILD_TESTS OFF)

add_subdirectory(external/yamlcpp)

include_directories(external/yamlcpp/include)


add_subdirectory(src)
