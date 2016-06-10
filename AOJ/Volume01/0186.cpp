#include <cstdio>
 
int main()
{
    int q1, b, c1, c2, q2;
 
    while (scanf("%d", &q1), q1) {
	scanf("%d %d %d %d" ,&b ,&c1 ,&c2 ,&q2);
 
	int cnt1 = b / c1;
	if (cnt1 > q2) {
	    cnt1 = q2;
	}
	b -= cnt1 * c1;
 
	int cnt2 = b / c2;
	if (cnt2 < 0) {
	    cnt2 = 0;
	}
	b -= cnt2 * c2;
 
	while (true) {
	    if (cnt1 + cnt2 >= q1 || cnt1 <= 0) {     
		break;  
	    } 
	    cnt1--;
	    b += c1;
 
	    b += cnt2 * c2;
	    cnt2 = b / c2;
	    b -= cnt2 * c2;
	}
 
	if (cnt1 <= 0) {
	    puts("NA");
	} else {
	    printf("%d %d\n" ,cnt1 ,cnt2);
	}
    }
    return 0;
}
