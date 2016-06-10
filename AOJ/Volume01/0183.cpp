#include <bits/stdc++.h>

using namespace std;

int main()
{
    char c;
    while (cin >> c, c != '0') {
        char b[3][3]; b[0][0] = c;
        for (int i = 1; i < 9; i++) {
            cin >> b[i/3][i%3];
        }
        
        auto win = [&](char c) -> bool {
            for (int i = 0; i < 3; i++) {
                if (b[i][0] == c && b[i][1] == c && b[i][2] == c) {
                    return true;
                }
                if (b[0][i] == c && b[1][i] == c && b[2][i] == c) {
                    return true;
                }
            }

            if (b[0][0] == c && b[1][1] == c && b[2][2] == c) {
                return true;
            }
            if (b[0][2] == c && b[1][1] == c && b[2][0] == c) {
                return true;
            }
            
            return false;
        };

        if (win('b')) {
            cout << 'b' << endl;
        } else if (win('w')) {
            cout << 'w' << endl;
        } else {
            cout << "NA" << endl;
        }
    }
    return 0;
}
