//
// Created by michele.da.rin on 07/07/2018.
//

//TODO: Gestire eccezioni per quando si da una risposta a una domanda multipla che non � un numero
//TODO: cambiare scritte per le caselle e carte speciale in modo che non risulti pi� "casella" in stampa

#include <iostream>
#include <vector>
#include <iomanip>
#include <utility>
#include "stdlib.h"
#include "Game.hpp"

#include "carte_blu.hpp"
#include "casella/inizio/CasellaInizio.hpp"
#include "casella/fine/CasellaFine.hpp"
#include "casella/pesca_rosso/CasellaPesca_Rosso.hpp"
#include "casella/sposta/CasellaSposta.hpp"
#include "casella/perdiTurni/CasellaPerdiTurni.hpp"
#include "casella/Casella.hpp"
#include "carte_rosso.hpp"
#include "casella/pesca_blu/CasellaPesca_Blu.hpp"
#include "casella/scambia/CasellaScambia.hpp"
#include "casella/tornaInizio/CasellaTornaInizio.hpp"

#define N_COLUMNS 3
#define W_COLUMN 39

Game::Game() {
    std::cout << "Quanti giocatori: ";
    std::cin >> this->numeroGiocatori;
    cin.ignore();

    for (int i = 0; i < this->numeroGiocatori; i++) {
        string nomeGiocatore;
        cout << "Come si chiama il giocatore " << i + 1 << " : ";
        cin >> nomeGiocatore;
        cin.ignore();

        Giocatore *nuovoGiocatore = new Giocatore(nomeGiocatore);
        this->giocatori.push_back(nuovoGiocatore);
    }

    this->startGame();
};

Game::Game(int giocatori) {
    this->numeroGiocatori = giocatori;

    for (int i = 0; i < this->numeroGiocatori; i++) {
        string nomeGiocatore;
        cout << "Come si chiama il giocatore " << i + 1 << " : ";
        cin >> nomeGiocatore;
        cin.ignore();

        Giocatore *nuovoGiocatore = new Giocatore(nomeGiocatore);
        this->giocatori.push_back(nuovoGiocatore);
    }

    this->startGame();
};

void Game::startGame() {
    this->initTabellone();

    this->printTabellone();

    this->initMazzo();
    this->initMazzo_Rosso();

    while(!this->gameEnded) {
        Giocatore *giocatoreCorrente = this->giocatori.at(this->giocatoreCorrente);

        this->printGiocatoreCorrente();

        if (giocatoreCorrente->getFermo() == 0) {

        	this->tiraDadi();

            int posizioneCorrente = giocatoreCorrente->getPosizione();
            Casella *casellaCorrente = this->tabellone.at(posizioneCorrente);
            TipoCasella tipoCasella = casellaCorrente->getTipoCasella();

            switch (tipoCasella) {
                default:
                    break;
                case Vuota:
                    break;
                case Fine:
                {
                    this->endGame();
                    break;
                }
                case PerdiTurni:
                {

                	this->perdiTurni();
                	break;
                }
                case PescaCarta_Blu:
                {
                    this->pescaCarta_blu();
                    break;
                }
                case PescaCarta_Rosso:
                {
                	this->pescaCarta_rosso();
                	break;
                }
                case Scambia:
                {
                    this->scambiaGiocatori();
                    break;
                }
                case Sposta:
                {
                	this->sposta();
                	break;
                }
                case TornaInizio:
                {
                    this->tornaInizio();
                    break;
                }
              }

            // Se il giocatore corrente � l'ultimo imposta l'indice del giocatore
            // successivo a 0
            this->setGiocatoreCorrente((this->giocatoreCorrente + 1) % this->numeroGiocatori);
            cout << endl << endl;
        } else {
            cout << giocatoreCorrente->getNome() << " � fermo per ancora " << giocatoreCorrente->getFermo() << " turni" << endl << endl;
            giocatoreCorrente->setFermo(giocatoreCorrente->getFermo() - 1);
            this->setGiocatoreCorrente((this->giocatoreCorrente + 1) % this->numeroGiocatori);	//Giocatore successivo
           }

        this->printTabellone();

        // Aspetta la pressione del tasto invio per passare al turno successivo
        cout << "Premi invio per continuare...";
        cin.ignore();
        cout << string( 100, '\n' );
    }
};

void Game::endGame() {
    Giocatore *giocatoreCorrente = this->getGiocatori().at(this->getGiocatoreCorrente());

    cout << giocatoreCorrente->getNome() << " ha vinto il gioco" << endl << endl;
    cout << "Grazie per aver giocato!!!" << endl << endl;

    this->setGameEnded(true);
};

void Game::spostaGiocatore(int spostamento) {
    Giocatore *giocatoreCorrente = this->giocatori.at(this->giocatoreCorrente);
    int posizioneCorrente = giocatoreCorrente->getPosizione();
    int lungh = this->tabellone.size();

    if (posizioneCorrente + spostamento >= lungh) {
        // Torna avanti al massimo fino a fine tabellone
    	spostamento = lungh - posizioneCorrente - 1;
    } else if (posizioneCorrente + spostamento < 0){
    	// Torna indietro al massimo fino a inizio tabellone
    	spostamento = - posizioneCorrente;
    }

    giocatoreCorrente->setPosizione(posizioneCorrente + spostamento);

    cout << giocatoreCorrente->getNome()
         << " si trova ora alla casella "
         << giocatoreCorrente->getPosizione()
         << endl;
};

void Game::tiraDadi() {
    Giocatore *giocatoreCorrente = this->giocatori.at(this->giocatoreCorrente);

    cout << giocatoreCorrente->getNome()
         << " tira i dadi." << endl;

    int risultato = (rand() % 6 + 1) + (rand() % 6 + 1);

    cout << "Il risultato del tiro e' "
         << risultato << "." << endl;

    this->spostaGiocatore(risultato);
    ///Controllo che il giocatore abbia raggiunto la fine del tabellone
    if (giocatoreCorrente->getPosizione() >= tabellone.size()){
    	int diff = giocatoreCorrente->getPosizione() - tabellone.size() + 1;
    	giocatoreCorrente->setPosizione(giocatoreCorrente->getPosizione() - diff);
    }
};

int Game::tiraDado_nospost(){
	Giocatore *giocatoreCorrente = this->giocatori.at(this->giocatoreCorrente);

	cout << giocatoreCorrente->getNome()
	         << " tira un dado." << endl;

	int risultato = (rand() % 6) + 1;

	cout << "Il risultato del tiro � "
	         << risultato << "." << endl;

	return risultato;
}

void Game::sposta(){
	Giocatore *giocatore = this->giocatori.at(this->giocatoreCorrente);
	Casella *casella = this->tabellone.at(giocatore->getPosizione());
	CasellaSposta *casellaSposta = static_cast<CasellaSposta *>(casella);
	int spostamento = casellaSposta->getSpostamento();
	cout << "Casella spostamento! " << endl;

	if (spostamento > 0){
		cout << "Avanzi di " << spostamento << endl;
	} else {
		cout << "Torni indietro di " << abs(spostamento) << endl;
	}

	this->spostaGiocatore(spostamento);
}

void Game::scambiaGiocatori() {
    Giocatore *giocatoreCorrente = this->getGiocatori().at(this->getGiocatoreCorrente());
    int prossimoGiocatore = (this->giocatoreCorrente + (rand()%(this->numeroGiocatori - 1) + 1))%(this->numeroGiocatori);
    //Viene scelto a caso uno degli altri giocatori.
    //-1 e +1 assicurano che non velga scelto di nuovo il giocatore corrente
    //Esempio: 5 giocatori, 2 giocatoreCorrente. Per -1 ho random un numero tra 0 e 3,
    //per +1 il random diventa tra 1 e 4, dunque prossimoGiocatore � random tra {3,4,0,1}
    Giocatore *giocatoreSuccessivo = this->getGiocatori().at(prossimoGiocatore);

    int posizione = giocatoreCorrente->getPosizione();
    giocatoreCorrente->setPosizione(giocatoreSuccessivo->getPosizione());
    giocatoreSuccessivo->setPosizione(posizione);

    cout << giocatoreCorrente->getNome()
         << " si trova ora alla posizione "
         << giocatoreCorrente->getPosizione()
         << ", mentre " << giocatoreSuccessivo->getNome()
         << " si trova alla posizione " << giocatoreSuccessivo->getPosizione() << endl << endl;
};

void Game::perdiTurni(){
	//TODO: Poi perch� dynamic_cast d� bug e static_cast no?
	Giocatore *giocatore = this->giocatori.at(this->giocatoreCorrente);
	Casella *casella = this->tabellone.at(giocatore->getPosizione());
	CasellaPerdiTurni *casellaPerdiTurni = static_cast<CasellaPerdiTurni *>(casella);
	int turni = casellaPerdiTurni->getTurni();
	giocatore->setFermo(turni);
	cout << "Ops! E' una casella Perdi Turni! Fermo per: " << turni << " turni" << endl;
}

void Game::DadoMagico(){
	int spostamento = this->tiraDado_nospost();

	if ((spostamento % 2) == 0){
		cout << "Il risultato � pari: avanzi di tante caselle quanto � il risultato del dado" << endl;
		this->spostaGiocatore(spostamento);
	}	else{
		cout << "Il risultato � dispari: torni indietro di tante caselle quanto � il risultato del dado" << endl;
		this->spostaGiocatore( - spostamento);
	}
}

void Game::printGiocatoreCorrente() {
    cout << "Tocca a "
         << this->giocatori.at(this->giocatoreCorrente)->getNome()
         << ", che si trova in posizione "
         << this->giocatori.at(this->giocatoreCorrente)->getPosizione()
         << "." << endl << endl;
};

void Game::initTabellone() {
    int numeroCaselle = rand() % 41 + 60;

    this->tabellone.push_back(new CasellaInizio());

    int voidChance = 100;
    int randInt = 0;

    // Generazione altre caselle
    /* Probabilità in percentuali:
     * - Vuota:                                     100% -> 70% -> 40% -> 10% -> 0%
     * Se non viene la casella vuota:
     * - Pesca una carta da mazzo blu:              20%
     * - Pesca una carta da mazzo rosso:			20%
     * - Muovi giocatore avanti da 1 a 6 caselle:   20%
     * - Muovi gioatore indietro da 1 a 6 caselle:  20%
     * - Scambia giocatore con un altro casuale:    8%
     * - Perdi da 1 a 3 turni:                      7%
     * - Torna alla partenza:                       5%
     */
    for (int i = 1; i < numeroCaselle; i++) {
        if (i == numeroCaselle - 1) {
            this->tabellone.push_back(new CasellaFine());
        } else {
            randInt = rand() % 100 + 1;

            if (randInt <= voidChance) {
                this->tabellone.push_back(new Casella());
                voidChance -= 30;
            } else {
                voidChance = 100;

                randInt = rand() % 100 + 1;

                if (randInt <= 20)
                  this->tabellone.push_back(new CasellaPesca_Blu());
                else if (randInt <= 40)
                	this->tabellone.push_back(new CasellaPesca_Rosso());
                else if (randInt <= 60)
                    this->tabellone.push_back(new CasellaSposta(rand() % 5 + 1));
                else if (randInt <= 80)
                    this->tabellone.push_back(new CasellaSposta(-(rand() % 5 + 1)));
                else if (randInt <= 88)
                	this->tabellone.push_back(new CasellaScambia());
                else if (randInt <= 95)
                    this->tabellone.push_back(new CasellaPerdiTurni(rand() % 3 + 1));
                else
                	this->tabellone.push_back(new CasellaTornaInizio());
            }
        }
    }
};

void Game::printTabellone() {
    int r = (this->tabellone.size() % N_COLUMNS == 0) ? 0 : 1;
    int n = this->tabellone.size() / N_COLUMNS + r;

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < N_COLUMNS; j++) {
            int pos = i + j * n;
            if (pos >= this->tabellone.size()) {
                continue;
            }

            Casella *casella = this->tabellone.at(pos);

            for (int y = 0; y < this->giocatori.size(); y++) {
                if (this->giocatori.at(y)->getPosizione() == pos) {
                    cout << this->giocatori.at(y)->getNome()[0];
                }
            }

            cout << (j > 0 ? "| " : "");
            cout << right << setfill(' ') << setw(this->numeroGiocatori) << '\0';
            cout << right << setw(2) << pos << '.' << left << setfill(' ') << setw(W_COLUMN) << casella->getTesto();

        }
        cout << endl;
    }

    cout << endl << endl << endl;
};

void Game::initMazzo() {
	//TODO: fissato il numero di carte con il numero delle domande inserite
	//		altrimenti servirebbero tipo 100/101 carte per far s� che nel mazzo non ci siano ripetizioni
//    int numeroCarte = rand() % 41 + 60;
	this->mazzo = new Mazzo;
	/// tmp_head segna dove inizia la creazione del mazzo, cos� poi da potercisi
	/// riattaccare alla fine e creare un lista circolare
    Mazzo* tmp_head = this->mazzo;
	int numeroCarta = rand() % (CARTE.size());
	Carta carta = CARTE.at(numeroCarta);
	this->mazzo->carta = carta;
	CARTE.erase(CARTE.begin() + numeroCarta);
    for (int i = 0; i < CARTE.size();) {
    	this->mazzo->next = new Mazzo;
    	this->mazzo = this->mazzo->next;
        numeroCarta = rand() % (CARTE.size());
        carta = CARTE.at(numeroCarta);
        this->mazzo->carta = carta;
        CARTE.erase(CARTE.begin() + numeroCarta);
    }
    this->mazzo->next = tmp_head;
};

void Game::initMazzo_Rosso() {
	this->mazzo_rosso = new Mazzo;
    Mazzo* tmp_head = this->mazzo_rosso;
	int numeroCarta = rand() % 5;
	Carta carta = CARTE_ROSSO.at(numeroCarta);
	this->mazzo_rosso->carta = carta;
    for (int i = 0; i < 40; i++) {
    	this->mazzo_rosso->next = new Mazzo;
    	this->mazzo_rosso = this->mazzo_rosso->next;
    	numeroCarta = rand() % 5;
        carta = CARTE_ROSSO.at(numeroCarta);
        this->mazzo_rosso->carta = carta;
    }
    this->mazzo_rosso->next = tmp_head;
};



void Game::pescaCarta_blu() {
//    int numeroCarta = rand() % this->tabellone.size();
//    Carta carta = this->mazzo.at(numeroCarta);
    int opzioneCorretta = this->mazzo->carta.getCorretta();
    int opzioneScelta;

    cout << this->giocatori.at(this->giocatoreCorrente)->getNome() << " pesca una carta dal mazzo blu: " << endl << endl;
    cout << this->mazzo->carta.getTesto() << endl;

    for (int i = 0; i < 5; i++) {
        string opzione = this->mazzo->carta.getOpzioni().at(i);
        cout << i + 1 << ". " << opzione << endl;
    }

    cout << "Seleziona opzione: ";
    cin >> opzioneScelta;
    cin.ignore();
    opzioneScelta = opzioneScelta - 1; ///I vettori hanno gli elementi numerati da 0 a 4, gli inserimenti sono da 1 a 5

    ///Se risposta corretta giocatore va avanti di 2, se sbagliata -3
    if (opzioneCorretta == opzioneScelta) {
        cout << "Corretta. Avanzi di 2 caselle!" << endl;
        spostaGiocatore(2);

    } else {
        cout << "Sbagliata. Torni indietro di 3 caselle.." << endl;
        spostaGiocatore(-3);
    }
    this->mazzo = this->mazzo->next;
};

void Game::pescaCarta_rosso(){
	string testo = this->mazzo_rosso->carta.getTesto();

	Giocatore *giocatoreCorrente = this->giocatori.at(this->giocatoreCorrente);
	cout << this->giocatori.at(this->giocatoreCorrente)->getNome() << " pesca una carta dal mazzo rosso. E' una carta ";
	cout << this->mazzo_rosso->carta.getTesto() << endl;
	TipoCarta tipoCarta = this->mazzo_rosso->carta.getTipoCarta();
	this->mazzo_rosso = this->mazzo_rosso->next;

	switch(tipoCarta){
	case Carta_PerdiTurno:
	{
		giocatoreCorrente->setFermo(1);
		cout << "Il prossimo turno rimarrai fermo" << endl;
		break;
	}
	case Carta_DadoMagico:
	{
		this->DadoMagico();
		break;
	}
	case Carta_PescaCartaBlu:
	{
		this->pescaCarta_blu();
		break;
	}
	case Carta_Indietro_5:
	{
		this->spostaGiocatore(-5);
		break;
	}
	case Carta_Ritira:
	{
		this->tiraDadi();
		break;
	}
	case Carta_Scambia:
	{
		this->scambiaGiocatori();
		break;
	}
	}
};


void Game::tornaInizio() {
    Giocatore *giocatoreCorrente = this->giocatori.at(this->giocatoreCorrente);

    giocatoreCorrente->setPosizione(0);
    cout << giocatoreCorrente->getNome() << " torna al punto di partenza! Nuova posizione: 0" << endl;
};

vector<Giocatore *> Game::getGiocatori() {
    return this->giocatori;
};

void Game::setGiocatori(vector<Giocatore *> giocatori) {
    this->giocatori = move(giocatori);
};

int Game::getGiocatoreCorrente() {
    return this->giocatoreCorrente;
};

void Game::setGiocatoreCorrente(int giocatoreCorrente) {
    this->giocatoreCorrente = giocatoreCorrente;
};

bool Game::isGameEnded() {
    return this->gameEnded;
};

void Game::setGameEnded(bool gameEnded) {
    this->gameEnded = gameEnded;
};

vector<Casella *> Game::getTabellone() {
    return this->tabellone;
};

void Game::setTabellone(vector<Casella *> tabellone) {
    this->tabellone = move(tabellone);
};

//TODO: sistemare maybe
//vector<Carta> Game::getMazzo() {
//    return this->mazzo;
//};


//TODO: sistemare maybe
//void Game::setMazzo(vector<Carta> mazzo) {
//    this->mazzo = move(mazzo);
//};
