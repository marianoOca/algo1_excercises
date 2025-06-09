#include "gtest/gtest.h"
#include <vector>
#include "../src/ejemplo.h"

using namespace std;

//Ejercicio 1
int fizz = -1, buzz = -2, fizzbuzz = -3;

TEST(fizzBuzzTEST, nIguaAUno) {
    int res = fizzBuzz(1);
    EXPECT_EQ(res, 1);
}

TEST(fizzBuzzTEST, nIguaAOnce) {
    int res = fizzBuzz(11);
    EXPECT_EQ(res, 11);
}

TEST(fizzBuzzTEST, nIguaANueve) {
    int res = fizzBuzz(9);
    EXPECT_EQ(res, fizz);
}

TEST(fizzBuzzTEST, nIguaADiez) {
    int res = fizzBuzz(10);
    EXPECT_EQ(res, buzz);
}

TEST(fizzBuzzTEST, nIguaAQuince) {
    int res = fizzBuzz(15);
    EXPECT_EQ(res, fizzbuzz);
}

//Ejercicio 2
TEST(factoresPrimosTEST, nIguaAUno) {
    vector<int> res = factoresPrimos(1);
    vector<int> esperado {};
    EXPECT_EQ(res, esperado);
}

TEST(factoresPrimosTEST, nIguaADos) {
    vector<int> res = factoresPrimos(2);
    vector<int> esperado {2};
    EXPECT_EQ(res, esperado);
}

TEST(factoresPrimosTEST, nIguaANueve) {
    vector<int> res = factoresPrimos(9);
    vector<int> esperado {3,3};
    EXPECT_EQ(res, esperado);
}

TEST(factoresPrimosTEST, nIguaACincuentaySeis) {
    vector<int> res = factoresPrimos(56);
    vector<int> esperado {2,2,2,7};
    EXPECT_EQ(res, esperado);
}

TEST(factoresPrimosTEST, nIguaANumeroGrande) {
    vector<int> res = factoresPrimos(25323960);
    vector<int> esperado {2,2,2,3,5,19,29,383};
    EXPECT_EQ(res, esperado);
}