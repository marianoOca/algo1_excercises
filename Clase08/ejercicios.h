#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <sstream>

using namespace std;

vector<vector<int>> rotar(vector<vector<int>> mat, int a, int d);
vector<vector<int> > productoVectorial(vector<int> u, vector<int> v);
void trasponer(vector<vector<int> > &m);
vector<vector<int> > multiplicar(vector<vector<int> > m1, vector<vector<int> > m2);
//Ejercicio 4
vector<vector<int> > promediar(vector<vector<int> > m);
int promedioLocal(vector<vector<int>> m, int f, int c);

int contarPicos(vector<vector<int> > m);
bool esElMayorLocal(vector<vector<int>> m, int f, int c);

bool esTriangular(vector<vector<int> > m);

bool hayAmenaza(vector<vector<int> > m);
vector<pair<int, int>> buscarReinas(vector<vector<int>> m);

int diferenciaDiagonales(vector<vector<int> > m);