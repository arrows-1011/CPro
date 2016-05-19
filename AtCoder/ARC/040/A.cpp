#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, R = 0, B = 0;
    cin >> N;
    char ch;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> ch;
            if (ch == 'B') B++;
            if (ch == 'R') R++;
        }
    }

    if (B < R) {
        cout << "TAKAHASHI" << endl;
    } else if (B > R) {
        cout << "AOKI" << endl;
    } else {
        cout << "DRAW" << endl;
    }
    return 0;
}
