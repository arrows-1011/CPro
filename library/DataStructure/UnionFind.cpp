#include <iostream>

using namespace std;

#define MAX 100000

int par[MAX], rank_[MAX];

void init(int N)
{
    for (int i = 0; i < N; i++) {
	par[i] = i;
	rank_[i] = 0;
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

    if (rank_[x] < rank_[y]) {
	par[x] = y;
    } else {
	par[y] = x;
	if (rank_[x] == rank_[y]) {
	    rank_[x]++;
	}
    }
}

bool same(int x,int y)
{
    return (find(x) == find(y));
}
