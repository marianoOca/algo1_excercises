#include "ejercicios.h"
#include "time.h"
#include <ctime>
#include "stdlib.h"
#include <string>
#include<iostream>

using namespace std;

int busquedaLineal(vector<int> v, int x){
    for(int i = 0 ; i < v.size() ; i++) if(v[i] == x) return i;
    return -1;
}
/*
int busquedaBinariaEntre(vector<int> lista, int desde, int hasta, int x){
    while (desde <= hasta){
        int medio = desde + (hasta-desde)/2;
        if (lista[medio] == x) return medio; //encontre el elemento
         if (lista[medio] < x){
            desde = medio + 1; //esta en la mitad derecha
         }else{
            hasta = medio - 1; //esta en la mitad izquierda
        }
    }
    return -1;
}//*/
///*
int busquedaBinariaEntre(vector<int> s, int desde, int hasta, int x){
    int size = hasta-desde+1, m;
    if(s.size() == 0) return -1;
    if( size <= 2 && s[desde] == x ) return desde;
    if( size == 2 && s[hasta] == x ) return hasta;
    if((size <= 2 && s[desde] != x) ||
       (size == 2 && s[hasta] != x)) return -1;

    while(hasta > desde+1) {
        m = (desde + hasta)/2;
        if(s[m] > x) {	// esta en la mitad izquierda
            hasta = m;
        } else { 		// esta en la mitad derecha
            desde = m;
        }
    }
    if (s[desde] == x) return desde;
    if (s[hasta] == x) return hasta; //encontre el elemento
    return -1;
}//*/

int busquedaJumpSearch(vector<int> v, int x){
                                    int perilla = 1;
    int n = 5*perilla, res = -1, size = v.size();

    if(v[size-1] < x) return res;

    int i = 0;
    while(i < size && res == -1){
        if(v[i] > x){
            res = busquedaLinealInversaDesdePor(v, i, n, x);
        }
        i += n;
    }

    if( i >= size){
        res = busquedaLinealInversaDesdePor(v, size-1, n, x);
    }

    return res;
}

int busquedaLinealInversaDesdePor(vector<int> v, int i, int n, int x){
    int res = -1;
    for(int j = i ; j >= 0 && j >= i-n ; j--){
        if(v[j] == x) res = j;
    }
    return res;
}

int buscar(vector<int> v, int x){
    return busquedaLineal(v, x);
    return busquedaBinariaEntre(v, 0, v.size()-1, x);
    return busquedaJumpSearch(v, x);
}


double ejemplo_como_calcular_tiempos() {
    clock_t t0 = clock();

    for(int i=0 ; i < 100000; i++){
        // nada
    }

    clock_t t1 = clock();
    double elapsed_msecs = double(t1 - t0) / CLOCKS_PER_SEC  * 1000; // mide el tiempo en milisegundos
    return elapsed_msecs;
}

vector<int> construir_vector(int size, string mode){
    vector<int> res {};
    time_t t;
    srand((unsigned) time(&t));
    int base = rand() % 100;
    int step;
    for(int i = 0; i < size; i++){
        step = rand() % 100;
        if(mode == "asc") {
            res.push_back(base+step);
            base += step;
        }
        if(mode == "desc"){
            res.push_back(base-step);
            base -= step;
        }
        if(mode == "azar"){
            res.push_back(step);
        }
        if(mode == "iguales"){
            res.push_back(base);
        }
    }
    return res;
}

//Ejercio 4
int indicePico(vector<int> v){
	int size = v.size();
    if(size == 1 || v[0] > v[1]) return 0;
    if(v[size-1] > v[size-2]) return size-1;

    for(int i = 1 ; i < size-1 ; i++){
        if(v[i-1] < v[i] && v[i+1] < v[i]) return i;
    }

    return -1;
}

//Ejercio 5
int puntoFijo(vector<int> v){
    int desde = 0, hasta = v.size();

    while (desde <= hasta) {
        int medio = desde + (hasta - desde) / 2;
        if (v[medio] == medio) {
            return medio; //encontre el elemento
        }
        if (v[medio] < medio) {
            desde = medio + 1; //esta en la mitad derecha
        } else {
            hasta = medio - 1; //esta en la mitad izquierda
        }
    }

    return -1;
}

//Ejercio 6
int encontrarRotado(vector<int> v, int x){
    int size = v.size();
	if(size == 1 && v[0] == x) return 0;
    if(size == 1 && v[0] != x) return -1;
    int indiceMenor = buscarMenor(v);

    if(indiceMenor == 0) return busquedaBinariaEntre(v, 0, size, x);
    if(x >= v[0]){  //Esta antes del mín
        return busquedaBinariaEntre(v, 0, indiceMenor-1, x);
    } else {    // x <= v[size-1] está después del min
        return busquedaBinariaEntre(v, indiceMenor, size-1, x);
    }
}

int buscarMenor(vector<int> v){
    int desde = 0, hasta = v.size()-1;

    while (desde <= hasta) {
        int m = desde + (hasta - desde) / 2;
        if(v[m] < v[m+1] && v[m] < v[m-1]) return m; //encontre el elemento
        if (v[m] > v[hasta]) {
            desde = m + 1; //esta en la mitad derecha
        } else {
            hasta = m - 1; //esta en la mitad izquierda
        }
    }

    hasta = v.size()-1;
    if(v[hasta] < v[hasta-1]) return hasta;
    return 0; // v[0] < v[1]
}

//Ejercio 7
int menorMasGrande(vector<int> v, int x){
    int hasta = v.size()-1, desde = 0, medio;

	if( x > v[hasta]) return -1;

    while (desde <= hasta){
        medio = desde + (hasta-desde)/2;
        if (v[medio] == x) return medio; //encontre el elemento
        if (v[medio] < x){
            desde = medio + 1; //esta en la mitad derecha
        }else{
            hasta = medio - 1; //esta en la mitad izquierda
        }
    }

    return medio;
}

//Ejercio 8
vector<int> masCercanoK(vector<int> v, int k,  int x){
	return {};
}
