#include <bits/stdc++.h>
 
using namespace std;
 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define FOR1(i,a,b) for(int i = a ; i <= b ; i++)
#define FOR2(i,a,b) for(int i = a ; i >= b ; i--)
 
int main()
{
    int n;
      
    cin >> n;
    while (n--) {
        int s, g;
        vector<int> v;
          
        cin >> s >> g;
        if (s < g) {
            for (int i = s; i <= g; i++) {
                v.push_back(i);
            }
        } else if (s > g) {
            if (s > 5) {
                for (int i = s; i <= 9; i++) {
                    v.push_back(i);
                }                   
                if (g > 5) {
                    for (int i = 5; i >= 0; i--) {
                        v.push_back(i);
                    }
                    for (int i = 1; i <= g; i++) {
                        v.push_back(i);
                    }
                } else {
                    for (int i = 5; i >= g; i--) {
                        v.push_back(i);
                    }
                }
            } else if (s <= 5) {
                for (int i = s; i >= g; i--) {
                    v.push_back(i);
                }
            }
        }        
        for (int i = 0; i < (int)v.size(); i++) {
            if (i > 0) cout << " ";
            cout << v[i];
        }
        cout << endl;
    }
    return 0;
}
