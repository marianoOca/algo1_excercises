#include <string>
#include <vector>

using namespace std;

string ordenarSeq(string s);
int seleccionarMinimoDesde(string &s, int i);
void swap(string &s, int i, int j);

vector<string> split(string s, char delim);

string darVueltaPalabra(string s);
string unSplit(vector<string> s, char d);

bool subsecuencia(string s1, string s2);

vector<vector<string>> agruparAnagramas(vector<string> v);
void agregarAnagrama(vector<vector<string>> &v, string s);
bool sonAnagramas(string s1, string s2);

bool esPalindromo(string s);
bool tieneRepetidos(string s);
string rotar(string s, int j);
string darVueltaK(string s, int k);
string abueloLaino(string s);
int cantidadDeFelicitaciones(vector<string> v);
int middleOut(string s, string t);
