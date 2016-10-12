#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
    string s;
    cin >> s;
    
    ll N = s.size();
    ll S = stol(s);
    ll P = pow(10LL, N);
    vector<ll> p;
    for (int i = 0; i <= 9; i++) {
        p.emplace_back(i);
    }
    
    ll diff = -1;
    string t;
    do {
        ll T = 0;
        string str;
        for (int i = 0; i < N; i++) {
            T *= 10LL;
            T += p[i];
            str += (p[i] + '0');
        }
        ll U = abs(S - T), V = min(U, P - U);
        if (diff < V) {
            diff = V;
            t = str;
        } else if (diff == V) {
            t = min(t, str);
        }
    } while (next_permutation(p.begin(), p.end()));
    
    cout << t << endl;
    return 0;
}

