#include <iostream>

using namespace std;

constexpr int MAX = 100000;

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
	par[x] = y;
    } else {
	par[y] = x;
	if (rnk[x] == rnk[y]) {
	    rnk[x]++;
	}
    }
}

bool same(int x,int y)
{
    return (find(x) == find(y));
}
