//
// Created by michele.da.rin on 08/07/2018.
//


#include "Casella.hpp"

Casella::Casella() {};

Casella::Casella(string testo, TipoCasella tipo) {
    this->testo = testo;
    this->tipo = tipo;
};

void Casella::eseguiAzione() {};

string Casella::getTesto() {
    return this->testo;
};

void Casella::setTesto(string testo) {
    this->testo = testo;
};

TipoCasella Casella::getTipoCasella() {
    return this->tipo;
};

void Casella::setTipoCasella(TipoCasella tipo) {
    this->tipo = tipo;
};


