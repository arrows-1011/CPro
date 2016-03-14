#include <bits/stdc++.h>

using namespace std;

#define INF (1<<29)

struct P{
    int t, c, nt;
    P(){}
    P(int t, int c, int nt) :
        t(t), c(c), nt(nt) {}

    bool operator < (const P &p) const {
        if (t != p.t) {
            return t < p.t;
        }
        return c > p.c;
    }
};


int main()
{
    int n;
    while (cin >> n, n) {
        vector<P> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i].t >> v[i].c;
            v[i].nt = v[i].t;
            v[i].c *= 2;
        }
        sort(v.begin(), v.end());
        queue<P> Q[2];
        for (int i = 0; i < n; i++) {
            Q[0].push(v[i]);
        }
        int res = 0;
        while (!Q[0].empty() || !Q[1].empty()) {          
            int f = INF;            
            if (!Q[0].empty()) {
                f = Q[0].front().nt;
            }
            if (!Q[1].empty()) {
                f = min(f, Q[1].front().nt);
            }

            res += f;
            queue<P> nQ[2], nQ2[2];
            for (int i = 0; i < 2; i++) {
                vector<P> v;
                while (!Q[i].empty()) {
                    P p = Q[i].front(); Q[i].pop();
                    if (p.nt-f == 0) {
                        p.nt = p.t;
                        if (--p.c > 0) {
                            v.push_back(p);   
                        }
                    } else {
                        p.nt -= f;
                        nQ[i].push(p);
                    }
                }
                sort(v.begin(), v.end());
                for (int j = 0; j < (int)v.size(); j++) {
                    nQ2[1-i].push(v[j]);
                }
            }
            for (int i = 0; i < 2; i++) {
                while (!nQ2[i].empty()) {
                    nQ[i].push(nQ2[i].front());
                    nQ2[i].pop();
                }
            }

            for (int i = 0; i < 2; i++) {
                int nt = 0;
                while (!nQ[i].empty()) {
                    P p = nQ[i].front(); nQ[i].pop();                  
                    nt = p.nt = max(nt, p.nt);
                    Q[i].push(p);
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
