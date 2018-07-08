//
// Created by michele.da.rin on 07/07/2018.
//

#include <iostream>

#include "Game.hpp"
#include "casella/inizio/CasellaInizio.hpp"
#include "casella/fine/CasellaFine.hpp"

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

        this->printGiocatoreCorrente();

        // Se il giocatore corrente è l'ultimo imposta l'indice del giocatore
        // successivo a 0
        this->setGiocatoreCorrente(this->giocatoreCorrente < this->numeroGiocatori ? this->giocatoreCorrente++ : 0);

        // Aspetta la pressione di un tasto per passare al turno successivo
        system("PAUSE");
    }
};

void Game::spostaGiocatore(int spostamento) {
    Giocatore giocatoreCorrente = this->giocatori.at(this->giocatoreCorrente);
    int posizioneCorrente = giocatoreCorrente.getPosizione();

    giocatoreCorrente.setPosizione(posizioneCorrente + spostamento);
};

int Game::tiraDadi() {
    return (rand() % 6 + 1) + (rand() % 6 + 1);
};

void Game::printGiocatoreCorrente() {
    cout << "Tocca a "
         << this->giocatori.at(this->giocatoreCorrente).getNome()
         << ", che si trova in posizione "
         << this->giocatori.at(this->giocatoreCorrente).getPosizione()
         << ".";
};

void Game::initTabellone() {
    int numeroCaselle = rand() % 41 + 60;

    this->tabellone.at(0) = new CasellaInizio();

    this->tabellone.at(numeroCaselle - 1) = new CasellaFine();

    // Generazione turni da aspettare
    // int turni = (rand() % 3 + 1);

};

vector<Giocatore> Game::getGiocatori() {
    return this->giocatori;
};

void Game::setGiocatori(vector<Giocatore> giocatori) {
    this->giocatori = giocatori;
};

int Game::getGiocatoreCorrente() {
    return this->giocatoreCorrente;
};

void Game::setGiocatoreCorrente(int giocatoreCorrente) {
    this->giocatoreCorrente = giocatoreCorrente;
};

bool Game::isGameEnded() {
    return this->gameEnded;
};

void Game::setGameEnded(bool gameEnded) {
    this->gameEnded = gameEnded;
};

vector<Casella *> Game::getTabellone() {
    return this->tabellone;
};

void Game::setTabellone(vector<Casella *> tabellone) {
    this->tabellone = tabellone;
};