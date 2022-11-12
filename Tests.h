#pragma once

class Tests {
    virtual void print_input_data(int N, int M, int *X, int *Y);
    virtual void print_pending_output(int *arr, int length, int count);
    virtual void print_result(int *arr, int length, int count);
    virtual void interface_for_reading_data(int *tests_generate, int *N_range, int *M_range, int *X_range, int *Y_range);
    virtual bool input_validation(int tests_generate, int N_range, int M_range, int X_range, int Y_range);
public:
    void easy_tests();
    void random_tests();
};