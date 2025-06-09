#include "ejercicios.h"

using namespace std;

// Insertion Sort
void insertionSort(vector< int > &arr){     // O(n²)
    int size = arr.size();
    for(int i = 0 ; i < size ; i++) {
        while (i > 0 && arr[i] < arr[i-1]) {
            swap(arr, i, i-1);
            i--;
        }
    }
}

void swap(vector<int> &s, int i, int j) {	// O(1)
    int k = s[i];
    s[i] = s[j];
    s[j] = k;
}

// Selection Sort
void selectionSort(vector< int > &arr){	    // O(n²)
    int posMin, size = arr.size();

    for(int i = 0 ; i < size ; i++) {
        posMin = seleccionarMinimoDesde(arr ,i);
        swap(arr, i, posMin);
    }
}

int seleccionarMinimoDesde(vector<int> &s, int i) {	// O(n)
    int posMin = i;

    for(int j = i ; j < s.size() ; j++){
        if( s[posMin] > s[j]) {
            posMin = j;
        }
    }

    return posMin;
}

//Bubble Sort
void bubbleSort(vector<int> &s) {	// O(n²)
    for(int i = 0 ; i < s.size() ; i++) burbujeo(s, i);
}

void burbujeo(vector<int> &s, int i) {		// O(n)
    for(int j = s.size()-1 ; j > i ; j--) {
        if(s[j] < s[j -1]){
            swap(s, j, j-1);
        }
    }
}

//Counting Sort
void countingSort(vector<int> &s, int cota){ // puede ser cota = |s|+1
    vector<int> contador {};

    for(int i = 0 ; i <= cota ; i++){               // O(n)
        contador.push_back(0);					    // Inicializo en contador llenándolo de 0s
    }

    for(int i = 0 ; i < s.size() ; i++){		    // O(n)
        contador[ s[i] ]++;						    // Lleno el contador con las apariciones de cada elemento
    }

    s = {};
    for(int i = 0 ; i < contador.size() ; i--){	    // O(2n)
        while(contador[i] > 0){					    // Reconstruyo la Secuencia
            s.push_back(i);
            contador[i]--;
        }
    }
}                                                   // O(4n) ∈ O(n)

// Bingo Sort
void bingoSort(vector<int> &s){
    vector<int> minimos {};

    for(int i = 0 ; i < s.size() ; i++){		// O(n²)
        minimos = indicesMinimosDesde(s, i);	// O(n)

        for(int j = 0 ; j < minimos.size() ; j++){
            swap(s, i, minimos[j]);
            i++;
        }
    }
}

vector<int> indicesMinimosDesde(vector<int> s, int i){
    vector<int> posMins {};
    int posDelMin = i, size = s.size();

    for(int j = i ; j < size ; j++){	// O(n)
        if( s[posDelMin] > s[j]) {
            posDelMin = j;
        }
    }

    for(int j = i ; j < size ; j++){    // O(n)
        if(s[posDelMin] == s[j]) posMins.push_back(j);
    }

    return posMins;						// O(n)
}

void ordenar(vector<int> &items){
    //insertionSort(items);
    //selectionSort(items);
    //bubbleSort(items);
    //countingSort(items, 1000);
    bingoSort(items);
}


int bestFit(int W, vector<int> &items){
	multiset<int> restos;
	for(int i=0; i<(int)items.size(); ++i){
		restos.insert(W);
	}
	int res = 0;
	for(int i=0; i<(int)items.size(); ++i){
		multiset<int>::iterator it = restos.lower_bound(items[i]);
		int restoAct = *it;
		if(restoAct==W){
			res++;
		}
		restoAct -= items[i];
		restos.erase(it);
		restos.insert(restoAct);
	}
	return res;
}

int main(){
	int N, W, aux;

	//Se levantan los items y la capacidad del contenedor
	cout << "Se levantan los items y la capacidad del contenedor";
	ifstream bpp("BPP.in");
	bpp >> N >> W;
	vector<int> items;
	for(int i=0; i<N; ++i){
		bpp >> aux;
		items.push_back(aux);
	}
	bpp.close();
	//Se corre best-fit
	int cant1 = bestFit(W, items);
	cout << "Con la idea bestFit, se consigue una asignacion con " << cant1 << " contenedores" << endl;

	//Se ordenan los items
	ordenar(items);
	//Se corre best-fit-decreasing
	int cant2 = bestFit(W, items);
	cout << "Con la idea bestFitDecreasing, se consigue una asignacion con " << cant2 << " contenedores" << endl;

	return 0;
}
