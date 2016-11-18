#include <iostream>
#include <vector>
#include <map>

using namespace std;

using ull = unsigned long long;
constexpr int MAX = 100000;
constexpr ull B = 100000007;

vector<int> G[MAX];
map<ull, ull> mp;

ull dfs(int v)
{
    ull res = 1;
    for (auto to : G[v]) {
        res += dfs(to) * B;
    }
    mp[res]++;
    return res;
}

ull solve()
{
    dfs(0);
    ull res = 0;
    for (auto x : mp) {
        if (x.second >= 2) {
            res += x.second * (x.second - 1) / 2;
        }
    }
    return res;
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        G[a].emplace_back(b);
    }
    cout << solve() << endl;
    return 0;
}
