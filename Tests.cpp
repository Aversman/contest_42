#include "Tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Tests::easy_test() {
    srand(time(NULL));
    unsigned int rand_num = rand() % 1000;
    printf("%d\n", rand_num);
}