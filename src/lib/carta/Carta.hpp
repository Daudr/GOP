//
// Created by michele.da.rin on 08/07/2018.
//

#ifndef GOP_CARTA_HPP
#define GOP_CARTA_HPP

#include <string>
#include <vector>

using namespace std;

class Carta {
    private:
        /// Testo della carta
        string testo;

        /// Opzioni della carta
        vector<string> opzioni;

        /// Indice della risposta giusta
        int corretta;

    public:
        Carta();

        /// Costruttore
        /// @param testo Testo della carta
        /// @param opzioni Array delle opzioni
        /// @param corretta Indice della risposta giusta
        Carta(string testo, vector<string> opzioni, int corretta);

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
};


#endif //GOP_CARTA_HPP
