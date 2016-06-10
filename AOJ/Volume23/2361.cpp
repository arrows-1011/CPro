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

ll get_val(Vec &v)
{
    ll res = 0LL, N = v.size();
    for (auto &x: v) {
        res *= N;
        res += x;
    }
    return res;
}

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

    unordered_map<ll, ll> min_cost;
    min_cost[get_val(start)] = 0;    
    
    while (!Q.empty()) {
        State s = Q.top(); Q.pop();
        Vec v = s.v;
        
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                swap(v[i], v[j]);
                ll vv = get_val(v);
                if (min_cost.count(vv) == 0 ||
                    s.cost + c[i][j] < min_cost[vv]) {
                    min_cost[vv] = s.cost + c[i][j];
                    Q.push(State(min_cost[vv], v));
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
