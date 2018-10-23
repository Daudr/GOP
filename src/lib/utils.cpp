//
// Created by michele.da.rin on 15/07/2018.
//

#include "utils.hpp"
#include <vector>

void clearCin() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void pause() {
    cout << "Premere invio per continuare...";
    clearCin();
    cin.get();
    cin.putback('\n');
}


/// Funzione che ordina array di interi in ordine crescente. Usa strategia di Bubble Sort
/// @param array di interi, passato per dereferenziazione
vector<int> sort_int(vector<int> arr){
	int dim = arr.size();
	int tmp;
	for (int k = 0; k < dim - 1; k++){
		for (int i = 0; i < (dim - k - 1); i++){
			if (arr[i] > arr[i + 1]){
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i+1] = tmp;
			}
		}
	}
	return arr;
}
