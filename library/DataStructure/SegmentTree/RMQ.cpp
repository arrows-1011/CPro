#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

constexpr int INF = INT_MAX;

class RMQ {
  public:
    int n;
    vector<int> dat;
  
    RMQ(int n_)
    {
        n = 1;
        while (n < n_) {
            n *= 2;
        }
        dat.assign(2 * n - 1, INF);
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
        if (r <= a || b <= l) {
            return INF;
        }
        if (a <= l && r <= b) {
            return dat[k];
        } else {
            int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
            int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
            return min(vl, vr);
        }
    }
    
    /* min [l, r] */
    int query(int l, int r)
    {
        return query(l, r + 1, 0, 0, n);
    }
};

int main()
{
    int N, Q;
    cin >> N >> Q;
    RMQ rmq(N);
    for (int i = 0; i < Q; i++) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) {
            rmq.update(x, y);
        } else {
            cout << rmq.query(x, y) << endl;
        }
    }
    return 0;
}
