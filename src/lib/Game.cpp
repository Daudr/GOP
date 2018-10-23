//
// Created by michele.da.rin on 07/07/2018.
//

//TODO: cambiare scritte per le caselle e carte speciale in modo che non risulti più "casella" in stampa

#include <iostream>
#include <vector>
#include <iomanip>
#include <utility>
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
    std::cout << "Quanti giocatori? ";
    std::cin >> this->numeroGiocatori;

    while (this->numeroGiocatori < 2){
    	cout << "Numero minimo di giocatori consetito è 2. Quanti giocatori?: ";
    	cin >> this->numeroGiocatori;
    }

    for (int i = 0; i < this->numeroGiocatori; i++) {
        string nomeGiocatore;
        cout << "Come si chiama il giocatore " << i + 1 << " : ";
        cin >> nomeGiocatore;

        Giocatore *nuovoGiocatore = new Giocatore(nomeGiocatore);
        this->giocatori.push_back(nuovoGiocatore);
    }

    this->startGame();
};


//Funzione per test al gioco
//Game::Game(int giocatori) {
//    this->numeroGiocatori = giocatori;
//
//    for (int i = 0; i < this->numeroGiocatori; i++) {
//        string nomeGiocatore;
//        cout << "Come si chiama il giocatore " << i + 1 << " : ";
//        cin >> nomeGiocatore;
//
//        Giocatore *nuovoGiocatore = new Giocatore(nomeGiocatore);
//        this->giocatori.push_back(nuovoGiocatore);
//    }
//
//    this->startGame();
//};

void Game::startGame() {

    this->initTabellone();

    this->printTabellone();

    this->initMazzo_blu();
    this->initMazzo_rosso();

    pause();

    while(!this->gameEnded) {
        Giocatore *giocatoreCorrente = this->giocatori.at(this->giocatoreCorrente);

        this->printGiocatoreCorrente();

        if (giocatoreCorrente->getFermo() == 0) {

        	this->tiraDadi();

            int posizioneCorrente = giocatoreCorrente->getPosizione();
            Casella *casellaCorrente = this->tabellone.at(posizioneCorrente);
            TipoCasella tipoCasella = casellaCorrente->getTipoCasella();

            do {
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
                posizioneCorrente = giocatoreCorrente->getPosizione();
                casellaCorrente = this->tabellone.at(posizioneCorrente);
                tipoCasella = casellaCorrente->getTipoCasella();
            } while ((tipoCasella != Vuota) && (tipoCasella != Inizio) && (tipoCasella != Fine) &&
            		(giocatoreCorrente->getFermo() == 0) && (tipoCasella != Scambia) && !(this->gameEnded));

            // Se il giocatore corrente è l'ultimo imposta l'indice del giocatore
            // successivo a 0
            this->setGiocatoreCorrente((this->giocatoreCorrente + 1) % this->numeroGiocatori);
            this->printTabellone();
            cout << endl << endl;
        } else {
        	cout << giocatoreCorrente->getNome() << " è fermo per ancora " << giocatoreCorrente->getFermo() << " turni" << endl << endl;
            giocatoreCorrente->setFermo(giocatoreCorrente->getFermo() - 1);
            this->setGiocatoreCorrente((this->giocatoreCorrente + 1) % this->numeroGiocatori);	//Giocatore successivo
            this->printTabellone();
            cout << endl << endl;
           }

        if (!(this->gameEnded)){
            // Aspetta la pressione di un tasto per passare al turno successivo
        	pause();
        	cout << endl;
        }
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
         << endl << endl;;
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

	cout << "Il risultato del tiro è "
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
		cout << "Torni indietro di " << spostamento << endl;
	}

	this->spostaGiocatore(spostamento);

	/// Controllo che non ci sia loop di spostamenti avanti e indietro. Eventualmente il giocatore viene spostato di 1 indietro.
    int posizioneCorrente = giocatore->getPosizione();
    Casella *casellaArrivo = this->tabellone.at(posizioneCorrente);
    TipoCasella tipoCasellaArrivo = casellaArrivo->getTipoCasella();

    if (tipoCasellaArrivo == Sposta){
    	CasellaSposta *casellaSpostaArrivo = static_cast<CasellaSposta *>(casellaArrivo);
    	int spostamentoArrivo = casellaSpostaArrivo->getSpostamento();
    	if (spostamentoArrivo == -spostamento){
    		this->spostaGiocatore(-1);
    	}
    }

}

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

    cout << "E' una Casella Scambia." << endl
    	 << giocatoreCorrente->getNome()
         << " si trova ora alla posizione "
         << giocatoreCorrente->getPosizione()
         << ", mentre " << giocatoreSuccessivo->getNome()
         << " si trova alla posizione " << giocatoreSuccessivo->getPosizione() << endl << endl;
};

void Game::perdiTurni(){
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
		cout << "Il risultato è pari: avanzi di tante caselle quanto è il risultato del dado" << endl;
		this->spostaGiocatore(spostamento);
	}	else{
		cout << "Il risultato è dispari: torni indietro di tante caselle quanto è il risultato del dado" << endl;
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
    /* Probabilità  in percentuali:
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



/// LEGENDA VARIABILI:
/// num_gioco -> Numero di giocatori
/// r -> 0 o 1 a seconda che l'ultima colonna sia piena o meno
/// n -> numero di righe per colonna
/// gioc_pos -> Vettore che al posto i-esimo ha la posizione del giocatore i-esimo
/// contatore -> Vettore che al posto i-esimo ha il numero di giocatori che vengono rappresentati alla i-esima colonna
/// contatore_2 -> Vettore che si aggiorna ogni riga e al posto i-esimo indica quanti giocatori sono già stati stampati nella i-esima colonna
/// tmp -> 2 utilizzi diversi, specificati volta per volta
/// gioc_pos_ord -> vettore con gioc_pos ordinato in maniera crescente
/// stampa_gioc -> vettore intero ausiliario. Al posto i-esimo indice del giocatore da rappresentare nella colonna i-esima
/// aumentoRighe_tot -> numero di righe necessarie in più per rappresentare un giocatore nel caso la colonna sia piena
/// aumentoRighe_parz -> numero di righe da aggiungere in una iterazione
/// controllo_colonna -> segnaposto che serve per azzerare tmp_3 nel caso in cui non ci siano altri giocatori da rappresentare nelle caselle di quella riga
/// is_player -> Vettore di valori booliani. Al posto i-esimo indica se all'iterazione successiva deve essere stampato un giocatore

void Game::printTabellone() {
	int num_gioc = this->numeroGiocatori;
    int r = ((this->tabellone.size() + num_gioc) % N_COLUMNS == 0) ? 0 : 1;
    int n = (this->tabellone.size() + num_gioc) / N_COLUMNS + r;

    vector<int> gioc_pos;
    for(int i = 0; i < num_gioc; i++){
    	gioc_pos.push_back(this->giocatori.at(i)->getPosizione());
    }

    vector<int> contatore;
    for (int i = 0; i < N_COLUMNS; i++){
    	contatore.push_back(0);
    }

    vector<int> contatore_2;
    for (int i = 0; i < N_COLUMNS; i++){
    	contatore_2.push_back(0);
    }

    int tmp = 0;
    vector<int> gioc_pos_ord (sort_int(gioc_pos));
    vector<int> stampa_gioc;
    for (int i = 0; i < N_COLUMNS; i++){
    	stampa_gioc.push_back(0);
    }

    /// tmp -> intero ausiliario che indica quale colonna di contatore deve essere aumentata a seconda della posizione dei giocatori
    for (int i = 0; i < num_gioc; i++){
    	tmp = ((gioc_pos_ord[i]+i) / n);
    	if (tmp < (N_COLUMNS - 1)){
    		for (int j = 1; (tmp + j < N_COLUMNS); j++){
    			contatore[tmp + j] = contatore [tmp + j] + 1;
    		}
    	}
    }


    /// 2 cicli for che controllano che nelle colonne ci sia sufficiente spazio per rappresentare i giocatori
    /// nella stessa colonna della loro posizione, eventualmente aggiungendo righe.
    /// Il primo for fa un controllo specifico sul giocatore più avanti nel gioco.
    /// Il secondo for controlla tutti i giocatori prima e se ci sono più giocatori non rappresentabili
    /// nella stessa casella.
    /// Dopo il controllo e aver contato le righe necessarie da aggiungere aggiorna i contatori

    /// tmp -> conta quanti giocatori ci sono nella stessa posizione (meno il primo)

    tmp = 0	;
    int aumentoRighe_tot = 0;
    int i = 0;
    int j = 0;

    while (i < (num_gioc-1)){
    	while ((gioc_pos_ord[j] == gioc_pos_ord[j+1]) && (j < num_gioc)){
    		tmp = tmp + 1;
    		j = j + 1;
    	}
    	for (int k = 1; k < N_COLUMNS; k++){
    		if (tmp >0){
    			cout << "TEST IF" << endl;
        		if ((gioc_pos_ord[i] <= (n*k - 1 - contatore[k])) && (gioc_pos_ord[i] + contatore[k] + tmp + 1 >= n*k)){
        			cout << "TEST IF 1.1" << endl;
        			int aumentoRighe_parz = tmp - (n*k - 1 - gioc_pos_ord[i] - contatore[k]);
        			aumentoRighe_tot = aumentoRighe_tot + aumentoRighe_parz;
        			i = i + tmp;
        		}
    		}
    		else {
    			cout << "TEST ELSE" << endl;
    			if ((gioc_pos_ord[i]-i)/n == k){
        			cout << "TEST ELSE 1.1" << endl;
        			if ((gioc_pos_ord[i] + contatore[k]) == n*k){
        				cout << "TEST ELSE 1.2" << endl;
        				aumentoRighe_tot = aumentoRighe_tot + 1;
        			}
        			else if ((gioc_pos_ord[i]-i)/n == k-1){
        				cout << "TEST ELSE 2" << endl;
        				if ((gioc_pos_ord[i] + contatore[k] + 1) == n*k){
        					cout << "TEST ELSE 2.1" << endl;
        					aumentoRighe_tot = aumentoRighe_tot + 1;
        	            	contatore[k] = contatore[k] + 1;
        				}
        			}
        		}
    		}
    	}

		tmp = 0;
    	i = i + 1;
    	j = i;
    }

    for (int k = 1; k < N_COLUMNS; k++){
    	if (contatore[k] == num_gioc){
            if (((gioc_pos_ord[num_gioc-1] + contatore[k]) == (n*k)) && ((gioc_pos_ord[num_gioc-1]) != (gioc_pos_ord[num_gioc-2]))){
            	aumentoRighe_tot = aumentoRighe_tot + 1;
            }
    	}
    	else if (contatore[k] == (num_gioc-1)){
            if (((gioc_pos_ord[num_gioc-1] + contatore[k] + 1) == (n*k)) && ((gioc_pos_ord[num_gioc-1]) != (gioc_pos_ord[num_gioc-2]))){
            	aumentoRighe_tot = aumentoRighe_tot + 1;
            	contatore[k] = contatore[k] + 1;
            }
    	}
    }

    /// Aggiornamento numero righe
    n = n + aumentoRighe_tot;
    cout << "AUMENTO RIGHE TOT:" << aumentoRighe_tot << " n:" << n << endl;

    vector<bool> is_player;
    for (int i = 0; i < N_COLUMNS; i++){
    	is_player.push_back(false);
    }

    int controllo_colonna = 0;

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < N_COLUMNS; j++) {
            int pos = i + j * n - contatore[j] - contatore_2[j];
            if (pos >= this->tabellone.size()) {
                continue;
            }

            if (j > 0) {
            	cout << "| ";
            }

            if (is_player[j]) {
                Giocatore *giocatoreCorrente = this->giocatori.at(stampa_gioc[j]);
              	cout << right << setw(2) << "   " << left << setfill(' ') << setw(W_COLUMN) << giocatoreCorrente->getNome();
            	is_player[j] = false;
            	stampa_gioc[j] = stampa_gioc[j] + 1;
            }
            else {
                Casella *casella = this->tabellone.at(pos);
            	cout << right << setw(2) << pos << '.' << left << setfill(' ') << setw(W_COLUMN) << casella->getTesto();
            }

            for (int k = stampa_gioc[j]; ((k < num_gioc) && (is_player[j] == false)); k++){
            	if (gioc_pos[k] == pos){
            		contatore_2[j] = contatore_2[j] + 1;
            		is_player[j] = true;
            		stampa_gioc[j] = k;
            		controllo_colonna = j;
            	}
            }

            if ((stampa_gioc[j] > 0) && !is_player[controllo_colonna]){
            	stampa_gioc[j] = 0;
            }

        }
        cout << endl;
    }
};

void Game::initMazzo_blu() {
	this->mazzo = new Mazzo;
	/// tmp_head segna dove inizia la creazione del mazzo, così poi da potercisi
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

void Game::initMazzo_rosso() {
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
    int opzioneCorretta = this->mazzo->carta.getCorretta();
    int opzioneScelta;

    cout << this->giocatori.at(this->giocatoreCorrente)->getNome() << " pesca una carta dal mazzo blu: " << endl << endl;
    cout << this->mazzo->carta.getTesto() << endl;

    /// Generatore di permutazioni pseudocasuali. Si usa la proprietà degli interi modulo p
    /// per cui dati a,b,c interi e x_0 = c, allora x_(k+1) = (a*x_k + b)mod(p) è successione
    /// pseudocasuali. Qui a = mult (moltiplicatore), b = drft.
    /// Le costanti 30 e 4 sono state scelte perché 30*4 = 120, che è anche il numero delle
    /// permutazioni totali di un insieme ordinato di 5 elementi.
    int mult, drift;
    mult = (rand()%30)*5+1 ;
    drift = (rand()%4) + 1;

    for (int i = 0; i < 5; i++) {
        string opzione = this->mazzo->carta.getOpzioni().at((mult*i + drift)%5);
        cout << i + 1 << ". " << opzione << endl;
    }

    cout << "Seleziona opzione: ";
    cin >> opzioneScelta;
    while (opzioneScelta > 5 or opzioneScelta < 1){
    	cout << "Selezione non valida. Inserisci un numero tra 1 e 5" << endl;
    	cin >> opzioneScelta;
    }
    cout << endl;
    opzioneScelta = (mult*(opzioneScelta - 1) + drift)%5; ///I vettori hanno gli elementi numerati da 0 a 4, gli inserimenti sono da 1 a 5

    ///Se risposta corretta giocatore va avanti di 2, se sbagliata -3
    if (opzioneCorretta == opzioneScelta) {
        cout << "Corretta. Avanzi di 2 caselle!" << endl;
        spostaGiocatore(2);

    } else {
        cout << "Sbagliata. Torni indietro di 3 caselle.." << endl;
        spostaGiocatore(-3);
    }

    pause();
    cout << endl;

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
	default:
		break;
	case Carta_Vuota:
		break;
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
