#pragma once
#include <cstring>

class Algorithm {
    const int N; // кол-во групп
    const int M; // кол-во аудиторий
    int *X; // массив из количества человек к i группе
    int *X_indx; // индексы групп
    int *Y_indx; // индексы (номера + 1) аудиторий
    int *Y; // массив из количества компьютеров в i аудитории
    virtual void sort_arrays();
public:
    Algorithm(const int N, const int M, int *X, int *Y): N(N), M(M) {
        this->X = new int[N];
        this->X_indx = new int[N];
        this->Y = new int[M];
        this->Y_indx = new int[M];
        for (int i = 0; i < N; i++) {
            this->X_indx[i] = i;
        }
        for (int i = 0; i < M; i++) {
            this->Y_indx[i] = i;
        }
        memcpy(this->X, X, sizeof(int) * this->N);
        memcpy(this->Y, Y, sizeof(int) * this->M);
    }
    ~Algorithm() {
        delete []this->X;
        delete []this->Y;
        delete []this->X_indx;
        delete []this->Y_indx;
    }
    int *solve_problem(int *counter);
};