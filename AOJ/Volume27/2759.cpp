#include <bits/stdc++.h>

using namespace std;

int solve(int iL, int iR, int nL, int nR, int t)
{
    if (iL >= 5 && iR >= 5) return 2;
    if (nL >= 5 && nR >= 5) return 1;
    
    int res = (t == 0 ? 2 : 1);
    if (t == 0) {
        if (iL < 5) {
            if (nL < 5) res = min(res, solve(iL, iR, iL + nL, nR, 1));
            if (nR < 5) res = min(res, solve(iL, iR, nL, iL + nR, 1));
        }
        if (iR < 5) {
            if (nL < 5) res = min(res, solve(iL, iR, iR + nL, nR, 1));
            if (nR < 5) res = min(res, solve(iL, iR, nL, iR + nR, 1));
        }
    } else {
        if (nL < 5) {
            if (iL < 5) res = max(res, solve(iL + nL, iR, nL, nR, 0));
            if (iR < 5) res = max(res, solve(iL, iR + nL, nL, nR, 0));
        }
        if (nR < 5) {
            if (iL < 5) res = max(res, solve(iL + nR, iR, nL, nR, 0));
            if (iR < 5) res = max(res, solve(iL, iR + nR, nL, nR, 0));
        }
    }
    return res;
}

int main()
{
    int iL, iR, nL, nR;
    cin >> iL >> iR >> nL >> nR;
    cout << (solve(iL, iR, nL, nR, 0) == 1 ? "ISONO" : "NAKAJIMA") << endl;
    return 0;
}
