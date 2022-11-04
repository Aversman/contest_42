#define SWAP(a, b) {int t = (a); (a) = (b); (b) = t;}
#include "Algorithm.h"

void Algorithm::sort_arrays() {
    for (int i = 1; i < this->N; i++) {
        int flag = 0;
        for (int j = 0; j < this->N - i; j++) {
            if (this->X[j] > this->X[j+1]) {
                SWAP(this->X[j], this->X[j+1]);
                SWAP(this->X_indx[j], this->X_indx[j+1]);
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
    for (int i = 1; i < this->M; i++) {
        int flag = 0;
        for (int j = 0; j < this->M - i; j++) {
            if (this->Y[j] > this->Y[j+1]) {
                SWAP(this->Y[j], this->Y[j+1]);
                SWAP(this->Y_indx[j], this->Y_indx[j+1]);
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
}

int *Algorithm::solve_problem(int *counter) {
    this->sort_arrays();
    int count = 0;
    int *classes = new int[this->N];
    for (int i = 0; i < this->N; i++) {
        classes[i] = 0;
    }

    int iter = 0;
    for (int i = 0; i < this->N; i++) {
        for (int j = iter; j < this->M; j++) {
            if (this->X[i] + 1 <= this->Y[j]) {
                count++;
                classes[this->X_indx[i]] = this->Y_indx[j] + 1;
                iter = j + 1;
                break;
            }
        }
    }
    *counter = count;
    return classes;
}