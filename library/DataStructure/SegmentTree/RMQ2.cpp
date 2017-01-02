#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

constexpr int MAX_N = (1 << 17);

int n, dat[2 * MAX_N - 1];
  
void init(int n_)
{
    n = 1;
    while (n < n_) {
        n *= 2;
    }
    for (int i = 0; i < 2 * n - 1; i++) {
	dat[i] = INT_MAX;
    }
}

void init(int n_, vector<int>& v)
{
    int N = v.size();
    init(n_);
    for (int i = (N - 1) + (n - 1); i >= 0; i--) {
	if (n - 1 <= i) {
            dat[i] = v[i - (n - 1)];
        } else {
            dat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }
}
  
void update(int k, int a)
{
    k += n - 1;
    dat[k] = a;
    while (k > 0) {
	k = (k - 1) / 2;
	dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
}

int query(int a, int b, int k, int l, int r)
{
    if(r <= a || b <= l) {
        return INT_MAX;
    }
    if (a <= l && r <= b) {
	return dat[k];
    } else {
	int vl = query(a, b, k * 2 + 1, l, (l + r)/2);
	int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
	return min(vl, vr);
    }
}
