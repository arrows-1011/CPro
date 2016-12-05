#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M, Q;
    cin >> N >> M >> Q;
    
    vector<int> f(N), b(N);
    vector<bool> exist(N);
    for (int i = 0; i < N; ++i) {
        f[i] = (i + 1) % N;
        b[i] = (i - 1 + N) % N;
        exist[i] = 1;
    }
    
    int baton = 0;
    for (int i = 0; i < M; ++i) {
        int a;
        cin >> a;
        for (int j = 0; j < a; ++j) {
            baton = (a & 1 ? b[baton] : f[baton]);
        }
        exist[baton] = 0;
        b[f[baton]] = b[baton];
        f[b[baton]] = f[baton];        
        baton = f[baton];
    }    
    for (int i = 0; i < Q; ++i) {
        int q;
        cin >> q;
        cout << exist[q] << endl;
    }
    return 0;
}
