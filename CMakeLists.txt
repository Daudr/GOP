cmake_minimum_required(VERSION 3.10)
project(gop)

set(CMAKE_CXX_STANDARD 11)

add_executable(gop main.cpp lib/Game.cpp lib/Game.hpp lib/giocatore/Giocatore.cpp lib/giocatore/Giocatore.hpp lib/Mazzo.cpp lib/Mazzo.hpp lib/carta/Carta.cpp lib/carta/Carta.hpp lib/tabellone/Tabellone.cpp lib/tabellone/Tabellone.hpp lib/casella/Casella.cpp lib/casella/Casella.hpp lib/casella/inizio/CasellaInizio.cpp lib/casella/inizio/CasellaInizio.hpp lib/casella/fine/CasellaFine.cpp lib/casella/fine/CasellaFine.hpp lib/casella/sposta/CasellaSposta.cpp lib/casella/sposta/CasellaSposta.hpp lib/casella/pesca/CasellaPesca.cpp lib/casella/pesca/CasellaPesca.hpp lib/casella/perdiTurni/CasellaPerdiTurni.cpp lib/casella/perdiTurni/CasellaPerdiTurni.hpp)