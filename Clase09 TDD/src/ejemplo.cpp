#include "ejemplo.h"

using namespace std;

//Ejercicio 1
int fizzBuzz(int n){
    int fizz = -1, buzz = -2, fizzbuzz = -3;

    if(n % 3 == 0 && n % 5 == 0) return fizzbuzz;
    if(n % 3 == 0) return fizz;
    if(n % 5 == 0) return buzz;
    return n;
}

//Ejercicio 2
vector<int> factoresPrimos(int n){
    vector<int> res {};
    if(n >= 2){
        for (int i = 2; i <= n; i++) {
            if (n % i == 0) {
                res.push_back(i);
                n = n / i;
                i = 1;
            }
        }
    }
    return res;

}