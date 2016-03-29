#include <bits/stdc++.h>

using namespace std;

double dist(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main()
{
    double sx, sy, gx, gy, T, V, x, y;
    cin >> sx >> sy >> gx >> gy >> T >> V;
    int N;
    cin >> N;
    bool poss = 0;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        double d = dist(sx, sy, x, y) + dist(x, y, gx, gy);
        if (d / V <= T) {
            poss = 1;
        }
    }
    cout << (poss ? "YES" : "NO") << endl;
    return 0;
}
