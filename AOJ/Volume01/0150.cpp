#include <bits/stdc++.h>

using namespace std;

#define MAX 10100
 
bool prime[MAX];

void make()
{
    fill(prime, prime + MAX, 1);
    prime[0] = prime[1] = 0;
     
    for (int i = 2; i*i < MAX; i++) {
        if (prime[i]) {
            for (int j = i*2; j < MAX; j += i) {
                prime[j] = 0;
	    }
	}
    }
}
 
int main()
{
    int n;
     
    make();
    while (cin >> n, n) {
        int a, b;
        for (int i = 0 ; i <= n; i++) {
            if (i >= 2 && prime[i] && prime[i-2]) {
                a = i-2;
                b = i;
            }
        }
        cout << a << ' ' << b << endl;
    }
    return 0;
}
