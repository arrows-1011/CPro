/*
  O(√n)でnと[1,n-1]までの数字で互いに素の数を出す。
*/

#include <iostream>

using namespace std;

constexpr int MAX = 100000;

//1個だけの場合
int eulerPhi(int n)
{
    if (n == 0) return 0;
    int ans = n;
    for (int i = 2; i * i <= n; i++) {
	if (n % i == 0) {
	    ans -= ans / i;
	    while (n % i == 0) n /= i;
	}
    }
    if (n > 1) ans -= ans / n;
    return ans;
}

//まとめてする場合
int EulerPhi(int n)
{
    static int lookup = 0, P[MAX], f[MAX];
    if (!lookup) {
	for (int i = 0; i < MAX; i++) {
	    P[i] = 1;
	    f[i] = i;
	}
	for (int i = 2; i < MAX; i++) {
	    if (P[i]) {
		f[i] -= f[i] / i;
		for (int j = i + i; j < MAX; j += i) {
		    P[j] = 0;
		    f[j] -= f[j] / i;
		}
	    }
	}
	lookup = 1;
    }
    return f[n];
}
