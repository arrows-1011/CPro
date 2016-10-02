#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v;
    if (n % 2) {
	for (int i = 0; i < n; i++) {
	    v.push_back((i & 1) ? 0 : m);
	}
    } else {
	for (int i = 0; i < n / 2 - 1; i++) {
	    v.push_back(0);
	}
	for (int i = 0; i <= n / 2; i++) {
	    v.push_back(m);
	}
    }
    for (int i = 0; i < n; i++) {
	if (i > 0) cout << " ";
	cout << v[i];
    }
    cout << endl;
    return 0;
}
