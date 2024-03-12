#include <stdio.h>
#include <stdlib.h>
int Euclidean(int prime, int mod, int* counter) {
	int mult, math, m2;
	*counter = *counter + 1;
	if (mod % prime > 1) {
		mult = Euclidean(mod % prime, prime, counter);
	}
	if (mod % prime == 1) {
		return (mod - (mod % prime)) / prime;
	}
	math = (mod - (mod % prime)) / prime;
	m2 = (mult * (mod - (prime * math)) + 1) / prime;
	return (mult * math) + m2;
}
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int relativelyPrime(int a, int b) {
	return gcd(a, b) == 1 ? 1 : 0;
}
int main(int argc, char* argv[]) {
	if(argc != 3) { 
		printf("Usage: %s [alpha] [mod] as in the formula: alpha %% mod.\n", argv[0]);
		return 1;
	}
	int alpha = atoi(argv[1]);
	int mod = atoi(argv[2]);
	if (!relativelyPrime(alpha, mod)) {
		printf("Your numbers are not relative primes!\n");
		return 1;
	}
	int* counter = (int*)malloc(sizeof(int));
	*counter = 0;
	int answer = Euclidean(alpha, mod, counter);
	if (*counter % 2 == 1) {
		printf("Your modular arithmetic inverse is: %d\n", mod - answer);
	}
	else {
		printf("Your modular arithmetic inverse is: %d\n", answer);
	}
	free(counter);
	return 0;
}
