#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b;
    c = b / a;
    b -= b / a * a;
    cout << c + (b > 0) << endl;
    return 0;
}
