#include <bits/stdc++.h>

using namespace std;

#define MAX 100000
typedef long long ll;

int par[MAX], rnk[MAX];

void init(int N)
{
    for (int i = 0; i < N; i++) {
        par[i] = i;
        rnk[i] = 0;
    }
}

int find(int x)
{
    if (par[x] == x) {
        return x;
    }
    return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x == y) return;

    if (rnk[x] < rnk[y]) {
        par[x] = par[y];
    } else {
        par[y] = par[x];
        if (rnk[x] == rnk[y]) rnk[x]++;
    }
}

bool same(int x, int y)
{
    return (find(x) == find(y));
}

int main()
{
    int N;
    string a, b;
    cin >> N >> a >> b;

    init(MAX);
    
    int alp[500] = {};
    for (int i = 0; i < N; i++) {
        unite(a[i], b[i]);
        alp[a[i]] = alp[b[i]] = 1;
    }

    for (int i = 0; i <= 9; i++) {
        char ch = (char)(i + '0');
        alp[find(ch)] = 0;
    }

    ll res = 1;
    for (int i = 0; i < 26; i++) {
        char ch = (char)(i + 'A');
        if (!alp[ch]) continue;
        if (find(ch) == ch) {
            if (a[0] != ch && b[0] != ch) {
                res *= 10;
            } else {
                res *= 9;
            }
        }
    }
    cout << res << endl;
    return 0;
}
