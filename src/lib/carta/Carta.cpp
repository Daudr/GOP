//
// Created by michele.da.rin on 08/07/2018.
//

#include "Carta.hpp"

Carta::Carta(){
	this->testo = " ";
	this->opzioni = {};
	this->corretta = 0;
	this->tipo = Carta_Vuota;
};

Carta::Carta(string testo, vector<string> opzioni, int corretta, TipoCarta tipo) {
    this->testo = testo;
    this->opzioni = opzioni;
    this->corretta = corretta;
    this->tipo = tipo;
};

string Carta::getTesto() {
    return this->testo;
};

void Carta::setTesto(string testo) {
    this->testo = testo;
};

vector<string> Carta::getOpzioni() {
    return this->opzioni;
};

void Carta::setOpzioni(vector<string>) {
    this->opzioni = opzioni;
};

int Carta::getCorretta() {
    return this->corretta;
};

void Carta::setCorretta(int corretta) {
    this->corretta = corretta;
};

TipoCarta Carta::getTipoCarta(){
	return this->tipo;
}
