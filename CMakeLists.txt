cmake_minimum_required(VERSION 3.10)
project(gop)

set(CMAKE_CXX_STANDARD 11)

add_executable(gop main.cpp lib/Game.cpp lib/Game.hpp lib/giocatore/Giocatore.cpp lib/giocatore/Giocatore.hpp lib/Mazzo.cpp lib/Mazzo.hpp lib/carta/Carta.cpp lib/carta/Carta.hpp lib/tabellone/Tabellone.cpp lib/tabellone/Tabellone.hpp)