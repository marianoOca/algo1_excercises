#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "anagramas.h"
using namespace std;

int main(){
    string palabra, palabra2;
    cout << "Ingrese una palabra en ingles con letras en minuscula:" << endl;
    cin >> palabra;

    ifstream dicci ("ingles.dic");
    vector<string> listaPalabras;
    string word;
    while(getline(dicci, word)){
        listaPalabras.push_back(word);
    }
    int cantidadAnagrama = 0;
    for (int i = 0; i < listaPalabras.size(); ++i)
    {
        if (esAnagrama(listaPalabras[i], palabra)) {
            cout << "Son anagramas: " << listaPalabras[i] << " y " << palabra << endl;
            cantidadAnagrama++;
        }
    }
    cout << "La cantidad de anagramas es: " << cantidadAnagrama << endl;
    return 0;
}

bool esAnagrama(string p1, string p2){ //devuelve true sii p1 es anagrama de p2
    return esAnagrama1(p1,p2);  // CAMBIAR AQUI QUE IMPLEMENTACION USAR
    return esAnagrama2(p1,p2);
}

// Anagrama 1: versión de ordenar
bool esAnagrama1(string p1, string p2){ //esta versión usa ordenar
    ordenarString(p1);
    ordenarString(p2);
    return p1 == p2;
}

// Anagrama 2: versión de los primos usando el teorema fundamental del álgebra
bool esAnagrama2(string p1, string p2){
    int size = p1.size(), res1 = 1, res2 = 1;
    if(size != p2.size()) return false;

    for(int i = 0 ; i < size ; i++){
        res1 = res1 * charToPrimo(p1[i]);
        res2 = res2 * charToPrimo(p2[i]);
    }

	return res1 == res2;
}

// Auxiliares anagrama 1
void ordenarString(string &s){
        int posMin;
        for(int i = 0 ; i < s.size() ; i++) {
            posMin = seleccionarMinimoDesde(s ,i);
            swap(s, i, posMin);
        }
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

// Auxiliares anagrama 2
int charToPrimo(char c){
    int n = c - 'a'+1;
	return nEsimoPrimo(n);
}

int nEsimoPrimo(int n){
    int p, i =2;
    while(n > 0){
        i++;
        if(esPrimo(i)) n--;
    }
    return i;
}

bool esPrimo(int n){
    if(n < 2) return false;
    for(int i = 2 ; i < n ; i++) if(n%i == 0) return false;
    return true;
}

int posicionEnAlfabeto(char c){
    return c - 'a';
}
