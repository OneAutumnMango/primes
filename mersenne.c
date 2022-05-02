#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define BLOCKSIZE 500

int is_ll(size_t prime) {
    size_t termN = 4;
    for (size_t i = 1; i <= prime - 2; i++) {
        termN = (termN * termN - 2) % ((size_t)pow(2, prime) -   1);
    }
    return termN == 0;
}

void findMersenneLucasLehmer() {
    FILE *fp = NULL;

    size_t *primes = malloc(BLOCKSIZE * sizeof(size_t));

    size_t num, len = 0;
    fp = fopen("../cprimes.txt", "r");
    while (fscanf(fp, "%llu\n", &num) == 1) {
        if (len % BLOCKSIZE == 0) {
            primes = realloc(primes, (len + BLOCKSIZE) * sizeof(size_t));
        }
        primes[len] = num;
        len++;
    }

    for (int i = 0; i <= len; i++) {
        if (is_ll(primes[i])) {
            size_t mersenne = (1ull << primes[i]) - 1);
            fp = fopen("../mersenne.txt", "a");
            fprintf(fp, "%llu: %llu\n",  primes[i], mersenne;
            fclose(fp);
            printf("%llu: %llu\n",  primes[i], mersenne;
        }
    }
}

int main() {
    findMersenneLucasLehmer();
    return 0;
}