#include <iostream>
#include <string>
 
using namespace std;
 
#define MAX_N 100000
 
int n, k, sa[MAX_N];
int _rank[MAX_N], tmp[MAX_N];
 
bool compare_sa(int i, int j)
{
    if (_rank[i] != _rank[j]) {
	return _rank[i] < _rank[j];
    } else {
	int ri = i + k <= n ? _rank[i+k] : -1;
	int rj = j + k <= n ? _rank[j+k] : -1;
	return ri < rj;
    }
}
 
void construct_sa(string &S, int *sa)
{
    n = S.length();
   
    for (int i = 0; i <= n; i++) {
	sa[i] = i;
	_rank[i] = i < n ? S[i] : -1;
    }
 
    for (k = 1; k <= n; k *= 2) {
	sort(sa, sa+n+1, compare_sa);
     
	tmp[sa[0]] = 0;
	for (int i = 1; i <= n; i++) {
	    tmp[sa[i]] = tmp[sa[i-1]] + (compare_sa(sa[i-1], sa[i]) ? 1 : 0);
	}
	for (int i = 0; i <= n; i++) {
	    _rank[i] = tmp[i];
	}
    }
}
 
bool contain(string &S, int *sa, string &T)
{
    int a = 0, b = S.length();
    while (b - a > 1) {
	int c = (a + b)/ 2;
	if (S.compare(sa[c],T.length(),T) < 0) {
            a = c;
	} else {
            b = c;
        }
    }
    return (S.compare(sa[b], T.length(), T) == 0);
}
 
int main()
{
    int Tc, q;
    string S, T;
    cin >> Tc;
    while (Tc--) {
	cin >> S >> q;
	construct_sa(S, sa);
	while(q--){
	    cin >> T;
	    if (S.size() < T.size()) {
                cout << 'n' << endl;
                continue;
            }
	    cout << (contain(S, sa, T) ? 'y' : 'n') << endl;
	}
    }
    return 0;
}
