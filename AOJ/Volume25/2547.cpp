#include <iostream>
#include <set>

using namespace std;

constexpr int MAX_N = 200000;

int n;
int h[MAX_N];

int L[MAX_N], R[MAX_N];
int st[MAX_N];

void solve()
{
    int t = 0;
    for (int i = 0; i < n; i++) {
        while (t > 0 && h[st[t - 1]] >= h[i]) t--;
        L[i] = t == 0 ? 0 : (st[t - 1] + 1);
        st[t++] = i;
    }

    t = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (t > 0 && h[st[t - 1]] >= h[i]) t--;
        R[i] = t == 0 ? n : st[t - 1];
        st[t++] = i;
    }

    int res = 0;
    set<pair<int, int>> used;
    for (int i = 0; i < n; i++) {
        if (used.count(make_pair(L[i], R[i])) == 0) {
            used.insert(make_pair(L[i], R[i]));
            res++;
        }
    }

    cout << res << endl;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    solve();
    return 0;
}
