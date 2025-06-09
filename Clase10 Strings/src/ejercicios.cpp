#include "ejercicios.h"

/* Para compilar */ 

using namespace std;

string ordenarSeq(string s){
    int posMin;
    for(int i = 0 ; i < s.size() ; i++) {
        posMin = seleccionarMinimoDesde(s ,i);
        swap(s, i, posMin);
    }
    return s;
}

int seleccionarMinimoDesde(string &s, int i){
    int posMin = i;
    for(int j = i ; j < s.size() ; j++){
        if( s[posMin] > s[j]) posMin = j;
    }
    return posMin;
}

void swap(string &s, int i, int j){
    char k = s[i];
    s[i] = s[j];
    s[j] = k;
}

//Ejercicio 1
vector<string> split(string s, char delim){
	vector<string> v {};
	string palabra;
	int largo = s.size();

	for(int i = 0 ; i < largo ; i++){
	    palabra = {};
	    while(s[i] != delim && i < largo){
	        palabra.push_back(s[i]);
	        i++;
	    }
	    if(palabra.size() > 0) v.push_back(palabra);
	}

	return v;
}

//Ejercicio 2
string darVueltaPalabra(string s){
	vector<string> palabras = split(s, ' '), nuevoOrden {};
	int cantPalabras = palabras.size();

	for(int i = cantPalabras-1 ; i >= 0 ; i--){
	    nuevoOrden.push_back(palabras[i]);
	}

	return unSplit(nuevoOrden, ' ');;
}

string unSplit(vector<string> s, char d){
    string res {};

    for(int i = 0 ; i < s.size() ; i++){
        for(int j = 0 ; j < s[i].size() ; j++){
            res.push_back(s[i][j]);
        }
        if(i < s.size()-1) res.push_back(d);
    }

    return res;
}

//Ejercicio 3: Decidir si s1 es substring o subsecuencia de s2
bool subsecuencia(string s1, string s2) {
	int j = 0;

    for(int i = 0 ;  i < s2.size() ; i++){
        if( j < s1.size() && s1[j] == s2[i]) j++;
    }

	return j == s1.size();
}

//Ejercicio 4: Mismo orden relativo de conjunto de anagramas y dentro de cada vector y con repetidos
vector<vector<string>> agruparAnagramas(vector<string> v){
	vector<vector<string>> res {};
	for(int i = 0 ; i < v.size() ; i++){
        agregarAnagrama(res, v[i]);
	}
	return res;
}

void agregarAnagrama(vector<vector<string>> &v, string s){
    int i = 0, size = v.size();
    while(i < size && !sonAnagramas(v[i][0], s)) i++;

    if(i < size){
        v[i].push_back(s);
    } else {
        v.push_back({s});
    }
}

bool sonAnagramas(string s1, string s2){
    s1 = ordenarSeq(s1);
    s2 = ordenarSeq(s2);
    return s1 == s2;
}

//Ejercicio 5
bool esPalindromo(string s){
	string espejo {};
	for(int i = s.size()-1 ; i >= 0 ; i--) espejo.push_back(s[i]);
	return s == espejo;
}

//Ejercicio 6
bool tieneRepetidos(string s){
	int size = s.size();
    bool distinto = true;

	for(int i = 0 ; i < size ; i++){
	    for(int j = i+1 ; j < size ; j++){
	        distinto &= s[i] != s[j];
	    }
	}

	return !distinto;
}

//Ejercicio 7
string rotar(string s, int j){
	int size = s.size();
    string res = s;

    for(int i = 0 ; i < size ; i++){
        res[ (i+j) % size ] = s[i];
    }

	return res;
}

//Ejercicio 8 (no se puede usar substring)
string darVueltaK(string s, int k){
	int size = s.size(); string res {};

	for(int i = k-1 ; i < size ; i += k) for(int j = i ; j > i-k ; j--) res.push_back(s[j]);

	if(size%k != 0) for(int i = size-1 ; i > size-size%k ; i--) res.push_back(s[i]);

	return res;
}

//Ejercicio 9: en risas.cpp

//Ejercicio 10.1
string abueloLaino(string s){
    string res;
    return res;
}

//Ejercicio 10.2
int cantidadDeFelicitaciones(vector<string> v){
    int res;
    return res;
}

//Ejercicio 10.2
int middleOut(string s, string t){

    return 0;
}
