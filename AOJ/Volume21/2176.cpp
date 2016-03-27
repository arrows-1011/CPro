#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100
#define INF (1<<29)
typedef pair<int, int> pii;

int main()
{
    int n, d, m;
    while (cin >> n >> d, n) {
        int N = 0;
        vector<int> cap[MAX];        
        for (int i = 0; i < n; i++) {
            cin >> m;
            cap[i].resize(m);
            for (int j = 0; j < m; j++, N++) {
                cin >> cap[i][j];                
            }
        }
        bool possible = 1;
        vector<int> cur(n, 0), sum(n, 0);        
        while (N--) {
            int p = -1, maxi = -INF;
            vector<pii> v(n);
            for (int i = 0; i < n; i++) {
                v[i] = pii(sum[i], i);
            }
            sort(v.begin(), v.end());
            for (int i = 0; i < n; i++) {
                if (cur[i] == (int)cap[i].size()) {
                    continue;
                }
                int j = 0;
                for (; j < n; j++) {
                    if (v[j].second != i) {
                        break;
                    }
                }
                if (sum[i] + cap[i][cur[i]] > maxi &&
                    sum[i] + cap[i][cur[i]] - v[j].first <= d) {
                    maxi = sum[i] + cap[i][cur[i]];
                    p = i;
                }
            }
            if (p == -1) {
                possible = 0;
                break;
            }
            
            sum[p] += cap[p][cur[p]++];
        }
        cout << (possible ? "Yes" : "No") << endl;
    }
    return 0;
}
