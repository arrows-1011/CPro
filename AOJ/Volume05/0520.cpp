#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 100
typedef long long ll;

vector<int> p, q, r, b;

int lcm(ll a, ll b)
{
    return a / __gcd(a, b) * b;
}

/*
  左端 = lw * p[v] と 右端 = rw * q[v] を等しくしたい。
  それぞれに何かを掛けると等しくなる。
  l = lcm(lw * p[v], rw * q[v])
  とする。
  
  l / p[v] が左端になり、 l / q[v] が右端になる。
 */

int dfs(int v)
{
    if (v == -1) return 1;    
    int lw = dfs(r[v]), rw = dfs(b[v]);
    int l = lcm(p[v] * lw, q[v] * rw);
    return l / p[v] + l / q[v];
}
 
void init(int N)
{
    p.resize(N); q.resize(N);
    r.resize(N); b.resize(N);
}

int main()
{
    int N;
    while (cin >> N, N) {
        init(N);
        bool used[MAX_N] = {};
        for (int i = 0; i < N; i++) {
            cin >> p[i] >> q[i] >> r[i] >> b[i];
            r[i]--; b[i]--;
            if (r[i] >= 0) used[r[i]] = 1;
            if (b[i] >= 0) used[b[i]] = 1;
            int gcd = __gcd(p[i], q[i]);
            p[i] /= gcd;
            q[i] /= gcd;
        }
        for (int i = 0; i < N; i++) {
            if (!used[i]) {
                cout << dfs(i) << endl;
                break;
            }            
        }
    }
    return 0;
}
