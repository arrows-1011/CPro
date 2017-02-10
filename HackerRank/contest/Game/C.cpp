/*
  Solved by grundy number
 */

#include <bits/stdc++.h>

using namespace std;

int memo[15][15];
const int dx[] = {-2, -2, +1, -1};
const int dy[] = {+1, -1, -2, -2};

bool inField(int x, int y)
{
    return (0 <= x && x < 15 && 0 <= y && y < 15);
}

int grundy(int x, int y)
{
    if (memo[y][x] != -1) {
        return memo[y][x];
    }
    set<int> st;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (inField(nx, ny)) {
            st.insert(grundy(nx, ny));
        }
    }
    int res = 0;
    while (st.count(res)) res++;
    return memo[y][x] = res;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        memset(memo, -1, sizeof(memo));
        cout << (grundy(x, y) != 0 ? "First" : "Second") << endl;
    }
    return 0;
}
