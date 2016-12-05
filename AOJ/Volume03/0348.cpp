#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int f[6], g[6];

int rec(int l, int r, int b1, int b2, int p)
{
    if (b1 == (1 << 6) - 1) return +1;
    if (b2 == (1 << 6) - 1) return -1;
    
    int res = (p == 0 ? -1 : +1);
    bool pass = 1;
    for (int i = 0; i < 6; i++) {
        if (p == 0) {
            if (b1 >> i & 1) continue;
            if (l == f[i]) {
                pass = 0;
                res = max(res, rec(l - 1, r, b1 | (1 << i), b2, 1));                
            }
            if (f[i] == r) {
                pass = 0;
                res = max(res, rec(l, r + 1, b1 | (1 << i), b2, 1));
            }
        } else {
            if (b2 >> i & 1) continue;
            if (l == g[i]) {
                pass = 0;
                res = min(res, rec(l - 1, r, b1, b2 | (1 << i), 0));
            }
            if (g[i] == r) {
                pass = 0;
                res = min(res, rec(l, r + 1, b1, b2 | (1 << i), 0));
            }
        }
    }

    if (pass) {
        res = rec(l, r, b1, b2, 1 ^ p);
    }
    
    return res;
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        bool used[13] = {};
        for (int j = 0; j < 6; j++) {
            cin >> f[j];
            used[--f[j]] = 1;
        }
        for (int j = 0, k = 0; j < 13; j++) {
            if (j != 6 && !used[j]) {
                g[k++] = j;
            }
        }
        cout << (rec(5, 7, 0, 0, 0) == 1 ? "yes" : "no") << endl;
    }
    return 0;
}
