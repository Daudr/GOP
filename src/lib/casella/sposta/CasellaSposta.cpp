//
// Created by michele.da.rin on 08/07/2018.
//

#include "CasellaSposta.hpp"

#include <string>
#include <sstream>

using namespace std;

CasellaSposta::CasellaSposta(int spostamento) {
    stringstream ss;
    if (spostamento < 0) {
        ss << "Spostati indietro di " << spostamento << " caselle";
    } else {
        ss << "Spostati avanti di " << spostamento << " caselle";
    }

    this->spostamento = spostamento;
    this->setTesto(ss.str());
    this->setTipoCasella(Sposta);
};

int CasellaSposta::getSpostamento() {
    return this->spostamento;
};

void CasellaSposta::setSpostamento(int spostamento) {
    this->spostamento = spostamento;
};