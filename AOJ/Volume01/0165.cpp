#include <iostream>
 
using namespace std;
 
#define MP 999983
#define MAX 1000000
int Prime[MAX+1];
bool prime[MAX+1];
 
void make()
{
    fill(prime, prime+MAX, true);
    prime[0] = prime[1] = false;
 
    for (int i = 2; i*i <= MAX; i++) {
	if (prime[i]) {
	    for (int j = i*i; j <= MAX; j += i) {
		prime[j] = false;
	    }
	}
    }
 
    int sum = 0;
    for (int i = 0; i <= MAX; i++) {
	if (prime[i]) {
	    sum++;
	}
	Prime[i] = sum;
    }
}
 
int main()
{
    int n;
 
    make();
    while (cin >> n, n) {
	int p, m, ans = 0;
	for (int i = 0; i < n; i++) {
	    cin >> p >> m;
 
	    int large = p + m;
	    int small = p - m;
 
	    if (large > MP) {
		large = MP;
	    }     
	    if (small < 0) {
		small = 0;
	    }
	    int X = Prime[large] - Prime[small] + prime[small];
	    if (X == 0) {
		ans--;
	    } else {
		ans += X-1;
	    }
	}
	cout << ans << endl;
    }
    return 0;
}
