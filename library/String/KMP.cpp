/*
  未検証
 */

#include <iostream>
#include <vector>

using namespace std;

using Vec = vector<int>;

Vec build_fail(const string& s)
{
    Vec fail(s.size() + 1);
    int j = fail[0] = -1;
    for (int i = 1; i <= (int)s.size(); i++) {
	while (j >= 0 && s[j] != s[i-1]) j = fail[j];
	fail[i] = ++j;
    }
    return fail;
}

int match(const string& t, const string& s, const Vec& fail)
{
    int res = 0, n = t.size(), m = s.size();
    for (int i = 0, k = 0; i < n; i++) {
	while (k >= 0 && s[k] != t[i]) k = fail[k];
	if (++k >= m) {
	    res++;
	    k = fail[k];
	}
    }
    return res;
}

