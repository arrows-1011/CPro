#include <iostream>

using namespace std;

#define MAX_P 100

int fact[MAX_P]; // n! mod p のテーブル O(p)

int extgcd(int a, int b, int &x, int &y)
{
    int d = a;
    if (b != 0) {
	d = extgcd(b, a%b, y, x);
	y -= (a / b) * x;
    } else {
	x = 1; y = 0;
    }
    return d;
}

int mod_inverse(int a, int m)
{
    int x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}

int mod_fact(int n, int p, int &e)
{
    e = 0;
    if (n == 0) return 1;
    int res = mod_fact(n/p, p, e);
    e += n/p;
    if (n / p % 2 != 0) return res * (p - fact[n % p]) % p;
    return res * fact[n % p] % p;
}

int mod_comb(int n, int k, int p)
{
    if (n < 0 || k < 0 || n < k) return 0;
    int e1, e2, e3;
    int a1 = mod_fact(n, p, e1), a2 = mod_fact(k, p, e2), a3 = mod_fact(n-k, p, e3);
    if (e1 > e2 + e3) return 0;
    return a1 * mod_inverse(a2 * a3 % p,p) % p;
}
