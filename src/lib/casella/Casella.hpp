//
// Created by michele.da.rin on 08/07/2018.
//

#ifndef NEWCASELLA_HPP_
#define NEWCASELLA_HPP_

#include <string>
using namespace std;

enum TipoCasella {
	Vuota,
	Inizio,
	Fine,
	Sposta,
	PescaCarta,
	PerdiTurni,
	TornaInizio
};

struct casella {
	int posizione;
	string testo;
	TipoCasella tipo;
	casella *next;
};

///esegue azione in una casella speciale
///@param puntatore a casella
void eseguiAzione(casella *x);

/// Ritorna il testo della casella
/// @param puntatore a casella
string getTesto(casella *x);

/// Imposta il testo della casella
/// @param puntatore a casella
/// @param testo Testo della casella
void setTesto(casella *x, string testo);

/// Ritorna il tipo della casella
/// @param puntatore a casella
TipoCasella getTipoCasella(casella *x);

/// Imposta il tipo della casella
/// @param puntatore a casella
/// @param tipo della casella
void setTipoCasella(casella *x, TipoCasella tipo);


#endif /* NEWCASELLA_HPP_ */
