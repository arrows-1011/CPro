/*
  約数を列挙する.
  O(√n)
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> divisor(int n)
{
    vector<int> res;
    for (int i = 1; i * i <= n; i++) {
	if (n % i == 0) {
	    res.emplace_back(i);
	    if (i != n / i) res.emplace_back(n / i);
	}
    }
    return res;
}
