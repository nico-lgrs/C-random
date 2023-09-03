#include "prng.h"

#define PRNG_MAX UINT32_MAX

void prng_seed(struct prng *prng, uint32_t seed) {
    prng->seed = seed;
    prng->state = seed;
}

void prng_reset(struct prng *prng) {
    prng->state = prng->seed;
}

uint32_t xorshift32(uint32_t state) {
    state ^= state << 13;
    state ^= state >> 17;
    state ^= state << 5;
    return state;
}

uint32_t randomNext(struct prng *prng) {
    prng->state = xorshift32(prng->state);
    return prng->state;
}

uint32_t randuint(struct prng *prng, uint32_t min, uint32_t max) {
    uint32_t n = max - min + 1;
    uint32_t remainder = PRNG_MAX % n;
    uint32_t x;
    do {
        x = randomNext(prng);
    } while (x >= PRNG_MAX - remainder);
    return min + x % n;
}

int32_t randint(struct prng *prng, int32_t min, int32_t max) {
    if (min < 0) {
        max -= min;
        return randuint(prng, 0, max) + min;
    }
    return randuint(prng, min, max);
}