#ifndef ANAGRAMAS_H_
#define ANAGRAMAS_H_
using namespace std;

void ordenarString(string &s);
int seleccionarMinimoDesde(string &s, int i);
void swap(string &s, int i, int j);

int charToPrimo(char c);
int nEsimoPrimo(int n);
bool esPrimo(int n);

int posicionEnAlfabeto(char c);
bool esAnagrama(string p1, string p2);
bool esAnagrama1(string p1, string p2);
bool esAnagrama2(string p1, string p2);


#endif /* ANAGRAMAS_H_ */
