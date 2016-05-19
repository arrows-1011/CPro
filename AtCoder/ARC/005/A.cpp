#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, cnt = 0;
    cin >> N;
    string w;    
    for (int i = 0; i < N; i++) {
        cin >> w;
        if (i == N-1) w.pop_back();
        if (w == "TAKAHASHIKUN" ||
            w == "Takahashikun" ||
            w == "takahashikun") {
            ++cnt;
        }
    }
    cout << cnt << endl;
    return 0;
}
