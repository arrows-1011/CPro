#include <bits/stdc++.h>

using namespace std;

int memo[101][2];

int rec(int v, int p)
{
    if (v <= 1) {
        return 1 - p;
    }
    
    int &res = memo[v][p];
    if (res != -1) {
        return res;
    }
    
    if (p == 0) {
        res = 1;
        if (v - 2 >= 0) res = min(res, rec(v - 2, 1));
        if (v - 3 >= 0) res = min(res, rec(v - 3, 1));
        if (v - 5 >= 0) res = min(res, rec(v - 5, 1));
    } else {
        res = 0;
        if (v - 2 >= 0) res = max(res, rec(v - 2, 0));
        if (v - 3 >= 0) res = max(res, rec(v - 3, 0));
        if (v - 5 >= 0) res = max(res, rec(v - 5, 0));
    }
    return res;
}

int main()
{
    int N, a;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        memset(memo, -1, sizeof(memo));
        cout << (rec(a, 0) == 0 ? "First" : "Second") << endl;                
    }
    return 0;
}
