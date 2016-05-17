#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> Vec;

struct State {
    ll cost;
    Vec v;
    State(ll cost, Vec v) :
        cost(cost), v(v) {}

    bool operator < (const State &s) const {
        return cost > s.cost;
    }
};

int main()
{
    int N;
    cin >> N;
    ll c[N][N];
    Vec start(N);
    for (int i = 0; i < N; i++) {
        start[i] = i;
        for (int j = 0; j < N; j++) {
            cin >> c[i][j];
        }
    }

    priority_queue<State> Q;
    Q.push(State(0, start));

    map<Vec, ll> min_cost;
    min_cost[start] = 0;
    
    while (!Q.empty()) {
        State s = Q.top(); Q.pop();
        Vec v = s.v;
        
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                swap(v[i], v[j]);
                if (min_cost.count(v) == 0 ||
                    s.cost + c[i][j] < min_cost[v]) {
                    min_cost[v] = s.cost + c[i][j];
                    Q.push(State(min_cost[v], v));
                }                    
                swap(v[i], v[j]);
            }
        }        
    }

    ll res = 0;
    for (auto &x: min_cost) {
        res = max(res, x.second);
    }
    
    cout << res << endl;    
    return 0;
}
