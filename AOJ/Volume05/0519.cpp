#include <bits/stdc++.h>

using namespace std;

#define MAX_V 5010
typedef vector<int> Vec;

int N, M;
Vec G[MAX_V];

bool visit(int v, Vec &order, Vec &color)
{
    color[v] = 1;
    for (int i = 0; i < (int)G[v].size(); i++) {
        int to = G[v][i];
        if (color[to] == 2) continue;
        if (color[to] == 1) return false;
        if (!visit(to, order, color)) return false;
    }
    order.push_back(v);
    color[v] = 2;
    return true;
}

bool topologicalSort(Vec &order)
{
    Vec color(N, 0);
    for (int i = 0; i < N; i++) {
        if (color[i] == 0 && !visit(i, order, color)) {
            return false;
        }
    }
    reverse(order.begin(), order.end());
    return true;
}

int main()
{
    int s, t;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> s >> t; s--; t--;
        G[s].push_back(t);
    }
    Vec order;
    if (topologicalSort(order)) {
        bool is_hamiltonian_path = 1;
        for (int i = 0; i < N-1; i++) {
            if (G[order[i]].size() == 0) {
                is_hamiltonian_path = 0;
            }
        }
        for (int i = 0; i < N; i++) {
            cout << order[i]+1 << endl;
        }
        cout << !is_hamiltonian_path << endl;
    }
    return 0;
}
