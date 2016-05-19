#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main()
{
    int N, K, x;
    cin >> N >> K;
    priority_queue<pii> Q;
    for (int i = 0; i < K-1; i++) {
        cin >> x;
        Q.push(pii(x, i));
    }    
    for (int i = K-1; i < N; i++) {
        cin >> x;
        Q.push(pii(x, i));
        while ((int)Q.size() > K) Q.pop();
        cout << Q.top().second + 1 << endl;
    }
    return 0;
}
