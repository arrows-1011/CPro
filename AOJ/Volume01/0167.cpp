#include <bits/stdc++.h>

using namespace std;

#define MAX 100
 
int array[MAX];
 
int bubble_sort(int n, int array[])
{
    int tmp, cnt = 0;
     
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (array[j+1] < array[j]) {
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
                cnt++;
            }
        }    
    }
    return cnt;
}
 
 
int main()
{
    int n, array[MAX];
     
    while (cin >> n, n) {
        for (int i = 0; i < n; i++) {
            cin >> array[i];
        }
        int ans = 0;
        ans = bubble_sort(n, array);
        cout << ans << endl;
    }
    return 0;
}
