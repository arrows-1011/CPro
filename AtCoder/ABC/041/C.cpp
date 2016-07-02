#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main()
{
    int N, a;
    cin >> N;
    priority_queue<pii> pq;
    for (int i = 0; i < N; i++) {
        cin >> a;
        pq.push(pii(a, i));
    }

    while (!pq.empty()) {
        pii p = pq.top(); pq.pop();
        cout << p.second + 1 << endl;
    }    
    return 0;
}
