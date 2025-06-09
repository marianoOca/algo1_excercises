#include "../llenarTaxis.h"
#include "gtest/gtest.h"

// 1 grupo de 1, 2 grupos de 2 y 1 grupo de 3: 2 autos
TEST(llenarTaxisTEST, dosTaxis1) {
    //exercise
    int res1 = llenarTaxis1(1, 2, 1);
    // check
    EXPECT_EQ(res1, 2);

}

TEST(llenarTaxisTEST, dosTaxis2) {
    //exercise
    int res2 = llenarTaxis2(1, 2, 1);
    // check
    EXPECT_EQ(res2, 2);
}

TEST(llenarTaxisTEST, dosTaxis3) {
    //exercise
    int res3 = llenarTaxis3(1, 2, 1);
    // check
    EXPECT_EQ(res3, 2);
}

// 2 grupos de 1, 2 grupos de 2 y 1 grupo de 3: 3 autos

TEST(llenarTaxisTEST, tresTaxis2) {
    //exercise
    int res2 = llenarTaxis2(2, 2, 1);
    // check
    EXPECT_EQ(res2, 3);
}

TEST(llenarTaxisTEST, tresTaxis3) {
    //exercise
    int res3 = llenarTaxis3(2, 2, 1);
    // check
    EXPECT_EQ(res3, 3);
}

// Por los test podemos ver que el correcto es el llenarTaxis2

TEST(llenarTaxisTEST, unTaxi) {
    //exercise
    int res2 = llenarTaxis2(1, 0, 1);
    // check
    EXPECT_EQ(res2, 1);
}

TEST(llenarTaxisTEST, noHayAutos) {
    //exercise
    int res2 = llenarTaxis2(0, 0, 0);
    // check
    EXPECT_EQ(res2, 0);
}

TEST(llenarTaxisTEST, cuatroAutos) {
    //exercise
    int res2 = llenarTaxis2(0, 1, 3);
    // check
    EXPECT_EQ(res2, 4);
}