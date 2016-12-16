#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> v;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y; y--;
        v.emplace_back(x, y);
    }

    sort(v.begin(), v.end());    
    
    vector<int> cnt(N, 1);
    vector<vector<int>> prev(N, vector<int>(2));

    for (int i = 0; i < M; i++) {
        int p = v[i].second;
        int c1 = cnt[p], c2 = cnt[p + 1];
        
        cnt[p]     += c2 - prev[p][0];
        cnt[p + 1] += c1 - prev[p][1];

        prev[p][0] = cnt[p];
        prev[p][1] = cnt[p + 1];
    }

    for (int i = 0; i < N; i++) {
        if (i > 0) cout << " ";
        cout << cnt[i];
    }
    cout << endl;
    return 0;
}
