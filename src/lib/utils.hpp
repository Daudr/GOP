//
// Created by michele.da.rin on 15/07/2018.
//

#ifndef GOP_UTILS_HPP
#define GOP_UTILS_HPP

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

/// Pulisce lo stream in ingresso
void clearCin();

/// Aspetta la pressione del tasto invio per continuare
void pause();

/// Funzione che mette in ordine crescente gli elementi di un array intero
/// @param vettore di interi
vector<int> sort_int(vector<int> arr);

#endif //GOP_UTILS_HPP
