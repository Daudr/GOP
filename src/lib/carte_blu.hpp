#ifndef GOP_CARTE_HPP
#define GOP_CARTE_HPP

#include "carta/Carta.hpp"

//TODO: è necessario usare per forza const?
// lasciandolo senza const in initMazzo si può
// facilmente eliminare la carte appena messa nel mazzo,
// così si evitano ripetizioni

//        {string "Testo", {vect<string> opzioni}, int corretta, TipoCarta tipo },

vector<Carta> CARTE = {
        { "MAPPAMONDO: Quale continente contiene il maggior numero di paesi?",
				{"Europa", "Asia", "Sud America", "Africa", "Oceania"}, 3, Carta_Vuota
        },

		{ "MAPPAMONDO: Quale è la catena montuosa più lunga?",
				{"Ande", "Grande Catena Divisoria", "Urali","Himalaya","Montagne Rocciose"}, 0, Carta_Vuota
		},

		{ "MAPPAMONDO: Qual è il lago più esteso in superficie? (Tolto il Mar Caspio!)",
				{"Lago Baikal","Lago Vittoria","Lago Superiore","Lago Michigan","Lago Huron"}, 2, Carta_Vuota
		},

		{ "MAPPAMONDO: Qual è la città con più abitanti?",
				{"Città del Messico", "Tokyo", "Shanghai", "Seoul", "Delhi"}, 1, Carta_Vuota
		},

		{ "MAPPAMONDO: In quanti continenti c'è una città che si chiama Roma?",
				{"2","3","5","Tutti e 7","C'è solo una capitale"}, 3, Carta_Vuota
		},

		{ "MAPPAMONDO: Di quale stato è capitale Havana?",
				{"Cuba", "Colombia", "Messico", "Cile", "Perù"}, 0, Carta_Vuota
		},

		{ "MAPPAMONDO: In quale paese si trova il Salto Angel, la cascata con la più alta caduta al mondo?",
				{"Uganda", "Brasile", "Venezuela","Indonesia","Nepal"}, 2, Carta_Vuota
		},

		{ "MAPPAMONDO: Qual è il secondo stato più grande al mondo per superficie?",
				{"Cina", "Stati Uniti d'America", "Canada", "Brasile", "Australia"}, 2, Carta_Vuota
		},

		{ "STORIA: Quante mogli ha avuto Enrico VIII?",
				{"6", "2", "14", "4", "9"}, 0, Carta_Vuota
		},

		{ "STORIA: Quanti governi diversi ha avuto la Repubblica Italiana?",
				{"65", "18", "23", "31", "40"}, 0, Carta_Vuota
		},

		{ "STORIA: Le ultime parole di quali di questi fisici non sono state capite perché la sua infermiera non parlava tedesco?",
				{"Max Planck", "Werner Heisenberg", "Carl Friedrich Gauss", "Erwin Schrodinger", "Albert Einstein"}, 4, Carta_Vuota
		},

		{ "STORIA: Quale è il paese più giovane al mondo?",
				{"Kosovo", "Israele", "Repubblica Ceca", "Sud Sudan", "Moldavia"}, 3, Carta_Vuota
		},

		{ "STORIA: Come si chiama la compagnia privata che per prima ha fatto un volo orbitale?",
				{"SpaceX", "Scaled Composities", "Airbus", "Boeing", "Dassaul Aviation"}, 1, Carta_Vuota
		},

		{ "STORIA: Di quale paese è leader il Principe Alberto II Grimaldi?",
				{"Svezia", "Monaco", "Spagna", "Portogallo", "Lussenburgo"}, 1, Carta_Vuota
		},

		{ "STORIA: Quale era il nome della residenza di Napoleone Bonaparte durante il suo esilio sull'Isola di Sant'Elena?",
				{"Dunleith", "Chateau de Rambouillet", "Longwood House", "Monticello", "Casa Del Popolo"}, 2, Carta_Vuota
		},

		{ "STORIA: Quale di queste città non è mai esistita?",
				{"Leningrado", "Troskygrad", "Stalingrad", "Kaliningrad", "Togliattigrad"}, 1, Carta_Vuota
		},

		{ "ZOO: Quale tra questi felini è il più grande?",
				{"Ghepardo", "Leopardo", "Leone", "Tigre", "Leopardo delle nevi"}, 3, Carta_Vuota
		},

		{ "ZOO: Quale tra queste balene emette il suono più forte?",
				{"Balenottera Azzura", "Squalo Balena", "Megattera", "Capodoglio", "Iperodonte Australe"}, 0, Carta_Vuota
		},

		{ "ZOO: Come si dice un grande gruppo di canguri?",
				{"Mandria", "Gregge", "Orda", "Branco", "Banda"}, 2, Carta_Vuota
		},

		{ "ZOO: Che forma hanno le pupille delle capre?",
				{"Cerchio", "Ovale", "Rettangolo", "Triangolo", "Rombo"}, 2, Carta_Vuota
		},

		{ "ZOO: Quale è il serpente più velenoso al mondo?",
				{"Serpente Bruno Orientale", "Taipan Occidentale", "Mamba Nero", "Cobra delle Filippine", "Vipera di Russell"}, 2, Carta_Vuota
		},

		{ "ZOO: Quale di questi animali è il più longevo?",
				{"Elefante", "Balenottera Azzurra", "Tartaruga Gigante", "Anaconda", "Locusta"}, 2, Carta_Vuota
		},

		{ "ZOO: Qual è l'uccello più veloce al mondo?",
				{"Aquila Arpia", "Falco Pellegrino", "Colibrì Cornuto", "Rondone Codaspina", "Grande Gufo Cornuto"}, 1, Carta_Vuota
		},

		{ "SPOTIFY: Quale di questi inventori creò la chitarra elettrica?",
				{"Orville Gibson", "Jim Marshall", "Clarence Leonidas Fender", "Les Paul", "Grover Jackson"}, 3, Carta_Vuota
		},

		{ "SPOTIFY: Da quale di questi cantanti è stata scritta 'Hallelujah'?",
				{"John Cale", "John Lennon", "Leonard Cohen", "Jeff Buckely", "Ben E. King"}, 2, Carta_Vuota
		},

		{ "SPOTIFY: Quale di questi artisti non ha mai vinto il Festival di Sanremo?",
				{"Eros Ramazzotti", "Elio e Le Storie Tese", "Romina Power", "Iva Zanicchi", "Marco Masini"}, 1, Carta_Vuota
		},

		{ "SPOTIFY: Chi scrisse la famosa canzone per piano 'Fur Elise' (per Elisa)?",
				{"Beethoven", "Bach", "Chopin", "Mozart", "Tchaikovsky"}, 0, Carta_Vuota
		},

		{ "SPOTIFY: L'orchestra di quale paese è più numerosa del suo esercito?",
				{"Lussemburgo", "Germania", "Estonia", "Principato di Monaco", "Lichtenstein"}, 3, Carta_Vuota
		},

		{ "SPOTIFY: Di che nazionalità era Wolfgang Amadeus Mozart?",
				{"Austriaca", "Svizzera", "Ungheresa", "Tedesca", "Polacca"}, 0, Carta_Vuota
		},

		{ "SPOTIFY: Come è morto Jeff Buckley, famoso interprete (ma non scrittore) di Halleluja?",
				{"Attacco cardiaco", "Annegamento nel Mississipi", "Incidente stradale", "Suicidio", "Sparato da un fan"}, 1, Carta_Vuota
		},

		{ "NETFLICS: In che anno il film 'Jurassic Park' è uscito al cinema?",
				{"1993", "1996", "2002", "1990", "1991"}, 0, Carta_Vuota
		},

		{ "NETFLICS: Quale di questi supereroi NON è stato creato dalla DC Comics?",
				{"Flash", "Wonder Woman", "Lanterna Verde", "Aquaman", "Daredevil"}, 4, Carta_Vuota
		},

		{ "NETFLICS: Qual è il nome della scimmietta nel film Disney 'Aladdin'?",
				{"Abu", "Apu", "Cimpi", "Koko", "Diddy"}, 0, Carta_Vuota
		},

		{ "NETFLICS: In Star Wars come si chiama la nave di cui Han Solo è capitano?",
				{"Tantive IV", "Ebon Hawk", "Fregata Nebulon-B", "Millennium Falcon", "AT-AT"}, 3, Carta_Vuota
		},

		{ "NETFLICS: Ne 'Il Signore degli Anelli', come si chiama l'elfo che prende parte a 'La Compagnia dell'Anello'?",
				{"Elrond", "Sauron", "Eragon", "Thrainduil", "Legolas"}, 4, Carta_Vuota
		},

		{ "NETFLICS: Quale attore è diventato virale sui social per non riuscire a vincere un Oscar? (E' poi riuscito a vincerne uno!)",
				{"Jack Nicholson", "Jared Leto", "Colin Firth", "Leonardo di Caprio", "Robert Downey Jr."}, 4, Carta_Vuota
		},

		{ "NETFLICS: In quale famosa serie tv Bryan Cranston ha recitato il ruolo di un chimico criminale soprannominato 'Heisenberg'?",
				{"Breaking Bad", "Mr. Robot", "The Walking Dead", "Orange is the New Black", "Narcos"}, 0, Carta_Vuota
		},

		{ "NETFLICS: Qual è il film campione di incassi nella storia del cinema, corretto per l'inflazione?",
				{"Avatar", "Titanic", "Via col Vento", "L'Esorcista", "Star Wars"}, 2, Carta_Vuota
		}
};

#endif //GOP_CARTE_HPP
