#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 20
 
int main()
{
    int n, m, a, b;
    bool G[MAX][MAX];
 
    memset(G, 0, sizeof(G));
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
	cin >> a >> b;
	G[b-1][a-1] = 1;
    }
    int rem = m;
    bool used[MAX];
    memset(used, 0, sizeof(used));
    while (1) {
	if (rem == 0) break;
	for (int i = 0; i < m; i++) {
	    if (used[i]) continue;
	    bool ok = 1;
	    for (int j = 0; j < m; j++) {
		if (i != j && G[i][j]) {
		    ok = 0;
		    break;
		}
	    }
	    if (ok) {
		cout << i+1 << endl;
		used[i] = 1;
		rem--;
		for (int j = 0; j < m; j++) {
		    G[j][i] = 0;
		}
	    }
	}
    }
    return 0;
}
