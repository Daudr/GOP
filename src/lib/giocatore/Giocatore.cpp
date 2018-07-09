//
// Created by michele.da.rin on 07/07/2018.
//

#include <string>

#include "Giocatore.hpp"

Giocatore::Giocatore(std::string nome) {
    this->nome = nome;
};

std::string Giocatore::getNome() {
    return this->nome;
};

void Giocatore::setNome(std::string nome) {
    this->nome = nome;
};

int Giocatore::getPosizione() {
    return this->posizione;
};

void Giocatore::setPosizione(int posizione) {
    this->posizione = posizione;
};

int Giocatore::getFermo() {
    return this->fermo;
};

void Giocatore::setFermo(int fermo) {
    this->fermo = fermo;
};