#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
 
int main()
{
    int n;
    while (cin >> n, n) {
	ll a[n], ans = 0;
 
	cin >> a[0];
	for (int i = 1; i < n; i++) {
	    cin >> a[i];
	}
	sort(a, a + n);
 
	for (int i = 1; i < n; i++) {
	    a[i] += a[i-1];
	    ans += a[i-1];
	}
	cout << ans << endl;
    }
    return 0;
}
