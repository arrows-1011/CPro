#include <iostream>

using namespace std;
 
int main()
{
    int room[8] = {0, 1, 2, 3, 5, 7, 8, 9}, n;
    int newroom[10], i;
     
    while (cin >> n, n) {
        for (i = 0; ;i++) {
            int nn = n / 8;
            newroom[i] = n % 8;
            n = nn;
            if (!n) break;
        }    
        for (int j = i; j >= 0; j--) {
            cout << room[newroom[j]];
        }
        cout << endl;
    }    
    return 0;
}
