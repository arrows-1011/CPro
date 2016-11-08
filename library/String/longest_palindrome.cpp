/*
  最長回文 O(n)
*/

#include <iostream>
#include <algorithm>

using namespace std;

int longest_palindrome(string& str, int N)
{
    int r[2 * N], k;

    for (int i = 0, j = 0; i < 2 * N; i += k, j = max(j - k, 0)) {
	while (i - j >= 0 && i + j + 1 < 2 * N &&
               str[(i - j) / 2] == str[(i + j + 1) / 2]) ++j;
	r[i] = j;
	for (k = 1; i - k >= 0 && r[i] - k >= 0 && r[i - k] != r[i] - k; k++) {
	    r[i + k] = min(r[i - k], r[i] - k);
	}
    }
    return *max_element(r, r + 2 * N);
}
