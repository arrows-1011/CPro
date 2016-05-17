#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    while (cin >> N, N) {
        vector<int> a(N), b(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> b[i];
        }
        
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        
        bool found = 0;
        int aw = 0, bw = 0, bidx = 0;
        for (int i = 0; i < N-1; i++) {
            if (a[i] > b[bidx]) {
                aw++;
            } else {
                bw++;
                bidx++;
            }
            if (aw > bw) {
                found = 1;
                cout << i+1 << endl;
                break;
            }
        }
        if (!found) {
            cout << "NA" << endl;
        }
    }        
    return 0;
}

/*
  K体で戦うとき、2人とも強い方からK体使うことは明らか。
  わたしは彼女がどのような順番で出してきても勝利数が過半数になるならOK。
 */
