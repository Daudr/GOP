#include <iostream>

#include "lib/Game.hpp"
#include <time.h>

int main() {
    // Inizializzazione della funzione rand
    srand(time(nullptr));

    auto game = new Game();

    return 0;
}
