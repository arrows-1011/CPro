#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    string S;
    while (cin >> S, S != "#") {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--; c--; d--;
        char field[9][9];
        int H = 0, W = 0;
        for (int i = 0; i < (int)S.size(); i++) {
            if (S[i] == '/') {
                H++;
                W = 0;
                continue;
            }
            if (isdigit(S[i])) {
                for (int j = 0; j < (S[i] - '0'); j++) {
                    field[H][W + j] = '.';     
                }
                W += (S[i] - '0');
            } else {
                field[H][W] = 'b';
                W++;
            }
        }
        
        field[a][b] = '.';
        field[c][d] = 'b';
        
        H++;
        string res;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; ) {
                if (field[i][j] == 'b') {
                    res += 'b';
                    j++;
                } else {
                    int cnt = 0;
                    while (j < W && field[i][j] == '.') {
                        j++;
                        cnt++;
                    }
                    res += (cnt + '0');
                }
            }
            if (i != H - 1) res += '/';
        }
        cout << res << endl;
    }        
    return 0;
}
