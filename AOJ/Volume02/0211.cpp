#include <cstdio>
#include <cmath>
#include <algorithm>
 
using namespace std;
 
#define MAX 10
typedef long long ll;
 
ll d[MAX], v[MAX];
 
ll gcd(ll a, ll b)
{
    return __gcd(a, b);
}
 
ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}
 
int main()
{
    int n;
 
    while (scanf("%d", &n), n) {
	for (int i = 0; i < n; i++) {
	    scanf("%lld %lld", &d[i], &v[i]);
	    ll a = gcd(d[i], v[i]);
	    d[i] /= a;
	    v[i] /= a;
	}       
     
	ll T = d[0], V = v[0];
	for (int i = 1; i < n; i++) {
	    T = lcm(T, d[i]);
	    V = gcd(V, v[i]);
	}
     
	for (int i = 0; i < n; i++) {
	    ll div = T / d[i];
	    printf("%lld\n", div*v[i]/V);
	}
    }
    return 0;
}
