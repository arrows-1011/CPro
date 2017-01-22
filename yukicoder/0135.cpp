#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> X(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }
    sort(X.begin(), X.end());

    constexpr int INF = (1 << 29);
    int res = INF;

    for (int i = 1; i < N; i++) {
        if (X[i] != X[i - 1]) {
            res = min(res, X[i] - X[i - 1]);
        }
    }
    cout << (res == INF ? 0 : res) << endl;
    return 0;
}

