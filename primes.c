#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define BLOCKSIZE 5000

void get_primes(void);

int main(void) {
    get_primes();
    return 0;
}

void get_primes(void) {
    FILE *fp = NULL;
    size_t *primes = malloc(BLOCKSIZE * sizeof(size_t)); /* array of primes */
    size_t len = 1;                                      /* length of primes[] */
    size_t cur = 3;                                      /* current number for testing */

    size_t i;

    primes[0] = 2;

    while (len < 100) {
        if (len % BLOCKSIZE == 0) {
            primes = realloc(primes, (len + BLOCKSIZE) * sizeof(size_t));
        }

        size_t prime = 1;
        for (i = 0; primes[i] < (int)sqrt(cur); i++) {
            /* printf("[%llu %% %llu] ", cur, primes[i]); */
            if (cur % primes[i] == 0) {
                prime = 0;
                break;
            }
        }

        if (prime == 1) {
            //            printf("%llu\n", cur);
            fp = fopen("primes.txt", "a");
            fprintf(fp, "%llu\n", cur);
            fclose(fp);

            primes[len] = cur;
            len++;
        }
        cur++;
    }
}
