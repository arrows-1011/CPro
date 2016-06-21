#include <bits/stdc++.h>

using namespace std;

typedef pair<char, int> P;

int idx, N;

int solve(vector<P> &v)
{
    char c = v[idx].first, d = v[idx].second;
    
    idx++;
    if (isdigit(c)) {
        return c - '0';
    } else {
        int res = (c == '*');
        while (idx < N && d < v[idx].second) {
            if (c == '*') {
                res *= solve(v);
            } else {
                res += solve(v);
            }
        }
        return res;
    }
}

int main()
{
    while (cin >> N, N) {
        vector<P> v(N);
        string s;
        for (int i = 0; i < N; i++) {
            cin >> s;
            v[i] = P(s.back(), s.size()-1);
        }
        idx = 0;
        cout << solve(v) << endl;
    }
    return 0;
}
