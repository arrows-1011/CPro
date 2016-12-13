#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>

using namespace std;

using ll = long long;

int main()
{
    int N;
    cin >> N;
    vector<ll> v(N + 2, 0);
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &v[i]);
    }
    int res = 0;
    map<ll, int> mp; mp[0] = 0;
    for (int i = 1; i <= N; i++) {
        v[i] += v[i - 1];
        if (!mp.count(v[i])) {
            mp[v[i]] = i;
        } else {
            res = max(res, i - mp[v[i]]);
        }
    }
    printf("%d\n", res);
    return 0;
}
