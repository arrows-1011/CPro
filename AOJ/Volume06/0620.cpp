#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < M; i++) {
        int k = i + 1;
        for (int j = 0; j < N-1; j++) {
            if (a[j] % k > a[j+1] % k) {
                swap(a[j], a[j+1]);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << a[i] << endl;
    }    
    return 0;
}
