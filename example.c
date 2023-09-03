#include "src/prng.h"
#include <stdio.h>
#include <stdlib.h>

#define ITER 100

int main() {
    struct prng r;
    prng_seed(&r, 42);
    printf("Random int:\n");
    for (int i = 0; i < ITER; ++i) {
        printf("%d ", randint(&r, -5, 5));
    }
    printf("\nRandom unsigned int:\n");
    for (int i = 0; i < ITER; ++i) {
        printf("%d ", randuint(&r, 2, 10));
    }
    printf("\n");
    return EXIT_SUCCESS;
}