#include <bits/stdc++.h>

using namespace std;

bool check(int x)
{
    int v = x % 10;
    while (x > 0) {
        if (x % 10 != v) {
            return 0;
        }
        x /= 10;
    }
    return 1;
}

int main()
{
    int N, cnt = 0;
    cin >> N;
    for (int i = 1; ; i++) {       
        if (check(i)) cnt++;
        if (cnt == N) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
