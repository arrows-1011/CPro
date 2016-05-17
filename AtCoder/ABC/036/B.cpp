#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    char c[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> c[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << c[N-j-1][i];
        }
        cout << endl;
    }  
    return 0;
}
