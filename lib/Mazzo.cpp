//
// Created by michele.da.rin on 08/07/2018.
//

#include "Mazzo.hpp"

Mazzo::Mazzo(vector<Carta> carte) {
    this->carte = carte;
};

vector<Carta> Mazzo::getCarte() {
    return this->carte;
};

void Mazzo::setCarte(vector<Carta> carte) {
    this->carte = carte;
};