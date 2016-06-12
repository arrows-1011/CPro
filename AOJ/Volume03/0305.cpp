#include <bits/stdc++.h>

using namespace std;

int get_pos(int r, int t)
{
    return r + t * 5;
}

int main()
{
    int N, r, t;
    cin >> N;
    while (N--) {
        cin >> r >> t;
        bool rr = (r % 100 == 0), tt = (t % 30 == 0);
        r /= 100; t /= 30;
        
        if (rr && tt) {
            cout << get_pos(r, t) << endl;
        } else if (rr && !tt) {
            cout << get_pos(r, t) << " " << get_pos(r, t+1) << endl;
        } else if (!rr && tt) {
            cout << get_pos(r, t) << " " << get_pos(r+1, t) << endl;
        } else {
            cout << get_pos(r, t) << " " << get_pos(r+1, t) << " "
                 << get_pos(r, t+1) << " " << get_pos(r+1, t+1) << endl;
        }
    }
    return 0;
}
