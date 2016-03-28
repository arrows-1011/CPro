#include <iostream>
#include <vector>

using namespace std;

#define F first
#define S second
typedef long long ll;
typedef pair<char, ll> P;

int main()
{
    ll len[3];    
    vector<P> X[3];
    for (int i = 0; i < 3; i++) {
        char c;
        ll l;
        while (cin >> c, c != '$') {
            cin >> l;
            X[i].push_back(P(c, l));
        }
        len[i] = X[i].size();
    }
    for (int i = 0; i <= len[0]-len[1]; i++) {
        bool same = 1;
        for (int j = i; j < i+len[1]; j++) {
            if (X[1][j-i].F != X[0][j].F ||
                (i < j && j < i+len[1]-1 && X[1][j-i].S != X[0][j].S)) {
                same = 0;
                break;
            }
        }
        if (X[0][i].S < X[1][0].S || X[0][i+len[1]-1].S < X[1][len[1]-1].S) {
            continue;
        }

        if (same) {
            vector<P> v, res;
            for (int j = 0; j < i; j++) {
                v.push_back(X[0][j]);
            }
            ll diff = X[0][i].S - X[1][0].S;
            if (len[1] != 1) {
                if (diff > 0) {
                    v.push_back(P(X[0][i].F, diff));      
                }
                for (int j = 0; j < len[2]; j++) {
                    v.push_back(X[2][j]);
                }
                diff = X[0][i+len[1]-1].S - X[1][len[1]-1].S;
                if (diff > 0) {
                    v.push_back(P(X[0][i+len[1]-1].F, diff));
                }
            } else {
                for (int j = 0; j < len[2]; j++) {
                    v.push_back(X[2][j]);
                }                
                if (diff > 0) {
                    v.push_back(P(X[0][i].F, diff));   
                }
            }
            for (int j = i+len[1]; j < len[0]; j++) {
                v.push_back(X[0][j]);
            }
            
            for (int j = 0; j < (int)v.size(); ) {
                ll k = j, sum = 0;
                while (k < (ll)v.size() &&
                       v[j].F == v[k].F) {
                    sum += v[k].S;
                    k++;
                }
                res.push_back(P(v[j].F, sum));
                j = k;
            }
            X[0] = res;
            break;
        }
    }
    for (int i = 0; i < X[0].size(); i++) {
        cout << X[0][i].F << " " << X[0][i].S << " ";
    }
    cout << "$" << endl;
    return 0;
}
