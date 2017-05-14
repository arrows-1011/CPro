#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M, A, B;
    cin >> N >> M >> A >> B;
    vector<int> D(N);
    for (int i = 0; i < N; i++) {
        cin >> D[i];
    }
    
    int cnt = 0;
    vector<int> p;
    for (int i = 0; i < N; i++) {
        if (D[i] >= A) {
            if (D[i] <= B) cnt++;
            p.emplace_back(D[i]);
        } else {
            break;
        }
    }
    
    int n = p.size(), res = n;
    if (N - n < M) {
        for (int i = n - 1; i >= 0 && cnt > 0; i--) {
            if (p[i] <= B) {
                res--;
                cnt--;
            } else {
                break;
            }
        }
    }
    cout << res << endl;
    return 0;
}
