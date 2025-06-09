#include "ejercicios.h"


// Ejercicio 1
bool existePico(vector<int> v){
    int i = 1;
    bool res = false;
    
    while (i < v.size()-1){
        res = res || (v[i-1] < v[i] && v[i+1] < v[i]);
        i++;
    }
	return res;
}

// Ejercicio 2
int mcd(int m, int n){
    int i = m;
    
    while (!(n % i == 0 && m % i == 0)){
        i--;
    }
    
	return i;
}

// Ejercicio 3
int indiceMinSubsec(vector<int> v, int l, int r){
    int i = r, res = r;
    
    while (i >= l){
        if (v[i] < v[res]) res = i;
        i--;
    }
    
	return res;
}

// Ejercicio 4
bool estaOrdenado(vector<int> v){
    int i = 0;
    bool res = true;
    
    while(i < v.size()-1){
        res = res && (v[i] <= v[i+1]);
        i++;
    }
    
    return res;
}

void ordenar1(vector<int>& v){
    int i = 0;
    
    while(!estaOrdenado(v)){
        while(i < v.size()-1){
            if(v[i] > v[i+1]){
                int a = v[i];
                v[i] = v[i+1];
                v[i+1] = a;
            }
            i++;
        }
        i=0;
    }
    
	return;
}

// Ejercicio 5
int cant(int n, vector<int> v){
    int i = 0, res = 0;
    
    while(i < v.size()){
        if(v[i] == n) res++;
        i++;
    }
    
    return res;
}

void ordenar2(vector<int>& v){
    //ordenar1(v);
    int i = 0, v0 = cant(0, v), v1 = cant(1, v), v2 = cant(2, v);

    v = {};
    while(i < v0){
        v.push_back(0);
        i++;
    }

    i = 0;
    while(i < v1){
        v.push_back(1);
        i++;
    }

    i = 0;
    while(i < v2){
        v.push_back(2);
        i++;
    }

    return;
}

// Ejercicio 6
tuple<int,int> division(int n, int d){
	return make_tuple(n / d,n % d);
}
