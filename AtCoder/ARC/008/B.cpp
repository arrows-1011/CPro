#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    char ch;
    vector<int> a(26, 0), b(26, 0);
    for (int i = 0; i < N; i++) {
        cin >> ch;
        a[ch-'A']++;
    }
    for (int i = 0; i < M; i++) {
        cin >> ch;
        b[ch-'A']++;
    }
    
    int res = 0;
    for (int i = 0; i < 26; i++) {
        if (a[i] == 0 || b[i] == 0) {
            if (a[i] > 0) {
                res = -1;
                break;
            }                
            continue;
        }        
        res = max(res, (a[i] + b[i] - 1) / b[i]);
    }
    cout << res << endl;
    return 0;
}
