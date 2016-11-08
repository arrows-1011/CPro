/*
  階乗を求める。ただし 1 <= n <= 20
*/

#include <iostream>

using namespace std;

using ll = long long;

ll dp[20];

ll factorial(int n)
{
    if (dp[n]) return dp[n];

    if (n == 1) return dp[n] = 1;
    return dp[n] = n * factorial(n - 1);
}

int main()
{
    int n;

    while (cin >> n, n) {
	cout << factorial(n) << endl;
    }

    return 0;
}
