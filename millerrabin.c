#include <stdio.h>
#include <stdbool.h> 

long long int power(long long int x, long long int y) { //y >=0, not working!!!!!!!!!!!!!!!
    long long int result = x;
    if (y == 0) { return 1; }
    while (y > 1) {
        result *= x;
        y -= 1;
    }
    return result;
}

int gcd(int a, long long int n) { //returns gcd of a and n
    int gcd = 1;
    for (int i = 1; i <= a && i <= n; ++i) {
        if (a % i == 0 && n % i == 0) {
            gcd = i;
        }
    } 
    return gcd;
}
bool mr(long long int n, int a, int d, int s) {//miller rabin (possibly)
    long long int c = 1;
    for (int r = 0; r < s; r++) {
        c = d * power(2,r); // d(2^r)
        //something is wrong with the power function??? maybe it can't handle big numbers, this next line doesn't always work
        if ((power(a, c) % n == -1) || (power(a,c) % n == (n - 1))) { //a^(d*2^r)
            return true;
        }
    } 
    return false;
}
int main () {
    long long int n = 59;
    int d = 2;
    int s = 1;

    while (d % 2 == 0) { //n-1 = d*2^s, determine s and d
        d = (n - 1) / power(2,s);
        if (d % 2 == 0) {
            s += 1;
        }
    }
    
    int a = 2;
    while (a < n) { //check all bases in range [2, n-1]
        if (gcd(a, n) == 1) { //base must be coprime
            if (power(a, d) % n == 1 || mr(n, a, d, s)) {
                printf("%d is probably prime, with base %d\n", n, a);
                a = n; // breaks out of the loop
            }
        }
        a += 1;
    }

    return 0;
}