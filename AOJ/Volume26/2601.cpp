#include <bits/stdc++.h>

using namespace std;
  
const int INF = 1<<28;
  
int main() {
    int W; cin >> W;
    vector<int> a(W);
    for(int i = 0; i < W; ++i) cin >> a[i];
    vector<int> L(W+1), R(W+1);
    L[0] = -1;
    for(int i = 0; i < W; ++i) {
        L[i+1] = L[i] - 1;
        if(a[i] == 0){
            L[i+1] = INF;
        }else if(a[i] < 0){
            L[i+1] = min(L[i+1], -a[i]-1);
        }
    }
    R[W] = -1;
    for(int i = W-1; i >= 0; --i) {
        R[i] = R[i+1] - 1;
        if(a[i] == 0){
            R[i] = INF;
        }else if(a[i] < 0){
            R[i] = min(R[i], -a[i]-1);
        }
    }
    int res = 0;
    for(int i = 0; i < W; ++i) {
        if(a[i] > 0); else continue;
        int t = max(L[i+1], R[i]);
        if(t < 0) continue;
        res += min(a[i], t+1);
    }
    cout << res << endl;
    return 0;
}
