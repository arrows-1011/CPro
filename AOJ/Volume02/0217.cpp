#include <cstdio>
 
int main()
{
    int n;
 
    while (scanf("%d", &n), n) {
	int p, d1, d2;
	int ans = 0, num;
 
	while (n--) {
	    scanf("%d %d %d", &p, &d1, &d2);
	    if (ans < d1+d2) {
		ans = d1+d2;
		num = p;
	    }
	}
	printf("%d %d\n", num, ans);
    }
    return 0;
}
