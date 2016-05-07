#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> d(N);
    for (int i = 0; i < N; i++) {
        cin >> d[i];
    }
    
    for (int i = 0; ; i++) {
        stringstream ss;
        ss << i;
        string s; ss >> s;
        int n = s.size();
        bool found = 0;
        for (int j = 0; j <= N - n; j++) {            
            bool ok = 1;
            for (int k = j; k < j + n; k++) {
                if (d[k] != s[k-j] - '0') {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                found = 1;
                break;
            }
        }
        if (!found) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
