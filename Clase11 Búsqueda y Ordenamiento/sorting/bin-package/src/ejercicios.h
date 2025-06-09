#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// Insertion Sort
void insertionSort(vector< int > &arr);
void swap(vector<int> &s, int i, int j);

// Selection Sort
void selectionSort(vector< int > &arr);
int seleccionarMinimoDesde(vector<int> &s, int i);

//Bubble Sort
void bubbleSort(vector<int> &s);
void burbujeo(vector<int> &s, int i);

//Counting Sort
void countingSort(vector<int> &s, int cota);

// Bingo Sort
void bingoSort(vector<int> &s);
vector<int> indicesMinimosDesde(vector<int> s, int i);

void ordenar(vector<int> &items);
int bestFit(int W, vector<int> &items);