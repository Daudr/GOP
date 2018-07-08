//
// Created by michele.da.rin on 08/07/2018.
//

#ifndef GOP_CASELLASPOSTA_HPP
#define GOP_CASELLASPOSTA_HPP


#include "../Casella.hpp"

class CasellaSposta : public Casella {
    private:
        /// Numero delle caselle di cui spostarsi
        int spostamento;

    public:
        /// Costruttore
        /// @param spostamento Numero delle caselle di cui spostarsi
        CasellaSposta(int spostamento);

        /// Ritorna lo spostamento
        int getSpostamento();

        /// Imposta lo spostamento
        /// @param spostamento Numero delle caselle di cui spostarsi
        void setSpostamento(int spostamento);
};


#endif //GOP_CASELLASPOSTA_HPP
