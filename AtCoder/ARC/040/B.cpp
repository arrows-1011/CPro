#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, R;
    cin >> N >> R;
    vector<char> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    int pos = 0, shoot = 0;
    bool flg = 0;
    for (int i = N-1; i >= 0; i--) {
        if (S[i] == '.') {
            for (int j = i; j > max(0, i-R); j--) {
                S[j] = 'o';
            }
            shoot++;
            i = max(0, i-R+1);
            if (!flg) {
                flg = 1;
                pos = i;
            }
        }        
    }
    cout << pos + shoot << endl;
    return 0;
}
