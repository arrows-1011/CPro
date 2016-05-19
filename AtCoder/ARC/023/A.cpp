#include <bits/stdc++.h>

using namespace std;

int fairfield(int y, int m, int d)
{
    if (m <= 2) y--, m += 12;
    return 365*y+y/4-y/100+y/400+153*(m+1)/5+d-428;
}

int main()
{
    int y, m, d;
    cin >> y >> m >> d;
    cout << fairfield(2014, 5, 17) - fairfield(y, m, d) << endl;
    return 0;
}
