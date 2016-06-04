#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;
const ull B = 1000000007ULL;

int main()
{
    int N; // N is the size of string s
    string s;
    cin >> N >> s;
    vector<ull> p(N+1); // p is power (base B)
    vector<ull> hash(N+1); // hash values
    p[0] = 1; hash[0] = 0;
    for (int i = 0; i < N; i++) {
        hash[i+1] = hash[i]*B + s[i];
        p[i+1] = p[i]*B;
    }
    /*
      sの部分文字列s[L,R]のハッシュ値は以下のようになる.
      hash[L,R] := hash[R+1]-hash[L]*p[R-L+1];
    */
    return 0;
}
