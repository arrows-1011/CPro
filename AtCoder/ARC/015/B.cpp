#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, cnt[6] = {};
    cin >> N;
    double MT, mT;    
    for (int i = 0; i < N; i++) {
        cin >> MT >> mT;
        if (MT >= 35) {
            cnt[0]++;
        } else if (MT >= 30) {
            cnt[1]++;
        } else if (MT >= 25) {
            cnt[2]++;
        }

        if (mT >= 25) {
            cnt[3]++;
        }
        if (mT < 0 && MT >= 0) {
            cnt[4]++;
        }
        if (MT < 0) {
            cnt[5]++;
        }
    }
    for (int i = 0; i < 6; i++) {
        if (i > 0) cout << " ";
        cout << cnt[i];
    }
    cout << endl;
    return 0;
}
