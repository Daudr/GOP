//
// Created by michele.da.rin on 07/07/2018.
//

#include <iostream>
#include "Game.hpp"

Game::Game() {
    std::cout << "Quanti giocatori: ";
    std::cin >> this->numeroGiocatori;

    this->startGame();
};

Game::Game(int giocatori) {
    this->startGame();
};

void Game::startGame() {
    while(!this->gameEnded) {
        // TODO: Inizializzare tabellone
        // TODO: Inizializzare mazzo di carte
        // TODO: Aggiungere logica per gestire i turni
    }
}

bool Game::isGameEnded() {
    return this->gameEnded;
};

void Game::setGameEnded(bool gameEnded) {
    this->gameEnded = gameEnded;
};