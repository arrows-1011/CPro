/*
  メモ化再帰解法
 */

#include <bits/stdc++.h>

using namespace std;

#define INF (1LL<<55)
typedef long long ll;

map<tuple<int, int, int, int>, ll> memo;

ll dfs(int curr, int R, int G, int B)
{
    if (memo.count(make_tuple(curr, R, G, B)) > 0) {
        return memo[make_tuple(curr, R, G, B)];
    }

    if (curr > 500) {
        return INF;
    }

    if (R == 0 && G == 0 && B == 0) {
        return 0;
    }
    
    ll res = INF;
    if (R > 0) {
        res = min(dfs(curr + 1, R, G, B),
                  dfs(curr + 1, R - 1, G, B) + abs(-100 - curr));
    } else if (G > 0) {
        res = min(dfs(curr + 1, R, G, B),
                  dfs(curr + 1, R, G - 1, B) + abs(curr));
    } else {
        res = min(dfs(curr + 1, R, G, B),
                  dfs(curr + 1, R, G, B - 1) + abs(100 - curr));
    }               
    return memo[make_tuple(curr, R, G, B)] = res;
}

int main()
{
    int R, G, B;
    cin >> R >> G >> B;
    cout << dfs(-500, R, G, B) << endl;
    return 0;
}
