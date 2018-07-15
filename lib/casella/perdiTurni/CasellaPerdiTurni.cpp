//
// Created by michele.da.rin on 08/07/2018.
//

#include "CasellaPerdiTurni.hpp"

CasellaPerdiTurni::CasellaPerdiTurni(int turni) {
    // int turni = rand() % 0 + 3;
};

int CasellaPerdiTurni::getTurni() {
    return this->turni;
};

void CasellaPerdiTurni::setTurni(int turni) {
    this->turni = turni;
};