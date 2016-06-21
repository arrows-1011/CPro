#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &a)
{
    int N = a.size();
    const int p[] = {5, 7, 5, 7, 7};
    for (int i = 0; i < N; i++) {
        bool poss = 1;
        int q = i;
        for (int j = 0; j < 5; j++) {
            int sum = 0;
            for (; q < N; ) {
                sum += a[q++];
                if (sum >= p[j]) break;
            }
            if (sum != p[j]) {
                poss = 0;
                break;
            }               
        }
        if (poss) {
            return i + 1;
        }
    }
    return -1;
}

int main()
{
    int N;
    while (cin >> N, N) {
        vector<int> a(N);
        string s;
        for (int i = 0; i < N; i++) {
            cin >> s;
            a[i] = s.size();
        }
        cout << solve(a) << endl;
    }
    return 0;
}
