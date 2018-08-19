#ifndef GOP_CARTE_HPP
#define GOP_CARTE_HPP

#include "carta/Carta.hpp"

//TODO: è necessario usare per forza const?
// lasciandolo senza const in initMazzo si può
// facilmente eliminare la carte appena messa nel mazzo,
// così si evitano ripetizioni
vector<Carta> CARTE = {
        {
            "Quanto fa 1 + 1?",
            { "1", "2", "0", "4" }, 2
        },
        {
        		"GEOGRAFIA: Quale continente contiene il maggior numero di paesi?",
				{"Europa", "Asia", "Sud America", "Africa", "Oceania"}, 3
        },


//        { "3", {}, 0 },
//        { "4", {}, 0 },
//        { "5", {}, 0 },
//        { "6", {}, 0 },
//        { "7", {}, 0 },
//        { "8", {}, 0 },
//        { "9", {}, 0 }
//        {string "Testo", {vect<string> opzioni}, int corretta },
};

#endif //GOP_CARTE_HPP
