#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, A, bug_cnt = 0;
    double ave = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A;
        if (A > 0) {
            bug_cnt++;
            ave += A;
        }
    }
    ave /= bug_cnt;
    cout << ceil(ave) << endl;
    return 0;
}
