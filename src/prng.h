#ifndef PRNG_H
#define PRNG_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

struct prng {
    uint32_t seed;
    uint32_t state;
};

/* Set the seed of the prng. */
void prng_seed(struct prng *prng, uint32_t seed);

/* Set prng state to its seed. */
void prng_reset(struct prng *prng);

/* Apply the 32 bits version of the xorshift algorithm. */
uint32_t xorshift32(uint32_t state);

/* Generate the next state based on the current state. */
uint32_t randomNext(struct prng *prng);

/* Get a random 32 bits unsigned integer between min included and max included. */
uint32_t randuint(struct prng *prng, uint32_t min, uint32_t max);

/* Get a random 32 bits signed integer between min included and max included. */
int32_t randint(struct prng *prng, int32_t min, int32_t max);

#ifdef __cplusplus
}
#endif

#endif
