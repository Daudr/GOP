//
// Created by michele.da.rin on 15/07/2018.
//

#include "utils.hpp"

void clearCin() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void pause() {
    cout << "Premere invio per continuare...";
    clearCin();
    cin.putback('\n');
    cin.get();
}