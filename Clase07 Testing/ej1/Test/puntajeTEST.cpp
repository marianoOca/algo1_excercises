#include "../puntaje.h"
#include "gtest/gtest.h"

// Escribir tests aca:
TEST(puntajeTEST, numero9) {
    // setup
    int b = 9;
    //exercise
    int result = puntaje(b);
    // check
    EXPECT_EQ(result,28);
}

TEST(puntajeTEST, numero10) {
    // setup
    int b = 10;
    //exercise
    int result = puntaje(b);
    // check
    EXPECT_EQ(result, 0);
}