//
// Created by michele.da.rin on 07/07/2018.
//

#ifndef GOP_GAME_HPP
#define GOP_GAME_HPP


class Game {
    private:
        /// Numero dei giocatori
        int numeroGiocatori;

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

        bool isGameEnded();
        void setGameEnded(bool gameEnded);

};


#endif //GOP_GAME_HPP
