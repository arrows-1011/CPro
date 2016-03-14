#include <bits/stdc++.h>

using namespace std;

#define MAX 300

int main()
{
    int mx, n;
    while (cin >> mx, mx) {
        cin >> n;
        vector<int> v(n+2, 0);
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        bool visited[MAX] = {0};
        visited[0] = 1;
        queue<int> Q;
        Q.push(0);

        while (!Q.empty()) {
            int now = Q.front(); Q.pop();
            if (now == n+1) {
                continue;
            }

            for (int i = 1; i <= mx; i++) {
                int next = min(n+1, now+i);
                next += v[next];
                if (next < 0) {
                    next = 0;
                } else if (next > n+1) {
                    next = n+1;
                }
                if (!visited[next]) {
                    visited[next] = 1;
                    Q.push(next);
                }
            }
        }
        bool reachable = 1;
        for (int i = 0; i <= n; i++) {
            if (!visited[i]) {              
                continue;
            }
            bool ng = 1, visited2[MAX] = {0};
            queue<int> Q2; Q2.push(i);
            visited2[i] = 1;
            while (!Q2.empty()) {
                int now = Q2.front(); Q2.pop();
                if (now == n+1) {
                    ng = 0;
                    break;
                }
                for (int i = 1; i <= mx; i++) {
                    int next = min(n+1, now+i);
                    next += v[next];
                    if (next < 0) {
                        next = 0;
                    } else if (next > n+1) {
                        next = n+1;
                    }
                    if (!visited2[next]) {
                        visited2[next] = 1;
                        Q2.push(next);
                    }
                }
            }
            if (ng) {
                reachable = 0;
                break;
            }
        }
        cout << (reachable && visited[n+1] ? "OK" : "NG") << endl;
    }
    return 0;
}
