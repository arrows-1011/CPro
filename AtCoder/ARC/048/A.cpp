#include <bits/stdc++.h>

using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    cout << (B - A - (B > 0 && A < 0)) << endl;
    return 0;
}
