#include <bits/stdc++.h>

using namespace std;

int main()
{
    char field[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> field[i][j];
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (j > 0) {
                cout << " ";
            }
            cout << field[3-i][3-j];
        }
        cout << endl;
    }
    return 0;
}
