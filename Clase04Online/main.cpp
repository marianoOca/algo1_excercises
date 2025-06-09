#include "generador.h"
#include "vectores.h"
#include <iostream>
#include <fstream>	
#include <string>
//#include <stdio.h>

using namespace std;

//Ej 8: leer (ej: 1 2 34 4 45) un archivo y devolver un vector con los números en el mismo orden.
vector<int> leerVector(string nombreArchivo){
    ifstream fin; vector<int> v = {}; int n;
    
    fin.open(nombreArchivo, ios::in);
    while(!fin.eof()){
        fin >> n;
        v.push_back(n);
    }
    fin.close();
    
    mostrarVector(v);
    return v;
}

//Ej 9: Dado un vector de enteros, grabar sus elementos en un archivo cuyo nombre viene como parámetro de entrada. 
void guardarVector(vector<int> v, string nombreArchivo){
    ofstream fout;

    fout.open(nombreArchivo, ios_base::app);
    fout << "[";
    for(int i=0; i < v.size(); i++){
        if(i < v.size()-1){
            fout << v[i] << " ,";
        } else {
            fout << v[i] << "]\n";
        }
    }
    fout.close();
}

//Ej 10: Encontrar el primer elemento tal que los elementos a su izquierda sumen más que los que están a su derecha.
int sumaALaIzquierda(vector<int> v, int i){
    int sum = 0; i;
    while(i > -1){
        sum += v[i];
        i--;
    }
    return sum;
}

int sumaALaDerecha(vector<int> v, int i){
    int sum = 0; i++;
    while(i < v.size()){
        sum += v[i];
        i++;
    }
    return sum;
}

int elementoMedio(vector<int> v){
    int i = 0;
    while(i < v.size()){
        if(sumaALaIzquierda(v, i) > sumaALaDerecha(v, i)){
            return i+1;
        }
        i++;
    }
}

//Ej 11: contar la cantidad de apariciones de cada uno
bool esPrimeraAparicion(int i, vector<int> v){
    int j = i - 1;
    bool res = true;
    
    while(j > -1){
        res = res && v[i] != v[j];
        j--;
    }
    return res;
}

int apariciones(int n, vector<int> v){
    int i = 0, res = 0;
    
    while(i < v.size()){
        if(n == v[i]) res ++;
        i++;
    }
    return res;
}

void cantApariciones(string nombreArchivo){
    ofstream fout; vector<int> v = {}; int linea = 1;
    
    v = leerVector(nombreArchivo);
    
    fout.open("nombreArchivo.txt", ios_base::app);
    for(int i=0; i < v.size(); i++){
        if( esPrimeraAparicion(i, v) ){
            fout << "\nlinea " << linea << ": " << v[i] << " "<< apariciones(v[i], v);
            linea ++;
        }
    }
    fout.close();
}

//Ej 12: Ingresar una palabra a buscar  y un archivo y devolver la cantidad de apariciones de la palabra.

int cantidadAparicionesDePalabra(string nombreArchivo, string palabra){
    ifstream fin; string s; int sum = 0;
    
    fin.open(nombreArchivo, ios::in);
    while(!fin.eof()){
        fin >> s;
        if (s == palabra) sum ++;
    }
    fin.close();
    
    return sum;
}

//Ej 13: Dados dos archivos , guardar el promedio de cada par de números que se encuentran en la misma posición.
void promedio(string nombreArchivoIn1, string nombreArchivoIn2, string nombreArchivoOut){
    ifstream fin; vector<int> v = {}; int n, i = 0;
    
    v = leerVector(nombreArchivoIn1);
    
    fin.open(nombreArchivoIn2, ios::in);
    while(!fin.eof()){
        fin >> n;
        v[i] = (v[i] + n)/2.0;
        i++;
    }
    fin.close();
    
    guardarVector(v, nombreArchivoOut);
}

//Ej 14: 
vector<int> ordenarVector(vector<int> v){
}

void ordenarSecuencias(string nombreArchivoIn1, string nombreArchivoIn2, string nombreArchivoOut){
    vector<int> v1 = {}, v2 = {}, vo = {}; int i = 0, j = 0;
    
    v1 = leerVector(nombreArchivoIn1);
    v2 = leerVector(nombreArchivoIn2);
    
    while(i < v1.size() || j < v2.size()){
        if(i < v1.size() && j < v2.size()){
            if(v1[i] < v2[j]){
                vo.push_back(v1[i]);
                i++;
            }else{//v1[i] >= v2[j]
                vo.push_back(v2[j]);
                j++;
            }
        }else{
            if(i < v1.size()){
                vo.push_back(v1[i]);
                i++;
            }else{//j < v2.size()
                vo.push_back(v2[j]);
                j++;
            }
        }
    }
    
    guardarVector(vo, nombreArchivoOut);
}

//Ej 15: intersecame esta
void interseccion(vector<int> v1, vector<int> v2){
    vector<int> vo = {}; int i = 0, aparEnV1, aparEnV2;
    /*
    string nombreArchivoIn1, nombreArchivoIn2; vector<int> v1 = {}, v2 = {};
    getline(cin, nombreArchivoIn1);
    getline(cin, nombreArchivoIn2);
    v1 = leerVector(nombreArchivoIn1);
    v2 = leerVector(nombreArchivoIn2);//*/
    
    while(i < v1.size()){
        if(esPrimeraAparicion(i, v1)){
            
            aparEnV1 = apariciones(v1[i], v1);
            aparEnV2 = apariciones(v1[i], v2);
            
            if( aparEnV1 < aparEnV2 ){
                while(apariciones(v1[i], vo) < aparEnV1){
                    vo.push_back(v1[i]);
                }
            } else {//aparEnV2 <= aparEnV1
                while(apariciones(v1[i], vo) < aparEnV2){
                    vo.push_back(v1[i]);
                }
            }
        }
        i++;
    }
    
    mostrarVector(vo);
}

int main() {
    holaModuloVectores(); // función definida en vectores.cpp
    //generarDatosLaboratorio(); // descomentar para crear automaticamente los archivos necesarios en la parte de entrada-salida. Una vez creados, se puede volver a comentar
    string s = {}, s1 = {"elementoMedio.in"}, s2 = {"nombreArchivo.txt"}, s3 ={"10000NumerosEntre1y50.in"};
    string s4 = {"cantidadAparicionesDePalabra.in"}, s5 = {"ordenarSecuencia1.in"}, s6 = {"ordenarSecuencia2.in"};
    vector<int> v1 {3,3,3,2,1,-9,-90}, v2 {-90, 1, 11, 1, 3, 3}; int n;
    char c;
    
    interseccion(v1, v2);
    
    //std::cout << cantidadAparicionesDePalabra(s2, s);
    
    return 0;
}
