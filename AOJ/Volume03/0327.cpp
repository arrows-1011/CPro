#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int>& v)
{
    int res = v[0];
    res += v[1] * 10 + v[2];
    res += v[3] * 100 + v[4] * 10 + v[5];
    return (res == v[6] * 100 + v[7] * 10 + v[8]);
}

int main()
{
    vector<int> p, v(9);
    for (int i = 0; i < 9; i++) {
        p.push_back(i + 1);
    }
    for (int i = 0; i < 9; i++) {
        cin >> v[i];
    }
    int res = 0;
    do {
        vector<int> nv(9);
        bool ok = 1;
        for (int i = 0; i < 9; i++) {
            nv[i] = p[i];
            if (v[i] == -1) continue;
            if (v[i] != p[i]) {
                ok = 0;
                break;
            }
        }
        if (ok && check(nv)) res++;
    } while (next_permutation(p.begin(), p.end()));
    cout << res << endl;
    return 0;
}
