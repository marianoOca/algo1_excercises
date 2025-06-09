#include "../baldosasDelPiso.h"
#include "gtest/gtest.h"


TEST(baldosasTEST, aulaRidiculamenteChica){
    int res = baldosasDelPiso(1,1,1);
    EXPECT_EQ(res, 1);
}

TEST(baldosasTEST, aula4x4){
    int res = baldosasDelPiso(4,4,2);
    EXPECT_EQ(res, 4);
}

TEST(baldosasTEST, pasillo){
    int res = baldosasDelPiso(1,6,3);
    EXPECT_EQ(res, 2);
}

TEST(baldosasTEST, otraAulaRidiculamenteChica){
    int res = baldosasDelPiso(2,2,3);
    EXPECT_EQ(res, 1);
}

TEST(baldosasTEST, aulaDe9x11){
    int res = baldosasDelPiso(9,11,2);
    EXPECT_EQ(res, 30);
}

TEST(baldosasTEST, otraAulaDe9x11){
    int res = baldosasDelPiso(9,11,3);
    EXPECT_EQ(res, 12);
}