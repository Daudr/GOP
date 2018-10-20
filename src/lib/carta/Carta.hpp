//
// Created by michele.da.rin on 08/07/2018.
//

#ifndef GOP_CARTA_HPP
#define GOP_CARTA_HPP

#include <string>
#include <vector>

using namespace std;

enum TipoCarta {
	Carta_Vuota,
	Carta_PerdiTurno,
	Carta_DadoMagico,
	Carta_PescaCartaBlu,
	Carta_Indietro_5,
	Carta_Ritira,
	Carta_Scambia
};

class Carta {
    private:
        /// Testo della carta
        string testo = "";

        /// Opzioni della carta
        vector<string> opzioni = {};

        /// Indice della risposta giusta
        int corretta = 0;

        /// Tipo della carta
        TipoCarta tipo = Carta_Vuota;

    public:
        Carta();

        /// Costruttore
        /// @param testo Testo della carta
        /// @param opzioni Array delle opzioni
        /// @param corretta Indice della risposta giusta
        Carta(string testo, vector<string> opzioni, int corretta, TipoCarta tipo);

        /// Ritorna il testo della carta
        string getTesto();

        /// Imposta il testo della carta
        /// @param testo Testo della carta
        void setTesto(string testo);

        /// Ritorna le opzioni
        vector<string> getOpzioni();

        /// Imposta le opzioni
        /// @param opzioni Le opzioni della carta
        void setOpzioni(vector<string>);

        /// Ritorna l'indice dell'opzione giusta
        int getCorretta();

        /// Imposta l'indice dell'opzione giusta
        void setCorretta(int corretta);

        /// Ritorna il tipo della carta
        TipoCarta getTipoCarta();

};


#endif //GOP_CARTA_HPP
