#include <bits/stdc++.h>

using namespace std;

struct Data {
    int y, m, d, ny;
} nn;

int main()
{
    while (cin >> nn.y >> nn.m >> nn.d) {
        int num = nn.d + nn.m * 100 + nn.y * 10000;
         
        if (num < 18680908) {
            cout << "pre-meiji" << endl;
            continue;
        } else if (18680908 <= num && num <= 19120729) {
            cout << "meiji" << ' ';
            nn.ny = nn.y - 1867;
        } else if (19120730 <= num && num <= 19261224) { 
            cout << "taisho" << ' ';
            nn.ny = nn.y - 1911;
        } else if (19261225 <= num && num <= 19890107) {
            cout << "showa" << ' ';
            nn.ny = nn.y - 1925;
        } else {
            cout << "heisei" << ' ';
            nn.ny = nn.y - 1988;
        }
        cout << nn.ny << ' ' << nn.m << ' ' << nn.d << endl;
    }
    return 0;
}
