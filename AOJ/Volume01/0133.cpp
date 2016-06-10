#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    char a[8][8][4];

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> a[i][j][0];
        }

    }

    for (int k = 0; k < 3; k++) {
        cout << (k + 1) * 90 << endl;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
		cout << a[7-j][i][k];
		a[i][j][k+1] = a[7-j][i][k];
            }
            cout << endl;
        }
    }
    return 0;
}
