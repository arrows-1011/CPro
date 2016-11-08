#include <iostream>
#include <algorithm>

using namespace std;

constexpr int MAX_L = 100000;
constexpr int MAX_SQRT_B = 1000;
using ll = long long;

//The number of primes  [a,b)
bool is_prime[MAX_L], is_prime_small[MAX_SQRT_B];

//is_prime[i-a] = true <-> i is prime
void segment_sieve(ll a, ll b)
{
    for (int i = 0; (ll)i * i < b; i++) is_prime_small[i] = true;
    for (int i = 0; i < b - a; i++) is_prime[i] = true;
  
    for (int i = 2; (ll)i * i < b; i++) {
	if (is_prime_small[i]) {
	    for (int j = 2 * i; (ll)j * j < b; j += i) is_prime_small[j] = false;
	    for (ll j = max(2LL, (a + i - 1) / i) * i; j < b; j += i) {
                is_prime[j - a] = false;
            }
	}
    }
}
