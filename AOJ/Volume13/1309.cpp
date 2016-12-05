#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <set>

using namespace std;

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

struct State {
    double d;
    int l, r;

    State () {}
    State (double d, int l, int r) : d{d}, l{l}, r{r} {}

    bool operator < (const State &s) const {
        return d > s.d - (1e-9);
    }
};

double dijkstra(const vector<double>& X, const vector<double>& Y)
{
    int N = X.size();
    map<int, map<int, double>> d;
    d[0][N - 1] = 0;

    priority_queue<State> pq;
    pq.push(State(0, 0, N - 1));

    while (!pq.empty()) {
        State s = pq.top(); pq.pop();
        int l = s.l, r = s.r;
        
        if (l > r) continue;
        if (d[l][r] < s.d) continue;
        if (l == r) return d[l][r];

        for (int i : {-1, +0, +1}) {
            int nl = l + i;
            for (int j : {-1, +0, +1}) {
                int nr = r + j;
                if (nl < 0 || nl >= N ||
                    nr < 0 || nr >= N) continue;

                if (Y[nl] != Y[nr]) continue;
                
                double ld = dist(X[l], Y[l], X[nl], Y[nl]);
                double rd = dist(X[r], Y[r], X[nr], Y[nr]);
                double nd = s.d + ld + rd;
                
                if (d[nl].count(nr) == 0 || nd < d[nl][nr]) {
                    d[nl][nr] = nd;
                    pq.push(State(nd, nl, nr));
                }               
            }
        }       
    }
    return -1;
}

int main()
{
    int N;
    while (1) {
        cin >> N;
        if (N == 0) break;
        vector<double> x(N), y(N);
        set<double> ys;
        for (int i = 0; i < N; i++) {
            cin >> x[i] >> y[i];
            ys.insert(y[i]);
        }

        set<pair<double, double>> v;
        for (int i = 0; i < N - 1; i++) {
            int sign = +1;
            double sy = y[i], ty = y[i + 1];
            
            if (sy > ty) {
                sign = -1;
                swap(sy, ty);
            }
            
            for (auto& cy : ys) {                
                double dx = x[i + 1] - x[i], dy = ty - sy;
                double s = (dy != 0 ? dx * sign / dy : 1);
                if (sy <= cy && cy <= ty) {
                    v.insert(make_pair(x[i] + s * (cy - y[i]), cy));
                }
            }
        }

        v.insert(make_pair(x[N - 1], y[N - 1]));
        
        vector<double> X, Y;
        for (auto& p : v) {
            X.emplace_back(p.first);
            Y.emplace_back(p.second);
        }
            
        printf("%.10f\n", dijkstra(X, Y));
    }        
    return 0;
}
