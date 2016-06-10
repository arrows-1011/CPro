#include <cstdio>
 
int main()
{
    int n,key;
 
    while (scanf("%d", &n), n) {
	int a[n];
	for (int i = 0; i < n; i++) {
	    scanf("%d", a + i);
	}
 
	scanf("%d", &key);
 
	int lb = 0, ub = n-1, cnt = 0;
	while (ub - lb >= 0) {
	    int mid = (lb + ub) / 2;
	    cnt++;
 
	    if (key == a[mid]) {
		break;
	    }
	    if (key < a[mid]) {
		ub = mid - 1;
	    } else {
		lb = mid + 1;
	    }
	}   
	printf("%d\n", cnt);
    }
    return 0;
}
