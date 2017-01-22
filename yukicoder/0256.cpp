#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;
    sort(s.rbegin(), s.rend());
    cout << s << endl;
    return 0;
}
