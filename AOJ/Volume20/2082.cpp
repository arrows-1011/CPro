#include <bits/stdc++.h>

using namespace std;

string d2b(int x, int M)
{
    string s;
    while (x > 0) {
        s += (x % 2 == 0 ? "0" : "1");
        x /= 2;
    }
    while ((int)s.size() < M) {
        s += "0";
    }
    reverse(s.begin(), s.end());
    return s;
}

int main()
{
    int N, M;
    while (cin >> N >> M, N) {
        vector<int> L(N);
        for (int i = 0; i < N; i++) {
            cin >> L[i];
        }

        vector<string> bits;
        for (int i = 0; i < (1<<M); i++) {
            if (L[0] == __builtin_popcount(i)) {
                bits.push_back(d2b(i, M));
            }
        }
        
        for (int i = 1; i < N; i++) {
            vector<string> nbits;
            for (int j = 0; j < (int)bits.size(); j++) {
                int cnt = 0;
                for (int k = i; k < i + M; k++) {
                    if (bits[j][k] == '1') {
                        cnt++;
                    }
                }
                int bit_cnt = L[i];
                if (cnt == bit_cnt) {
                    nbits.push_back(bits[j] + "0");
                } else if (cnt + 1 == bit_cnt) {
                    nbits.push_back(bits[j] + "1");
                }
            }
            bits = nbits;
        }

        if (bits.size() == 0) {
            cout << "Goofy" << endl;
        } else {
            cout << bits[0] << endl;
        }
    }
    return 0;
}
