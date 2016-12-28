#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;
constexpr ll MOD = ((1e9) + 9);

mat mul(const mat& A, const mat& B)
{
    mat C(A.size(), vec(B[0].size()));
    for (int i = 0; i < (int)A.size(); i++) {
        for (int k = 0; k < (int)B.size(); k++) {
            for (int j = 0; j < (int)B[0].size(); j++) {
                C[i][j] = (C[i][j] + (A[i][k] * B[k][j]) % MOD) % MOD;
            }
        }
    }
    return C;
}

mat pow(mat A, ll n)
{
    mat B(A.size(), vec(A.size()));
    for (int i = 0; i < (int)A.size(); i++) {
        B[i][i] = 1;
    }
    while (n > 0) {
        if (n & 1) {
            B = mul(B, A);
        }
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}

int main()
{
    ll W, H, N, tc = 0;
    while (cin >> W >> H >> N, W) {
        map<ll, vector<ll>> mp;
        for (int i = 0; i < N; i++) {
            ll x, y;
            cin >> x >> y; x--; y--;
            mp[y].emplace_back(x);
        }        

        for (auto& m : mp) {
            auto& v = m.second;
            sort(v.begin(), v.end());
        }
        
        mat A(W, vec(W));
        for (int i = 0; i < W; i++) {
            for (int j = -1; j <= 1; j++) {
                int k = i + j;
                if (0 <= k && k < W) {
                    A[i][k] = 1;
                }
            }
        }
        
        ll curr = 0;
        mat B(W, vec(W, 0)); B[0][0] = 1;
        for (const auto& m : mp) {
            ll next = m.first;
            B = mul(B, pow(A, next - curr));
            for (const auto& x : m.second) {
                B[0][x] = 0;
            }                
            curr = next;
        }

        B = mul(B, pow(A, H - curr - 1));

        if (mp.count(0) > 0 && mp[0][0] == 0) {
            cout << "Case " << ++tc << ": " << 0 << endl;
        } else {            
            cout << "Case " << ++tc << ": " << B[0][W - 1] << endl;
        }
    }        
    return 0;
}
