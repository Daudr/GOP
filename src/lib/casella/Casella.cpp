//
// Created by michele.da.rin on 08/07/2018.
//

#include "Casella.hpp"

#include <string>
using namespace std;

void eseguiAzione(casella *x){};

string getTesto(casella *x){
	return x->testo;
};

void setTesto(casella *x, string testo){
	x->testo = testo;
};

TipoCasella getTipoCasella(casella *x){
	return x->tipo;
};

void setTipoCasella(casella *x, TipoCasella tipo){
	x->tipo = tipo;
};
