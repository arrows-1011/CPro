#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 1001
#define MOD 1000000007
typedef long long ll;
 
ll a[MAX][MAX], b[MAX][MAX];

struct State {
    ll v, i, j;
    State(ll v, ll i, ll j) :
        v(v), i(i), j(j) {}

    bool operator < (const State &s) const {
        return v < s.v;
    }
};

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<State> v;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
            v.push_back(State(a[i][j], i, j));
            b[i][j] = 1;
        }
    }

    sort(v.begin(), v.end());
    
    const int di[] = {-1, 0, 1, 0};
    const int dj[] = {0, -1, 0, 1};
 
    for (int i = 0; i < (int)v.size(); i++) {
        int ii = v[i].i, jj = v[i].j;
        for (int k = 0; k < 4; k++) {
            int ni = ii + di[k];
            int nj = jj + dj[k];
            if (0 > ni || ni >= N || 0 > nj || nj >= M) continue;
            if (a[ii][jj] < a[ni][nj]) {
                b[ni][nj] += b[ii][jj];
                b[ni][nj] %= MOD;
            }
        }
    }
 
    ll res = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            res += b[i][j];
            res %= MOD;
        }
    }
    cout << res << endl;
    return 0;
}
