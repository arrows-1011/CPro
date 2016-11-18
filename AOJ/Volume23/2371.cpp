#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;

using pii = pair<int, int>;
using Edge = tuple<int, int, int>;
constexpr int MAX = 252521;
constexpr int INF = INT_MAX;

struct State {
    int v, cost, trans, en;
    
    State () {}
    State (int v, int cost, int trans, int en) :
        v{v}, cost{cost}, trans{trans}, en{en} {}

    bool operator < (const State& s) const {
        if (cost != s.cost) {
            return cost > s.cost;
        }
        return trans > s.trans;
    }
};

int N, T;
vector<Edge> G[MAX];

pii dijkstra()
{
    vector<pii> d(MAX, pii(INF, INF));
    
    priority_queue<State> pq;
    pq.push(State(0, 0, 0, -1));
    while (!pq.empty()) {
        auto st = pq.top(); pq.pop();
        int v = st.v, cost = st.cost, trans = st.trans, en = st.en;

        if (pii(cost, trans) > d[en]) continue;
        
        if (v == 1) {
            return d[en];
        }
        
        for (const auto& g : G[v]) {
            int to, ncost, nen;
            int ntrans = trans;
            
            tie(to, ncost, nen) = g;
            ncost += cost;
            
            if (en != -1 && abs(en - nen) > 1) {
                ncost += T;
                ntrans++;
            }
            
            if (pii(ncost, ntrans) < d[nen]) {
                d[nen] = pii(ncost, ntrans);
                pq.push(State(to, ncost, ntrans, nen));
            }
        }        
    }
    return pii(-1, -1);
}

int main()
{
    string A, B;
    map<string, int> s2i;
    int n = 0;
    
    cin >> N >> T >> A >> B;
    
    s2i[A] = 0;
    s2i[B] = 1;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        vector<int> v;
        for (int j = 0; j < a; j++) {
            string s;
            cin >> s;
            if (s2i.count(s) == 0) {
                s2i[s] = s2i.size();
            }
            v.emplace_back(s2i[s]);
        }
        for (int j = 0; j < a - 1; j++) {
            int cost;
            cin >> cost;
            G[v[j]].emplace_back(v[j + 1], cost, n + j);
            G[v[j + 1]].emplace_back(v[j], cost, n + j);           
        }
        n += a;
    }
    pii res = dijkstra();
    if (res.first == -1) {
        cout << -1 << endl;
    } else {
        cout << res.first << " " << res.second << endl;
    }
    return 0;
}
