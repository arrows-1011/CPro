#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main()
{
    ll N, T, Q;
    cin >> N >> T >> Q;
    vector<ll> A(N), D(N), left, right, rleft, rright;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> D[i];
        if (D[i] == 1) {      
            right.push_back(A[i]);
            rleft.push_back(-A[i]);
        } else {
            left.push_back(A[i]);
            rright.push_back(-A[i]);
        }
    } 

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
   
    sort(rleft.begin(), rleft.end());
    sort(rright.begin(), rright.end());
 
    ll q;
    for (int i = 0; i < Q; i++) {
        cin >> q; q--;    
        if (D[q] == 1) {
            ll l = lower_bound(left.begin(), left.end(), A[q]) - left.begin();
            if (l == (int)left.size()) {
                cout << A[q] + T << endl;
                continue;
            }
            
            ll ub = upper_bound(right.begin(), right.end(), left[l]) - right.begin()-1;
            ll now = (right[ub] != A[q] ? right[ub] : A[q]); 
            if (right[ub] != A[q]) {
                ll g;
                if (now + T >= left[l] - T) {
                    g = (now + left[l]) / 2;
                } else {
                    g = now + T;
                }
                cout << min(A[q] + T, g) << endl;
            } else {
                if (now + T >= left[l] - T) {
                    cout << (now + left[l]) / 2 << endl;
                } else {
                    cout << now + T << endl;
                }
            }   
        } else {  
            ll l = lower_bound(rleft.begin(), rleft.end(), -A[q]) - rleft.begin();
            if (l == (int)rleft.size()) {
                cout << A[q] - T << endl;
                continue;
            }

            ll ub = upper_bound(rright.begin(), rright.end(), rleft[l]) - rright.begin()-1;
            ll now = (-rright[ub] != A[q] ? -rright[ub] : A[q]);
            if (-rright[ub] != A[q]) {
                ll g;
                if (now - T <= -rleft[l] + T) {
                    g = (now - rleft[l]) / 2;
                } else {
                    g = now - T;
                }
                cout << max(A[q] - T, g) << endl;
            } else {
                if (now - T <= -rleft[l] + T) {
                    cout << (now - rleft[l]) / 2 << endl;
                } else {
                    cout << now - T << endl;
                }
            } 
        }
    }  
    return 0;
}
