#include <iostream>
#include "gtest/gtest.h"

int main(int argc, char **argv) {
    std::cout << "LaboTDD - Ejecutando Tests" << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}