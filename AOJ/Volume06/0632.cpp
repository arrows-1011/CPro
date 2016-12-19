#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M, D;
    cin >> N >> M >> D;
    vector<string> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= M - D; j++) {
            bool put = 1;
            for (int k = j; k < j + D; k++) {
                if (v[i][k] == '#') {
                    put = 0;
                    break;
                }
            }
            if (put) ++cnt;
        }
    }

    for (int j = 0; j < M; j++) {
        for (int i = 0; i <= N - D; i++) {
            bool put = 1;
            for (int k = i; k < i + D; k++) {
                if (v[k][j] == '#') {
                    put = 0;
                    break;
                }
            }
            if (put) ++cnt;
        }
    }
    
    cout << cnt << endl;
    
    return 0;
}
