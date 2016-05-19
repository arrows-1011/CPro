#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<string> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    int p = 0;
    bool draw = 1;
    set<string> used;
    for (int i = 0; i < N; i++) {
        if (i > 0) {
            if (used.count(a[i]) > 0 ||
                a[i-1][a[i-1].size()-1] != a[i][0]) {
                draw = 0;
                break;
            }            
        }
        p ^= 1;
        used.insert(a[i]);
    }

    if (draw) {
        cout << "DRAW" << endl;
    } else {
        cout << (p == 0 ? "LOSE" : "WIN") << endl;
    }
    return 0;
}
