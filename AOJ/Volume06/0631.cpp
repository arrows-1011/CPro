#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main()
{
    int N, M, A, B;
    cin >> N >> M;
    vector<pair<int, int>> v(M);
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        v[i] = make_pair(A, B);
    }

    sort(v.rbegin(), v.rend());
    
    int res = 0;
    for (int i = 0; i < M - 1; i++) {
        tie(A, B) = v[i];
        if (A < N) {
            res += N - A;
        }
    }
    cout << res << endl;
    return 0;
}
