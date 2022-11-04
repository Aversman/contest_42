#include "Tests.h"
#include <iostream>

int main(void)
{
    int *X = new int[5];
    int *Y = new int[7];
    
    X[0] = 15;
    X[1] = 10;
    X[2] = 13;
    X[3] = 20;
    X[4] = 4;
    
    Y[0] = 10;
    Y[1] = 5;
    Y[2] = 2;
    Y[3] = 6;
    Y[4] = 14;
    Y[5] = 4;
    Y[6] = 70;

    Algorithm test(5, 7, X, Y);
    int count = 0;
    int *result = test.solve_problem(&count);
    std::cout << count << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    delete []result;
    delete []X;
    delete []Y;

    Tests my_test;
    my_test.easy_test();
    return 0;
}