#include <iostream>
#include <math.h>
using namespace std;

long long int a[10000000];
// Function to print prime numbers in the range of a given number n
void SieveOfEratosthenes(long long int n)
{
	for (int i = 0; i <= n; i++) // initialize all numbers as prime
		a[i] = 1;

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (a[i] == 1) // checks if i is prime
		{
			for (int j = 2; i * j <= n; j++)
				a[i * j] = 0; // multiples of i are not prime
		}
	}

	for (int i = 2; i <= n; i++)
		if (a[i] == 1)
		{
			cout << i << " "; // prints primes
		}
}

int main()
{
	// print primes less than 10000001
	long long int n;
	cin>>n;
	SieveOfEratosthenes(n);
}
