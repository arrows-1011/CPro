#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    int N, M, s, t, p;
    cin >> N >> M;
    vector<pii> v[2];
    for (int i = 0; i < N; i++) {
        cin >> s >> t;
        int j = i+1;
        if (s < t) {
            v[0].push_back(pii(s, j));
            v[0].push_back(pii(t, j));
        } else {
            v[1].push_back(pii(s, -j));
            v[1].push_back(pii(t, -j));
        }
    }
    for (int i = 0; i < M; i++) {
        cin >> p;
        v[0].push_back(pii(p, 0));
        v[1].push_back(pii(p, 0));
    }

    sort(v[0].begin(), v[0].end());
    sort(v[1].rbegin(), v[1].rend());

    ll res = 0;
    for (int i = 0; i < 2; i++) {
        vector<int> use(N, -1);
        int cut = 0, even = 0, odd = 0;
        for (int j = 0; j < (int)v[i].size(); j++) {
            int k = (i == 0 ? +1 : -1);
            int x = v[i][j].second * k;
            if (j > 0) {
                ll cost = k * (ll)(v[i][j].first - v[i][j-1].first) * even;
                res += cost;
            }
                
            if (x != 0) {
                x--;
                if (use[x] == -1) {
                    use[x] = cut;
                    even++;
                } else {
                    if ((cut - use[x]) % 2 == 0) {
                        even--;
                    } else {
                        odd--;
                    }
                }
            } else {
                cut++;
                swap(even, odd);
            }
        }
    }
    cout << res << endl;
    return 0;
}
