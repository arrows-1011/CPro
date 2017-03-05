#include <bits/stdc++.h>

using namespace std;

using Vec = vector<int>;
using Mat = vector<Vec>;

int simulate(int v, int dir, Vec& d, Mat adj)
{
    int cnt = 1;
    while (true) {
        int next = adj[v][dir];
        if (next == -1) break;
        
        for (int i = 0; i < 4; i++) {
            if (adj[v][i] != -1) {
                adj[adj[v][i]][(i + 2) % 4] = adj[v][(i + 2) % 4];
            }
        }
        
        v = next;
        dir = d[v];
        cnt += 1;
    }    
    return cnt;
}

int main()
{
    int N;
    cin >> N;
    Vec x(N), y(N), d(N);
    const string dv = "<^>v";
    for (int i = 0; i < N; i++) {
        char ch;
        cin >> x[i] >> y[i] >> ch;
        d[i] = dv.find(ch);
    }

    Mat adj(N, vector<int>(4, -1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (x[i] == x[j]) {
                if (y[i] > y[j] && (adj[i][1] == -1 || y[adj[i][1]] < y[j])) {
                    adj[i][1] = j;
                }
                if (y[i] < y[j] && (adj[i][3] == -1 || y[adj[i][3]] > y[j])) {
                    adj[i][3] = j;
                }
            }
            if (y[i] == y[j]) {
                if (x[i] > x[j] && (adj[i][0] == -1 || x[adj[i][0]] < x[j])) {
                    adj[i][0] = j;
                }
                if (x[i] < x[j] && (adj[i][2] == -1 || x[adj[i][2]] > x[j])) {
                    adj[i][2] = j;
                }
            }
        }
    }

    int res = 0;
    for (int i = 0; i < N; i++) {
        res = max(res, simulate(i, d[i], d, adj));
    }
    cout << res << endl;
    return 0;
}
