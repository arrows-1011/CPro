#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int W, H;
    cin >> W >> H;
    int gcd = __gcd(W, H);
    cout << W/gcd << ":" << H/gcd << endl;
    return 0;
}
