//
// Created by michele.da.rin on 07/07/2018.
//

#ifndef GOP_GAME_HPP
#define GOP_GAME_HPP

#include <vector>
#include <string>

#include "utils.hpp"

#include "giocatore/Giocatore.hpp"
#include "casella/Casella.hpp"
#include "carta/Carta.hpp"

using namespace std;

struct Mazzo {
	Carta carta = Carta();
	Mazzo* next;
};

class Game {
    private:
        /// Numero dei giocatori
        int numeroGiocatori = 0;

        /// Array di giocatori
        vector<Giocatore *> giocatori;

        /// Indice del giocatore corrente
        int giocatoreCorrente = 0;

        /// Array delle caselle che compongono il tabellone
        vector<Casella *> tabellone;

        /// Puntatore alla lista delle carte che compongono il mazzo di domande
        Mazzo* mazzo = NULL;

        /// Puntatore alla liste delle carte che compongono il mazzo di bonus e penalità
        Mazzo* mazzo_rosso = NULL;

        /// Indica se il gioco Ã¨ finito
        bool gameEnded = false;

    public:
        /// Costruttore di Default
        Game();
        
        /// Costruttore di default
        /// @param giocatori numero di giocatori
        Game(int giocatori);

        /// Fa partire il gioco con il primo turno
        void startGame ();

        /// Finisce il gioco
        void endGame ();

        /// Sposta il giocatore
        void spostaGiocatore(int spostamento);

        /// Simula il tiro di due dadi da 6 facce e lo spostamento del giocatore
        void tiraDadi();

        /// Simula il tiro di un dado da 6 facce, senza spostamento
        int tiraDado_nospost();

        /// Sposta il giocatore. Funzione per la casella
        void sposta();

        /// Scambia la posizione di due giocatori
        void scambiaGiocatori();

        /// Il giocatore perde un numero di turni casuale
        void perdiTurni();

        /// Lancia il dado. Se pari va avanti di 2, se dispari va indietro di 3
        void DadoMagico();

        /// Stampa il nome e la posizione del giocatore corrente;
        void printGiocatoreCorrente();

        /// Inizializza le caselle che compongono il tabellone
        void initTabellone();

        /// Stampa il tabellone sulla console
        void printTabellone();

        /// Inizializza il mazzo delle domande
        void initMazzo();

        /// Inizializza il mazzo dei bonus e delle penalità
        void initMazzo_Rosso();

        /// Pesca una carta dal mazzo
        void pescaCarta_blu();

        /// Pesca una carta dal mazzo bonus e penalità
        void pescaCarta_rosso();

        /// Fa tornare un giocatore alla prima casella
        void tornaInizio();

        /// Ritorna l'array del giocatore
        vector<Giocatore *> getGiocatori();

        /// Imposta l'array dei giocatori
        /// @param giocatori Array dei giocaori
        void setGiocatori(vector<Giocatore *> giocatori);

        /// Ritorna l'indice del giocatore corrente
        int getGiocatoreCorrente();

        /// Imposta l'indice del giocatore corrente
        /// @param giocatoreCorrente Indice del giocatore corrente
        void setGiocatoreCorrente(int giocatoreCorrente);

        /// Ritorna un booleano che inndica se il gioco Ã¨ finito
        bool isGameEnded();

        /// Imposta il booleano che indica se il gioco Ã¨ finito
        /// @param gameEnded Booleano che indica se il gioco Ã¨ finito
        void setGameEnded(bool gameEnded);

        /// Ritorna l'array delle caselle che compongono il tabellone
        vector<Casella *> getTabellone();

        /// Imposta l'array delle caselle che compongono l'array del tabellone
        /// @param tabellone Array delle caselle che compongono il tabellone
        void setTabellone(vector<Casella *> tabellone);

        /// Ritorna l'array che compongono il mazzo
        vector<Carta> getMazzo();

        /// Imposta l'array delle carte che compongono il mazzo
        void setMazzo(Mazzo* pointer);
};

#endif //GOP_GAME_HPP
