/*
 * carte_bis.hpp
 *
 *  Created on: 24 set 2018
 *      Author: alexb
 */
//
#include <vector>
#include <string>
#include "carta/Carta.hpp"

using namespace std;

#ifndef LIB_CARTE_BIS_HPP_
#define LIB_CARTE_BIS_HPP_

const vector<Carta> CARTE_ROSSO = {
		{"Perdi Turno", {}, 0, Carta_PerdiTurno},
		{"Dado Magico", {}, 0, Carta_DadoMagico},
		{"Pesca Blu", {}, 0, Carta_PescaCartaBlu},
		{"Torna Indietro 5", {}, 0, Carta_Indietro_5},
		{"Ritira", {}, 0, Carta_Ritira},
		{"Scambia", {}, 0, Carta_Scambia}
};



#endif /* LIB_CARTE_BIS_HPP_ */
