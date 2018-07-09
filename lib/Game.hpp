//
// Created by michele.da.rin on 07/07/2018.
//

#ifndef GOP_GAME_HPP
#define GOP_GAME_HPP

#include <vector>
#include <string>

#include "giocatore/Giocatore.hpp"
#include "casella/Casella.hpp"

using namespace std;

class Game {
    private:
        /// Numero dei giocatori
        int numeroGiocatori;

        /// Array di giocatori
        vector<Giocatore> giocatori;

        /// Indice del giocatore corrente
        int giocatoreCorrente = 0;

        /// Array delle caselle che compongono il tabellone
        vector<Casella *> tabellone;

        /// Indica se il gioco è finito
        bool gameEnded = false;

    public:
        /// Costruttore di Default
        Game();
        
        /// Costruttore di default
        /// @param giocatori numero di giocatori
        Game(int giocatori);

        /// Fa partire il gioco con il primo turno
        void startGame ();

        /// Sposta un giocatore
        void spostaGiocatore(int spostamento);

        /// Simula il tiro di due dadi da 6 facce e lo spostamento del giocatore
        void tiraDadi();

        /// Stampa il nome e la posizione del giocatore corrente;
        void printGiocatoreCorrente();

        /// Inizializza le caselle che compongono il tabellone
        void initTabellone();

        /// Stampa il tabellone sulla console
        void printTabellone();

        /// Ritorna l'array del giocatore
        vector<Giocatore> getGiocatori();

        /// Imposta l'array dei giocatori
        /// @param giocatori Array dei giocaori
        void setGiocatori(vector<Giocatore> giocatori);

        /// Ritorna l'indice del giocatore corrente
        int getGiocatoreCorrente();

        /// Imposta l'indice del giocatore corrente
        /// @param giocatoreCorrente Indice del giocatore corrente
        void setGiocatoreCorrente(int giocatoreCorrente);

        /// Ritorna un booleano che inndica se il gioco è finito
        bool isGameEnded();

        /// Imposta il booleano che indica se il gioco è finito
        /// @param gameEnded Booleano che indica se il gioco è finito
        void setGameEnded(bool gameEnded);

        /// Ritorna l'array delle caselle che compongono il tabellone
        vector<Casella *> getTabellone();

        /// Imposta l'array delle caselle che compongono l'array del tabellone
        /// @param tabellone Array delle caselle che compongono il tabellone
        void setTabellone(vector<Casella *> tabellone);
};

#endif //GOP_GAME_HPP
