#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

constexpr int MAX = 110;
constexpr int INF = (1 << 20);

int mem[MAX][MAX];

int solve(int L, int R, const vector<int>& c)
{
    if (L > R)  return 0;    
    if (L == R) return -INF;
    
    int& res = mem[L][R];
    if (res != -1) return res;
    
    if (c[L] == c[R]) {
        int nL = L + 1, nR = R - 1;
        while (nL < R  && c[nL] == c[L]) nL++;
        while (nR > nL && c[nR] == c[R]) nR--;
        res = max(res, solve(nL, nR, c) + (nL - L) + (R - nR));

        for (int i = nL + 1; i <= nR - 1; i++) {
            if (c[i] == c[L]) {
                int l = solve(nL, i - 1, c);
                int r = solve(i + 1, nR, c);
                if (l == (i - nL) && r == (nR - i)) {
                    res = max(res, l + r + (nL - L) + (R - nR) + 1);
                }
            }
        }
    }
    
    int nL = L + 1;
    while (nL <= R && c[nL] == c[L]) nL++;
    if (nL - L >= 2) {
        res = max(res, solve(nL, R, c) + (nL - L));
    }
    
    int nR = R - 1;
    while (nR >= L && c[nR] == c[R]) nR--;
    if (R - nR >= 2) {
        res = max(res, solve(L, nR, c) + (R - nR));
    }
        
    for (int i = L; i <= R - 1; i++) {       
        res = max(res, solve(L, i, c) + solve(i + 1, R, c));
    }
    return res;
}

int main()
{
    int N;
    cin >> N;
    vector<int> c(N);
    for (int i = 0; i < N; i++) {
        cin >> c[i];
    }
    memset(mem, -1, sizeof(mem));
    cout << (solve(0, N - 1, c) == N ? "yes" : "no") << endl;
    return 0;
}
