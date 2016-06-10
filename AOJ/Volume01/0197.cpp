#include <bits/stdc++.h>

using namespace std;

int cnt;
 
int GCD(int x, int y)
{
    if (x < y) swap(x, y);
    
    while (y != 0) {
	x %= y;
        swap(x, y);
	cnt++;
    }
    return x;
}
 
int main()
{
    int x, y, ans;
   
    while (cin >> x >> y, (x | y)) {
	cnt = 0;
	ans = GCD(x, y);
	printf("%d %d\n", ans, cnt);
    }
    return 0;
}
