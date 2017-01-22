#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    map<string, int> cnt;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        cnt[s]++;
    }
    bool poss = 1;
    for (auto &x: cnt) {
        if (N % 2 == 0 && x.second > N/2) {
            poss = 0;
        }
        if (N % 2 == 1 && x.second > N/2+1) {
            poss = 0;
        }
    }
    cout << (poss ? "YES" : "NO") << endl;
    return 0;
}
