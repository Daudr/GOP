//
// Created by michele.da.rin on 08/07/2018.
//

#ifndef GOP_CASELLA_HPP
#define GOP_CASELLA_HPP

#include <string>

using namespace std;

enum TipoCasella {
    Vuota,
    Inizio,
    Fine,
    Sposta,
    PescaCarta,
    PerdiTurni,
    TornaInizio
};

class Casella {
    protected:
        /// Testo della casella
        string testo = "Vuota";

        /// Tipo della casella;
        TipoCasella tipo = Vuota;

    public:
        /// Costuttore di default
        Casella();

        /// Costruttore
        /// @param testo Testo della casella
        /// @param tipo Tipo della casella
        Casella(string testo, TipoCasella tipo);

        /// Esegue l'azione in una casella speciale
        void eseguiAzione();

        /// Ritorna il testo della casella
        string getTesto();

        /// Imposta il testo della casella
        /// @param testo Testo della casella
        void setTesto (string testo);

        /// Ritorna il tipo della casella
        TipoCasella getTipoCasella();

        /// Imposta il tipo della casella
        /// @param tipo Tipo della casella
        void setTipoCasella(TipoCasella tipo);
};


#endif //GOP_CASELLA_HPP
