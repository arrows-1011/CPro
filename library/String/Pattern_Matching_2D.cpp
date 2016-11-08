#include <iostream>
#include <set>
 
using namespace std;
 
constexpr int MAX = 2048;
using ull = unsigned long long;
 
int N, M, P, Q;
char a[MAX][MAX], b[MAX][MAX];
 
ull _hash[MAX][MAX], tmp[MAX][MAX];
 
void compute_hash(char c[MAX][MAX], int n, int m)
{
    constexpr ull B1 = 9973;
    constexpr ull B2 = 100000007;
   
    ull t1 = 1;
    for (int j = 0; j < Q; j++) t1 *= B1;
   
    for (int i = 0; i < n; i++) {
        ull e = 0;
        for (int j = 0; j < Q; j++) e = e * B1 + c[i][j];
        for (int j = 0; j + Q <= m; j++) {
            tmp[i][j] = e;
            if (j + Q < m) e = e * B1 - t1 * c[i][j] + c[i][j + Q]; 
        }
    }
   
    ull t2 = 1;
    for (int i = 0; i < P; i++) t2 *= B2;
   
    for (int j = 0; j + Q <= m; j++) {
        ull e = 0;
        for (int i = 0; i < P; i++) e = e * B2 + tmp[i][j];
     
        for (int i = 0; i + P <= n; i++) {
            _hash[i][j] = e;
            if (i + P < n) e = e * B2 - t2 * tmp[i][j] + tmp[i + P][j];
        }
    }
}
 
void solve()
{
    multiset<ull> unseen;
    compute_hash(a, P, Q);
    unseen.insert(_hash[0][0]);
    ull res = _hash[0][0], ans = 0;
    compute_hash(b, N, M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (res == _hash[i][j]) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
 
int main()
{
    while (cin >> P >> Q >> N >> M) {
        for (int i = 0; i < P; i++) {
            for (int j = 0; j < Q; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) { 
                cin >> b[i][j];
            }
        }
        solve();
    }
    return 0;
}
