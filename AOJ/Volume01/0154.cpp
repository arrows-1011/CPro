#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 7
typedef pair<int,int> P;
 
int m, cnt;
vector<P> v;
 
void check(int num, int pos)
{
    if (num == 0) {
	cnt++;
	return;
    } else if(num < 0 || m <= pos) {
	return;
    }
 
    for (int i = 0; i < v[pos].second; i++) {
	check(num-v[pos].first*(i+1), pos+1);
    }
    check(num, pos+1);
}
 
int main()
{
    int g, num;
    while (cin >> m, m) {
	v.clear(); v.resize(m);
	for (int i = 0; i < m; i++) {
	    cin >> v[i].first >> v[i].second;
	}
 
	cin >> g;
	for (int i = 0; i < g; i++) {
	    cin >> num;
	    cnt = 0; check(num, 0);
	    cout << cnt << endl;
	}
    }
    return 0;
}
