#include <bits/stdc++.h>

using namespace std;

#define MAX 100
 
int main()
{
    int a, b, arr[MAX+1];
 
    while (cin >> a >> b) {
        memset(arr, 0, sizeof(arr));
	arr[--a]++;
	arr[--b]++;
 
	while (cin >> a >> b, (a | b)) {
	    arr[--a]++;
	    arr[--b]++;
	}
 
	bool flg = 0;
	if ((arr[0] % 2 == 1) && (arr[1] % 2==1)) flg = 1;
	for (int i = 2; i < MAX; i++) {
	    if(arr[i] % 2 == 1) flg = 0;
	}
        cout << (flg ? "OK" : "NG") << endl;
    }
    return 0;
}
