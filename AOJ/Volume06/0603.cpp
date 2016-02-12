#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> bulb(N), count(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> bulb[i];
    }
    count[0] = 1;
    for (int i = 1; i < N; i++) {
        if (bulb[i-1] != bulb[i]) {
            count[i] = count[i-1] + 1;
        } else {
            count[i] = 1;
        }
    }
    auto solve = [=](){
        vector<int> v;
        int mx = 1;
        for (int i = N-1; i >= 0; i--) {
            mx = max(mx, count[i]);
            if (count[i] == 1) {
                v.push_back(mx);
                mx = 1;
            }
        }
        if (v.size() == 1) {
            return v[0];
        }
        
        int res = 0;
        for (size_t i = 0; i < v.size()-1; i++){
            res = max(res, v[i]+v[i+1]);
            if (i+2 < v.size()) {
                res = max(res, v[i]+v[i+1]+v[i+2]);
            }            
        }
        return res;
    };

    cout << solve() << endl;    
    return 0;
}
