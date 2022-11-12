#include "Tests.h"
#include <stdlib.h>
#include <ctime>
#include <iostream>
#include "Algorithm.h"

void Tests::print_input_data(int N, int M, int *X, int *Y) {
    std::cout << std::endl << "[+] Input data:" << std::endl;
    std::cout << "N: " << N << std::endl;
    std::cout << "X: ";
    for (int i = 0; i < N; i++) {
        std::cout << X[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "M: " << N << std::endl;
    std::cout << "Y: ";
    for (int i = 0; i < M; i++) {
        std::cout << Y[i] << " ";
    }
    std::cout << std::endl;
}

void Tests::print_pending_output(int *arr, int length, int count) {
    std::cout << std::endl << "[+] Excected result:" << std::endl;
    std::cout << count << std::endl;
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void Tests::print_result(int *arr, int length, int count) {
    std::cout << std::endl << "[+] Result:" << std::endl;
    std::cout << count << std::endl;
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void Tests::easy_tests() {
    // Test #1
    int N = 5;
    int M = 5;
    int X[N] = {5, 5, 5, 5, 5};
    int answer_count = 0;
    int Y[M] = {5, 5, 5, 5, 5};
    int answer_arr[N] = {0, 0, 0, 0, 0};

    std::cout << "---Test #1 ---" << std::endl << std::endl;
    this->print_input_data(N, M, X, Y);
    this->print_pending_output(answer_arr, N, answer_count);

    Algorithm first_test(N, M, X, Y);
    int result;
    int *result_arr = first_test.solve_problem(&result);
    this->print_result(result_arr, N, result);
    if (result != answer_count) {
        std::cout << std::endl << "[-] Test #1 is not passed!" << std::endl;
        delete []result_arr;
        return;
    }
    for (int i = 0; i < N; i++) {
        if (result_arr[i] != answer_arr[i]) {
            std::cout << std::endl << "[-] Test #1 is not passed!" << std::endl;
            delete []result_arr;
            return;
        }
    }
    std::cout << std::endl << "[+] Test #1 is passed!" << std::endl;
    delete []result_arr;

    // Test #2
    N = 5;
    M = 7;
    int X2[N] = {5, 5, 5, 5, 5};
    int Y2[M] = {6, 6, 6, 6, 6, 6, 6};
    answer_count = 5;
    int answer_arr2[N] = {1, 2, 3, 4, 5};

    std::cout << std::endl << std::endl;
    std::cout << "---Test #2 ---" << std::endl << std::endl;
    this->print_input_data(N, M, X2, Y2);
    this->print_pending_output(answer_arr2, N, answer_count);

    Algorithm second_test(N, M, X2, Y2);
    result_arr = second_test.solve_problem(&result);
    this->print_result(result_arr, N, result);
    if (result != answer_count) {
        std::cout << std::endl << "[-] Test #2 is not passed!" << std::endl;
        delete []result_arr;
        return;
    }
    for (int i = 0; i < N; i++) {
        if (result_arr[i] != answer_arr2[i]) {
            std::cout << std::endl << "[-] Test #2 is not passed!" << std::endl;
            delete []result_arr;
            return;
        }
    }
    std::cout << std::endl << "[+] Test #2 is passed!" << std::endl;
    delete []result_arr;

    // Test #3
    int X3[N] = {15, 10, 13, 20, 4};
    int Y3[M] = {10, 5, 2, 6, 14, 4, 70};
    answer_count = 3;
    int answer_arr3[N] = {0, 5, 7, 0, 2};

    std::cout << std::endl << std::endl;
    std::cout << "---Test #3 ---" << std::endl << std::endl;
    this->print_input_data(N, M, X3, Y3);
    this->print_pending_output(answer_arr3, N, answer_count);

    Algorithm third_test(N, M, X3, Y3);
    result_arr = third_test.solve_problem(&result);
    this->print_result(result_arr, N, result);
    if (result != answer_count) {
        std::cout << std::endl << "[-] Test #3 is not passed!" << std::endl;
        delete []result_arr;
        return;
    }
    for (int i = 0; i < N; i++) {
        if (result_arr[i] != answer_arr3[i]) {
            std::cout << std::endl << "[-] Test #3 is not passed!" << std::endl;
            delete []result_arr;
            return;
        }
    }
    std::cout << std::endl << "[+] Test #3 is passed!" << std::endl;
    delete []result_arr;
}

void Tests::interface_for_reading_data(int *tests_generate, int *N_range, int *M_range, int *X_range, int *Y_range) {
    std::cout << "[+] How many tests need to be generated: ";
    std::cin >> *tests_generate;

    std::cout << "[+] Enter the max range for N: ";
    std::cin >> *N_range;

    std::cout << "[+] Enter the max range for Xi: ";
    std::cin >> *X_range;

    std::cout << "[+] Enter the max range for M: ";
    std::cin >> *M_range;

    std::cout << "[+] Enter the max range for Yi: ";
    std::cin >> *Y_range;
}

bool Tests::input_validation(int tests_generate, int N_range, int M_range, int X_range, int Y_range) {
    if (tests_generate < 0) return false;
    if (N_range < 0) return false;
    if (M_range < 0) return false;
    if (X_range < 0) return false;
    if (Y_range < 0) return false;
    if (M_range < N_range) return false;
    return true;
}

void Tests::random_tests() {
    int tests_generate = 0;
    int N_range = 0;
    int M_range = 0;
    int X_range = 0;
    int Y_range = 0;
    this->interface_for_reading_data(&tests_generate, &N_range, &M_range, &X_range, &Y_range);
    if (!this->input_validation(tests_generate, N_range, M_range, X_range, Y_range)) {
        std::cout << "[-] The entered data is incorrect, please try again" << std::endl;
        return;
    }

    srand(time(NULL));
    for (int i = 0; i < tests_generate; i++) {
        std::cout << std::endl << "Test #" << i + 1 << std::endl;
        int N = rand() % N_range;
        int M = rand() % M_range;
        int *X = new int[N];
        int *Y = new int[M];
        for (int j = 0; j < N; j++) {
            X[j] = rand() % X_range;
        }
        for (int j = 0; j < M; j++) {
            Y[j] = rand() % Y_range;
        }

        this->print_input_data(N, M, X, Y);

        Algorithm test(N, M, X, Y);
        int res;
        clock_t start_time = clock();
        int *res_arr = test.solve_problem(&res);
        double algorithm_time_speed = (clock() - start_time) / CLOCKS_PER_SEC;
        this->print_result(res_arr, N, res);
        std::cout << "[+] Iterations count: " << test.iteration_count << std::endl;
        std::cout << "[+] Algorithm execution time: " << algorithm_time_speed << std::endl;

        delete []res_arr;
        delete []X;
        delete []Y;
    }
}