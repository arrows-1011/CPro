#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, L, tab = 0, cnt = 0;
    char ch;
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        cin >> ch;
        if (ch == '+') {
            tab++;
        } else {
            tab--;
        }
        if (tab == L) {
            tab = 0;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
