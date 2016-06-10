#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main()
{
    int N, q, a, v;
    cin >> N >> q;
    vector<int> p(N+1, 0);
    priority_queue<pii> Q;
    while (q--) {
        cin >> a >> v;
        p[a] += v;
        Q.push(pii(p[a], -a));
        while (1) {
            pii mp = Q.top();
            if (p[-mp.second] == mp.first) {
                cout << -mp.second << " " << mp.first << endl;
                break;                
            }
            Q.pop();
        }
    }
    return 0;
}
