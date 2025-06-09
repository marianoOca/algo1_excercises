#include <iostream>
#include <math.h>

int ej4(){
    int n, ac = 0, i = 0;
    printf("dame un binario\n");
    std :: cin >> n;
    
    while(n != 0){
        ac = ac + (pow(2,i))*(n % 10);
        i++;
        n = n / 10;
    }
    
    std :: cout << "En decimal es: " << ac << std :: endl ;
    return 0;
}

int ej5(){
    float rad, pi = 3.14159;
    printf("dame una radio\n");
    std :: cin >> rad;
    std :: cout << "El diametro es: " << 2*rad << std :: endl ;
    std :: cout << "La circunferencia es: " << 2*rad*pi << std :: endl ;
    std :: cout << "El area es: " << rad*rad*pi << std :: endl ;
    return 0;
}

//ej 6
int triplicarPorValor(int valor){
    valor = 3*valor;
    return valor;
}

void triplicarPorReferencia(int& valor){ valor = 3*valor; }

//ej 7
void swap(int& a, int& b){
    int c = a;
    a = b;
    b = c;
}

//ej 8
void collatzIter(int n, int& cantPasos){
    while(n != 1){
        if(n % 2 == 0){
            n = n / 2;
        }else{
            n = 3*n + 1;
        }
        std :: cout << n << " " << std :: endl ;
        cantPasos ++;
    }
    cantPasos ++;
}

void collatzRecu(int n, int& cantPasos){
    cantPasos ++;
    std :: cout << n << " " << std :: endl ;
    if(n != 1){
        if(n % 2 == 0){
            collatzRecu(n/2, cantPasos);
        }else{
            collatzRecu(3*n + 1, cantPasos);
        }
    }
}

int ej8(){
    int n, cantPasos = 0;
    
    printf("dame un numerito\n");
    std :: cin >> n;
    
    collatzIter(n, cantPasos);
    //collatzRecu(n, cantPasos);
    
    std :: cout << "Cantidad de pasos: " << cantPasos << std :: endl;
    return 0;
}

//ej 9
int division(){
    int dividendo, divisor;
    printf("dame un dividendo: ");
    std :: cin >> dividendo;
    printf("dame un divisor: ");
    std :: cin >> divisor;
    
    std :: cout << "cociente: " << dividendo / divisor << std :: endl;
    std :: cout << "resto: " << dividendo % divisor << std :: endl;
    return 0;
}

int main(){
    return division();
}
