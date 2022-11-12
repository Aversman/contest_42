#include <iostream>
#include "Tests.h"
#include "Interface.h"

void Interface::interface_init() {
    Tests tests;
    int test_count = 0;
    std::cout << std::endl << "Problem #42" << std::endl;
    std::cout << std::endl << "1) Self-written obvious tests with answers" << std::endl;
    std::cout << "2) Generated tests with given ranges" << std::endl << std::endl;
    std::cout << "Enter tests number to get started: ";
    std::cin >> test_count;
    if (test_count != 1 && test_count != 2) {
        std::cout << "[-] Invalid input" << std::endl;
        return;
    }
    std::cout << std::endl;
    if (test_count == 1) {
        tests.easy_tests();
    }else {
        tests.random_tests();
    }
}