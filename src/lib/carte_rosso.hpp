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
		{"PerdiTurno", {}, 0, Carta_PerdiTurno},
		{"DadoMagico", {}, 0, Carta_DadoMagico},
		{"PescaCarta", {}, 0, Carta_PescaCarta},
		{"Sposta", {}, 0, Carta_Sposta},
		{"Ritira", {}, 0, Carta_Ritira},
		{"Scambia", {}, 0, Carta_Scambia}
};



#endif /* LIB_CARTE_BIS_HPP_ */
