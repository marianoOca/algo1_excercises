#include "../electores.h"
#include "gtest/gtest.h"

// Escribir tests aca:
TEST(electoresTEST, unDosTres){
    int res = validarVotante(1,2,3);
    EXPECT_EQ(res, ERROR);
}

TEST(electoresTEST, unMenor){
    int res = validarVotante(1,11,2010);
    EXPECT_EQ(res, NO_VOTA);
}

TEST(electoresTEST, unoDe16){
    int res = validarVotante(22,10,2004);
    EXPECT_EQ(res, OPCIONAL_MENOR);
}

TEST(electoresTEST, yo){
    int res = validarVotante(26,4,2000);
    EXPECT_EQ(res, OBLIGATORIO);
}

TEST(electoresTEST, laAbuela){
    int res = validarVotante(31,2,1933);
    EXPECT_EQ(res, OPCIONAL_MAYOR);
}

TEST(electoresTEST, unoDe160){
    int res = validarVotante(21,10,1860);
    EXPECT_EQ(res, ERROR);
}
