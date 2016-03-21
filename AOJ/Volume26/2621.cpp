#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, W;
    cin >> N;
    vector<int> X(N), Y(N);
    map<int, map<int, int>> coor;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i] >> W;
        coor[X[i]][Y[i]] = W;
    }
    int res = 0;
    for (int i = 0; i < N; i++) {
        res = max(res, coor[X[i]][Y[i]] +
                       coor[X[i]+1][Y[i]] +
                       coor[X[i]][Y[i]+1] +
                       coor[X[i]+1][Y[i]+1]);

        res = max(res, coor[X[i]][Y[i]] +
                       coor[X[i]+1][Y[i]] +
                       coor[X[i]][Y[i]-1] +
                       coor[X[i]+1][Y[i]-1]);
    }
    cout << res << " / " << 1 << endl;
    return 0;
}
