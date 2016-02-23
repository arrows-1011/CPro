#include <iostream>

using namespace std;

#define MAX_N 1000
typedef long long ll;

int n;

class BIT {
  public:
    int a[MAX_N+1], n;
  
    BIT() {
	for (int i = 0; i < MAX_N; i++) {
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
