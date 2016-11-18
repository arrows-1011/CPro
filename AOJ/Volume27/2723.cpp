#include <iostream>
#include <vector>
#include <set>
#include <tuple>

using namespace std;

using ll = long long;

bool in(int d, int D)
{
    return (0 <= d && d < D);
}

int main()
{
    ll A, B, C, N;
    cin >> A >> B >> C >> N;
    vector<int> x(N), y(N), z(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i] >> z[i];
    }
    
    constexpr int dx[] = {-1, +0, +1, +0, +0, +0};
    constexpr int dy[] = {+0, -1, +0, +1, +0, +0};
    constexpr int dz[] = {+0, +0, +0, +0, -1, +1};
    
    set<tuple<int, int, int>> er;
    ll res = 2 * (A * B + B * C + C * A);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 6; j++) {
            int nx = x[i] + dx[j];
            int ny = y[i] + dy[j];
            int nz = z[i] + dz[j];

            if (!in(nx, A) || !in(ny, B) || !in(nz, C)) {
                res--;
                continue;
            }

            if (er.count(make_tuple(nx, ny, nz)) > 0) {
                res--;
            } else {
                res++;
            }            
        }
        er.insert(make_tuple(x[i], y[i], z[i]));
    }
    cout << res << endl;
    return 0;
}
