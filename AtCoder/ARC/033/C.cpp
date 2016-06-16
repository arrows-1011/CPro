#include <bits/stdc++.h>

using namespace std;

#define MAX_N (1<<19)

class BIT {
  public:
    int bit[MAX_N+1], n;
  
    BIT()
    {
        n = MAX_N;
        memset(bit, 0, sizeof(bit));
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

int main()
{
    BIT b;
    int Q, T, X;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> T >> X;        
        if (T == 1) {
            b.add(X, 1);
        } else {
            int l = 0, r = MAX_N;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (b.sum(mid) < X) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            cout << r << endl;
            b.add(r, -1);
        }
    }    
    return 0;
}
