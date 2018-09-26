#ifndef GOP_CARTE_HPP
#define GOP_CARTE_HPP

#include "carta/Carta.hpp"

//TODO: è necessario usare per forza const?
// lasciandolo senza const in initMazzo si può
// facilmente eliminare la carte appena messa nel mazzo,
// così si evitano ripetizioni
vector<Carta> CARTE = {
        { "GEOGRAFIA: Quale continente contiene il maggior numero di paesi?",
				{"Europa", "Asia", "Sud America", "Africa", "Oceania"}, 3, Carta_Vuota
        },

		{ "GEOGRAFIA: Quale è la catena montuosa più lunga?",
				{"Ande", "Grande Catena Divisoria", "Urali","Himalaya","Montagne Rocciose"}, 0, Carta_Vuota
		},

		{ "GEOGRAFIA: Qual è il lago più esteso in superficie? (Tolto il Mar Caspio!)",
				{"Lago Baikal","Lago Vittoria","Lago Superiore","Lago Michigan","Lago Huron"}, 2, Carta_Vuota
		},

		{ "GEOGRAFIA: Qual è la città con più abitanti?",
				{"Città del Messico", "Tokyo", "Shanghai", "Seoul", "Delhi"}, 1, Carta_Vuota
		},

		{ "GEOGRAFIA: In quanti continenti c'è una città che si chiama Roma?",
				{"2","3","5","Tutti e 7","C'è solo una capitale"}, 3, Carta_Vuota
		},

		{ "GEOGRAFIA: Di quale stato è capitale Havana?",
				{"Cuba", "Colombia", "Messico", "Cile", "Perù"}, 0, Carta_Vuota
		},

		{ "GEOGRAFIA: In quale paese si trova il Salto Angel, la cascata con la più alta caduta al mondo?",
				{"Uganda", "Brasile", "Venezuela","Indonesia","Nepal"}, 2, Carta_Vuota
		},

		{ "GEOGRAFIA: Qual è il secondo stato più grande al mondo per superficie?",
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
