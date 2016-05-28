#include <bits/stdc++.h>

using namespace std;

#define MAX 114514
#define INF 810893
typedef pair<int, int> pii;

int main()
{
    int N, a, b;
    cin >> N;
    vector<pii> v(N);
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v[i] = pii(a, -b);
    }

    sort(v.begin(), v.end());
    
    int dp[MAX];
    fill(dp, dp + N, INF);    
    for (int i = 0; i < N; i++) {
        *lower_bound(dp, dp + N, -v[i].second) = -v[i].second;
    }
    cout << (lower_bound(dp, dp + N, INF) - dp) << endl;
    return 0;
}
