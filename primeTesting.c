#include <stdio.h>
#include <math.h>
#include <stdbool.h> 


int trialdivision(long long int n) {
    int a = 2;
    int b = ceil(sqrt(n));

    while (a<=b) {
        if (n % a == 0) {
            return 0;
        }
        a += 1;
    }
    return 1;
}

void sieve(long long int n) {
    int s = sqrt(n) + 1; // only look at numbers less than square root of n
    bool arr[s]; //false means not prime, true means prime
    for (int i = 0; i <= s; i++) {
        if (i % 2 == 0) { //set all even numbers to false
            arr[i] = false;
        }
        arr[i] = true; //pretend everything else is prime
    }

    arr[0] = false;
    arr[1] = false;
    arr[2] = true; //even prime number

    for (int i = 3; i < s; i += 2) { //start at 3 and go up by 2
        if (arr[i]) {
            for (int j = i + i; j <= s; j += i) { //set all multiples of i to false
                arr[j] = false;
            }
            
        }
    }
    
    int quotient = 1;

    for (int i = 2; i < s; i++) {
        if (arr[i]) {
            if (n % i == 0) {
                quotient = n / i;
                printf("%d %d", i, quotient); 
                sieve(n / i); //see if the quotient can be divided further, recursion
            }
        }
    }
}



int main() {

    long long int p1 = 658947810229;
    long long int p2 = 658947810253;

    printf("prime factors of %lld:\n", p1);
    sieve(p1);
    printf("\nprime factors of %lld: \n", p2);
    sieve(p2);

    /*if (trialdivision(p1)) {
       printf("p1 is prime\n");
    } else {
        printf("p1 is composite, factors include:\n");
        sieve(p1);
    }
    if (trialdivision(p2)) {
        printf("p2 is prime");
    } else {
        printf("p2 is composite, factors include:\n");
        sieve(p2);
    }*/
   return 0;
}