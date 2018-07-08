//
// Created by michele.da.rin on 08/07/2018.
//

#ifndef GOP_MAZZO_HPP
#define GOP_MAZZO_HPP


#include <vector>
#include "carta/Carta.hpp"

using namespace std;

class Mazzo {
    private:
        /// Carte che compongono il mazzo
        vector<Carta> carte;

    public:
        /// Costruttore
        /// @param carte Carte che compongono il mazzo
        Mazzo(vector<Carta> carte);
};


#endif //GOP_MAZZO_HPP
