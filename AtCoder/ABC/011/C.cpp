#include <bits/stdc++.h>

using namespace std;

#define MAX 350
#define INF (1<<29)

bool check(int N, int a[3])
{
    for (int i = 0; i < 3; i++) {
        if (N == a[i]) {
            return 0;
        }
    }

    int dist[MAX];
    fill(dist, dist + MAX, INF);
    dist[N] = 0;
    queue<int> Q;
    Q.push(N);
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        if (v == 0) {
            if (dist[v] <= 100) {
                return 1;
            }
            continue;
        }
        for (int i = 1; i <= 3; i++) {
            if (v - i < 0) {
                continue;
            }
            bool ng = 0;
            for (int j = 0; j < 3; j++) {
                if (v - i == a[j]) {
                    ng = 1;
                    break;
                }
            }

            if (!ng && dist[v] + 1 < dist[v - i]) {
                dist[v - i] = dist[v] + 1;
                Q.push(v - i);
            }
        }
    }
    return 0;
}

int main()
{
    int N, a[3];
    cin >> N;
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    cout << (check(N, a) ? "YES" : "NO") << endl;
    return 0;
}
