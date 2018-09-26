#include <iostream>

#include "lib/Game.hpp"
#include <time.h>

int main() {
    // Inizializzazione della funzione rand
	//TODO: c'era unsigned. E' da rimettere?
    srand(time(nullptr));

    auto game = new Game(2);

    return 0;
}
