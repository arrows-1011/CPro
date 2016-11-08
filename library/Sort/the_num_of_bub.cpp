#include <iostream>

using namespace std;

constexpr int MAX_N = 1000;
using ll = long long;

int n;

class BIT {
  public:
    int a[MAX_N + 1], n;
  
    BIT() {
        n = MAX_N + 1;
	for (int i = 0; i < n; i++) {
	    a[i] = 0;
	}
    }

    int sum(int i)
    {
	int s = 0;
	while (i > 0) {
	    s += a[i];
	    i -= i & -i;
	}
	return s;
    }
  
    void add(int i, int x)
    {
	while (i <= n) {
	    a[i] += x;
	    i += i & -i;
	}
    }
};

void solve()
{
    ll ans = 0;
    BIT b;
    for (int j = 0; j < n; j++) {
	ans += j - b.sum(b.a[j]);
    }
}
