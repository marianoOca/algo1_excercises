#include "vectores.h"

// Función para probar en main.cpp si este módulo fue cargado correctamente
void holaModuloVectores(){
    cout << "El módulo vectores fue cargado correctamente" << endl;
}


//Ejercicio: Dados un vector v y un int a, decide si a divide a todos los numeros de v.
bool divide(vector<int> v, int a){
    int i = 0;
    bool res = true;
    
    while(i < v.size()){
        res = res && (v[i] % a == 0);
        i++;
    }
    
    return res;
}

//Ejercicio: Dado un vector v, devuelve el valor maximo encontrado.
int mayor(vector<int> v){
	int i = 0;
	int res = v[0];
	
	while(i < v.size()){
        if(v[i] > res) res = v[i];
        i++;
    }
    
    return res;
}

//Ejercicio: Dado un vector v, devuelve el reverso.
vector<int> reverso(vector<int> v){
	int i = (v.size() - 1);
	vector<int> res {};
	
	while (i > -1){
	    res.push_back(v[i]);
	    i--;
	}
	
	return res;
}

//Ejercicio: Dado un vector v y un entero k, rotar k posiciones los elementos de v.
vector<int> rotar(vector<int> v, int k){
	int i;
	vector<int> res {};
	
	k = k % v.size();
	
	while (i < v.size()){
	    if (i + k < v.size()){
	        res.push_back(v[i+k]);
	    }else{
	        res.push_back(v[i+k-v.size()]);
	    }
	    i++;
	}
	return res;
}

//Ejercicio: Dado un vector v de enteros no repetidos, devuelve verdadero si el mismo está ordenado
bool estaOrdenado(vector<int> v){
    bool deMayorAMenor = true, deMenorAMayor = true;
    
    int i = 1;
    while (i < v.size()){
        deMenorAMayor = deMenorAMayor && v[i-1] <= v[i];
        i++;
    }
    
    i = 1;
    while (i < v.size()){
        deMayorAMenor = deMayorAMenor && v[i-1] >= v[i];
        i++;
    }
    
    return deMayorAMenor || deMenorAMayor;
}

//Ejercicio: que dado un entero devuelve un vector con los factores primos del mismo
bool esPrimo(int n){
    int i = 2;
    bool res = true;
    
    if (n < 2) return false;
    
    while( i < n){
        res = res && (n % i != 0);
        i++;
    }
    
    return res;
}

vector<int> factoresPrimos(int n){
	int i = 2;
	vector<int> res {1};
	
	while(i < n){
	    if(esPrimo(i) && (n % i == 0)) res.push_back(i);
	    i++;
	}
	
	return res;
}

//Ejercicio: que dado un vector de enteros muestra por la salida estándar, el vector
void mostrarVector(vector<int> v){
    printf("[");
    for(int i=0; i < v.size(); i++){
        if(i < v.size()-1){
            std::cout << v[i] << " ,";
        } else {
            std::cout << v[i] << "]\n";
        }
    }
	// Ejemplo: si el vector es <1, 2, 5, 65> se debe mostrar en pantalla [1, 2, 5, 65]
}
