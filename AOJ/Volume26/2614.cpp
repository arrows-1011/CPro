#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

using ull = unsigned long long;
constexpr ull B = 53173ULL;

vector<ull> rolling_hash(const string& s, int N, vector<ull>& p)
{
    vector<ull> _hash(N + 1);
    p.resize(N + 1);
    p[0] = 1;
    for (int i = 0; i < N; i++) {
        _hash[i + 1] = _hash[i] * B + s[i];
        p[i + 1] = p[i] * B;
    }
    return _hash;
}

bool check(const vector<ull>& v, ull x)
{
    return binary_search(v.begin(), v.end(), x);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string S, T;
    cin >> S >> T;

    int s = S.size(), t = T.size();

    vector<ull> p;
    auto ht = rolling_hash(T, t, p);
    
    auto gen_ch = [](int x) -> char {
        if (x < 26) return (char)('a' + x);
        x -= 26;
        return (char)('A' + x);
    };
    
    vector<ull> v;
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < 52; j++) {
            char ch = gen_ch(j);
            if (ch == T[i]) continue;
            auto hv = ht[t] + (ch - T[i]) * p[t - i - 1];
            v.emplace_back(hv);
        }
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    auto hs = rolling_hash(S, s, p);
    
    int res = 0;
    for (int i = 0; i <= s - t; i++) {
        
        if (check(v, hs[i + t] - hs[i] * p[t])) {
            ++res;
        }
    }  
    cout << res << endl;
    return 0;
}
