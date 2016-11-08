#include <iostream>

using namespace std;

constexpr int MAX_N = (1 << 17);

class BIT {
  public:
    int bit[MAX_N + 1], n;
  
    BIT()
    {
        n = MAX_N + 1;
	for (int i = 0; i < n; i++) {
	    bit[i] = 0;
	}
    }

    int sum(int i)
    {
	int s = 0;
	while (i > 0) {
	    s += bit[i];
	    i -= i & -i;
	}
	return s;
    }
  
    void add(int i, int x)
    {
	while (i <= n) {
	    bit[i] += x;
	    i += i & -i;
	}
    }
};

