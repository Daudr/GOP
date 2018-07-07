//
// Created by michele.da.rin on 07/07/2018.
//

#ifndef GOP_GIOCATORE_HPP
#define GOP_GIOCATORE_HPP


class Giocatore {
    private:
        string nome;

    public:
        Giocatore (string name);

        string getNome();

        void setNome (string nome);
};


#endif //GOP_GIOCATORE_HPP
