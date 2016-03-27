#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M, l, r;
    cin >> N >> M;
    vector<int> v(N+1, 0);
    for (int i = 0; i < M; i++) {
        cin >> l >> r;
        l--; r--;
        v[l]++; v[r+1]--;        
    }
    for (int i = 1; i <= N; i++) {
        v[i] += v[i-1];
    }
    for (int i = 0; i < N; i++) {
        cout << (v[i]&1 ? 1 : 0);
    }
    cout << endl;
    return 0;
}
