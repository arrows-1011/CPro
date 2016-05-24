#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    char c[N][9];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> c[i][j];
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < N; j++) {
            if (c[j][i] == 'x') {
                cnt++;
            } else if (c[j][i] == 'o') {
                cnt++;
                while (j < N && c[j][i] == 'o') {
                    j++;
                }
                j--;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}
