#include "ejercicios.h"

vector<vector<int>> rotar(vector<vector<int>> mat, int a, int d) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> res(n, vector<int>(m));
    int i = 0;
    while(i < n) {
        int j = 0;
        while(j < m) {
            res[(i + a) % n][(j + d) % m] = mat[i][j];
            j++;
        }
        i++;
    }
    return res;
}

//Ejercicio 1
vector<vector<int>> productoVectorial(vector<int> u, vector<int> v){
    int cantFil = u.size(), cantCol = v.size();
	vector<vector<int>> res(cantFil, v);

	for(int i = 0 ; i < cantFil ; i++){
        for(int j = 0 ; j < cantCol ; j++){
            res[i][j] = u[i]*v[j];
        }
	}
	return res;
}

//Ejercicio 2
void trasponer(vector<vector<int>> &m) {
    int cantFil = m.size(), cantCol = m[0].size();
    vector<vector<int>> res(cantCol, vector<int>(cantFil));

    for(int i = 0 ; i < cantCol ; i++){
        for(int j = 0 ; j < cantFil ; j++){
            res[i][j] = m[j][i];
        }
    }
	m = res;
}

//Ejercicio 3
vector<vector<int>> multiplicar(vector<vector<int>> m1, vector<vector<int>> m2){// Pre{cantCol1 = cantFil2}
    int cantFil1 = m1.size(), cantCol1 = m1[0].size(), cantFil2 = m2.size(), cantCol2 = m2[0].size();
    vector<vector<int>> res(cantFil1, vector<int>(cantCol2));

    for(int i = 0 ; i < cantFil1 ; i++){
        for(int j = 0 ; j < cantCol2 ; j++){
            res[i][j] = 0;
            for(int k = 0 ;  k < cantFil2 ; k++) {
                res[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
	return res;
}

//Ejercicio 4
vector<vector<int>> promediar(vector<vector<int>> m){
    int cantFil = m.size(), cantCol = m[0].size();
    vector<vector<int>> res = m; //(cantFil, vector<int>(cantCol))

    for(int i = 0 ; i < cantCol ; i++){
        for(int j = 0 ; j < cantFil ; j++){
            res[i][j] = promedioLocal(m, i, j);
        }
    }
    return res;
}

int promedioLocal(vector<vector<int>> m, int f, int c){
    int cantFil = m.size(), cantCol = m[0].size(), res = 0, cant = 0;

    for(int i = f-1 ; i <= f+1 ; i++){
        for(int j = c-1 ; j <= c+1 ; j++){
            if(i>=0 && j>=0 && i<cantCol && j<cantFil){
                res += m[i][j];
                cant++;
            }
        }
    }
    return res/cant;
}

//Ejercicio 5
int contarPicos(vector<vector<int>> m){
    int cantFil = m.size(), cantCol = m[0].size(), res = 0;

    for(int i = 0 ; i < cantFil ; i++){
        for(int j = 0 ; j < cantCol ; j++){
            if(esElMayorLocal(m, i, j)){
                res++;
            }
        }
    }
    return res;
}

bool esElMayorLocal(vector<vector<int>> m, int f, int c){
    int cantFil = m.size(), cantCol = m[0].size();
    bool res = true;

    for(int i = f-1 ; i <= f+1 ; i++){
        for(int j = c-1 ; j <= c+1 ; j++){
            if(i>=0 && j>=0 && i<cantFil && j<cantCol && (i != f || j != c)){
                res &= m[f][c] > m[i][j];
            }
        }
    }
    return res;
}

//Ejercicio 6
bool esTriangular(vector<vector<int>> m){
    int size = m.size();
    if(size < 2) return false;
    if(size != m[0].size()) return false;

    bool triangularInferior = true, triangularSuperior = true;

    for(int i = 1 ; i < size ; i++){
        for(int j = i-1 ; j >= 0 ; j--){
            triangularSuperior &= m[i][j] == 0;
        }
    }

    for(int i = 0 ; i < size-1 ; i++){
        for(int j = i+1 ; j < size ; j++){
            triangularInferior &= m[i][j] == 0;
        }
    }

    return triangularSuperior || triangularInferior;
}

//Ejercicio 7
bool hayAmenaza(vector<vector<int>> m){
    vector<pair<int, int>> reinas = buscarReinas(m);
    int cantReinas = reinas.size();
	bool mismaFil = false, mismaCol = false, mismaDiago = false;

	for(int i = 0 ;  i < cantReinas ; i++){
        for(int j = 1 ;  j < cantReinas ; j++){
            if(!(reinas[i].first == reinas[j].first && reinas[i].second == reinas[j].second)){
                if(reinas[i].first == reinas[j].first) mismaFil = true;
                if(reinas[i].second == reinas[j].second) mismaCol = true;

                if(abs(reinas[i].first - reinas[j].first) ==
                   abs(reinas[i].second - reinas[j].second)) mismaDiago = true;
            }
        }
	}
    return mismaFil || mismaCol || mismaDiago;
}

vector<pair<int, int>> buscarReinas(vector<vector<int>> m){
    int cantFil = m.size(), cantCol = m[0].size();
    vector<pair<int, int>> res {};
    vector<int> reina;

    for(int i = 0 ; i < cantFil ; i++){
        for(int j = 0 ; j < cantCol ; j++){
            if(m[i][j] == 1) {
                res.push_back(make_pair(i, j));
            }
        }
    }
    return res;
}

//Ejercicio 8
int diferenciaDiagonales(vector<vector<int>> m) {
    int diago1 = 0, diago2 = 0, size = m.size();

    for(int i = 0 ; i < size ; i++){
        diago1 += m[i][i];
        diago2 += m[i][size-1-i];
    }

    return abs(diago1 - diago2);
}