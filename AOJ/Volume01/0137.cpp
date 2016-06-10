#include <bits/stdc++.h>

using namespace std;
 
int main()
{
    int n, d;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> d;
        cout << "Case " << i+1 << ':' << endl;
        for (int j = 0; j < 10; j++) {
            d = d*d%100000000/100%10000;
            cout << d << endl;
        }
    }   
    return 0;
}
