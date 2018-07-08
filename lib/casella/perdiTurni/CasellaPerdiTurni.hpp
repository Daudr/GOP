//
// Created by michele.da.rin on 08/07/2018.
//

#ifndef GOP_CASELLAPERDITURNI_HPP
#define GOP_CASELLAPERDITURNI_HPP


#include "../Casella.hpp"

class CasellaPerdiTurni : public Casella {
    private:
        /// Turni in cui il giocatore deve stare fermo
        int turni;

    public:
        /// Costruttore
        /// @param turni Turni in cui il giocatore deve stare fermo;
        CasellaPerdiTurni(int turni);
};


#endif //GOP_CASELLAPERDITURNI_HPP