#include <bits/stdc++.h>

using namespace std;

bool check(int x, set<int> &D)
{
    while (x > 0) {
        if (D.count(x % 10)) {
            return 0;
        }
        x /= 10;
    }
    return 1;
}

int main()
{
    int N, K, x;
    cin >> N >> K;
    set<int> D;
    for (int i = 0; i < K; i++) {
        cin >> x;
        D.insert(x);
    }

    for (int i = N; ; i++) {
        if (check(i, D)) {
            cout << i << endl;
            break;
        }            
    }    
    return 0;
}
