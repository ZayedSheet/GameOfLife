project(A4)
set(CMAKE_CXX_STANDARD 11)
cmake_minimum_required(VERSION 2.6)

#Header Files
include_directories(include)
include_directories(catch)

#Executables
add_executable(gol src/View.cpp src/GameState.cpp experiment/main.cpp)
add_executable(test test/testmain.cpp test/testGameState.cpp  test/testView.cpp src/GameState.cpp src/View.cpp)