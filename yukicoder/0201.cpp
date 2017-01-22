#include <iostream>

using namespace std;

int c(string a, string b)
{
    int n = a.size(), m = b.size();
    if (n < m) return 1;
    if (n > m) return -1;

    for (int i = 0; i < n; i++) {
        if (a[i] < b[i]) return 1;
        if (a[i] > b[i]) return -1;
    }
    return 0;
}

int main()
{
    string SA, PA, XA, SB, PB, XB;
    cin >> SA >> PA >> XA >> SB >> PB >> XB;
    int res = c(PA, PB);
    if (res == 1) {
        cout << SB << endl;
    } else if (res == -1) {
        cout << SA << endl;
    } else {
        cout << -1 << endl;
    }        
    return 0;
}
