#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>

void g(mpz_t result, mpz_t x, mpz_t n) {
    mpz_mul(result, x, x); //x^2
    mpz_add_ui(result, result, 1);
    mpz_mod(result, result, n);
}

int main() {

    mpz_t n;
    mpz_init_set_str(n, "597158248165169644887070147581847514621", 10);
    mpz_t t;
    mpz_init_set_ui(t, 2);
    mpz_t h;
    mpz_init_set_ui(h, 2);
    mpz_t d;
    mpz_init(d);
    mpz_t temp;
    mpz_init(temp);

    g(t, t, n); //g(t)
    g(h, h, n);
    g(h, h, n); //g(g(h))
    mpz_sub(temp, t, h); // t-h
    mpz_gcd(d, temp, n);


    //0 means false in C!!!! not true!!!
    while (!mpz_cmp_ui(d, 1)) {
        if (!mpz_cmp(t,h)) {
            printf("maybe prime");
            break;
        }
        if (!mpz_cmp_ui(d, 1)) {
            g(t, t, n); //g(t)
            g(h, h, n);
            g(h, h, n); //g(g(h))
            mpz_sub(temp, t, h); // t-h
            mpz_gcd(d, temp, n);
        }
        if (mpz_cmp_ui(d, 1)) {
            printf("%s is a factor", d);
        }
    }


   mpz_clear(n);
   mpz_clear(t);
   mpz_clear(h);
   mpz_clear(d);
   mpz_clear(temp);

   return 0;
}
