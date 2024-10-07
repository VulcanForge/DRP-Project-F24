#include "stdio.h" 
#include "gmp.h"
/*
int modular_calc(int a,int d,int n) {
    int res = 1;
    a = a % n;

    while (d > 0) {


    }
}

bool millerrabin(long long n, long long d) {
    // while loop to check if a**d (mod n) = +1 /-1
    int a = (n-2)/2; // random number
    int b = modular_calc(a, d, n);
    while()
}

bool isprime(long long n) {
    long long d = n - 1;
    while (d % 2 == 0) {
        d /= 2;
    }

    return millerrabin(n, d);
    // now I have d & n as in n - 1 = 2^k * d
}

int main() {
    return isprime(n);
}

*/
bool millerrabin(mpz_t n, mpz_t d) {
        // while loop to check if a**d (mod n) = +1 /-1
        mpz_t a; // pick a random number 
        mpz_init_set_ui (a, 2);
	mpz_t n_minus_1;
	mpz_init(n_minus_1); 
	mpz_sub_ui(n_minus_1, n, 1);
	//mpz_init_set_ui (temp, n)	
	
	while(mpz_cmp(d, n_minus_1) <= 0) {
            mpz_powm (r, a, d, n);
            
	    if (mpz_cmp_si(r,1) == 0) {
                
                return false;
            }
            if (mpz_cmp_si(r,n_minus_1) == 0) {
                
                return true;
            }
	   
            mpz_mul(d, d, 2);
            mpz_init_set_si(a, r);
        }
    }

mpz_t odd_part(mpz_t a) {
        mpz_t d;
	mpz_init (d);
	mpz_sub_ui (d, a, 1);
        while (mpz_divisible_2exp_p (a, 1) != 0) { //mpz_div
            mpz_fdiv_q(d, d, 2);
        }
        return d;
    }

int main(){
    mpz_t a;
	mpz_init_set_str (a, "597158248165169644887070147581847514621", 10);
   
    //mpz_t two;
	//mpz_init_set_ui (two, 2); // 2 // random num [2, n - 2] = a
	
    mpz_t r;
	mpz_init (r); // remainder

	mpz_t exponent; 
	mpz_init (exponent);

    // exponenet in mr is d intially and then changes to the resudual so res = d

    mpz_t res;
    mpz_init (res);
    mpz_init_set_ui (res, odd_part(a)); // res = d;


    //need to perform miller rabin loop
    if(millerrabin(a, res)) {
        printf("is prime!!");
    } else {
        printf("composite!");
    }

	mpz_clear (exponent);
	mpz_clear (r);
	//mpz_clear (two);
	mpz_clear (a);
}
