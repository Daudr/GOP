//
// Created by michele.da.rin on 08/07/2018.
//

#ifndef GOP_CARTA_HPP
#define GOP_CARTA_HPP

#include <string>

using namespace std;

class Carta {
    private:
        /// Testo della carta
        string testo;

    public:
        /// Costruttore
        /// @param testo Testo della carta
        Carta(string testo);

        /// Ritorna il testo della carta
        string getTesto();

        /// Imposta il testo della carta
        /// @param testo Testo della carta
        void setTesto(string testo);
};


#endif //GOP_CARTA_HPP
