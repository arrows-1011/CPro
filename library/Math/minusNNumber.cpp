#include <iostream>

using namespace std;

using ll = long long;

string solve(ll x, ll N)
{
    string res;
    if (x == 0LL) return "0";
    ll a, b;
    int t = 0;
    for (; x; t++) {
	t = t & 1;
	a = x / N;
	b = x - a * N;
	if (b < 0 && t == 0) {
	    a--;
	    b += N;
	} else if(b > 0 && t == 1) {
	    a++;
	    b -= N;
	}
	b = (b < 0 ? -b : b);
	res = " " + res;
	res[0] = b + '0';
	x = a;
    }
    return res;
}

int main()
{
    ll x;
    while (cin >> x, x) {
	cout << solve(x, 10) << endl;
    }
    return 0;
}
