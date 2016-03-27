#include <bits/stdc++.h>
 
using namespace std;
 
inline int change_pixel(int v, string &str)
{
    int nv = v;
    const int d[7][7] =
        {
            { 8,  9,  3,  4,  5,  0,  1},
            { 9, 10,  4,  5,  6,  1,  2},
            {12, 13,  7,  8,  9,  3,  4},
            {13, 14,  8,  9, 10,  4,  5},
            {14, 15,  9, 10, 11,  5,  6},
            {16, 17, 12, 13, 14,  8,  9},
            {17, 18, 13, 14, 15,  9, 10}
        };
 
    for (int i = 0; i < 7; i++) {
        int bit = 0;
        nv &= ~(1 << d[i][3]);
        for (int j = 0; j < 7; j++) {
            bit |= (v >> d[i][j] & 1) ? (1<<j) : 0;
        }        
        nv |= (1 << d[i][3])*(str[bit] - '0');
    }
    return nv;
}
 
bool is_idempotent(string &str)
{
    for (int i = 0; i < (1<<19); i++) {
        int before = i, after;
        before = change_pixel(before, str);
        after  = change_pixel(before, str);
        if ((before >> 9 & 1) != (after >> 9 & 1)) {
            return false;
        }
    }
    return true;
}
 
int main()
{
    string str;
    while (cin >> str, str != "#") {
        cout << (is_idempotent(str) ? "yes" : "no") << endl;
    }
    return 0;
}
