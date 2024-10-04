#include <iostream>

#include <gmp.h>

int main ()
{
	mpz_t a;
	mpz_init_set_str (a, "597158248165169644887070147581847514621", 10);
	mpz_t two;
	mpz_init_set_ui (two, 2);
	mpz_t r;
	mpz_init (r);
	mpz_t exponent;
	mpz_init (exponent);
	mpz_sub_ui (exponent, a, 1);
	mpz_powm (r, two, exponent, a);
	if (mpz_cmp_ui (r, 1) == 0)
	{
		std::cout << "The number is prime.\n";
	}
	else
	{
		std::cout << "The number is composite.\n";
	}
	mpz_clear (exponent);
	mpz_clear (r);
	mpz_clear (two);
	mpz_clear (a);
}
