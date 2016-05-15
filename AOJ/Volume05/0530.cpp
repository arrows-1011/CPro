#include <bits/stdc++.h>

using namespace std;

#define MAX_N 155
#define MAX_K 15
#define INF (1<<29)
typedef pair<int, int> pii;

struct State {
    int dng, x, y, m;
    State(){}
    State(int dng, int x, int y, int m) :
        dng(dng), x(x), y(y), m(m) {}

    bool operator < (const State &s) const {
        return dng > s.dng;
    }
};

int main()
{
    int N, M, K, x, d;
    while (cin >> N >> M, N) {
        vector<pii> G[MAX_N];
        for (int i = 0; i < N; i++) {
            cin >> K;            
            for (int j = 0; j < K; j++) {
                cin >> x >> d; 
                G[i].push_back(pii(x, d));
            }
        }
        G[N].push_back(pii(0, 0));
        
        int dn[MAX_N][MAX_K][MAX_N];
        for (int i = 0; i < MAX_N; i++) {
            for (int j = 0; j < MAX_K; j++) {
                for (int k = 0; k < MAX_N; k++) {
                    dn[i][j][k] = INF;
                }
            }
        }
        
        priority_queue<State> Q;
        for (int i = 0; i < 2; i++) {
            int size = G[i].size();
            int nm = (i == 1 ? M - 1 : M);
            for (int j = 0; j < size; j++) {
                Q.push(State(0, j, i, nm)); 
                dn[i][j][nm] = 0;
            }
        }
                
        while (!Q.empty()) {
            State s = Q.top(); Q.pop();
            int y = s.y, x = s.x, m = s.m;
            int dng = G[y][x].second;
            x = G[y][x].first;
            if (y == N) {
                cout << s.dng << endl;
                break;
            }

            for (int i = 1; i <= 2; i++) {
                int ny = y + i;
                if (ny > N) continue;                
                for (int j = 0; j < (int)G[ny].size(); j++) {
                    int nx = G[ny][j].first, nd = G[ny][j].second;
                    int nm = (i == 2 ? m - 1 : m);
                    int ncost = s.dng + (ny < N ? (dng + nd) * abs(x - nx) : 0);

                    if (nm >= 0 && ncost < dn[ny][j][nm]) {
                        dn[ny][j][nm] = ncost;
                        Q.push(State(ncost, j, ny, nm));
                    }
                }
            }
           
        }
    }
    return 0;
}
