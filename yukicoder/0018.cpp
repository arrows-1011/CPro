#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S;
    cin >> S;
    for (int i = 0; i < (int)S.size(); i++) {
        int n = (i % 26) + 1, s = S[i] - 'A';
        cout << (char)(((s - n + 26) % 26) + 'A');
    }
    cout << endl;
    return 0;
}
