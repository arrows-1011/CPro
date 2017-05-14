#include <bits/stdc++.h>
 
using namespace std;
 
int solve(int N, vector<int> &cnt)
{
    if (cnt[0] == N) return 1;
 
    int res = 0, p = (cnt[1] > cnt[2] ? 1 : 2);
    cnt[p]--;
         
    while (1) {
        res++;
        if (p == 0) {
            break;
        } else if (p == 1) {
            if (cnt[1] > 0) {
                cnt[1]--;
                p = 2;
            } else if (cnt[0] > 0) {
                cnt[0]--;
                p = 1;
            } else {
                p = 0;
                if (cnt[2] == 0) {
                    break;
                }
            }                
        } else {
            if (cnt[2] > 0) {
                cnt[2]--;
                p = 1;
            } else if (cnt[0] > 0) {
                cnt[0]--;
                p = 2;
            } else {
                p = 0;
                if (cnt[1] == 0) {
                    break;
                }
            }
        }
    }
    return res;
}
 
int main()
{
    int N;
    cin >> N;
    int a;
    vector<int> cnt(3, 0);
    for (int i = 0; i < N; i++) {
        cin >> a;
        cnt[a%3]++;
    }
 
    cout << solve(N, cnt) << endl;
    return 0;
}
