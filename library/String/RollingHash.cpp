#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;
const ull B = 1000000007ULL;

/*
  sの部分文字列s[L,R]のハッシュ値は以下のようになる.
  hash[L,R] := hash[R+1]-hash[L]*p[R-L+1];
*/

vector<ull> rolling_hash(string &s, int N, vector<ull> &p)
{
    vector<ull> _hash(N+1);
    p.resize(N+1);
    for (int i = 0; i < N; i++) {
        _hash[i+1] = _hash[i] * B + s[i];
        p[i+1] = p[i] * B;
    }
    return _hash;
}
