//
// Created by michele.da.rin on 07/07/2018.
//

#include <iostream>
#include <vector>
#include <iomanip>
#include <utility>
#include "Game.hpp"
#include "casella/inizio/CasellaInizio.hpp"
#include "casella/fine/CasellaFine.hpp"
#include "casella/pesca/CasellaPesca.hpp"
#include "casella/sposta/CasellaSposta.hpp"
#include "casella/perdiTurni/CasellaPerdiTurni.hpp"
#include "casella/Casella.hpp"
#include "carte.hpp"
#include "casella/scambia/CasellaScambia.hpp"
#include "casella/tornaInizio/CasellaTornaInizio.hpp"

#define N_COLUMNS 3
#define W_COLUMN 39

Game::Game() {
    std::cout << "Quanti giocatori: ";
    std::cin >> this->numeroGiocatori;

    for (int i = 0; i < this->numeroGiocatori; i++) {
        string nomeGiocatore;
        cout << "Come si chiama il giocatore " << i + 1 << " : ";
        cin >> nomeGiocatore;

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

        Giocatore *nuovoGiocatore = new Giocatore(nomeGiocatore);
        this->giocatori.push_back(nuovoGiocatore);
    }

    this->startGame();
};

void Game::startGame() {
	//TODO: finire implementare le caselle Sposta e Pesca Carta
    this->initTabellone();

    this->printTabellone();

    this->initMazzo();

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
                	//TODO: Poi perché dynamic_cast dà bug e static_cast no?
                	Giocatore *giocatore = this->giocatori.at(this->giocatoreCorrente);
                    Casella *casella = this->tabellone.at(giocatore->getPosizione());
                    cout << "Posizione giocatore " << giocatore->getPosizione() << endl;
                    CasellaPerdiTurni *casellaPerdiTurni = static_cast<CasellaPerdiTurni *>(casella);
                    int turni = casellaPerdiTurni->getTurni();
                    giocatoreCorrente->setFermo(turni);
                    cout << "Ops! " << "E' una casella Perdi Turni! Fermo per: " << turni << " turni" << endl;
                    break;
                }
                case PescaCarta:
                {
                    this->pescaCarta();
                    break;
                }
                case Scambia:
                {
                    this->scambiaGiocatori();
                    break;
                }
                case Sposta:
                {
                	this->spostaGiocatore(1);
                	break;
                }
                case TornaInizio:
                {
                    this->tornaInizio();
                    break;
                }
              }

            // Se il giocatore corrente è l'ultimo imposta l'indice del giocatore
            // successivo a 0
            this->setGiocatoreCorrente((this->giocatoreCorrente + 1) % this->numeroGiocatori);
            cout << endl << endl;
        } else {
        	cout << giocatoreCorrente->getNome() << " è fermo per ancora " << giocatoreCorrente->getFermo() << " turni" << endl;
            giocatoreCorrente->setFermo(giocatoreCorrente->getFermo() - 1);
            this->setGiocatoreCorrente((this->giocatoreCorrente + 1) % this->numeroGiocatori);	//Giocatore successivo
           }
        // Aspetta la pressione di un tasto per passare al turno successivo
        pause();
    }
};

void Game::endGame() {
	//TODO: BUG - spesso invece che fermarsi il giocatore va oltre la fine e il programma restituisce errore Out of Range
    Giocatore *giocatoreCorrente = this->getGiocatori().at(this->getGiocatoreCorrente());

    cout << giocatoreCorrente->getNome() << " ha vinto il gioco" << endl << endl;
    cout << "Grazie per aver giocato!!!" << endl << endl;

    this->setGameEnded(true);
};

void Game::spostaGiocatore(int spostamento) {
    Giocatore *giocatoreCorrente = this->giocatori.at(this->giocatoreCorrente);
    int posizioneCorrente = giocatoreCorrente->getPosizione();

    if (posizioneCorrente + spostamento > this->tabellone.size()) {
        // Torna indietro per la differenza
        spostamento = (posizioneCorrente + spostamento) - this->tabellone.size();
    }

    giocatoreCorrente->setPosizione(posizioneCorrente + spostamento);
};

void Game::scambiaGiocatori() {
    Giocatore *giocatoreCorrente = this->getGiocatori().at(this->getGiocatoreCorrente());
    int prossimoGiocatore = (this->giocatoreCorrente + (rand()%(this->numeroGiocatori - 1) + 1))%(this->numeroGiocatori);
    //Viene scelto a caso uno degli altri giocatori.
    //-1 e +1 assicurano che non velga scelto di nuovo il giocatore corrente
    //Esempio: 5 giocatori, 2 giocatoreCorrente. Per -1 ho random un numero tra 0 e 3,
    //per +1 il random diventa tra 1 e 4, dunque prossimoGiocatore è random tra {3,4,0,1}
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

void Game::tiraDadi() {
    Giocatore *giocatoreCorrente = this->giocatori.at(this->giocatoreCorrente);

    cout << giocatoreCorrente->getNome()
         << " tira il dado." << endl;

    int risultato = (rand() % 6 + 1) + (rand() % 6 + 1);

    cout << "Il risultato del tiro Ã¨ "
         << risultato << "." << endl;

    this->spostaGiocatore(risultato);

    cout << giocatoreCorrente->getNome()
         << " si trova ora alla casella "
         << giocatoreCorrente->getPosizione()
         << endl;
};

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
    /* ProbabilitÃ  in percentuali:
     * - Vuota:                                     100% -> 70% -> 40% -> 10% -> 0%
     * Se non viene la casella vuota:
     * - Pesca una carta:                           35%
     * - Muovi giocatore avanti da 1 a 6 caselle:   21%
     * - Muovi gioatore indietro da 1 a 6 caselle:  21%
     * - Scambia giocatore con un altro casuale:    10%
     * - Perdi da 1 a 3 turni:                      10%
     * - Torna alla partenza:                       3%
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

                if (randInt <= 35)
                    this->tabellone.push_back(new CasellaPesca());
                else if (randInt <= 56)
                    this->tabellone.push_back(new CasellaSposta(rand() % 5 + 1));
                else if (randInt <= 77)
                    this->tabellone.push_back(new CasellaSposta(-(rand() % 5 + 1)));
                else if (randInt <= 87)
                	this->tabellone.push_back(new CasellaScambia());
                else if (randInt <= 97)
                    this->tabellone.push_back(new CasellaPerdiTurni(rand() % 3 + 1));
                else
                	//TODO: Perché c'era tabellone.at?
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

            // show_players_position(c,pos,players,numPlayers);

            cout << (j > 0 ? "| " : "");
            // cout << right << setfill(' ') << setw(this->numeroGiocatori) << c;
            cout << right << setw(2) << pos << '.' << left << setfill(' ') << setw(W_COLUMN) << casella->getTesto();

        }
        cout << endl;
    }
};

void Game::initMazzo() {
	//TODO: fissare il mazzo a 40 carte va bene?
	//		altrimenti servirebbero tipo 100/101 carte per far sì che nel mazzo non ci siano ripetizioni
//    int numeroCarte = rand() % 41 + 60;
	int numeroCarte = 40;

    for (int i = 0; i < numeroCarte; i++) {
        int numeroCarta = rand() % (CARTE.size() - i);

        this->mazzo.push_back(CARTE.at(numeroCarta));
        CARTE.erase(CARTE.begin() + numeroCarta);
    }
};

void Game::pescaCarta() {
//    int numeroCarta = rand() % this->tabellone.size();
//    Carta carta = this->mazzo.at(numeroCarta);
//    int opzioneCorretta = carta.getCorretta();
//    int opzioneScelta;
//
//    cout << this->giocatori.at(this->giocatoreCorrente)->getNome() << " pesca una carta: " << endl << endl;
//
//    cout << carta.getTesto() << endl << endl;
//
//    for (int i = 0; i < carta.getOpzioni().size(); i++) {
//        string opzione = carta.getOpzioni().at(i);
//        cout << i + 1 << "." << opzione << endl;
//    }
//
//    cout << "Seleziona opzione: ";
//    cin >> opzioneScelta;
//
//    if (opzioneCorretta == opzioneScelta) {
//        cout << "Corretta";
//    } else {
//        cout << "Sbagliata";
//    }
};

void Game::tornaInizio() {
    Giocatore *giocatoreCorrente = this->giocatori.at(this->giocatoreCorrente);

    giocatoreCorrente->setPosizione(0);
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

vector<Carta> Game::getMazzo() {
    return this->mazzo;
};

void Game::setMazzo(vector<Carta> mazzo) {
    this->mazzo = move(mazzo);
};
