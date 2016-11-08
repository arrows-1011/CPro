#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
 
using ll = long long;
constexpr ll INF = (1LL << 55);
  
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
	cin >> a[i];
    }
    vector<ll> dp(n, INF);
    for (int i = 0; i < n; i++) {
	*lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
    }
    cout << lower_bound(dp.begin(), dp.end(), INF) - dp.begin() << endl;
    return 0;
}
