#include <bits/stdc++.h>

using namespace std;
 
int main()
{
    int N;
 
    while (cin >> N, N != -1) {
        double x = 1, y = 0, r;
	for (int i = 0; i < N-1; i++) {
            r = atan2(y, x);
	    x -= sin(r);
	    y += cos(r);
	}
	printf("%.5f\n%.5f\n", x, y);
    }
    return 0;
}
