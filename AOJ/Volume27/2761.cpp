#include <bits/stdc++.h>

using namespace std;

int N, M;
int x[100];
int memo[110][110][10];
int a[10], b[10], c[10];

int rec(int L, int R, int m)
{
    if (R - L == 0) {
	return (x[L] == a[m] ? 1 : 2);
    }
    int &res = memo[L][R][m];
    if (res > 0) return res;
    res = 2;
    for (int i = L; i <= R; i++) {
	int d = rec(L, i, b[m]);
	int e = rec(i + 1, R, c[m]);
	if (d == 1 && e == 1) {
	    res = 1;
	    break;
	}
    }
    return res;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++) {
	cin >> x[i];
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
	cin >> a[i] >> b[i] >> c[i];
	b[i]--; c[i]--;
    }
    memset(memo, 0, sizeof(memo));
    cout << (rec(0, N - 1, 0) == 1 ? "Yes" : "No") << endl;
    return 0;
}
