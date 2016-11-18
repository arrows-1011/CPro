#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

using ll = long long;

struct Data {
    ll h, a, d, s;
    
    Data() {}
    Data(ll h, ll a, ll d, ll s) :
        h{h}, a{a}, d{d}, s{s} {}

    bool operator < (const Data& d) const {
        return s < d.s;
    }
};

istream& operator >> (istream& is, Data& d)
{
    return is >> d.h >> d.a >> d.d >> d.s;
}

ll solve(Data& M, vector<Data>& ene)
{
    vector<pair<double, Data>> v;
    for (const Data& e : ene) {
        if (M.a <= e.d && M.d < e.a) return -1;
        ll turn = ceil((double)e.h / (M.a - e.d));
        if (e.a - M.d <= 0) continue;
        v.emplace_back((double)turn / (e.a - M.d), e);
    }

    sort(v.begin(), v.end());
    
    ll res = 0, total_turn = 0;
    for (const auto& d : v) {
        Data e = d.second;
        ll turn = ceil((double)e.h / (M.a - e.d));
        total_turn += turn;
        
        ll damage = (total_turn - (M.s > e.s)) * max(0LL, e.a - M.d);
        M.h -= damage;
        if (M.h <= 0) return -1;
        res += damage;
    }        
    return res;
}

int main()
{
    int N;
    cin >> N;
    Data M;
    cin >> M;
    vector<Data> ene(N);
    for (int i = 0; i < N; i++) {
        cin >> ene[i];        
    }
    cout << solve(M, ene) << endl;
    return 0;
}
