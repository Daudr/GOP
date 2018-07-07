//
// Created by michele.da.rin on 07/07/2018.
//

#ifndef GOP_GAME_HPP
#define GOP_GAME_HPP


class Game {
    private:
        int numeroGiocatori;
        bool gameEnded = false;

    public:
        Game();
        Game(int giocatori);

        void startGame ();

        bool isGameEnded();
        void setGameEnded(bool gameEnded);

};


#endif //GOP_GAME_HPP
