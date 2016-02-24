#include <iostream>

using namespace std;

#define MAX 1000

class Union_Find {
  public:
    int par[MAX], rank[MAX], size[MAX], gnum;
    
    Union_Find(int N) {
        gnum = N;
        for (int i = 0; i < N; i++) {
            par[i] = i;
            rank[i] = 0;
            size[i] = 1;
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
        
        if (rank[x] < rank[y]) {
            par[x] = y;
            size[y] += size[x];
        } else {
            par[y] = x;
            size[x] += size[y];
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
        gnum--;
    }

    bool same(int x, int y)
    {
        return (find(x) == find(y));
    }

    int getSize(int x)
    {
        return size[find(x)];
    }

    int groups()
    {
        return gnum;
    }
};
