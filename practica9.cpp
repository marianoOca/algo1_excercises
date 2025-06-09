#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <sstream>

using namespace std;
// Algoritmos de Ordenamiento \\
// Insertion Sort
vector<int> insertionSort(vector <int> s ) {	// O(n²)
	for(int i = 0 ; i < s.size() ; i++) {
		while (i > 0 && s[i] < s[i-1]) {
			swap(s, i, i-1);
			i--;
		}
	}

	return s;
}

void swap(vector<int> &s, int i, int j) {		// O(1)
	int k = s[i];
	s[i] = s[j];
	s[j] = k;
}

// Selection Sort
vector<int> selectionSort(vector<int> s) {		// O(n²)
	int posMin;

	for(int i = 0 ; i < s.size() ; i++) {
		posMin = seleccionarMinimoDesde(s ,i);
		swap(s, i, posMin);
	}

	return s;
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

//Bubble Sort
vector<int> bubbleSort (vector<int> s) {	// O(n²)
	for(int i = 0 ; i < s.size() ; i++) {
		burbujeo(s, i);
	}

	return s;
}

void burbujeo(vector<int> &s, int i) {		// O(n)
	for(int j = s.size()-1 ; j > i ; j--) {
		if(s[j] < s[j -1]){
			swap(s, j, j-1);
		}
	}
}

//Counting Sort
vector<int> countingSort(vector<int> &s, int cota){	// puede ser cota = |s|+1
	vector<int> contador {}, res {};

	for(int i = 0 ; i <= cota ; i++){		 	// O(n)
		contador.push_back(0);					// Inicializo en contador llenándolo de 0s
	}

	for(int i = 0 ; i < s.size() ; i++){		// O(n)
		contador[ s[i] ]++;						// Lleno el contador con las apariciones de cada elemento
	}

	for(int i = 0 ; i < contador.size() ; i--){	// O(2n)
		while(contador[i] > 0){					// Reconstruyo la Secuencia
			res.push_back(i);
			contador[i]--;
		}
	}

	return res; 								// O(4n) ∈ O(n)
}

// Algoritmos de Búsqueda \\
// Búsqueda Lineal
int linearSearch(vector <int> s, int x) {
	bool found = false;
	int i = 0;

	while(i < s.size() && !found) {
		if(s[i] == x){
			found = true;
		}
		i++;
	}

	return found;
}

//Búsqueda Binaria
int binarySearch(vector<int> s, int x){
	int desde = 0, hasta = s.size(), m;

	while(hasta > desde+1) {
		m = (desde + hasta)/2;

		if(s[m] > x) {	// esta en la mitad izquierda
			hasta = m;
		} else { 		// esta en la mitad derecha
			desde = m;
		}
	}

	return s[m] == x;
}


vector <int > reconstruir (vector <int > &lista , vector <int> conteo ) {
	vector <int > resultado ( lista . size () ) ;
	int indice_conteo = 0;
	for(int i = 0 ; i < s.size() ; i++) {
		// Ignoro valores nulos
		while ( conteo[ indice_conteo ]==0) {
			indice_conteo ++;
		}
		lista [i] = indice_conteo ;
		conteo [ indice_conteo ] - -;
	}
}


// EJERCICIOS \\
//Ej 1
proc dondeEsta(in m : seq⟨seq⟨ℤ⟩⟩, in x : ℤ, out res : ⟨ℤ x ℤ⟩){
	Pre {|m| > 0 ∧L |m[0]| > 0 ∧ esMatrizCuadrada(m)}
	Post {(x ∈ m ∧ m[res₀][res₁] = e) ∨ (x ¬∈ m ∧ res = ⟨-1,-1⟩) }
}

vector<int> dondeEsta(vector<vector<int>> m, int x){
	vector<int> res = {-1,-1};

	for(int i = 0 ; i < m.size() ; i++){
		for(int j = 0 ; j < m[0].size() ; j++){
			if( m[i][j] == x){
				res[0] = i;
				res[1] = j;
			}
		}
	}

	return res;										// con n = |m| = |m[0]| ⟶ O(n²)
}

//Ej 2.a. se que |s| ≥ 2 con sólo 1 elemento faltante
int cualFalta(vector<int> s){
	int desde = 0, hasta = s.size()-1, m;

	while(hasta > desde+1){
		m = (desde + hasta)/2;
	   	if(s[m] == m){
	 		hasta = m;
	   	} else {
	 		desde = m;
	   	}
	}

	return desde;
}

//Ej 2.b. con más de 1 elemento faltante
vector<int> cualesFaltan(vector<int> s){		// sea n = N (cant. de elementos que debería tener)
	vector<int> res;							// sea k = elementos que faltan, se que k <= n-2

	for(int i = 0 ; i < s.size()-1 ; i++){			// O(k*n) ⟶ k acotado ⟶ O(n)
		for(int j = 1 ; s[i]+j < s[i+1] ; j++){	//	  O(k)
			res.push_back( s[i]+j );
		}
	}

	return res;									// O(n)
}


//Ej 2.c
int kEsimoFaltante(vector<int> s, int k){	// O(n)
	vector<int> temp = cualesFaltan(s);		// O(n)
	
	return temp[k-1];						// O(1) + O(n) = O(n)
}

//Ej 3
float raizCuadrada(float n){
	float cotaInf = 0, cotaSup = n, raiz;
	int i = 0;

	while(i < 200){
		raiz = (cotaInf + cotaSup)/2;

		if(raiz*raiz == n) return raiz;
		if(raiz*raiz > n){
			cotaSup = raiz;
		} else{
			cotaInf = raiz;
		}
		i++;
	}

	return raiz;
}

//Ej 4.a.
int contarCerosYUnos(vector<int> s){
	int res = 0;

	for(int i = 0 ; i < s.size() ; i++){
		res += s[i]; 
	}

	return res;
}

//Ej 4.b. considero |s| > 2
int contarCerosYUnosOrdenados(vector<int> s){
	int desde = 0, hasta = s.size()-1, m;

	if(s[0] == 1) return s.size();
	if(s[s.size()-1] == 0) return 0;

	while(s[desde] == 0 && s[desde+1] == 1){
		m = (desde+hasta)/2;
		if(s[m] == 1){
			hasta = m;
		} else {
			desde = m;
		}
	}

	return s.size() - desde;
}

/*Ej5.a.| Ejemplos: voy del 5 al 8	| 5.b. 						| 5.c.							  Peor Caso
 		| 1  2  4  5				| 1  2  4  5				| 1  2  4  5	| 1  2  4  5	| 8  8  8  5
		| 3  7  9 10				| 3  6  9 10				| 3  7  9 10	| 3  7  9 10	| 8  8  8  8
		| 6 11 15 20				| 3  8 15 20				| 6  8 15 20	| 6  8 15 20	| 8  8  8  8
		| 8 12 16 22				| 3  8 16 22				| 8  8 16 22	| 7  9 16 22	| 8  8  8  8
*///	|13 14 17 23				|13 14 17 23				| 8 14 17 23	| 8 14 17 23	| 8  8  8  8
int buscarEnMatrizOrdenada(vector<vector<int>> m, int e){
	int res = 0, i = 0, j = m.size()-1; // arranco en la esquina superior derecha

	while( i < m.size() && j >= 0){		// repito hasta caerme de la matriz
		if(m[i][j] == e) res++;
		if(m[i][j] > e){
			j--;						// si m[i][j] > e me muevo a la izaquierda
		} else {
			i++;						// si m[i][j] < e me muevo abajo
		}
	}

	return res;							// O(N+M)
} 

//Ej 5.c.
int buscarEnMatrizOrdenada(vector<vector<int>> m, int e){
	int res=0, i0, i=0, j=m.size()-1; 	// arranco en la esquina superior derecha

	while( i < m.size() && j >= 0){		// repito hasta caerme de la matriz
		
		if(m[i][j] > e){
			j--;						// si m[i][j] > e me muevo a la izaquierda
		} else if(m[i][j] < e){
			i++;						// si m[i][j] < e me muevo abajo
		} else{
			i0 = i;
			while(j >= 0 && m[i][j] == e){
				res++;
				if(i+1 < m.size() && m[i+1][j] == e){
					i++;
				} else {
					i = i0;
					j--;
				}
			}
		}
	}

	return res;							// O(N*M)
} 

//Ej 6.b.
int difEntreMaxYMin(vector<int> s){
	if(s.size() < 2) return 0;
	int max = s[0], min = s[0];

	for(int i = 1 ; i < s.size() ; i++){
		if(max < s[i]) max = s[i];
		if(min > s[i]) min = s[i];
	}

	return max - min;				// O(n)
}

//Ej 6.c.
int masApariciones(vector<int> s){				// sea n = |s|
	vector<int> apa(s.size()+1, 0);				// inicializo un vector lleno de 0 de largo |s|+1
    int primerApa;

	for(int i = 0 ; i < s.size() ; i++){		// ∑ᵢ₌₀ⁿ⁻¹ i = n(n-1)/2 = O(n²)
		primerApa = dondeAparecePrimero(s, i);
		apa[primerApa]++;
	}

	return s[ indiceDelMayor(apa) ];			// O(n²)
}

int dondeAparecePrimero(vector<int> s, int i){	// O(i)
	for(int j = 0 ; j <= i ; j++){
		if(s[i] == s[j]) return j;
	}
}

int indiceDelMayor(vector<int> s){				// O(n)
	int i = 0;
	for(int j = 0 ; j < s.size() ; j++){
		if(s[i] < s[j]) i = j;
	}
	return i;
}

//Ej 6.d.
int masAparicionesAcotados(vector<int> s, int r1, int r2){	// sea n = |s| y m = cota = r2-r1+1	CHEQUEA ESTO TAMBIEN
	vector<int> apa{};
	for(int i = 0 ; i <= r2-r1 ; i++) apa.push_back(0);		// O(m)

	for(int i = 0 ; i < s.size() ; i++){					// O(n)
		apa[ s[i]-r1 ]++;
	}

	return indiceDelMayor(apa)+r1;							// O(n+2m) si n >> m ⟶ O(n)
}

//Ej 6.e. los anteriores pero recibiendo secuencias Ordenadas
int difEntreMaxYMinOrdenado(vector<int> s){
	if(s.size() < 2) return 0;
	int max = s[0], min = s[s.size()-1];
	return max - min;						// O(1)
}

int masAparicionesOrdenado(vector<int> s){	// sea n = |s| y Pre {|s| > 0}
	int i0, apariciones = 0, masAparecido;

	for(int i = 0 ; i < s.size()-1 ; i++){	// O(n)
		i0 = i;
		while(s[i] == s[i+1]) i++;	
		if(i-i0+1 > apariciones) {
			masAparecido = s[i];
			apariciones = i-i0+1;
		}
	}

	return masApa;							// O(n)
}

// masAparicionesAcotados se puede reemplazar por masAparicionesOrdenado
// no conviene ordenar primero la secuencia, ya que eso tiene una complejidad O(n²) generalmente

//Ej 7. Se puede acotar entre mayor(s) y 1 (inclusive)
bool esDeCuentasEstaSecuencia(vector<int> s){	// sea n = |s| y m = mayor(s)
	if(s.size() == 0) return true;				// si es vacío, es de cuentas

	for(int i = 0 ; i < s.size() ; i++){		// (∀e : ℤ)(e ∈ s ⟶L 0 < e ≥ |s|)
		if(s[i] < 1 || s[i] > s.size()) return false;
	}

	int mayor = s[indiceDelMayor(s)];			// O(n)
	vector<int> apariciones(mayor, 0);			// O(m)

	for(int i = 0 ; i < s.size() ; i++){		// O(n)
		apariciones[s[i]]++;
	}

	bool esDeCuentas = true;
	for(int i = 0 ; i < apariciones.size() ; i++){	// O(m)
		esDeCuentas &= (apariciones[i] == i || apariciones[i] = 0);
	}

	return esDeCuentas;							// O(1) + 3*O(n) + 2*O(m) = O(n+m)
}

//Ej 8.
vector<char> ordenarString(vector<char> s){	// sea n = |s| y m = max(ord(s))
	if(s.size() == 0) return {};	
	int max = ord(s[0]);
	for(int i = 0 ; i < s.size() ; i++){	// O(n)
		if(max < ord(s[i])) max = ord(s[i]);
	}
	max++;

	vector<int> apariciones(max, 0);		// O(m)
	for(int i = 0 ; i < s.size() ; i++){	// O(n)
		apariciones( ord(s[i]) );
	}

	int j = 0;
	for(int i = 0 ; i < s.size() ; i++){	// O(n+m)
		while(apariciones[j] == 0) j++;
		
		s[i] = char(apariciones[j]);
		apariciones[j]--;
	}

	return s;								// O(n+m)
}

//Ej 10.
vector<int> cocktailSort(vector<int> s){	// O(n²)
	int posMin, posMax;

	for(int i = 0 ; i < s.size()/2 ; i++) {
		posMin = seleccionarMinimoDesde(s, i);
		posMax = seleccionarMaximoDesde(s, s.size()-1-i);
		swap(s, posMin, i);
		swap(s, posMax, s.size()-1-i);
	}

	return s;
}

int seleccionarMaximoDesde(vector<int> &s, int i) {	// O(n)
	int posMax = i;
	
	for(int j = i ; j >= 0 ; j--){
		if(s[posMax] < s[j]){
			posMax = j;
		}
	}

	return posMax;
}

//Ej 12.
vector<int> cocktailShakerSort(vector<int> a){
	bool hizoSwap = true;
	int i = 0;
	while(i < a.size()/2 && hizoSwap){			// O(n/2)
		hizoSwap = false;
		for(int j = 0 ; j < a.size()-1 ; j++){	// O(n)
			if (a[j] > a[j+1]) {
				swap(a, j, j+1);
				hizoSwap = true;
			}
		}
		for(int j = a.size()-2 ; j >= 0 ; j++){	// O(n)
			if(a[j] > a[j+1]){
				swap(a, j, j+1);
				hizoSwap = true;
			}
		}
		i++
	}
	return s;									// O(n/2)*2*O(n) = O(n²)
}

//Ej 14.
vector<int> bingoSort(vector<int> s){
	vector<int> minimos {};

	for(int i = 0 ; i < s.size() ; i++){		// O(n²)
		minimos = indicesMinimosDesde(s, i);	// O(n)

		for(int j = 0 ; j < minimos.size() ; j++){
			swap(s, i, minimos[j]);
			i++;
		}
	}
	return s;
}

vector<int> indicesMinimosDesde(vector<int> s, int i){
	vector<int> posMins {};

	int min = seleccionarMinimoDesde(s, i);		// O(n)

	for(int j = i ; j < s.size() ; j++){
		if(s[i] == s[j]) posMins.push_back(j);	// O(n)
	}

	return posMins;								// O(n)
}

//Ej 16.
vector<int> ordenarDosMitades(vector<int> &a) { // sea n = |a|
	if(a.size() < 2) return a;

	int med = a.size()/2;								// busco el medio
	for(int k = 1 ; k < a.size() ; k++) {				// O(n)
		if(a[k-1] > a[k]) med = k;
	}

	int i = 0, j = med;
	vector<int> res {};
	for(int k = 0; k < a.size() ; k++){					// O(n)
		if((i < med && a[i] < a[j]) || j > a.size() ){
			res[k] = a[i];
			i++;
		} else {
			res[k] = a[j];
			j++;
		}
	}

	return res;											// O(n)
}

//Ej 17.
vector<int> reconstruye(vector<int> a){		// O(n)
	vector<int> b {};

	for(int i = 0 ; i < a.size() ; i--){
		while(a[i] > 0){
			b.push_back(i);
			a[i]--;
		}
	}

	return b;
}

//Ej 18 |s| = n ∧ (∀e : ℤ)(e ∈ s ⟶L e ∈ {0,...,n})
vector<int> ordenarDescendientementeSecuenciaAcotada(vector<int> s){
	vector<int> temp {}, res {};
	
	for(int i = 0 ; i <= s.size() ; i++){		// O(n)
		temp.push_back(0);
	}

	for(int i = 0 ; i < s.size() ; i++){		// O(n)
		temp[ s[i] ]++;
	}

	for(int i = temp.size()-1 ; i >= 0 ; i--){	// O(2n)
		while(temp[i] > 0){
			res.push_back(i);
			temp[i]--;
		}
	}

	return res; 								// O(4n) ∈ O(n)
}