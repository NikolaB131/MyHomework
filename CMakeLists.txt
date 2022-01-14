cmake_minimum_required(VERSION 3.17)
project(MyHomework)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(MyHomework main.cpp QueryPerformanceCounter.cpp 2SiAOD_2/2SiAOD_2.cpp 2SiAOD_2/HashTable.cpp 2SiAOD_2/TableAndFileManager.cpp 2SiAOD_5/2SiAOD_5.cpp 2SiAOD_5/Graph.cpp)