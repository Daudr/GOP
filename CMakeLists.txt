cmake_minimum_required(VERSION 3.10)
project(gop)

set(CMAKE_CXX_STANDARD 11)

add_executable(gop main.cpp lib/Game.cpp lib/Game.hpp lib/giocatore/Giocatore.cpp lib/giocatore/Giocatore.hpp)