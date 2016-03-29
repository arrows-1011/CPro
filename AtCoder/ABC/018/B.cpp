#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    int N, l, r;
    cin >> str >> N;
    for (int i = 0; i < N; i++) {
        cin >> l >> r; l--; r--;
        string nstr = str;
        for (int j = l; j <= r; j++) {
            nstr[j] = str[r-j+l];
        }
        str = nstr;
    }
    cout << str << endl;
    return 0;
}
