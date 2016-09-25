#include <bits/stdc++.h>

using namespace std;

#define MAX 400010
typedef long long ll;

int bit[MAX], n;

void init()
{
    n = MAX-1;
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

int get_val(int N, int key)
{
    int l = 0, idx = N;
    while (idx - l > 0) {
        int mid = (l + idx) / 2;
        if (sum(mid) < key) {
            l = mid + 1;
        } else {
            idx = mid;
        }
    }
    return l;
}

int main()
{
    ll Q, lim, x;
    int q;
    while (1) {
        scanf("%lld %lld", &Q, &lim);
        if (Q == 0 && lim == 0) break;
        ll idx = 1;
        init();
        map<ll, ll> i2v, v2i;
        while (Q--) {
            scanf("%d %lld", &q, &x);
            switch (q) {
                case 0: {
                    i2v[idx] = x; v2i[x] = idx;
                    add(idx, 1); idx++;
                    int r = sum(idx);
                    if (r > lim) {
                        add(get_val(idx, r - lim), -1);
                    }
                    break;
                }
                case 1: {
                    add(get_val(idx, x), -1);
                    break;
                }
                case 2: {                   
                    printf("%lld\n", i2v[get_val(idx, x)]);
                    break;
                }
                case 3: {
                    add(v2i[x], -1);
                    break;
                }
            }
        }
        puts("end");
    }
    return 0;
}
