# include <iostream>

//  ej 2
int f( int x, int y){
    if (x > y){
        return ( x+y );
    }else{
        return ( x*y );
    }
}
//  ej 4
int esPrimo( int n ){
    int i = 2;
    while (i < n){
        if (n % i == 0) return false;
        i++;
    }
    return true;
}

//  ej 5
int fiboRecu (int n) {
    if ( n == 0 ) return 0;
    if ( n == 1 ) return 1;
    return (fiboRecu(n-1) + fiboRecu(n-2));
}

int fiboNoRecu (int n){
    int f0 = 0, f1 = 1, f2 = 1, i = 2;
    
    if ( n == 0 ) return f0;
    if ( n == 1 ) return f1;
    
    while ( i != n ){
        f0 = f1;
        f1 = f2;
        f2 =  f1 + f0;
        i++;
    }
    
    return f2;
}

//  ej 6
int menoresParesRecu(int n){
    if (n == 1) return 1;
    if (n % 2 == 1) return (n + menoresParesRecu(n-2));
    return menoresParesRecu(n-1);
}

int menoresParesNoRecu(int n){
    int sum = 0;
    
    if (n % 2 == 0) n--;
    
    while (n != 1){
        sum += n;
        n -= 2;
    }
    return sum;
}

//  ej 7
int auxSDR(int n, int m){
    if (m == 1) return 1;
    if (n % m == 0) return (m + auxSDR(n, m-1));
    return auxSDR(n, m-1);
}
int sumaDivisoresRecu(int n){
     return auxSDR(n, n);
}

int sumaDivisoresNoRecu(int n){
    int suma = 0, i = n;
    while (i != 0){
        if (n % i == 0) suma += i;
        i--;
    }
    return suma;
}
//  ej 8
int combinatorioRecu (int n, int k) {
    if (n == k) return 1;
    if (k == 1) return n;
    return (combinatorioRecu (n-1, k) + combinatorioRecu (n-1, k-1));
}
//no puede hacerse de forma iterativa usando la igualdad dada ya que en cada recursión
//las opciones se bifurcan.
int factroial(int n){
    int f = 1;
    while (n > 1){
        f = f*n;
        n--;
    }
    return f;
}

int combinatorioNoRecu (int n, int k) {
    return (factroial(n)/(factroial(n-k)*factroial(k)));
}

int main () {
    int n, k;
    std :: cout << "Dame una n!"<< std :: endl;
    std :: cin >> n;
    std :: cout << "Dame una k!"<< std :: endl;
    std :: cin >> k;
    
    n = combinatorioNoRecu(n,k);
    
    //std :: cout << (esPrimo(n) ? "true" : "false") << std::endl;
    std :: cout << "El resultado es: " << n << std :: endl ;
    return 0;
}