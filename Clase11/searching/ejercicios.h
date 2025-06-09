#include <vector>
#include <string>

using namespace std;

int busquedaLineal(vector<int> v, int x);
int busquedaBinariaEntre(vector<int> s, int desde, int hasta, int x);
int busquedaJumpSearch(vector<int> v, int x);
int busquedaLinealInversaDesdePor(vector<int> v, int i, int n, int x);
int buscar(vector<int> v, int x);
double ejemplo_como_calcular_tiempos();
vector<int> construir_vector(int size, string mode);
int indicePico(vector<int> v);
int puntoFijo(vector<int> v);
int encontrarRotado(vector<int> v, int x);
int buscarMenor(vector<int> v);
bool esElMenor(vector<int> v, int i);
int menorMasGrande(vector<int> v, int x);
vector<int> masCercanoK(vector<int> v, int k,  int x);
