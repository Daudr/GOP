//
// Created by michele.da.rin on 07/07/2018.
//

#ifndef GOP_GIOCATORE_HPP
#define GOP_GIOCATORE_HPP

#include <string>

using namespace std;

class Giocatore {
    private:
        /// Nome del giocatore
        string nome;

        /// Posizione del giocatore nel tabellone
        int posizione;

    public:
        /// Costruttore
        /// @param name Nome del giocatore
        Giocatore (string name);

        /// Ritorna il nome del giocatore
        /// @return Nome del giocatore
        string getNome();

        /// Imposta il nome del giocatore
        /// @param nome Nome del giocatore
        void setNome (string nome);

        /// Ritorna la posizione del giocatore nel tabellone
        int getPosizione();

        /// Imposta la posizione del giocatore nel tabellone
        /// @param posizione Posizione del giocatore
        void setPosizione(int posizione);
};


#endif //GOP_GIOCATORE_HPP
