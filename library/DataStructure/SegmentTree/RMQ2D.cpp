#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

constexpr int MAX = (1 << 23);

class RMQ2D {
  public:
    int H, W;
    int dat[MAX];    

    int c(int i, int j)
    {
        return i * (2 * W - 1) + j;
    }
    
    void init(int h, int w, vector<int>& grid)
    {        
        H = 1;
        while (H < h) H *= 2;
        W = 1;
        while (W < w) W *= 2;
        
        for (int i = 0; i < 2 * H - 1; i++) {        
            for (int j = 0; j < 2 * W - 1; j++) {
                dat[c(i, j)] = INT_MAX;
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                dat[c(i + H - 1, j + W - 1)] = grid[i * w + j];
            }
        }
        
        for (int i = 2 * H - 2; i >= 0; i--) {
            for (int j = W - 2; j >= 0; j--) {
                dat[c(i, j)] = min(dat[c(i, j * 2 + 1)],
                                   dat[c(i, j * 2 + 2)]);
            }
        }

        for (int i = 2 * W - 2; i >= 0; i--) {
            for (int j = H - 2; j >= 0; j--) {
                dat[c(j, i)] = min(dat[c(j * 2 + 1, i)],
                                   dat[c(j * 2 + 2, i)]);
            }
        }
    }

    int query_h(int h1, int w1, int h2, int w2, int k, int l, int r)
    {
        if (r <= h1 || h2 <= l) return INT_MAX;
        if (h1 <= l && r <= h2) return query_w(w1, w2, k, 0, 0, W);
        int vl = query_h(h1, w1, h2, w2, k * 2 + 1, l, (l + r) / 2);
        int vr = query_h(h1, w1, h2, w2, k * 2 + 2, (l + r) / 2, r);
        return min(vl, vr);
    }

    int query_w(int w1, int w2, int j, int k, int l, int r)
    {
        if (r <= w1 || w2 <= l) return INT_MAX;
        if (w1 <= l && r <= w2) return dat[c(j, k)];
        int vl = query_w(w1, w2, j, k * 2 + 1, l, (l + r) / 2);
        int vr = query_w(w1, w2, j, k * 2 + 2, (l + r) / 2, r);
        return min(vl, vr);
    }

    int query(int h1, int w1, int h2, int w2)
    {
        return query_h(h1, w1, h2 + 1, w2 + 1, 0, 0, H);
    }
};
