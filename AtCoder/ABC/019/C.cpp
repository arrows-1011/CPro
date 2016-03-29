#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, a;
    cin >> N;
    set<int> s;
    for (int i = 0; i < N; i++) {
        cin >> a;
        while (a % 2 == 0) {
            a /= 2;
        }
        s.insert(a);
    }
    cout << s.size() << endl;
    return 0;
}
