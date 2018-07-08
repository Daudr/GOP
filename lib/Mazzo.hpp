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

        /// Rtorna le carte che compongono il mazzo
        vector<Carta> getCarte();

        /// Imposta le carte che compongono il mazzo
        /// @param carte Carte che compongono il mazzo
        void setCarte(vector<Carta> carte);
};


#endif //GOP_MAZZO_HPP
