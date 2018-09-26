#ifndef GOP_CARTE_HPP
#define GOP_CARTE_HPP

#include "carta/Carta.hpp"

//TODO: � necessario usare per forza const?
// lasciandolo senza const in initMazzo si pu�
// facilmente eliminare la carte appena messa nel mazzo,
// cos� si evitano ripetizioni
vector<Carta> CARTE = {
        { "GEOGRAFIA: Quale continente contiene il maggior numero di paesi?",
				{"Europa", "Asia", "Sud America", "Africa", "Oceania"}, 3, Carta_Vuota
        },

		{ "GEOGRAFIA: Quale � la catena montuosa pi� lunga?",
				{"Ande", "Grande Catena Divisoria", "Urali","Himalaya","Montagne Rocciose"}, 0, Carta_Vuota
		},

		{ "GEOGRAFIA: Qual � il lago pi� esteso in superficie? (Tolto il Mar Caspio!)",
				{"Lago Baikal","Lago Vittoria","Lago Superiore","Lago Michigan","Lago Huron"}, 2, Carta_Vuota
		},

		{ "GEOGRAFIA: Qual � la citt� con pi� abitanti?",
				{"Citt� del Messico", "Tokyo", "Shanghai", "Seoul", "Delhi"}, 1, Carta_Vuota
		},

		{ "GEOGRAFIA: In quanti continenti c'� una citt� che si chiama Roma?",
				{"2","3","5","Tutti e 7","C'� solo una capitale"}, 3, Carta_Vuota
		},

		{ "GEOGRAFIA: Di quale stato � capitale Havana?",
				{"Cuba", "Colombia", "Messico", "Cile", "Per�"}, 0, Carta_Vuota
		},

		{ "GEOGRAFIA: In quale paese si trova il Salto Angel, la cascata con la pi� alta caduta al mondo?",
				{"Uganda", "Brasile", "Venezuela","Indonesia","Nepal"}, 2, Carta_Vuota
		},

		{ "GEOGRAFIA: Qual � il secondo stato pi� grande al mondo per superficie?",
				{"Cina", "Stati Uniti d'America", "Canada", "Brasile", "Australia"}, 2, Carta_Vuota
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
