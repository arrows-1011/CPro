#include <cstdio>
#include <vector>

using namespace std;

struct SegmentTree {
    int N;
    vector<int> dl, dr;
    
    SegmentTree(int N_)
    {
        N = 1;
        while (N < N_) {
            N *= 2;
        }
        
        dl.assign(2 * N - 1, -1);
        dr.assign(2 * N - 1, -1);
        
        for (int i = N - 1; i < 2 * N - 1; i++) {
            dl[i] = 0; dr[i] = 1;
        }
    }
    
    void eval(int k, int l, int r)
    {
        if (r == -1) {
            return;
        }
            
        if (dr[k] == -1) {
            dl[k] = l;
            dr[k] = r;
        } else if (dr[k] == l) {
            dr[k] = r;
        } else {
            dl[k] = dr[k] = -2;
        }
    }

    void update(int a, int b, int k, int l, int r, int x)
    {
        if (r <= a || b <= l) {
            return;
        }

        if (a <= l && r <= b) {
            eval(k, x, x + 1);
        } else {
            eval(k * 2 + 1, dl[k], dr[k]);
            eval(k * 2 + 2, dl[k], dr[k]);
            dl[k] = dr[k] = -1;
            update(a, b, k * 2 + 1, l, (l + r) / 2, x);
            update(a, b, k * 2 + 2, (l + r) / 2, r, x);
        }
    }

    void update(int l, int r, int x)
    {
        update(l, r + 1, 0, 0, N, x);
    }

    int query(int K)
    {
        for (int i = 0; i < N - 1; i++) {
            eval(i * 2 + 1, dl[i], dr[i]);
            eval(i * 2 + 2, dl[i], dr[i]);
        }
        
        int cnt = 0;
        for (int i = N - 1; i < 2 * N - 1; i++) {
            if (dl[i] == 0 && dr[i] == K + 1) {
                cnt += 1;
            }
        }
        return cnt;
    }
};

int main()
{
    int N, K, T;
    scanf("%d %d %d", &N, &K, &T);    
    
    SegmentTree seg(N);
    for (int i = 0; i < T; i++) {
        int l, r, x;
        scanf("%d %d %d", &l, &r, &x);
        seg.update(l - 1, r - 1, x);
    }
        
    printf("%d\n", seg.query(K));
    return 0;
}
